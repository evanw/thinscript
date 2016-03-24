const TYPE_CLASS = 0;
const TYPE_GLOBAL = 1;
const TYPE_NATIVE = 2;

const FUNCTION_GLOBAL = 3;

const VARIABLE_ARGUMENT = 4;
const VARIABLE_CONSTANT = 5;
const VARIABLE_INSTANCE = 6;
const VARIABLE_LOCAL = 7;

function isType(symbolKind: int): bool {
  return symbolKind >= TYPE_CLASS && symbolKind <= TYPE_NATIVE;
}

function isVariable(symbolKind: int): bool {
  return symbolKind >= VARIABLE_ARGUMENT && symbolKind <= VARIABLE_LOCAL;
}

const SYMBOL_STATE_UNINITIALIZED = 0;
const SYMBOL_STATE_INITIALIZING = 1;
const SYMBOL_STATE_INITIALIZED = 2;

class Symbol {
  kind: int;
  name: String;
  node: Node;
  range: Range;
  scope: Scope;
  resolvedType: Type;
  next: Symbol;
  state: int;

  // The "offset" variable is used to store kind-specific information
  //
  //   TYPE_CLASS: Object size
  //   TYPE_GLOBAL: N/A
  //   TYPE_NATIVE: N/A
  //
  //   FUNCTION_GLOBAL: N/A
  //
  //   VARIABLE_ARGUMENT: Argument index
  //   VARIABLE_CONSTANT: N/A
  //   VARIABLE_INSTANCE: Instance offset
  //   VARIABLE_LOCAL: N/A
  //
  offset: int;
}

function isExternSymbol(symbol: Symbol): bool {
  return (symbol.node.flags & NODE_FLAG_EXTERN) != 0;
}

class Scope {
  parent: Scope;
  symbol: Symbol;
  firstSymbol: Symbol;
  lastSymbol: Symbol;
}

class Type {
  symbol: Symbol;
}

function typeIsClass(type: Type): bool {
  return type.symbol.kind == TYPE_CLASS;
}

function typeIsReference(context: CheckContext, type: Type): bool {
  return typeIsClass(type) || type == context.stringType;
}

function typeToString(type: Type): String {
  return type.symbol.name;
}

class CheckContext {
  log: Log;
  currentReturnType: Type;
  boolType: Type;
  errorType: Type;
  intType: Type;
  nullType: Type;
  stringType: Type;
  voidType: Type;
}

function findLocal(scope: Scope, name: String): Symbol {
  var symbol = scope.firstSymbol;
  while (symbol != null) {
    if (String_equal(symbol.name, name)) {
      return symbol;
    }
    symbol = symbol.next;
  }
  return null;
}

function findNested(scope: Scope, name: String): Symbol {
  while (scope != null) {
    var local = findLocal(scope, name);
    if (local != null) {
      return local;
    }
    scope = scope.parent;
  }
  return null;
}

function define(log: Log, scope: Scope, symbol: Symbol): bool {
  var existing = findLocal(scope, symbol.name);
  if (existing != null) {
    error(log, symbol.range, String_appendNew(String_append(String_new("Duplicate symbol '"), symbol.name), "'"));
    return false;
  }

  if (scope.firstSymbol == null) {
    scope.firstSymbol = symbol;
    scope.lastSymbol = symbol;
  }

  else {
    scope.lastSymbol.next = symbol;
    scope.lastSymbol = symbol;
  }

  return true;
}

function defineNativeType(log: Log, scope: Scope, name: string): Type {
  var symbol = new Symbol();
  symbol.kind = TYPE_NATIVE;
  symbol.name = String_new(name);
  symbol.resolvedType = new Type();
  symbol.resolvedType.symbol = symbol;
  symbol.state = SYMBOL_STATE_INITIALIZED;

  define(log, scope, symbol);

  return symbol.resolvedType;
}

function addScopeToSymbol(symbol: Symbol, parentScope: Scope): void {
  var scope = new Scope();
  scope.parent = parentScope;
  scope.symbol = symbol;
  symbol.scope = scope;
}

