function ByteArray_setString(array, index, text) {
  var length = globals.string_length(text);
  globals.assert(index >= 0 && (index + length | 0) <= array.length());
  var data = array._data;
  var i = 0;

  while (i < length) {
    data[index + i | 0] = globals.string_get(text, i) & 255;
    i = i + 1 | 0;
  }
}

function ByteArray() {
  this._data = null;
  this._length = 0;
}

ByteArray.prototype.length = function() {
  return this._length;
};

ByteArray.prototype.clear = function() {
  this._length = 0;
};

ByteArray.prototype.get = function(index) {
  globals.assert(index >>> 0 < this._length >>> 0);

  return this._data[index];
};

ByteArray.prototype.set = function(index, value) {
  globals.assert(index >>> 0 < this._length >>> 0);
  this._data[index] = value;
};

ByteArray.prototype.append = function(value) {
  var index = this._length;
  this.resize(index + 1 | 0);
  this._data[index] = value;
};

ByteArray.prototype.bytes = function() {
  return this._data.subarray(0, this._length);
};

ByteArray.prototype.resize = function(length) {
  if (length > (this._data !== null ? this._data.length : 0)) {
    var capacity = length << 1;
    var data = globals.Uint8Array_new(capacity);

    if (this._data !== null) {
      data.set(this._data);
    }

    this._data = data;
  }

  this._length = length;
};

function ByteArray_set16(array, index, value) {
  array.set(index, value & 255);
  array.set(index + 1 | 0, value >> 8 & 255);
}

function ByteArray_set32(array, index, value) {
  array.set(index, value & 255);
  array.set(index + 1 | 0, value >> 8 & 255);
  array.set(index + 2 | 0, value >> 16 & 255);
  array.set(index + 3 | 0, value >> 24 & 255);
}

function ByteArray_append32(array, value) {
  array.append(value & 255);
  array.append(value >> 8 & 255);
  array.append(value >> 16 & 255);
  array.append(value >> 24 & 255);
}

function CheckContext() {
  this.log = null;
  this.isUnsafeAllowed = false;
  this.currentReturnType = null;
  this.nextGlobalVariableOffset = 0;
  this.boolType = null;
  this.byteType = null;
  this.errorType = null;
  this.intType = null;
  this.nullType = null;
  this.shortType = null;
  this.stringType = null;
  this.ubyteType = null;
  this.uintType = null;
  this.ushortType = null;
  this.voidType = null;
}

