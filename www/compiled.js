function isType(kind) {
  return kind >= 0 && kind <= 3;
}
function isFunction(kind) {
  return kind >= 4 && kind <= 5;
}
function isVariable(kind) {
  return kind >= 6 && kind <= 9;
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
Symbol.prototype.isEnumValue = function() {
  return this.node.parent.kind === 8;
};
Symbol.prototype.resolvedTypeIntIfEnumValue = function(context) {
  if (this.isEnumValue()) {
    return context.intType;
  }
  return this.resolvedType;
};
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
Type.prototype.isClass = function() {
  return this.symbol.kind === 0;
};
Type.prototype.isEnum = function() {
  return this.symbol.kind === 1;
};
Type.prototype.isInteger = function(context) {
  return this === context.intType || this.isEnum();
};
function typeIsReference(context, type) {
  return type.isClass() || type === context.stringType;
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
function findMember(type, name) {
  var child = type.symbol.node.firstChild;
  while (child !== null) {
    __imports.assert(child.kind === 1 || child.kind === 10);
    if (__imports.String_equal(child.symbol.name, name)) {
      return child.symbol;
    }
    child = child.nextSibling;
  }
  return null;
}
function findNested(scope, name, mode) {
  while (scope !== null) {
    if (scope.symbol === null || scope.symbol.kind !== 0 || mode === 1) {
      var local = findLocal(scope, name);
      if (local !== null) {
        return local;
      }
    }
    scope = scope.parent;
  }
  return null;
}
function define(log, scope, symbol) {
  var existing = findLocal(scope, symbol.name);
  if (existing !== null) {
    log.error(symbol.range, __imports.String_appendNew(__imports.String_append(__imports.String_new("Duplicate symbol '"), symbol.name), "'"));
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
  symbol.kind = 3;
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
  if (node.parent !== null) {
    var kind = node.kind;
    var parentKind = node.parent.kind;
    if (kind !== 1 && (kind !== 10 || parentKind !== 4) && parentKind === 0 !== (kind === 4 || kind === 8 || kind === 10 || kind === 5)) {
      context.log.error(node.range, __imports.String_new("This statement is not allowed here"));
    }
  }
  if (node.kind === 0) {
    __imports.assert(parentScope === null);
    var symbol = new Symbol();
    symbol.kind = 2;
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
  } else if (node.kind === 4 || node.kind === 8) {
    var symbol = new Symbol();
    symbol.kind = node.kind === 4 ? 0 : 1;
    symbol.name = node.stringValue;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    define(context.log, parentScope, symbol);
    parentScope = symbol.scope;
  } else if (node.kind === 10) {
    var symbol = new Symbol();
    symbol.kind = node.parent.kind === 4 ? 4 : 5;
    symbol.name = node.stringValue;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    define(context.log, parentScope, symbol);
    parentScope = symbol.scope;
    if (symbol.kind === 4) {
      var parent = node.parent.symbol;
      __imports.assert(parent.kind === 0);
      initializeSymbol(context, parent);
      node.insertChildBefore(node.firstChild, createVariable(__imports.String_new("this"), createType(parent.resolvedType), null));
    }
  } else if (node.kind === 1) {
    var symbol = new Symbol();
    symbol.kind = node.parent.kind === 4 ? 8 : node.parent.kind === 10 ? 6 : node.parent.kind === 5 || node.parent.kind === 8 ? 7 : 9;
    symbol.name = node.stringValue;
    symbol.scope = parentScope;
    linkSymbolToNode(symbol, node);
    define(context.log, parentScope, symbol);
  } else if (node.kind === 2) {
    if (node.parent.kind !== 10) {
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
  } else if (symbol.kind === 1) {
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
  } else if (isFunction(symbol.kind)) {
    var returnType = symbol.node.functionReturnType();
    resolveAsType(context, returnType, symbol.scope.parent);
    var offset = 0;
    var child = symbol.node.firstChild;
    while (child !== returnType) {
      __imports.assert(child.kind === 1);
      __imports.assert(child.symbol.kind === 6);
      initializeSymbol(context, child.symbol);
      child.symbol.offset = offset;
      offset = offset + 1;
      child = child.nextSibling;
    }
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
  } else if (isVariable(symbol.kind)) {
    var type = symbol.node.variableType();
    var value = symbol.node.variableValue();
    if (type !== null) {
      resolveAsType(context, type, symbol.scope);
      symbol.resolvedType = type.resolvedType;
    } else if (value !== null) {
      resolveAsExpression(context, value, symbol.scope);
      symbol.resolvedType = value.resolvedType;
    } else {
      context.log.error(symbol.node.internalRange, __imports.String_new("Cannot create untyped variables"));
      symbol.resolvedType = context.errorType;
    }
    if (symbol.resolvedType === context.voidType || symbol.resolvedType === context.nullType) {
      context.log.error(symbol.node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_new("Cannot create a variable with type '"), typeToString(symbol.resolvedType)), "'"));
      symbol.resolvedType = context.errorType;
    }
    if (symbol.kind === 7) {
      if (symbol.resolvedType !== context.errorType && !symbol.resolvedType.isInteger(context)) {
        context.log.error(symbol.node.internalRange, __imports.String_new("All constants must be integers for now"));
        symbol.resolvedType = context.errorType;
      }
      if (value !== null) {
        resolveAsExpression(context, value, symbol.scope);
        checkConversion(context, value, symbol.resolvedTypeIntIfEnumValue(context));
        if (value.kind === 20) {
          symbol.offset = value.intValue;
        } else {
          context.log.error(value.range, __imports.String_new("Constants must be initialized to a single integer for now"));
        }
      } else if (symbol.isEnumValue()) {
        if (symbol.node.previousSibling !== null) {
          var previousSymbol = symbol.node.previousSibling.symbol;
          initializeSymbol(context, previousSymbol);
          symbol.offset = previousSymbol.offset + 1;
        } else {
          symbol.offset = 0;
        }
      } else {
        context.log.error(symbol.node.internalRange, __imports.String_new("Constants must be initialized"));
      }
    }
    if (symbol.scope.symbol === null) {
      var scope = symbol.scope.parent;
      while (scope !== null) {
        var shadowed = findLocal(scope, symbol.name);
        if (shadowed !== null) {
          context.log.error(symbol.node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_new("The symbol '"), symbol.name), "' shadows another symbol with the same name in a parent scope"));
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
  if (node.resolvedType !== context.errorType && node.isType()) {
    context.log.error(node.range, __imports.String_new("Expected expression but found type"));
    node.resolvedType = context.errorType;
  }
}
function resolveAsType(context, node, parentScope) {
  __imports.assert(isExpression(node));
  resolve(context, node, parentScope);
  if (node.resolvedType !== context.errorType && !node.isType()) {
    context.log.error(node.range, __imports.String_new("Expected type but found expression"));
    node.resolvedType = context.errorType;
  }
}
function checkConversion(context, from, to) {
  __imports.assert(isExpression(from));
  __imports.assert(to !== null);
  if (from.resolvedType !== context.errorType && to !== context.errorType && from.resolvedType !== to && (from.resolvedType !== context.nullType || !typeIsReference(context, to))) {
    context.log.error(from.range, __imports.String_appendNew(__imports.String_append(__imports.String_appendNew(__imports.String_append(__imports.String_new("Cannot convert from type '"), typeToString(from.resolvedType)), "' to type '"), typeToString(to)), "'"));
    from.resolvedType = context.errorType;
  }
}
function checkStorage(context, target) {
  __imports.assert(isExpression(target));
  if (target.resolvedType !== context.errorType && (target.kind !== 21 && target.kind !== 18 || target.symbol !== null && (!isVariable(target.symbol.kind) || target.symbol.kind === 7))) {
    context.log.error(target.range, __imports.String_new("Cannot store to this location"));
    target.resolvedType = context.errorType;
  }
}
function resolveUnary(context, node, parentScope, expectedType) {
  var value = node.unaryValue();
  resolveAsExpression(context, value, parentScope);
  checkConversion(context, value, expectedType);
  node.resolvedType = expectedType;
}
function resolveBinary(context, node, parentScope) {
  var left = node.binaryLeft();
  var right = node.binaryRight();
  resolveAsExpression(context, left, parentScope);
  resolveAsExpression(context, right, parentScope);
}
function checkBinary(context, node, expectedType, resultType) {
  var left = node.binaryLeft();
  var right = node.binaryRight();
  checkConversion(context, left, expectedType);
  checkConversion(context, right, expectedType);
  node.resolvedType = resultType;
}
function createDefaultValueForType(context, type) {
  if (type.isInteger(context)) {
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
      if (child.kind === 1) {
        child.symbol.offset = offset;
        offset = offset + 4;
      }
      child = child.nextSibling;
    }
    node.symbol.offset = offset > 0 ? offset : 1;
  } else if (node.kind === 8) {
    initializeSymbol(context, node.symbol);
    resolveChildren(context, node, node.scope);
  } else if (node.kind === 10) {
    var body = node.functionBody();
    initializeSymbol(context, node.symbol);
    if (body !== null) {
      var oldReturnType = context.currentReturnType;
      context.currentReturnType = node.functionReturnType().resolvedType;
      resolveChildren(context, body, node.scope);
      context.currentReturnType = oldReturnType;
    }
  } else if (node.kind === 1) {
    var symbol = node.symbol;
    initializeSymbol(context, symbol);
    var value = node.variableValue();
    if (value !== null) {
      resolveAsExpression(context, value, parentScope);
      checkConversion(context, value, symbol.resolvedTypeIntIfEnumValue(context));
    } else {
      node.appendChild(createDefaultValueForType(context, symbol.resolvedType));
    }
  } else if (node.kind === 3 || node.kind === 6) {
    var found = false;
    var n = node;
    while (n !== null) {
      if (n.kind === 14) {
        found = true;
        break;
      }
      n = n.parent;
    }
    if (!found) {
      context.log.error(node.range, __imports.String_new("Cannot use this statement outside of a loop"));
    }
  } else if (node.kind === 2) {
    resolveChildren(context, node, node.scope);
  } else if (node.kind === 5 || node.kind === 13) {
    resolveChildren(context, node, parentScope);
  } else if (node.kind === 20) {
    node.resolvedType = context.intType;
  } else if (node.kind === 24) {
    node.resolvedType = context.stringType;
  } else if (node.kind === 15) {
    node.resolvedType = context.boolType;
  } else if (node.kind === 23) {
    node.resolvedType = context.nullType;
  } else if (node.kind === 25) {
    var symbol = findNested(parentScope, __imports.String_new("this"), 0);
    if (symbol === null) {
      context.log.error(node.range, __imports.String_new("Cannot use 'this' here"));
    } else {
      node.becomeSymbolReference(symbol);
    }
  } else if (node.kind === 21) {
    var symbol = findNested(parentScope, node.stringValue, 0);
    if (symbol === null) {
      var message = __imports.String_appendNew(__imports.String_append(__imports.String_new("No symbol named '"), node.stringValue), "' here");
      symbol = findNested(parentScope, node.stringValue, 1);
      if (symbol !== null) {
        message = __imports.String_appendNew(__imports.String_append(__imports.String_appendNew(message, ", did you mean 'this."), symbol.name), "'?");
      }
      context.log.error(node.range, message);
    } else if (symbol.state === 1) {
      context.log.error(node.range, __imports.String_appendNew(__imports.String_append(__imports.String_new("Cyclic reference to symbol '"), node.stringValue), "' here"));
    } else if (isFunction(symbol.kind) && (node.parent.kind !== 16 || node !== node.parent.callValue())) {
      context.log.error(node.range, __imports.String_new("Bare function references are not allowed"));
    } else {
      initializeSymbol(context, symbol);
      node.symbol = symbol;
      node.resolvedType = symbol.resolvedType;
      if (node.symbol.kind === 7) {
        node.becomeIntegerConstant(node.symbol.offset);
      }
    }
  } else if (node.kind === 18) {
    var target = node.dotTarget();
    resolve(context, target, parentScope);
    if (target.resolvedType !== context.errorType) {
      if (target.isType() && target.resolvedType.isEnum() || !target.isType() && target.resolvedType.isClass()) {
        var child = target.resolvedType.symbol.node.firstChild;
        node.symbol = findMember(target.resolvedType, node.stringValue);
        if (node.symbol === null) {
          context.log.error(node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_appendNew(__imports.String_append(__imports.String_new("No member named '"), node.stringValue), "' on type '"), typeToString(target.resolvedType)), "'"));
        } else {
          initializeSymbol(context, node.symbol);
          node.resolvedType = node.symbol.resolvedType;
          if (node.symbol.kind === 7) {
            node.becomeIntegerConstant(node.symbol.offset);
          }
        }
      } else {
        context.log.error(node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_new("The type '"), typeToString(target.resolvedType)), "' has no members"));
      }
    }
  } else if (node.kind === 16) {
    var value = node.callValue();
    resolveAsExpression(context, value, parentScope);
    if (value.resolvedType !== context.errorType) {
      var symbol = value.symbol;
      if (symbol === null || !isFunction(symbol.kind)) {
        context.log.error(value.range, __imports.String_appendNew(__imports.String_append(__imports.String_new("Cannot call value of type '"), typeToString(value.resolvedType)), "'"));
      } else {
        initializeSymbol(context, symbol);
        var returnType = symbol.node.functionReturnType();
        var argumentVariable = symbol.node.functionFirstArgumentIgnoringThis();
        var argumentValue = value.nextSibling;
        while (argumentVariable !== returnType && argumentValue !== null) {
          resolveAsExpression(context, argumentValue, parentScope);
          checkConversion(context, argumentValue, argumentVariable.symbol.resolvedType);
          argumentVariable = argumentVariable.nextSibling;
          argumentValue = argumentValue.nextSibling;
        }
        if (argumentVariable !== returnType) {
          context.log.error(node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_new("Not enough arguments for function '"), symbol.name), "'"));
        } else if (argumentValue !== null) {
          while (argumentValue !== null) {
            resolveAsExpression(context, argumentValue, parentScope);
            argumentValue = argumentValue.nextSibling;
          }
          context.log.error(node.internalRange, __imports.String_appendNew(__imports.String_append(__imports.String_new("Too many arguments for function '"), symbol.name), "'"));
        }
        node.resolvedType = returnType.resolvedType;
      }
    }
  } else if (node.kind === 12) {
    var value = node.returnValue();
    if (value !== null) {
      resolveAsExpression(context, value, parentScope);
      if (context.currentReturnType !== null) {
        checkConversion(context, value, context.currentReturnType);
      }
    } else if (context.currentReturnType !== null && context.currentReturnType !== context.voidType) {
      context.log.error(node.range, __imports.String_new("Expected return value"));
    }
  } else if (node.kind === 7) {
  } else if (node.kind === 9) {
    resolveAsExpression(context, node.expressionValue(), parentScope);
  } else if (node.kind === 14) {
    var value = node.whileValue();
    var body = node.whileBody();
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType);
    resolve(context, body, parentScope);
  } else if (node.kind === 11) {
    var value = node.ifValue();
    var yes = node.ifTrue();
    var no = node.ifFalse();
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType);
    resolve(context, yes, parentScope);
    if (no !== null) {
      resolve(context, no, parentScope);
    }
  } else if (node.kind === 19) {
    var value = node.hookValue();
    var yes = node.hookTrue();
    var no = node.hookFalse();
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType);
    resolve(context, yes, parentScope);
    resolve(context, no, parentScope);
    var commonType = (yes.resolvedType === context.nullType ? no : yes).resolvedType;
    if (yes.resolvedType !== commonType && (yes.resolvedType !== context.nullType || !typeIsReference(context, commonType)) && no.resolvedType !== commonType && (no.resolvedType !== context.nullType || !typeIsReference(context, commonType))) {
      context.log.error(spanRanges(yes.range, no.range), __imports.String_appendNew(__imports.String_append(__imports.String_appendNew(__imports.String_append(__imports.String_new("Type '"), typeToString(yes.resolvedType)), "' is not the same as type '"), typeToString(no.resolvedType)), "'"));
    }
    node.resolvedType = commonType;
  } else if (node.kind === 36) {
    var left = node.binaryLeft();
    var right = node.binaryRight();
    resolveAsExpression(context, left, parentScope);
    resolveAsExpression(context, right, parentScope);
    checkConversion(context, right, left.resolvedType);
    checkStorage(context, left);
    node.resolvedType = left.resolvedType;
  } else if (node.kind === 35 || node.kind === 53 || node.kind === 48 || node.kind === 40 || node.kind === 37 || node.kind === 38 || node.kind === 39 || node.kind === 51 || node.kind === 52) {
    resolveBinary(context, node, parentScope);
    checkBinary(context, node, context.intType, context.intType);
  } else if (node.kind === 44 || node.kind === 45 || node.kind === 42 || node.kind === 43) {
    var left = node.binaryLeft();
    var right = node.binaryRight();
    resolveAsExpression(context, left, parentScope);
    resolveAsExpression(context, right, parentScope);
    var expectedType = left.resolvedType === right.resolvedType && left.resolvedType.isInteger(context) ? left.resolvedType : context.intType;
    checkConversion(context, left, expectedType);
    checkConversion(context, right, expectedType);
  } else if (node.kind === 47 || node.kind === 46) {
    resolveBinary(context, node, parentScope);
    checkBinary(context, node, context.boolType, context.boolType);
  } else if (node.kind === 41 || node.kind === 49) {
    var left = node.binaryLeft();
    var right = node.binaryRight();
    resolveBinary(context, node, parentScope);
    node.resolvedType = context.boolType;
    var leftType = left.resolvedType;
    var rightType = right.resolvedType;
    if (leftType !== context.errorType && rightType !== context.errorType && (leftType === rightType ? leftType === context.voidType : (leftType !== context.nullType || !typeIsReference(context, rightType)) && (rightType !== context.nullType || !typeIsReference(context, leftType)))) {
      context.log.error(node.range, __imports.String_appendNew(__imports.String_append(__imports.String_appendNew(__imports.String_append(__imports.String_new("Cannot compare type '"), typeToString(leftType)), "' with type '"), typeToString(rightType)), "'"));
    }
  } else if (node.kind === 27 || node.kind === 28 || node.kind === 30) {
    resolveUnary(context, node, parentScope, context.intType);
  } else if (node.kind === 29) {
    resolveUnary(context, node, parentScope, context.boolType);
  } else if (node.kind === 22) {
    var type = node.newType();
    resolveAsType(context, type, parentScope);
    if (type.resolvedType !== context.errorType) {
      if (!type.resolvedType.isClass()) {
        context.log.error(type.range, __imports.String_appendNew(__imports.String_append(__imports.String_new("Cannot construct type '"), typeToString(type.resolvedType)), "'"));
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
        child.remove();
        result.global.appendChild(child);
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
  return result.log.toString();
};
function JsResult() {
  this.context = null;
  this.code = null;
  this.indent = 0;
}
JsResult.prototype.appendIndent = function() {
  var i = this.indent;
  while (i > 0) {
    this.code = __imports.String_appendNew(this.code, "  ");
    i = i - 1;
  }
};
JsResult.prototype.emitText = function(text) {
  this.code = __imports.String_appendNew(this.code, text);
};
JsResult.prototype.emitString = function(text) {
  this.code = __imports.String_append(this.code, text);
};
JsResult.prototype.emitBlock = function(node) {
  this.emitText("{\n");
  this.indent = this.indent + 1;
  var child = node.firstChild;
  while (child !== null) {
    this.emitStatement(child);
    child = child.nextSibling;
  }
  this.indent = this.indent - 1;
  this.appendIndent();
  this.emitText("}");
};
JsResult.prototype.emitUnary = function(node, parentPrecedence, operator) {
  var isPostfix = isUnaryPostfix(node.kind);
  var operatorPrecedence = isPostfix ? 13 : 12;
  if (parentPrecedence > operatorPrecedence) {
    this.emitText("(");
  }
  if (!isPostfix) {
    this.emitText(operator);
  }
  this.emitExpression(node.unaryValue(), operatorPrecedence);
  if (isPostfix) {
    this.emitText(operator);
  }
  if (parentPrecedence > operatorPrecedence) {
    this.emitText(")");
  }
};
JsResult.prototype.emitBinary = function(node, parentPrecedence, operator, operatorPrecedence) {
  var isRightAssociative = node.kind === 36;
  if (parentPrecedence > operatorPrecedence) {
    this.emitText("(");
  }
  this.emitExpression(node.binaryLeft(), isRightAssociative ? operatorPrecedence + 1 : operatorPrecedence);
  this.emitText(operator);
  this.emitExpression(node.binaryRight(), isRightAssociative ? operatorPrecedence : operatorPrecedence + 1);
  if (parentPrecedence > operatorPrecedence) {
    this.emitText(")");
  }
};
JsResult.prototype.emitExpression = function(node, parentPrecedence) {
  if (node.kind === 21) {
    this.emitString(node.symbol.name);
  } else if (node.kind === 23) {
    this.emitText("null");
  } else if (node.kind === 15) {
    this.emitText(node.intValue !== 0 ? "true" : "false");
  } else if (node.kind === 20) {
    this.emitString(__imports.String_toString(node.intValue));
  } else if (node.kind === 24) {
    this.emitString(__imports.String_quote(node.stringValue));
  } else if (node.kind === 18) {
    this.emitExpression(node.dotTarget(), 14);
    this.emitText(".");
    this.emitString(node.symbol.name);
  } else if (node.kind === 19) {
    if (parentPrecedence > 1) {
      this.emitText("(");
    }
    this.emitExpression(node.hookValue(), 2);
    this.emitText(" ? ");
    this.emitExpression(node.hookTrue(), 1);
    this.emitText(" : ");
    this.emitExpression(node.hookFalse(), 1);
    if (parentPrecedence > 1) {
      this.emitText(")");
    }
  } else if (node.kind === 16) {
    var value = node.callValue();
    if (value.symbol.node.functionBody() === null) {
      this.emitText("__imports.");
    }
    this.emitExpression(value, 13);
    this.emitText("(");
    var child = value.nextSibling;
    while (child !== null) {
      this.emitExpression(child, 0);
      child = child.nextSibling;
      if (child !== null) {
        this.emitText(", ");
      }
    }
    this.emitText(")");
  } else if (node.kind === 22) {
    this.emitText("new ");
    this.emitExpression(node.newType(), 13);
    this.emitText("()");
  } else if (node.kind === 27) {
    this.emitUnary(node, parentPrecedence, "~");
  } else if (node.kind === 28) {
    this.emitUnary(node, parentPrecedence, "-");
  } else if (node.kind === 29) {
    this.emitUnary(node, parentPrecedence, "!");
  } else if (node.kind === 30) {
    this.emitUnary(node, parentPrecedence, "+");
  } else if (node.kind === 34) {
    this.emitUnary(node, parentPrecedence, "++");
  } else if (node.kind === 33) {
    this.emitUnary(node, parentPrecedence, "--");
  } else if (node.kind === 32) {
    this.emitUnary(node, parentPrecedence, "++");
  } else if (node.kind === 31) {
    this.emitUnary(node, parentPrecedence, "--");
  } else if (node.kind === 35) {
    this.emitBinary(node, parentPrecedence, " + ", 10);
  } else if (node.kind === 36) {
    this.emitBinary(node, parentPrecedence, " = ", 1);
  } else if (node.kind === 37) {
    this.emitBinary(node, parentPrecedence, " & ", 6);
  } else if (node.kind === 38) {
    this.emitBinary(node, parentPrecedence, " | ", 4);
  } else if (node.kind === 39) {
    this.emitBinary(node, parentPrecedence, " ^ ", 5);
  } else if (node.kind === 40) {
    this.emitBinary(node, parentPrecedence, " / ", 11);
  } else if (node.kind === 41) {
    this.emitBinary(node, parentPrecedence, " === ", 7);
  } else if (node.kind === 42) {
    this.emitBinary(node, parentPrecedence, " > ", 8);
  } else if (node.kind === 43) {
    this.emitBinary(node, parentPrecedence, " >= ", 8);
  } else if (node.kind === 44) {
    this.emitBinary(node, parentPrecedence, " < ", 8);
  } else if (node.kind === 45) {
    this.emitBinary(node, parentPrecedence, " <= ", 8);
  } else if (node.kind === 46) {
    this.emitBinary(node, parentPrecedence, " && ", 3);
  } else if (node.kind === 47) {
    this.emitBinary(node, parentPrecedence, " || ", 2);
  } else if (node.kind === 48) {
    this.emitBinary(node, parentPrecedence, " * ", 11);
  } else if (node.kind === 49) {
    this.emitBinary(node, parentPrecedence, " !== ", 7);
  } else if (node.kind === 50) {
    this.emitBinary(node, parentPrecedence, " % ", 11);
  } else if (node.kind === 51) {
    this.emitBinary(node, parentPrecedence, " << ", 9);
  } else if (node.kind === 52) {
    this.emitBinary(node, parentPrecedence, " >> ", 9);
  } else if (node.kind === 53) {
    this.emitBinary(node, parentPrecedence, " - ", 10);
  } else {
    __imports.assert(false);
  }
};
JsResult.prototype.emitStatement = function(node) {
  if (node.kind === 10) {
    var body = node.functionBody();
    if (body === null) {
      return;
    }
    var needsSemicolon = false;
    this.appendIndent();
    if (node.parent.kind === 4) {
      this.emitString(node.parent.symbol.name);
      this.emitText(".prototype.");
      this.emitString(node.symbol.name);
      this.emitText(" = function");
      needsSemicolon = true;
    } else if (isExternSymbol(node.symbol)) {
      this.emitText("var ");
      this.emitString(node.symbol.name);
      this.emitText(" = exports.");
      this.emitString(node.symbol.name);
      this.emitText(" = function");
      needsSemicolon = true;
    } else {
      this.emitText("function ");
      this.emitString(node.symbol.name);
    }
    this.emitText("(");
    var returnType = node.functionReturnType();
    var child = node.functionFirstArgumentIgnoringThis();
    while (child !== returnType) {
      __imports.assert(child.kind === 1);
      this.emitString(child.symbol.name);
      child = child.nextSibling;
      if (child !== returnType) {
        this.emitText(", ");
      }
    }
    this.emitText(") ");
    this.emitBlock(node.functionBody());
    this.emitText(needsSemicolon ? ";\n" : "\n");
  } else if (node.kind === 11) {
    this.appendIndent();
    while (true) {
      this.emitText("if (");
      this.emitExpression(node.ifValue(), 0);
      this.emitText(") ");
      this.emitBlock(node.ifTrue());
      var no = node.ifFalse();
      if (no === null) {
        this.emitText("\n");
        break;
      }
      this.emitText(" else ");
      if (no.firstChild === null || no.firstChild !== no.lastChild || no.firstChild.kind !== 11) {
        this.emitBlock(no);
        this.emitText("\n");
        break;
      }
      node = no.firstChild;
    }
  } else if (node.kind === 14) {
    this.appendIndent();
    this.emitText("while (");
    this.emitExpression(node.whileValue(), 0);
    this.emitText(") ");
    this.emitBlock(node.whileBody());
    this.emitText("\n");
  } else if (node.kind === 3) {
    this.appendIndent();
    this.emitText("break;\n");
  } else if (node.kind === 6) {
    this.appendIndent();
    this.emitText("continue;\n");
  } else if (node.kind === 9) {
    this.appendIndent();
    this.emitExpression(node.expressionValue(), 0);
    this.emitText(";\n");
  } else if (node.kind === 7) {
  } else if (node.kind === 12) {
    var value = node.returnValue();
    this.appendIndent();
    if (value !== null) {
      this.emitText("return ");
      this.emitExpression(value, 0);
      this.emitText(";\n");
    } else {
      this.emitText("return;\n");
    }
  } else if (node.kind === 2) {
    this.appendIndent();
    this.emitBlock(node);
    this.emitText("\n");
  } else if (node.kind === 13) {
    this.appendIndent();
    this.emitText("var ");
    var child = node.firstChild;
    while (child !== null) {
      var value = child.variableValue();
      this.emitString(child.symbol.name);
      child = child.nextSibling;
      if (child !== null) {
        this.emitText(", ");
      }
      __imports.assert(value !== null);
      this.emitText(" = ");
      this.emitExpression(value, 0);
    }
    this.emitText(";\n");
  } else if (node.kind === 4) {
    this.appendIndent();
    this.emitText("function ");
    this.emitString(node.symbol.name);
    this.emitText("() {\n");
    this.indent = this.indent + 1;
    var child = node.firstChild;
    while (child !== null) {
      if (child.kind === 1) {
        this.appendIndent();
        this.emitText("this.");
        this.emitString(child.symbol.name);
        this.emitText(" = ");
        this.emitExpression(child.variableValue(), 0);
        this.emitText(";\n");
      }
      child = child.nextSibling;
    }
    this.indent = this.indent - 1;
    this.appendIndent();
    this.emitText("}\n");
    child = node.firstChild;
    while (child !== null) {
      if (child.kind === 10) {
        this.emitStatement(child);
      }
      child = child.nextSibling;
    }
  } else if (node.kind === 5 || node.kind === 8) {
  } else {
    __imports.assert(false);
  }
};
function jsEmit(global, context) {
  var result = new JsResult();
  result.context = context;
  result.code = __imports.String_new("");
  var child = global.firstChild;
  while (child !== null) {
    result.emitStatement(child);
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
  if (token === 44) {
    return "ENUM";
  }
  if (token === 14) {
    return "EQUAL";
  }
  if (token === 45) {
    return "EXPORT";
  }
  if (token === 46) {
    return "EXTENDS";
  }
  if (token === 47) {
    return "EXTERN";
  }
  if (token === 48) {
    return "FALSE";
  }
  if (token === 49) {
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
  if (token === 50) {
    return "IF";
  }
  if (token === 51) {
    return "IMPLEMENTS";
  }
  if (token === 52) {
    return "IMPORT";
  }
  if (token === 3) {
    return "INT";
  }
  if (token === 53) {
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
  if (token === 54) {
    return "NEW";
  }
  if (token === 27) {
    return "NOT";
  }
  if (token === 28) {
    return "NOT_EQUAL";
  }
  if (token === 55) {
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
  if (token === 56) {
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
  if (token === 57) {
    return "THIS";
  }
  if (token === 58) {
    return "TRUE";
  }
  if (token === 59) {
    return "VAR";
  }
  if (token === 60) {
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
      } else if (__imports.String_equalNew(text, "enum")) {
        kind = 44;
      } else if (__imports.String_equalNew(text, "export")) {
        kind = 45;
      } else if (__imports.String_equalNew(text, "extends")) {
        kind = 46;
      } else if (__imports.String_equalNew(text, "extern")) {
        kind = 47;
      } else if (__imports.String_equalNew(text, "false")) {
        kind = 48;
      } else if (__imports.String_equalNew(text, "function")) {
        kind = 49;
      } else if (__imports.String_equalNew(text, "if")) {
        kind = 50;
      } else if (__imports.String_equalNew(text, "implements")) {
        kind = 51;
      } else if (__imports.String_equalNew(text, "import")) {
        kind = 52;
      } else if (__imports.String_equalNew(text, "interface")) {
        kind = 53;
      } else if (__imports.String_equalNew(text, "new")) {
        kind = 54;
      } else if (__imports.String_equalNew(text, "null")) {
        kind = 55;
      } else if (__imports.String_equalNew(text, "return")) {
        kind = 56;
      } else if (__imports.String_equalNew(text, "this")) {
        kind = 57;
      } else if (__imports.String_equalNew(text, "true")) {
        kind = 58;
      } else if (__imports.String_equalNew(text, "var")) {
        kind = 59;
      } else if (__imports.String_equalNew(text, "while")) {
        kind = 60;
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
        log.error(createRange(source, start, i), __imports.String_new(c === 39 ? "Unterminated character literal" : c === 96 ? "Unterminated template literal" : "Unterminated string literal"));
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
          log.error(createRange(source, start, start + 2), __imports.String_new("Unterminated multi-line comment"));
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
          log.error(createRange(source, start, i), __imports.String_new("Use '!=' instead of '!=='"));
        }
      }
    } else if (c === 61) {
      kind = 5;
      if (i < limit && __imports.String_get(contents, i) === 61) {
        kind = 14;
        i = i + 1;
        if (i < limit && __imports.String_get(contents, i) === 61) {
          i = i + 1;
          log.error(createRange(source, start, i), __imports.String_new("Use '==' instead of '==='"));
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
      log.error(range, __imports.String_appendNew(__imports.String_append(__imports.String_new("Syntax error: '"), __imports.String_slice(contents, start, start + 1)), "'"));
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
  return kind >= 27 && kind <= 34;
}
function isUnaryPostfix(kind) {
  return kind >= 31 && kind <= 32;
}
function isBinary(kind) {
  return kind >= 35 && kind <= 53;
}
function isExpression(node) {
  return node.kind >= 15 && node.kind <= 53;
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
Node.prototype.childCount = function() {
  var count = 0;
  var child = this.firstChild;
  while (child !== null) {
    count = count + 1;
    child = child.nextSibling;
  }
  return count;
};
Node.prototype.appendChild = function(child) {
  child.parent = this;
  if (this.firstChild === null) {
    this.firstChild = child;
    this.lastChild = child;
  } else {
    child.previousSibling = this.lastChild;
    this.lastChild.nextSibling = child;
    this.lastChild = child;
  }
};
Node.prototype.insertChildBefore = function(after, before) {
  if (before === null) {
    return;
  }
  __imports.assert(before !== after);
  __imports.assert(before.parent === null);
  __imports.assert(before.previousSibling === null);
  __imports.assert(before.nextSibling === null);
  __imports.assert(after === null || after.parent === this);
  if (after === null) {
    this.appendChild(before);
    return;
  }
  before.parent = this;
  before.previousSibling = after.previousSibling;
  before.nextSibling = after;
  if (after.previousSibling !== null) {
    __imports.assert(after === after.previousSibling.nextSibling);
    after.previousSibling.nextSibling = before;
  } else {
    __imports.assert(after === this.firstChild);
    this.firstChild = before;
  }
  after.previousSibling = before;
};
Node.prototype.remove = function() {
  __imports.assert(this.parent !== null);
  if (this.previousSibling !== null) {
    __imports.assert(this.previousSibling.nextSibling === this);
    this.previousSibling.nextSibling = this.nextSibling;
  } else {
    __imports.assert(this.parent.firstChild === this);
    this.parent.firstChild = this.nextSibling;
  }
  if (this.nextSibling !== null) {
    __imports.assert(this.nextSibling.previousSibling === this);
    this.nextSibling.previousSibling = this.previousSibling;
  } else {
    __imports.assert(this.parent.lastChild === this);
    this.parent.lastChild = this.previousSibling;
  }
  this.parent = null;
  this.previousSibling = null;
  this.nextSibling = null;
};
Node.prototype.removeChildren = function() {
  while (this.lastChild !== null) {
    this.lastChild.remove();
  }
};
Node.prototype.becomeSymbolReference = function(symbol) {
  this.kind = 21;
  this.symbol = symbol;
  this.stringValue = symbol.name;
  this.resolvedType = symbol.resolvedType;
  this.removeChildren();
};
Node.prototype.becomeIntegerConstant = function(value) {
  this.kind = 20;
  this.intValue = value;
  this.removeChildren();
};
Node.prototype.isType = function() {
  return this.kind === 26 || this.symbol !== null && isType(this.symbol.kind);
};
Node.prototype.withRange = function(range) {
  this.range = range;
  return this;
};
Node.prototype.withInternalRange = function(range) {
  this.internalRange = range;
  return this;
};
Node.prototype.functionFirstArgumentIgnoringThis = function() {
  __imports.assert(this.kind === 10);
  __imports.assert(this.childCount() >= 2);
  __imports.assert(this.symbol !== null);
  return this.symbol.kind === 4 ? this.firstChild.nextSibling : this.firstChild;
};
Node.prototype.functionReturnType = function() {
  __imports.assert(this.kind === 10);
  __imports.assert(this.childCount() >= 2);
  __imports.assert(isExpression(this.lastChild.previousSibling));
  return this.lastChild.previousSibling;
};
Node.prototype.functionBody = function() {
  __imports.assert(this.kind === 10);
  __imports.assert(this.childCount() >= 2);
  __imports.assert(this.lastChild.kind === 2 || this.lastChild.kind === 7);
  var body = this.lastChild;
  return body.kind === 2 ? body : null;
};
Node.prototype.newType = function() {
  __imports.assert(this.kind === 22);
  __imports.assert(this.childCount() === 1);
  __imports.assert(isExpression(this.firstChild));
  return this.firstChild;
};
Node.prototype.callValue = function() {
  __imports.assert(this.kind === 16);
  __imports.assert(this.childCount() >= 1);
  __imports.assert(isExpression(this.firstChild));
  return this.firstChild;
};
Node.prototype.dotTarget = function() {
  __imports.assert(this.kind === 18);
  __imports.assert(this.childCount() === 1);
  __imports.assert(isExpression(this.firstChild));
  return this.firstChild;
};
Node.prototype.returnValue = function() {
  __imports.assert(this.kind === 12);
  __imports.assert(this.childCount() <= 1);
  __imports.assert(this.firstChild === null || isExpression(this.firstChild));
  return this.firstChild;
};
Node.prototype.variableType = function() {
  __imports.assert(this.kind === 1);
  __imports.assert(this.childCount() <= 2);
  __imports.assert(isExpression(this.firstChild) || this.firstChild.kind === 7);
  var type = this.firstChild;
  return type.kind !== 7 ? type : null;
};
Node.prototype.variableValue = function() {
  __imports.assert(this.kind === 1);
  __imports.assert(this.childCount() <= 2);
  __imports.assert(this.firstChild.nextSibling === null || isExpression(this.firstChild.nextSibling));
  return this.firstChild.nextSibling;
};
Node.prototype.expressionValue = function() {
  __imports.assert(this.kind === 9);
  __imports.assert(this.childCount() === 1);
  __imports.assert(isExpression(this.firstChild));
  return this.firstChild;
};
Node.prototype.binaryLeft = function() {
  __imports.assert(isBinary(this.kind));
  __imports.assert(this.childCount() === 2);
  __imports.assert(isExpression(this.firstChild));
  return this.firstChild;
};
Node.prototype.binaryRight = function() {
  __imports.assert(isBinary(this.kind));
  __imports.assert(this.childCount() === 2);
  __imports.assert(isExpression(this.lastChild));
  return this.lastChild;
};
Node.prototype.unaryValue = function() {
  __imports.assert(isUnary(this.kind));
  __imports.assert(this.childCount() === 1);
  __imports.assert(isExpression(this.firstChild));
  return this.firstChild;
};
Node.prototype.whileValue = function() {
  __imports.assert(this.kind === 14);
  __imports.assert(this.childCount() === 2);
  __imports.assert(isExpression(this.firstChild));
  return this.firstChild;
};
Node.prototype.whileBody = function() {
  __imports.assert(this.kind === 14);
  __imports.assert(this.childCount() === 2);
  __imports.assert(this.lastChild.kind === 2);
  return this.lastChild;
};
Node.prototype.hookValue = function() {
  __imports.assert(this.kind === 19);
  __imports.assert(this.childCount() === 3);
  __imports.assert(isExpression(this.firstChild));
  return this.firstChild;
};
Node.prototype.hookTrue = function() {
  __imports.assert(this.kind === 19);
  __imports.assert(this.childCount() === 3);
  __imports.assert(isExpression(this.firstChild.nextSibling));
  return this.firstChild.nextSibling;
};
Node.prototype.hookFalse = function() {
  __imports.assert(this.kind === 19);
  __imports.assert(this.childCount() === 3);
  __imports.assert(isExpression(this.lastChild));
  return this.lastChild;
};
Node.prototype.ifValue = function() {
  __imports.assert(this.kind === 11);
  __imports.assert(this.childCount() === 2 || this.childCount() === 3);
  __imports.assert(isExpression(this.firstChild));
  return this.firstChild;
};
Node.prototype.ifTrue = function() {
  __imports.assert(this.kind === 11);
  __imports.assert(this.childCount() === 2 || this.childCount() === 3);
  __imports.assert(this.firstChild.nextSibling.kind === 2);
  return this.firstChild.nextSibling;
};
Node.prototype.ifFalse = function() {
  __imports.assert(this.kind === 11);
  __imports.assert(this.childCount() === 2 || this.childCount() === 3);
  __imports.assert(this.firstChild.nextSibling.nextSibling === null || this.firstChild.nextSibling.nextSibling.kind === 2);
  return this.firstChild.nextSibling.nextSibling;
};
function createNew(type) {
  __imports.assert(isExpression(type));
  var node = new Node();
  node.kind = 22;
  node.appendChild(type);
  return node;
}
function createHook(test, primary, secondary) {
  __imports.assert(isExpression(test));
  __imports.assert(isExpression(primary));
  __imports.assert(isExpression(secondary));
  var node = new Node();
  node.kind = 19;
  node.appendChild(test);
  node.appendChild(primary);
  node.appendChild(secondary);
  return node;
}
function createNull() {
  var node = new Node();
  node.kind = 23;
  return node;
}
function createThis() {
  var node = new Node();
  node.kind = 25;
  return node;
}
function createBool(value) {
  var node = new Node();
  node.kind = 15;
  node.intValue = value ? 1 : 0;
  return node;
}
function createInt(value) {
  var node = new Node();
  node.kind = 20;
  node.intValue = value;
  return node;
}
function createString(value) {
  var node = new Node();
  node.kind = 24;
  node.stringValue = value;
  return node;
}
function createName(value) {
  var node = new Node();
  node.kind = 21;
  node.stringValue = value;
  return node;
}
function createType(type) {
  var node = new Node();
  node.kind = 26;
  node.resolvedType = type;
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
  node.kind = 9;
  node.appendChild(value);
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
function createEnum(name) {
  var node = new Node();
  node.kind = 8;
  node.stringValue = name;
  return node;
}
function createIf(value, trueBranch, falseBranch) {
  __imports.assert(isExpression(value));
  __imports.assert(trueBranch.kind === 2);
  __imports.assert(falseBranch === null || falseBranch.kind === 2);
  var node = new Node();
  node.kind = 11;
  node.appendChild(value);
  node.appendChild(trueBranch);
  if (falseBranch !== null) {
    node.appendChild(falseBranch);
  }
  return node;
}
function createWhile(value, body) {
  __imports.assert(isExpression(value));
  __imports.assert(body.kind === 2);
  var node = new Node();
  node.kind = 14;
  node.appendChild(value);
  node.appendChild(body);
  return node;
}
function createReturn(value) {
  __imports.assert(value === null || isExpression(value));
  var node = new Node();
  node.kind = 12;
  if (value !== null) {
    node.appendChild(value);
  }
  return node;
}
function createVariables() {
  var node = new Node();
  node.kind = 13;
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
  node.appendChild(type !== null ? type : createEmpty());
  if (value !== null) {
    node.appendChild(value);
  }
  return node;
}
function createFunction(name) {
  var node = new Node();
  node.kind = 10;
  node.stringValue = name;
  return node;
}
function createUnary(kind, value) {
  __imports.assert(isUnary(kind));
  __imports.assert(isExpression(value));
  var node = new Node();
  node.kind = kind;
  node.appendChild(value);
  return node;
}
function createBinary(kind, left, right) {
  __imports.assert(isBinary(kind));
  __imports.assert(isExpression(left));
  __imports.assert(isExpression(right));
  var node = new Node();
  node.kind = kind;
  node.appendChild(left);
  node.appendChild(right);
  return node;
}
function createCall(value) {
  __imports.assert(isExpression(value));
  var node = new Node();
  node.kind = 16;
  node.appendChild(value);
  return node;
}
function createDot(value, name) {
  __imports.assert(isExpression(value));
  var node = new Node();
  node.kind = 18;
  node.stringValue = name;
  node.appendChild(value);
  return node;
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
function ParserContext() {
  this.current = null;
  this.log = null;
}
ParserContext.prototype.peek = function(kind) {
  return this.current.kind === kind;
};
ParserContext.prototype.eat = function(kind) {
  if (this.peek(kind)) {
    this.advance();
    return true;
  }
  return false;
};
ParserContext.prototype.advance = function() {
  if (!this.peek(0)) {
    this.current = this.current.next;
  }
};
ParserContext.prototype.unexpectedToken = function() {
  this.log.error(this.current.range, __imports.String_append(__imports.String_new("Unexpected "), __imports.String_new(tokenToString(this.current.kind))));
};
ParserContext.prototype.expect = function(kind) {
  if (!this.peek(kind)) {
    this.log.error(this.current.range, __imports.String_append(__imports.String_append(__imports.String_append(__imports.String_new("Expected "), __imports.String_new(tokenToString(kind))), __imports.String_new(" but found ")), __imports.String_new(tokenToString(this.current.kind))));
    return false;
  }
  this.advance();
  return true;
};
ParserContext.prototype.parseUnaryPrefix = function(kind) {
  __imports.assert(isUnary(kind));
  var token = this.current;
  this.advance();
  var value = this.parseExpression(12);
  if (value === null) {
    return null;
  }
  return createUnary(kind, value).withRange(spanRanges(token.range, value.range));
};
ParserContext.prototype.parseBinary = function(kind, left, localPrecedence, operatorPrecedence) {
  if (localPrecedence >= operatorPrecedence) {
    return left;
  }
  this.advance();
  var right = this.parseExpression(operatorPrecedence === 1 ? 0 : operatorPrecedence);
  if (right === null) {
    return null;
  }
  return createBinary(kind, left, right).withRange(spanRanges(left.range, right.range));
};
ParserContext.prototype.parseUnaryPostfix = function(kind, value, localPrecedence) {
  if (localPrecedence >= 13) {
    return value;
  }
  var token = this.current;
  this.advance();
  return createUnary(kind, value).withRange(spanRanges(value.range, token.range));
};
ParserContext.prototype.parseQuotedString = function(range) {
  __imports.assert(range.end - range.start >= 2);
  var text = range.toString();
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
        this.log.error(escape, __imports.String_append(__imports.String_append(__imports.String_new("Invalid escape code '"), escape.toString()), __imports.String_new("'")));
        return null;
      }
    }
    end = end + 1;
  }
  return __imports.String_append(result, __imports.String_slice(text, start, end));
};
ParserContext.prototype.parsePrefix = function() {
  var token = this.current;
  if (this.eat(55)) {
    return createNull().withRange(token.range);
  }
  if (this.eat(57)) {
    return createThis().withRange(token.range);
  }
  if (this.peek(1)) {
    var text = this.parseQuotedString(token.range);
    if (text === null) {
      return null;
    }
    if (__imports.String_length(text) !== 1) {
      this.log.error(token.range, __imports.String_new("Invalid character literal"));
      return null;
    }
    this.advance();
    return createInt(__imports.String_get(text, 0)).withRange(token.range);
  }
  if (this.peek(4)) {
    var text = this.parseQuotedString(token.range);
    if (text === null) {
      return null;
    }
    this.advance();
    return createString(text).withRange(token.range);
  }
  if (this.peek(3)) {
    var value = parseInt(token.range);
    this.advance();
    return createInt(value).withRange(token.range);
  }
  if (this.eat(58)) {
    return createBool(true).withRange(token.range);
  }
  if (this.eat(48)) {
    return createBool(false).withRange(token.range);
  }
  if (this.peek(2)) {
    var value = token.range.toString();
    this.advance();
    return createName(value).withRange(token.range);
  }
  if (this.eat(54)) {
    var type = this.parseType();
    if (type === null || !this.expect(19)) {
      return null;
    }
    var close = this.current;
    if (!this.expect(35)) {
      return null;
    }
    return createNew(type).withRange(spanRanges(token.range, close.range));
  }
  if (this.eat(19)) {
    var value = this.parseExpression(0);
    if (value === null || !this.expect(35)) {
      return null;
    }
    return value;
  }
  if (this.peek(27)) {
    return this.parseUnaryPrefix(29);
  }
  if (this.peek(24)) {
    return this.parseUnaryPrefix(28);
  }
  if (this.peek(25)) {
    return this.parseUnaryPrefix(33);
  }
  if (this.peek(29)) {
    return this.parseUnaryPrefix(30);
  }
  if (this.peek(30)) {
    return this.parseUnaryPrefix(34);
  }
  if (this.peek(11)) {
    return this.parseUnaryPrefix(27);
  }
  this.unexpectedToken();
  return null;
};
ParserContext.prototype.parseInfix = function(precedence, node) {
  var token = this.current;
  if (this.peek(5)) {
    return this.parseBinary(36, node, precedence, 1);
  }
  if (this.peek(6)) {
    return this.parseBinary(37, node, precedence, 6);
  }
  if (this.peek(7)) {
    return this.parseBinary(38, node, precedence, 4);
  }
  if (this.peek(8)) {
    return this.parseBinary(39, node, precedence, 5);
  }
  if (this.peek(12)) {
    return this.parseBinary(40, node, precedence, 11);
  }
  if (this.peek(14)) {
    return this.parseBinary(41, node, precedence, 7);
  }
  if (this.peek(15)) {
    return this.parseBinary(42, node, precedence, 8);
  }
  if (this.peek(16)) {
    return this.parseBinary(43, node, precedence, 8);
  }
  if (this.peek(20)) {
    return this.parseBinary(44, node, precedence, 8);
  }
  if (this.peek(21)) {
    return this.parseBinary(45, node, precedence, 8);
  }
  if (this.peek(22)) {
    return this.parseBinary(46, node, precedence, 3);
  }
  if (this.peek(23)) {
    return this.parseBinary(47, node, precedence, 2);
  }
  if (this.peek(24)) {
    return this.parseBinary(53, node, precedence, 10);
  }
  if (this.peek(26)) {
    return this.parseBinary(48, node, precedence, 11);
  }
  if (this.peek(28)) {
    return this.parseBinary(49, node, precedence, 7);
  }
  if (this.peek(29)) {
    return this.parseBinary(35, node, precedence, 10);
  }
  if (this.peek(32)) {
    return this.parseBinary(50, node, precedence, 11);
  }
  if (this.peek(37)) {
    return this.parseBinary(51, node, precedence, 9);
  }
  if (this.peek(38)) {
    return this.parseBinary(52, node, precedence, 9);
  }
  if (this.peek(30)) {
    return this.parseUnaryPostfix(32, node, precedence);
  }
  if (this.peek(25)) {
    return this.parseUnaryPostfix(31, node, precedence);
  }
  if (this.peek(19) && precedence < 13) {
    this.advance();
    var call = createCall(node);
    if (!this.peek(35)) {
      while (true) {
        var value = this.parseExpression(0);
        if (value === null) {
          return null;
        }
        call.appendChild(value);
        if (!this.eat(10)) {
          break;
        }
      }
    }
    var close = this.current;
    if (!this.expect(35)) {
      return null;
    }
    return call.withRange(spanRanges(node.range, close.range)).withInternalRange(spanRanges(token.range, close.range));
  }
  if (this.peek(31) && precedence < 1) {
    this.advance();
    var middle = this.parseExpression(0);
    if (middle === null || !this.expect(9)) {
      return null;
    }
    var right = this.parseExpression(0);
    if (right === null) {
      return null;
    }
    return createHook(node, middle, right).withRange(spanRanges(node.range, right.range));
  }
  if (this.peek(13) && precedence < 14) {
    this.advance();
    var name = this.current;
    if (!this.expect(2)) {
      return null;
    }
    return createDot(node, name.range.toString()).withRange(spanRanges(node.range, name.range)).withInternalRange(name.range);
  }
  return node;
};
ParserContext.prototype.parseExpression = function(precedence) {
  var node = this.parsePrefix();
  if (node === null) {
    return null;
  }
  __imports.assert(node.range !== null);
  while (true) {
    var result = this.parseInfix(precedence, node);
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
};
ParserContext.prototype.parseType = function() {
  return this.parseExpression(13);
};
ParserContext.prototype.parseIf = function() {
  var token = this.current;
  __imports.assert(token.kind === 50);
  this.advance();
  if (!this.expect(19)) {
    return null;
  }
  var value = this.parseExpression(0);
  if (value === null || !this.expect(35)) {
    return null;
  }
  var trueBranch = this.parseBody();
  if (trueBranch === null) {
    return null;
  }
  var falseBranch = null;
  if (this.eat(43)) {
    falseBranch = this.parseBody();
    if (falseBranch === null) {
      return null;
    }
  }
  return createIf(value, trueBranch, falseBranch).withRange(spanRanges(token.range, (falseBranch !== null ? falseBranch : trueBranch).range));
};
ParserContext.prototype.parseWhile = function() {
  var token = this.current;
  __imports.assert(token.kind === 60);
  this.advance();
  if (!this.expect(19)) {
    return null;
  }
  var value = this.parseExpression(0);
  if (value === null || !this.expect(35)) {
    return null;
  }
  var body = this.parseBody();
  if (body === null) {
    return null;
  }
  return createWhile(value, body).withRange(spanRanges(token.range, body.range));
};
ParserContext.prototype.parseBody = function() {
  var node = this.parseStatement();
  if (node === null) {
    return null;
  }
  if (node.kind === 2) {
    return node;
  }
  var block = createBlock();
  block.appendChild(node);
  return block.withRange(node.range);
};
ParserContext.prototype.parseBlock = function() {
  var open = this.current;
  if (!this.expect(17)) {
    return null;
  }
  var block = createBlock();
  if (!this.parseStatements(block)) {
    return null;
  }
  var close = this.current;
  if (!this.expect(33)) {
    return null;
  }
  return block.withRange(spanRanges(open.range, close.range));
};
ParserContext.prototype.parseReturn = function() {
  var token = this.current;
  __imports.assert(token.kind === 56);
  this.advance();
  var value = null;
  if (!this.peek(36)) {
    value = this.parseExpression(0);
    if (value === null) {
      return null;
    }
  }
  var semicolon = this.current;
  if (!this.expect(36)) {
    return null;
  }
  return createReturn(value).withRange(spanRanges(token.range, semicolon.range));
};
ParserContext.prototype.parseEnum = function(flags) {
  var token = this.current;
  __imports.assert(token.kind === 44);
  this.advance();
  var name = this.current;
  if (!this.expect(2) || !this.expect(17)) {
    return null;
  }
  var text = name.range.toString();
  var node = createEnum(text);
  node.flags = flags;
  while (!this.peek(0) && !this.peek(33)) {
    var member = this.current.range;
    var value = null;
    if (!this.expect(2)) {
      return null;
    }
    if (this.eat(5)) {
      value = this.parseExpression(0);
      if (value === null) {
        return null;
      }
    }
    var variable = createVariable(member.toString(), createName(text), value);
    node.appendChild(variable.withRange(value !== null ? spanRanges(member, value.range) : member).withInternalRange(member));
    if (!this.eat(10)) {
      break;
    }
  }
  var close = this.current;
  if (!this.expect(33)) {
    return null;
  }
  return node.withRange(spanRanges(token.range, close.range)).withInternalRange(name.range);
};
ParserContext.prototype.parseClass = function(flags) {
  var token = this.current;
  __imports.assert(token.kind === 40);
  this.advance();
  var name = this.current;
  if (!this.expect(2) || !this.expect(17)) {
    return null;
  }
  var node = createClass(name.range.toString());
  node.flags = flags;
  while (!this.peek(0) && !this.peek(33)) {
    var start = this.current;
    if (!this.expect(2)) {
      return null;
    }
    if (this.peek(19)) {
      this.current = start;
      if (this.parseFunction(0, node) === null) {
        return null;
      }
    } else {
      this.current = start;
      if (this.parseVariables(0, node) === null) {
        return null;
      }
    }
  }
  var close = this.current;
  if (!this.expect(33)) {
    return null;
  }
  return node.withRange(spanRanges(token.range, close.range)).withInternalRange(name.range);
};
ParserContext.prototype.parseFunction = function(flags, parent) {
  var token = this.current;
  if (parent === null) {
    __imports.assert(token.kind === 49);
    this.advance();
  }
  var name = this.current;
  if (!this.expect(2) || !this.expect(19)) {
    return null;
  }
  var node = createFunction(name.range.toString());
  node.flags = flags;
  if (!this.peek(35)) {
    while (true) {
      var argument = this.current;
      if (!this.expect(2) || !this.expect(9)) {
        return null;
      }
      var type = this.parseType();
      if (type === null) {
        return null;
      }
      var variable = createVariable(argument.range.toString(), type, null);
      node.appendChild(variable.withRange(spanRanges(argument.range, type.range)).withInternalRange(argument.range));
      if (!this.eat(10)) {
        break;
      }
    }
  }
  if (!this.expect(35) || !this.expect(9)) {
    return null;
  }
  var returnType = this.parseType();
  if (returnType === null) {
    return null;
  }
  node.appendChild(returnType);
  var block = null;
  var semicolon = this.current;
  if (this.eat(36)) {
    block = createEmpty().withRange(semicolon.range);
  } else {
    block = this.parseBlock();
    if (block === null) {
      return null;
    }
  }
  if (parent !== null) {
    parent.appendChild(node);
  }
  node.appendChild(block);
  return node.withRange(spanRanges(token.range, block.range)).withInternalRange(name.range);
};
ParserContext.prototype.parseVariables = function(flags, parent) {
  var token = this.current;
  if (parent === null) {
    __imports.assert(token.kind === 59 || token.kind === 41);
    this.advance();
  }
  var node = token.kind === 41 ? createConstants() : createVariables();
  while (true) {
    var name = this.current;
    if (!this.expect(2)) {
      return null;
    }
    var type = null;
    if (this.eat(9)) {
      type = this.parseType();
      if (type === null) {
        return null;
      }
    }
    var value = null;
    if (this.eat(5)) {
      value = this.parseExpression(0);
      if (value === null) {
        return null;
      }
      if (parent !== null) {
        this.log.error(value.range, __imports.String_new("Inline initialization of instance variables is not supported yet"));
      }
    }
    var range = value !== null ? spanRanges(name.range, value.range) : type !== null ? spanRanges(name.range, type.range) : name.range;
    var variable = createVariable(name.range.toString(), type, value);
    variable.flags = flags;
    (parent !== null ? parent : node).appendChild(variable.withRange(range).withInternalRange(name.range));
    if (!this.eat(10)) {
      break;
    }
  }
  var semicolon = this.current;
  if (!this.expect(36)) {
    return null;
  }
  return node.withRange(spanRanges(token.range, semicolon.range));
};
ParserContext.prototype.parseLoopJump = function(kind) {
  var token = this.current;
  this.advance();
  if (!this.expect(36)) {
    return null;
  }
  var node = new Node();
  node.kind = kind;
  return node.withRange(token.range);
};
ParserContext.prototype.parseStatement = function() {
  var flags = 0;
  if (this.eat(47)) {
    flags = flags | 1;
  }
  if (this.peek(41) || this.peek(59)) {
    return this.parseVariables(flags, null);
  }
  if (this.peek(49)) {
    return this.parseFunction(flags, null);
  }
  if (this.peek(40)) {
    return this.parseClass(flags);
  }
  if (this.peek(44)) {
    return this.parseEnum(flags);
  }
  if (flags !== 0) {
    this.unexpectedToken();
    return null;
  }
  if (this.peek(17)) {
    return this.parseBlock();
  }
  if (this.peek(39)) {
    return this.parseLoopJump(3);
  }
  if (this.peek(42)) {
    return this.parseLoopJump(6);
  }
  if (this.peek(50)) {
    return this.parseIf();
  }
  if (this.peek(60)) {
    return this.parseWhile();
  }
  if (this.peek(56)) {
    return this.parseReturn();
  }
  if (this.peek(36)) {
    var token = this.current;
    this.advance();
    return createEmpty().withRange(token.range);
  }
  var value = this.parseExpression(0);
  if (value === null) {
    return null;
  }
  var semicolon = this.current;
  if (!this.expect(36)) {
    return null;
  }
  return createExpression(value).withRange(spanRanges(value.range, semicolon.range));
};
ParserContext.prototype.parseStatements = function(parent) {
  while (!this.peek(0) && !this.peek(33)) {
    var child = this.parseStatement();
    if (child === null) {
      return false;
    }
    parent.appendChild(child);
  }
  return true;
};
function parse(firstToken, log) {
  var context = new ParserContext();
  context.current = firstToken;
  context.log = log;
  var global = new Node();
  global.kind = 0;
  if (!context.parseStatements(global)) {
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
Range.prototype.toString = function() {
  return __imports.String_slice(this.source.contents, this.start, this.end);
};
Range.prototype.enclosingLine = function() {
  var contents = this.source.contents;
  var start = this.start;
  var end = this.start;
  while (start > 0 && __imports.String_get(contents, start - 1) !== 10) {
    start = start - 1;
  }
  while (end + 1 < __imports.String_length(contents) && __imports.String_get(contents, end) !== 10) {
    end = end + 1;
  }
  return createRange(this.source, start, end);
};
function Diagnostic() {
  this.range = null;
  this.message = null;
  this.next = null;
}
function Log() {
  this.first = null;
  this.last = null;
}
Log.prototype.error = function(range, message) {
  var diagnostic = new Diagnostic();
  diagnostic.range = range;
  diagnostic.message = message;
  this.append(diagnostic);
};
Log.prototype.append = function(diagnostic) {
  if (this.first === null) {
    this.first = diagnostic;
  } else {
    this.last.next = diagnostic;
  }
  this.last = diagnostic;
};
Log.prototype.toString = function() {
  var result = __imports.String_new("");
  var d = this.first;
  while (d !== null) {
    var lineRange = d.range.enclosingLine();
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
    result = __imports.String_append(result, lineRange.toString());
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
};
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
WasmModule.prototype.allocateImport = function(signatureIndex, mod, name) {
  var result = new WasmImport();
  result.signatureIndex = signatureIndex;
  result.module = mod;
  result.name = name;
  if (this.firstImport === null) {
    this.firstImport = result;
  } else {
    this.lastImport.next = result;
  }
  this.lastImport = result;
  this.importCount = this.importCount + 1;
  return result;
};
WasmModule.prototype.allocateFunction = function(name, signatureIndex, body) {
  var fn = new WasmFunction();
  fn.name = name;
  fn.signatureIndex = signatureIndex;
  fn.body = body;
  if (this.firstFunction === null) {
    this.firstFunction = fn;
  } else {
    this.lastFunction.next = fn;
  }
  this.lastFunction = fn;
  this.functionCount = this.functionCount + 1;
  return fn;
};
WasmModule.prototype.allocateSignature = function(argumentTypes, returnType) {
  __imports.assert(returnType !== null);
  __imports.assert(returnType.next === null);
  var signature = new WasmSignature();
  signature.argumentTypes = argumentTypes;
  signature.returnType = returnType;
  var check = this.firstSignature;
  var i = 0;
  while (check !== null) {
    if (wasmAreSignaturesEqual(signature, check)) {
      return i;
    }
    check = check.next;
    i = i + 1;
  }
  if (this.firstSignature === null) {
    this.firstSignature = signature;
  } else {
    this.lastSignature.next = signature;
  }
  this.lastSignature = signature;
  this.signatureCount = this.signatureCount + 1;
  return i;
};
WasmModule.prototype.emitModule = function(array) {
  __imports.ByteArray_appendByte(array, 1836278016);
  __imports.ByteArray_appendByte(array, 1836278016 >> 8);
  __imports.ByteArray_appendByte(array, 1836278016 >> 16);
  __imports.ByteArray_appendByte(array, 1836278016 >> 24);
  __imports.ByteArray_appendByte(array, 10);
  __imports.ByteArray_appendByte(array, 10 >> 8);
  __imports.ByteArray_appendByte(array, 10 >> 16);
  __imports.ByteArray_appendByte(array, 10 >> 24);
  this.emitSignatures(array);
  this.emitImportTable(array);
  this.emitFunctionSignatures(array);
  this.emitMemory(array);
  this.emitExportTable(array);
  this.emitFunctionBodies(array);
  this.emitDataSegments(array);
};
WasmModule.prototype.emitSignatures = function(array) {
  var section = wasmStartSection(array, __imports.String_new("signatures"));
  wasmWriteVarUnsigned(array, this.signatureCount);
  var signature = this.firstSignature;
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
};
WasmModule.prototype.emitImportTable = function(array) {
  if (this.firstImport === null) {
    return;
  }
  var section = wasmStartSection(array, __imports.String_new("import_table"));
  wasmWriteVarUnsigned(array, this.importCount);
  var current = this.firstImport;
  while (current !== null) {
    wasmWriteVarUnsigned(array, current.signatureIndex);
    wasmWriteLengthPrefixedString(array, current.module);
    wasmWriteLengthPrefixedString(array, current.name);
    current = current.next;
  }
  wasmFinishSection(array, section);
};
WasmModule.prototype.emitFunctionSignatures = function(array) {
  if (this.firstFunction === null) {
    return;
  }
  var section = wasmStartSection(array, __imports.String_new("function_signatures"));
  wasmWriteVarUnsigned(array, this.functionCount);
  var fn = this.firstFunction;
  while (fn !== null) {
    wasmWriteVarUnsigned(array, fn.signatureIndex);
    fn = fn.next;
  }
  wasmFinishSection(array, section);
};
WasmModule.prototype.emitMemory = function(array) {
  var section = wasmStartSection(array, __imports.String_new("memory"));
  wasmWriteVarUnsigned(array, 256);
  wasmWriteVarUnsigned(array, 256);
  wasmWriteVarUnsigned(array, 1);
  wasmFinishSection(array, section);
};
WasmModule.prototype.emitExportTable = function(array) {
  var exportedCount = 0;
  var fn = this.firstFunction;
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
  fn = this.firstFunction;
  while (fn !== null) {
    if (fn.isExported) {
      wasmWriteVarUnsigned(array, i);
      wasmWriteLengthPrefixedString(array, fn.name);
    }
    fn = fn.next;
    i = i + 1;
  }
  wasmFinishSection(array, section);
};
WasmModule.prototype.emitFunctionBodies = function(array) {
  if (this.firstFunction === null) {
    return;
  }
  var section = wasmStartSection(array, __imports.String_new("function_bodies"));
  wasmWriteVarUnsigned(array, this.functionCount);
  var fn = this.firstFunction;
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
};
WasmModule.prototype.emitDataSegments = function(array) {
  var section = wasmStartSection(array, __imports.String_new("data_segments"));
  wasmWriteVarUnsigned(array, 1);
  var memoryInitializer = this.memoryInitializer;
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
};
WasmModule.prototype.collectStrings = function(node) {
  if (node.kind === 24) {
    var memoryInitializer = this.memoryInitializer;
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
    this.collectStrings(child);
    child = child.nextSibling;
  }
};
WasmModule.prototype.prepareFunctions = function(node, context) {
  if (node.kind === 0 || node.kind === 4) {
    var child = node.firstChild;
    while (child !== null) {
      this.prepareFunctions(child, context);
      child = child.nextSibling;
    }
  } else if (node.kind === 10) {
    var returnType = node.functionReturnType();
    var shared = new WasmSharedOffset();
    var argumentTypesFirst = null;
    var argumentTypesLast = null;
    var argument = node.firstChild;
    while (argument !== returnType) {
      var type = wasmWrapType(wasmGetType(context, argument.variableType().resolvedType));
      if (argumentTypesFirst === null) {
        argumentTypesFirst = type;
      } else {
        argumentTypesLast.next = type;
      }
      argumentTypesLast = type;
      shared.nextLocalOffset = shared.nextLocalOffset + 1;
      argument = argument.nextSibling;
    }
    var signatureIndex = this.allocateSignature(argumentTypesFirst, wasmWrapType(wasmGetType(context, returnType.resolvedType)));
    var body = node.functionBody();
    if (body === null) {
      node.symbol.offset = this.importCount;
      this.allocateImport(signatureIndex, __imports.String_new("imports"), node.symbol.name);
      node = node.nextSibling;
      return;
    }
    node.symbol.offset = this.functionCount;
    var fn = this.allocateFunction(node.symbol.name, signatureIndex, body);
    if (isExternSymbol(node.symbol)) {
      fn.isExported = true;
    }
    wasmAssignLocalVariableOffsets(body, shared);
    fn.intLocalCount = shared.intLocalCount;
  }
};
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
function emitBinaryExpression(array, node, opcode) {
  __imports.ByteArray_appendByte(array, opcode);
  wasmEmitNode(array, node.binaryLeft());
  wasmEmitNode(array, node.binaryRight());
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
  } else if (node.kind === 14) {
    var value = node.whileValue();
    var body = node.whileBody();
    if (value.kind === 15 && value.intValue === 0) {
      return 0;
    }
    __imports.ByteArray_appendByte(array, 2);
    var offset = __imports.ByteArray_length(array);
    wasmWriteVarUnsigned(array, ~0);
    var count = 0;
    if (value.kind !== 15) {
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
    while (parent !== null && parent.kind !== 14) {
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
  } else if (node.kind === 9) {
    wasmEmitNode(array, node.expressionValue());
  } else if (node.kind === 12) {
    var value = node.returnValue();
    __imports.ByteArray_appendByte(array, 20);
    if (value !== null) {
      wasmEmitNode(array, value);
    }
  } else if (node.kind === 13) {
    var count = 0;
    var child = node.firstChild;
    while (child !== null) {
      __imports.assert(child.kind === 1);
      count = count + wasmEmitNode(array, child);
      child = child.nextSibling;
    }
    return count;
  } else if (node.kind === 11) {
    var branch = node.ifFalse();
    __imports.ByteArray_appendByte(array, branch === null ? 3 : 4);
    wasmEmitNode(array, node.ifValue());
    wasmEmitNode(array, node.ifTrue());
    if (branch !== null) {
      wasmEmitNode(array, branch);
    }
  } else if (node.kind === 19) {
    __imports.ByteArray_appendByte(array, 4);
    wasmEmitNode(array, node.hookValue());
    wasmEmitNode(array, node.hookTrue());
    wasmEmitNode(array, node.hookFalse());
  } else if (node.kind === 1) {
    var value = node.variableValue();
    if (node.symbol.kind === 9) {
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
  } else if (node.kind === 21) {
    if (node.symbol.kind === 6 || node.symbol.kind === 9) {
      __imports.ByteArray_appendByte(array, 14);
      wasmWriteVarUnsigned(array, node.symbol.offset);
    } else {
      __imports.assert(false);
    }
  } else if (node.kind === 23) {
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, 0);
  } else if (node.kind === 20 || node.kind === 15) {
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, node.intValue);
  } else if (node.kind === 24) {
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, node.intValue);
  } else if (node.kind === 16) {
    var value = node.callValue();
    var symbol = value.symbol;
    __imports.assert(isFunction(symbol.kind));
    __imports.ByteArray_appendByte(array, symbol.node.functionBody() === null ? 31 : 18);
    wasmWriteVarUnsigned(array, symbol.offset);
    if (symbol.kind === 4) {
      wasmEmitNode(array, value.dotTarget());
    }
    var child = value.nextSibling;
    while (child !== null) {
      wasmEmitNode(array, child);
      child = child.nextSibling;
    }
  } else if (node.kind === 22) {
    var type = node.newType();
    __imports.assert(type.symbol.kind === 0);
    __imports.ByteArray_appendByte(array, 31);
    wasmWriteVarUnsigned(array, 0);
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, type.symbol.offset);
  } else if (node.kind === 30) {
    wasmEmitNode(array, node.unaryValue());
  } else if (node.kind === 28) {
    __imports.ByteArray_appendByte(array, 65);
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, 0);
    wasmEmitNode(array, node.unaryValue());
  } else if (node.kind === 27) {
    __imports.ByteArray_appendByte(array, 73);
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, ~0);
    wasmEmitNode(array, node.unaryValue());
  } else if (node.kind === 29) {
    __imports.ByteArray_appendByte(array, 90);
    wasmEmitNode(array, node.unaryValue());
  } else if (node.kind === 18) {
    var symbol = node.symbol;
    if (symbol.kind === 8) {
      __imports.ByteArray_appendByte(array, 42);
      wasmWriteVarUnsigned(array, 2);
      wasmWriteVarUnsigned(array, symbol.offset);
      wasmEmitNode(array, node.dotTarget());
    } else {
      __imports.assert(false);
    }
  } else if (node.kind === 36) {
    var left = node.binaryLeft();
    var symbol = left.symbol;
    if (symbol.kind === 8) {
      __imports.assert(left.kind === 18);
      __imports.ByteArray_appendByte(array, 51);
      wasmWriteVarUnsigned(array, 2);
      wasmWriteVarUnsigned(array, symbol.offset);
      wasmEmitNode(array, left.dotTarget());
      wasmEmitNode(array, node.binaryRight());
    } else if (symbol.kind === 6 || symbol.kind === 9) {
      __imports.ByteArray_appendByte(array, 15);
      wasmWriteVarUnsigned(array, symbol.offset);
      wasmEmitNode(array, node.binaryRight());
    } else {
      __imports.assert(false);
    }
  } else if (node.kind === 35) {
    emitBinaryExpression(array, node, 64);
  } else if (node.kind === 53) {
    emitBinaryExpression(array, node, 65);
  } else if (node.kind === 48) {
    emitBinaryExpression(array, node, 66);
  } else if (node.kind === 40) {
    emitBinaryExpression(array, node, 67);
  } else if (node.kind === 50) {
    emitBinaryExpression(array, node, 69);
  } else if (node.kind === 51) {
    emitBinaryExpression(array, node, 74);
  } else if (node.kind === 52) {
    emitBinaryExpression(array, node, 76);
  } else if (node.kind === 37) {
    emitBinaryExpression(array, node, 71);
  } else if (node.kind === 38) {
    emitBinaryExpression(array, node, 72);
  } else if (node.kind === 39) {
    emitBinaryExpression(array, node, 73);
  } else if (node.kind === 41) {
    emitBinaryExpression(array, node, 77);
  } else if (node.kind === 49) {
    emitBinaryExpression(array, node, 78);
  } else if (node.kind === 44) {
    emitBinaryExpression(array, node, 79);
  } else if (node.kind === 45) {
    emitBinaryExpression(array, node, 80);
  } else if (node.kind === 42) {
    emitBinaryExpression(array, node, 83);
  } else if (node.kind === 43) {
    emitBinaryExpression(array, node, 84);
  } else if (node.kind === 46) {
    __imports.ByteArray_appendByte(array, 4);
    wasmEmitNode(array, node.binaryLeft());
    wasmEmitNode(array, node.binaryRight());
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, 0);
  } else if (node.kind === 47) {
    __imports.ByteArray_appendByte(array, 4);
    wasmEmitNode(array, node.binaryLeft());
    __imports.ByteArray_appendByte(array, 10);
    wasmWriteVarSigned(array, 1);
    wasmEmitNode(array, node.binaryRight());
  } else {
    __imports.assert(false);
  }
  return 1;
}
function wasmWrapType(id) {
  __imports.assert(id === 0 || id === 1);
  var type = new WasmType();
  type.id = id;
  return type;
}
function wasmGetType(context, type) {
  if (type === context.boolType || type.isInteger(context) || typeIsReference(context, type)) {
    return 1;
  }
  if (type === context.voidType) {
    return 0;
  }
  __imports.assert(false);
  return 0;
}
function WasmSharedOffset() {
  this.nextLocalOffset = 0;
  this.intLocalCount = 0;
}
function wasmAssignLocalVariableOffsets(node, shared) {
  if (node.kind === 1) {
    __imports.assert(node.symbol.kind === 9);
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
  var signatureIndex = module.allocateSignature(wasmWrapType(1), wasmWrapType(1));
  module.allocateImport(signatureIndex, __imports.String_new("imports"), __imports.String_new("new"));
  module.collectStrings(global);
  module.prepareFunctions(global, context);
  module.emitModule(array);
}