function linkSymbolToNode(symbol: Symbol, node: Node): void {
  node.symbol = symbol;
  node.scope = symbol.scope;
  symbol.range = node.internalRange != null ? node.internalRange : node.range;
  symbol.node = node;
}

function initialize(context: CheckContext, node: Node, parentScope: Scope): void {
  // Validate node placement
  if (node.parent != null && node.kind != NODE_VARIABLE) {
    if ((node.kind == NODE_CLASS || node.kind == NODE_FUNCTION || node.kind == NODE_CONSTANTS) != (node.parent.kind == NODE_GLOBAL)) {
      error(context.log, node.range, String_new("This statement is not allowed here"));
    }
  }

  // Global
  if (node.kind == NODE_GLOBAL) {
    assert(parentScope == null);

    var symbol = new Symbol();
    symbol.kind = TYPE_GLOBAL;
    symbol.name = String_new("<global>");
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
    symbol.state = SYMBOL_STATE_INITIALIZED;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);

    context.boolType = defineNativeType(context.log, symbol.scope, "bool");
    context.errorType = defineNativeType(context.log, symbol.scope, "<error>");
    context.intType = defineNativeType(context.log, symbol.scope, "int");
    context.nullType = defineNativeType(context.log, symbol.scope, "null");
    context.stringType = defineNativeType(context.log, symbol.scope, "string");
    context.voidType = defineNativeType(context.log, symbol.scope, "void");

    parentScope = symbol.scope;
  }

  // Class
  else if (node.kind == NODE_CLASS) {
    var symbol = new Symbol();
    symbol.kind = TYPE_CLASS;
    symbol.name = node.stringValue;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);

    define(context.log, parentScope, symbol);

    parentScope = symbol.scope;
  }

  // Function
  else if (node.kind == NODE_FUNCTION) {
    var symbol = new Symbol();
    symbol.kind = FUNCTION_GLOBAL;
    symbol.name = node.stringValue;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);

    define(context.log, parentScope, symbol);

    parentScope = symbol.scope;
  }

  // Variable
  else if (node.kind == NODE_VARIABLE) {
    var symbol = new Symbol();
    symbol.kind =
      node.parent.kind == NODE_CLASS ? VARIABLE_INSTANCE :
      node.parent.kind == NODE_FUNCTION ? VARIABLE_ARGUMENT :
      node.parent.kind == NODE_CONSTANTS ? VARIABLE_CONSTANT :
      VARIABLE_LOCAL;
    symbol.name = node.stringValue;
    symbol.scope = parentScope;
    linkSymbolToNode(symbol, node);

    define(context.log, parentScope, symbol);
  }

  // Block
  else if (node.kind == NODE_BLOCK) {
    if (node.parent.kind != NODE_FUNCTION) {
      var scope = new Scope();
      scope.parent = parentScope;
      parentScope = scope;
    }

    node.scope = parentScope;
  }

  // Children
  var child = node.firstChild;
  while (child != null) {
    initialize(context, child, parentScope);
    child = child.nextSibling;
  }
}