CheckContext.prototype.allocateGlobalVariableOffset = function(sizeOf, alignmentOf) {
  var offset = alignToNextMultipleOf(this.nextGlobalVariableOffset, alignmentOf);
  this.nextGlobalVariableOffset = offset + sizeOf | 0;

  return offset;
};

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

    if (kind !== 1 && kind !== 14 && (kind !== 10 || parentKind !== 4) && parentKind === 0 !== (kind === 4 || kind === 8 || kind === 10 || kind === 5)) {
      context.log.error(node.range, "This statement is not allowed here");
    }
  }

  if (node.kind === 0) {
    globals.assert(parentScope === null);
    var symbol = new Symbol();
    symbol.kind = 2;
    symbol.name = "<global>";
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
    symbol.state = 2;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    parentScope = symbol.scope;
    context.boolType = parentScope.defineNativeType(context.log, "bool", 1);
    context.errorType = parentScope.defineNativeType(context.log, "<error>", 0);
    context.nullType = parentScope.defineNativeType(context.log, "null", 0);
    context.stringType = parentScope.defineNativeType(context.log, "string", 4);
    context.voidType = parentScope.defineNativeType(context.log, "void", 0);
    context.byteType = parentScope.defineNativeIntegerType(context.log, "byte", 1, false);
    context.intType = parentScope.defineNativeIntegerType(context.log, "int", 4, false);
    context.shortType = parentScope.defineNativeIntegerType(context.log, "short", 2, false);
    context.ubyteType = parentScope.defineNativeIntegerType(context.log, "ubyte", 1, true);
    context.uintType = parentScope.defineNativeIntegerType(context.log, "uint", 4, true);
    context.ushortType = parentScope.defineNativeIntegerType(context.log, "ushort", 2, true);
  }

  else if (node.kind === 4 || node.kind === 8) {
    var symbol = new Symbol();
    symbol.kind = node.kind === 4 ? 0 : 1;
    symbol.name = node.stringValue;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    parentScope.define(context.log, symbol);
    parentScope = symbol.scope;
  }

  else if (node.kind === 10) {
    var symbol = new Symbol();
    symbol.kind = node.parent.kind === 4 ? 4 : 5;
    symbol.name = node.stringValue;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    parentScope.define(context.log, symbol);
    parentScope = symbol.scope;

    if (symbol.kind === 4) {
      var parent = symbol.parent();
      globals.assert(parent.kind === 0);
      initializeSymbol(context, parent);
      node.insertChildBefore(node.firstChild, createVariable("this", createType(parent.resolvedType), null));
    }
  }

  else if (node.kind === 1) {
    var symbol = new Symbol();
    symbol.kind = node.parent.kind === 4 ? 9 : node.parent.kind === 10 ? 6 : node.parent.kind === 5 || node.parent.kind === 8 ? 7 : node.parent.kind === 14 && node.parent.parent.kind === 0 ? 8 : 10;
    symbol.name = node.stringValue;
    symbol.scope = parentScope;
    linkSymbolToNode(symbol, node);
    parentScope.define(context.log, symbol);
  }

  else if (node.kind === 2) {
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

function forbidFlag(context, node, flag, text) {
  if ((node.flags & flag) !== 0) {
    var range = rangeForFlag(node.firstFlag, flag);

    if (range !== null) {
      node.flags = node.flags & ~flag;
      context.log.error(range, text);
    }
  }
}

function requireFlag(context, node, flag, text) {
  if ((node.flags & flag) === 0) {
    node.flags = node.flags | flag;
    context.log.error(node.range, text);
  }
}

function initializeSymbol(context, symbol) {
  if (symbol.state === 2) {
    globals.assert(symbol.resolvedType !== null);

    return;
  }

  globals.assert(symbol.state === 0);
  globals.assert(symbol.resolvedType === null);
  symbol.state = 1;
  var node = symbol.node;
  forbidFlag(context, node, 2, "Unsupported flag 'export'");
  forbidFlag(context, node, 8, "Unsupported flag 'get'");
  forbidFlag(context, node, 16, "Unsupported flag 'private'");
  forbidFlag(context, node, 32, "Unsupported flag 'protected'");
  forbidFlag(context, node, 64, "Unsupported flag 'public'");
  forbidFlag(context, node, 128, "Unsupported flag 'set'");
  forbidFlag(context, node, 256, "Unsupported flag 'static'");

  if (symbol.kind === 0) {
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
  }

  else if (symbol.kind === 1) {
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
    var underlyingSymbol = symbol.resolvedType.underlyingType(context).symbol;
    symbol.byteSize = underlyingSymbol.byteSize;
    symbol.maxAlignment = underlyingSymbol.maxAlignment;
  }

  else if (isFunction(symbol.kind)) {
    var body = node.functionBody();
    var returnType = node.functionReturnType();
    resolveAsType(context, returnType, symbol.scope.parent);
    var offset = 0;
    var child = node.firstChild;

    while (child !== returnType) {
      globals.assert(child.kind === 1);
      globals.assert(child.symbol.kind === 6);
      initializeSymbol(context, child.symbol);
      child.symbol.offset = offset;
      offset = offset + 1 | 0;
      child = child.nextSibling;
    }

    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;

    if (symbol.kind === 4) {
      forbidFlag(context, node, 4, "Cannot use 'extern' on an instance function");
      forbidFlag(context, node, 1, "Cannot use 'declare' on an instance function");

      if (symbol.parent().node.isDeclare()) {
        node.flags = node.flags | 1;

        if (body !== null) {
          context.log.error(body.range, "Cannot implement a function on a declared class");
        }
      }

      else if (body === null) {
        context.log.error(node.lastChild.range, "Must implement this function");
      }
    }

    else if (body === null) {
      forbidFlag(context, node, 4, "Cannot use 'extern' on an unimplemented function");
      requireFlag(context, node, 1, "Declared functions must be prefixed with 'declare'");
    }

    else {
      forbidFlag(context, node, 1, "Cannot use 'declare' on a function with an implementation");
    }
  }

  else if (isVariable(symbol.kind)) {
    var type = node.variableType();
    var value = node.variableValue();

    if (type !== null) {
      resolveAsType(context, type, symbol.scope);
      symbol.resolvedType = type.resolvedType;
    }

    else if (value !== null) {
      resolveAsExpression(context, value, symbol.scope);
      symbol.resolvedType = value.resolvedType;
    }

    else {
      context.log.error(node.internalRange, "Cannot create untyped variables");
      symbol.resolvedType = context.errorType;
    }

    if (symbol.resolvedType === context.voidType || symbol.resolvedType === context.nullType) {
      context.log.error(node.internalRange, StringBuilder_new().append("Cannot create a variable with type '").append(symbol.resolvedType.toString()).appendChar(39).finish());
      symbol.resolvedType = context.errorType;
    }

    if (symbol.kind === 7) {
      if (value !== null) {
        resolveAsExpression(context, value, symbol.scope);
        checkConversion(context, value, symbol.resolvedTypeUnderlyingIfEnumValue(context), 0);

        if (value.kind === 23 || value.kind === 17) {
          symbol.offset = value.intValue;
        }

        else if (value.resolvedType !== context.errorType) {
          context.log.error(value.range, "Invalid constant initializer");
          symbol.resolvedType = context.errorType;
        }
      }

      else if (symbol.isEnumValue()) {
        if (node.previousSibling !== null) {
          var previousSymbol = node.previousSibling.symbol;
          initializeSymbol(context, previousSymbol);
          symbol.offset = previousSymbol.offset + 1 | 0;
        }

        else {
          symbol.offset = 0;
        }
      }

      else {
        context.log.error(node.internalRange, "Constants must be initialized");
      }
    }

    if (symbol.scope.symbol === null) {
      var scope = symbol.scope.parent;

      while (scope !== null) {
        var shadowed = scope.findLocal(symbol.name);

        if (shadowed !== null) {
          context.log.error(node.internalRange, StringBuilder_new().append("The symbol '").append(symbol.name).append("' shadows another symbol with the same name in a parent scope").finish());

          break;
        }

        if (scope.symbol !== null) {
          break;
        }

        scope = scope.parent;
      }
    }
  }

  else {
    globals.assert(false);
  }

  globals.assert(symbol.resolvedType !== null);
  symbol.state = 2;
}

function resolveChildren(context, node, parentScope) {
  var child = node.firstChild;

  while (child !== null) {
    resolve(context, child, parentScope);
    child = child.nextSibling;
  }
}

function resolveChildrenAsExpressions(context, node, parentScope) {
  var child = node.firstChild;

  while (child !== null) {
    resolveAsExpression(context, child, parentScope);
    child = child.nextSibling;
  }
}

function resolveAsExpression(context, node, parentScope) {
  globals.assert(isExpression(node));
  resolve(context, node, parentScope);

  if (node.resolvedType !== context.errorType && node.isType()) {
    context.log.error(node.range, "Expected expression but found type");
    node.resolvedType = context.errorType;
  }
}

function resolveAsType(context, node, parentScope) {
  globals.assert(isExpression(node));
  resolve(context, node, parentScope);

  if (node.resolvedType !== context.errorType && !node.isType()) {
    context.log.error(node.range, "Expected type but found expression");
    node.resolvedType = context.errorType;
  }
}

function checkConversion(context, node, to, kind) {
  var from = node.resolvedType;
  var canCast = false;
  globals.assert(isExpression(node));
  globals.assert(from !== null);
  globals.assert(to !== null);

  if (from === to || from === context.errorType || to === context.errorType) {
    return;
  }

  else if (from === context.nullType && to.isReference(context)) {
    return;
  }

  else if (context.isUnsafeAllowed && (from.isReference(context) || to.isReference(context))) {
    if (kind === 1) {
      return;
    }

    canCast = true;
  }

  else if (from.isInteger() && to.isInteger()) {
    var mask = to.integerBitMask();

    if (kind === 1 || from.symbol.byteSize < to.symbol.byteSize || node.kind === 23 && (to.isUnsigned() ? node.intValue >= 0 && node.intValue >>> 0 <= mask : node.intValue >= (~mask | 0) >> 1 && node.intValue <= (mask >>> 1 | 0))) {
      return;
    }

    canCast = true;
  }

  context.log.error(node.range, StringBuilder_new().append("Cannot convert from type '").append(from.toString()).append("' to type '").append(to.toString()).append(canCast ? "' without a cast" : "'").finish());
  node.resolvedType = context.errorType;
}

function checkStorage(context, target) {
  globals.assert(isExpression(target));

  if (target.resolvedType !== context.errorType && target.kind !== 22 && (target.kind !== 24 && target.kind !== 20 || target.symbol !== null && (!isVariable(target.symbol.kind) || target.symbol.kind === 7))) {
    context.log.error(target.range, "Cannot store to this location");
    target.resolvedType = context.errorType;
  }
}

function createDefaultValueForType(context, type) {
  if (type.isInteger()) {
    return createInt(0);
  }

  if (type === context.boolType) {
    return createBool(false);
  }

  globals.assert(type.isReference(context));

  return createNull();
}

function simplifyBinary(node) {
  var left = node.binaryLeft();
  var right = node.binaryRight();

  if ((node.kind === 40 || node.kind === 53 || node.kind === 42 || node.kind === 43 || node.kind === 44) && left.kind === 23 && right.kind !== 23) {
    left.remove();
    node.appendChild(left);
    left = node.binaryLeft();
    right = node.binaryRight();
  }

  if ((node.kind === 53 || (node.kind === 45 || node.kind === 55) && node.resolvedType.isUnsigned()) && right.kind === 23 && isPositivePowerOf2(right.intValue)) {
    var shift = -1;
    var value = right.intValue;

    while (value !== 0) {
      value = value >> 1;
      shift = shift + 1 | 0;
    }

    if (node.kind === 53) {
      node.kind = 56;
      right.intValue = shift;
    }

    else if (node.kind === 45) {
      node.kind = 57;
      right.intValue = shift;
    }

    else if (node.kind === 55) {
      node.kind = 42;
      right.intValue = right.intValue - 1 | 0;
    }

    else {
      globals.assert(false);
    }
  }

  else if (node.kind === 40 && right.kind === 33) {
    var value = right.unaryValue();
    node.kind = 58;
    value.remove();
    right.replaceWith(value);
  }

  else if (node.kind === 40 && right.isNegativeInteger()) {
    node.kind = 58;
    right.intValue = -right.intValue;
  }
}

function binaryHasUnsignedArguments(node) {
  var left = node.binaryLeft();
  var right = node.binaryRight();
  var leftType = left.resolvedType;
  var rightType = right.resolvedType;

  return leftType.isUnsigned() && rightType.isUnsigned() || leftType.isUnsigned() && right.isNonNegativeInteger() || left.isNonNegativeInteger() && rightType.isUnsigned();
}

function isSymbolAccessAllowed(context, symbol, range) {
  if (symbol.isUnsafe() && !context.isUnsafeAllowed) {
    context.log.error(range, StringBuilder_new().append("Cannot use symbol '").append(symbol.name).append("' outside an unsafe block").finish());

    return false;
  }

  return true;
}

function resolve(context, node, parentScope) {
  globals.assert(node.kind === 0 || parentScope !== null);

  if (node.resolvedType !== null) {
    return;
  }

  node.resolvedType = context.errorType;

  if (node.kind === 0) {
    resolveChildren(context, node, node.scope);
  }

  else if (node.kind === 4) {
    initializeSymbol(context, node.symbol);
    resolveChildren(context, node, node.scope);
    node.symbol.determineClassLayout(context);
  }

  else if (node.kind === 8) {
    initializeSymbol(context, node.symbol);
    resolveChildren(context, node, node.scope);
  }

  else if (node.kind === 10) {
    var body = node.functionBody();
    initializeSymbol(context, node.symbol);

    if (body !== null) {
      var oldReturnType = context.currentReturnType;
      var oldUnsafeAllowed = context.isUnsafeAllowed;
      context.currentReturnType = node.functionReturnType().resolvedType;
      context.isUnsafeAllowed = node.isUnsafe();
      resolveChildren(context, body, node.scope);
      context.currentReturnType = oldReturnType;
      context.isUnsafeAllowed = oldUnsafeAllowed;
    }
  }

  else if (node.kind === 1) {
    var symbol = node.symbol;
    initializeSymbol(context, symbol);
    var value = node.variableValue();

    if (value !== null) {
      resolveAsExpression(context, value, parentScope);
      checkConversion(context, value, symbol.resolvedTypeUnderlyingIfEnumValue(context), 0);

      if (symbol.kind === 8 && value.kind !== 23 && value.kind !== 17 && value.kind !== 26) {
        context.log.error(value.range, "Global initializers must be compile-time constants");
      }
    }

    else if (symbol.resolvedType !== context.errorType) {
      value = createDefaultValueForType(context, symbol.resolvedType);
      resolveAsExpression(context, value, parentScope);
      node.appendChild(value);
    }

    if (symbol.kind === 8 && symbol.resolvedType !== context.errorType) {
      symbol.offset = context.allocateGlobalVariableOffset(symbol.resolvedType.variableSizeOf(), symbol.resolvedType.variableAlignmentOf());
    }
  }

  else if (node.kind === 3 || node.kind === 6) {
    var found = false;
    var n = node;

    while (n !== null) {
      if (n.kind === 15) {
        found = true;

        break;
      }

      n = n.parent;
    }

    if (!found) {
      context.log.error(node.range, "Cannot use this statement outside of a loop");
    }
  }

  else if (node.kind === 2) {
    var oldUnsafeAllowed = context.isUnsafeAllowed;

    if (node.isUnsafe()) {
      context.isUnsafeAllowed = true;
    }

    resolveChildren(context, node, node.scope);
    context.isUnsafeAllowed = oldUnsafeAllowed;
  }

  else if (node.kind === 5 || node.kind === 14) {
    resolveChildren(context, node, parentScope);
  }

  else if (node.kind === 23) {
    node.resolvedType = node.intValue < 0 ? context.uintType : context.intType;
  }

  else if (node.kind === 29) {
    node.resolvedType = context.stringType;
  }

  else if (node.kind === 17) {
    node.resolvedType = context.boolType;
  }

  else if (node.kind === 26) {
    node.resolvedType = context.nullType;
  }

  else if (node.kind === 22) {
    resolveChildrenAsExpressions(context, node, parentScope);
    var target = node.indexTarget();
    var type = target.resolvedType;

    if (type !== context.errorType) {
      var symbol = type.isClass() ? type.findMember("[]") : null;

      if (symbol === null) {
        context.log.error(node.internalRange, StringBuilder_new().append("Cannot index into type '").append(target.resolvedType.toString()).appendChar(39).finish());
      }

      else {
        globals.assert(symbol.kind === 4);
        node.kind = 18;
        target.remove();
        node.insertChildBefore(node.firstChild, createMemberReference(target, symbol));
        node.resolvedType = null;
        resolveAsExpression(context, node, parentScope);
      }
    }
  }

  else if (node.kind === 16) {
    var type = node.alignOfType();
    resolveAsType(context, type, parentScope);
    node.resolvedType = context.intType;

    if (type.resolvedType !== context.errorType) {
      node.becomeIntegerConstant(type.resolvedType.allocationAlignmentOf());
    }
  }

  else if (node.kind === 28) {
    var type = node.sizeOfType();
    resolveAsType(context, type, parentScope);
    node.resolvedType = context.intType;

    if (type.resolvedType !== context.errorType) {
      node.becomeIntegerConstant(type.resolvedType.allocationSizeOf());
    }
  }

  else if (node.kind === 30) {
    var symbol = parentScope.findNested("this", 0);

    if (symbol === null) {
      context.log.error(node.range, "Cannot use 'this' here");
    }

    else {
      node.becomeSymbolReference(symbol);
    }
  }

  else if (node.kind === 27) {
    node.resolvedType = context.errorType;
  }

  else if (node.kind === 24) {
    var name = node.stringValue;
    var symbol = parentScope.findNested(name, 0);

    if (symbol === null) {
      var builder = StringBuilder_new().append("No symbol named '").append(name).append("' here");
      symbol = parentScope.findNested(name, 1);

      if (symbol !== null) {
        builder.append(", did you mean 'this.").append(symbol.name).append("'?");
      }

      else if (globals.string_equals(name, "number")) {
        builder.append(", did you mean 'int'?");
      }

      else if (globals.string_equals(name, "boolean")) {
        builder.append(", did you mean 'bool'?");
      }

      context.log.error(node.range, builder.finish());
    }

    else if (symbol.state === 1) {
      context.log.error(node.range, StringBuilder_new().append("Cyclic reference to symbol '").append(name).append("' here").finish());
    }

    else if (isFunction(symbol.kind) && (node.parent.kind !== 18 || node !== node.parent.callValue())) {
      context.log.error(node.range, "Bare function references are not allowed");
    }

    else if (isSymbolAccessAllowed(context, symbol, node.range)) {
      initializeSymbol(context, symbol);
      node.symbol = symbol;
      node.resolvedType = symbol.resolvedType;

      if (symbol.kind === 7) {
        if (symbol.resolvedType === context.boolType) {
          node.becomeBooleanConstant(symbol.offset !== 0);
        }

        else {
          node.becomeIntegerConstant(symbol.offset);
        }
      }
    }
  }

  else if (node.kind === 19) {
    var value = node.castValue();
    var type = node.castType();
    resolveAsExpression(context, value, parentScope);
    resolveAsType(context, type, parentScope);
    var castedType = type.resolvedType;
    checkConversion(context, value, castedType, 1);
    node.resolvedType = castedType;

    if (value.kind === 23 && castedType.isInteger()) {
      var result = value.intValue;
      var shift = 32 - castedType.integerBitCount() | 0;
      node.becomeIntegerConstant(castedType.isUnsigned() ? (castedType.integerBitMask() | 0) & result : result << shift >> shift);
    }
  }

  else if (node.kind === 20) {
    var target = node.dotTarget();
    resolve(context, target, parentScope);

    if (target.resolvedType !== context.errorType) {
      if (target.isType() && target.resolvedType.isEnum() || !target.isType() && target.resolvedType.isClass()) {
        var child = target.resolvedType.symbol.node.firstChild;
        var name = node.stringValue;

        if (globals.string_length(name) > 0) {
          var symbol = target.resolvedType.findMember(name);

          if (symbol === null) {
            context.log.error(node.internalRange, StringBuilder_new().append("No member named '").append(name).append("' on type '").append(target.resolvedType.toString()).appendChar(39).finish());
          }

          else if (isSymbolAccessAllowed(context, symbol, node.internalRange)) {
            initializeSymbol(context, symbol);
            node.symbol = symbol;
            node.resolvedType = symbol.resolvedType;

            if (symbol.kind === 7) {
              node.becomeIntegerConstant(symbol.offset);
            }
          }
        }
      }

      else {
        context.log.error(node.internalRange, StringBuilder_new().append("The type '").append(target.resolvedType.toString()).append("' has no members").finish());
      }
    }
  }

  else if (node.kind === 18) {
    var value = node.callValue();
    resolveAsExpression(context, value, parentScope);

    if (value.resolvedType !== context.errorType) {
      var symbol = value.symbol;

      if (symbol === null || !isFunction(symbol.kind)) {
        context.log.error(value.range, StringBuilder_new().append("Cannot call value of type '").append(value.resolvedType.toString()).appendChar(39).finish());
      }

      else {
        initializeSymbol(context, symbol);
        var returnType = symbol.node.functionReturnType();
        var argumentVariable = symbol.node.functionFirstArgumentIgnoringThis();
        var argumentValue = value.nextSibling;

        while (argumentVariable !== returnType && argumentValue !== null) {
          resolveAsExpression(context, argumentValue, parentScope);
          checkConversion(context, argumentValue, argumentVariable.symbol.resolvedType, 0);
          argumentVariable = argumentVariable.nextSibling;
          argumentValue = argumentValue.nextSibling;
        }

        if (argumentVariable !== returnType) {
          context.log.error(node.internalRange, StringBuilder_new().append("Not enough arguments for function '").append(symbol.name).appendChar(39).finish());
        }

        else if (argumentValue !== null) {
          while (argumentValue !== null) {
            resolveAsExpression(context, argumentValue, parentScope);
            argumentValue = argumentValue.nextSibling;
          }

          context.log.error(node.internalRange, StringBuilder_new().append("Too many arguments for function '").append(symbol.name).appendChar(39).finish());
        }

        node.resolvedType = returnType.resolvedType;
      }
    }
  }

  else if (node.kind === 12) {
    var value = node.returnValue();

    if (value !== null) {
      resolveAsExpression(context, value, parentScope);

      if (context.currentReturnType !== null) {
        if (context.currentReturnType !== context.voidType) {
          checkConversion(context, value, context.currentReturnType, 0);
        }

        else {
          context.log.error(value.range, "Unexpected return value in function returning 'void'");
        }
      }
    }

    else if (context.currentReturnType !== null && context.currentReturnType !== context.voidType) {
      context.log.error(node.range, StringBuilder_new().append("Expected return value in function returning '").append(context.currentReturnType.toString()).appendChar(39).finish());
    }
  }

  else if (node.kind === 7) {
  }

  else if (node.kind === 9) {
    resolveAsExpression(context, node.expressionValue(), parentScope);
  }

  else if (node.kind === 15) {
    var value = node.whileValue();
    var body = node.whileBody();
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType, 0);
    resolve(context, body, parentScope);
  }

  else if (node.kind === 11) {
    var value = node.ifValue();
    var yes = node.ifTrue();
    var no = node.ifFalse();
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType, 0);
    resolve(context, yes, parentScope);

    if (no !== null) {
      resolve(context, no, parentScope);
    }
  }

  else if (node.kind === 21) {
    var value = node.hookValue();
    var yes = node.hookTrue();
    var no = node.hookFalse();
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType, 0);
    resolve(context, yes, parentScope);
    resolve(context, no, parentScope);
    var commonType = (yes.resolvedType === context.nullType ? no : yes).resolvedType;

    if (yes.resolvedType !== commonType && (yes.resolvedType !== context.nullType || !commonType.isReference(context)) && no.resolvedType !== commonType && (no.resolvedType !== context.nullType || !commonType.isReference(context))) {
      context.log.error(spanRanges(yes.range, no.range), StringBuilder_new().append("Type '").append(yes.resolvedType.toString()).append("' is not the same as type '").append(no.resolvedType.toString()).appendChar(39).finish());
    }

    node.resolvedType = commonType;
  }

  else if (node.kind === 41) {
    var left = node.binaryLeft();
    var right = node.binaryRight();

    if (left.kind === 22) {
      resolveChildrenAsExpressions(context, left, parentScope);
      var target = left.indexTarget();
      var type = target.resolvedType;

      if (type !== context.errorType) {
        var symbol = type.isClass() ? type.findMember("[]=") : null;

        if (symbol === null) {
          context.log.error(left.internalRange, StringBuilder_new().append("Cannot index into type '").append(target.resolvedType.toString()).appendChar(39).finish());
        }

        else {
          globals.assert(symbol.kind === 4);
          node.kind = 18;
          target.remove();
          left.remove();

          while (left.lastChild !== null) {
            var value = left.lastChild;
            value.remove();
            node.insertChildBefore(node.firstChild, value);
          }

          node.insertChildBefore(node.firstChild, createMemberReference(target, symbol));
          node.internalRange = spanRanges(left.internalRange, right.range);
          node.resolvedType = null;
          resolveAsExpression(context, node, parentScope);

          return;
        }
      }
    }

    resolveAsExpression(context, left, parentScope);
    resolveAsExpression(context, right, parentScope);
    checkConversion(context, right, left.resolvedType, 0);
    checkStorage(context, left);
    node.resolvedType = left.resolvedType;
  }

  else if (node.kind === 40 || node.kind === 58 || node.kind === 53 || node.kind === 45 || node.kind === 55 || node.kind === 42 || node.kind === 43 || node.kind === 44 || node.kind === 56 || node.kind === 57) {
    var left = node.binaryLeft();
    var right = node.binaryRight();
    resolveAsExpression(context, left, parentScope);
    resolveAsExpression(context, right, parentScope);
    var commonType = binaryHasUnsignedArguments(node) ? context.uintType : context.intType;

    if (commonType === context.uintType) {
      node.flags = node.flags | 1024;
    }

    checkConversion(context, left, commonType, 0);
    checkConversion(context, right, commonType, 0);
    node.resolvedType = commonType;

    if (left.kind === 23 && right.kind === 23) {
      var inputLeft = left.intValue;
      var inputRight = right.intValue;
      var output = 0;

      if (node.kind === 40) {
        output = inputLeft + inputRight | 0;
      }

      else if (node.kind === 42) {
        output = inputLeft & inputRight;
      }

      else if (node.kind === 43) {
        output = inputLeft | inputRight;
      }

      else if (node.kind === 44) {
        output = inputLeft ^ inputRight;
      }

      else if (node.kind === 45) {
        output = inputLeft / inputRight | 0;
      }

      else if (node.kind === 53) {
        output = __imul(inputLeft, inputRight);
      }

      else if (node.kind === 55) {
        output = inputLeft % inputRight | 0;
      }

      else if (node.kind === 56) {
        output = inputLeft << inputRight;
      }

      else if (node.kind === 57) {
        output = inputLeft >> inputRight;
      }

      else if (node.kind === 58) {
        output = inputLeft - inputRight | 0;
      }

      else {
        return;
      }

      node.becomeIntegerConstant(output);
    }

    else {
      simplifyBinary(node);
    }
  }

  else if (node.kind === 49 || node.kind === 50 || node.kind === 47 || node.kind === 48) {
    var left = node.binaryLeft();
    var right = node.binaryRight();
    resolveAsExpression(context, left, parentScope);
    resolveAsExpression(context, right, parentScope);
    var leftType = left.resolvedType;
    var rightType = right.resolvedType;
    var expectedType = leftType === rightType && leftType.isEnum() ? leftType : binaryHasUnsignedArguments(node) ? context.uintType : context.intType;

    if (expectedType === context.uintType) {
      node.flags = node.flags | 1024;
    }

    checkConversion(context, left, expectedType, 0);
    checkConversion(context, right, expectedType, 0);
    node.resolvedType = context.boolType;
  }

  else if (node.kind === 52 || node.kind === 51) {
    var left = node.binaryLeft();
    var right = node.binaryRight();
    resolveAsExpression(context, left, parentScope);
    resolveAsExpression(context, right, parentScope);
    checkConversion(context, left, context.boolType, 0);
    checkConversion(context, right, context.boolType, 0);
    node.resolvedType = context.boolType;
  }

  else if (node.kind === 46 || node.kind === 54) {
    var left = node.binaryLeft();
    var right = node.binaryRight();
    resolveAsExpression(context, left, parentScope);
    resolveAsExpression(context, right, parentScope);
    node.resolvedType = context.boolType;
    var leftType = left.resolvedType;
    var rightType = right.resolvedType;

    if (leftType !== context.errorType && rightType !== context.errorType && (leftType === rightType ? leftType === context.voidType : (leftType !== context.nullType || !rightType.isReference(context)) && (rightType !== context.nullType || !leftType.isReference(context)) && (!leftType.isUnsigned() || !right.isNonNegativeInteger()) && (!rightType.isUnsigned() || !left.isNonNegativeInteger()))) {
      context.log.error(node.range, StringBuilder_new().append("Cannot compare type '").append(leftType.toString()).append("' with type '").append(rightType.toString()).appendChar(39).finish());
    }
  }

  else if (node.kind === 32 || node.kind === 33 || node.kind === 35) {
    var value = node.unaryValue();
    resolveAsExpression(context, value, parentScope);
    var expectedType = value.resolvedType.isUnsigned() ? context.uintType : context.intType;
    checkConversion(context, value, expectedType, 0);
    node.resolvedType = node.kind === 33 ? context.intType : expectedType;

    if (value.kind === 23) {
      var input = value.intValue;
      var output = input;

      if (node.kind === 32) {
        output = ~input;
      }

      else if (node.kind === 33) {
        output = -input;
      }

      node.becomeIntegerConstant(output);
    }
  }

  else if (node.kind === 36 || node.kind === 37 || node.kind === 38 || node.kind === 39) {
    context.log.error(node.range, "This operator is currently unsupported");
  }

  else if (node.kind === 34) {
    var value = node.unaryValue();
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context.boolType, 0);
    node.resolvedType = context.boolType;
  }

  else if (node.kind === 25) {
    var type = node.newType();
    resolveAsType(context, type, parentScope);

    if (type.resolvedType !== context.errorType) {
      if (!type.resolvedType.isClass()) {
        context.log.error(type.range, StringBuilder_new().append("Cannot construct type '").append(type.resolvedType.toString()).appendChar(39).finish());
      }

      else {
        node.resolvedType = type.resolvedType;
      }
    }

    if (type.nextSibling !== null) {
      context.log.error(node.internalRange, "Constructors with arguments are not supported yet");
    }
  }

  else {
    globals.assert(false);
  }
}

function check(global, log) {
  var context = new CheckContext();
  context.log = log;
  initialize(context, global, null);
  resolve(context, global, null);

  return context;
}

function Compiler() {
  this.log = null;
  this.global = null;
  this.firstSource = null;
  this.lastSource = null;
  this.target = 0;
  this.context = null;
  this.wasm = null;
  this.js = null;
}

Compiler.prototype.initialize = function(target) {
  globals.assert(this.log === null);
  this.log = new Log();
  this.global = new Node();
  this.global.kind = 0;
  this.target = target;

  if (target === 2) {
    this.addInput("<native>", libraryForWebAssembly());
  }
};

