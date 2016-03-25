function isType(symbolKind) {
  return symbolKind >= 0 && symbolKind <= 2;
}
function isVariable(symbolKind) {
  return symbolKind >= 4 && symbolKind <= 7;
}
function Symbol() {
  this.kind = 0;
  this.name = null;
  this.node = null;
  this.range = null;
  this.scope = null;
  this.resolvedType = null;
  this.next = null;
  this.state = 0;
  this.offset = 0;
}
function isExternSymbol(symbol) {
  return (symbol.node.flags & 1) !== 0;
}
function Scope() {
  this.parent = null;
  this.symbol = null;
  this.firstSymbol = null;
  this.lastSymbol = null;
}
function Type() {
  this.symbol = null;
}
function typeIsClass(type) {
  return type.symbol.kind === 0;
}
function typeIsReference(context, type) {
  return typeIsClass(type) || type === context.stringType;
}
function typeToString(type) {
  return type.symbol.name;
}
function CheckContext() {
  this.log = null;
  this.currentReturnType = null;
  this.boolType = null;
  this.errorType = null;
  this.intType = null;
  this.nullType = null;
  this.stringType = null;
  this.voidType = null;
}
function findLocal(scope, name) {
  var symbol = scope.firstSymbol;
  while (symbol !== null) {
    if (__imports.String_equal(symbol.name, name)) {
      return symbol;
    }
    symbol = symbol.next;
  }
  return null;
}
function findNested(scope, name) {
  while (scope !== null) {
    var local = findLocal(scope, name);
    if (local !== null) {
      return local;
    }
    scope = scope.parent;
  }
  return null;
}
function define(log, scope, symbol) {
  var existing = findLocal(scope, symbol.name);
  if (existing !== null) {
    error(log, symbol.range, __imports.String_appendNew(__imports.String_append(__imports.String_new("Duplicate symbol '"), symbol.name), "'"));
    return false;
  }
  if (scope.firstSymbol === null) {
    scope.firstSymbol = symbol;
  } else {
    scope.lastSymbol.next = symbol;
  }
  scope.lastSymbol = symbol;
  return true;
}
function defineNativeType(log, scope, name) {
  var symbol = new Symbol();
  symbol.kind = 2;
  symbol.name = __imports.String_new(name);
  symbol.resolvedType = new Type();
  symbol.resolvedType.symbol = symbol;
  symbol.state = 2;
  define(log, scope, symbol);
  return symbol.resolvedType;
}
function addScopeToSymbol(symbol, parentScope) {
  var scope = new Scope();
  scope.parent = parentScope;
  scope.symbol = symbol;
  symbol.scope = scope;
}
function linkSymbolToNode(symbol, node) {
  node.symbol = symbol;
  node.scope = symbol.scope;
  symbol.range = node.internalRange !== null ? node.internalRange : node.range;
  symbol.node = node;
}
function initialize(context, node, parentScope) {
  if (node.parent !== null && node.kind !== 1) {
    if ((node.kind === 4 || node.kind === 9 || node.kind === 5) !== (node.parent.kind === 0)) {
      error(context.log, node.range, __imports.String_new("This statement is not allowed here"));
    }
  }
  if (node.kind === 0) {
    __imports.assert(parentScope === null);
    var symbol = new Symbol();
    symbol.kind = 1;
    symbol.name = __imports.String_new("<global>");
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
    symbol.state = 2;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    context.boolType = defineNativeType(context.log, symbol.scope, "bool");
    context.errorType = defineNativeType(context.log, symbol.scope, "<error>");
    context.intType = defineNativeType(context.log, symbol.scope, "int");
    context.nullType = defineNativeType(context.log, symbol.scope, "null");
    context.stringType = defineNativeType(context.log, symbol.scope, "string");
    context.voidType = defineNativeType(context.log, symbol.scope, "void");
    parentScope = symbol.scope;
  } else if (node.kind === 4) {
    var symbol = new Symbol();
    symbol.kind = 0;
    symbol.name = node.stringValue;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    define(context.log, parentScope, symbol);
    parentScope = symbol.scope;
  } else if (node.kind === 9) {
    var symbol = new Symbol();
    symbol.kind = 3;
    symbol.name = node.stringValue;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    define(context.log, parentScope, symbol);
    parentScope = symbol.scope;
  } else if (node.kind === 1) {
    var symbol = new Symbol();
    symbol.kind = node.parent.kind === 4 ? 6 : node.parent.kind === 9 ? 4 : node.parent.kind === 5 ? 5 : 7;
    symbol.name = node.stringValue;
    symbol.scope = parentScope;
    linkSymbolToNode(symbol, node);
    define(context.log, parentScope, symbol);
  } else if (node.kind === 2) {
    if (node.parent.kind !== 9) {
      var scope = new Scope();
      scope.parent = parentScope;
      parentScope = scope;
    }
    node.scope = parentScope;
  }
  var child = node.firstChild;
  while (child !== null) {
    initialize(context, child, parentScope);
    child = child.nextSibling;
  }
}
function initializeSymbol(context, symbol) {
  if (symbol.state === 2) {
    __imports.assert(symbol.resolvedType !== null);
    return;
  }
  __imports.assert(symbol.state === 0);
  __imports.assert(symbol.resolvedType === null);
  symbol.state = 1;
  if (symbol.kind === 0) {
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
  } else if (symbol.kind === 3) {
    var returnType = functionReturnType(symbol.node);
    resolveAsType(context, returnType, symbol.scope.parent);
    var offset = 0;
    var child = symbol.node.firstChild;
    while (child !== returnType) {
      __imports.assert(child.kind === 1);
      __imports.assert(child.symbol.kind === 4);
      initializeSymbol(context, child.symbol);
      child.symbol.offset = offset;
      offset = offset + 1;
      child = child.nextSibling;
    }
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
  } else if (isVariable(symbol.kind)) {
    var type = variableType(symbol.node);
    var value = variableValue(symbol.node);
    if (type !== null) {
      resolveAsType(context, type, symbol.scope);
      symbol.resolvedType = type.resolvedType;
    } else if (value !== null) {
      resolveAsExpression(context, value, symbol.scope);
      symbol.resolvedType = value.resolvedType;
    } else {
      error(context.log, symbol.node.internalRange, __imports.String_new("Cannot create untyped variables"));
      symbol.resolvedType = context.errorType;
    }
    if (symbol.resolvedType === context.voidType || symbol.resolvedType === context.nullType) {
      error(context.log, symbol.node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_new("Cannot create a variable with type '"), typeToString(symbol.resolvedType)), "'"));
      symbol.resolvedType = context.errorType;
    }
    if (symbol.kind === 5) {
      if (symbol.resolvedType !== context.errorType && symbol.resolvedType !== context.intType) {
        error(context.log, symbol.node.internalRange, __imports.String_new("All constants must be integers for now"));
        symbol.resolvedType = context.errorType;
      }
      if (value !== null) {
        resolveAsExpression(context, value, symbol.scope);
        checkConversion(context, value, symbol.resolvedType);
        if (value.kind === 19) {
          symbol.offset = value.intValue;
        } else {
          error(context.log, value.range, __imports.String_new("Constants must be initialized to a single integer for now"));
        }
      } else {
        error(context.log, symbol.node.internalRange, __imports.String_new("Constants must be initialized"));
      }
    }
    if (symbol.scope.symbol === null) {
      var scope = symbol.scope.parent;
      while (scope !== null) {
        var shadowed = findLocal(scope, symbol.name);
        if (shadowed !== null) {
          error(context.log, symbol.node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_new("The symbol '"), symbol.name), "' shadows another symbol with the same name in a parent scope"));
          break;
        }
        if (scope.symbol !== null) {
          break;
        }
        scope = scope.parent;
      }
    }
  } else {
    __imports.assert(false);
  }
  __imports.assert(symbol.resolvedType !== null);
  symbol.state = 2;
}
function resolveChildren(context, node, parentScope) {
  var child = node.firstChild;
  while (child !== null) {
    resolve(context, child, parentScope);
    child = child.nextSibling;
  }
}
function resolveAsExpression(context, node, parentScope) {
  __imports.assert(isExpression(node));
  resolve(context, node, parentScope);
  if (node.resolvedType !== context.errorType && node.symbol !== null && isType(node.symbol.kind)) {
    error(context.log, node.range, __imports.String_new("Expected expression but found type"));
    node.resolvedType = context.errorType;
  }
}
function resolveAsType(context, node, parentScope) {
  __imports.assert(isExpression(node));
  resolve(context, node, parentScope);
  if (node.resolvedType !== context.errorType && (node.symbol === null || !isType(node.symbol.kind))) {
    error(context.log, node.range, __imports.String_new("Expected type but found expression"));
    node.resolvedType = context.errorType;
  }
}
function checkConversion(context, from, to) {
  __imports.assert(isExpression(from));
  __imports.assert(to !== null);
  if (from.resolvedType !== context.errorType && to !== context.errorType && from.resolvedType !== to && (from.resolvedType !== context.nullType || !typeIsReference(context, to))) {
    error(context.log, from.range, __imports.String_appendNew(__imports.String_append(__imports.String_appendNew(__imports.String_append(__imports.String_new("Cannot convert from type '"), typeToString(from.resolvedType)), "' to type '"), typeToString(to)), "'"));
    from.resolvedType = context.errorType;
  }
}
function checkStorage(context, target) {
  __imports.assert(isExpression(target));
  if (target.resolvedType !== context.errorType && (target.kind !== 20 && target.kind !== 17 || target.symbol !== null && (!isVariable(target.symbol.kind) || target.symbol.kind === 5))) {
    error(context.log, target.range, __imports.String_new("Cannot store to this location"));
    target.resolvedType = context.errorType;
  }
}
function resolveUnary(context, node, parentScope, expectedType) {
  var value = unaryValue(node);
  resolveAsExpression(context, value, parentScope);
  checkConversion(context, value, expectedType);
  node.resolvedType = expectedType;
}
function resolveBinary(context, node, parentScope) {
  var left = binaryLeft(node);
  var right = binaryRight(node);
  resolveAsExpression(context, left, parentScope);
  resolveAsExpression(context, right, parentScope);
}
function checkBinary(context, node, expectedType, resultType) {
  var left = binaryLeft(node);
  var right = binaryRight(node);
  checkConversion(context, left, expectedType);
  checkConversion(context, right, expectedType);
  node.resolvedType = resultType;
}
function createDefaultValueForType(context, type) {
  if (type === context.intType) {
    return createInt(0);
  }
  if (type === context.boolType) {
    return createBool(false);
  }
  __imports.assert(typeIsReference(context, type));
  return createNull();
}
function resolve(context, node, parentScope) {
  __imports.assert(node.kind === 0 || parentScope !== null);
  if (node.resolvedType !== null) {
    return;
  }
  node.resolvedType = context.errorType;
  if (node.kind === 0) {
    resolveChildren(context, node, node.scope);
  } else if (node.kind === 4) {
    initializeSymbol(context, node.symbol);
    resolveChildren(context, node, node.scope);
    var offset = 0;
    var child = node.firstChild;
    while (child !== null) {
      __imports.assert(child.kind === 1);
      child.symbol.offset = offset;
      offset = offset + 4;
      child = child.nextSibling;
    }
    node.symbol.offset = offset > 0 ? offset : 1;
  } else if (node.kind === 9) {
    var body = functionBody(node);
    initializeSymbol(context, node.symbol);
    if (body !== null) {
      var oldReturnType = context.currentReturnType;
      context.currentReturnType = functionReturnType(node).resolvedType;
      resolveChildren(context, body, node.scope);
      context.currentReturnType = oldReturnType;
    }
  } else if (node.kind === 1) {
    var symbol = node.symbol;
    initializeSymbol(context, symbol);
    var value = variableValue(node);
    if (value !== null) {
      resolveAsExpression(context, value, parentScope);
      checkConversion(context, value, symbol.resolvedType);
    } else {
      appendChild(node, createDefaultValueForType(context, symbol.resolvedType));
    }
  } else if (node.kind === 3 || node.kind === 6) {
    var found = false;
    var n = node;
    while (n !== null) {
      if (n.kind === 13) {
        found = true;
        break;
      }
      n = n.parent;
    }
    if (!found) {
      error(context.log, node.range, __imports.String_new("Cannot use this statement outside of a loop"));
    }
  } else if (node.kind === 2) {
    resolveChildren(context, node, node.scope);
  } else if (node.kind === 5 || node.kind === 12) {
    resolveChildren(context, node, parentScope);
  } else if (node.kind === 19) {
    node.resolvedType = context.intType;
  } else if (node.kind === 23) {
    node.resolvedType = context.stringType;
  } else if (node.kind === 14) {
    node.resolvedType = context.boolType;
  } else if (node.kind === 22) {
    node.resolvedType = context.nullType;
  } else if (node.kind === 20) {
    var symbol = findNested(parentScope, node.stringValue);
    if (symbol === null) {
      error(context.log, node.range, __imports.String_appendNew(__imports.String_append(__imports.String_new("No symbol named '"), node.stringValue), "' here"));
    } else if (symbol.state === 1) {
      error(context.log, node.range, __imports.String_appendNew(__imports.String_append(__imports.String_new("Cyclic reference to symbol '"), node.stringValue), "' here"));
    } else if (symbol.kind === 3 && (node.parent.kind !== 15 || node !== callValue(node.parent))) {
      error(context.log, node.range, __imports.String_new("Bare function references are not allowed"));
    } else {
      initializeSymbol(context, symbol);
      node.symbol = symbol;
      node.resolvedType = symbol.resolvedType;
      if (node.symbol.kind === 5) {
        node.kind = 19;
        node.intValue = node.symbol.offset;
      }
    }
  } else if (node.kind === 17) {
    var target = dotTarget(node);
    resolveAsExpression(context, target, parentScope);
    if (target.resolvedType !== context.errorType) {
      if (typeIsClass(target.resolvedType)) {
        var child = target.resolvedType.symbol.node.firstChild;
        while (child !== null) {
          __imports.assert(child.kind === 1);
          if (__imports.String_equal(child.symbol.name, node.stringValue)) {
            initializeSymbol(context, child.symbol);
            node.symbol = child.symbol;
            break;
          }
          child = child.nextSibling;
        }
        if (node.symbol !== null) {
          node.resolvedType = node.symbol.resolvedType;
        } else {
          error(context.log, node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_appendNew(__imports.String_append(__imports.String_new("No member named '"), node.stringValue), "' on type '"), typeToString(target.resolvedType)), "'"));
        }
      } else {
        error(context.log, node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_new("The type '"), typeToString(target.resolvedType)), "' has no members"));
      }
    }
  } else if (node.kind === 15) {
    var value = callValue(node);
    resolveAsExpression(context, value, parentScope);
    if (value.resolvedType !== context.errorType) {
      var symbol = value.symbol;
      if (symbol === null || symbol.kind !== 3) {
        error(context.log, value.range, __imports.String_appendNew(__imports.String_append(__imports.String_new("Cannot call value of type '"), typeToString(value.resolvedType)), "'"));
      } else {
        initializeSymbol(context, symbol);
        var returnType = functionReturnType(symbol.node);
        var argumentVariable = symbol.node.firstChild;
        var argumentValue = value.nextSibling;
        while (argumentVariable !== returnType && argumentValue !== null) {
          resolveAsExpression(context, argumentValue, parentScope);
          checkConversion(context, argumentValue, argumentVariable.symbol.resolvedType);
          argumentVariable = argumentVariable.nextSibling;
          argumentValue = argumentValue.nextSibling;
        }
        if (argumentVariable !== returnType) {
          error(context.log, node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_new("Not enough arguments for function '"), symbol.name), "'"));
        } else if (argumentValue !== null) {
          while (argumentValue !== null) {
            resolveAsExpression(context, argumentValue, parentScope);
            argumentValue = argumentValue.nextSibling;
          }
          error(context.log, node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_new("Too many arguments for function '"), symbol.name), "'"));
        }
        node.resolvedType = returnType.resolvedType;
      }
    }
  } else if (node.kind === 11) {
    var value = returnValue(node);
    if (value !== null) {
      resolveAsExpression(context, value, parentScope);
      if (context.currentReturnType !== null) {
        checkConversion(context, value, context.currentReturnType);
      }
    } else if (context.currentReturnType !== null && context.currentReturnType !== context.voidType) {
      error(context.log, node.range, __imports.String_new("Expected return value"));
    }
  } else if (node.kind === 7) {
  } else if (node.kind === 8) {
    resolveAsExpression(context, expressionValue(node), parentScope);
  } else if (node.kind === 13) {
    var value = whileValue(node);
    var body = whileBody(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType);
    resolve(context, body, parentScope);
  } else if (node.kind === 10) {
    var value = ifValue(node);
    var yes = ifTrue(node);
    var no = ifFalse(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType);
    resolve(context, yes, parentScope);
    if (no !== null) {
      resolve(context, no, parentScope);
    }
  } else if (node.kind === 18) {
    var value = hookValue(node);
    var yes = hookTrue(node);
    var no = hookFalse(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType);
    resolve(context, yes, parentScope);
    resolve(context, no, parentScope);
    var commonType = (yes.resolvedType === context.nullType ? no : yes).resolvedType;
    if (yes.resolvedType !== commonType && (yes.resolvedType !== context.nullType || !typeIsReference(context, commonType)) && no.resolvedType !== commonType && (no.resolvedType !== context.nullType || !typeIsReference(context, commonType))) {
      error(context.log, spanRanges(yes.range, no.range), __imports.String_appendNew(__imports.String_append(__imports.String_appendNew(__imports.String_append(__imports.String_new("Type '"), typeToString(yes.resolvedType)), "' is not the same as type '"), typeToString(no.resolvedType)), "'"));
    }
    node.resolvedType = commonType;
  } else if (node.kind === 33) {
    var left = binaryLeft(node);
    var right = binaryRight(node);
    resolveAsExpression(context, left, parentScope);
    resolveAsExpression(context, right, parentScope);
    checkConversion(context, right, left.resolvedType);
    checkStorage(context, left);
    node.resolvedType = left.resolvedType;
  } else if (node.kind === 32 || node.kind === 50 || node.kind === 45 || node.kind === 37 || node.kind === 34 || node.kind === 35 || node.kind === 36 || node.kind === 48 || node.kind === 49) {
    resolveBinary(context, node, parentScope);
    checkBinary(context, node, context.intType, context.intType);
  } else if (node.kind === 41 || node.kind === 42 || node.kind === 39 || node.kind === 40) {
    resolveBinary(context, node, parentScope);
    checkBinary(context, node, context.intType, context.boolType);
  } else if (node.kind === 44 || node.kind === 43) {
    resolveBinary(context, node, parentScope);
    checkBinary(context, node, context.boolType, context.boolType);
  } else if (node.kind === 38 || node.kind === 46) {
    var left = binaryLeft(node);
    var right = binaryRight(node);
    resolveBinary(context, node, parentScope);
    node.resolvedType = context.boolType;
    var leftType = left.resolvedType;
    var rightType = right.resolvedType;
    if (leftType !== context.errorType && rightType !== context.errorType && (leftType === rightType ? leftType === context.voidType : (leftType !== context.nullType || !typeIsReference(context, rightType)) && (rightType !== context.nullType || !typeIsReference(context, leftType)))) {
      error(context.log, node.range, __imports.String_appendNew(__imports.String_append(__imports.String_appendNew(__imports.String_append(__imports.String_new("Cannot compare type '"), typeToString(leftType)), "' with type '"), typeToString(rightType)), "'"));
    }
  } else if (node.kind === 24 || node.kind === 25 || node.kind === 27) {
    resolveUnary(context, node, parentScope, context.intType);
  } else if (node.kind === 26) {
    resolveUnary(context, node, parentScope, context.boolType);
  } else if (node.kind === 21) {
    var type = newType(node);
    resolveAsType(context, type, parentScope);
    if (type.resolvedType !== context.errorType) {
      if (!typeIsClass(type.resolvedType)) {
        error(context.log, type.range, __imports.String_appendNew(__imports.String_append(__imports.String_new("Cannot construct type '"), typeToString(type.resolvedType)), "'"));
      } else {
        node.resolvedType = type.resolvedType;
      }
    }
  } else {
    __imports.assert(false);
  }
}
function check(global, log) {
  var context = new CheckContext();
  context.log = log;
  initialize(context, global, null);
  resolve(context, global, null);
  return context;
}
function CompileResult() {
  this.log = null;
  this.global = null;
  this.context = null;
  this.wasm = null;
  this.js = null;
}
var CompileResult_new = exports.CompileResult_new = function() {
  var result = new CompileResult();
  result.log = new Log();
  result.global = new Node();
  result.global.kind = 0;
  return result;
};
var CompileResult_addInput = exports.CompileResult_addInput = function(result, name, contents) {
  var source = new Source();
  source.name = name;
  source.contents = contents;
  var token = tokenize(source, result.log);
  if (token !== null) {
    var file = parse(token, result.log);
    if (file !== null) {
      while (file.firstChild !== null) {
        var child = file.firstChild;
        remove(child);
        appendChild(result.global, child);
      }
    }
  }
};
var CompileResult_finish = exports.CompileResult_finish = function(result) {
  if (result.log.first === null) {
    result.context = check(result.global, result.log);
    if (result.log.first === null) {
      result.wasm = __imports.ByteArray_new();
      wasmEmit(result.global, result.context, result.wasm);
      result.js = jsEmit(result.global, result.context);
    }
  }
};
var CompileResult_wasm = exports.CompileResult_wasm = function(result) {
  return result.wasm;
};
var CompileResult_js = exports.CompileResult_js = function(result) {
  return result.js;
};
var CompileResult_log = exports.CompileResult_log = function(result) {
  return logToString(result.log);
};
function JsResult() {
  this.context = null;
  this.code = null;
  this.indent = 0;
}
function jsAppendIndent(result) {
  var i = result.indent;
  while (i > 0) {
    result.code = __imports.String_appendNew(result.code, "  ");
    i = i - 1;
  }
}
function jsAppendText(result, text) {
  result.code = __imports.String_appendNew(result.code, text);
}
function jsAppendString(result, text) {
  result.code = __imports.String_append(result.code, text);
}
function jsEmitChildren(result, node) {
  var child = node.firstChild;
  while (child !== null) {
    jsEmitStatement(result, child);
    child = child.nextSibling;
  }
}
function jsEmitBlock(result, node) {
  jsAppendText(result, "{\n");
  result.indent = result.indent + 1;
  jsEmitChildren(result, node);
  result.indent = result.indent - 1;
  jsAppendIndent(result);
  jsAppendText(result, "}");
}
function jsEmitUnary(result, node, parentPrecedence, operator) {
  var isPostfix = isUnaryPostfix(node.kind);
  var operatorPrecedence = isPostfix ? 13 : 12;
  if (parentPrecedence > operatorPrecedence) {
    jsAppendText(result, "(");
  }
  if (!isPostfix) {
    jsAppendText(result, operator);
  }
  jsEmitExpression(result, unaryValue(node), operatorPrecedence);
  if (isPostfix) {
    jsAppendText(result, operator);
  }
  if (parentPrecedence > operatorPrecedence) {
    jsAppendText(result, ")");
  }
}
function jsEmitBinary(result, node, parentPrecedence, operator, operatorPrecedence) {
  var isRightAssociative = node.kind === 33;
  if (parentPrecedence > operatorPrecedence) {
    jsAppendText(result, "(");
  }
  jsEmitExpression(result, binaryLeft(node), isRightAssociative ? operatorPrecedence + 1 : operatorPrecedence);
  jsAppendText(result, operator);
  jsEmitExpression(result, binaryRight(node), isRightAssociative ? operatorPrecedence : operatorPrecedence + 1);
  if (parentPrecedence > operatorPrecedence) {
    jsAppendText(result, ")");
  }
}
function jsEmitExpression(result, node, parentPrecedence) {
  if (node.kind === 20) {
    jsAppendString(result, node.symbol.name);
  } else if (node.kind === 22) {
    jsAppendText(result, "null");
  } else if (node.kind === 14) {
    jsAppendText(result, node.intValue !== 0 ? "true" : "false");
  } else if (node.kind === 19) {
    jsAppendString(result, __imports.String_toString(node.intValue));
  } else if (node.kind === 23) {
    jsAppendString(result, __imports.String_quote(node.stringValue));
  } else if (node.kind === 17) {
    jsEmitExpression(result, dotTarget(node), 14);
    jsAppendText(result, ".");
    jsAppendString(result, node.symbol.name);
  } else if (node.kind === 18) {
    if (parentPrecedence > 1) {
      jsAppendText(result, "(");
    }
    jsEmitExpression(result, hookValue(node), 2);
    jsAppendText(result, " ? ");
    jsEmitExpression(result, hookTrue(node), 1);
    jsAppendText(result, " : ");
    jsEmitExpression(result, hookFalse(node), 1);
    if (parentPrecedence > 1) {
      jsAppendText(result, ")");
    }
  } else if (node.kind === 15) {
    var value = callValue(node);
    if (functionBody(value.symbol.node) === null) {
      jsAppendText(result, "__imports.");
    }
    jsEmitExpression(result, value, 13);
    jsAppendText(result, "(");
    var child = value.nextSibling;
    while (child !== null) {
      jsEmitExpression(result, child, 0);
      child = child.nextSibling;
      if (child !== null) {
        jsAppendText(result, ", ");
      }
    }
    jsAppendText(result, ")");
  } else if (node.kind === 21) {
    jsAppendText(result, "new ");
    jsEmitExpression(result, newType(node), 13);
    jsAppendText(result, "()");
  } else if (node.kind === 24) {
    jsEmitUnary(result, node, parentPrecedence, "~");
  } else if (node.kind === 25) {
    jsEmitUnary(result, node, parentPrecedence, "-");
  } else if (node.kind === 26) {
    jsEmitUnary(result, node, parentPrecedence, "!");
  } else if (node.kind === 27) {
    jsEmitUnary(result, node, parentPrecedence, "+");
  } else if (node.kind === 31) {
    jsEmitUnary(result, node, parentPrecedence, "++");
  } else if (node.kind === 30) {
    jsEmitUnary(result, node, parentPrecedence, "--");
  } else if (node.kind === 29) {
    jsEmitUnary(result, node, parentPrecedence, "++");
  } else if (node.kind === 28) {
    jsEmitUnary(result, node, parentPrecedence, "--");
  } else if (node.kind === 32) {
    jsEmitBinary(result, node, parentPrecedence, " + ", 10);
  } else if (node.kind === 33) {
    jsEmitBinary(result, node, parentPrecedence, " = ", 1);
  } else if (node.kind === 34) {
    jsEmitBinary(result, node, parentPrecedence, " & ", 6);
  } else if (node.kind === 35) {
    jsEmitBinary(result, node, parentPrecedence, " | ", 4);
  } else if (node.kind === 36) {
    jsEmitBinary(result, node, parentPrecedence, " ^ ", 5);
  } else if (node.kind === 37) {
    jsEmitBinary(result, node, parentPrecedence, " / ", 11);
  } else if (node.kind === 38) {
    jsEmitBinary(result, node, parentPrecedence, " === ", 7);
  } else if (node.kind === 39) {
    jsEmitBinary(result, node, parentPrecedence, " > ", 8);
  } else if (node.kind === 40) {
    jsEmitBinary(result, node, parentPrecedence, " >= ", 8);
  } else if (node.kind === 41) {
    jsEmitBinary(result, node, parentPrecedence, " < ", 8);
  } else if (node.kind === 42) {
    jsEmitBinary(result, node, parentPrecedence, " <= ", 8);
  } else if (node.kind === 43) {
    jsEmitBinary(result, node, parentPrecedence, " && ", 3);
  } else if (node.kind === 44) {
    jsEmitBinary(result, node, parentPrecedence, " || ", 2);
  } else if (node.kind === 45) {
    jsEmitBinary(result, node, parentPrecedence, " * ", 11);
  } else if (node.kind === 46) {
    jsEmitBinary(result, node, parentPrecedence, " !== ", 7);
  } else if (node.kind === 47) {
    jsEmitBinary(result, node, parentPrecedence, " % ", 11);
  } else if (node.kind === 48) {
    jsEmitBinary(result, node, parentPrecedence, " << ", 9);
  } else if (node.kind === 49) {
    jsEmitBinary(result, node, parentPrecedence, " >> ", 9);
  } else if (node.kind === 50) {
    jsEmitBinary(result, node, parentPrecedence, " - ", 10);
  } else {
    __imports.assert(false);
  }
}
function jsEmitStatement(result, node) {
  if (node.kind === 9) {
    var body = functionBody(node);
    if (body === null) {
      return;
    }
    jsAppendIndent(result);
    if (isExternSymbol(node.symbol)) {
      jsAppendText(result, "var ");
      jsAppendString(result, node.symbol.name);
      jsAppendText(result, " = exports.");
      jsAppendString(result, node.symbol.name);
      jsAppendText(result, " = function");
    } else {
      jsAppendText(result, "function ");
      jsAppendString(result, node.symbol.name);
    }
    jsAppendText(result, "(");
    var returnType = functionReturnType(node);
    var child = node.firstChild;
    while (child !== returnType) {
      __imports.assert(child.kind === 1);
      if (child !== node.firstChild) {
        jsAppendText(result, ", ");
      }
      jsAppendString(result, child.symbol.name);
      child = child.nextSibling;
    }
    jsAppendText(result, ") ");
    jsEmitBlock(result, functionBody(node));
    jsAppendText(result, isExternSymbol(node.symbol) ? ";\n" : "\n");
  } else if (node.kind === 10) {
    jsAppendIndent(result);
    while (true) {
      jsAppendText(result, "if (");
      jsEmitExpression(result, ifValue(node), 0);
      jsAppendText(result, ") ");
      jsEmitBlock(result, ifTrue(node));
      var no = ifFalse(node);
      if (no === null) {
        jsAppendText(result, "\n");
        break;
      }
      jsAppendText(result, " else ");
      if (no.firstChild === null || no.firstChild !== no.lastChild || no.firstChild.kind !== 10) {
        jsEmitBlock(result, no);
        jsAppendText(result, "\n");
        break;
      }
      node = no.firstChild;
    }
  } else if (node.kind === 13) {
    jsAppendIndent(result);
    jsAppendText(result, "while (");
    jsEmitExpression(result, whileValue(node), 0);
    jsAppendText(result, ") ");
    jsEmitBlock(result, whileBody(node));
    jsAppendText(result, "\n");
  } else if (node.kind === 3) {
    jsAppendIndent(result);
    jsAppendText(result, "break;\n");
  } else if (node.kind === 6) {
    jsAppendIndent(result);
    jsAppendText(result, "continue;\n");
  } else if (node.kind === 8) {
    jsAppendIndent(result);
    jsEmitExpression(result, expressionValue(node), 0);
    jsAppendText(result, ";\n");
  } else if (node.kind === 7) {
  } else if (node.kind === 11) {
    var value = returnValue(node);
    jsAppendIndent(result);
    if (value !== null) {
      jsAppendText(result, "return ");
      jsEmitExpression(result, value, 0);
      jsAppendText(result, ";\n");
    } else {
      jsAppendText(result, "return;\n");
    }
  } else if (node.kind === 2) {
    jsAppendIndent(result);
    jsEmitBlock(result, node);
    jsAppendText(result, "\n");
  } else if (node.kind === 12) {
    jsAppendIndent(result);
    jsAppendText(result, "var ");
    var child = node.firstChild;
    while (child !== null) {
      var value = variableValue(child);
      jsAppendString(result, child.symbol.name);
      child = child.nextSibling;
      if (child !== null) {
        jsAppendText(result, ", ");
      }
      __imports.assert(value !== null);
      jsAppendText(result, " = ");
      jsEmitExpression(result, value, 0);
    }
    jsAppendText(result, ";\n");
  } else if (node.kind === 4) {
    jsAppendIndent(result);
    jsAppendText(result, "function ");
    jsAppendString(result, node.symbol.name);
    jsAppendText(result, "() {\n");
    result.indent = result.indent + 1;
    var child = node.firstChild;
    while (child !== null) {
      __imports.assert(child.kind === 1);
      jsAppendIndent(result);
      jsAppendText(result, "this.");
      jsAppendString(result, child.symbol.name);
      jsAppendText(result, " = ");
      jsEmitExpression(result, variableValue(child), 0);
      jsAppendText(result, ";\n");
      child = child.nextSibling;
    }
    result.indent = result.indent - 1;
    jsAppendIndent(result);
    jsAppendText(result, "}\n");
  } else if (node.kind === 5) {
  } else {
    __imports.assert(false);
  }
}
function jsEmit(global, context) {
  var result = new JsResult();
  result.context = context;
  result.code = __imports.String_new("");
  var child = global.firstChild;
  while (child !== null) {
    jsEmitStatement(result, child);
    child = child.nextSibling;
  }
  return result.code;
}
function Token() {
  this.kind = 0;
  this.range = null;
  this.next = null;
}
function tokenToString(token) {
  if (token === 5) {
    return "ASSIGN";
  }
  if (token === 6) {
    return "BITWISE_AND";
  }
  if (token === 7) {
    return "BITWISE_OR";
  }
  if (token === 8) {
    return "BITWISE_XOR";
  }
  if (token === 39) {
    return "BREAK";
  }
  if (token === 1) {
    return "CHARACTER";
  }
  if (token === 40) {
    return "CLASS";
  }
  if (token === 9) {
    return "COLON";
  }
  if (token === 10) {
    return "COMMA";
  }
  if (token === 11) {
    return "COMPLEMENT";
  }
  if (token === 41) {
    return "CONST";
  }
  if (token === 42) {
    return "CONTINUE";
  }
  if (token === 12) {
    return "DIVIDE";
  }
  if (token === 13) {
    return "DOT";
  }
  if (token === 43) {
    return "ELSE";
  }
  if (token === 0) {
    return "END_OF_FILE";
  }
  if (token === 14) {
    return "EQUAL";
  }
  if (token === 44) {
    return "EXPORT";
  }
  if (token === 45) {
    return "EXTENDS";
  }
  if (token === 46) {
    return "EXTERN";
  }
  if (token === 47) {
    return "FALSE";
  }
  if (token === 48) {
    return "FUNCTION";
  }
  if (token === 15) {
    return "GREATER_THAN";
  }
  if (token === 16) {
    return "GREATER_THAN_EQUAL";
  }
  if (token === 2) {
    return "IDENTIFIER";
  }
  if (token === 49) {
    return "IF";
  }
  if (token === 50) {
    return "IMPLEMENTS";
  }
  if (token === 51) {
    return "IMPORT";
  }
  if (token === 3) {
    return "INT";
  }
  if (token === 52) {
    return "INTERFACE";
  }
  if (token === 17) {
    return "LEFT_BRACE";
  }
  if (token === 18) {
    return "LEFT_BRACKET";
  }
  if (token === 19) {
    return "LEFT_PARENTHESIS";
  }
  if (token === 20) {
    return "LESS_THAN";
  }
  if (token === 21) {
    return "LESS_THAN_EQUAL";
  }
  if (token === 22) {
    return "LOGICAL_AND";
  }
  if (token === 23) {
    return "LOGICAL_OR";
  }
  if (token === 24) {
    return "MINUS";
  }
  if (token === 25) {
    return "MINUS_MINUS";
  }
  if (token === 26) {
    return "MULTIPLY";
  }
  if (token === 53) {
    return "NEW";
  }
  if (token === 27) {
    return "NOT";
  }
  if (token === 28) {
    return "NOT_EQUAL";
  }
  if (token === 54) {
    return "NULL";
  }
  if (token === 29) {
    return "PLUS";
  }
  if (token === 30) {
    return "PLUS_PLUS";
  }
  if (token === 31) {
    return "QUESTION_MARK";
  }
  if (token === 32) {
    return "REMAINDER";
  }
  if (token === 55) {
    return "RETURN";
  }
  if (token === 33) {
    return "RIGHT_BRACE";
  }
  if (token === 34) {
    return "RIGHT_BRACKET";
  }
  if (token === 35) {
    return "RIGHT_PARENTHESIS";
  }
  if (token === 36) {
    return "SEMICOLON";
  }
  if (token === 37) {
    return "SHIFT_LEFT";
  }
  if (token === 38) {
    return "SHIFT_RIGHT";
  }
  if (token === 4) {
    return "STRING";
  }
  if (token === 56) {
    return "THIS";
  }
  if (token === 57) {
    return "TRUE";
  }
  if (token === 58) {
    return "VAR";
  }
  if (token === 59) {
    return "WHILE";
  }
  return null;
}
function isAlpha(c) {
  return c >= 97 && c <= 122 || c >= 65 && c <= 90 || c === 95;
}
function isNumber(c) {
  return c >= 48 && c <= 57;
}
function tokenize(source, log) {
  var first = null;
  var last = null;
  var contents = source.contents;
  var limit = __imports.String_length(contents);
  var i = 0;
  while (i < limit) {
    var start = i;
    var c = __imports.String_get(contents, i);
    i = i + 1;
    if (c === 32 || c === 9 || c === 13 || c === 10) {
      continue;
    }
    var kind = 0;
    if (isAlpha(c)) {
      kind = 2;
      while (i < limit && (isAlpha(__imports.String_get(contents, i)) || isNumber(__imports.String_get(contents, i)))) {
        i = i + 1;
      }
      var text = __imports.String_slice(contents, start, i);
      if (__imports.String_equalNew(text, "break")) {
        kind = 39;
      } else if (__imports.String_equalNew(text, "class")) {
        kind = 40;
      } else if (__imports.String_equalNew(text, "const")) {
        kind = 41;
      } else if (__imports.String_equalNew(text, "continue")) {
        kind = 42;
      } else if (__imports.String_equalNew(text, "else")) {
        kind = 43;
      } else if (__imports.String_equalNew(text, "export")) {
        kind = 44;
      } else if (__imports.String_equalNew(text, "extends")) {
        kind = 45;
      } else if (__imports.String_equalNew(text, "extern")) {
        kind = 46;
      } else if (__imports.String_equalNew(text, "false")) {
        kind = 47;
      } else if (__imports.String_equalNew(text, "function")) {
        kind = 48;
      } else if (__imports.String_equalNew(text, "if")) {
        kind = 49;
      } else if (__imports.String_equalNew(text, "implements")) {
        kind = 50;
      } else if (__imports.String_equalNew(text, "import")) {
        kind = 51;
      } else if (__imports.String_equalNew(text, "interface")) {
        kind = 52;
      } else if (__imports.String_equalNew(text, "new")) {
        kind = 53;
      } else if (__imports.String_equalNew(text, "null")) {
        kind = 54;
      } else if (__imports.String_equalNew(text, "return")) {
        kind = 55;
      } else if (__imports.String_equalNew(text, "this")) {
        kind = 56;
      } else if (__imports.String_equalNew(text, "true")) {
        kind = 57;
      } else if (__imports.String_equalNew(text, "var")) {
        kind = 58;
      } else if (__imports.String_equalNew(text, "while")) {
        kind = 59;
      }
    } else if (isNumber(c)) {
      kind = 3;
      while (i < limit && isNumber(__imports.String_get(contents, i))) {
        i = i + 1;
      }
    } else if (c === 34 || c === 39 || c === 96) {
      while (i < limit) {
        var next = __imports.String_get(contents, i);
        if (i + 1 < limit && next === 92) {
          i = i + 2;
        } else if (next === 10 && c !== 96) {
          break;
        } else {
          i = i + 1;
          if (next === c) {
            kind = c === 39 ? 1 : 4;
            break;
          }
        }
      }
      if (kind === 0) {
        error(log, createRange(source, start, i), __imports.String_new(c === 39 ? "Unterminated character literal" : c === 96 ? "Unterminated template literal" : "Unterminated string literal"));
        return null;
      }
    } else if (c === 37) {
      kind = 32;
    } else if (c === 40) {
      kind = 19;
    } else if (c === 41) {
      kind = 35;
    } else if (c === 42) {
      kind = 26;
    } else if (c === 44) {
      kind = 10;
    } else if (c === 46) {
      kind = 13;
    } else if (c === 58) {
      kind = 9;
    } else if (c === 59) {
      kind = 36;
    } else if (c === 63) {
      kind = 31;
    } else if (c === 91) {
      kind = 18;
    } else if (c === 93) {
      kind = 34;
    } else if (c === 94) {
      kind = 8;
    } else if (c === 123) {
      kind = 17;
    } else if (c === 125) {
      kind = 33;
    } else if (c === 126) {
      kind = 11;
    } else if (c === 47) {
      kind = 12;
      if (i < limit && __imports.String_get(contents, i) === 47) {
        i = i + 1;
        while (i < limit && __imports.String_get(contents, i) !== 10) {
          i = i + 1;
        }
        continue;
      }
      if (i < limit && __imports.String_get(contents, i) === 42) {
        i = i + 1;
        var foundEnd = false;
        while (i < limit) {
          var next = __imports.String_get(contents, i);
          if (next === 42 && i + 1 < limit && __imports.String_get(contents, i + 1) === 47) {
            foundEnd = true;
            i = i + 2;
            break;
          }
          i = i + 1;
        }
        if (!foundEnd) {
          error(log, createRange(source, start, start + 2), __imports.String_new("Unterminated multi-line comment"));
          return null;
        }
        continue;
      }
    } else if (c === 33) {
      kind = 27;
      if (i < limit && __imports.String_get(contents, i) === 61) {
        kind = 28;
        i = i + 1;
        if (i < limit && __imports.String_get(contents, i) === 61) {
          i = i + 1;
          error(log, createRange(source, start, i), __imports.String_new("Use '!=' instead of '!=='"));
        }
      }
    } else if (c === 61) {
      kind = 5;
      if (i < limit && __imports.String_get(contents, i) === 61) {
        kind = 14;
        i = i + 1;
        if (i < limit && __imports.String_get(contents, i) === 61) {
          i = i + 1;
          error(log, createRange(source, start, i), __imports.String_new("Use '==' instead of '==='"));
        }
      }
    } else if (c === 43) {
      kind = 29;
      if (i < limit && __imports.String_get(contents, i) === 43) {
        kind = 30;
        i = i + 1;
      }
    } else if (c === 45) {
      kind = 24;
      if (i < limit && __imports.String_get(contents, i) === 45) {
        kind = 25;
        i = i + 1;
      }
    } else if (c === 38) {
      kind = 6;
      if (i < limit && __imports.String_get(contents, i) === 38) {
        kind = 22;
        i = i + 1;
      }
    } else if (c === 124) {
      kind = 7;
      if (i < limit && __imports.String_get(contents, i) === 124) {
        kind = 23;
        i = i + 1;
      }
    } else if (c === 60) {
      kind = 20;
      if (i < limit) {
        c = __imports.String_get(contents, i);
        if (c === 60) {
          kind = 37;
          i = i + 1;
        } else if (c === 61) {
          kind = 21;
          i = i + 1;
        }
      }
    } else if (c === 62) {
      kind = 15;
      if (i < limit) {
        c = __imports.String_get(contents, i);
        if (c === 62) {
          kind = 38;
          i = i + 1;
        } else if (c === 61) {
          kind = 16;
          i = i + 1;
        }
      }
    }
    var range = createRange(source, start, i);
    if (kind === 0) {
      error(log, range, __imports.String_appendNew(__imports.String_append(__imports.String_new("Syntax error: '"), __imports.String_slice(contents, start, start + 1)), "'"));
      return null;
    }
    var token = new Token();
    token.kind = kind;
    token.range = range;
    if (first === null) {
      first = token;
    } else {
      last.next = token;
    }
    last = token;
  }
  var eof = new Token();
  eof.kind = 0;
  eof.range = createRange(source, limit, limit);
  if (first === null) {
    first = eof;
  } else {
    last.next = eof;
  }
  last = eof;
  return first;
}
function isUnary(kind) {
  return kind >= 24 && kind <= 31;
}
function isUnaryPostfix(kind) {
  return kind >= 28 && kind <= 29;
}
function isBinary(kind) {
  return kind >= 32 && kind <= 50;
}
function isExpression(node) {
  return node.kind >= 14 && node.kind <= 50;
}
function Node() {
  this.kind = 0;
  this.flags = 0;
  this.range = null;
  this.internalRange = null;
  this.parent = null;
  this.firstChild = null;
  this.lastChild = null;
  this.previousSibling = null;
  this.nextSibling = null;
  this.intValue = 0;
  this.stringValue = null;
  this.resolvedType = null;
  this.symbol = null;
  this.scope = null;
}
function childCount(node) {
  var count = 0;
  var child = node.firstChild;
  while (child !== null) {
    count = count + 1;
    child = child.nextSibling;
  }
  return count;
}
function appendChild(node, child) {
  child.parent = node;
  if (node.firstChild === null) {
    node.firstChild = child;
    node.lastChild = child;
  } else {
    child.previousSibling = node.lastChild;
    node.lastChild.nextSibling = child;
    node.lastChild = child;
  }
}
function remove(node) {
  __imports.assert(node.parent !== null);
  if (node.previousSibling !== null) {
    __imports.assert(node.previousSibling.nextSibling === node);
    node.previousSibling.nextSibling = node.nextSibling;
  } else {
    __imports.assert(node.parent.firstChild === node);
    node.parent.firstChild = node.nextSibling;
  }
  if (node.nextSibling !== null) {
    __imports.assert(node.nextSibling.previousSibling === node);
    node.nextSibling.previousSibling = node.previousSibling;
  } else {
    __imports.assert(node.parent.lastChild === node);
    node.parent.lastChild = node.previousSibling;
  }
  node.parent = null;
  node.previousSibling = null;
  node.nextSibling = null;
}
function withRange(node, range) {
  node.range = range;
  return node;
}
function withInternalRange(node, range) {
  node.internalRange = range;
  return node;
}
function createNew(type) {
  __imports.assert(isExpression(type));
  var node = new Node();
  node.kind = 21;
  appendChild(node, type);
  return node;
}
function createHook(test, primary, secondary) {
  __imports.assert(isExpression(test));
  __imports.assert(isExpression(primary));
  __imports.assert(isExpression(secondary));
  var node = new Node();
  node.kind = 18;
  appendChild(node, test);
  appendChild(node, primary);
  appendChild(node, secondary);
  return node;
}
function createNull() {
  var node = new Node();
  node.kind = 22;
  return node;
}
function createBool(value) {
  var node = new Node();
  node.kind = 14;
  node.intValue = value ? 1 : 0;
  return node;
}
function createInt(value) {
  var node = new Node();
  node.kind = 19;
  node.intValue = value;
  return node;
}
function createString(value) {
  var node = new Node();
  node.kind = 23;
  node.stringValue = value;
  return node;
}
function createName(value) {
  var node = new Node();
  node.kind = 20;
  node.stringValue = value;
  return node;
}
function createEmpty() {
  var node = new Node();
  node.kind = 7;
  return node;
}
function createExpression(value) {
  __imports.assert(isExpression(value));
  var node = new Node();
  node.kind = 8;
  appendChild(node, value);
  return node;
}
function createBlock() {
  var node = new Node();
  node.kind = 2;
  return node;
}
function createClass(name) {
  var node = new Node();
  node.kind = 4;
  node.stringValue = name;
  return node;
}
function createIf(value, trueBranch, falseBranch) {
  __imports.assert(isExpression(value));
  __imports.assert(trueBranch.kind === 2);
  __imports.assert(falseBranch === null || falseBranch.kind === 2);
  var node = new Node();
  node.kind = 10;
  appendChild(node, value);
  appendChild(node, trueBranch);
  if (falseBranch !== null) {
    appendChild(node, falseBranch);
  }
  return node;
}
function createWhile(value, body) {
  __imports.assert(isExpression(value));
  __imports.assert(body.kind === 2);
  var node = new Node();
  node.kind = 13;
  appendChild(node, value);
  appendChild(node, body);
  return node;
}
function createReturn(value) {
  __imports.assert(value === null || isExpression(value));
  var node = new Node();
  node.kind = 11;
  if (value !== null) {
    appendChild(node, value);
  }
  return node;
}
function createVariables() {
  var node = new Node();
  node.kind = 12;
  return node;
}
function createConstants() {
  var node = new Node();
  node.kind = 5;
  return node;
}
function createVariable(name, type, value) {
  __imports.assert(type === null || isExpression(type));
  __imports.assert(value === null || isExpression(value));
  var node = new Node();
  node.kind = 1;
  node.stringValue = name;
  appendChild(node, type !== null ? type : createEmpty());
  if (value !== null) {
    appendChild(node, value);
  }
  return node;
}
function createFunction(name) {
  var node = new Node();
  node.kind = 9;
  node.stringValue = name;
  return node;
}
function createUnary(kind, value) {
  __imports.assert(isUnary(kind));
  __imports.assert(isExpression(value));
  var node = new Node();
  node.kind = kind;
  appendChild(node, value);
  return node;
}
function createBinary(kind, left, right) {
  __imports.assert(isBinary(kind));
  __imports.assert(isExpression(left));
  __imports.assert(isExpression(right));
  var node = new Node();
  node.kind = kind;
  appendChild(node, left);
  appendChild(node, right);
  return node;
}
function createCall(value) {
  __imports.assert(isExpression(value));
  var node = new Node();
  node.kind = 15;
  appendChild(node, value);
  return node;
}
function createDot(value, name) {
  __imports.assert(isExpression(value));
  var node = new Node();
  node.kind = 17;
  node.stringValue = name;
  appendChild(node, value);
  return node;
}
function functionReturnType(node) {
  __imports.assert(node.kind === 9);
  __imports.assert(childCount(node) >= 2);
  __imports.assert(isExpression(node.lastChild.previousSibling));
  return node.lastChild.previousSibling;
}
function functionBody(node) {
  __imports.assert(node.kind === 9);
  __imports.assert(childCount(node) >= 2);
  __imports.assert(node.lastChild.kind === 2 || node.lastChild.kind === 7);
  var body = node.lastChild;
  return body.kind === 2 ? body : null;
}
function newType(node) {
  __imports.assert(node.kind === 21);
  __imports.assert(childCount(node) === 1);
  __imports.assert(isExpression(node.firstChild));
  return node.firstChild;
}
function callValue(node) {
  __imports.assert(node.kind === 15);
  __imports.assert(childCount(node) >= 1);
  __imports.assert(isExpression(node.firstChild));
  return node.firstChild;
}
function dotTarget(node) {
  __imports.assert(node.kind === 17);
  __imports.assert(childCount(node) === 1);
  __imports.assert(isExpression(node.firstChild));
  return node.firstChild;
}
function returnValue(node) {
  __imports.assert(node.kind === 11);
  __imports.assert(childCount(node) <= 1);
  __imports.assert(node.firstChild === null || isExpression(node.firstChild));
  return node.firstChild;
}
function variableType(node) {
  __imports.assert(node.kind === 1);
  __imports.assert(childCount(node) <= 2);
  __imports.assert(isExpression(node.firstChild) || node.firstChild.kind === 7);
  var type = node.firstChild;
  return type.kind !== 7 ? type : null;
}
function variableValue(node) {
  __imports.assert(node.kind === 1);
  __imports.assert(childCount(node) <= 2);
  __imports.assert(node.firstChild.nextSibling === null || isExpression(node.firstChild.nextSibling));
  return node.firstChild.nextSibling;
}
function expressionValue(node) {
  __imports.assert(node.kind === 8);
  __imports.assert(childCount(node) === 1);
  __imports.assert(isExpression(node.firstChild));
  return node.firstChild;
}
function binaryLeft(node) {
  __imports.assert(isBinary(node.kind));
  __imports.assert(childCount(node) === 2);
  __imports.assert(isExpression(node.firstChild));
  return node.firstChild;
}
function binaryRight(node) {
  __imports.assert(isBinary(node.kind));
  __imports.assert(childCount(node) === 2);
  __imports.assert(isExpression(node.lastChild));
  return node.lastChild;
}
function unaryValue(node) {
  __imports.assert(isUnary(node.kind));
  __imports.assert(childCount(node) === 1);
  __imports.assert(isExpression(node.firstChild));
  return node.firstChild;
}
function whileValue(node) {
  __imports.assert(node.kind === 13);
  __imports.assert(childCount(node) === 2);
  __imports.assert(isExpression(node.firstChild));
  return node.firstChild;
}
function whileBody(node) {
  __imports.assert(node.kind === 13);
  __imports.assert(childCount(node) === 2);
  __imports.assert(node.lastChild.kind === 2);
  return node.lastChild;
}
function hookValue(node) {
  __imports.assert(node.kind === 18);
  __imports.assert(childCount(node) === 3);
  __imports.assert(isExpression(node.firstChild));
  return node.firstChild;
}
function hookTrue(node) {
  __imports.assert(node.kind === 18);
  __imports.assert(childCount(node) === 3);
  __imports.assert(isExpression(node.firstChild.nextSibling));
  return node.firstChild.nextSibling;
}
function hookFalse(node) {
  __imports.assert(node.kind === 18);
  __imports.assert(childCount(node) === 3);
  __imports.assert(isExpression(node.lastChild));
  return node.lastChild;
}
function ifValue(node) {
  __imports.assert(node.kind === 10);
  __imports.assert(childCount(node) === 2 || childCount(node) === 3);
  __imports.assert(isExpression(node.firstChild));
  return node.firstChild;
}
function ifTrue(node) {
  __imports.assert(node.kind === 10);
  __imports.assert(childCount(node) === 2 || childCount(node) === 3);
  __imports.assert(node.firstChild.nextSibling.kind === 2);
  return node.firstChild.nextSibling;
}
function ifFalse(node) {
  __imports.assert(node.kind === 10);
  __imports.assert(childCount(node) === 2 || childCount(node) === 3);
  __imports.assert(node.firstChild.nextSibling.nextSibling === null || node.firstChild.nextSibling.nextSibling.kind === 2);
  return node.firstChild.nextSibling.nextSibling;
}
function ParserContext() {
  this.current = null;
  this.log = null;
}
function peek(context, kind) {
  return context.current.kind === kind;
}
function eat(context, kind) {
  if (peek(context, kind)) {
    advance(context);
    return true;
  }
  return false;
}
function advance(context) {
  if (!peek(context, 0)) {
    context.current = context.current.next;
  }
}
function unexpectedToken(context) {
  error(context.log, context.current.range, __imports.String_append(__imports.String_new("Unexpected "), __imports.String_new(tokenToString(context.current.kind))));
}
function expect(context, kind) {
  if (!peek(context, kind)) {
    error(context.log, context.current.range, __imports.String_append(__imports.String_append(__imports.String_append(__imports.String_new("Expected "), __imports.String_new(tokenToString(kind))), __imports.String_new(" but found ")), __imports.String_new(tokenToString(context.current.kind))));
    return false;
  }
  advance(context);
  return true;
}
function parseInt(range) {
  var i = range.start;
  var value = 0;
  while (i < range.end) {
    value = value * 10 + __imports.String_get(range.source.contents, i) - 48;
    i = i + 1;
  }
  return value;
}
function parseUnaryPrefix(context, kind) {
  __imports.assert(isUnary(kind));
  var token = context.current;
  advance(context);
  var value = parseExpression(context, 12);
  if (value === null) {
    return null;
  }
  return withRange(createUnary(kind, value), spanRanges(token.range, value.range));
}
function parseBinary(context, kind, left, localPrecedence, operatorPrecedence) {
  if (localPrecedence >= operatorPrecedence) {
    return left;
  }
  advance(context);
  var right = parseExpression(context, operatorPrecedence === 1 ? 0 : operatorPrecedence);
  if (right === null) {
    return null;
  }
  return withRange(createBinary(kind, left, right), spanRanges(left.range, right.range));
}
function parseUnaryPostfix(context, kind, value, localPrecedence) {
  if (localPrecedence >= 13) {
    return value;
  }
  var token = context.current;
  advance(context);
  return withRange(createUnary(kind, value), spanRanges(value.range, token.range));
}
function parseQuotedString(context, range) {
  __imports.assert(range.end - range.start >= 2);
  var text = rangeToString(range);
  var end = 1;
  var limit = __imports.String_length(text) - 1;
  var start = end;
  var result = __imports.String_new("");
  while (end < limit) {
    var c = __imports.String_get(text, end);
    if (c === 92) {
      result = __imports.String_append(result, __imports.String_slice(text, start, end));
      end = end + 1;
      start = end + 1;
      c = __imports.String_get(text, end);
      if (c === 48) {
        result = __imports.String_appendNew(result, "");
      } else if (c === 116) {
        result = __imports.String_appendNew(result, "\t");
      } else if (c === 110) {
        result = __imports.String_appendNew(result, "\n");
      } else if (c === 114) {
        result = __imports.String_appendNew(result, "\r");
      } else if (c === 34 || c === 39 || c === 96 || c === 10 || c === 92) {
        start = end;
      } else {
        var escape = createRange(range.source, range.start + end - 1, range.start + end + 1);
        error(context.log, escape, __imports.String_append(__imports.String_append(__imports.String_new("Invalid escape code '"), rangeToString(escape)), __imports.String_new("'")));
        return null;
      }
    }
    end = end + 1;
  }
  return __imports.String_append(result, __imports.String_slice(text, start, end));
}
function parsePrefix(context) {
  var token = context.current;
  if (eat(context, 54)) {
    return withRange(createNull(), token.range);
  }
  if (peek(context, 1)) {
    var text = parseQuotedString(context, token.range);
    if (text === null) {
      return null;
    }
    if (__imports.String_length(text) !== 1) {
      error(context.log, token.range, __imports.String_new("Invalid character literal"));
      return null;
    }
    advance(context);
    return withRange(createInt(__imports.String_get(text, 0)), token.range);
  }
  if (peek(context, 4)) {
    var text = parseQuotedString(context, token.range);
    if (text === null) {
      return null;
    }
    advance(context);
    return withRange(createString(text), token.range);
  }
  if (peek(context, 3)) {
    var value = parseInt(token.range);
    advance(context);
    return withRange(createInt(value), token.range);
  }
  if (eat(context, 57)) {
    return withRange(createBool(true), token.range);
  }
  if (eat(context, 47)) {
    return withRange(createBool(false), token.range);
  }
  if (peek(context, 2)) {
    var value = rangeToString(token.range);
    advance(context);
    return withRange(createName(value), token.range);
  }
  if (eat(context, 53)) {
    var type = parseType(context);
    if (type === null || !expect(context, 19)) {
      return null;
    }
    var close = context.current;
    if (!expect(context, 35)) {
      return null;
    }
    return withRange(createNew(type), spanRanges(token.range, close.range));
  }
  if (eat(context, 19)) {
    var value = parseExpression(context, 0);
    if (value === null || !expect(context, 35)) {
      return null;
    }
    return value;
  }
  if (peek(context, 27)) {
    return parseUnaryPrefix(context, 26);
  }
  if (peek(context, 24)) {
    return parseUnaryPrefix(context, 25);
  }
  if (peek(context, 25)) {
    return parseUnaryPrefix(context, 30);
  }
  if (peek(context, 29)) {
    return parseUnaryPrefix(context, 27);
  }
  if (peek(context, 30)) {
    return parseUnaryPrefix(context, 31);
  }
  if (peek(context, 11)) {
    return parseUnaryPrefix(context, 24);
  }
  unexpectedToken(context);
  return null;
}
function parseInfix(context, precedence, node) {
  var token = context.current;
  if (peek(context, 5)) {
    return parseBinary(context, 33, node, precedence, 1);
  }
  if (peek(context, 6)) {
    return parseBinary(context, 34, node, precedence, 6);
  }
  if (peek(context, 7)) {
    return parseBinary(context, 35, node, precedence, 4);
  }
  if (peek(context, 8)) {
    return parseBinary(context, 36, node, precedence, 5);
  }
  if (peek(context, 12)) {
    return parseBinary(context, 37, node, precedence, 11);
  }
  if (peek(context, 14)) {
    return parseBinary(context, 38, node, precedence, 7);
  }
  if (peek(context, 15)) {
    return parseBinary(context, 39, node, precedence, 8);
  }
  if (peek(context, 16)) {
    return parseBinary(context, 40, node, precedence, 8);
  }
  if (peek(context, 20)) {
    return parseBinary(context, 41, node, precedence, 8);
  }
  if (peek(context, 21)) {
    return parseBinary(context, 42, node, precedence, 8);
  }
  if (peek(context, 22)) {
    return parseBinary(context, 43, node, precedence, 3);
  }
  if (peek(context, 23)) {
    return parseBinary(context, 44, node, precedence, 2);
  }
  if (peek(context, 24)) {
    return parseBinary(context, 50, node, precedence, 10);
  }
  if (peek(context, 26)) {
    return parseBinary(context, 45, node, precedence, 11);
  }
  if (peek(context, 28)) {
    return parseBinary(context, 46, node, precedence, 7);
  }
  if (peek(context, 29)) {
    return parseBinary(context, 32, node, precedence, 10);
  }
  if (peek(context, 32)) {
    return parseBinary(context, 47, node, precedence, 11);
  }
  if (peek(context, 37)) {
    return parseBinary(context, 48, node, precedence, 9);
  }
  if (peek(context, 38)) {
    return parseBinary(context, 49, node, precedence, 9);
  }
  if (peek(context, 30)) {
    return parseUnaryPostfix(context, 29, node, precedence);
  }
  if (peek(context, 25)) {
    return parseUnaryPostfix(context, 28, node, precedence);
  }
  if (peek(context, 19) && precedence < 13) {
    advance(context);
    var call = createCall(node);
    if (!peek(context, 35)) {
      while (true) {
        var value = parseExpression(context, 0);
        if (value === null) {
          return null;
        }
        appendChild(call, value);
        if (!eat(context, 10)) {
          break;
        }
      }
    }
    var close = context.current;
    if (!expect(context, 35)) {
      return null;
    }
    return withInternalRange(withRange(call, spanRanges(node.range, close.range)), spanRanges(token.range, close.range));
  }
  if (peek(context, 31) && precedence < 1) {
    advance(context);
    var middle = parseExpression(context, 0);
    if (middle === null || !expect(context, 9)) {
      return null;
    }
    var right = parseExpression(context, 0);
    if (right === null) {
      return null;
    }
    return withRange(createHook(node, middle, right), spanRanges(node.range, right.range));
  }
  if (peek(context, 13) && precedence < 14) {
    advance(context);
    var name = context.current;
    if (!expect(context, 2)) {
      return null;
    }
    return withInternalRange(withRange(createDot(node, rangeToString(name.range)), spanRanges(node.range, name.range)), name.range);
  }
  return node;
}
function parseExpression(context, precedence) {
  var node = parsePrefix(context);
  if (node === null) {
    return null;
  }
  __imports.assert(node.range !== null);
  while (true) {
    var result = parseInfix(context, precedence, node);
    if (result === null) {
      return null;
    }
    if (result === node) {
      break;
    }
    node = result;
    __imports.assert(node.range !== null);
  }
  return node;
}
function parseType(context) {
  return parseExpression(context, 13);
}
function parseIf(context) {
  var token = context.current;
  __imports.assert(token.kind === 49);
  advance(context);
  if (!expect(context, 19)) {
    return null;
  }
  var value = parseExpression(context, 0);
  if (value === null || !expect(context, 35)) {
    return null;
  }
  var trueBranch = parseBody(context);
  if (trueBranch === null) {
    return null;
  }
  var falseBranch = null;
  if (eat(context, 43)) {
    falseBranch = parseBody(context);
    if (falseBranch === null) {
      return null;
    }
  }
  return withRange(createIf(value, trueBranch, falseBranch), spanRanges(token.range, (falseBranch !== null ? falseBranch : trueBranch).range));
}
function parseWhile(context) {
  var token = context.current;
  __imports.assert(token.kind === 59);
  advance(context);
  if (!expect(context, 19)) {
    return null;
  }
  var value = parseExpression(context, 0);
  if (value === null || !expect(context, 35)) {
    return null;
  }
  var body = parseBody(context);
  if (body === null) {
    return null;
  }
  return withRange(createWhile(value, body), spanRanges(token.range, body.range));
}
function parseBody(context) {
  var node = parseStatement(context);
  if (node === null) {
    return null;
  }
  if (node.kind === 2) {
    return node;
  }
  var block = createBlock();
  appendChild(block, node);
  return withRange(block, node.range);
}
function parseBlock(context) {
  var open = context.current;
  if (!expect(context, 17)) {
    return null;
  }
  var block = createBlock();
  if (!parseStatements(context, block)) {
    return null;
  }
  var close = context.current;
  if (!expect(context, 33)) {
    return null;
  }
  return withRange(block, spanRanges(open.range, close.range));
}
function parseReturn(context) {
  var token = context.current;
  __imports.assert(token.kind === 55);
  advance(context);
  var value = null;
  if (!peek(context, 36)) {
    value = parseExpression(context, 0);
    if (value === null) {
      return null;
    }
  }
  var semicolon = context.current;
  if (!expect(context, 36)) {
    return null;
  }
  return withRange(createReturn(value), spanRanges(token.range, semicolon.range));
}
function parseClass(context, flags) {
  var token = context.current;
  __imports.assert(token.kind === 40);
  advance(context);
  var name = context.current;
  if (!expect(context, 2) || !expect(context, 17)) {
    return null;
  }
  var node = createClass(rangeToString(name.range));
  node.flags = flags;
  while (!peek(context, 0) && !peek(context, 33)) {
    if (parseVariables(context, 0, node) === null) {
      return null;
    }
  }
  var close = context.current;
  if (!expect(context, 33)) {
    return null;
  }
  return withInternalRange(withRange(node, spanRanges(token.range, close.range)), name.range);
}
function parseFunction(context, flags) {
  var token = context.current;
  __imports.assert(token.kind === 48);
  advance(context);
  var name = context.current;
  if (!expect(context, 2) || !expect(context, 19)) {
    return null;
  }
  var node = createFunction(rangeToString(name.range));
  node.flags = flags;
  if (!peek(context, 35)) {
    while (true) {
      var argument = context.current;
      if (!expect(context, 2) || !expect(context, 9)) {
        return null;
      }
      var type = parseType(context);
      if (type === null) {
        return null;
      }
      var variable = createVariable(rangeToString(argument.range), type, null);
      appendChild(node, withInternalRange(withRange(variable, spanRanges(argument.range, type.range)), argument.range));
      if (!eat(context, 10)) {
        break;
      }
    }
  }
  if (!expect(context, 35) || !expect(context, 9)) {
    return null;
  }
  var returnType = parseType(context);
  if (returnType === null) {
    return null;
  }
  appendChild(node, returnType);
  var block = null;
  var semicolon = context.current;
  if (eat(context, 36)) {
    block = withRange(createEmpty(), semicolon.range);
  } else {
    block = parseBlock(context);
    if (block === null) {
      return null;
    }
  }
  appendChild(node, block);
  return withInternalRange(withRange(node, spanRanges(token.range, block.range)), name.range);
}
function parseVariables(context, flags, parent) {
  var token = context.current;
  if (parent === null) {
    __imports.assert(token.kind === 58 || token.kind === 41);
    advance(context);
  }
  var node = token.kind === 41 ? createConstants() : createVariables();
  while (true) {
    var name = context.current;
    if (!expect(context, 2)) {
      return null;
    }
    var type = null;
    if (eat(context, 9)) {
      type = parseType(context);
      if (type === null) {
        return null;
      }
    }
    var value = null;
    if (eat(context, 5)) {
      value = parseExpression(context, 0);
      if (value === null) {
        return null;
      }
      if (parent !== null) {
        error(context.log, value.range, __imports.String_new("Inline initialization of instance variables is not supported yet"));
      }
    }
    var range = value !== null ? spanRanges(name.range, value.range) : type !== null ? spanRanges(name.range, type.range) : name.range;
    var variable = createVariable(rangeToString(name.range), type, value);
    variable.flags = flags;
    appendChild(parent !== null ? parent : node, withInternalRange(withRange(variable, range), name.range));
    if (!eat(context, 10)) {
      break;
    }
  }
  var semicolon = context.current;
  if (!expect(context, 36)) {
    return null;
  }
  return parent !== null ? parent : withRange(node, spanRanges(token.range, semicolon.range));
}
function parseLoopJump(context, kind) {
  var token = context.current;
  advance(context);
  if (!expect(context, 36)) {
    return null;
  }
  var node = new Node();
  node.kind = kind;
  return withRange(node, token.range);
}
function parseStatement(context) {
  var flags = 0;
  if (eat(context, 46)) {
    flags = flags | 1;
  }
  if (peek(context, 41) || peek(context, 58)) {
    return parseVariables(context, flags, null);
  }
  if (peek(context, 48)) {
    return parseFunction(context, flags);
  }
  if (peek(context, 40)) {
    return parseClass(context, flags);
  }
  if (flags !== 0) {
    unexpectedToken(context);
    return null;
  }
  if (peek(context, 17)) {
    return parseBlock(context);
  }
  if (peek(context, 39)) {
    return parseLoopJump(context, 3);
  }
  if (peek(context, 42)) {
    return parseLoopJump(context, 6);
  }
  if (peek(context, 49)) {
    return parseIf(context);
  }
  if (peek(context, 59)) {
    return parseWhile(context);
  }
  if (peek(context, 55)) {
    return parseReturn(context);
  }
  if (peek(context, 36)) {
    var token = context.current;
    advance(context);
    return withRange(createEmpty(), token.range);
  }
  var value = parseExpression(context, 0);
  if (value === null) {
    return null;
  }
  var semicolon = context.current;
  if (!expect(context, 36)) {
    return null;
  }
  return withRange(createExpression(value), spanRanges(value.range, semicolon.range));
}
function parseStatements(context, parent) {
  while (!peek(context, 0) && !peek(context, 33)) {
    var child = parseStatement(context);
    if (child === null) {
      return false;
    }
    appendChild(parent, child);
  }
  return true;
}
function parse(firstToken, log) {
  var context = new ParserContext();
  context.current = firstToken;
  context.log = log;
  var global = new Node();
  global.kind = 0;
  if (!parseStatements(context, global)) {
    return null;
  }
  return global;
}
function String() {
}
function ByteArray() {
}
function Source() {
  this.name = null;
  this.contents = null;
}
function Range() {
  this.source = null;
  this.start = 0;
  this.end = 0;
}
function Diagnostic() {
  this.range = null;
  this.message = null;
  this.next = null;
}
function Log() {
  this.first = null;
  this.last = null;
}
function rangeToString(range) {
  return __imports.String_slice(range.source.contents, range.start, range.end);
}
function logToString(log) {
  var result = __imports.String_new("");
  var d = log.first;
  while (d !== null) {
    var lineRange = enclosingLine(d.range);
    var column = d.range.start - lineRange.start;
    var line = 0;
    var i = 0;
    while (i < lineRange.start) {
      if (__imports.String_get(lineRange.source.contents, i) === 10) {
        line = line + 1;
      }
      i = i + 1;
    }
    result = __imports.String_append(result, d.range.source.name);
    result = __imports.String_appendNew(result, ":");
    result = __imports.String_append(result, __imports.String_toString(line + 1));
    result = __imports.String_appendNew(result, ":");
    result = __imports.String_append(result, __imports.String_toString(column + 1));
    result = __imports.String_appendNew(result, ": error: ");
    result = __imports.String_append(result, d.message);
    result = __imports.String_appendNew(result, "\n");
    result = __imports.String_append(result, rangeToString(lineRange));
    result = __imports.String_appendNew(result, "\n");
    i = 0;
    while (i < column) {
      result = __imports.String_appendNew(result, " ");
      i = i + 1;
    }
    if (d.range.end - d.range.start <= 1) {
      result = __imports.String_appendNew(result, "^");
    } else {
      i = d.range.start;
      while (i < d.range.end && i < lineRange.end) {
        result = __imports.String_appendNew(result, "~");
        i = i + 1;
      }
    }
    result = __imports.String_appendNew(result, "\n");
    d = d.next;
  }
  return result;
}
function appendDiagnostic(log, diagnostic) {
  if (log.first === null) {
    log.first = diagnostic;
    log.last = diagnostic;
  } else {
    log.last.next = diagnostic;
    log.last = diagnostic;
  }
}
function error(log, range, message) {
  var diagnostic = new Diagnostic();
  diagnostic.range = range;
  diagnostic.message = message;
  appendDiagnostic(log, diagnostic);
}
function createRange(source, start, end) {
  __imports.assert(start <= end);
  var range = new Range();
  range.source = source;
  range.start = start;
  range.end = end;
  return range;
}
function spanRanges(left, right) {
  __imports.assert(left.source === right.source);
  __imports.assert(left.end <= right.start);
  return createRange(left.source, left.start, right.end);
}
function enclosingLine(range) {
  var contents = range.source.contents;
  var start = range.start;
  var end = range.start;
  while (start > 0 && __imports.String_get(contents, start - 1) !== 10) {
    start = start - 1;
  }
  while (end + 1 < __imports.String_length(contents) && __imports.String_get(contents, end) !== 10) {
    end = end + 1;
  }
  return createRange(range.source, start, end);
}
function WasmType() {
  this.id = 0;
  this.next = null;
}
function WasmSignature() {
  this.argumentTypes = null;
  this.returnType = null;
  this.next = null;
}
function wasmAreSignaturesEqual(a, b) {
  __imports.assert(a.returnType !== null);
  __imports.assert(b.returnType !== null);
  __imports.assert(a.returnType.next === null);
  __imports.assert(b.returnType.next === null);
  var x = a.argumentTypes;
  var y = b.argumentTypes;
  while (x !== null && y !== null) {
    if (x.id !== y.id) {
      return false;
    }
    x = x.next;
    y = y.next;
  }
  if (x !== null || y !== null) {
    return false;
  }
  if (a.returnType.id !== b.returnType.id) {
    return false;
  }
  return true;
}
function WasmFunction() {
  this.name = null;
  this.signatureIndex = 0;
  this.body = null;
  this.isExported = false;
  this.intLocalCount = 0;
  this.next = null;
}
function WasmImport() {
  this.signatureIndex = 0;
  this.module = null;
  this.name = null;
  this.next = null;
}
function WasmModule() {
  this.firstImport = null;
  this.lastImport = null;
  this.importCount = 0;
  this.firstFunction = null;
  this.lastFunction = null;
  this.functionCount = 0;
  this.firstSignature = null;
  this.lastSignature = null;
  this.signatureCount = 0;
  this.memoryInitializer = null;
}
function wasmAllocateImport(module, signatureIndex, mod, name) {
  var result = new WasmImport();
  result.signatureIndex = signatureIndex;
  result.module = mod;
  result.name = name;
  if (module.firstImport === null) {
    module.firstImport = result;
  } else {
    module.lastImport.next = result;
  }
  module.lastImport = result;
  module.importCount = module.importCount + 1;
  return result;
}
function wasmAllocateFunction(module, name, signatureIndex, body) {
  var fn = new WasmFunction();
  fn.name = name;
  fn.signatureIndex = signatureIndex;
  fn.body = body;
  if (module.firstFunction === null) {
    module.firstFunction = fn;
  } else {
    module.lastFunction.next = fn;
  }
  module.lastFunction = fn;
  module.functionCount = module.functionCount + 1;
  return fn;
}
function wasmAllocateSignature(module, argumentTypes, returnType) {
  __imports.assert(returnType !== null);
  __imports.assert(returnType.next === null);
  var signature = new WasmSignature();
  signature.argumentTypes = argumentTypes;
  signature.returnType = returnType;
  var check = module.firstSignature;
  var i = 0;
  while (check !== null) {
    if (wasmAreSignaturesEqual(signature, check)) {
      return i;
    }
    check = check.next;
    i = i + 1;
  }
  if (module.firstSignature === null) {
    module.firstSignature = signature;
  } else {
    module.lastSignature.next = signature;
  }
  module.lastSignature = signature;
  module.signatureCount = module.signatureCount + 1;
  return i;
}
function wasmPatchVarUnsigned(array, offset, value, maxValue) {
  while (true) {
    var byte = value & 127;
    value = value >> 7 & 33554431;
    maxValue = maxValue >> 7 & 33554431;
    if (maxValue !== 0) {
      byte = byte | 128;
    }
    __imports.ByteArray_setByte(array, offset, byte);
    offset = offset + 1;
    if (maxValue === 0) {
      break;
    }
  }
}
function wasmWriteVarUnsigned(array, value) {
  while (true) {
    var byte = value & 127;
    value = value >> 7 & 33554431;
    if (value !== 0) {
      byte = byte | 128;
    }
    __imports.ByteArray_appendByte(array, byte);
    if (value === 0) {
      break;
    }
  }
}
function wasmWriteVarSigned(array, value) {
  while (true) {
    var byte = value & 127;
    value = value >> 7;
    var done = value === 0 && (byte & 64) === 0 || value === -1 && (byte & 64) !== 0;
    if (!done) {
      byte = byte | 128;
    }
    __imports.ByteArray_appendByte(array, byte);
    if (done) {
      break;
    }
  }
}
function wasmWriteLengthPrefixedString(array, value) {
  var length = __imports.String_length(value);
  wasmWriteVarUnsigned(array, length);
  var i = 0;
  while (i < length) {
    __imports.ByteArray_appendByte(array, __imports.String_get(value, i));
    i = i + 1;
  }
}
function wasmStartSection(array, name) {
  var offset = __imports.ByteArray_length(array);
  wasmWriteVarUnsigned(array, ~0);
  wasmWriteLengthPrefixedString(array, name);
  return offset;
}
function wasmFinishSection(array, offset) {
  wasmPatchVarUnsigned(array, offset, __imports.ByteArray_length(array) - offset - 5, ~0);
}
function wasmEmitSignatures(array, module) {
  var section = wasmStartSection(array, __imports.String_new("signatures"));
  wasmWriteVarUnsigned(array, module.signatureCount);
  var signature = module.firstSignature;
  while (signature !== null) {
    var count = 0;
    var type = signature.argumentTypes;
    while (type !== null) {
      count = count + 1;
      type = type.next;
    }
    wasmWriteVarUnsigned(array, count);
    wasmWriteVarUnsigned(array, signature.returnType.id);
    type = signature.argumentTypes;
    while (type !== null) {
      wasmWriteVarUnsigned(array, type.id);
      type = type.next;
    }
    signature = signature.next;
  }
  wasmFinishSection(array, section);
}
function wasmEmitImportTable(array, module) {
  if (module.firstImport === null) {
    return;
  }
  var section = wasmStartSection(array, __imports.String_new("import_table"));
  wasmWriteVarUnsigned(array, module.importCount);
  var current = module.firstImport;
  while (current !== null) {
    wasmWriteVarUnsigned(array, current.signatureIndex);
    wasmWriteLengthPrefixedString(array, current.module);
    wasmWriteLengthPrefixedString(array, current.name);
    current = current.next;
  }
  wasmFinishSection(array, section);
}
function wasmEmitFunctionSignatures(array, module) {
  if (module.firstFunction === null) {
    return;
  }
  var section = wasmStartSection(array, __imports.String_new("function_signatures"));
  wasmWriteVarUnsigned(array, module.functionCount);
  var fn = module.firstFunction;
  while (fn !== null) {
    wasmWriteVarUnsigned(array, fn.signatureIndex);
    fn = fn.next;
  }
  wasmFinishSection(array, section);
}
function wasmEmitMemory(array, module) {
  var section = wasmStartSection(array, __imports.String_new("memory"));
  wasmWriteVarUnsigned(array, 256);
  wasmWriteVarUnsigned(array, 256);
  wasmWriteVarUnsigned(array, 1);
  wasmFinishSection(array, section);
}
function wasmEmitExportTable(array, module) {
  var exportedCount = 0;
  var fn = module.firstFunction;
  while (fn !== null) {
    if (fn.isExported) {
      exportedCount = exportedCount + 1;
    }
    fn = fn.next;
  }
  if (exportedCount === 0) {
    return;
  }
  var section = wasmStartSection(array, __imports.String_new("export_table"));
  wasmWriteVarUnsigned(array, exportedCount);
  var i = 0;
  fn = module.firstFunction;
  while (fn !== null) {
    if (fn.isExported) {
      wasmWriteVarUnsigned(array, i);
      wasmWriteLengthPrefixedString(array, fn.name);
    }
    fn = fn.next;
    i = i + 1;
  }
  wasmFinishSection(array, section);
}
function emitBinaryExpression(array, node, opcode) {
  __imports.ByteArray_appendByte(array, opcode);
  wasmEmitNode(array, binaryLeft(node));
  wasmEmitNode(array, binaryRight(node));
}
function wasmEmitNode(array, node) {
  if (node.kind === 2) {
    __imports.ByteArray_appendByte(array, 1);
    var offset = __imports.ByteArray_length(array);
    wasmWriteVarUnsigned(array, ~0);
    var count = 0;
    var child = node.firstChild;
    while (child !== null) {
      count = count + wasmEmitNode(array, child);
      child = child.nextSibling;
    }
    wasmPatchVarUnsigned(array, offset, count, ~0);
  } else if (node.kind === 13) {
    var value = whileValue(node);
    var body = whileBody(node);
    if (value.kind === 14 && value.intValue === 0) {
      return 0;
    }
    __imports.ByteArray_appendByte(array, 2);
    var offset = __imports.ByteArray_length(array);
    wasmWriteVarUnsigned(array, ~0);
    var count = 0;
    if (value.kind !== 14) {
      __imports.ByteArray_appendByte(array, 7);
      wasmWriteVarUnsigned(array, 1);
      __imports.ByteArray_appendByte(array, 0);
      __imports.ByteArray_appendByte(array, 90);
      wasmEmitNode(array, value);
      count = count + 1;
    }
    var child = body.firstChild;
    while (child !== null) {
      count = count + wasmEmitNode(array, child);
      child = child.nextSibling;
    }
    __imports.ByteArray_appendByte(array, 6);
    wasmWriteVarUnsigned(array, 0);
    __imports.ByteArray_appendByte(array, 0);
    count = count + 1;
    wasmPatchVarUnsigned(array, offset, count, ~0);
  } else if (node.kind === 3 || node.kind === 6) {
    var label = 0;
    var parent = node.parent;
    while (parent !== null && parent.kind !== 13) {
      if (parent.kind === 2) {
        label = label + 1;
      }
      parent = parent.parent;
    }
    __imports.assert(label > 0);
    __imports.ByteArray_appendByte(array, 6);
    wasmWriteVarUnsigned(array, label - (node.kind === 3 ? 0 : 1));
    __imports.ByteArray_appendByte(array, 0);
  } else if (node.kind === 7) {
    return 0;
  } else if (node.kind === 8) {
    wasmEmitNode(array, expressionValue(node));
  } else if (node.kind === 11) {
    var value = returnValue(node);
    __imports.ByteArray_appendByte(array, 20);
    if (value !== null) {
      wasmEmitNode(array, value);
    }
  } else if (node.kind === 12) {
    var count = 0;
    var child = node.firstChild;
    while (child !== null) {
      __imports.assert(child.kind === 1);
      count = count + wasmEmitNode(array, child);
      child = child.nextSibling;
    }
    return count;
  } else if (node.kind === 10) {
    var branch = ifFalse(node);
    __imports.ByteArray_appendByte(array, branch === null ? 3 : 4);
    wasmEmitNode(array, ifValue(node));
    wasmEmitNode(array, ifTrue(node));
    if (branch !== null) {
      wasmEmitNode(array, branch);
    }
  } else if (node.kind === 18) {
    __imports.ByteArray_appendByte(array, 4);
    wasmEmitNode(array, hookValue(node));
    wasmEmitNode(array, hookTrue(node));
    wasmEmitNode(array, hookFalse(node));
  } else if (node.kind === 1) {
    var value = variableValue(node);
    if (node.symbol.kind === 7) {
      __imports.ByteArray_appendByte(array, 15);
      wasmWriteVarUnsigned(array, node.symbol.offset);
      if (value !== null) {
        wasmEmitNode(array, value);
      } else {
        __imports.ByteArray_appendByte(array, 10);
        wasmWriteVarSigned(array, 0);
      }
    } else {
      __imports.assert(false);
    }
  } else if (node.kind === 20) {
    if (node.symbol.kind === 4 || node.symbol.kind === 7) {
      __imports.ByteArray_appendByte(array, 14);
      wasmWriteVarUnsigned(array, node.symbol.offset);
    } else {
      __imports.assert(false);
    }
  } else if (node.kind === 22) {
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, 0);
  } else if (node.kind === 19 || node.kind === 14) {
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, node.intValue);
  } else if (node.kind === 23) {
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, node.intValue);
  } else if (node.kind === 15) {
    var value = callValue(node);
    var symbol = value.symbol;
    __imports.assert(symbol.kind === 3);
    if (functionBody(symbol.node) === null) {
      __imports.ByteArray_appendByte(array, 31);
      wasmWriteVarUnsigned(array, symbol.offset);
    } else {
      __imports.ByteArray_appendByte(array, 18);
      wasmWriteVarUnsigned(array, symbol.offset);
    }
    var child = value.nextSibling;
    while (child !== null) {
      wasmEmitNode(array, child);
      child = child.nextSibling;
    }
  } else if (node.kind === 21) {
    var type = newType(node);
    __imports.assert(type.symbol.kind === 0);
    __imports.ByteArray_appendByte(array, 31);
    wasmWriteVarUnsigned(array, 0);
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, type.symbol.offset);
  } else if (node.kind === 27) {
    wasmEmitNode(array, unaryValue(node));
  } else if (node.kind === 25) {
    __imports.ByteArray_appendByte(array, 65);
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, 0);
    wasmEmitNode(array, unaryValue(node));
  } else if (node.kind === 24) {
    __imports.ByteArray_appendByte(array, 73);
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, ~0);
    wasmEmitNode(array, unaryValue(node));
  } else if (node.kind === 26) {
    __imports.ByteArray_appendByte(array, 90);
    wasmEmitNode(array, unaryValue(node));
  } else if (node.kind === 17) {
    var symbol = node.symbol;
    if (symbol.kind === 6) {
      __imports.ByteArray_appendByte(array, 42);
      wasmWriteVarUnsigned(array, 2);
      wasmWriteVarUnsigned(array, symbol.offset);
      wasmEmitNode(array, dotTarget(node));
    } else {
      __imports.assert(false);
    }
  } else if (node.kind === 33) {
    var left = binaryLeft(node);
    var symbol = left.symbol;
    if (symbol.kind === 6) {
      __imports.assert(left.kind === 17);
      __imports.ByteArray_appendByte(array, 51);
      wasmWriteVarUnsigned(array, 2);
      wasmWriteVarUnsigned(array, symbol.offset);
      wasmEmitNode(array, dotTarget(left));
      wasmEmitNode(array, binaryRight(node));
    } else if (symbol.kind === 4 || symbol.kind === 7) {
      __imports.ByteArray_appendByte(array, 15);
      wasmWriteVarUnsigned(array, symbol.offset);
      wasmEmitNode(array, binaryRight(node));
    } else {
      __imports.assert(false);
    }
  } else if (node.kind === 32) {
    emitBinaryExpression(array, node, 64);
  } else if (node.kind === 50) {
    emitBinaryExpression(array, node, 65);
  } else if (node.kind === 45) {
    emitBinaryExpression(array, node, 66);
  } else if (node.kind === 37) {
    emitBinaryExpression(array, node, 67);
  } else if (node.kind === 47) {
    emitBinaryExpression(array, node, 69);
  } else if (node.kind === 48) {
    emitBinaryExpression(array, node, 74);
  } else if (node.kind === 49) {
    emitBinaryExpression(array, node, 76);
  } else if (node.kind === 34) {
    emitBinaryExpression(array, node, 71);
  } else if (node.kind === 35) {
    emitBinaryExpression(array, node, 72);
  } else if (node.kind === 36) {
    emitBinaryExpression(array, node, 73);
  } else if (node.kind === 38) {
    emitBinaryExpression(array, node, 77);
  } else if (node.kind === 46) {
    emitBinaryExpression(array, node, 78);
  } else if (node.kind === 41) {
    emitBinaryExpression(array, node, 79);
  } else if (node.kind === 42) {
    emitBinaryExpression(array, node, 80);
  } else if (node.kind === 39) {
    emitBinaryExpression(array, node, 83);
  } else if (node.kind === 40) {
    emitBinaryExpression(array, node, 84);
  } else if (node.kind === 43) {
    __imports.ByteArray_appendByte(array, 4);
    wasmEmitNode(array, binaryLeft(node));
    wasmEmitNode(array, binaryRight(node));
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, 0);
  } else if (node.kind === 44) {
    __imports.ByteArray_appendByte(array, 4);
    wasmEmitNode(array, binaryLeft(node));
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, 1);
    wasmEmitNode(array, binaryRight(node));
  } else {
    __imports.assert(false);
  }
  return 1;
}
function wasmEmitFunctionBodies(array, module) {
  if (module.firstFunction === null) {
    return;
  }
  var section = wasmStartSection(array, __imports.String_new("function_bodies"));
  wasmWriteVarUnsigned(array, module.functionCount);
  var fn = module.firstFunction;
  while (fn !== null) {
    var bodyLength = __imports.ByteArray_length(array);
    wasmWriteVarUnsigned(array, ~0);
    if (fn.intLocalCount > 0) {
      wasmWriteVarUnsigned(array, 1);
      wasmWriteVarUnsigned(array, fn.intLocalCount);
      __imports.ByteArray_appendByte(array, 1);
    } else {
      wasmWriteVarUnsigned(array, 0);
    }
    var child = fn.body.firstChild;
    while (child !== null) {
      wasmEmitNode(array, child);
      child = child.nextSibling;
    }
    wasmPatchVarUnsigned(array, bodyLength, __imports.ByteArray_length(array) - bodyLength - 5, ~0);
    fn = fn.next;
  }
  wasmFinishSection(array, section);
}
function wasmEmitDataSegments(array, module) {
  var section = wasmStartSection(array, __imports.String_new("data_segments"));
  wasmWriteVarUnsigned(array, 1);
  var memoryInitializer = module.memoryInitializer;
  var byteOffset = 8;
  var byteCount = __imports.ByteArray_length(memoryInitializer);
  var initialHeapOffset = byteOffset + byteCount + 7 & ~7;
  __imports.assert(byteCount >= 4);
  wasmWriteVarUnsigned(array, byteOffset);
  wasmWriteVarUnsigned(array, byteCount);
  __imports.ByteArray_setByte(memoryInitializer, 0, initialHeapOffset);
  __imports.ByteArray_setByte(memoryInitializer, 1, initialHeapOffset >> 8);
  __imports.ByteArray_setByte(memoryInitializer, 2, initialHeapOffset >> 16);
  __imports.ByteArray_setByte(memoryInitializer, 3, initialHeapOffset >> 24);
  var i = 0;
  while (i < byteCount) {
    __imports.ByteArray_appendByte(array, __imports.ByteArray_getByte(memoryInitializer, i));
    i = i + 1;
  }
  wasmFinishSection(array, section);
}
function wasmEmitModule(array, module) {
  __imports.ByteArray_appendByte(array, 1836278016);
  __imports.ByteArray_appendByte(array, 1836278016 >> 8);
  __imports.ByteArray_appendByte(array, 1836278016 >> 16);
  __imports.ByteArray_appendByte(array, 1836278016 >> 24);
  __imports.ByteArray_appendByte(array, 10);
  __imports.ByteArray_appendByte(array, 10 >> 8);
  __imports.ByteArray_appendByte(array, 10 >> 16);
  __imports.ByteArray_appendByte(array, 10 >> 24);
  wasmEmitSignatures(array, module);
  wasmEmitImportTable(array, module);
  wasmEmitFunctionSignatures(array, module);
  wasmEmitMemory(array, module);
  wasmEmitExportTable(array, module);
  wasmEmitFunctionBodies(array, module);
  wasmEmitDataSegments(array, module);
}
function wasmWrapType(id) {
  __imports.assert(id === 0 || id === 1);
  var type = new WasmType();
  type.id = id;
  return type;
}
function wasmGetType(context, type) {
  if (type === context.boolType || type === context.intType || typeIsReference(context, type)) {
    return 1;
  }
  if (type === context.voidType) {
    return 0;
  }
  __imports.assert(false);
  return 0;
}
function wasmCollectStrings(module, node) {
  if (node.kind === 23) {
    var memoryInitializer = module.memoryInitializer;
    node.intValue = 8 + __imports.ByteArray_length(memoryInitializer);
    var text = node.stringValue;
    var i = 0;
    var count = __imports.String_length(text);
    while (i < count) {
      __imports.ByteArray_appendByte(memoryInitializer, __imports.String_get(text, i));
      i = i + 1;
    }
    __imports.ByteArray_appendByte(memoryInitializer, 0);
  }
  var child = node.firstChild;
  while (child !== null) {
    wasmCollectStrings(module, child);
    child = child.nextSibling;
  }
}
function WasmSharedOffset() {
  this.nextLocalOffset = 0;
  this.intLocalCount = 0;
}
function wasmAssignLocalVariableOffsets(node, shared) {
  if (node.kind === 1) {
    __imports.assert(node.symbol.kind === 7);
    node.symbol.offset = shared.nextLocalOffset;
    shared.nextLocalOffset = shared.nextLocalOffset + 1;
    shared.intLocalCount = shared.intLocalCount + 1;
  }
  var child = node.firstChild;
  while (child !== null) {
    wasmAssignLocalVariableOffsets(child, shared);
    child = child.nextSibling;
  }
}
function wasmEmit(global, context, array) {
  var module = new WasmModule();
  module.memoryInitializer = __imports.ByteArray_new();
  __imports.ByteArray_appendByte(module.memoryInitializer, 0);
  __imports.ByteArray_appendByte(module.memoryInitializer, 0);
  __imports.ByteArray_appendByte(module.memoryInitializer, 0);
  __imports.ByteArray_appendByte(module.memoryInitializer, 0);
  var imports = __imports.String_new("imports");
  var signatureIndex = wasmAllocateSignature(module, wasmWrapType(1), wasmWrapType(1));
  wasmAllocateImport(module, signatureIndex, imports, __imports.String_new("new"));
  wasmCollectStrings(module, global);
  var child = global.firstChild;
  while (child !== null) {
    if (child.kind === 9) {
      var returnType = functionReturnType(child);
      var shared = new WasmSharedOffset();
      var argumentTypesFirst = null;
      var argumentTypesLast = null;
      var argument = child.firstChild;
      while (argument !== returnType) {
        var type = wasmWrapType(wasmGetType(context, variableType(argument).resolvedType));
        if (argumentTypesFirst === null) {
          argumentTypesFirst = type;
        } else {
          argumentTypesLast.next = type;
        }
        argumentTypesLast = type;
        shared.nextLocalOffset = shared.nextLocalOffset + 1;
        argument = argument.nextSibling;
      }
      signatureIndex = wasmAllocateSignature(module, argumentTypesFirst, wasmWrapType(wasmGetType(context, returnType.resolvedType)));
      var body = functionBody(child);
      if (body === null) {
        child.symbol.offset = module.importCount;
        wasmAllocateImport(module, signatureIndex, imports, child.symbol.name);
        child = child.nextSibling;
        continue;
      }
      child.symbol.offset = module.functionCount;
      var fn = wasmAllocateFunction(module, child.symbol.name, signatureIndex, body);
      if (isExternSymbol(child.symbol)) {
        fn.isExported = true;
      }
      wasmAssignLocalVariableOffsets(body, shared);
      fn.intLocalCount = shared.intLocalCount;
    }
    child = child.nextSibling;
  }
  wasmEmitModule(array, module);
}