function initializeSymbol(context: CheckContext, symbol: Symbol): void {
  if (symbol.state == SYMBOL_STATE_INITIALIZED) {
    assert(symbol.resolvedType != null);
    return;
  }

  assert(symbol.state == SYMBOL_STATE_UNINITIALIZED);
  assert(symbol.resolvedType == null);
  symbol.state = SYMBOL_STATE_INITIALIZING;

  // Class
  if (symbol.kind == TYPE_CLASS) {
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
  }

  // Function
  else if (symbol.kind == FUNCTION_GLOBAL) {
    var returnType = functionReturnType(symbol.node);
    resolveAsType(context, returnType, symbol.scope.parent);

    var offset = 0;
    var child = symbol.node.firstChild;
    while (child != returnType) {
      assert(child.kind == NODE_VARIABLE);
      assert(child.symbol.kind == VARIABLE_ARGUMENT);
      initializeSymbol(context, child.symbol);
      child.symbol.offset = offset;
      offset = offset + 1;
      child = child.nextSibling;
    }

    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
  }

  // Variable
  else if (isVariable(symbol.kind)) {
    var type = variableType(symbol.node);
    var value = variableValue(symbol.node);

    if (type != null) {
      resolveAsType(context, type, symbol.scope);
      symbol.resolvedType = type.resolvedType;
    }

    else if (value != null) {
      resolveAsExpression(context, value, symbol.scope);
      symbol.resolvedType = value.resolvedType;
    }

    else {
      error(context.log, symbol.node.internalRange, String_new("Cannot create untyped variables"));
      symbol.resolvedType = context.errorType;
    }

    // Validate the variable type
    if (symbol.resolvedType == context.voidType || symbol.resolvedType == context.nullType) {
      error(context.log, symbol.node.internalRange, String_appendNew(String_append(
        String_new("Cannot create a variable with type '"),
        typeToString(symbol.resolvedType)),
        "'"));
      symbol.resolvedType = context.errorType;
    }

    // Resolve constant values at initialization time
    if (symbol.kind == VARIABLE_CONSTANT) {
      if (symbol.resolvedType != context.errorType && symbol.resolvedType != context.intType) {
        error(context.log, symbol.node.internalRange, String_new("All constants must be integers for now"));
        symbol.resolvedType = context.errorType;
      }

      if (value != null) {
        resolveAsExpression(context, value, symbol.scope);
        checkConversion(context, value, symbol.resolvedType);

        // TODO: Constant folding
        if (value.kind == NODE_INT) {
          symbol.offset = value.intValue;
        }

        else {
          error(context.log, value.range, String_new("Constants must be initialized to a single integer for now"));
        }
      }

      else {
        error(context.log, symbol.node.internalRange, String_new("Constants must be initialized"));
      }
    }
  }

  else {
    assert(false);
  }

  assert(symbol.resolvedType != null);
  symbol.state = SYMBOL_STATE_INITIALIZED;
}

function resolveChildren(context: CheckContext, node: Node, parentScope: Scope): void {
  var child = node.firstChild;
  while (child != null) {
    resolve(context, child, parentScope);
    child = child.nextSibling;
  }
}

function resolveAsExpression(context: CheckContext, node: Node, parentScope: Scope): void {
  assert(isExpression(node));
  resolve(context, node, parentScope);

  if (node.resolvedType != context.errorType && node.symbol != null && isType(node.symbol.kind)) {
    error(context.log, node.range, String_new("Expected expression but found type"));
    node.resolvedType = context.errorType;
  }
}

function resolveAsType(context: CheckContext, node: Node, parentScope: Scope): void {
  assert(isExpression(node));
  resolve(context, node, parentScope);

  if (node.resolvedType != context.errorType && (node.symbol == null || !isType(node.symbol.kind))) {
    error(context.log, node.range, String_new("Expected type but found expression"));
    node.resolvedType = context.errorType;
  }
}

function checkConversion(context: CheckContext, from: Node, to: Type): void {
  assert(isExpression(from));
  assert(to != null);

  if (from.resolvedType != context.errorType && to != context.errorType &&
      from.resolvedType != to && (from.resolvedType != context.nullType || !typeIsReference(context, to))) {
    error(context.log, from.range, String_appendNew(String_append(String_appendNew(String_append(
      String_new("Cannot convert from type '"),
      typeToString(from.resolvedType)),
      "' to type '"),
      typeToString(to)),
      "'"));
    from.resolvedType = context.errorType;
  }
}

function checkStorage(context: CheckContext, target: Node): void {
  assert(isExpression(target));

  if (target.resolvedType != context.errorType && (target.kind != NODE_NAME && target.kind != NODE_DOT ||
      target.symbol != null && (!isVariable(target.symbol.kind) || target.symbol.kind == VARIABLE_CONSTANT))) {
    error(context.log, target.range, String_new("Cannot store to this location"));
    target.resolvedType = context.errorType;
  }
}

function resolveUnary(context: CheckContext, node: Node, parentScope: Scope, expectedType: Type): void {
  var value = unaryValue(node);
  resolveAsExpression(context, value, parentScope);
  checkConversion(context, value, expectedType);
  node.resolvedType = expectedType;
}