Compiler.prototype.addInput = function(name, contents) {
  var source = new Source();
  source.name = name;
  source.contents = contents;

  if (this.firstSource === null) {
    this.firstSource = source;
  }

  else {
    this.lastSource.next = source;
  }

  this.lastSource = source;
};

Compiler.prototype.finish = function() {
  globals.Profiler_begin();
  var source = this.firstSource;

  while (source !== null) {
    source.firstToken = tokenize(source, this.log);
    source = source.next;
  }

  globals.Profiler_end(globals.String_new("lexing"));
  globals.Profiler_begin();
  source = this.firstSource;

  while (source !== null) {
    if (source.firstToken !== null) {
      var file = parse(source.firstToken, this.log);

      if (file !== null) {
        while (file.firstChild !== null) {
          var child = file.firstChild;
          child.remove();
          this.global.appendChild(child);
        }
      }
    }

    source = source.next;
  }

  globals.Profiler_end(globals.String_new("parsing"));
  globals.Profiler_begin();
  globals.assert(this.context === null);
  this.context = check(this.global, this.log);
  globals.Profiler_end(globals.String_new("checking"));

  if (this.log.first !== null) {
    return false;
  }

  globals.Profiler_begin();

  if (this.target === 1) {
    this.js = jsEmit(this.global, this.context);
  }

  else if (this.target === 2) {
    this.wasm = new ByteArray();
    wasmEmit(this.global, this.context, this.wasm);
  }

  globals.Profiler_end(globals.String_new("emitting"));

  return true;
};

var Compiler_new = exports.Compiler_new = function(target) {
  var compiler = new Compiler();
  compiler.initialize(target);

  return compiler;
};

var Compiler_addInput = exports.Compiler_addInput = function(compiler, name, contents) {
  compiler.addInput(name, contents);
};

var Compiler_finish = exports.Compiler_finish = function(compiler) {
  compiler.finish();
};

var Compiler_wasm = exports.Compiler_wasm = function(compiler) {
  return compiler.wasm;
};

var Compiler_js = exports.Compiler_js = function(compiler) {
  return compiler.js;
};

var Compiler_log = exports.Compiler_log = function(compiler) {
  return globals.String_new(compiler.log.toString());
};

function String() {
}

function isPositivePowerOf2(value) {
  return value > 0 && (value & value - 1) === 0;
}

function alignToNextMultipleOf(offset, alignment) {
  globals.assert(isPositivePowerOf2(alignment));

  return (offset + alignment | 0) - 1 & -alignment;
}

function JsResult() {
  this.context = null;
  this.code = null;
  this.indent = 0;
  this.foundMultiply = false;
  this.previousNode = null;
}

JsResult.prototype.emitIndent = function() {
  var i = this.indent;

  while (i > 0) {
    this.code = globals.String_appendNew(this.code, "  ");
    i = i - 1 | 0;
  }
};

JsResult.prototype.emitText = function(text) {
  this.code = globals.String_appendNew(this.code, text);
};

JsResult.prototype.emitString = function(text) {
  this.code = globals.String_append(this.code, text);
};

JsResult.prototype.emitNewlineBefore = function(node) {
  if (this.previousNode !== null && (!jsIsCompactNodeKind(this.previousNode.kind) || !jsIsCompactNodeKind(node.kind))) {
    this.emitText("\n");
  }

  this.previousNode = null;
};

JsResult.prototype.emitNewlineAfter = function(node) {
  this.previousNode = node;
};

JsResult.prototype.emitStatements = function(node) {
  while (node !== null) {
    this.emitStatement(node);
    node = node.nextSibling;
  }
};

JsResult.prototype.emitBlock = function(node) {
  this.previousNode = null;
  this.emitText("{\n");
  this.indent = this.indent + 1 | 0;
  this.emitStatements(node.firstChild);
  this.indent = this.indent - 1 | 0;
  this.emitIndent();
  this.emitText("}");
  this.previousNode = null;
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

JsResult.prototype.emitBinary = function(node, parentPrecedence, operator, operatorPrecedence, mode) {
  var isRightAssociative = node.kind === 41;
  var parentKind = node.parent.kind;
  var isUnsigned = node.isUnsignedOperator();
  var shouldCastToInt = mode === 1 && (isUnsigned || parentKind !== 56 && parentKind !== 57 && parentKind !== 43 && parentKind !== 42 && parentKind !== 44);
  var selfPrecedence = shouldCastToInt ? isUnsigned ? 9 : 4 : parentPrecedence;

  if (parentPrecedence > selfPrecedence) {
    this.emitText("(");
  }

  if (selfPrecedence > operatorPrecedence) {
    this.emitText("(");
  }

  this.emitExpression(node.binaryLeft(), isRightAssociative ? operatorPrecedence + 1 | 0 : operatorPrecedence);
  this.emitText(operator);
  this.emitExpression(node.binaryRight(), isRightAssociative ? operatorPrecedence : operatorPrecedence + 1 | 0);

  if (selfPrecedence > operatorPrecedence) {
    this.emitText(")");
  }

  if (shouldCastToInt) {
    this.emitText(isUnsigned ? " >>> 0" : " | 0");
  }

  if (parentPrecedence > selfPrecedence) {
    this.emitText(")");
  }
};

JsResult.prototype.emitCommaSeparatedExpressions = function(start, stop) {
  while (start !== stop) {
    this.emitExpression(start, 0);
    start = start.nextSibling;

    if (start !== stop) {
      this.emitText(", ");
    }
  }
};

JsResult.prototype.emitExpression = function(node, parentPrecedence) {
  globals.assert(node.resolvedType !== null);

  if (node.kind === 24) {
    var symbol = node.symbol;

    if (symbol.kind === 5 && symbol.node.isDeclare()) {
      this.emitText("globals.");
    }

    this.emitText(symbol.name);
  }

  else if (node.kind === 26) {
    this.emitText("null");
  }

  else if (node.kind === 17) {
    this.emitText(node.intValue !== 0 ? "true" : "false");
  }

  else if (node.kind === 23) {
    this.emitString(node.resolvedType.isUnsigned() ? globals.String_toStringUnsigned(node.intValue >>> 0) : globals.String_toStringSigned(node.intValue));
  }

  else if (node.kind === 29) {
    this.emitString(globals.String_quote(globals.String_new(node.stringValue)));
  }

  else if (node.kind === 19) {
    var context = this.context;
    var value = node.castValue();
    var from = value.resolvedType.underlyingType(context);
    var type = node.resolvedType.underlyingType(context);

    if (from === type || from.symbol.byteSize < type.symbol.byteSize) {
      this.emitExpression(value, parentPrecedence);
    }

    else if (type === context.byteType || type === context.shortType) {
      if (parentPrecedence > 9) {
        this.emitText("(");
      }

      var shift = globals.String_toStringSigned(32 - (type.symbol.byteSize << 3) | 0);
      this.emitExpression(value, 9);
      this.emitText(" << ");
      this.emitString(shift);
      this.emitText(" >> ");
      this.emitString(shift);

      if (parentPrecedence > 9) {
        this.emitText(")");
      }
    }

    else if (type === context.ubyteType || type === context.ushortType) {
      if (parentPrecedence > 6) {
        this.emitText("(");
      }

      this.emitExpression(value, 6);
      this.emitText(" & ");
      this.emitString(globals.String_toStringUnsigned(type.integerBitMask()));

      if (parentPrecedence > 6) {
        this.emitText(")");
      }
    }

    else if (type === context.intType) {
      if (parentPrecedence > 4) {
        this.emitText("(");
      }

      this.emitExpression(value, 4);
      this.emitText(" | 0");

      if (parentPrecedence > 4) {
        this.emitText(")");
      }
    }

    else if (type === context.uintType) {
      if (parentPrecedence > 9) {
        this.emitText("(");
      }

      this.emitExpression(value, 9);
      this.emitText(" >>> 0");

      if (parentPrecedence > 9) {
        this.emitText(")");
      }
    }

    else {
      this.emitExpression(value, parentPrecedence);
    }
  }

  else if (node.kind === 20) {
    this.emitExpression(node.dotTarget(), 14);
    this.emitSymbolAccess(node.symbol);
  }

  else if (node.kind === 21) {
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
  }

  else if (node.kind === 18) {
    var value = node.callValue();
    var isDeclaredInstance = value.kind === 20 && value.symbol.node.isDeclare();

    if (isDeclaredInstance && globals.string_equals(value.symbol.name, "[]")) {
      this.emitExpression(value.dotTarget(), 13);
      this.emitText("[");
      this.emitCommaSeparatedExpressions(value.nextSibling, null);
      this.emitText("]");
    }

    else if (isDeclaredInstance && globals.string_equals(value.symbol.name, "[]=")) {
      if (parentPrecedence > 1) {
        this.emitText("(");
      }

      this.emitExpression(value.dotTarget(), 13);
      this.emitText("[");
      this.emitCommaSeparatedExpressions(value.nextSibling, node.lastChild);
      this.emitText("] = ");
      this.emitExpression(node.lastChild, 1);

      if (parentPrecedence > 1) {
        this.emitText(")");
      }
    }

    else {
      this.emitExpression(value, 13);
      this.emitText("(");
      this.emitCommaSeparatedExpressions(value.nextSibling, null);
      this.emitText(")");
    }
  }

  else if (node.kind === 25) {
    this.emitText("new ");
    this.emitExpression(node.newType(), 13);
    this.emitText("()");
  }

  else if (node.kind === 32) {
    this.emitUnary(node, parentPrecedence, "~");
  }

  else if (node.kind === 33) {
    this.emitUnary(node, parentPrecedence, "-");
  }

  else if (node.kind === 34) {
    this.emitUnary(node, parentPrecedence, "!");
  }

  else if (node.kind === 35) {
    this.emitUnary(node, parentPrecedence, "+");
  }

  else if (node.kind === 39) {
    this.emitUnary(node, parentPrecedence, "++");
  }

  else if (node.kind === 38) {
    this.emitUnary(node, parentPrecedence, "--");
  }

  else if (node.kind === 37) {
    this.emitUnary(node, parentPrecedence, "++");
  }

  else if (node.kind === 36) {
    this.emitUnary(node, parentPrecedence, "--");
  }

  else if (node.kind === 40) {
    this.emitBinary(node, parentPrecedence, " + ", 10, 1);
  }

  else if (node.kind === 41) {
    this.emitBinary(node, parentPrecedence, " = ", 1, 0);
  }

  else if (node.kind === 42) {
    this.emitBinary(node, parentPrecedence, " & ", 6, 0);
  }

  else if (node.kind === 43) {
    this.emitBinary(node, parentPrecedence, " | ", 4, 0);
  }

  else if (node.kind === 44) {
    this.emitBinary(node, parentPrecedence, " ^ ", 5, 0);
  }

  else if (node.kind === 45) {
    this.emitBinary(node, parentPrecedence, " / ", 11, 1);
  }

  else if (node.kind === 46) {
    this.emitBinary(node, parentPrecedence, " === ", 7, 0);
  }

  else if (node.kind === 47) {
    this.emitBinary(node, parentPrecedence, " > ", 8, 0);
  }

  else if (node.kind === 48) {
    this.emitBinary(node, parentPrecedence, " >= ", 8, 0);
  }

  else if (node.kind === 49) {
    this.emitBinary(node, parentPrecedence, " < ", 8, 0);
  }

  else if (node.kind === 50) {
    this.emitBinary(node, parentPrecedence, " <= ", 8, 0);
  }

  else if (node.kind === 51) {
    this.emitBinary(node, parentPrecedence, " && ", 3, 0);
  }

  else if (node.kind === 52) {
    this.emitBinary(node, parentPrecedence, " || ", 2, 0);
  }

  else if (node.kind === 54) {
    this.emitBinary(node, parentPrecedence, " !== ", 7, 0);
  }

  else if (node.kind === 55) {
    this.emitBinary(node, parentPrecedence, " % ", 11, 1);
  }

  else if (node.kind === 56) {
    this.emitBinary(node, parentPrecedence, " << ", 9, 0);
  }

  else if (node.kind === 57) {
    this.emitBinary(node, parentPrecedence, node.isUnsignedOperator() ? " >>> " : " >> ", 9, 0);
  }

  else if (node.kind === 58) {
    this.emitBinary(node, parentPrecedence, " - ", 10, 1);
  }

  else if (node.kind === 53) {
    var left = node.binaryLeft();
    var right = node.binaryRight();
    var isUnsigned = node.isUnsignedOperator();

    if (isUnsigned && parentPrecedence > 9) {
      this.emitText("(");
    }

    this.emitText("__imul(");
    this.emitExpression(left, 0);
    this.emitText(", ");
    this.emitExpression(right, 0);
    this.emitText(")");
    this.foundMultiply = true;

    if (isUnsigned) {
      this.emitText(" >>> 0");

      if (parentPrecedence > 9) {
        this.emitText(")");
      }
    }
  }

  else {
    globals.assert(false);
  }
};

JsResult.prototype.emitSymbolAccess = function(symbol) {
  var c = globals.string_get(symbol.name, 0);

  if (isAlpha(c)) {
    this.emitText(".");
    this.emitText(symbol.name);
  }

  else {
    this.emitText("[");
    this.emitString(globals.String_quote(globals.String_new(symbol.name)));
    this.emitText("]");
  }
};

JsResult.prototype.emitStatement = function(node) {
  if (node.kind === 10) {
    var body = node.functionBody();

    if (body === null) {
      return;
    }

    var symbol = node.symbol;
    var needsSemicolon = false;
    this.emitNewlineBefore(node);
    this.emitIndent();

    if (symbol.kind === 4) {
      this.emitText(symbol.parent().name);
      this.emitText(".prototype");
      this.emitSymbolAccess(symbol);
      this.emitText(" = function");
      needsSemicolon = true;
    }

    else if (node.isExtern()) {
      this.emitText("var ");
      this.emitText(symbol.name);
      this.emitText(" = exports.");
      this.emitText(symbol.name);
      this.emitText(" = function");
      needsSemicolon = true;
    }

    else {
      this.emitText("function ");
      this.emitText(symbol.name);
    }

    this.emitText("(");
    var returnType = node.functionReturnType();
    var child = node.functionFirstArgumentIgnoringThis();

    while (child !== returnType) {
      globals.assert(child.kind === 1);
      this.emitText(child.symbol.name);
      child = child.nextSibling;

      if (child !== returnType) {
        this.emitText(", ");
      }
    }

    this.emitText(") ");
    this.emitBlock(node.functionBody());
    this.emitText(needsSemicolon ? ";\n" : "\n");
    this.emitNewlineAfter(node);
  }

  else if (node.kind === 11) {
    this.emitNewlineBefore(node);
    this.emitIndent();

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

      this.emitText("\n\n");
      this.emitIndent();
      this.emitText("else ");

      if (no.firstChild === null || no.firstChild !== no.lastChild || no.firstChild.kind !== 11) {
        this.emitBlock(no);
        this.emitText("\n");

        break;
      }

      node = no.firstChild;
    }

    this.emitNewlineAfter(node);
  }

  else if (node.kind === 15) {
    this.emitNewlineBefore(node);
    this.emitIndent();
    this.emitText("while (");
    this.emitExpression(node.whileValue(), 0);
    this.emitText(") ");
    this.emitBlock(node.whileBody());
    this.emitText("\n");
    this.emitNewlineAfter(node);
  }

  else if (node.kind === 3) {
    this.emitNewlineBefore(node);
    this.emitIndent();
    this.emitText("break;\n");
    this.emitNewlineAfter(node);
  }

  else if (node.kind === 6) {
    this.emitNewlineBefore(node);
    this.emitIndent();
    this.emitText("continue;\n");
    this.emitNewlineAfter(node);
  }

  else if (node.kind === 9) {
    this.emitNewlineBefore(node);
    this.emitIndent();
    this.emitExpression(node.expressionValue(), 0);
    this.emitText(";\n");
    this.emitNewlineAfter(node);
  }

  else if (node.kind === 7) {
  }

  else if (node.kind === 12) {
    var value = node.returnValue();
    this.emitNewlineBefore(node);
    this.emitIndent();

    if (value !== null) {
      this.emitText("return ");
      this.emitExpression(value, 0);
      this.emitText(";\n");
    }

    else {
      this.emitText("return;\n");
    }

    this.emitNewlineAfter(node);
  }

  else if (node.kind === 2) {
    if (node.parent.kind === 2) {
      this.emitStatements(node.firstChild);
    }

    else {
      this.emitNewlineBefore(node);
      this.emitIndent();
      this.emitBlock(node);
      this.emitText("\n");
      this.emitNewlineAfter(node);
    }
  }

  else if (node.kind === 14) {
    this.emitNewlineBefore(node);
    this.emitIndent();
    this.emitText("var ");
    var child = node.firstChild;

    while (child !== null) {
      var value = child.variableValue();
      this.emitText(child.symbol.name);
      child = child.nextSibling;

      if (child !== null) {
        this.emitText(", ");
      }

      globals.assert(value !== null);
      this.emitText(" = ");
      this.emitExpression(value, 0);
    }

    this.emitText(";\n");
    this.emitNewlineAfter(node);
  }

  else if (node.kind === 4) {
    if (node.isDeclare()) {
      return;
    }

    this.emitNewlineBefore(node);
    this.emitIndent();
    this.emitText("function ");
    this.emitText(node.symbol.name);
    this.emitText("() {\n");
    this.indent = this.indent + 1 | 0;
    var child = node.firstChild;

    while (child !== null) {
      if (child.kind === 1) {
        this.emitIndent();
        this.emitText("this.");
        this.emitText(child.symbol.name);
        this.emitText(" = ");
        this.emitExpression(child.variableValue(), 0);
        this.emitText(";\n");
      }

      child = child.nextSibling;
    }

    this.indent = this.indent - 1 | 0;
    this.emitIndent();
    this.emitText("}\n");
    this.emitNewlineAfter(node);
    child = node.firstChild;

    while (child !== null) {
      if (child.kind === 10) {
        this.emitStatement(child);
      }

      child = child.nextSibling;
    }
  }

  else if (node.kind === 5 || node.kind === 8) {
  }

  else {
    globals.assert(false);
  }
};

function jsIsCompactNodeKind(kind) {
  return kind === 5 || kind === 9 || kind === 14;
}

function jsEmit(global, context) {
  var result = new JsResult();
  result.context = context;
  result.code = globals.String_new("");
  result.emitStatements(global.firstChild);

  if (result.foundMultiply) {
    result.emitText("\nvar __imul = Math.imul || function(a, b) {\n");
    result.emitText("  return (a * (b >>> 16) << 16) + a * (b & 65535) | 0;\n");
    result.emitText("};\n");
  }

  return result.code;
}

function isKeyword(kind) {
  return kind >= 39 && kind <= 71;
}

function Token() {
  this.kind = 0;
  this.range = null;
  this.next = null;
}

function tokenToString(token) {
  if (token === 0) {
    return "end of file";
  }

  if (token === 1) {
    return "character literal";
  }

  if (token === 2) {
    return "identifier";
  }

  if (token === 3) {
    return "integer literal";
  }

  if (token === 4) {
    return "string literal";
  }

  if (token === 5) {
    return "'='";
  }

  if (token === 6) {
    return "'&'";
  }

  if (token === 7) {
    return "'|'";
  }

  if (token === 8) {
    return "'^'";
  }

  if (token === 9) {
    return "':'";
  }

  if (token === 10) {
    return "','";
  }

  if (token === 11) {
    return "'~'";
  }

  if (token === 12) {
    return "'/'";
  }

  if (token === 13) {
    return "'.'";
  }

  if (token === 14) {
    return "'=='";
  }

  if (token === 15) {
    return "'>'";
  }

  if (token === 16) {
    return "'>='";
  }

  if (token === 17) {
    return "'{'";
  }

  if (token === 18) {
    return "'['";
  }

  if (token === 19) {
    return "'('";
  }

  if (token === 20) {
    return "'<'";
  }

  if (token === 21) {
    return "'<='";
  }

  if (token === 22) {
    return "'&&'";
  }

  if (token === 23) {
    return "'||'";
  }

  if (token === 24) {
    return "'-'";
  }

  if (token === 25) {
    return "'--'";
  }

  if (token === 26) {
    return "'*'";
  }

  if (token === 27) {
    return "'!'";
  }

  if (token === 28) {
    return "'!='";
  }

  if (token === 29) {
    return "'+'";
  }

  if (token === 30) {
    return "'++'";
  }

  if (token === 31) {
    return "'?'";
  }

  if (token === 32) {
    return "'%'";
  }

  if (token === 33) {
    return "'}'";
  }

  if (token === 34) {
    return "']'";
  }

  if (token === 35) {
    return "')'";
  }

  if (token === 36) {
    return "';'";
  }

  if (token === 37) {
    return "'<<'";
  }

  if (token === 38) {
    return "'>>'";
  }

  if (token === 39) {
    return "'alignof'";
  }

  if (token === 40) {
    return "'as'";
  }

  if (token === 41) {
    return "'break'";
  }

  if (token === 42) {
    return "'class'";
  }

  if (token === 43) {
    return "'const'";
  }

  if (token === 44) {
    return "'continue'";
  }

  if (token === 45) {
    return "'declare'";
  }

  if (token === 46) {
    return "'else'";
  }

  if (token === 47) {
    return "'enum'";
  }

  if (token === 48) {
    return "'export'";
  }

  if (token === 49) {
    return "'extends'";
  }

  if (token === 50) {
    return "'extern'";
  }

  if (token === 51) {
    return "'false'";
  }

  if (token === 52) {
    return "'function'";
  }

  if (token === 53) {
    return "'if'";
  }

  if (token === 54) {
    return "'implements'";
  }

  if (token === 55) {
    return "'import'";
  }

  if (token === 56) {
    return "'interface'";
  }

  if (token === 57) {
    return "'let'";
  }

  if (token === 58) {
    return "'new'";
  }

  if (token === 59) {
    return "'null'";
  }

  if (token === 60) {
    return "'operator'";
  }

  if (token === 61) {
    return "'private'";
  }

  if (token === 62) {
    return "'protected'";
  }

  if (token === 63) {
    return "'public'";
  }

  if (token === 64) {
    return "'return'";
  }

  if (token === 65) {
    return "'sizeof'";
  }

  if (token === 66) {
    return "'static'";
  }

  if (token === 67) {
    return "'this'";
  }

  if (token === 68) {
    return "'true'";
  }

  if (token === 69) {
    return "'unsafe'";
  }

  if (token === 70) {
    return "'var'";
  }

  if (token === 71) {
    return "'while'";
  }

  globals.assert(false);

  return null;
}

function isAlpha(c) {
  return c >= 97 && c <= 122 || c >= 65 && c <= 90 || c === 95;
}

function isNumber(c) {
  return c >= 48 && c <= 57;
}

function isDigit(c, base) {
  if (base === 16) {
    return isNumber(c) || c >= 65 && c <= 70 || c >= 97 && c <= 102;
  }

  return c >= 48 && c < (base + 48 | 0);
}

function tokenize(source, log) {
  var first = null;
  var last = null;
  var contents = source.contents;
  var limit = globals.string_length(contents);
  var i = 0;

  while (i < limit) {
    var start = i;
    var c = globals.string_get(contents, i);
    i = i + 1 | 0;

    if (c === 32 || c === 9 || c === 13 || c === 10) {
      continue;
    }

    var kind = 0;

    if (isAlpha(c)) {
      kind = 2;

      while (i < limit && (isAlpha(globals.string_get(contents, i)) || isNumber(globals.string_get(contents, i)))) {
        i = i + 1 | 0;
      }

      var length = i - start | 0;

      if (length >= 2 && length <= 10) {
        var text = globals.string_slice(contents, start, i);

        if (length === 2) {
          if (globals.string_equals(text, "as")) {
            kind = 40;
          }

          else if (globals.string_equals(text, "if")) {
            kind = 53;
          }
        }

        else if (length === 3) {
          if (globals.string_equals(text, "let")) {
            kind = 57;
          }

          else if (globals.string_equals(text, "new")) {
            kind = 58;
          }

          else if (globals.string_equals(text, "var")) {
            kind = 70;
          }
        }

        else if (length === 4) {
          if (globals.string_equals(text, "else")) {
            kind = 46;
          }

          else if (globals.string_equals(text, "enum")) {
            kind = 47;
          }

          else if (globals.string_equals(text, "null")) {
            kind = 59;
          }

          else if (globals.string_equals(text, "this")) {
            kind = 67;
          }

          else if (globals.string_equals(text, "true")) {
            kind = 68;
          }
        }

        else if (length === 5) {
          if (globals.string_equals(text, "break")) {
            kind = 41;
          }

          else if (globals.string_equals(text, "class")) {
            kind = 42;
          }

          else if (globals.string_equals(text, "const")) {
            kind = 43;
          }

          else if (globals.string_equals(text, "false")) {
            kind = 51;
          }

          else if (globals.string_equals(text, "while")) {
            kind = 71;
          }
        }

        else if (length === 6) {
          if (globals.string_equals(text, "export")) {
            kind = 48;
          }

          else if (globals.string_equals(text, "extern")) {
            kind = 50;
          }

          else if (globals.string_equals(text, "import")) {
            kind = 55;
          }

          else if (globals.string_equals(text, "public")) {
            kind = 63;
          }

          else if (globals.string_equals(text, "return")) {
            kind = 64;
          }

          else if (globals.string_equals(text, "sizeof")) {
            kind = 65;
          }

          else if (globals.string_equals(text, "static")) {
            kind = 66;
          }

          else if (globals.string_equals(text, "unsafe")) {
            kind = 69;
          }
        }

        else if (length === 7) {
          if (globals.string_equals(text, "alignof")) {
            kind = 39;
          }

          else if (globals.string_equals(text, "declare")) {
            kind = 45;
          }

          else if (globals.string_equals(text, "extends")) {
            kind = 49;
          }

          else if (globals.string_equals(text, "private")) {
            kind = 61;
          }
        }

        else if (globals.string_equals(text, "continue")) {
          kind = 44;
        }

        else if (globals.string_equals(text, "function")) {
          kind = 52;
        }

        else if (globals.string_equals(text, "implements")) {
          kind = 54;
        }

        else if (globals.string_equals(text, "interface")) {
          kind = 56;
        }

        else if (globals.string_equals(text, "protected")) {
          kind = 62;
        }
      }
    }

    else if (isNumber(c)) {
      kind = 3;

      if (i < limit) {
        var next = globals.string_get(contents, i);
        var base = 10;

        if (c === 48 && (i + 1 | 0) < limit) {
          if (next === 98 || next === 66) {
            base = 2;
          }

          else if (next === 111 || next === 79) {
            base = 8;
          }

          else if (next === 120 || next === 88) {
            base = 16;
          }

          if (base !== 10) {
            if (isDigit(globals.string_get(contents, i + 1 | 0), base)) {
              i = i + 2 | 0;
            }

            else {
              base = 10;
            }
          }
        }

        while (i < limit && isDigit(globals.string_get(contents, i), base)) {
          i = i + 1 | 0;
        }

        if (i < limit && (isAlpha(globals.string_get(contents, i)) || isNumber(globals.string_get(contents, i)))) {
          i = i + 1 | 0;

          while (i < limit && (isAlpha(globals.string_get(contents, i)) || isNumber(globals.string_get(contents, i)))) {
            i = i + 1 | 0;
          }

          log.error(createRange(source, start, i), StringBuilder_new().append("Invalid integer literal: '").appendSlice(contents, start, i).appendChar(39).finish());

          return null;
        }
      }
    }

    else if (c === 34 || c === 39 || c === 96) {
      while (i < limit) {
        var next = globals.string_get(contents, i);

        if ((i + 1 | 0) < limit && next === 92) {
          i = i + 2 | 0;
        }

        else if (next === 10 && c !== 96) {
          break;
        }

        else {
          i = i + 1 | 0;

          if (next === c) {
            kind = c === 39 ? 1 : 4;

            break;
          }
        }
      }

      if (kind === 0) {
        log.error(createRange(source, start, i), c === 39 ? "Unterminated character literal" : c === 96 ? "Unterminated template literal" : "Unterminated string literal");

        return null;
      }
    }

    else if (c === 37) {
      kind = 32;
    }

    else if (c === 40) {
      kind = 19;
    }

    else if (c === 41) {
      kind = 35;
    }

    else if (c === 42) {
      kind = 26;
    }

    else if (c === 44) {
      kind = 10;
    }

    else if (c === 46) {
      kind = 13;
    }

    else if (c === 58) {
      kind = 9;
    }

    else if (c === 59) {
      kind = 36;
    }

    else if (c === 63) {
      kind = 31;
    }

    else if (c === 91) {
      kind = 18;
    }

    else if (c === 93) {
      kind = 34;
    }

    else if (c === 94) {
      kind = 8;
    }

    else if (c === 123) {
      kind = 17;
    }

    else if (c === 125) {
      kind = 33;
    }

    else if (c === 126) {
      kind = 11;
    }

    else if (c === 47) {
      kind = 12;

      if (i < limit && globals.string_get(contents, i) === 47) {
        i = i + 1 | 0;

        while (i < limit && globals.string_get(contents, i) !== 10) {
          i = i + 1 | 0;
        }

        continue;
      }

      if (i < limit && globals.string_get(contents, i) === 42) {
        i = i + 1 | 0;
        var foundEnd = false;

        while (i < limit) {
          var next = globals.string_get(contents, i);

          if (next === 42 && (i + 1 | 0) < limit && globals.string_get(contents, i + 1 | 0) === 47) {
            foundEnd = true;
            i = i + 2 | 0;

            break;
          }

          i = i + 1 | 0;
        }

        if (!foundEnd) {
          log.error(createRange(source, start, start + 2 | 0), "Unterminated multi-line comment");

          return null;
        }

        continue;
      }
    }

    else if (c === 33) {
      kind = 27;

      if (i < limit && globals.string_get(contents, i) === 61) {
        kind = 28;
        i = i + 1 | 0;

        if (i < limit && globals.string_get(contents, i) === 61) {
          i = i + 1 | 0;
          log.error(createRange(source, start, i), "Use '!=' instead of '!=='");
        }
      }
    }

    else if (c === 61) {
      kind = 5;

      if (i < limit && globals.string_get(contents, i) === 61) {
        kind = 14;
        i = i + 1 | 0;

        if (i < limit && globals.string_get(contents, i) === 61) {
          i = i + 1 | 0;
          log.error(createRange(source, start, i), "Use '==' instead of '==='");
        }
      }
    }

    else if (c === 43) {
      kind = 29;

      if (i < limit && globals.string_get(contents, i) === 43) {
        kind = 30;
        i = i + 1 | 0;
      }
    }

    else if (c === 45) {
      kind = 24;

      if (i < limit && globals.string_get(contents, i) === 45) {
        kind = 25;
        i = i + 1 | 0;
      }
    }

    else if (c === 38) {
      kind = 6;

      if (i < limit && globals.string_get(contents, i) === 38) {
        kind = 22;
        i = i + 1 | 0;
      }
    }

    else if (c === 124) {
      kind = 7;

      if (i < limit && globals.string_get(contents, i) === 124) {
        kind = 23;
        i = i + 1 | 0;
      }
    }

    else if (c === 60) {
      kind = 20;

      if (i < limit) {
        c = globals.string_get(contents, i);

        if (c === 60) {
          kind = 37;
          i = i + 1 | 0;
        }

        else if (c === 61) {
          kind = 21;
          i = i + 1 | 0;
        }
      }
    }

    else if (c === 62) {
      kind = 15;

      if (i < limit) {
        c = globals.string_get(contents, i);

        if (c === 62) {
          kind = 38;
          i = i + 1 | 0;
        }

        else if (c === 61) {
          kind = 16;
          i = i + 1 | 0;
        }
      }
    }

    var range = createRange(source, start, i);

    if (kind === 0) {
      log.error(range, StringBuilder_new().append("Syntax error: '").appendSlice(contents, start, start + 1 | 0).appendChar(39).finish());

      return null;
    }

    var token = new Token();
    token.kind = kind;
    token.range = range;

    if (first === null) {
      first = token;
    }

    else {
      last.next = token;
    }

    last = token;
  }

  var eof = new Token();
  eof.kind = 0;
  eof.range = createRange(source, limit, limit);

  if (first === null) {
    first = eof;
  }

  else {
    last.next = eof;
  }

  last = eof;

  return first;
}

function libraryForWebAssembly() {
  return "\n// Cast to these to read from and write to arbitrary locations in memory\nunsafe class UBytePtr { value: ubyte; }\nunsafe class UShortPtr { value: ushort; }\nunsafe class UIntPtr { value: uint; }\n\n// These will be filled in by the WebAssembly code generator\nunsafe var currentHeapPointer: uint = 0;\nunsafe var originalHeapPointer: uint = 0;\n\nunsafe function malloc(sizeOf: uint): uint {\n  // Align all allocations to 8 bytes\n  var offset = (currentHeapPointer + 7) & ~7 as uint;\n  sizeOf = (sizeOf + 7) & ~7 as uint;\n\n  // Use a simple bump allocator for now\n  var limit = offset + sizeOf;\n  currentHeapPointer = limit;\n\n  // Make sure the memory starts off at zero\n  var ptr = offset;\n  while (ptr < limit) {\n    (ptr as UIntPtr).value = 0;\n    ptr = ptr + 4;\n  }\n\n  return offset;\n}\n";
}

function Source() {
  this.name = null;
  this.contents = null;
  this.next = null;
  this.firstToken = null;
}

function Range() {
  this.source = null;
  this.start = 0;
  this.end = 0;
}

Range.prototype.toString = function() {
  return globals.string_slice(this.source.contents, this.start, this.end);
};

Range.prototype.equals = function(other) {
  return this.source === other.source && this.start === other.start && this.end === other.end;
};