function resolveBinary(context: CheckContext, node: Node, parentScope: Scope): void {
  var left = binaryLeft(node);
  var right = binaryRight(node);
  resolveAsExpression(context, left, parentScope);
  resolveAsExpression(context, right, parentScope);
}

function checkBinary(context: CheckContext, node: Node, expectedType: Type, resultType: Type): void {
  var left = binaryLeft(node);
  var right = binaryRight(node);
  checkConversion(context, left, expectedType);
  checkConversion(context, right, expectedType);
  node.resolvedType = resultType;
}

function createDefaultValueForType(context: CheckContext, type: Type): Node {
  if (type == context.intType) {
    return createInt(0);
  }

  if (type == context.boolType) {
    return createBool(false);
  }

  assert(typeIsReference(context, type));
  return createNull();
}

function resolve(context: CheckContext, node: Node, parentScope: Scope): void {
  assert(node.kind == NODE_GLOBAL || parentScope != null);

  if (node.resolvedType != null) {
    return;
  }

  node.resolvedType = context.errorType;

  if (node.kind == NODE_GLOBAL) {
    resolveChildren(context, node, node.scope);
  }

  else if (node.kind == NODE_CLASS) {
    initializeSymbol(context, node.symbol);
    resolveChildren(context, node, node.scope);

    // Determine class layout
    var offset = 0;
    var child = node.firstChild;
    while (child != null) {
      assert(child.kind == NODE_VARIABLE);
      child.symbol.offset = offset;
      offset = offset + 4;
      child = child.nextSibling;
    }
    node.symbol.offset = offset > 0 ? offset : 1;
  }

  else if (node.kind == NODE_FUNCTION) {
    var body = functionBody(node);
    initializeSymbol(context, node.symbol);

    if (body != null) {
      var oldReturnType = context.currentReturnType;
      context.currentReturnType = functionReturnType(node).resolvedType;
      resolveChildren(context, body, node.scope);
      context.currentReturnType = oldReturnType;
    }
  }

  else if (node.kind == NODE_VARIABLE) {
    var symbol = node.symbol;
    initializeSymbol(context, symbol);

    var value = variableValue(node);
    if (value != null) {
      resolveAsExpression(context, value, parentScope);
      checkConversion(context, value, symbol.resolvedType);
    }

    else {
      appendChild(node, createDefaultValueForType(context, symbol.resolvedType));
    }
  }

  else if (node.kind == NODE_BREAK || node.kind == NODE_CONTINUE) {
    var found = false;
    var n = node;
    while (n != null) {
      if (n.kind == NODE_WHILE) {
        found = true;
        break;
      }
      n = n.parent;
    }
    if (!found) {
      error(context.log, node.range, String_new("Cannot use this statement outside of a loop"));
    }
  }

  else if (node.kind == NODE_BLOCK) {
    resolveChildren(context, node, node.scope);
  }

  else if (node.kind == NODE_CONSTANTS || node.kind == NODE_VARIABLES) {
    resolveChildren(context, node, parentScope);
  }

  else if (node.kind == NODE_INT) {
    node.resolvedType = context.intType;
  }

  else if (node.kind == NODE_STRING) {
    node.resolvedType = context.stringType;
  }

  else if (node.kind == NODE_BOOL) {
    node.resolvedType = context.boolType;
  }

  else if (node.kind == NODE_NULL) {
    node.resolvedType = context.nullType;
  }

  else if (node.kind == NODE_NAME) {
    var symbol = findNested(parentScope, node.stringValue);

    if (symbol == null) {
      error(context.log, node.range, String_appendNew(String_append(
        String_new("No symbol named '"),
        node.stringValue),
        "' here"));
    }

    else if (symbol.state == SYMBOL_STATE_INITIALIZING) {
      error(context.log, node.range, String_appendNew(String_append(
        String_new("Cyclic reference to symbol '"),
        node.stringValue),
        "' here"));
    }

    else if (symbol.kind == FUNCTION_GLOBAL && (node.parent.kind != NODE_CALL || node != callValue(node.parent))) {
      error(context.log, node.range, String_new("Bare function references are not allowed"));
    }

    else {
      initializeSymbol(context, symbol);
      node.symbol = symbol;
      node.resolvedType = symbol.resolvedType;

      // Inline constants
      if (node.symbol.kind == VARIABLE_CONSTANT) {
        node.kind = NODE_INT;
        node.intValue = node.symbol.offset;
      }
    }
  }

  else if (node.kind == NODE_DOT) {
    var target = dotTarget(node);
    resolveAsExpression(context, target, parentScope);

    if (target.resolvedType != context.errorType) {
      if (typeIsClass(target.resolvedType)) {
        var child = target.resolvedType.symbol.node.firstChild;

        while (child != null) {
          assert(child.kind == NODE_VARIABLE);

          if (String_equal(child.symbol.name, node.stringValue)) {
            initializeSymbol(context, child.symbol);
            node.symbol = child.symbol;
            break;
          }

          child = child.nextSibling;
        }

        if (node.symbol != null) {
          node.resolvedType = node.symbol.resolvedType;
        }

        else {
          error(context.log, node.internalRange, String_appendNew(String_append(String_appendNew(String_append(
            String_new("No member named '"),
            node.stringValue),
            "' on type '"),
            typeToString(target.resolvedType)),
            "'"));
        }
      }

      else {
        error(context.log, node.internalRange, String_appendNew(String_append(
          String_new("The type '"),
          typeToString(target.resolvedType)),
          "' has no members"));
      }
    }
  }

  else if (node.kind == NODE_CALL) {
    var value = callValue(node);
    resolveAsExpression(context, value, parentScope);

    if (value.resolvedType != context.errorType) {
      var symbol = value.symbol;
      if (symbol == null || symbol.kind != FUNCTION_GLOBAL) {
        error(context.log, value.range, String_appendNew(String_append(
          String_new("Cannot call value of type '"),
          typeToString(value.resolvedType)),
          "'"));
      }

      else {
        initializeSymbol(context, symbol);

        var returnType = functionReturnType(symbol.node);
        var argumentVariable = symbol.node.firstChild;
        var argumentValue = value.nextSibling;

        // Match argument values with variables
        while (argumentVariable != returnType && argumentValue != null) {
          resolveAsExpression(context, argumentValue, parentScope);
          checkConversion(context, argumentValue, argumentVariable.symbol.resolvedType);
          argumentVariable = argumentVariable.nextSibling;
          argumentValue = argumentValue.nextSibling;
        }

        // Not enough arguments?
        if (argumentVariable != returnType) {
          error(context.log, node.internalRange, String_appendNew(String_append(
            String_new("Not enough arguments for function '"),
            symbol.name),
            "'"));
        }

        // Too many arguments?
        else if (argumentValue != null) {
          while (argumentValue != null) {
            resolveAsExpression(context, argumentValue, parentScope);
            argumentValue = argumentValue.nextSibling;
          }
          error(context.log, node.internalRange, String_appendNew(String_append(
            String_new("Too many arguments for function '"),
            symbol.name),
            "'"));
        }

        // Pass the return type along
        node.resolvedType = returnType.resolvedType;
      }
    }
  }

  else if (node.kind == NODE_RETURN) {
    var value = returnValue(node);

    if (value != null) {
      resolveAsExpression(context, value, parentScope);

      if (context.currentReturnType != null) {
        checkConversion(context, value, context.currentReturnType);
      }
    }

    else if (context.currentReturnType != null && context.currentReturnType != context.voidType) {
      error(context.log, node.range, String_new("Expected return value"));
    }
  }

  else if (node.kind == NODE_EMPTY) {
  }

  else if (node.kind == NODE_EXPRESSION) {
    resolveAsExpression(context, expressionValue(node), parentScope);
  }

  else if (node.kind == NODE_WHILE) {
    var value = whileValue(node);
    var body = whileBody(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType);
    resolve(context, body, parentScope);
  }

  else if (node.kind == NODE_IF) {
    var value = ifValue(node);
    var yes = ifTrue(node);
    var no = ifFalse(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType);
    resolve(context, yes, parentScope);
    if (no != null) {
      resolve(context, no, parentScope);
    }
  }

  else if (node.kind == NODE_HOOK) {
    var value = hookValue(node);
    var yes = hookTrue(node);
    var no = hookFalse(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType);
    resolve(context, yes, parentScope);
    resolve(context, no, parentScope);
    var commonType = (yes.resolvedType == context.nullType ? no : yes).resolvedType;
    if (yes.resolvedType != commonType && (yes.resolvedType != context.nullType || !typeIsReference(context, commonType)) &&
        no.resolvedType != commonType && (no.resolvedType != context.nullType || !typeIsReference(context, commonType))) {
      error(context.log, spanRanges(yes.range, no.range), String_appendNew(String_append(String_appendNew(String_append(
        String_new("Type '"),
        typeToString(yes.resolvedType)),
        "' is not the same as type '"),
        typeToString(no.resolvedType)),
        "'"));
    }
    node.resolvedType = commonType;
  }

  else if (node.kind == NODE_ASSIGN) {
    var left = binaryLeft(node);
    var right = binaryRight(node);
    resolveAsExpression(context, left, parentScope);
    resolveAsExpression(context, right, parentScope);
    checkConversion(context, right, left.resolvedType);
    checkStorage(context, left);
    node.resolvedType = left.resolvedType;
  }

  else if (
      node.kind == NODE_ADD || node.kind == NODE_SUBTRACT || node.kind == NODE_MULTIPLY || node.kind == NODE_DIVIDE ||
      node.kind == NODE_BITWISE_AND || node.kind == NODE_BITWISE_OR || node.kind == NODE_BITWISE_XOR ||
      node.kind == NODE_SHIFT_LEFT || node.kind == NODE_SHIFT_RIGHT) {
    resolveBinary(context, node, parentScope);
    checkBinary(context, node, context.intType, context.intType);
  }

  else if (
      node.kind == NODE_LESS_THAN || node.kind == NODE_LESS_THAN_EQUAL ||
      node.kind == NODE_GREATER_THAN || node.kind == NODE_GREATER_THAN_EQUAL) {
    resolveBinary(context, node, parentScope);
    checkBinary(context, node, context.intType, context.boolType);
  }

  else if (node.kind == NODE_LOGICAL_OR || node.kind == NODE_LOGICAL_AND) {
    resolveBinary(context, node, parentScope);
    checkBinary(context, node, context.boolType, context.boolType);
  }

  else if (node.kind == NODE_EQUAL || node.kind == NODE_NOT_EQUAL) {
    var left = binaryLeft(node);
    var right = binaryRight(node);
    resolveBinary(context, node, parentScope);
    node.resolvedType = context.boolType;

    var leftType = left.resolvedType;
    var rightType = right.resolvedType;

    if (leftType != context.errorType && rightType != context.errorType && (leftType == rightType ? leftType == context.voidType :
        (leftType != context.nullType || !typeIsReference(context, rightType)) &&
        (rightType != context.nullType || !typeIsReference(context, leftType)))) {
      error(context.log, node.range, String_appendNew(String_append(String_appendNew(String_append(
        String_new("Cannot compare type '"),
        typeToString(leftType)),
        "' with type '"),
        typeToString(rightType)),
        "'"));
    }
  }

  else if (node.kind == NODE_COMPLEMENT || node.kind == NODE_NEGATIVE || node.kind == NODE_POSITIVE) {
    resolveUnary(context, node, parentScope, context.intType);
  }

  else if (node.kind == NODE_NOT) {
    resolveUnary(context, node, parentScope, context.boolType);
  }

  else if (node.kind == NODE_NEW) {
    var type = newType(node);
    resolveAsType(context, type, parentScope);

    if (type.resolvedType != context.errorType) {
      if (!typeIsClass(type.resolvedType)) {
        error(context.log, type.range, String_appendNew(String_append(
          String_new("Cannot construct type '"),
          typeToString(type.resolvedType)),
          "'"));
      }

      else {
        node.resolvedType = type.resolvedType;
      }
    }
  }

  else {
    assert(false);
  }
}

function check(global: Node, log: Log): CheckContext {
  var context = new CheckContext();
  context.log = log;
  initialize(context, global, null);
  resolve(context, global, null);
  return context;
}