Range.prototype.enclosingLine = function() {
  var contents = this.source.contents;
  var start = this.start;
  var end = this.start;

  while (start > 0 && globals.string_get(contents, start - 1 | 0) !== 10) {
    start = start - 1 | 0;
  }

  var length = globals.string_length(contents);

  while ((end + 1 | 0) < length && globals.string_get(contents, end) !== 10) {
    end = end + 1 | 0;
  }

  return createRange(this.source, start, end);
};

function createRange(source, start, end) {
  globals.assert(start <= end);
  var range = new Range();
  range.source = source;
  range.start = start;
  range.end = end;

  return range;
}

function spanRanges(left, right) {
  globals.assert(left.source === right.source);
  globals.assert(left.end <= right.start);

  return createRange(left.source, left.start, right.end);
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

Log.prototype.error = function(range, message) {
  var diagnostic = new Diagnostic();
  diagnostic.range = range;
  diagnostic.message = message;
  this.append(diagnostic);
};

Log.prototype.append = function(diagnostic) {
  if (this.first === null) {
    this.first = diagnostic;
  }

  else {
    this.last.next = diagnostic;
  }

  this.last = diagnostic;
};

Log.prototype.toString = function() {
  var result = StringBuilder_new();
  var d = this.first;

  while (d !== null) {
    var lineRange = d.range.enclosingLine();
    var column = d.range.start - lineRange.start | 0;
    var line = 0;
    var i = 0;

    while (i < lineRange.start) {
      if (globals.string_get(lineRange.source.contents, i) === 10) {
        line = line + 1 | 0;
      }

      i = i + 1 | 0;
    }

    result.append(d.range.source.name).appendChar(58).append(globals.string_intToString(line + 1 | 0)).appendChar(58).append(globals.string_intToString(column + 1 | 0)).append(": error: ").append(d.message).appendChar(10).append(lineRange.toString()).appendChar(10);
    i = 0;

    while (i < column) {
      result.appendChar(32);
      i = i + 1 | 0;
    }

    if ((d.range.end - d.range.start | 0) <= 1) {
      result.appendChar(94);
    }

    else {
      i = d.range.start;

      while (i < d.range.end && i < lineRange.end) {
        result.appendChar(126);
        i = i + 1 | 0;
      }
    }

    result.appendChar(10);
    d = d.next;
  }

  return result.finish();
};

function isUnary(kind) {
  return kind >= 32 && kind <= 39;
}

function isUnaryPostfix(kind) {
  return kind >= 36 && kind <= 37;
}

function isBinary(kind) {
  return kind >= 40 && kind <= 58;
}

function isExpression(node) {
  return node.kind >= 16 && node.kind <= 58;
}

function NodeFlag() {
  this.flag = 0;
  this.range = null;
  this.next = null;
}

function appendFlag(first, flag, range) {
  var link = new NodeFlag();
  link.flag = flag;
  link.range = range;

  if (first === null) {
    return link;
  }

  var secondToLast = first;

  while (secondToLast.next !== null) {
    secondToLast = secondToLast.next;
  }

  secondToLast.next = link;

  return first;
}

function allFlags(link) {
  var all = 0;

  while (link !== null) {
    all = all | link.flag;
    link = link.next;
  }

  return all;
}

function rangeForFlag(link, flag) {
  while (link !== null) {
    if (link.flag === flag) {
      return link.range;
    }

    link = link.next;
  }

  return null;
}

function Node() {
  this.kind = 0;
  this.flags = 0;
  this.firstFlag = null;
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

Node.prototype.isNegativeInteger = function() {
  return this.kind === 23 && this.intValue < 0;
};

Node.prototype.isNonNegativeInteger = function() {
  return this.kind === 23 && this.intValue >= 0;
};

Node.prototype.isDeclare = function() {
  return (this.flags & 1) !== 0;
};

Node.prototype.isExtern = function() {
  return (this.flags & 4) !== 0;
};

Node.prototype.isUnsafe = function() {
  return (this.flags & 512) !== 0;
};

Node.prototype.isUnsignedOperator = function() {
  return (this.flags & 1024) !== 0;
};

Node.prototype.childCount = function() {
  var count = 0;
  var child = this.firstChild;

  while (child !== null) {
    count = count + 1 | 0;
    child = child.nextSibling;
  }

  return count;
};

Node.prototype.appendChild = function(child) {
  child.parent = this;

  if (this.firstChild === null) {
    this.firstChild = child;
  }

  else {
    child.previousSibling = this.lastChild;
    this.lastChild.nextSibling = child;
  }

  this.lastChild = child;
};

Node.prototype.prependChild = function(child) {
  this.insertChildBefore(this.firstChild, child);
};

Node.prototype.insertChildBefore = function(after, before) {
  if (before === null) {
    return;
  }

  globals.assert(before !== after);
  globals.assert(before.parent === null);
  globals.assert(before.previousSibling === null);
  globals.assert(before.nextSibling === null);
  globals.assert(after === null || after.parent === this);

  if (after === null) {
    this.appendChild(before);

    return;
  }

  before.parent = this;
  before.previousSibling = after.previousSibling;
  before.nextSibling = after;

  if (after.previousSibling !== null) {
    globals.assert(after === after.previousSibling.nextSibling);
    after.previousSibling.nextSibling = before;
  }

  else {
    globals.assert(after === this.firstChild);
    this.firstChild = before;
  }

  after.previousSibling = before;
};

Node.prototype.remove = function() {
  globals.assert(this.parent !== null);

  if (this.previousSibling !== null) {
    globals.assert(this.previousSibling.nextSibling === this);
    this.previousSibling.nextSibling = this.nextSibling;
  }

  else {
    globals.assert(this.parent.firstChild === this);
    this.parent.firstChild = this.nextSibling;
  }

  if (this.nextSibling !== null) {
    globals.assert(this.nextSibling.previousSibling === this);
    this.nextSibling.previousSibling = this.previousSibling;
  }

  else {
    globals.assert(this.parent.lastChild === this);
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

Node.prototype.replaceWith = function(node) {
  globals.assert(node !== this);
  globals.assert(this.parent !== null);
  globals.assert(node.parent === null);
  globals.assert(node.previousSibling === null);
  globals.assert(node.nextSibling === null);
  node.parent = this.parent;
  node.previousSibling = this.previousSibling;
  node.nextSibling = this.nextSibling;

  if (this.previousSibling !== null) {
    globals.assert(this.previousSibling.nextSibling === this);
    this.previousSibling.nextSibling = node;
  }

  else {
    globals.assert(this.parent.firstChild === this);
    this.parent.firstChild = node;
  }

  if (this.nextSibling !== null) {
    globals.assert(this.nextSibling.previousSibling === this);
    this.nextSibling.previousSibling = node;
  }

  else {
    globals.assert(this.parent.lastChild === this);
    this.parent.lastChild = node;
  }

  this.parent = null;
  this.previousSibling = null;
  this.nextSibling = null;
};

Node.prototype.becomeSymbolReference = function(symbol) {
  this.kind = 24;
  this.symbol = symbol;
  this.stringValue = symbol.name;
  this.resolvedType = symbol.resolvedType;
  this.removeChildren();
};

Node.prototype.becomeIntegerConstant = function(value) {
  this.kind = 23;
  this.symbol = null;
  this.intValue = value;
  this.removeChildren();
};

Node.prototype.becomeBooleanConstant = function(value) {
  this.kind = 17;
  this.symbol = null;
  this.intValue = value ? 1 : 0;
  this.removeChildren();
};

Node.prototype.isType = function() {
  return this.kind === 31 || this.symbol !== null && isType(this.symbol.kind);
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
  globals.assert(this.kind === 10);
  globals.assert(this.childCount() >= 2);
  globals.assert(this.symbol !== null);

  return this.symbol.kind === 4 ? this.firstChild.nextSibling : this.firstChild;
};

Node.prototype.functionReturnType = function() {
  globals.assert(this.kind === 10);
  globals.assert(this.childCount() >= 2);
  globals.assert(isExpression(this.lastChild.previousSibling));

  return this.lastChild.previousSibling;
};

Node.prototype.functionBody = function() {
  globals.assert(this.kind === 10);
  globals.assert(this.childCount() >= 2);
  globals.assert(this.lastChild.kind === 2 || this.lastChild.kind === 7);
  var body = this.lastChild;

  return body.kind === 2 ? body : null;
};

Node.prototype.newType = function() {
  globals.assert(this.kind === 25);
  globals.assert(this.childCount() >= 1);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.callValue = function() {
  globals.assert(this.kind === 18);
  globals.assert(this.childCount() >= 1);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.castValue = function() {
  globals.assert(this.kind === 19);
  globals.assert(this.childCount() === 2);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.castType = function() {
  globals.assert(this.kind === 19);
  globals.assert(this.childCount() === 2);
  globals.assert(isExpression(this.lastChild));

  return this.lastChild;
};

Node.prototype.alignOfType = function() {
  globals.assert(this.kind === 16);
  globals.assert(this.childCount() === 1);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.sizeOfType = function() {
  globals.assert(this.kind === 28);
  globals.assert(this.childCount() === 1);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.dotTarget = function() {
  globals.assert(this.kind === 20);
  globals.assert(this.childCount() === 1);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.returnValue = function() {
  globals.assert(this.kind === 12);
  globals.assert(this.childCount() <= 1);
  globals.assert(this.firstChild === null || isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.variableType = function() {
  globals.assert(this.kind === 1);
  globals.assert(this.childCount() <= 2);
  globals.assert(isExpression(this.firstChild) || this.firstChild.kind === 7);
  var type = this.firstChild;

  return type.kind !== 7 ? type : null;
};

Node.prototype.variableValue = function() {
  globals.assert(this.kind === 1);
  globals.assert(this.childCount() <= 2);
  globals.assert(this.firstChild.nextSibling === null || isExpression(this.firstChild.nextSibling));

  return this.firstChild.nextSibling;
};

Node.prototype.expressionValue = function() {
  globals.assert(this.kind === 9);
  globals.assert(this.childCount() === 1);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.binaryLeft = function() {
  globals.assert(isBinary(this.kind));
  globals.assert(this.childCount() === 2);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.binaryRight = function() {
  globals.assert(isBinary(this.kind));
  globals.assert(this.childCount() === 2);
  globals.assert(isExpression(this.lastChild));

  return this.lastChild;
};

Node.prototype.unaryValue = function() {
  globals.assert(isUnary(this.kind));
  globals.assert(this.childCount() === 1);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.whileValue = function() {
  globals.assert(this.kind === 15);
  globals.assert(this.childCount() === 2);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.whileBody = function() {
  globals.assert(this.kind === 15);
  globals.assert(this.childCount() === 2);
  globals.assert(this.lastChild.kind === 2);

  return this.lastChild;
};

Node.prototype.hookValue = function() {
  globals.assert(this.kind === 21);
  globals.assert(this.childCount() === 3);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.hookTrue = function() {
  globals.assert(this.kind === 21);
  globals.assert(this.childCount() === 3);
  globals.assert(isExpression(this.firstChild.nextSibling));

  return this.firstChild.nextSibling;
};

Node.prototype.hookFalse = function() {
  globals.assert(this.kind === 21);
  globals.assert(this.childCount() === 3);
  globals.assert(isExpression(this.lastChild));

  return this.lastChild;
};

Node.prototype.indexTarget = function() {
  globals.assert(this.kind === 22);
  globals.assert(this.childCount() >= 1);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.ifValue = function() {
  globals.assert(this.kind === 11);
  globals.assert(this.childCount() === 2 || this.childCount() === 3);
  globals.assert(isExpression(this.firstChild));

  return this.firstChild;
};

Node.prototype.ifTrue = function() {
  globals.assert(this.kind === 11);
  globals.assert(this.childCount() === 2 || this.childCount() === 3);
  globals.assert(this.firstChild.nextSibling.kind === 2);

  return this.firstChild.nextSibling;
};

Node.prototype.ifFalse = function() {
  globals.assert(this.kind === 11);
  globals.assert(this.childCount() === 2 || this.childCount() === 3);
  globals.assert(this.firstChild.nextSibling.nextSibling === null || this.firstChild.nextSibling.nextSibling.kind === 2);

  return this.firstChild.nextSibling.nextSibling;
};

function createNew(type) {
  globals.assert(isExpression(type));
  var node = new Node();
  node.kind = 25;
  node.appendChild(type);

  return node;
}

function createHook(test, primary, secondary) {
  globals.assert(isExpression(test));
  globals.assert(isExpression(primary));
  globals.assert(isExpression(secondary));
  var node = new Node();
  node.kind = 21;
  node.appendChild(test);
  node.appendChild(primary);
  node.appendChild(secondary);

  return node;
}

function createIndex(target) {
  globals.assert(isExpression(target));
  var node = new Node();
  node.kind = 22;
  node.appendChild(target);

  return node;
}

function createNull() {
  var node = new Node();
  node.kind = 26;

  return node;
}

function createThis() {
  var node = new Node();
  node.kind = 30;

  return node;
}

function createAlignOf(type) {
  globals.assert(isExpression(type));
  var node = new Node();
  node.kind = 16;
  node.appendChild(type);

  return node;
}

function createSizeOf(type) {
  globals.assert(isExpression(type));
  var node = new Node();
  node.kind = 28;
  node.appendChild(type);

  return node;
}

function createBool(value) {
  var node = new Node();
  node.kind = 17;
  node.intValue = value ? 1 : 0;

  return node;
}

function createInt(value) {
  var node = new Node();
  node.kind = 23;
  node.intValue = value;

  return node;
}

function createString(value) {
  var node = new Node();
  node.kind = 29;
  node.stringValue = value;

  return node;
}

function createName(value) {
  var node = new Node();
  node.kind = 24;
  node.stringValue = value;

  return node;
}

function createType(type) {
  globals.assert(type !== null);
  var node = new Node();
  node.kind = 31;
  node.resolvedType = type;

  return node;
}

function createEmpty() {
  var node = new Node();
  node.kind = 7;

  return node;
}

function createExpression(value) {
  globals.assert(isExpression(value));
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
  globals.assert(isExpression(value));
  globals.assert(trueBranch.kind === 2);
  globals.assert(falseBranch === null || falseBranch.kind === 2);
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
  globals.assert(isExpression(value));
  globals.assert(body.kind === 2);
  var node = new Node();
  node.kind = 15;
  node.appendChild(value);
  node.appendChild(body);

  return node;
}

function createReturn(value) {
  globals.assert(value === null || isExpression(value));
  var node = new Node();
  node.kind = 12;

  if (value !== null) {
    node.appendChild(value);
  }

  return node;
}

function createVariables() {
  var node = new Node();
  node.kind = 14;

  return node;
}

function createConstants() {
  var node = new Node();
  node.kind = 5;

  return node;
}

function createVariable(name, type, value) {
  globals.assert(type === null || isExpression(type));
  globals.assert(value === null || isExpression(value));
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
  globals.assert(isUnary(kind));
  globals.assert(isExpression(value));
  var node = new Node();
  node.kind = kind;
  node.appendChild(value);

  return node;
}

function createBinary(kind, left, right) {
  globals.assert(isBinary(kind));
  globals.assert(isExpression(left));
  globals.assert(isExpression(right));
  var node = new Node();
  node.kind = kind;
  node.appendChild(left);
  node.appendChild(right);

  return node;
}

function createCall(value) {
  globals.assert(isExpression(value));
  var node = new Node();
  node.kind = 18;
  node.appendChild(value);

  return node;
}

function createCast(value, type) {
  globals.assert(isExpression(value));
  globals.assert(isExpression(type));
  var node = new Node();
  node.kind = 19;
  node.appendChild(value);
  node.appendChild(type);

  return node;
}

function createDot(value, name) {
  globals.assert(isExpression(value));
  var node = new Node();
  node.kind = 20;
  node.stringValue = name;
  node.appendChild(value);

  return node;
}

function createMemberReference(value, symbol) {
  globals.assert(isExpression(value));
  var node = new Node();
  node.kind = 20;
  node.stringValue = symbol.name;
  node.symbol = symbol;
  node.resolvedType = symbol.resolvedType;
  node.appendChild(value);

  return node;
}

function createParseError() {
  var node = new Node();
  node.kind = 27;

  return node;
}

function ParserContext() {
  this.previous = null;
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
    this.previous = this.current;
    this.current = this.current.next;
  }
};

ParserContext.prototype.unexpectedToken = function() {
  this.log.error(this.current.range, StringBuilder_new().append("Unexpected ").append(tokenToString(this.current.kind)).finish());
};

ParserContext.prototype.expect = function(kind) {
  if (!this.peek(kind)) {
    var previousLine = this.previous.range.enclosingLine();
    var currentLine = this.current.range.enclosingLine();

    if (kind !== 2 && !previousLine.equals(currentLine)) {
      this.log.error(createRange(previousLine.source, previousLine.end, previousLine.end), StringBuilder_new().append("Expected ").append(tokenToString(kind)).finish());
    }

    else {
      this.log.error(this.current.range, StringBuilder_new().append("Expected ").append(tokenToString(kind)).append(" but found ").append(tokenToString(this.current.kind)).finish());
    }

    return false;
  }

  this.advance();

  return true;
};

ParserContext.prototype.parseUnaryPrefix = function(kind) {
  globals.assert(isUnary(kind));
  var token = this.current;
  this.advance();
  var value = this.parseExpression(12, 0);

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
  var precedence = operatorPrecedence === 1 ? 0 : operatorPrecedence;
  var right = this.parseExpression(precedence, 0);

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
  globals.assert((range.end - range.start | 0) >= 2);
  var text = range.source.contents;
  var end = range.start + 1 | 0;
  var limit = range.end - 1 | 0;
  var start = end;
  var builder = StringBuilder_new();

  while (end < limit) {
    var c = globals.string_get(text, end);

    if (c === 92) {
      builder.appendSlice(text, start, end);
      end = end + 1 | 0;
      start = end + 1 | 0;
      c = globals.string_get(text, end);

      if (c === 48) {
        builder.appendChar(0);
      }

      else if (c === 116) {
        builder.appendChar(9);
      }

      else if (c === 110) {
        builder.appendChar(10);
      }

      else if (c === 114) {
        builder.appendChar(13);
      }

      else if (c === 34 || c === 39 || c === 96 || c === 10 || c === 92) {
        start = end;
      }

      else {
        var escape = createRange(range.source, (range.start + end | 0) - 1 | 0, (range.start + end | 0) + 1 | 0);
        this.log.error(escape, StringBuilder_new().append("Invalid escape code '").append(escape.toString()).appendChar(39).finish());

        return null;
      }
    }

    end = end + 1 | 0;
  }

  return builder.appendSlice(text, start, end).finish();
};

ParserContext.prototype.parsePrefix = function(mode) {
  var token = this.current;

  if (this.peek(2)) {
    this.advance();

    return createName(token.range.toString()).withRange(token.range);
  }

  if (mode === 0) {
    if (this.eat(59)) {
      return createNull().withRange(token.range);
    }

    if (this.eat(67)) {
      return createThis().withRange(token.range);
    }

    if (this.peek(1)) {
      var text = this.parseQuotedString(token.range);

      if (text === null) {
        return null;
      }

      this.advance();

      if (globals.string_length(text) !== 1) {
        this.log.error(token.range, "Invalid character literal (strings use double quotes)");

        return createParseError().withRange(token.range);
      }

      return createInt(globals.string_get(text, 0)).withRange(token.range);
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
      var value = createInt(0);

      if (!this.parseInt(token.range, value)) {
        value = createParseError();
      }

      this.advance();

      return value.withRange(token.range);
    }

    if (this.eat(68)) {
      return createBool(true).withRange(token.range);
    }

    if (this.eat(51)) {
      return createBool(false).withRange(token.range);
    }

    if (this.eat(58)) {
      var type = this.parseType();

      if (type === null) {
        return null;
      }

      return this.parseArgumentList(token.range, createNew(type));
    }

    if (this.eat(39)) {
      if (!this.expect(19)) {
        return null;
      }

      var type = this.parseType();

      if (type === null) {
        return null;
      }

      var close = this.current;

      if (!this.expect(35)) {
        return null;
      }

      return createAlignOf(type).withRange(spanRanges(token.range, close.range));
    }

    if (this.eat(65)) {
      if (!this.expect(19)) {
        return null;
      }

      var type = this.parseType();

      if (type === null) {
        return null;
      }

      var close = this.current;

      if (!this.expect(35)) {
        return null;
      }

      return createSizeOf(type).withRange(spanRanges(token.range, close.range));
    }

    if (this.eat(19)) {
      var value = this.parseExpression(0, 0);

      if (value === null || !this.expect(35)) {
        return null;
      }

      return value;
    }

    if (this.peek(27)) {
      return this.parseUnaryPrefix(34);
    }

    if (this.peek(24)) {
      return this.parseUnaryPrefix(33);
    }

    if (this.peek(25)) {
      return this.parseUnaryPrefix(38);
    }

    if (this.peek(29)) {
      return this.parseUnaryPrefix(35);
    }

    if (this.peek(30)) {
      return this.parseUnaryPrefix(39);
    }

    if (this.peek(11)) {
      return this.parseUnaryPrefix(32);
    }
  }

  this.unexpectedToken();

  return null;
};

ParserContext.prototype.parseInfix = function(precedence, node, mode) {
  var token = this.current.range;

  if (this.peek(13) && precedence < 14) {
    this.advance();
    var name = this.current;
    var range = name.range;

    if (isKeyword(name.kind)) {
      this.advance();
    }

    else if (!this.expect(2)) {
      range = createRange(range.source, token.end, token.end);
    }

    return createDot(node, range.toString()).withRange(spanRanges(node.range, range)).withInternalRange(range);
  }

  if (mode === 0) {
    if (this.peek(5)) {
      return this.parseBinary(41, node, precedence, 1);
    }

    if (this.peek(6)) {
      return this.parseBinary(42, node, precedence, 6);
    }

    if (this.peek(7)) {
      return this.parseBinary(43, node, precedence, 4);
    }

    if (this.peek(8)) {
      return this.parseBinary(44, node, precedence, 5);
    }

    if (this.peek(12)) {
      return this.parseBinary(45, node, precedence, 11);
    }

    if (this.peek(14)) {
      return this.parseBinary(46, node, precedence, 7);
    }

    if (this.peek(15)) {
      return this.parseBinary(47, node, precedence, 8);
    }

    if (this.peek(16)) {
      return this.parseBinary(48, node, precedence, 8);
    }

    if (this.peek(20)) {
      return this.parseBinary(49, node, precedence, 8);
    }

    if (this.peek(21)) {
      return this.parseBinary(50, node, precedence, 8);
    }

    if (this.peek(22)) {
      return this.parseBinary(51, node, precedence, 3);
    }

    if (this.peek(23)) {
      return this.parseBinary(52, node, precedence, 2);
    }

    if (this.peek(24)) {
      return this.parseBinary(58, node, precedence, 10);
    }

    if (this.peek(26)) {
      return this.parseBinary(53, node, precedence, 11);
    }

    if (this.peek(28)) {
      return this.parseBinary(54, node, precedence, 7);
    }

    if (this.peek(29)) {
      return this.parseBinary(40, node, precedence, 10);
    }

    if (this.peek(32)) {
      return this.parseBinary(55, node, precedence, 11);
    }

    if (this.peek(37)) {
      return this.parseBinary(56, node, precedence, 9);
    }

    if (this.peek(38)) {
      return this.parseBinary(57, node, precedence, 9);
    }

    if (this.peek(30)) {
      return this.parseUnaryPostfix(37, node, precedence);
    }

    if (this.peek(25)) {
      return this.parseUnaryPostfix(36, node, precedence);
    }

    if (this.peek(40) && precedence < 12) {
      this.advance();
      var type = this.parseType();

      if (type === null) {
        return null;
      }

      return createCast(node, type).withRange(spanRanges(node.range, type.range)).withInternalRange(token);
    }

    var isIndex = this.peek(18);

    if ((isIndex || this.peek(19)) && precedence < 13) {
      return this.parseArgumentList(node.range, isIndex ? createIndex(node) : createCall(node));
    }

    if (this.peek(31) && precedence < 1) {
      this.advance();
      var middle = this.parseExpression(0, 0);

      if (middle === null || !this.expect(9)) {
        return null;
      }

      var right = this.parseExpression(0, 0);

      if (right === null) {
        return null;
      }

      return createHook(node, middle, right).withRange(spanRanges(node.range, right.range));
    }
  }

  return node;
};

ParserContext.prototype.parseArgumentList = function(start, node) {
  var open = this.current.range;
  var isIndex = node.kind === 22;
  var left = isIndex ? 18 : 19;
  var right = isIndex ? 34 : 35;

  if (!this.expect(left)) {
    return null;
  }

  if (!this.peek(right)) {
    while (true) {
      var value = this.parseExpression(0, 0);

      if (value === null) {
        return null;
      }

      node.appendChild(value);

      if (!this.eat(10)) {
        break;
      }
    }
  }

  var close = this.current.range;

  if (!this.expect(right)) {
    return null;
  }

  return node.withRange(spanRanges(start, close)).withInternalRange(spanRanges(open, close));
};

ParserContext.prototype.parseExpression = function(precedence, mode) {
  var node = this.parsePrefix(mode);

  if (node === null) {
    return null;
  }

  globals.assert(node.range !== null);

  while (true) {
    var result = this.parseInfix(precedence, node, mode);

    if (result === null) {
      return null;
    }

    if (result === node) {
      break;
    }

    node = result;
    globals.assert(node.range !== null);
  }

  return node;
};

ParserContext.prototype.parseType = function() {
  return this.parseExpression(13, 1);
};

ParserContext.prototype.parseIf = function() {
  var token = this.current;
  globals.assert(token.kind === 53);
  this.advance();

  if (!this.expect(19)) {
    return null;
  }

  var value = null;

  if (this.peek(35)) {
    this.unexpectedToken();
    this.advance();
    value = createParseError();
  }

  else {
    value = this.parseExpression(0, 0);

    if (value === null || !this.expect(35)) {
      return null;
    }
  }

  var trueBranch = this.parseBody();

  if (trueBranch === null) {
    return null;
  }

  var falseBranch = null;

  if (this.eat(46)) {
    falseBranch = this.parseBody();

    if (falseBranch === null) {
      return null;
    }
  }

  return createIf(value, trueBranch, falseBranch).withRange(spanRanges(token.range, (falseBranch !== null ? falseBranch : trueBranch).range));
};

ParserContext.prototype.parseWhile = function() {
  var token = this.current;
  globals.assert(token.kind === 71);
  this.advance();

  if (!this.expect(19)) {
    return null;
  }

  var value = null;

  if (this.peek(35)) {
    this.unexpectedToken();
    this.advance();
    value = createParseError();
  }

  else {
    value = this.parseExpression(0, 0);

    if (value === null || !this.expect(35)) {
      return null;
    }
  }

  var body = this.parseBody();

  if (body === null) {
    return null;
  }

  return createWhile(value, body).withRange(spanRanges(token.range, body.range));
};

ParserContext.prototype.parseBody = function() {
  var node = this.parseStatement(0);

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
  globals.assert(token.kind === 64);
  this.advance();
  var value = null;

  if (!this.peek(36)) {
    value = this.parseExpression(0, 0);

    if (value === null) {
      return null;
    }
  }

  var semicolon = this.current;
  this.expect(36);

  return createReturn(value).withRange(spanRanges(token.range, semicolon.range));
};

ParserContext.prototype.parseEmpty = function() {
  var token = this.current;
  this.advance();

  return createEmpty().withRange(token.range);
};

ParserContext.prototype.parseEnum = function(firstFlag) {
  var token = this.current;
  globals.assert(token.kind === 47);
  this.advance();
  var name = this.current;

  if (!this.expect(2) || !this.expect(17)) {
    return null;
  }

  var text = name.range.toString();
  var node = createEnum(text);
  node.firstFlag = firstFlag;
  node.flags = allFlags(firstFlag);

  while (!this.peek(0) && !this.peek(33)) {
    var member = this.current.range;
    var value = null;

    if (!this.expect(2)) {
      return null;
    }

    if (this.eat(5)) {
      value = this.parseExpression(0, 0);

      if (value === null) {
        return null;
      }
    }

    var variable = createVariable(member.toString(), createName(text), value);
    node.appendChild(variable.withRange(value !== null ? spanRanges(member, value.range) : member).withInternalRange(member));

    if (this.peek(36)) {
      this.expect(10);
      this.advance();
    }

    else if (this.peek(2)) {
      this.expect(10);
    }

    else if (!this.eat(10)) {
      break;
    }
  }

  var close = this.current;

  if (!this.expect(33)) {
    return null;
  }

  return node.withRange(spanRanges(token.range, close.range)).withInternalRange(name.range);
};

ParserContext.prototype.parseClass = function(firstFlag) {
  var token = this.current;
  globals.assert(token.kind === 42);
  this.advance();
  var name = this.current;

  if (!this.expect(2) || !this.expect(17)) {
    return null;
  }

  var node = createClass(name.range.toString());
  node.firstFlag = firstFlag;
  node.flags = allFlags(firstFlag);

  while (!this.peek(0) && !this.peek(33)) {
    var childFlags = this.parseFlags();
    var childName = this.current;
    var oldKind = childName.kind;

    if (isKeyword(childName.kind)) {
      childName.kind = 2;
      this.advance();
    }

    if (!this.expect(2)) {
      return null;
    }

    var text = childName.range.toString();

    if (globals.string_equals(text, "operator") && this.peek(18)) {
      childName.kind = 60;
      this.current = childName;

      if (this.parseFunction(childFlags, node) === null) {
        return null;
      }

      continue;
    }

    else if (this.peek(2)) {
      var isGet = globals.string_equals(text, "get");
      var isSet = globals.string_equals(text, "set");

      if (isGet || isSet) {
        childFlags = appendFlag(childFlags, isGet ? 8 : 128, childName.range);
        childName = this.current;
        this.advance();
      }

      else if (oldKind === 52) {
        this.log.error(childName.range, "Instance functions don't need the 'function' keyword");
        childName = this.current;
        this.advance();
      }

      else if (oldKind === 43 || oldKind === 57 || oldKind === 70) {
        this.log.error(childName.range, StringBuilder_new().append("Instance variables don't need the '").append(childName.range.toString()).append("' keyword").finish());
        childName = this.current;
        this.advance();
      }
    }

    if (this.peek(19)) {
      this.current = childName;

      if (this.parseFunction(childFlags, node) === null) {
        return null;
      }
    }

    else {
      this.current = childName;

      if (this.parseVariables(childFlags, node) === null) {
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

ParserContext.prototype.parseFunction = function(firstFlag, parent) {
  var token = this.current;
  var nameRange = null;
  var name = null;

  if (parent !== null && this.eat(60)) {
    var end = this.current;

    if (!this.expect(18) || !this.expect(34)) {
      return null;
    }

    if (this.peek(5)) {
      nameRange = spanRanges(token.range, this.current.range);
      name = "[]=";
      this.advance();
    }

    else {
      nameRange = spanRanges(token.range, end.range);
      name = "[]";
    }
  }

  else {
    if (parent === null) {
      globals.assert(token.kind === 52);
      this.advance();
    }

    nameRange = this.current.range;

    if (!this.expect(2)) {
      return null;
    }

    name = nameRange.toString();
  }

  if (!this.expect(19)) {
    return null;
  }

  var node = createFunction(name);
  node.firstFlag = firstFlag;
  node.flags = allFlags(firstFlag);

  if (!this.peek(35)) {
    while (true) {
      var firstArgumentFlag = this.parseFlags();
      var argument = this.current;

      if (!this.expect(2)) {
        return null;
      }

      var type = null;
      var range = argument.range;

      if (this.expect(9)) {
        type = this.parseType();

        if (type !== null) {
          range = spanRanges(range, type.range);
        }

        else if (this.peek(10) || this.peek(35)) {
          type = createParseError();
        }

        else {
          return null;
        }
      }

      else if (this.peek(10) || this.peek(35)) {
        type = createParseError();
      }

      var variable = createVariable(argument.range.toString(), type, null);
      variable.firstFlag = firstArgumentFlag;
      variable.flags = allFlags(firstArgumentFlag);
      node.appendChild(variable.withRange(range).withInternalRange(argument.range));

      if (!this.eat(10)) {
        break;
      }
    }
  }

  if (!this.expect(35)) {
    return null;
  }

  var returnType = null;

  if (this.expect(9)) {
    returnType = this.parseType();

    if (returnType === null) {
      if (this.peek(36) || this.peek(17)) {
        returnType = createParseError();
      }

      else {
        return null;
      }
    }
  }

  else if (this.peek(36) || this.peek(17)) {
    returnType = createParseError();
  }

  else {
    return null;
  }

  node.appendChild(returnType);
  var block = null;
  var semicolon = this.current;

  if (this.eat(36)) {
    block = createEmpty().withRange(semicolon.range);
  }

  else {
    block = this.parseBlock();

    if (block === null) {
      return null;
    }
  }

  if (parent !== null) {
    parent.appendChild(node);
  }

  node.appendChild(block);

  return node.withRange(spanRanges(token.range, block.range)).withInternalRange(nameRange);
};

ParserContext.prototype.parseVariables = function(firstFlag, parent) {
  var token = this.current;

  if (parent === null) {
    globals.assert(token.kind === 43 || token.kind === 57 || token.kind === 70);
    this.advance();
  }

  var node = token.kind === 43 ? createConstants() : createVariables();

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
      value = this.parseExpression(0, 0);

      if (value === null) {
        return null;
      }

      if (parent !== null) {
        this.log.error(value.range, "Inline initialization of instance variables is not supported yet");
      }
    }

    var range = value !== null ? spanRanges(name.range, value.range) : type !== null ? spanRanges(name.range, type.range) : name.range;
    var variable = createVariable(name.range.toString(), type, value);
    variable.firstFlag = firstFlag;
    variable.flags = allFlags(firstFlag);
    (parent !== null ? parent : node).appendChild(variable.withRange(range).withInternalRange(name.range));

    if (!this.eat(10)) {
      break;
    }
  }

  var semicolon = this.current;
  this.expect(36);

  return node.withRange(spanRanges(token.range, semicolon.range));
};

ParserContext.prototype.parseLoopJump = function(kind) {
  var token = this.current;
  this.advance();
  this.expect(36);
  var node = new Node();
  node.kind = kind;

  return node.withRange(token.range);
};

ParserContext.prototype.parseFlags = function() {
  var firstFlag = null;
  var lastFlag = null;

  while (true) {
    var token = this.current;
    var flag = 0;

    if (this.eat(45)) {
      flag = 1;
    }

    else if (this.eat(48)) {
      flag = 2;
    }

    else if (this.eat(50)) {
      flag = 4;
    }

    else if (this.eat(61)) {
      flag = 16;
    }

    else if (this.eat(62)) {
      flag = 32;
    }

    else if (this.eat(63)) {
      flag = 64;
    }

    else if (this.eat(66)) {
      flag = 256;
    }

    else if (this.eat(69)) {
      flag = 512;
    }

    else {
      return firstFlag;
    }

    var link = new NodeFlag();
    link.flag = flag;
    link.range = token.range;

    if (firstFlag === null) {
      firstFlag = link;
    }

    else {
      lastFlag.next = link;
    }

    lastFlag = link;
  }
};

ParserContext.prototype.parseUnsafe = function() {
  var token = this.current;
  this.advance();
  var node = this.parseBlock();

  if (node === null) {
    return null;
  }

  node.flags = node.flags | 512;

  return node.withRange(spanRanges(token.range, node.range));
};

ParserContext.prototype.parseStatement = function(mode) {
  var firstFlag = mode === 1 ? this.parseFlags() : null;

  if (this.peek(69) && firstFlag === null) {
    return this.parseUnsafe();
  }

  if (this.peek(43) || this.peek(57) || this.peek(70)) {
    return this.parseVariables(firstFlag, null);
  }

  if (this.peek(52)) {
    return this.parseFunction(firstFlag, null);
  }

  if (this.peek(42)) {
    return this.parseClass(firstFlag);
  }

  if (this.peek(47)) {
    return this.parseEnum(firstFlag);
  }

  if (firstFlag !== null) {
    this.unexpectedToken();

    return null;
  }

  if (this.peek(17)) {
    return this.parseBlock();
  }

  if (this.peek(41)) {
    return this.parseLoopJump(3);
  }

  if (this.peek(44)) {
    return this.parseLoopJump(6);
  }

  if (this.peek(53)) {
    return this.parseIf();
  }

  if (this.peek(71)) {
    return this.parseWhile();
  }

  if (this.peek(64)) {
    return this.parseReturn();
  }

  if (this.peek(36)) {
    return this.parseEmpty();
  }

  var value = this.parseExpression(0, 0);

  if (value === null) {
    return null;
  }

  var semicolon = this.current;
  this.expect(36);

  return createExpression(value).withRange(spanRanges(value.range, semicolon.range));
};

ParserContext.prototype.parseStatements = function(parent) {
  while (!this.peek(0) && !this.peek(33)) {
    var child = this.parseStatement(parent.kind === 0 ? 1 : 0);

    if (child === null) {
      return false;
    }

    parent.appendChild(child);
  }

  return true;
};

ParserContext.prototype.parseInt = function(range, node) {
  var source = range.source;
  var contents = source.contents;
  var i = range.start;
  var limit = range.end;
  var value = 0;
  var base = 10;

  if (globals.string_get(contents, i) === 48 && (i + 1 | 0) < limit) {
    var c = globals.string_get(contents, i + 1 | 0);

    if (c === 98 || c === 66) {
      base = 2;
    }

    else if (c === 111 || c === 79) {
      base = 8;
    }

    else if (c === 120 || c === 88) {
      base = 16;
    }

    else {
      this.log.error(range, "Use the '0o' prefix for octal integers");

      return false;
    }

    if (base !== 10) {
      i = i + 2 | 0;
    }
  }

  while (i < limit) {
    var c = globals.string_get(contents, i);
    var digit = (c >= 65 && c <= 70 ? c - 55 | 0 : c >= 97 && c <= 102 ? c - 87 | 0 : c - 48 | 0) >>> 0;
    var baseValue = __imul(value, base) >>> 0;

    if (baseValue / base >>> 0 !== value || baseValue > 4294967295 - digit >>> 0) {
      this.log.error(range, "Integer literal is too big to fit in 32 bits");

      return false;
    }

    value = baseValue + digit >>> 0;
    i = i + 1 | 0;
  }

  node.intValue = value | 0;

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

function Scope() {
  this.parent = null;
  this.symbol = null;
  this.firstSymbol = null;
  this.lastSymbol = null;
}

Scope.prototype.findLocal = function(name) {
  var symbol = this.firstSymbol;

  while (symbol !== null) {
    if (globals.string_equals(symbol.name, name)) {
      return symbol;
    }

    symbol = symbol.next;
  }

  return null;
};

Scope.prototype.findNested = function(name, mode) {
  var scope = this;

  while (scope !== null) {
    if (scope.symbol === null || scope.symbol.kind !== 0 || mode === 1) {
      var local = scope.findLocal(name);

      if (local !== null) {
        return local;
      }
    }

    scope = scope.parent;
  }

  return null;
};

Scope.prototype.define = function(log, symbol) {
  var existing = this.findLocal(symbol.name);

  if (existing !== null) {
    log.error(symbol.range, StringBuilder_new().append("Duplicate symbol '").append(symbol.name).append("'").finish());

    return false;
  }

  if (this.firstSymbol === null) {
    this.firstSymbol = symbol;
  }

  else {
    this.lastSymbol.next = symbol;
  }

  this.lastSymbol = symbol;

  return true;
};

Scope.prototype.defineNativeType = function(log, name, byteSizeAndMaxAlignment) {
  var symbol = new Symbol();
  symbol.kind = 3;
  symbol.name = name;
  symbol.byteSize = byteSizeAndMaxAlignment;
  symbol.maxAlignment = byteSizeAndMaxAlignment;
  symbol.resolvedType = new Type();
  symbol.resolvedType.symbol = symbol;
  symbol.state = 2;
  this.define(log, symbol);

  return symbol.resolvedType;
};

Scope.prototype.defineNativeIntegerType = function(log, name, byteSizeAndMaxAlignment, isUnsigned) {
  var type = this.defineNativeType(log, name, byteSizeAndMaxAlignment);
  type.symbol.flags = isUnsigned ? 3 : 1;

  return type;
};

function StringBuilder() {
  this.next = null;
  this._text = null;
}

StringBuilder.prototype.clear = function() {
  this._text = "";
};

StringBuilder.prototype.appendChar = function(c) {
  this._text = globals.StringBuilder_appendChar(this._text, c);

  return this;
};

StringBuilder.prototype.appendSlice = function(text, start, end) {
  this._text = globals.StringBuilder_append(this._text, globals.string_slice(text, start, end));

  return this;
};

StringBuilder.prototype.append = function(text) {
  this._text = globals.StringBuilder_append(this._text, text);

  return this;
};

StringBuilder.prototype.finish = function() {
  this.next = stringBuilderPool;
  stringBuilderPool = this;

  return this._text;
};

var stringBuilderPool = null;

function StringBuilder_new() {
  var sb = stringBuilderPool;

  if (sb !== null) {
    stringBuilderPool = sb.next;
  }

  else {
    sb = new StringBuilder();
  }

  sb.clear();

  return sb;
}

function isType(kind) {
  return kind >= 0 && kind <= 3;
}

function isFunction(kind) {
  return kind >= 4 && kind <= 5;
}

function isVariable(kind) {
  return kind >= 6 && kind <= 10;
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
  this.flags = 0;
  this.byteSize = 0;
  this.maxAlignment = 0;
  this.offset = 0;
}

Symbol.prototype.isEnumValue = function() {
  return this.node.parent.kind === 8;
};

Symbol.prototype.isUnsafe = function() {
  return this.node !== null && this.node.isUnsafe();
};

Symbol.prototype.parent = function() {
  var parent = this.node.parent;

  return parent.kind === 4 ? parent.symbol : null;
};

Symbol.prototype.resolvedTypeUnderlyingIfEnumValue = function(context) {
  return this.isEnumValue() ? this.resolvedType.underlyingType(context) : this.resolvedType;
};

Symbol.prototype.determineClassLayout = function(context) {
  globals.assert(this.kind === 0);

  if (this.byteSize !== 0) {
    return;
  }

  var offset = 0;
  var child = this.node.firstChild;
  var maxAlignment = 1;

  while (child !== null) {
    if (child.kind === 1) {
      var type = child.symbol.resolvedType;

      if (type !== context.errorType) {
        var alignmentOf = type.variableAlignmentOf();
        offset = alignToNextMultipleOf(offset, alignmentOf);

        if (alignmentOf > maxAlignment) {
          maxAlignment = alignmentOf;
        }

        child.symbol.offset = offset;
        offset = offset + type.variableSizeOf() | 0;
      }
    }

    child = child.nextSibling;
  }

  if (offset === 0) {
    offset = 1;
  }

  offset = alignToNextMultipleOf(offset, maxAlignment);
  this.byteSize = offset;
  this.maxAlignment = maxAlignment;
};

function Type() {
  this.symbol = null;
}

Type.prototype.isClass = function() {
  return this.symbol.kind === 0;
};

Type.prototype.isEnum = function() {
  return this.symbol.kind === 1;
};

Type.prototype.isInteger = function() {
  return (this.symbol.flags & 1) !== 0 || this.isEnum();
};

Type.prototype.isUnsigned = function() {
  return (this.symbol.flags & 2) !== 0;
};

Type.prototype.underlyingType = function(context) {
  return this.isEnum() ? context.intType : this;
};

Type.prototype.integerBitCount = function() {
  return this.symbol.byteSize << 3;
};

Type.prototype.integerBitMask = function() {
  return 4294967295 >>> ((32 - this.integerBitCount() | 0) >>> 0);
};

Type.prototype.isReference = function(context) {
  return this === context.stringType || this.isClass();
};

Type.prototype.allocationSizeOf = function() {
  return this.symbol.byteSize;
};

Type.prototype.allocationAlignmentOf = function() {
  return this.allocationSizeOf();
};

Type.prototype.variableSizeOf = function() {
  return this.isClass() ? 4 : this.symbol.byteSize;
};

Type.prototype.variableAlignmentOf = function() {
  return this.variableSizeOf();
};

Type.prototype.toString = function() {
  return this.symbol.name;
};

Type.prototype.findMember = function(name) {
  var child = this.symbol.node.firstChild;

  while (child !== null) {
    globals.assert(child.kind === 1 || child.kind === 10);

    if (globals.string_equals(child.symbol.name, name)) {
      return child.symbol;
    }

    child = child.nextSibling;
  }

  return null;
};

function WasmWrappedType() {
  this.id = 0;
  this.next = null;
}

function WasmSignature() {
  this.argumentTypes = null;
  this.returnType = null;
  this.next = null;
}

function wasmAreSignaturesEqual(a, b) {
  globals.assert(a.returnType !== null);
  globals.assert(b.returnType !== null);
  globals.assert(a.returnType.next === null);
  globals.assert(b.returnType.next === null);
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
  this.currentHeapPointer = 0;
  this.originalHeapPointer = 0;
  this.mallocFunctionIndex = 0;
  this.context = null;
}

WasmModule.prototype.growMemoryInitializer = function() {
  var array = this.memoryInitializer;
  var current = array.length();
  var length = this.context.nextGlobalVariableOffset;

  while (current < length) {
    array.append(0);
    current = current + 1 | 0;
  }
};

WasmModule.prototype.allocateImport = function(signatureIndex, mod, name) {
  var result = new WasmImport();
  result.signatureIndex = signatureIndex;
  result.module = mod;
  result.name = name;

  if (this.firstImport === null) {
    this.firstImport = result;
  }

  else {
    this.lastImport.next = result;
  }

  this.lastImport = result;
  this.importCount = this.importCount + 1 | 0;

  return result;
};

WasmModule.prototype.allocateFunction = function(name, signatureIndex, body) {
  var fn = new WasmFunction();
  fn.name = name;
  fn.signatureIndex = signatureIndex;
  fn.body = body;

  if (this.firstFunction === null) {
    this.firstFunction = fn;
  }

  else {
    this.lastFunction.next = fn;
  }

  this.lastFunction = fn;
  this.functionCount = this.functionCount + 1 | 0;

  return fn;
};

WasmModule.prototype.allocateSignature = function(argumentTypes, returnType) {
  globals.assert(returnType !== null);
  globals.assert(returnType.next === null);
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
    i = i + 1 | 0;
  }

  if (this.firstSignature === null) {
    this.firstSignature = signature;
  }

  else {
    this.lastSignature.next = signature;
  }

  this.lastSignature = signature;
  this.signatureCount = this.signatureCount + 1 | 0;

  return i;
};

WasmModule.prototype.emitModule = function(array) {
  ByteArray_append32(array, 1836278016);
  ByteArray_append32(array, 10);
  this.emitSignatures(array);
  this.emitImportTable(array);
  this.emitFunctionSignatures(array);
  this.emitMemory(array);
  this.emitExportTable(array);
  this.emitFunctionBodies(array);
  this.emitDataSegments(array);
};

WasmModule.prototype.emitSignatures = function(array) {
  var section = wasmStartSection(array, "signatures");
  wasmWriteVarUnsigned(array, this.signatureCount);
  var signature = this.firstSignature;

  while (signature !== null) {
    var count = 0;
    var type = signature.argumentTypes;

    while (type !== null) {
      count = count + 1 | 0;
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

  var section = wasmStartSection(array, "import_table");
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

  var section = wasmStartSection(array, "function_signatures");
  wasmWriteVarUnsigned(array, this.functionCount);
  var fn = this.firstFunction;

  while (fn !== null) {
    wasmWriteVarUnsigned(array, fn.signatureIndex);
    fn = fn.next;
  }

  wasmFinishSection(array, section);
};

WasmModule.prototype.emitMemory = function(array) {
  var section = wasmStartSection(array, "memory");
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
      exportedCount = exportedCount + 1 | 0;
    }

    fn = fn.next;
  }

  if (exportedCount === 0) {
    return;
  }

  var section = wasmStartSection(array, "export_table");
  wasmWriteVarUnsigned(array, exportedCount);
  var i = 0;
  fn = this.firstFunction;

  while (fn !== null) {
    if (fn.isExported) {
      wasmWriteVarUnsigned(array, i);
      wasmWriteLengthPrefixedString(array, fn.name);
    }

    fn = fn.next;
    i = i + 1 | 0;
  }

  wasmFinishSection(array, section);
};

WasmModule.prototype.emitFunctionBodies = function(array) {
  if (this.firstFunction === null) {
    return;
  }

  var section = wasmStartSection(array, "function_bodies");
  wasmWriteVarUnsigned(array, this.functionCount);
  var fn = this.firstFunction;

  while (fn !== null) {
    var bodyLength = array.length();
    wasmWriteVarUnsigned(array, -1);

    if (fn.intLocalCount > 0) {
      wasmWriteVarUnsigned(array, 1);
      wasmWriteVarUnsigned(array, fn.intLocalCount);
      array.append(1);
    }

    else {
      wasmWriteVarUnsigned(array, 0);
    }

    var child = fn.body.firstChild;

    while (child !== null) {
      this.emitNode(array, child);
      child = child.nextSibling;
    }

    wasmPatchVarUnsigned(array, bodyLength, (array.length() - bodyLength | 0) - 5 | 0, -1);
    fn = fn.next;
  }

  wasmFinishSection(array, section);
};

WasmModule.prototype.emitDataSegments = function(array) {
  this.growMemoryInitializer();
  var memoryInitializer = this.memoryInitializer;
  var initalizerLength = memoryInitializer.length();
  var initialHeapPointer = alignToNextMultipleOf(initalizerLength + 8 | 0, 8);
  ByteArray_set32(memoryInitializer, this.currentHeapPointer, initialHeapPointer);
  ByteArray_set32(memoryInitializer, this.originalHeapPointer, initialHeapPointer);
  var section = wasmStartSection(array, "data_segments");
  wasmWriteVarUnsigned(array, 1);
  wasmWriteVarUnsigned(array, 8);
  wasmWriteVarUnsigned(array, initalizerLength);
  var i = 0;

  while (i < initalizerLength) {
    array.append(memoryInitializer.get(i));
    i = i + 1 | 0;
  }

  wasmFinishSection(array, section);
};

WasmModule.prototype.prepareToEmit = function(node) {
  if (node.kind === 29) {
    var text = node.stringValue;
    var length = globals.string_length(text);
    var offset = this.context.allocateGlobalVariableOffset(length + 4 | 0, 4);
    node.intValue = offset;
    this.growMemoryInitializer();
    var memoryInitializer = this.memoryInitializer;
    ByteArray_set32(memoryInitializer, offset, length);
    ByteArray_setString(memoryInitializer, offset + 4 | 0, text);
  }

  else if (node.kind === 1) {
    var symbol = node.symbol;

    if (symbol.kind === 8) {
      var sizeOf = symbol.resolvedType.variableSizeOf();
      var value = symbol.node.variableValue().intValue;
      var memoryInitializer = this.memoryInitializer;
      this.growMemoryInitializer();

      if (sizeOf === 1) {
        memoryInitializer.set(symbol.offset, value & 255);
      }

      else if (sizeOf === 2) {
        ByteArray_set16(memoryInitializer, symbol.offset, value);
      }

      else if (sizeOf === 4) {
        ByteArray_set32(memoryInitializer, symbol.offset, value);
      }

      else {
        globals.assert(false);
      }

      if (globals.string_equals(symbol.name, "currentHeapPointer")) {
        globals.assert(this.currentHeapPointer === -1);
        this.currentHeapPointer = symbol.offset;
      }

      else if (globals.string_equals(symbol.name, "originalHeapPointer")) {
        globals.assert(this.originalHeapPointer === -1);
        this.originalHeapPointer = symbol.offset;
      }
    }
  }

  else if (node.kind === 10) {
    var returnType = node.functionReturnType();
    var shared = new WasmSharedOffset();
    var argumentTypesFirst = null;
    var argumentTypesLast = null;
    var argument = node.firstChild;

    while (argument !== returnType) {
      var type = wasmWrapType(this.getWasmType(argument.variableType().resolvedType));

      if (argumentTypesFirst === null) {
        argumentTypesFirst = type;
      }

      else {
        argumentTypesLast.next = type;
      }

      argumentTypesLast = type;
      shared.nextLocalOffset = shared.nextLocalOffset + 1 | 0;
      argument = argument.nextSibling;
    }

    var signatureIndex = this.allocateSignature(argumentTypesFirst, wasmWrapType(this.getWasmType(returnType.resolvedType)));
    var body = node.functionBody();
    var symbol = node.symbol;

    if (body === null) {
      var moduleName = symbol.kind === 4 ? symbol.parent().name : "globals";
      symbol.offset = this.importCount;
      this.allocateImport(signatureIndex, moduleName, symbol.name);
      node = node.nextSibling;

      return;
    }

    symbol.offset = this.functionCount;
    var fn = this.allocateFunction(symbol.name, signatureIndex, body);

    if (symbol.kind === 5 && globals.string_equals(symbol.name, "malloc")) {
      globals.assert(this.mallocFunctionIndex === -1);
      this.mallocFunctionIndex = symbol.offset;
    }

    if (node.isExtern()) {
      fn.isExported = true;
    }

    wasmAssignLocalVariableOffsets(body, shared);
    fn.intLocalCount = shared.intLocalCount;
  }

  var child = node.firstChild;

  while (child !== null) {
    this.prepareToEmit(child);
    child = child.nextSibling;
  }
};

WasmModule.prototype.emitBinaryExpression = function(array, node, opcode) {
  array.append(opcode);
  this.emitNode(array, node.binaryLeft());
  this.emitNode(array, node.binaryRight());
};

WasmModule.prototype.emitLoadFromMemory = function(array, type, relativeBase, offset) {
  var sizeOf = type.variableSizeOf();

  if (sizeOf === 1) {
    array.append(type.isUnsigned() ? 33 : 32);
    wasmWriteVarUnsigned(array, 0);
  }

  else if (sizeOf === 2) {
    array.append(type.isUnsigned() ? 35 : 34);
    wasmWriteVarUnsigned(array, 1);
  }

  else if (sizeOf === 4) {
    array.append(42);
    wasmWriteVarUnsigned(array, 2);
  }

  else {
    globals.assert(false);
  }

  wasmWriteVarUnsigned(array, offset);

  if (relativeBase !== null) {
    this.emitNode(array, relativeBase);
  }

  else {
    array.append(10);
    wasmWriteVarUnsigned(array, 0);
  }
};

WasmModule.prototype.emitStoreToMemory = function(array, type, relativeBase, offset, value) {
  var sizeOf = type.variableSizeOf();

  if (sizeOf === 1) {
    array.append(46);
    wasmWriteVarUnsigned(array, 0);
  }

  else if (sizeOf === 2) {
    array.append(47);
    wasmWriteVarUnsigned(array, 1);
  }

  else if (sizeOf === 4) {
    array.append(51);
    wasmWriteVarUnsigned(array, 2);
  }

  else {
    globals.assert(false);
  }

  wasmWriteVarUnsigned(array, offset);

  if (relativeBase !== null) {
    this.emitNode(array, relativeBase);
  }

  else {
    array.append(10);
    wasmWriteVarUnsigned(array, 0);
  }

  this.emitNode(array, value);
};

WasmModule.prototype.emitNode = function(array, node) {
  globals.assert(!isExpression(node) || node.resolvedType !== null);

  if (node.kind === 2) {
    array.append(1);
    var offset = array.length();
    wasmWriteVarUnsigned(array, -1);
    var count = 0;
    var child = node.firstChild;

    while (child !== null) {
      count = count + this.emitNode(array, child) | 0;
      child = child.nextSibling;
    }

    wasmPatchVarUnsigned(array, offset, count, -1);
  }

  else if (node.kind === 15) {
    var value = node.whileValue();
    var body = node.whileBody();

    if (value.kind === 17 && value.intValue === 0) {
      return 0;
    }

    array.append(2);
    var offset = array.length();
    wasmWriteVarUnsigned(array, -1);
    var count = 0;

    if (value.kind !== 17) {
      array.append(7);
      wasmWriteVarUnsigned(array, 1);
      array.append(0);
      array.append(90);
      this.emitNode(array, value);
      count = count + 1 | 0;
    }

    var child = body.firstChild;

    while (child !== null) {
      count = count + this.emitNode(array, child) | 0;
      child = child.nextSibling;
    }

    array.append(6);
    wasmWriteVarUnsigned(array, 0);
    array.append(0);
    count = count + 1 | 0;
    wasmPatchVarUnsigned(array, offset, count, -1);
  }

  else if (node.kind === 3 || node.kind === 6) {
    var label = 0;
    var parent = node.parent;

    while (parent !== null && parent.kind !== 15) {
      if (parent.kind === 2) {
        label = label + 1 | 0;
      }

      parent = parent.parent;
    }

    globals.assert(label > 0);
    array.append(6);
    wasmWriteVarUnsigned(array, label - (node.kind === 3 ? 0 : 1) | 0);
    array.append(0);
  }

  else if (node.kind === 7) {
    return 0;
  }

  else if (node.kind === 9) {
    this.emitNode(array, node.expressionValue());
  }

  else if (node.kind === 12) {
    var value = node.returnValue();
    array.append(20);

    if (value !== null) {
      this.emitNode(array, value);
    }
  }

  else if (node.kind === 14) {
    var count = 0;
    var child = node.firstChild;

    while (child !== null) {
      globals.assert(child.kind === 1);
      count = count + this.emitNode(array, child) | 0;
      child = child.nextSibling;
    }

    return count;
  }

  else if (node.kind === 11) {
    var branch = node.ifFalse();
    array.append(branch === null ? 3 : 4);
    this.emitNode(array, node.ifValue());
    this.emitNode(array, node.ifTrue());

    if (branch !== null) {
      this.emitNode(array, branch);
    }
  }

  else if (node.kind === 21) {
    array.append(4);
    this.emitNode(array, node.hookValue());
    this.emitNode(array, node.hookTrue());
    this.emitNode(array, node.hookFalse());
  }

  else if (node.kind === 1) {
    var value = node.variableValue();

    if (node.symbol.kind === 10) {
      array.append(15);
      wasmWriteVarUnsigned(array, node.symbol.offset);

      if (value !== null) {
        this.emitNode(array, value);
      }

      else {
        array.append(10);
        wasmWriteVarSigned(array, 0);
      }
    }

    else {
      globals.assert(false);
    }
  }

  else if (node.kind === 24) {
    var symbol = node.symbol;

    if (symbol.kind === 6 || symbol.kind === 10) {
      array.append(14);
      wasmWriteVarUnsigned(array, symbol.offset);
    }

    else if (symbol.kind === 8) {
      this.emitLoadFromMemory(array, symbol.resolvedType, null, symbol.offset + 8 | 0);
    }

    else {
      globals.assert(false);
    }
  }

  else if (node.kind === 26) {
    array.append(10);
    wasmWriteVarSigned(array, 0);
  }

  else if (node.kind === 23 || node.kind === 17) {
    array.append(10);
    wasmWriteVarSigned(array, node.intValue);
  }

  else if (node.kind === 29) {
    array.append(10);
    wasmWriteVarSigned(array, node.intValue + 8 | 0);
  }

  else if (node.kind === 18) {
    var value = node.callValue();
    var symbol = value.symbol;
    globals.assert(isFunction(symbol.kind));
    array.append(symbol.node.functionBody() === null ? 31 : 18);
    wasmWriteVarUnsigned(array, symbol.offset);

    if (symbol.kind === 4) {
      this.emitNode(array, value.dotTarget());
    }

    var child = value.nextSibling;

    while (child !== null) {
      this.emitNode(array, child);
      child = child.nextSibling;
    }
  }

  else if (node.kind === 25) {
    var type = node.newType();
    globals.assert(type.symbol.kind === 0);
    array.append(18);
    wasmWriteVarUnsigned(array, this.mallocFunctionIndex);
    globals.assert(type.symbol.byteSize > 0);
    array.append(10);
    wasmWriteVarSigned(array, type.symbol.byteSize);
  }

  else if (node.kind === 35) {
    this.emitNode(array, node.unaryValue());
  }

  else if (node.kind === 33) {
    array.append(65);
    array.append(10);
    wasmWriteVarSigned(array, 0);
    this.emitNode(array, node.unaryValue());
  }

  else if (node.kind === 32) {
    array.append(73);
    array.append(10);
    wasmWriteVarSigned(array, -1);
    this.emitNode(array, node.unaryValue());
  }

  else if (node.kind === 34) {
    array.append(90);
    this.emitNode(array, node.unaryValue());
  }

  else if (node.kind === 19) {
    var value = node.castValue();
    var context = this.context;
    var from = value.resolvedType.underlyingType(context);
    var type = node.resolvedType.underlyingType(context);

    if (from === type || from.symbol.byteSize < type.symbol.byteSize) {
      this.emitNode(array, value);
    }

    else if (type === context.byteType || type === context.shortType) {
      var shift = 32 - (type.symbol.byteSize << 3) | 0;
      array.append(76);
      array.append(74);
      this.emitNode(array, value);
      array.append(10);
      wasmWriteVarSigned(array, shift);
      array.append(10);
      wasmWriteVarSigned(array, shift);
    }

    else if (type === context.ubyteType || type === context.ushortType) {
      array.append(71);
      this.emitNode(array, value);
      array.append(10);
      wasmWriteVarSigned(array, type.integerBitMask() | 0);
    }

    else {
      this.emitNode(array, value);
    }
  }

  else if (node.kind === 20) {
    var symbol = node.symbol;

    if (symbol.kind === 9) {
      this.emitLoadFromMemory(array, symbol.resolvedType, node.dotTarget(), symbol.offset);
    }

    else {
      globals.assert(false);
    }
  }

  else if (node.kind === 41) {
    var left = node.binaryLeft();
    var symbol = left.symbol;

    if (symbol.kind === 9) {
      this.emitStoreToMemory(array, symbol.resolvedType, left.dotTarget(), symbol.offset, node.binaryRight());
    }

    else if (symbol.kind === 8) {
      this.emitStoreToMemory(array, symbol.resolvedType, null, symbol.offset + 8 | 0, node.binaryRight());
    }

    else if (symbol.kind === 6 || symbol.kind === 10) {
      array.append(15);
      wasmWriteVarUnsigned(array, symbol.offset);
      this.emitNode(array, node.binaryRight());
    }

    else {
      globals.assert(false);
    }
  }

  else if (node.kind === 51) {
    array.append(4);
    this.emitNode(array, node.binaryLeft());
    this.emitNode(array, node.binaryRight());
    array.append(10);
    wasmWriteVarSigned(array, 0);
  }

  else if (node.kind === 52) {
    array.append(4);
    this.emitNode(array, node.binaryLeft());
    array.append(10);
    wasmWriteVarSigned(array, 1);
    this.emitNode(array, node.binaryRight());
  }

  else {
    var isUnsigned = node.isUnsignedOperator();

    if (node.kind === 40) {
      this.emitBinaryExpression(array, node, 64);
    }

    else if (node.kind === 42) {
      this.emitBinaryExpression(array, node, 71);
    }

    else if (node.kind === 43) {
      this.emitBinaryExpression(array, node, 72);
    }

    else if (node.kind === 44) {
      this.emitBinaryExpression(array, node, 73);
    }

    else if (node.kind === 46) {
      this.emitBinaryExpression(array, node, 77);
    }

    else if (node.kind === 53) {
      this.emitBinaryExpression(array, node, 66);
    }

    else if (node.kind === 54) {
      this.emitBinaryExpression(array, node, 78);
    }

    else if (node.kind === 56) {
      this.emitBinaryExpression(array, node, 74);
    }

    else if (node.kind === 58) {
      this.emitBinaryExpression(array, node, 65);
    }

    else if (node.kind === 45) {
      this.emitBinaryExpression(array, node, isUnsigned ? 68 : 67);
    }

    else if (node.kind === 47) {
      this.emitBinaryExpression(array, node, isUnsigned ? 85 : 83);
    }

    else if (node.kind === 48) {
      this.emitBinaryExpression(array, node, isUnsigned ? 86 : 84);
    }

    else if (node.kind === 49) {
      this.emitBinaryExpression(array, node, isUnsigned ? 81 : 79);
    }

    else if (node.kind === 50) {
      this.emitBinaryExpression(array, node, isUnsigned ? 82 : 80);
    }

    else if (node.kind === 55) {
      this.emitBinaryExpression(array, node, isUnsigned ? 70 : 69);
    }

    else if (node.kind === 57) {
      this.emitBinaryExpression(array, node, isUnsigned ? 75 : 76);
    }

    else {
      globals.assert(false);
    }
  }

  return 1;
};

WasmModule.prototype.getWasmType = function(type) {
  var context = this.context;

  if (type === context.boolType || type.isInteger() || type.isReference(context)) {
    return 1;
  }

  if (type === context.voidType) {
    return 0;
  }

  globals.assert(false);

  return 0;
};

function wasmPatchVarUnsigned(array, offset, value, maxValue) {
  var current = value >>> 0;
  var max = maxValue >>> 0;

  while (true) {
    var byte = current & 127;
    current = current >>> 7;
    max = max >>> 7;

    if (max !== 0) {
      byte = byte | 128;
    }

    array.set(offset, byte & 255);
    offset = offset + 1 | 0;

    if (max === 0) {
      break;
    }
  }
}

function wasmWriteVarUnsigned(array, value) {
  var current = value >>> 0;

  while (true) {
    var byte = current & 127;
    current = current >>> 7;

    if (current !== 0) {
      byte = byte | 128;
    }

    array.append(byte & 255);

    if (current === 0) {
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

    array.append(byte & 255);

    if (done) {
      break;
    }
  }
}

function wasmWriteLengthPrefixedString(array, value) {
  var length = globals.string_length(value);
  wasmWriteVarUnsigned(array, length);
  var index = array.length();
  array.resize(index + length | 0);
  ByteArray_setString(array, index, value);
}

function wasmStartSection(array, name) {
  var offset = array.length();
  wasmWriteVarUnsigned(array, -1);
  wasmWriteLengthPrefixedString(array, name);

  return offset;
}

function wasmFinishSection(array, offset) {
  wasmPatchVarUnsigned(array, offset, (array.length() - offset | 0) - 5 | 0, -1);
}

function wasmWrapType(id) {
  globals.assert(id === 0 || id === 1);
  var type = new WasmWrappedType();
  type.id = id;

  return type;
}

function WasmSharedOffset() {
  this.nextLocalOffset = 0;
  this.intLocalCount = 0;
}

function wasmAssignLocalVariableOffsets(node, shared) {
  if (node.kind === 1) {
    globals.assert(node.symbol.kind === 10);
    node.symbol.offset = shared.nextLocalOffset;
    shared.nextLocalOffset = shared.nextLocalOffset + 1 | 0;
    shared.intLocalCount = shared.intLocalCount + 1 | 0;
  }

  var child = node.firstChild;

  while (child !== null) {
    wasmAssignLocalVariableOffsets(child, shared);
    child = child.nextSibling;
  }
}

function wasmEmit(global, context, array) {
  var module = new WasmModule();
  module.context = context;
  module.memoryInitializer = new ByteArray();
  module.mallocFunctionIndex = -1;
  module.currentHeapPointer = -1;
  module.originalHeapPointer = -1;
  module.prepareToEmit(global);
  globals.assert(module.mallocFunctionIndex !== -1);
  globals.assert(module.currentHeapPointer !== -1);
  globals.assert(module.originalHeapPointer !== -1);
  module.emitModule(array);
}

var __imul = Math.imul || function(a, b) {
  return (a * (b >>> 16) << 16) + a * (b & 65535) | 0;
};
