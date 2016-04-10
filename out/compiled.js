(function(__declare, __extern) {
  function string_op_get(__this, index) {
    return __this.charCodeAt(index);
  }

  function string_startsWith(__this, text) {
    return __this.slice(0, text.length) === text;
  }

  function string_endsWith(__this, text) {
    return __this.slice(-text.length | 0, __this.length) === text;
  }

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

  function ByteArray_setString(array, index, text) {
    var length = text.length;
    __declare.assert(index >= 0 && (index + (length << 1) | 0) <= array.length());
    var data = array._data;
    var i = 0;

    while (i < length) {
      var c = string_op_get(text, i);
      data[index] = c & 255;
      data[index + 1 | 0] = c >>> 8 & 255;
      index = index + 2 | 0;
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
    __declare.assert(index >>> 0 < this._length >>> 0);

    return this._data[index];
  };

  ByteArray.prototype.set = function(index, value) {
    __declare.assert(index >>> 0 < this._length >>> 0);
    this._data[index] = value;
  };

  ByteArray.prototype.append = function(value) {
    var index = this._length;
    this.resize(index + 1 | 0);
    this._data[index] = value;
  };

  ByteArray.prototype.resize = function(length) {
    if (length > (this._data !== null ? this._data.length : 0)) {
      var capacity = length << 1;
      var data = __declare.Uint8Array_new(capacity);

      if (this._data !== null) {
        data.set(this._data);
      }

      this._data = data;
    }

    this._length = length;
  };

  function CResult() {
    this.context = null;
    this.code = null;
    this.codePrefix = null;
    this.indent = 0;
    this.hasStrings = false;
    this.previousNode = null;
    this.nextStringLiteral = 0;
  }

  CResult.prototype.emitIndent = function() {
    var i = this.indent;

    while (i > 0) {
      this.code.append("  ");
      i = i - 1 | 0;
    }
  };

  CResult.prototype.emitNewlineBefore = function(node) {
    if (this.previousNode !== null && (!isCompactNodeKind(this.previousNode.kind) || !isCompactNodeKind(node.kind))) {
      this.code.appendChar(10);
    }

    this.previousNode = null;
  };

  CResult.prototype.emitNewlineAfter = function(node) {
    this.previousNode = node;
  };

  CResult.prototype.emitStatements = function(node) {
    while (node !== null) {
      this.emitStatement(node);
      node = node.nextSibling;
    }
  };

  CResult.prototype.emitBlock = function(node) {
    this.previousNode = null;
    this.code.append("{\n");
    this.indent = this.indent + 1 | 0;
    this.emitStatements(node.firstChild);
    this.indent = this.indent - 1 | 0;
    this.emitIndent();
    this.code.appendChar(125);
    this.previousNode = null;
  };

  CResult.prototype.emitUnary = function(node, parentPrecedence, operator) {
    var isPostfix = isUnaryPostfix(node.kind);
    var operatorPrecedence = isPostfix ? 14 : 13;
    var code = this.code;

    if (parentPrecedence > operatorPrecedence) {
      code.appendChar(40);
    }

    if (!isPostfix) {
      code.append(operator);
    }

    this.emitExpression(node.unaryValue(), operatorPrecedence);

    if (isPostfix) {
      code.append(operator);
    }

    if (parentPrecedence > operatorPrecedence) {
      code.appendChar(41);
    }
  };

  CResult.prototype.emitBinary = function(node, parentPrecedence, operator, operatorPrecedence) {
    var kind = node.kind;
    var isRightAssociative = kind === 45;
    var needsParentheses = parentPrecedence > operatorPrecedence;
    var parentKind = node.parent.kind;
    var code = this.code;

    if (parentKind === 57 && kind === 56 || parentKind === 47 && kind === 46 || (parentKind === 50 || parentKind === 59) && (kind === 50 || kind === 59) || (kind === 44 || kind === 63) && (parentKind === 46 || parentKind === 47 || parentKind === 48 || parentKind === 61 || parentKind === 62)) {
      needsParentheses = true;
    }

    if (needsParentheses) {
      code.appendChar(40);
    }

    this.emitExpression(node.binaryLeft(), isRightAssociative ? operatorPrecedence + 1 | 0 : operatorPrecedence);
    code.append(operator);
    this.emitExpression(node.binaryRight(), isRightAssociative ? operatorPrecedence : operatorPrecedence + 1 | 0);

    if (needsParentheses) {
      code.appendChar(41);
    }
  };

  CResult.prototype.emitCommaSeparatedExpressions = function(start, stop) {
    while (start !== stop) {
      this.emitExpression(start, 0);
      start = start.nextSibling;

      if (start !== stop) {
        this.code.append(", ");
      }
    }
  };

  CResult.prototype.emitSymbolName = function(symbol) {
    if (symbol.kind === 4) {
      this.code.append(symbol.parent().name).appendChar(95);
    }

    this.code.append(symbol.rename !== null ? symbol.rename : symbol.name);
  };

  CResult.prototype.emitCharacter = function(c) {
    var codePrefix = this.codePrefix;

    if (isASCII(c)) {
      codePrefix.appendChar(39);

      if (c === 92 || c === 39) {
        codePrefix.appendChar(92);
      }

      codePrefix.appendChar(c);
      codePrefix.appendChar(39);
    }

    else if (c === 0) {
      codePrefix.append("'\\0'");
    }

    else if (c === 13) {
      codePrefix.append("'\\r'");
    }

    else if (c === 10) {
      codePrefix.append("'\\n'");
    }

    else if (c === 9) {
      codePrefix.append("'\\t'");
    }

    else {
      codePrefix.append(c.toString());
    }
  };

  CResult.prototype.emitExpression = function(node, parentPrecedence) {
    var code = this.code;
    __declare.assert(node.resolvedType !== null);

    if (node.kind === 25) {
      this.emitSymbolName(node.symbol);
    }

    else if (node.kind === 27) {
      code.append("NULL");
    }

    else if (node.kind === 18) {
      code.appendChar(node.intValue !== 0 ? 49 : 48);
    }

    else if (node.kind === 24) {
      code.append(node.resolvedType.isUnsigned() ? (node.intValue >>> 0).toString() : node.intValue.toString());
    }

    else if (node.kind === 30) {
      var id = this.nextStringLiteral;
      var builder = StringBuilder_new();
      builder.append("__string_").append(id.toString());
      var value = node.stringValue;
      var codePrefix = this.codePrefix;
      var length = value.length;
      var i = 0;

      if (!this.hasStrings) {
        codePrefix.append("\n#ifdef THINSCRIPT_BIG_ENDIAN\n  #define S(a, b) (((a) << 16) | (b))\n#else\n  #define S(a, b) ((a) | ((b) << 16))\n#endif\n\n");
        this.hasStrings = true;
      }

      var underscore = true;
      i = 0;

      while (i < length && i < 32) {
        var c = string_op_get(value, i);

        if (isAlpha(c) || isNumber(c)) {
          if (underscore) {
            builder.appendChar(95);
            underscore = false;
          }

          builder.appendChar(c);
        }

        else {
          underscore = true;
        }

        i = i + 1 | 0;
      }

      var name = builder.finish();
      codePrefix.append("static const uint32_t ").append(name).append("[] = {").append(length.toString());
      i = 0;

      while (i < length) {
        codePrefix.append(", S(");
        this.emitCharacter(string_op_get(value, i));

        if ((i + 1 | 0) < length) {
          codePrefix.append(", ");
          this.emitCharacter(string_op_get(value, i + 1 | 0));
          codePrefix.appendChar(41);
        }

        else {
          codePrefix.append(", 0)");
        }

        i = i + 2 | 0;
      }

      codePrefix.append("};\n");
      this.nextStringLiteral = this.nextStringLiteral + 1 | 0;
      code.append("(const uint16_t *)").append(name);
    }

    else if (node.kind === 20) {
      if (parentPrecedence > 13) {
        code.appendChar(40);
      }

      code.appendChar(40);
      this.emitType(node.resolvedType, 0);
      code.appendChar(41);
      this.emitExpression(node.castValue(), 13);

      if (parentPrecedence > 13) {
        code.appendChar(41);
      }
    }

    else if (node.kind === 21) {
      var target = node.dotTarget();
      this.emitExpression(target, 15);
      code.append(target.resolvedType.isReference() ? "->" : ".");
      this.emitSymbolName(node.symbol);
    }

    else if (node.kind === 22) {
      if (parentPrecedence > 1) {
        code.appendChar(40);
      }

      this.emitExpression(node.hookValue(), 2);
      code.append(" ? ");
      this.emitExpression(node.hookTrue(), 1);
      code.append(" : ");
      this.emitExpression(node.hookFalse(), 1);

      if (parentPrecedence > 1) {
        code.appendChar(41);
      }
    }

    else if (node.kind === 19) {
      var value = node.callValue();
      this.emitSymbolName(value.symbol);
      code.appendChar(40);

      if (value.kind === 21) {
        this.emitExpression(value.dotTarget(), 0);

        if (value.nextSibling !== null) {
          code.append(", ");
        }
      }

      this.emitCommaSeparatedExpressions(value.nextSibling, null);
      code.appendChar(41);
    }

    else if (node.kind === 26) {
      code.append("calloc(1, sizeof(");
      this.emitType(node.resolvedType, 2);
      code.append("))");
    }

    else if (node.kind === 34) {
      this.emitUnary(node, parentPrecedence, "~");
    }

    else if (node.kind === 35) {
      this.emitUnary(node, parentPrecedence, "*");
    }

    else if (node.kind === 36) {
      this.emitUnary(node, parentPrecedence, "-");
    }

    else if (node.kind === 37) {
      this.emitUnary(node, parentPrecedence, "!");
    }

    else if (node.kind === 39) {
      this.emitUnary(node, parentPrecedence, "+");
    }

    else if (node.kind === 40) {
      this.emitUnary(node, parentPrecedence, "--");
    }

    else if (node.kind === 41) {
      this.emitUnary(node, parentPrecedence, "++");
    }

    else if (node.kind === 42) {
      this.emitUnary(node, parentPrecedence, "--");
    }

    else if (node.kind === 43) {
      this.emitUnary(node, parentPrecedence, "++");
    }

    else if (node.kind === 44) {
      this.emitBinary(node, parentPrecedence, " + ", 10);
    }

    else if (node.kind === 45) {
      this.emitBinary(node, parentPrecedence, " = ", 1);
    }

    else if (node.kind === 46) {
      this.emitBinary(node, parentPrecedence, " & ", 6);
    }

    else if (node.kind === 47) {
      this.emitBinary(node, parentPrecedence, " | ", 4);
    }

    else if (node.kind === 48) {
      this.emitBinary(node, parentPrecedence, " ^ ", 5);
    }

    else if (node.kind === 49) {
      this.emitBinary(node, parentPrecedence, " / ", 11);
    }

    else if (node.kind === 50) {
      this.emitBinary(node, parentPrecedence, " == ", 7);
    }

    else if (node.kind === 52) {
      this.emitBinary(node, parentPrecedence, " > ", 8);
    }

    else if (node.kind === 53) {
      this.emitBinary(node, parentPrecedence, " >= ", 8);
    }

    else if (node.kind === 54) {
      this.emitBinary(node, parentPrecedence, " < ", 8);
    }

    else if (node.kind === 55) {
      this.emitBinary(node, parentPrecedence, " <= ", 8);
    }

    else if (node.kind === 56) {
      this.emitBinary(node, parentPrecedence, " && ", 3);
    }

    else if (node.kind === 57) {
      this.emitBinary(node, parentPrecedence, " || ", 2);
    }

    else if (node.kind === 58) {
      this.emitBinary(node, parentPrecedence, " * ", 11);
    }

    else if (node.kind === 59) {
      this.emitBinary(node, parentPrecedence, " != ", 7);
    }

    else if (node.kind === 60) {
      this.emitBinary(node, parentPrecedence, " % ", 11);
    }

    else if (node.kind === 61) {
      this.emitBinary(node, parentPrecedence, " << ", 9);
    }

    else if (node.kind === 62) {
      this.emitBinary(node, parentPrecedence, " >> ", 9);
    }

    else if (node.kind === 63) {
      this.emitBinary(node, parentPrecedence, " - ", 10);
    }

    else {
      __declare.assert(false);
    }
  };

  CResult.prototype.shouldEmitClass = function(node) {
    __declare.assert(node.kind === 5);

    return node.symbol.kind === 0 && node.symbol !== this.context.stringType.symbol;
  };

  CResult.prototype.emitType = function(originalType, mode) {
    var context = this.context;
    var code = this.code;
    var type = originalType;

    if (type.isEnum()) {
      type = type.underlyingType(this.context);
    }

    else {
      while (type.pointerTo !== null) {
        type = type.pointerTo;
      }
    }

    if (type.isClass()) {
      code.append("struct ");
    }

    if (type === context.boolType || type === context.byteType) {
      code.append("uint8_t");
    }

    else if (type === context.sbyteType) {
      code.append("int8_t");
    }

    else if (type === context.intType) {
      code.append("int32_t");
    }

    else if (type === context.shortType) {
      code.append("int16_t");
    }

    else if (type === context.stringType) {
      code.append("const uint16_t");
    }

    else if (type === context.uintType) {
      code.append("uint32_t");
    }

    else if (type === context.ushortType) {
      code.append("uint16_t");
    }

    else {
      this.emitSymbolName(type.symbol);
    }

    if (originalType.pointerTo !== null) {
      code.appendChar(32);

      while (originalType.pointerTo !== null) {
        code.appendChar(42);
        originalType = originalType.pointerTo;
      }
    }

    else if (mode !== 2) {
      if (type.isReference()) {
        code.append(" *");
      }

      else if (mode === 1) {
        code.appendChar(32);
      }
    }
  };

  CResult.prototype.emitStatement = function(node) {
    var code = this.code;

    if (node.kind === 12) {
      this.emitNewlineBefore(node);
      this.emitIndent();

      while (true) {
        code.append("if (");
        this.emitExpression(node.ifValue(), 0);
        code.append(") ");
        this.emitBlock(node.ifTrue());
        var no = node.ifFalse();

        if (no === null) {
          code.appendChar(10);

          break;
        }

        code.append("\n\n");
        this.emitIndent();
        code.append("else ");

        if (no.firstChild === null || no.firstChild !== no.lastChild || no.firstChild.kind !== 12) {
          this.emitBlock(no);
          code.appendChar(10);

          break;
        }

        node = no.firstChild;
      }

      this.emitNewlineAfter(node);
    }

    else if (node.kind === 16) {
      this.emitNewlineBefore(node);
      this.emitIndent();
      code.append("while (");
      this.emitExpression(node.whileValue(), 0);
      code.append(") ");
      this.emitBlock(node.whileBody());
      code.appendChar(10);
      this.emitNewlineAfter(node);
    }

    else if (node.kind === 4) {
      this.emitNewlineBefore(node);
      this.emitIndent();
      code.append("break;\n");
      this.emitNewlineAfter(node);
    }

    else if (node.kind === 7) {
      this.emitNewlineBefore(node);
      this.emitIndent();
      code.append("continue;\n");
      this.emitNewlineAfter(node);
    }

    else if (node.kind === 10) {
      this.emitNewlineBefore(node);
      this.emitIndent();
      this.emitExpression(node.expressionValue(), 0);
      code.append(";\n");
      this.emitNewlineAfter(node);
    }

    else if (node.kind === 8) {
    }

    else if (node.kind === 13) {
      var value = node.returnValue();
      this.emitNewlineBefore(node);
      this.emitIndent();

      if (value !== null) {
        code.append("return ");
        this.emitExpression(value, 0);
        code.append(";\n");
      }

      else {
        code.append("return;\n");
      }

      this.emitNewlineAfter(node);
    }

    else if (node.kind === 3) {
      if (node.parent.kind === 3) {
        this.emitStatements(node.firstChild);
      }

      else {
        this.emitNewlineBefore(node);
        this.emitIndent();
        this.emitBlock(node);
        code.appendChar(10);
        this.emitNewlineAfter(node);
      }
    }

    else if (node.kind === 15) {
      this.emitNewlineBefore(node);
      var child = node.firstChild;

      while (child !== null) {
        var value = child.variableValue();
        this.emitIndent();
        this.emitType(child.symbol.resolvedType, 1);
        this.emitSymbolName(child.symbol);
        __declare.assert(value !== null);
        code.append(" = ");
        this.emitExpression(value, 0);
        code.append(";\n");
        child = child.nextSibling;
      }

      this.emitNewlineAfter(node);
    }

    else if (node.kind === 6 || node.kind === 9) {
    }

    else {
      __declare.assert(false);
    }
  };

  CResult.prototype.emitIncludes = function() {
    var code = this.codePrefix;
    code.append("#include <stdint.h>\n");
    code.append("#include <stdlib.h>\n");
    code.append("#include <string.h>\n");
  };

  CResult.prototype.emitTypeDeclarations = function(node) {
    var code = this.code;

    while (node !== null) {
      if (node.kind === 5) {
        if (this.shouldEmitClass(node)) {
          this.emitNewlineBefore(node);
          code.append("struct ").append(node.symbol.name).append(";\n");
        }
      }

      node = node.nextSibling;
    }
  };

  CResult.prototype.emitTypeDefinitions = function(node) {
    var code = this.code;

    while (node !== null) {
      if (node.kind === 5) {
        if (this.shouldEmitClass(node)) {
          this.emitNewlineBefore(node);
          code.append("struct ");
          this.emitSymbolName(node.symbol);
          code.append(" {\n");
          this.indent = this.indent + 1 | 0;
          var child = node.firstChild;

          while (child !== null) {
            if (child.kind === 2) {
              this.emitIndent();
              this.emitType(child.symbol.resolvedType, 1);
              this.emitSymbolName(child.symbol);
              code.append(";\n");
            }

            child = child.nextSibling;
          }

          this.indent = this.indent - 1 | 0;
          code.append("};\n");
          this.emitNewlineAfter(node);
        }
      }

      node = node.nextSibling;
    }
  };

  CResult.prototype.shouldEmitFunction = function(symbol) {
    return symbol.kind !== 5 || symbol.name !== "malloc" && symbol.name !== "memcpy" && symbol.name !== "memcmp";
  };

  CResult.prototype.emitFunctionDeclarations = function(node) {
    var code = this.code;

    while (node !== null) {
      if (node.kind === 11) {
        var symbol = node.symbol;

        if (this.shouldEmitFunction(symbol)) {
          var returnType = node.functionReturnType();
          var child = node.firstChild;
          this.emitNewlineBefore(node);

          if (!node.isDeclareOrExtern()) {
            code.append("static ");
          }

          this.emitType(returnType.resolvedType, 1);
          this.emitSymbolName(symbol);
          code.appendChar(40);

          while (child !== returnType) {
            __declare.assert(child.kind === 2);
            this.emitType(child.symbol.resolvedType, 1);
            this.emitSymbolName(child.symbol);
            child = child.nextSibling;

            if (child !== returnType) {
              code.append(", ");
            }
          }

          code.append(");\n");
        }
      }

      else if (node.kind === 5) {
        this.emitFunctionDeclarations(node.firstChild);
      }

      node = node.nextSibling;
    }
  };

  CResult.prototype.emitGlobalVariables = function(node) {
    var code = this.code;

    while (node !== null) {
      if (node.kind === 2) {
        var value = node.variableValue();
        this.emitNewlineBefore(node);

        if (!node.isDeclareOrExtern()) {
          code.append("static ");
        }

        this.emitType(node.symbol.resolvedType, 1);
        this.emitSymbolName(node.symbol);
        code.append(" = ");
        this.emitExpression(value, 0);
        code.append(";\n");
      }

      else if (node.kind === 15) {
        this.emitGlobalVariables(node.firstChild);
      }

      node = node.nextSibling;
    }
  };

  CResult.prototype.emitFunctionDefinitions = function(node) {
    var code = this.code;

    while (node !== null) {
      if (node.kind === 11) {
        var body = node.functionBody();
        var symbol = node.symbol;

        if (body !== null && this.shouldEmitFunction(symbol)) {
          var returnType = node.functionReturnType();
          var child = node.firstChild;
          this.emitNewlineBefore(node);

          if (!node.isDeclareOrExtern()) {
            code.append("static ");
          }

          this.emitType(returnType.resolvedType, 1);
          this.emitSymbolName(symbol);
          code.appendChar(40);

          while (child !== returnType) {
            __declare.assert(child.kind === 2);
            this.emitType(child.symbol.resolvedType, 1);
            this.emitSymbolName(child.symbol);
            child = child.nextSibling;

            if (child !== returnType) {
              code.append(", ");
            }
          }

          code.append(") ");
          this.emitBlock(node.functionBody());
          code.appendChar(10);
          this.emitNewlineAfter(node);
        }
      }

      else if (node.kind === 5) {
        this.emitFunctionDefinitions(node.firstChild);
      }

      node = node.nextSibling;
    }
  };

  CResult.prototype.finish = function() {
    if (this.hasStrings) {
      this.codePrefix.append("\n#undef S\n");
    }
  };

  function cEmit(compiler) {
    var child = compiler.global.firstChild;
    var code = StringBuilder_new();
    var codePrefix = StringBuilder_new();
    var result = new CResult();
    result.context = compiler.context;
    result.code = code;
    result.codePrefix = codePrefix;

    if (child !== null) {
      result.emitIncludes();
      result.emitNewlineAfter(child);
      result.emitTypeDeclarations(child);
      result.emitNewlineAfter(child);
      result.emitTypeDefinitions(child);
      result.emitNewlineAfter(child);
      result.emitFunctionDeclarations(child);
      result.emitNewlineAfter(child);
      result.emitGlobalVariables(child);
      result.emitNewlineAfter(child);
      result.emitFunctionDefinitions(child);
      result.finish();
    }

    codePrefix.append(code.finish());
    compiler.output_c = codePrefix.finish();
  }

  function CheckContext() {
    this.log = null;
    this.target = 0;
    this.pointerByteSize = 0;
    this.isUnsafeAllowed = false;
    this.enclosingClass = null;
    this.currentReturnType = null;
    this.nextGlobalVariableOffset = 0;
    this.boolType = null;
    this.sbyteType = null;
    this.errorType = null;
    this.intType = null;
    this.nullType = null;
    this.shortType = null;
    this.stringType = null;
    this.byteType = null;
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

  function initialize(context, node, parentScope, mode) {
    var kind = node.kind;

    if (node.parent !== null) {
      var parentKind = node.parent.kind;

      if (kind !== 2 && kind !== 15 && (kind !== 11 || parentKind !== 5) && parentKind === 0 !== (kind === 5 || kind === 9 || kind === 11 || kind === 6)) {
        context.log.error(node.range, "This statement is not allowed here");
      }
    }

    if (kind === 5 || kind === 9) {
      __declare.assert(node.symbol === null);
      var symbol = new Symbol();
      symbol.kind = kind === 5 ? 0 : 1;
      symbol.name = node.stringValue;
      symbol.resolvedType = new Type();
      symbol.resolvedType.symbol = symbol;
      symbol.flags = 4;
      addScopeToSymbol(symbol, parentScope);
      linkSymbolToNode(symbol, node);
      parentScope.define(context.log, symbol, 0);
      parentScope = symbol.scope;
    }

    else if (kind === 11) {
      __declare.assert(node.symbol === null);
      var symbol = new Symbol();
      symbol.kind = node.parent.kind === 5 ? 4 : 5;
      symbol.name = node.stringValue;

      if (node.isOperator()) {
        if (symbol.name === "+" || symbol.name === "-") {
          if (node.firstChild === node.functionReturnType()) {
            symbol.flags = 8;
            symbol.rename = symbol.name === "+" ? "op_positive" : "op_negative";
          }

          else {
            symbol.flags = 2;
            symbol.rename = symbol.name === "+" ? "op_add" : "op_subtract";
          }
        }

        else {
          symbol.rename = symbol.name === "%" ? "op_remainder" : symbol.name === "&" ? "op_and" : symbol.name === "*" ? "op_multiply" : symbol.name === "**" ? "op_exponent" : symbol.name === "++" ? "op_increment" : symbol.name === "--" ? "op_decrement" : symbol.name === "/" ? "op_divide" : symbol.name === "<" ? "op_lessThan" : symbol.name === "<<" ? "op_shiftLeft" : symbol.name === "==" ? "op_equals" : symbol.name === ">" ? "op_greaterThan" : symbol.name === ">>" ? "op_shiftRight" : symbol.name === "[]" ? "op_get" : symbol.name === "[]=" ? "op_set" : symbol.name === "^" ? "op_xor" : symbol.name === "|" ? "op_or" : symbol.name === "~" ? "op_complement" : null;
        }
      }

      addScopeToSymbol(symbol, parentScope);
      linkSymbolToNode(symbol, node);
      parentScope.define(context.log, symbol, symbol.isSetter() ? 2 : symbol.isGetter() ? 3 : symbol.isBinaryOperator() ? 4 : symbol.isUnaryOperator() ? 1 : 0);
      parentScope = symbol.scope;

      if (symbol.kind === 4) {
        var parent = symbol.parent();
        initializeSymbol(context, parent);
        node.insertChildBefore(node.firstChild, createVariable("this", createType(parent.resolvedType), null));
      }
    }

    else if (kind === 2) {
      __declare.assert(node.symbol === null);
      var symbol = new Symbol();
      symbol.kind = node.parent.kind === 5 ? 9 : node.parent.kind === 11 ? 6 : node.parent.kind === 6 || node.parent.kind === 9 ? 7 : node.parent.kind === 15 && node.parent.parent.kind === 0 ? 8 : 10;
      symbol.name = node.stringValue;
      symbol.scope = parentScope;
      linkSymbolToNode(symbol, node);
      parentScope.define(context.log, symbol, 0);
    }

    else if (kind === 3) {
      if (node.parent.kind !== 11) {
        var scope = new Scope();
        scope.parent = parentScope;
        parentScope = scope;
      }

      node.scope = parentScope;
    }

    var child = node.firstChild;

    while (child !== null) {
      initialize(context, child, parentScope, mode);
      child = child.nextSibling;
    }

    if (kind === 0 && mode === 1) {
      context.boolType = parentScope.findLocal("bool", 0).resolvedType;
      context.byteType = parentScope.findLocal("byte", 0).resolvedType;
      context.intType = parentScope.findLocal("int", 0).resolvedType;
      context.sbyteType = parentScope.findLocal("sbyte", 0).resolvedType;
      context.shortType = parentScope.findLocal("short", 0).resolvedType;
      context.stringType = parentScope.findLocal("string", 0).resolvedType;
      context.uintType = parentScope.findLocal("uint", 0).resolvedType;
      context.ushortType = parentScope.findLocal("ushort", 0).resolvedType;
      prepareNativeType(context.boolType, 1, 0);
      prepareNativeType(context.byteType, 1, 48);
      prepareNativeType(context.intType, 4, 32);
      prepareNativeType(context.sbyteType, 1, 32);
      prepareNativeType(context.shortType, 2, 32);
      prepareNativeType(context.stringType, 4, 4);
      prepareNativeType(context.uintType, 4, 48);
      prepareNativeType(context.ushortType, 2, 48);
    }
  }

  function prepareNativeType(type, byteSizeAndMaxAlignment, flags) {
    var symbol = type.symbol;
    symbol.kind = 3;
    symbol.byteSize = byteSizeAndMaxAlignment;
    symbol.maxAlignment = byteSizeAndMaxAlignment;
    symbol.flags = flags;
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
      __declare.assert(symbol.resolvedType !== null);

      return;
    }

    __declare.assert(symbol.state === 0);
    symbol.state = 1;
    var node = symbol.node;
    forbidFlag(context, node, 2, "Unsupported flag 'export'");
    forbidFlag(context, node, 128, "Unsupported flag 'protected'");
    forbidFlag(context, node, 1024, "Unsupported flag 'static'");

    if (symbol.kind === 0 || symbol.kind === 3) {
      forbidFlag(context, node, 8, "Cannot use 'get' on a class");
      forbidFlag(context, node, 512, "Cannot use 'set' on a class");
      forbidFlag(context, node, 256, "Cannot use 'public' on a class");
      forbidFlag(context, node, 64, "Cannot use 'private' on a class");
    }

    else if (symbol.kind === 1) {
      forbidFlag(context, node, 8, "Cannot use 'get' on an enum");
      forbidFlag(context, node, 512, "Cannot use 'set' on an enum");
      forbidFlag(context, node, 256, "Cannot use 'public' on an enum");
      forbidFlag(context, node, 64, "Cannot use 'private' on an enum");
      symbol.resolvedType = new Type();
      symbol.resolvedType.symbol = symbol;
      var underlyingSymbol = symbol.resolvedType.underlyingType(context).symbol;
      symbol.byteSize = underlyingSymbol.byteSize;
      symbol.maxAlignment = underlyingSymbol.maxAlignment;
    }

    else if (isFunction(symbol.kind)) {
      var body = node.functionBody();
      var returnType = node.functionReturnType();
      var oldUnsafeAllowed = context.isUnsafeAllowed;
      context.isUnsafeAllowed = node.isUnsafe();
      resolveAsType(context, returnType, symbol.scope.parent);
      var argumentCount = 0;
      var child = node.firstChild;

      while (child !== returnType) {
        __declare.assert(child.kind === 2);
        __declare.assert(child.symbol.kind === 6);
        initializeSymbol(context, child.symbol);
        child.symbol.offset = argumentCount;
        argumentCount = argumentCount + 1 | 0;
        child = child.nextSibling;
      }

      if (symbol.kind !== 4) {
        forbidFlag(context, node, 8, "Cannot use 'get' here");
        forbidFlag(context, node, 512, "Cannot use 'set' here");
        forbidFlag(context, node, 256, "Cannot use 'public' here");
        forbidFlag(context, node, 64, "Cannot use 'private' here");
      }

      else if (node.isGet()) {
        forbidFlag(context, node, 512, "Cannot use both 'get' and 'set'");

        if (argumentCount !== 1) {
          context.log.error(symbol.range, "Getters must not have any arguments");
        }
      }

      else if (node.isSet()) {
        symbol.rename = StringBuilder_new().append("set_").append(symbol.name).finish();

        if (argumentCount !== 2) {
          context.log.error(symbol.range, "Setters must have exactly one argument");
        }
      }

      else if (node.isOperator()) {
        if (symbol.name === "~" || symbol.name === "++" || symbol.name === "--") {
          if (argumentCount !== 1) {
            context.log.error(symbol.range, StringBuilder_new().append("Operator '").append(symbol.name).append("' must not have any arguments").finish());
          }
        }

        else if (symbol.name === "+" || symbol.name === "-") {
          if (argumentCount > 2) {
            context.log.error(symbol.range, StringBuilder_new().append("Operator '").append(symbol.name).append("' must have at most one argument").finish());
          }
        }

        else if (symbol.name === "[]=") {
          if (argumentCount < 2) {
            context.log.error(symbol.range, "Operator '[]=' must have at least one argument");
          }
        }

        else if (argumentCount !== 2) {
          context.log.error(symbol.range, StringBuilder_new().append("Operator '").append(symbol.name).append("' must have exactly one argument").finish());
        }
      }

      symbol.resolvedType = new Type();
      symbol.resolvedType.symbol = symbol;

      if (symbol.kind === 4) {
        var parent = symbol.parent();
        var shouldConvertInstanceToGlobal = false;
        forbidFlag(context, node, 4, "Cannot use 'extern' on an instance function");
        forbidFlag(context, node, 1, "Cannot use 'declare' on an instance function");

        if (parent.node.isDeclare()) {
          if (body === null) {
            node.flags = node.flags | 1;
          }

          else {
            shouldConvertInstanceToGlobal = true;
          }
        }

        else {
          if (body === null) {
            context.log.error(node.lastChild.range, "Must implement this function");
          }

          if (parent.node.isExtern()) {
            node.flags = node.flags | 4;
          }
        }

        if (shouldConvertInstanceToGlobal) {
          symbol.kind = 5;
          symbol.flags = symbol.flags | 1;
          symbol.rename = StringBuilder_new().append(parent.name).appendChar(95).append(symbol.rename !== null ? symbol.rename : symbol.name).finish();
          __declare.assert(node.firstChild.symbol.name === "this");
          node.firstChild.symbol.rename = "__this";
        }
      }

      else if (body === null) {
        forbidFlag(context, node, 4, "Cannot use 'extern' on an unimplemented function");
        requireFlag(context, node, 1, "Declared functions must be prefixed with 'declare'");
      }

      else {
        forbidFlag(context, node, 1, "Cannot use 'declare' on a function with an implementation");
      }

      context.isUnsafeAllowed = oldUnsafeAllowed;
    }

    else if (isVariable(symbol.kind)) {
      forbidFlag(context, node, 8, "Cannot use 'get' on a variable");
      forbidFlag(context, node, 512, "Cannot use 'set' on a variable");
      var type = node.variableType();
      var value = node.variableValue();
      var oldUnsafeAllowed = context.isUnsafeAllowed;
      context.isUnsafeAllowed = context.isUnsafeAllowed || node.isUnsafe();

      if (symbol.kind !== 9) {
        forbidFlag(context, node, 256, "Cannot use 'public' here");
        forbidFlag(context, node, 64, "Cannot use 'private' here");
      }

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

          if (value.kind === 24 || value.kind === 18) {
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
          var shadowed = scope.findLocal(symbol.name, 0);

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

      context.isUnsafeAllowed = oldUnsafeAllowed;
    }

    else {
      __declare.assert(false);
    }

    __declare.assert(symbol.resolvedType !== null);
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
    __declare.assert(isExpression(node));
    resolve(context, node, parentScope);

    if (node.resolvedType !== context.errorType) {
      if (node.isType()) {
        context.log.error(node.range, "Expected expression but found type");
        node.resolvedType = context.errorType;
      }

      else if (node.resolvedType === context.voidType && node.parent.kind !== 10) {
        context.log.error(node.range, "This expression does not return a value");
        node.resolvedType = context.errorType;
      }
    }
  }

  function resolveAsType(context, node, parentScope) {
    __declare.assert(isExpression(node));
    resolve(context, node, parentScope);

    if (node.resolvedType !== context.errorType && !node.isType()) {
      context.log.error(node.range, "Expected type but found expression");
      node.resolvedType = context.errorType;
    }
  }

  function canConvert(context, node, to, kind) {
    var from = node.resolvedType;
    __declare.assert(isExpression(node));
    __declare.assert(from !== null);
    __declare.assert(to !== null);

    if (from === to || from === context.errorType || to === context.errorType) {
      return true;
    }

    else if (from === context.nullType && to.isReference()) {
      return true;
    }

    else if (context.isUnsafeAllowed && (from.isReference() || to.isReference())) {
      if (kind === 1) {
        return true;
      }
    }

    else if (from.isInteger() && to.isInteger()) {
      var mask = to.integerBitMask(context);

      if (from.isEnum() && to === from.underlyingType(context)) {
        return true;
      }

      if (kind === 1 || from.symbol.byteSize < to.symbol.byteSize || node.kind === 24 && (to.isUnsigned() ? node.intValue >= 0 && node.intValue >>> 0 <= mask : node.intValue >= (~mask | 0) >> 1 && node.intValue <= (mask >>> 1 | 0))) {
        return true;
      }
    }

    return false;
  }

  function checkConversion(context, node, to, kind) {
    if (!canConvert(context, node, to, kind)) {
      context.log.error(node.range, StringBuilder_new().append("Cannot convert from type '").append(node.resolvedType.toString()).append("' to type '").append(to.toString()).append(kind === 0 && canConvert(context, node, to, 1) ? "' without a cast" : "'").finish());
      node.resolvedType = context.errorType;
    }
  }

  function checkStorage(context, target) {
    __declare.assert(isExpression(target));

    if (target.resolvedType !== context.errorType && target.kind !== 23 && target.kind !== 35 && (target.kind !== 25 && target.kind !== 21 || target.symbol !== null && (!isVariable(target.symbol.kind) || target.symbol.kind === 7))) {
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

    __declare.assert(type.isReference());

    return createNull();
  }

  function simplifyBinary(node) {
    var left = node.binaryLeft();
    var right = node.binaryRight();

    if ((node.kind === 44 || node.kind === 58 || node.kind === 46 || node.kind === 47 || node.kind === 48) && left.kind === 24 && right.kind !== 24) {
      node.appendChild(left.remove());
      left = node.binaryLeft();
      right = node.binaryRight();
    }

    if ((node.kind === 58 || (node.kind === 49 || node.kind === 60) && node.resolvedType.isUnsigned()) && right.kind === 24 && isPositivePowerOf2(right.intValue)) {
      var shift = -1;
      var value = right.intValue;

      while (value !== 0) {
        value = value >> 1;
        shift = shift + 1 | 0;
      }

      if (node.kind === 58) {
        node.kind = 61;
        right.intValue = shift;
      }

      else if (node.kind === 49) {
        node.kind = 62;
        right.intValue = shift;
      }

      else if (node.kind === 60) {
        node.kind = 46;
        right.intValue = right.intValue - 1 | 0;
      }

      else {
        __declare.assert(false);
      }
    }

    else if (node.kind === 44 && right.kind === 36) {
      node.kind = 63;
      right.replaceWith(right.unaryValue().remove());
    }

    else if (node.kind === 44 && right.isNegativeInteger()) {
      node.kind = 63;
      right.intValue = -right.intValue | 0;
    }
  }

  function binaryHasUnsignedArguments(node) {
    var left = node.binaryLeft();
    var right = node.binaryRight();
    var leftType = left.resolvedType;
    var rightType = right.resolvedType;

    return leftType.isUnsigned() && rightType.isUnsigned() || leftType.isUnsigned() && right.isNonNegativeInteger() || left.isNonNegativeInteger() && rightType.isUnsigned();
  }

  function isSymbolAccessAllowed(context, symbol, node, range) {
    if (symbol.isUnsafe() && !context.isUnsafeAllowed) {
      context.log.error(range, StringBuilder_new().append("Cannot use symbol '").append(symbol.name).append("' outside an 'unsafe' block").finish());

      return false;
    }

    if (symbol.node !== null && symbol.node.isPrivate()) {
      var parent = symbol.parent();

      if (parent !== null && context.enclosingClass !== parent) {
        context.log.error(range, StringBuilder_new().append("Cannot access private symbol '").append(symbol.name).append("' here").finish());

        return false;
      }
    }

    if (isFunction(symbol.kind) && (symbol.isSetter() ? !node.isAssignTarget() : !node.isCallValue())) {
      if (symbol.isSetter()) {
        context.log.error(range, StringBuilder_new().append("Cannot use setter '").append(symbol.name).append("' here").finish());
      }

      else {
        context.log.error(range, StringBuilder_new().append("Must call function '").append(symbol.name).appendChar(39).finish());
      }

      return false;
    }

    return true;
  }

  function resolve(context, node, parentScope) {
    var kind = node.kind;
    __declare.assert(kind === 0 || parentScope !== null);

    if (node.resolvedType !== null) {
      return;
    }

    node.resolvedType = context.errorType;

    if (kind === 0 || kind === 1) {
      resolveChildren(context, node, parentScope);
    }

    else if (kind === 5) {
      var oldEnclosingClass = context.enclosingClass;
      initializeSymbol(context, node.symbol);
      context.enclosingClass = node.symbol;
      resolveChildren(context, node, node.scope);

      if (node.symbol.kind === 0) {
        node.symbol.determineClassLayout(context);
      }

      context.enclosingClass = oldEnclosingClass;
    }

    else if (kind === 9) {
      initializeSymbol(context, node.symbol);
      resolveChildren(context, node, node.scope);
    }

    else if (kind === 11) {
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

    else if (kind === 2) {
      var symbol = node.symbol;
      initializeSymbol(context, symbol);
      var oldUnsafeAllowed = context.isUnsafeAllowed;
      context.isUnsafeAllowed = context.isUnsafeAllowed || node.isUnsafe();
      var value = node.variableValue();

      if (value !== null) {
        resolveAsExpression(context, value, parentScope);
        checkConversion(context, value, symbol.resolvedTypeUnderlyingIfEnumValue(context), 0);

        if (symbol.kind === 8 && value.kind !== 24 && value.kind !== 18 && value.kind !== 27) {
          context.log.error(value.range, "Global initializers must be compile-time constants");
        }
      }

      else if (symbol.resolvedType !== context.errorType) {
        value = createDefaultValueForType(context, symbol.resolvedType);
        resolveAsExpression(context, value, parentScope);
        node.appendChild(value);
      }

      if (symbol.kind === 8 && symbol.resolvedType !== context.errorType) {
        symbol.offset = context.allocateGlobalVariableOffset(symbol.resolvedType.variableSizeOf(context), symbol.resolvedType.variableAlignmentOf(context));
      }

      context.isUnsafeAllowed = oldUnsafeAllowed;
    }

    else if (kind === 4 || kind === 7) {
      var found = false;
      var n = node;

      while (n !== null) {
        if (n.kind === 16) {
          found = true;

          break;
        }

        n = n.parent;
      }

      if (!found) {
        context.log.error(node.range, "Cannot use this statement outside of a loop");
      }
    }

    else if (kind === 3) {
      var oldUnsafeAllowed = context.isUnsafeAllowed;

      if (node.isUnsafe()) {
        context.isUnsafeAllowed = true;
      }

      resolveChildren(context, node, node.scope);
      context.isUnsafeAllowed = oldUnsafeAllowed;
    }

    else if (kind === 6 || kind === 15) {
      resolveChildren(context, node, parentScope);
    }

    else if (kind === 24) {
      node.resolvedType = node.intValue < 0 && !node.isPositive() ? context.uintType : context.intType;
    }

    else if (kind === 30) {
      node.resolvedType = context.stringType;
    }

    else if (kind === 18) {
      node.resolvedType = context.boolType;
    }

    else if (kind === 27) {
      node.resolvedType = context.nullType;
    }

    else if (kind === 23) {
      resolveChildrenAsExpressions(context, node, parentScope);
      var target = node.indexTarget();
      var type = target.resolvedType;

      if (type !== context.errorType) {
        var symbol = type.hasInstanceMembers() ? type.findMember("[]", 0) : null;

        if (symbol === null) {
          context.log.error(node.internalRange, StringBuilder_new().append("Cannot index into type '").append(target.resolvedType.toString()).appendChar(39).finish());
        }

        else {
          __declare.assert(symbol.kind === 4 || symbol.kind === 5 && symbol.shouldConvertInstanceToGlobal());
          node.kind = 19;
          target.remove();
          node.insertChildBefore(node.firstChild, createMemberReference(target, symbol));
          node.resolvedType = null;
          resolveAsExpression(context, node, parentScope);
        }
      }
    }

    else if (kind === 17) {
      var type = node.alignOfType();
      resolveAsType(context, type, parentScope);
      node.resolvedType = context.intType;

      if (type.resolvedType !== context.errorType) {
        node.becomeIntegerConstant(type.resolvedType.allocationAlignmentOf(context));
      }
    }

    else if (kind === 29) {
      var type = node.sizeOfType();
      resolveAsType(context, type, parentScope);
      node.resolvedType = context.intType;

      if (type.resolvedType !== context.errorType) {
        node.becomeIntegerConstant(type.resolvedType.allocationSizeOf(context));
      }
    }

    else if (kind === 31) {
      var symbol = parentScope.findNested("this", 0, 0);

      if (symbol === null) {
        context.log.error(node.range, "Cannot use 'this' here");
      }

      else {
        node.becomeSymbolReference(symbol);
      }
    }

    else if (kind === 28) {
      node.resolvedType = context.errorType;
    }

    else if (kind === 25) {
      var name = node.stringValue;
      var symbol = parentScope.findNested(name, 0, 0);

      if (symbol === null) {
        var builder = StringBuilder_new().append("No symbol named '").append(name).append("' here");
        symbol = parentScope.findNested(name, 0, 1);

        if (symbol !== null) {
          builder.append(", did you mean 'this.").append(symbol.name).append("'?");
        }

        else if (name === "number") {
          builder.append(", did you mean 'int'?");
        }

        else if (name === "boolean") {
          builder.append(", did you mean 'bool'?");
        }

        context.log.error(node.range, builder.finish());
      }

      else if (symbol.state === 1) {
        context.log.error(node.range, StringBuilder_new().append("Cyclic reference to symbol '").append(name).append("' here").finish());
      }

      else if (isSymbolAccessAllowed(context, symbol, node, node.range)) {
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

    else if (kind === 20) {
      var value = node.castValue();
      var type = node.castType();
      resolveAsExpression(context, value, parentScope);
      resolveAsType(context, type, parentScope);
      var castedType = type.resolvedType;
      checkConversion(context, value, castedType, 1);
      node.resolvedType = castedType;

      if (value.kind === 24 && castedType.isInteger()) {
        var result = value.intValue;
        var shift = 32 - castedType.integerBitCount(context) | 0;
        node.becomeIntegerConstant(castedType.isUnsigned() ? (castedType.integerBitMask(context) | 0) & result : result << shift >> shift);
      }
    }

    else if (kind === 21) {
      var target = node.dotTarget();
      resolve(context, target, parentScope);

      if (target.resolvedType !== context.errorType) {
        if (target.isType() && target.resolvedType.isEnum() || !target.isType() && target.resolvedType.hasInstanceMembers()) {
          var name = node.stringValue;

          if (name.length > 0) {
            var symbol = target.resolvedType.findMember(name, node.isAssignTarget() ? 6 : 5);

            if (symbol === null) {
              context.log.error(node.internalRange, StringBuilder_new().append("No member named '").append(name).append("' on type '").append(target.resolvedType.toString()).appendChar(39).finish());
            }

            else if (symbol.isGetter()) {
              node.kind = 19;
              node.appendChild(createMemberReference(target.remove(), symbol));
              node.resolvedType = null;
              resolveAsExpression(context, node, parentScope);

              return;
            }

            else if (isSymbolAccessAllowed(context, symbol, node, node.internalRange)) {
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

    else if (kind === 19) {
      var value = node.callValue();
      resolveAsExpression(context, value, parentScope);

      if (value.resolvedType !== context.errorType) {
        var symbol = value.symbol;

        if (symbol === null || !isFunction(symbol.kind)) {
          context.log.error(value.range, StringBuilder_new().append("Cannot call value of type '").append(value.resolvedType.toString()).appendChar(39).finish());
        }

        else {
          initializeSymbol(context, symbol);

          if (symbol.shouldConvertInstanceToGlobal()) {
            var name = createSymbolReference(symbol);
            node.insertChildBefore(value, name.withRange(value.internalRange));
            node.insertChildBefore(value, value.dotTarget().remove());
            value.remove();
            value = name;
          }

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

    else if (kind === 13) {
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

    else if (kind === 8) {
    }

    else if (kind === 10) {
      resolveAsExpression(context, node.expressionValue(), parentScope);
    }

    else if (kind === 16) {
      var value = node.whileValue();
      var body = node.whileBody();
      resolveAsExpression(context, value, parentScope);
      checkConversion(context, value, context.boolType, 0);
      resolve(context, body, parentScope);
    }

    else if (kind === 12) {
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

    else if (kind === 22) {
      var value = node.hookValue();
      var yes = node.hookTrue();
      var no = node.hookFalse();
      resolveAsExpression(context, value, parentScope);
      checkConversion(context, value, context.boolType, 0);
      resolve(context, yes, parentScope);
      resolve(context, no, parentScope);
      var commonType = (yes.resolvedType === context.nullType ? no : yes).resolvedType;

      if (yes.resolvedType !== commonType && (yes.resolvedType !== context.nullType || !commonType.isReference()) && no.resolvedType !== commonType && (no.resolvedType !== context.nullType || !commonType.isReference())) {
        context.log.error(spanRanges(yes.range, no.range), StringBuilder_new().append("Type '").append(yes.resolvedType.toString()).append("' is not the same as type '").append(no.resolvedType.toString()).appendChar(39).finish());
      }

      node.resolvedType = commonType;
    }

    else if (kind === 45) {
      var left = node.binaryLeft();
      var right = node.binaryRight();

      if (left.kind === 23) {
        resolveChildrenAsExpressions(context, left, parentScope);
        var target = left.indexTarget();
        var type = target.resolvedType;

        if (type !== context.errorType) {
          var symbol = type.hasInstanceMembers() ? type.findMember("[]=", 0) : null;

          if (symbol === null) {
            context.log.error(left.internalRange, StringBuilder_new().append("Cannot index into type '").append(target.resolvedType.toString()).appendChar(39).finish());
          }

          else {
            __declare.assert(symbol.kind === 4);
            node.kind = 19;
            target.remove();
            left.remove();

            while (left.lastChild !== null) {
              node.insertChildBefore(node.firstChild, left.lastChild.remove());
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

      if (left.symbol !== null && left.symbol.isSetter()) {
        node.kind = 19;
        node.internalRange = left.internalRange;
        node.resolvedType = null;
        resolveAsExpression(context, node, parentScope);

        return;
      }

      resolveAsExpression(context, right, parentScope);
      checkConversion(context, right, left.resolvedType, 0);
      checkStorage(context, left);
      node.resolvedType = left.resolvedType;
    }

    else if (kind === 26) {
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

    else if (kind === 38) {
      var value = node.unaryValue();
      resolveAsType(context, value, parentScope);

      if (context.target === 2) {
        context.log.error(node.internalRange, "Cannot use pointers when compiling to JavaScript");
      }

      else if (!context.isUnsafeAllowed) {
        context.log.error(node.internalRange, "Cannot use pointers outside an 'unsafe' block");
      }

      else {
        var type = value.resolvedType;

        if (type !== context.errorType) {
          if (!type.isInteger() && type.pointerTo === null) {
            context.log.error(node.internalRange, StringBuilder_new().append("Cannot create a pointer to non-integer type '").append(type.toString()).appendChar(39).finish());
          }

          else {
            node.resolvedType = type.pointerType();
          }
        }
      }
    }

    else if (kind === 35) {
      var value = node.unaryValue();
      resolveAsExpression(context, value, parentScope);
      var type = value.resolvedType;

      if (type !== context.errorType) {
        if (type.pointerTo === null) {
          context.log.error(node.internalRange, StringBuilder_new().append("Cannot dereference type '").append(type.toString()).appendChar(39).finish());
        }

        else {
          node.resolvedType = type.pointerTo;
        }
      }
    }

    else if (kind === 33) {
      var value = node.unaryValue();
      resolveAsExpression(context, value, parentScope);
      context.log.error(node.internalRange, "The address-of operator is not supported");
    }

    else if (isUnary(kind)) {
      var value = node.unaryValue();
      resolveAsExpression(context, value, parentScope);

      if (kind === 37) {
        checkConversion(context, value, context.boolType, 0);
        node.resolvedType = context.boolType;
      }

      else if (value.resolvedType.isInteger()) {
        if (value.resolvedType.isUnsigned()) {
          node.flags = node.flags | 4096;
          node.resolvedType = context.uintType;
        }

        else {
          node.resolvedType = context.intType;
        }

        if (value.kind === 24) {
          var input = value.intValue;
          var output = input;

          if (kind === 34) {
            output = ~input;
          }

          else if (kind === 36) {
            output = -input | 0;
          }

          node.becomeIntegerConstant(output);
        }
      }

      else if (value.resolvedType !== context.errorType) {
        var name = node.internalRange.toString();
        var symbol = value.resolvedType.findMember(name, 1);

        if (symbol !== null) {
          node.appendChild(createMemberReference(value.remove(), symbol).withRange(node.range).withInternalRange(node.internalRange));
          node.kind = 19;
          node.resolvedType = null;
          resolveAsExpression(context, node, parentScope);
        }

        else {
          context.log.error(node.internalRange, StringBuilder_new().append("Cannot use unary operator '").append(name).append("' with type '").append(value.resolvedType.toString()).appendChar(39).finish());
        }
      }
    }

    else if (isBinary(kind)) {
      var left = node.binaryLeft();
      var right = node.binaryRight();
      resolveAsExpression(context, left, parentScope);
      resolveAsExpression(context, right, parentScope);
      var leftType = left.resolvedType;
      var rightType = right.resolvedType;

      if (kind === 57 || kind === 56) {
        checkConversion(context, left, context.boolType, 0);
        checkConversion(context, right, context.boolType, 0);
        node.resolvedType = context.boolType;
      }

      else if (kind === 44 && leftType.pointerTo !== null && rightType.isInteger()) {
        node.resolvedType = leftType;
      }

      else if ((kind === 54 || kind === 55 || kind === 52 || kind === 53) && (leftType.pointerTo !== null || rightType.pointerTo !== null)) {
        node.resolvedType = context.boolType;

        if (leftType !== rightType) {
          context.log.error(node.internalRange, StringBuilder_new().append("Cannot compare type '").append(leftType.toString()).append("' with type '").append(rightType.toString()).appendChar(39).finish());
        }
      }

      else if (leftType.isInteger() && kind !== 50 && kind !== 59) {
        if (kind === 44 || kind === 63 || kind === 58 || kind === 49 || kind === 60 || kind === 46 || kind === 47 || kind === 48 || kind === 61 || kind === 62) {
          var isUnsigned = binaryHasUnsignedArguments(node);
          var commonType = isUnsigned ? context.uintType : context.intType;

          if (isUnsigned) {
            node.flags = node.flags | 4096;
          }

          checkConversion(context, left, commonType, 0);
          checkConversion(context, right, commonType, 0);
          node.resolvedType = commonType;

          if (left.kind === 24 && right.kind === 24) {
            var inputLeft = left.intValue;
            var inputRight = right.intValue;
            var output = 0;

            if (kind === 44) {
              output = inputLeft + inputRight | 0;
            }

            else if (kind === 46) {
              output = inputLeft & inputRight;
            }

            else if (kind === 47) {
              output = inputLeft | inputRight;
            }

            else if (kind === 48) {
              output = inputLeft ^ inputRight;
            }

            else if (kind === 49) {
              output = inputLeft / inputRight | 0;
            }

            else if (kind === 58) {
              output = __imul(inputLeft, inputRight);
            }

            else if (kind === 60) {
              output = inputLeft % inputRight | 0;
            }

            else if (kind === 61) {
              output = inputLeft << inputRight;
            }

            else if (kind === 62) {
              output = isUnsigned ? inputLeft >>> 0 >>> (inputRight >>> 0) | 0 : inputLeft >> inputRight;
            }

            else if (kind === 63) {
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

        else if (kind === 54 || kind === 55 || kind === 52 || kind === 53) {
          var expectedType = binaryHasUnsignedArguments(node) ? context.uintType : context.intType;

          if (expectedType === context.uintType) {
            node.flags = node.flags | 4096;
          }

          if (leftType !== rightType) {
            checkConversion(context, left, expectedType, 0);
            checkConversion(context, right, expectedType, 0);
          }

          node.resolvedType = context.boolType;
        }

        else {
          context.log.error(node.internalRange, "This operator is not currently supported");
        }
      }

      else if (leftType !== context.errorType) {
        var name = node.internalRange.toString();
        var symbol = leftType.findMember(kind === 59 ? "==" : kind === 55 ? ">" : kind === 53 ? "<" : name, 4);

        if (symbol !== null) {
          left = createMemberReference(left.remove(), symbol).withRange(node.range).withInternalRange(node.internalRange);
          right.remove();

          if (kind === 59 || kind === 55 || kind === 53) {
            var call = createCall(left);
            call.appendChild(right);
            node.kind = 37;
            node.appendChild(call.withRange(node.range).withInternalRange(node.range));
          }

          else {
            node.appendChild(left);
            node.appendChild(right);
            node.kind = 19;
          }

          node.resolvedType = null;
          resolveAsExpression(context, node, parentScope);
        }

        else if (kind === 50 || kind === 59) {
          node.resolvedType = context.boolType;

          if (leftType !== context.errorType && rightType !== context.errorType && leftType !== rightType && !canConvert(context, right, leftType, 0) && !canConvert(context, left, rightType, 0)) {
            context.log.error(node.internalRange, StringBuilder_new().append("Cannot compare type '").append(leftType.toString()).append("' with type '").append(rightType.toString()).appendChar(39).finish());
          }
        }

        else {
          context.log.error(node.internalRange, StringBuilder_new().append("Cannot use binary operator '").append(name).append("' with type '").append(leftType.toString()).appendChar(39).finish());
        }
      }
    }

    else {
      __declare.assert(false);
    }
  }

  function Compiler() {
    this.log = null;
    this.global = null;
    this.firstSource = null;
    this.lastSource = null;
    this.preprocessor = null;
    this.target = 0;
    this.context = null;
    this.librarySource = null;
    this.output_wasm = null;
    this.output_js = null;
    this.output_c = null;
  }

  Compiler.prototype.initialize = function(target) {
    __declare.assert(this.log === null);
    this.log = new Log();
    this.preprocessor = new Preprocessor();
    this.target = target;
    this.librarySource = this.addInput("<native>", library());
    this.librarySource.isLibrary = true;
    this.createGlobals();

    if (target === 1) {
      this.preprocessor.define("C", true);
    }

    else if (target === 2) {
      this.preprocessor.define("JS", true);
    }

    else if (target === 3) {
      this.preprocessor.define("WASM", true);
    }
  };

  Compiler.prototype.createGlobals = function() {
    var context = new CheckContext();
    context.log = this.log;
    context.target = this.target;
    context.pointerByteSize = 4;
    var global = new Node();
    global.kind = 1;
    var scope = new Scope();
    global.scope = scope;
    context.errorType = scope.defineNativeType(context.log, "<error>");
    context.nullType = scope.defineNativeType(context.log, "null");
    context.voidType = scope.defineNativeType(context.log, "void");
    this.context = context;
    this.global = global;
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

    return source;
  };

  Compiler.prototype.finish = function() {
    __declare.Profiler_begin();
    var source = this.firstSource;

    while (source !== null) {
      source.firstToken = tokenize(source, this.log);
      source = source.next;
    }

    __declare.Profiler_end("lexing");
    __declare.Profiler_begin();
    source = this.firstSource;

    while (source !== null) {
      this.preprocessor.run(source, this.log);
      source = source.next;
    }

    __declare.Profiler_end("preprocessing");
    __declare.Profiler_begin();
    source = this.firstSource;

    while (source !== null) {
      if (source.firstToken !== null) {
        source.file = parse(source.firstToken, this.log);
      }

      source = source.next;
    }

    __declare.Profiler_end("parsing");
    __declare.Profiler_begin();
    var global = this.global;
    var context = this.context;
    source = this.firstSource;

    while (source !== null) {
      var file = source.file;

      if (file !== null) {
        if (source === this.librarySource) {
          initialize(context, file, global.scope, 1);
          resolve(context, file, global.scope);
        }

        else {
          initialize(context, file, global.scope, 0);
        }

        while (file.firstChild !== null) {
          var child = file.firstChild;
          child.remove();
          global.appendChild(child);
        }
      }

      source = source.next;
    }

    resolve(context, global, global.scope);
    __declare.Profiler_end("checking");

    if (this.log.hasErrors()) {
      return false;
    }

    __declare.Profiler_begin();
    treeShaking(global);
    __declare.Profiler_end("shaking");
    __declare.Profiler_begin();

    if (this.target === 1) {
      cEmit(this);
    }

    else if (this.target === 2) {
      jsEmit(this);
    }

    else if (this.target === 3) {
      wasmEmit(this);
    }

    __declare.Profiler_end("emitting");

    return true;
  };

  function isPositivePowerOf2(value) {
    return value > 0 && (value & value - 1) === 0;
  }

  function alignToNextMultipleOf(offset, alignment) {
    __declare.assert(isPositivePowerOf2(alignment));

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
      this.code.append("  ");
      i = i - 1 | 0;
    }
  };

  JsResult.prototype.emitNewlineBefore = function(node) {
    if (this.previousNode !== null && (!isCompactNodeKind(this.previousNode.kind) || !isCompactNodeKind(node.kind))) {
      this.code.appendChar(10);
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
    this.code.append("{\n");
    this.indent = this.indent + 1 | 0;
    this.emitStatements(node.firstChild);
    this.indent = this.indent - 1 | 0;
    this.emitIndent();
    this.code.appendChar(125);
    this.previousNode = null;
  };

  JsResult.prototype.emitUnary = function(node, parentPrecedence, operator) {
    var isPostfix = isUnaryPostfix(node.kind);
    var shouldCastToInt = node.kind === 36 && !jsKindCastsOperandsToInt(node.parent.kind);
    var isUnsigned = node.isUnsignedOperator();
    var operatorPrecedence = shouldCastToInt ? isUnsigned ? 9 : 4 : isPostfix ? 14 : 13;
    var code = this.code;

    if (parentPrecedence > operatorPrecedence) {
      code.appendChar(40);
    }

    if (!isPostfix) {
      code.append(operator);
    }

    this.emitExpression(node.unaryValue(), operatorPrecedence);

    if (isPostfix) {
      code.append(operator);
    }

    if (shouldCastToInt) {
      code.append(isUnsigned ? " >>> 0" : " | 0");
    }

    if (parentPrecedence > operatorPrecedence) {
      code.appendChar(41);
    }
  };

  JsResult.prototype.emitBinary = function(node, parentPrecedence, operator, operatorPrecedence, mode) {
    var isRightAssociative = node.kind === 45;
    var isUnsigned = node.isUnsignedOperator();
    var code = this.code;
    var shouldCastToInt = mode === 1 && (isUnsigned || !jsKindCastsOperandsToInt(node.parent.kind));
    var selfPrecedence = shouldCastToInt ? isUnsigned ? 9 : 4 : parentPrecedence;

    if (parentPrecedence > selfPrecedence) {
      code.appendChar(40);
    }

    if (selfPrecedence > operatorPrecedence) {
      code.appendChar(40);
    }

    this.emitExpression(node.binaryLeft(), isRightAssociative ? operatorPrecedence + 1 | 0 : operatorPrecedence);
    code.append(operator);
    this.emitExpression(node.binaryRight(), isRightAssociative ? operatorPrecedence : operatorPrecedence + 1 | 0);

    if (selfPrecedence > operatorPrecedence) {
      code.appendChar(41);
    }

    if (shouldCastToInt) {
      code.append(isUnsigned ? " >>> 0" : " | 0");
    }

    if (parentPrecedence > selfPrecedence) {
      code.appendChar(41);
    }
  };

  JsResult.prototype.emitCommaSeparatedExpressions = function(start, stop) {
    while (start !== stop) {
      this.emitExpression(start, 0);
      start = start.nextSibling;

      if (start !== stop) {
        this.code.append(", ");
      }
    }
  };

  JsResult.prototype.emitExpression = function(node, parentPrecedence) {
    var code = this.code;

    if (node.kind === 25) {
      var symbol = node.symbol;

      if (symbol.kind === 5 && symbol.node.isDeclare()) {
        code.append("__declare.");
      }

      this.emitSymbolName(symbol);
    }

    else if (node.kind === 27) {
      code.append("null");
    }

    else if (node.kind === 18) {
      code.append(node.intValue !== 0 ? "true" : "false");
    }

    else if (node.kind === 24) {
      if (parentPrecedence === 15) {
        code.appendChar(40);
      }

      code.append(node.resolvedType.isUnsigned() ? (node.intValue >>> 0).toString() : node.intValue.toString());

      if (parentPrecedence === 15) {
        code.appendChar(41);
      }
    }

    else if (node.kind === 30) {
      StringBuilder_appendQuoted(code, node.stringValue);
    }

    else if (node.kind === 20) {
      var context = this.context;
      var value = node.castValue();
      var from = value.resolvedType.underlyingType(context);
      var type = node.resolvedType.underlyingType(context);
      var fromSize = from.variableSizeOf(context);
      var typeSize = type.variableSizeOf(context);

      if (from === type || fromSize < typeSize) {
        this.emitExpression(value, parentPrecedence);
      }

      else if (type === context.sbyteType || type === context.shortType) {
        if (parentPrecedence > 9) {
          code.appendChar(40);
        }

        var shift = (32 - (typeSize << 3) | 0).toString();
        this.emitExpression(value, 9);
        code.append(" << ");
        code.append(shift);
        code.append(" >> ");
        code.append(shift);

        if (parentPrecedence > 9) {
          code.appendChar(41);
        }
      }

      else if (type === context.byteType || type === context.ushortType) {
        if (parentPrecedence > 6) {
          code.appendChar(40);
        }

        this.emitExpression(value, 6);
        code.append(" & ");
        code.append(type.integerBitMask(context).toString());

        if (parentPrecedence > 6) {
          code.appendChar(41);
        }
      }

      else if (type === context.intType) {
        if (parentPrecedence > 4) {
          code.appendChar(40);
        }

        this.emitExpression(value, 4);
        code.append(" | 0");

        if (parentPrecedence > 4) {
          code.appendChar(41);
        }
      }

      else if (type === context.uintType) {
        if (parentPrecedence > 9) {
          code.appendChar(40);
        }

        this.emitExpression(value, 9);
        code.append(" >>> 0");

        if (parentPrecedence > 9) {
          code.appendChar(41);
        }
      }

      else {
        this.emitExpression(value, parentPrecedence);
      }
    }

    else if (node.kind === 21) {
      this.emitExpression(node.dotTarget(), 15);
      code.appendChar(46);
      this.emitSymbolName(node.symbol);
    }

    else if (node.kind === 22) {
      if (parentPrecedence > 1) {
        code.appendChar(40);
      }

      this.emitExpression(node.hookValue(), 2);
      code.append(" ? ");
      this.emitExpression(node.hookTrue(), 1);
      code.append(" : ");
      this.emitExpression(node.hookFalse(), 1);

      if (parentPrecedence > 1) {
        code.appendChar(41);
      }
    }

    else if (node.kind === 23) {
      var value = node.indexTarget();
      this.emitExpression(value, 14);
      code.appendChar(91);
      this.emitCommaSeparatedExpressions(value.nextSibling, null);
      code.appendChar(93);
    }

    else if (node.kind === 19) {
      if (node.expandCallIntoOperatorTree()) {
        this.emitExpression(node, parentPrecedence);
      }

      else {
        var value = node.callValue();
        this.emitExpression(value, 14);

        if (value.symbol === null || !value.symbol.isGetter()) {
          code.appendChar(40);
          this.emitCommaSeparatedExpressions(value.nextSibling, null);
          code.appendChar(41);
        }
      }
    }

    else if (node.kind === 26) {
      code.append("new ");
      this.emitExpression(node.newType(), 14);
      code.append("()");
    }

    else if (node.kind === 37) {
      var value = node.unaryValue();
      value.expandCallIntoOperatorTree();
      var invertedKind = invertedBinaryKind(value.kind);

      if (invertedKind !== value.kind) {
        value.kind = invertedKind;
        this.emitExpression(value, parentPrecedence);
      }

      else {
        this.emitUnary(node, parentPrecedence, "!");
      }
    }

    else if (node.kind === 34) {
      this.emitUnary(node, parentPrecedence, "~");
    }

    else if (node.kind === 36) {
      this.emitUnary(node, parentPrecedence, "-");
    }

    else if (node.kind === 39) {
      this.emitUnary(node, parentPrecedence, "+");
    }

    else if (node.kind === 43) {
      this.emitUnary(node, parentPrecedence, "++");
    }

    else if (node.kind === 42) {
      this.emitUnary(node, parentPrecedence, "--");
    }

    else if (node.kind === 41) {
      this.emitUnary(node, parentPrecedence, "++");
    }

    else if (node.kind === 40) {
      this.emitUnary(node, parentPrecedence, "--");
    }

    else if (node.kind === 44) {
      this.emitBinary(node, parentPrecedence, " + ", 10, 1);
    }

    else if (node.kind === 45) {
      this.emitBinary(node, parentPrecedence, " = ", 1, 0);
    }

    else if (node.kind === 46) {
      this.emitBinary(node, parentPrecedence, " & ", 6, 0);
    }

    else if (node.kind === 47) {
      this.emitBinary(node, parentPrecedence, " | ", 4, 0);
    }

    else if (node.kind === 48) {
      this.emitBinary(node, parentPrecedence, " ^ ", 5, 0);
    }

    else if (node.kind === 49) {
      this.emitBinary(node, parentPrecedence, " / ", 11, 1);
    }

    else if (node.kind === 50) {
      this.emitBinary(node, parentPrecedence, " === ", 7, 0);
    }

    else if (node.kind === 52) {
      this.emitBinary(node, parentPrecedence, " > ", 8, 0);
    }

    else if (node.kind === 53) {
      this.emitBinary(node, parentPrecedence, " >= ", 8, 0);
    }

    else if (node.kind === 54) {
      this.emitBinary(node, parentPrecedence, " < ", 8, 0);
    }

    else if (node.kind === 55) {
      this.emitBinary(node, parentPrecedence, " <= ", 8, 0);
    }

    else if (node.kind === 56) {
      this.emitBinary(node, parentPrecedence, " && ", 3, 0);
    }

    else if (node.kind === 57) {
      this.emitBinary(node, parentPrecedence, " || ", 2, 0);
    }

    else if (node.kind === 59) {
      this.emitBinary(node, parentPrecedence, " !== ", 7, 0);
    }

    else if (node.kind === 60) {
      this.emitBinary(node, parentPrecedence, " % ", 11, 1);
    }

    else if (node.kind === 61) {
      this.emitBinary(node, parentPrecedence, " << ", 9, 0);
    }

    else if (node.kind === 62) {
      this.emitBinary(node, parentPrecedence, node.isUnsignedOperator() ? " >>> " : " >> ", 9, 0);
    }

    else if (node.kind === 63) {
      this.emitBinary(node, parentPrecedence, " - ", 10, 1);
    }

    else if (node.kind === 58) {
      var left = node.binaryLeft();
      var right = node.binaryRight();
      var isUnsigned = node.isUnsignedOperator();

      if (isUnsigned && parentPrecedence > 9) {
        code.appendChar(40);
      }

      code.append("__imul(");
      this.emitExpression(left, 0);
      code.append(", ");
      this.emitExpression(right, 0);
      code.appendChar(41);
      this.foundMultiply = true;

      if (isUnsigned) {
        code.append(" >>> 0");

        if (parentPrecedence > 9) {
          code.appendChar(41);
        }
      }
    }

    else {
      __declare.assert(false);
    }
  };

  JsResult.prototype.emitSymbolName = function(symbol) {
    this.code.append(symbol.rename !== null ? symbol.rename : symbol.name);
  };

  JsResult.prototype.emitStatement = function(node) {
    var code = this.code;

    if (node.kind === 11) {
      var body = node.functionBody();

      if (body === null) {
        return;
      }

      var symbol = node.symbol;
      var needsSemicolon = false;
      this.emitNewlineBefore(node);
      this.emitIndent();

      if (symbol.kind === 4) {
        this.emitSymbolName(symbol.parent());
        code.append(".prototype.");
        this.emitSymbolName(symbol);
        code.append(" = function");
        needsSemicolon = true;
      }

      else if (node.isExtern()) {
        code.append("var ");
        this.emitSymbolName(symbol);
        code.append(" = __extern.");
        this.emitSymbolName(symbol);
        code.append(" = function");
        needsSemicolon = true;
      }

      else {
        code.append("function ");
        this.emitSymbolName(symbol);
      }

      code.appendChar(40);
      var returnType = node.functionReturnType();
      var child = node.functionFirstArgumentIgnoringThis();

      while (child !== returnType) {
        __declare.assert(child.kind === 2);
        this.emitSymbolName(child.symbol);
        child = child.nextSibling;

        if (child !== returnType) {
          code.append(", ");
        }
      }

      code.append(") ");
      this.emitBlock(node.functionBody());
      code.append(needsSemicolon ? ";\n" : "\n");
      this.emitNewlineAfter(node);
    }

    else if (node.kind === 12) {
      this.emitNewlineBefore(node);
      this.emitIndent();

      while (true) {
        code.append("if (");
        this.emitExpression(node.ifValue(), 0);
        code.append(") ");
        this.emitBlock(node.ifTrue());
        var no = node.ifFalse();

        if (no === null) {
          code.appendChar(10);

          break;
        }

        code.append("\n\n");
        this.emitIndent();
        code.append("else ");

        if (no.firstChild === null || no.firstChild !== no.lastChild || no.firstChild.kind !== 12) {
          this.emitBlock(no);
          code.appendChar(10);

          break;
        }

        node = no.firstChild;
      }

      this.emitNewlineAfter(node);
    }

    else if (node.kind === 16) {
      this.emitNewlineBefore(node);
      this.emitIndent();
      code.append("while (");
      this.emitExpression(node.whileValue(), 0);
      code.append(") ");
      this.emitBlock(node.whileBody());
      code.appendChar(10);
      this.emitNewlineAfter(node);
    }

    else if (node.kind === 4) {
      this.emitNewlineBefore(node);
      this.emitIndent();
      code.append("break;\n");
      this.emitNewlineAfter(node);
    }

    else if (node.kind === 7) {
      this.emitNewlineBefore(node);
      this.emitIndent();
      code.append("continue;\n");
      this.emitNewlineAfter(node);
    }

    else if (node.kind === 10) {
      this.emitNewlineBefore(node);
      this.emitIndent();
      this.emitExpression(node.expressionValue(), 0);
      code.append(";\n");
      this.emitNewlineAfter(node);
    }

    else if (node.kind === 8) {
    }

    else if (node.kind === 13) {
      var value = node.returnValue();
      this.emitNewlineBefore(node);
      this.emitIndent();

      if (value !== null) {
        code.append("return ");
        this.emitExpression(value, 0);
        code.append(";\n");
      }

      else {
        code.append("return;\n");
      }

      this.emitNewlineAfter(node);
    }

    else if (node.kind === 3) {
      if (node.parent.kind === 3) {
        this.emitStatements(node.firstChild);
      }

      else {
        this.emitNewlineBefore(node);
        this.emitIndent();
        this.emitBlock(node);
        code.appendChar(10);
        this.emitNewlineAfter(node);
      }
    }

    else if (node.kind === 15) {
      this.emitNewlineBefore(node);
      this.emitIndent();
      code.append("var ");
      var child = node.firstChild;

      while (child !== null) {
        var value = child.variableValue();
        this.emitSymbolName(child.symbol);
        child = child.nextSibling;

        if (child !== null) {
          code.append(", ");
        }

        __declare.assert(value !== null);
        code.append(" = ");
        this.emitExpression(value, 0);
      }

      code.append(";\n");
      this.emitNewlineAfter(node);
    }

    else if (node.kind === 5) {
      if (!node.isDeclare()) {
        this.emitNewlineBefore(node);
        this.emitIndent();
        code.append("function ");
        this.emitSymbolName(node.symbol);
        code.append("() {\n");
        this.indent = this.indent + 1 | 0;
        var argument = node.firstChild;

        while (argument !== null) {
          if (argument.kind === 2) {
            this.emitIndent();
            code.append("this.");
            this.emitSymbolName(argument.symbol);
            code.append(" = ");
            this.emitExpression(argument.variableValue(), 0);
            code.append(";\n");
          }

          argument = argument.nextSibling;
        }

        this.indent = this.indent - 1 | 0;
        this.emitIndent();
        code.append("}\n");
        this.emitNewlineAfter(node);
      }

      var child = node.firstChild;

      while (child !== null) {
        if (child.kind === 11) {
          this.emitStatement(child);
        }

        child = child.nextSibling;
      }
    }

    else if (node.kind === 9) {
      if (node.isExtern()) {
        this.emitNewlineBefore(node);
        this.emitIndent();
        code.append("__extern.");
        this.emitSymbolName(node.symbol);
        code.append(" = {\n");
        this.indent = this.indent + 1 | 0;
        var child = node.firstChild;

        while (child !== null) {
          __declare.assert(child.kind === 2);
          this.emitIndent();
          this.emitSymbolName(child.symbol);
          code.append(": ");
          code.append(child.symbol.offset.toString());
          child = child.nextSibling;
          code.append(child !== null ? ",\n" : "\n");
        }

        this.indent = this.indent - 1 | 0;
        this.emitIndent();
        code.append("};\n");
        this.emitNewlineAfter(node);
      }
    }

    else if (node.kind === 6) {
    }

    else {
      __declare.assert(false);
    }
  };

  function jsKindCastsOperandsToInt(kind) {
    return kind === 61 || kind === 62 || kind === 47 || kind === 46 || kind === 48;
  }

  function jsEmit(compiler) {
    var code = StringBuilder_new();
    var result = new JsResult();
    result.context = compiler.context;
    result.code = code;
    code.append("(function(__declare, __extern) {\n");
    result.indent = 1;
    result.emitStatements(compiler.global.firstChild);

    if (result.foundMultiply) {
      code.appendChar(10);
      result.emitIndent();
      code.append("var __imul = Math.imul || function(a, b) {\n");
      result.indent = 2;
      result.emitIndent();
      code.append("return (a * (b >>> 16) << 16) + a * (b & 65535) | 0;\n");
      result.indent = 1;
      result.emitIndent();
      code.append("};\n");
    }

    code.append("}(\n");
    result.emitIndent();
    code.append("typeof global !== 'undefined' ? global : this,\n");
    result.emitIndent();
    code.append("typeof exports !== 'undefined' ? exports : this\n");
    code.append("));\n");
    compiler.output_js = code.finish();
  }

  function isKeyword(kind) {
    return kind >= 40 && kind <= 72;
  }

  function Token() {
    this.kind = 0;
    this.range = null;
    this.next = null;
  }

  function splitToken(first, firstKind, secondKind) {
    var range = first.range;
    __declare.assert((range.end - range.start | 0) >= 2);
    var second = new Token();
    second.kind = secondKind;
    second.range = createRange(range.source, range.start + 1 | 0, range.end);
    second.next = first.next;
    first.kind = firstKind;
    first.next = second;
    range.end = range.start + 1 | 0;
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
      return "'**'";
    }

    if (token === 16) {
      return "'>'";
    }

    if (token === 17) {
      return "'>='";
    }

    if (token === 18) {
      return "'{'";
    }

    if (token === 19) {
      return "'['";
    }

    if (token === 20) {
      return "'('";
    }

    if (token === 21) {
      return "'<'";
    }

    if (token === 22) {
      return "'<='";
    }

    if (token === 23) {
      return "'&&'";
    }

    if (token === 24) {
      return "'||'";
    }

    if (token === 25) {
      return "'-'";
    }

    if (token === 26) {
      return "'--'";
    }

    if (token === 27) {
      return "'*'";
    }

    if (token === 28) {
      return "'!'";
    }

    if (token === 29) {
      return "'!='";
    }

    if (token === 30) {
      return "'+'";
    }

    if (token === 31) {
      return "'++'";
    }

    if (token === 32) {
      return "'?'";
    }

    if (token === 33) {
      return "'%'";
    }

    if (token === 34) {
      return "'}'";
    }

    if (token === 35) {
      return "']'";
    }

    if (token === 36) {
      return "')'";
    }

    if (token === 37) {
      return "';'";
    }

    if (token === 38) {
      return "'<<'";
    }

    if (token === 39) {
      return "'>>'";
    }

    if (token === 40) {
      return "'alignof'";
    }

    if (token === 41) {
      return "'as'";
    }

    if (token === 42) {
      return "'break'";
    }

    if (token === 43) {
      return "'class'";
    }

    if (token === 44) {
      return "'const'";
    }

    if (token === 45) {
      return "'continue'";
    }

    if (token === 46) {
      return "'declare'";
    }

    if (token === 47) {
      return "'else'";
    }

    if (token === 48) {
      return "'enum'";
    }

    if (token === 49) {
      return "'export'";
    }

    if (token === 50) {
      return "'extends'";
    }

    if (token === 51) {
      return "'extern'";
    }

    if (token === 52) {
      return "'false'";
    }

    if (token === 53) {
      return "'function'";
    }

    if (token === 54) {
      return "'if'";
    }

    if (token === 55) {
      return "'implements'";
    }

    if (token === 56) {
      return "'import'";
    }

    if (token === 57) {
      return "'interface'";
    }

    if (token === 58) {
      return "'let'";
    }

    if (token === 59) {
      return "'new'";
    }

    if (token === 60) {
      return "'null'";
    }

    if (token === 61) {
      return "'operator'";
    }

    if (token === 62) {
      return "'private'";
    }

    if (token === 63) {
      return "'protected'";
    }

    if (token === 64) {
      return "'public'";
    }

    if (token === 65) {
      return "'return'";
    }

    if (token === 66) {
      return "'sizeof'";
    }

    if (token === 67) {
      return "'static'";
    }

    if (token === 68) {
      return "'this'";
    }

    if (token === 69) {
      return "'true'";
    }

    if (token === 70) {
      return "'unsafe'";
    }

    if (token === 71) {
      return "'var'";
    }

    if (token === 72) {
      return "'while'";
    }

    if (token === 73) {
      return "'#define'";
    }

    if (token === 74) {
      return "'#elif'";
    }

    if (token === 75) {
      return "'#else'";
    }

    if (token === 76) {
      return "'#endif'";
    }

    if (token === 77) {
      return "'#error'";
    }

    if (token === 78) {
      return "'#if'";
    }

    if (token === 80) {
      return "newline";
    }

    if (token === 81) {
      return "'#undef'";
    }

    if (token === 82) {
      return "'#warning'";
    }

    __declare.assert(false);

    return null;
  }

  function isAlpha(c) {
    return c >= 97 && c <= 122 || c >= 65 && c <= 90 || c === 95;
  }

  function isASCII(c) {
    return c >= 32 && c <= 126;
  }

  function isNumber(c) {
    return c >= 48 && c <= 57;
  }

  function isDigit(c, base) {
    if (base === 16) {
      return isNumber(c) || c >= 65 && c <= 70 || c >= 97 && c <= 102;
    }

    return c >= 48 && c < base + 48 >>> 0;
  }

  function tokenize(source, log) {
    var first = null;
    var last = null;
    var contents = source.contents;
    var limit = contents.length;
    var needsPreprocessor = false;
    var wantNewline = false;
    var i = 0;

    while (i < limit) {
      var start = i;
      var c = string_op_get(contents, i);
      i = i + 1 | 0;

      if (c === 32 || c === 9 || c === 13) {
        continue;
      }

      var kind = 0;

      if (c === 10) {
        if (!wantNewline) {
          continue;
        }

        kind = 80;
        wantNewline = false;
      }

      else if (isAlpha(c)) {
        kind = 2;

        while (i < limit && (isAlpha(string_op_get(contents, i)) || isNumber(string_op_get(contents, i)))) {
          i = i + 1 | 0;
        }

        var length = i - start | 0;

        if (length >= 2 && length <= 10) {
          var text = contents.slice(start, i);

          if (length === 2) {
            if (text === "as") {
              kind = 41;
            }

            else if (text === "if") {
              kind = 54;
            }
          }

          else if (length === 3) {
            if (text === "let") {
              kind = 58;
            }

            else if (text === "new") {
              kind = 59;
            }

            else if (text === "var") {
              kind = 71;
            }
          }

          else if (length === 4) {
            if (text === "else") {
              kind = 47;
            }

            else if (text === "enum") {
              kind = 48;
            }

            else if (text === "null") {
              kind = 60;
            }

            else if (text === "this") {
              kind = 68;
            }

            else if (text === "true") {
              kind = 69;
            }
          }

          else if (length === 5) {
            if (text === "break") {
              kind = 42;
            }

            else if (text === "class") {
              kind = 43;
            }

            else if (text === "const") {
              kind = 44;
            }

            else if (text === "false") {
              kind = 52;
            }

            else if (text === "while") {
              kind = 72;
            }
          }

          else if (length === 6) {
            if (text === "export") {
              kind = 49;
            }

            else if (text === "extern") {
              kind = 51;
            }

            else if (text === "import") {
              kind = 56;
            }

            else if (text === "public") {
              kind = 64;
            }

            else if (text === "return") {
              kind = 65;
            }

            else if (text === "sizeof") {
              kind = 66;
            }

            else if (text === "static") {
              kind = 67;
            }

            else if (text === "unsafe") {
              kind = 70;
            }
          }

          else if (length === 7) {
            if (text === "alignof") {
              kind = 40;
            }

            else if (text === "declare") {
              kind = 46;
            }

            else if (text === "extends") {
              kind = 50;
            }

            else if (text === "private") {
              kind = 62;
            }
          }

          else if (text === "continue") {
            kind = 45;
          }

          else if (text === "function") {
            kind = 53;
          }

          else if (text === "implements") {
            kind = 55;
          }

          else if (text === "interface") {
            kind = 57;
          }

          else if (text === "protected") {
            kind = 63;
          }
        }
      }

      else if (isNumber(c)) {
        kind = 3;

        if (i < limit) {
          var next = string_op_get(contents, i);
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
              if (isDigit(string_op_get(contents, i + 1 | 0), base)) {
                i = i + 2 | 0;
              }

              else {
                base = 10;
              }
            }
          }

          while (i < limit && isDigit(string_op_get(contents, i), base)) {
            i = i + 1 | 0;
          }

          if (i < limit && (isAlpha(string_op_get(contents, i)) || isNumber(string_op_get(contents, i)))) {
            i = i + 1 | 0;

            while (i < limit && (isAlpha(string_op_get(contents, i)) || isNumber(string_op_get(contents, i)))) {
              i = i + 1 | 0;
            }

            log.error(createRange(source, start, i), StringBuilder_new().append("Invalid integer literal: '").appendSlice(contents, start, i).appendChar(39).finish());

            return null;
          }
        }
      }

      else if (c === 34 || c === 39 || c === 96) {
        while (i < limit) {
          var next = string_op_get(contents, i);

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
        kind = 33;
      }

      else if (c === 40) {
        kind = 20;
      }

      else if (c === 41) {
        kind = 36;
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
        kind = 37;
      }

      else if (c === 63) {
        kind = 32;
      }

      else if (c === 91) {
        kind = 19;
      }

      else if (c === 93) {
        kind = 35;
      }

      else if (c === 94) {
        kind = 8;
      }

      else if (c === 123) {
        kind = 18;
      }

      else if (c === 125) {
        kind = 34;
      }

      else if (c === 126) {
        kind = 11;
      }

      else if (c === 42) {
        kind = 27;

        if (i < limit && string_op_get(contents, i) === 42) {
          kind = 15;
          i = i + 1 | 0;
        }
      }

      else if (c === 47) {
        kind = 12;

        if (i < limit && string_op_get(contents, i) === 47) {
          i = i + 1 | 0;

          while (i < limit && string_op_get(contents, i) !== 10) {
            i = i + 1 | 0;
          }

          continue;
        }

        if (i < limit && string_op_get(contents, i) === 42) {
          i = i + 1 | 0;
          var foundEnd = false;

          while (i < limit) {
            var next = string_op_get(contents, i);

            if (next === 42 && (i + 1 | 0) < limit && string_op_get(contents, i + 1 | 0) === 47) {
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
        kind = 28;

        if (i < limit && string_op_get(contents, i) === 61) {
          kind = 29;
          i = i + 1 | 0;

          if (i < limit && string_op_get(contents, i) === 61) {
            i = i + 1 | 0;
            log.error(createRange(source, start, i), "Use '!=' instead of '!=='");
          }
        }
      }

      else if (c === 61) {
        kind = 5;

        if (i < limit && string_op_get(contents, i) === 61) {
          kind = 14;
          i = i + 1 | 0;

          if (i < limit && string_op_get(contents, i) === 61) {
            i = i + 1 | 0;
            log.error(createRange(source, start, i), "Use '==' instead of '==='");
          }
        }
      }

      else if (c === 43) {
        kind = 30;

        if (i < limit && string_op_get(contents, i) === 43) {
          kind = 31;
          i = i + 1 | 0;
        }
      }

      else if (c === 45) {
        kind = 25;

        if (i < limit && string_op_get(contents, i) === 45) {
          kind = 26;
          i = i + 1 | 0;
        }
      }

      else if (c === 38) {
        kind = 6;

        if (i < limit && string_op_get(contents, i) === 38) {
          kind = 23;
          i = i + 1 | 0;
        }
      }

      else if (c === 124) {
        kind = 7;

        if (i < limit && string_op_get(contents, i) === 124) {
          kind = 24;
          i = i + 1 | 0;
        }
      }

      else if (c === 60) {
        kind = 21;

        if (i < limit) {
          c = string_op_get(contents, i);

          if (c === 60) {
            kind = 38;
            i = i + 1 | 0;
          }

          else if (c === 61) {
            kind = 22;
            i = i + 1 | 0;
          }
        }
      }

      else if (c === 62) {
        kind = 16;

        if (i < limit) {
          c = string_op_get(contents, i);

          if (c === 62) {
            kind = 39;
            i = i + 1 | 0;
          }

          else if (c === 61) {
            kind = 17;
            i = i + 1 | 0;
          }
        }
      }

      else if (c === 35) {
        while (i < limit && (isAlpha(string_op_get(contents, i)) || isNumber(string_op_get(contents, i)))) {
          i = i + 1 | 0;
        }

        var text = contents.slice(start, i);

        if (text === "#define") {
          kind = 73;
        }

        else if (text === "#elif") {
          kind = 74;
        }

        else if (text === "#else") {
          kind = 75;
        }

        else if (text === "#endif") {
          kind = 76;
        }

        else if (text === "#error") {
          kind = 77;
        }

        else if (text === "#if") {
          kind = 78;
        }

        else if (text === "#undef") {
          kind = 81;
        }

        else if (text === "#warning") {
          kind = 82;
        }

        else if (start === 0 && text === "#" && i < limit && string_op_get(contents, i) === 33) {
          while (i < limit && string_op_get(contents, i) !== 10) {
            i = i + 1 | 0;
          }

          continue;
        }

        else {
          var builder = StringBuilder_new().append("Invalid preprocessor token '").append(text).appendChar(39);

          if (text === "#ifdef") {
            builder.append(", did you mean '#if'?");
            kind = 78;
          }

          else if (text === "#elsif" || text === "#elseif") {
            builder.append(", did you mean '#elif'?");
            kind = 74;
          }

          else if (text === "#end") {
            builder.append(", did you mean '#endif'?");
            kind = 76;
          }

          log.error(createRange(source, start, i), builder.finish());
        }

        if (last !== null && last.kind !== 80) {
          var end = last.range.end;
          var j = i - 1 | 0;

          while (j >= end) {
            if (string_op_get(contents, j) === 10) {
              break;
            }

            j = j - 1 | 0;
          }

          if (j < end) {
            log.error(createRange(source, start, i), StringBuilder_new().append("Expected newline before ").append(tokenToString(kind)).finish());
          }
        }

        needsPreprocessor = true;
        wantNewline = true;
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

    if (needsPreprocessor) {
      var token = new Token();
      token.kind = 79;
      token.next = first;

      return token;
    }

    return first;
  }

  function library() {
    return "\n#if WASM\n\n  // These will be filled in by the WebAssembly code generator\n  unsafe var currentHeapPointer: *byte = null;\n  unsafe var originalHeapPointer: *byte = null;\n\n  extern unsafe function malloc(sizeOf: uint): *byte {\n    // Align all allocations to 8 bytes\n    var offset = ((currentHeapPointer as uint + 7) & ~7 as uint) as *byte;\n    sizeOf = (sizeOf + 7) & ~7 as uint;\n\n    // Use a simple bump allocator for now\n    var limit = offset + sizeOf;\n    currentHeapPointer = limit;\n\n    // Make sure the memory starts off at zero\n    var ptr = offset;\n    while (ptr < limit) {\n      *(ptr as *int) = 0;\n      ptr = ptr + 4;\n    }\n\n    return offset;\n  }\n\n  unsafe function memcpy(target: *byte, source: *byte, length: uint): void {\n    // No-op if either of the inputs are null\n    if (source == null || target == null) {\n      return;\n    }\n\n    // Optimized aligned copy\n    if (length >= 16 && (source as uint) % 4 == (target as uint) % 4) {\n      // Pick off the beginning\n      while ((target as uint) % 4 != 0) {\n        *target = *source;\n        target = target + 1;\n        source = source + 1;\n        length = length - 1;\n      }\n\n      // Pick off the end\n      while (length % 4 != 0) {\n        length = length - 1;\n        *(target + length) = *(source + length);\n      }\n\n      // Zip over the middle\n      var end = target + length;\n      while (target < end) {\n        *(target as *int) = *(source as *int);\n        target = target + 4;\n        source = source + 4;\n      }\n    }\n\n    // Slow unaligned copy\n    else {\n      var end = target + length;\n      while (target < end) {\n        *target = *source;\n        target = target + 1;\n        source = source + 1;\n      }\n    }\n  }\n\n  unsafe function memcmp(a: *byte, b: *byte, length: uint): int {\n    // No-op if either of the inputs are null\n    if (a == null || b == null) {\n      return 0;\n    }\n\n    // Return the first non-zero difference\n    while (length > 0) {\n      var delta = *a as int - *b as int;\n      if (delta != 0) {\n        return delta;\n      }\n      a = a + 1;\n      b = b + 1;\n      length = length - 1;\n    }\n\n    // Both inputs are identical\n    return 0;\n  }\n\n#elif C\n\n  declare unsafe function malloc(sizeOf: uint): *byte;\n  declare unsafe function memcpy(target: *byte, source: *byte, length: uint): void;\n  declare unsafe function memcmp(a: *byte, b: *byte, length: uint): int;\n\n#endif\n\n#if WASM || C\n\n  declare class bool {\n    toString(): string {\n      return this ? \"true\" : \"false\";\n    }\n  }\n\n  declare class sbyte {\n    toString(): string {\n      return (this as int).toString();\n    }\n  }\n\n  declare class byte {\n    toString(): string {\n      return (this as uint).toString();\n    }\n  }\n\n  declare class short {\n    toString(): string {\n      return (this as int).toString();\n    }\n  }\n\n  declare class ushort {\n    toString(): string {\n      return (this as uint).toString();\n    }\n  }\n\n  declare class int {\n    toString(): string {\n      // Special-case this to keep the rest of the code simple\n      if (this == -2147483648) {\n        return \"-2147483648\";\n      }\n\n      // Treat this like an unsigned integer prefixed by '-' if it's negative\n      return internalIntToString((this < 0 ? -this : this) as uint, this < 0);\n    }\n  }\n\n  declare class uint {\n    toString(): string {\n      return internalIntToString(this, false);\n    }\n  }\n\n  function internalIntToString(value: uint, sign: bool): string {\n    // Avoid allocation for common cases\n    if (value == 0) return \"0\";\n    if (value == 1) return sign ? \"-1\" : \"1\";\n\n    unsafe {\n      // Determine how many digits we need\n      var length = ((sign ? 1 : 0) + (\n        value >= 100000000 ?\n          value >= 1000000000 ? 10 : 9 :\n        value >= 10000 ?\n          value >= 1000000 ?\n            value >= 10000000 ? 8 : 7 :\n            value >= 100000 ? 6 : 5 :\n          value >= 100 ?\n            value >= 1000 ? 4 : 3 :\n            value >= 10 ? 2 : 1)) as uint;\n\n      var ptr = string_new(length) as *byte;\n      var end = ptr + 4 + length * 2;\n\n      if (sign) {\n        *((ptr + 4) as *ushort) = '-';\n      }\n\n      while (value != 0) {\n        end = end + -2;\n        *(end as *ushort) = (value % 10 + '0') as ushort;\n        value = value / 10;\n      }\n\n      return ptr as string;\n    }\n  }\n\n  function string_new(length: uint): string {\n    unsafe {\n      var ptr = malloc(4 + length * 2);\n      *(ptr as *uint) = length;\n      return ptr as string;\n    }\n  }\n\n  declare class string {\n    charAt(index: int): string {\n      return this.slice(index, index + 1);\n    }\n\n    charCodeAt(index: int): ushort {\n      return this[index];\n    }\n\n    get length(): int {\n      unsafe {\n        return *(this as *int);\n      }\n    }\n\n    operator [] (index: int): ushort {\n      if (index as uint < this.length as uint) {\n        unsafe {\n          return *((this as *byte + 4 + index * 2) as *ushort);\n        }\n      }\n      return 0;\n    }\n\n    operator == (other: string): bool {\n      unsafe {\n        if (this as *byte == other as *byte) return true;\n        if (this as *byte == null || other as *byte == null) return false;\n        var length = this.length;\n        if (length != other.length) return false;\n        return memcmp(this as *byte + 4, other as *byte + 4, length as uint * 2) == 0;\n      }\n    }\n\n    slice(start: int, end: int): string {\n      var length = this.length;\n\n      if (start < 0) start = start + length;\n      if (end < 0) end = end + length;\n\n      if (start < 0) start = 0;\n      else if (start > length) start = length;\n\n      if (end < start) end = start;\n      else if (end > length) end = length;\n\n      unsafe {\n        var range = (end - start) as uint;\n        var ptr = string_new(range);\n        memcpy(ptr as *byte + 4, this as *byte + 4 + start * 2, range * 2);\n        return ptr;\n      }\n    }\n\n    startsWith(text: string): bool {\n      var textLength = text.length;\n      if (this.length < textLength) return false;\n      unsafe {\n        return memcmp(this as *byte + 4, text as *byte + 4, textLength as uint * 2) == 0;\n      }\n    }\n\n    endsWith(text: string): bool {\n      var thisLength = this.length;\n      var textLength = text.length;\n      if (thisLength < textLength) return false;\n      unsafe {\n        return memcmp(this as *byte + 4 + (thisLength - textLength) * 2, text as *byte + 4, textLength as uint * 2) == 0;\n      }\n    }\n  }\n\n#else\n\n  declare class bool {\n    toString(): string;\n  }\n\n  declare class sbyte {\n    toString(): string;\n  }\n\n  declare class byte {\n    toString(): string;\n  }\n\n  declare class short {\n    toString(): string;\n  }\n\n  declare class ushort {\n    toString(): string;\n  }\n\n  declare class int {\n    toString(): string;\n  }\n\n  declare class uint {\n    toString(): string;\n  }\n\n  declare class string {\n    charAt(index: int): string;\n    charCodeAt(index: int): ushort;\n    get length(): int;\n    operator == (other: string): bool;\n    operator [] (index: int): ushort { return this.charCodeAt(index); }\n    slice(start: int, end: int): string;\n\n    #if JS\n      startsWith(text: string): bool { return this.slice(0, text.length) == text; }\n      endsWith(text: string): bool { return this.slice(-text.length, this.length) == text; }\n    #else\n      startsWith(text: string): bool;\n      endsWith(text: string): bool;\n    #endif\n  }\n\n#endif\n";
  }

  function LineColumn() {
    this.line = 0;
    this.column = 0;
  }

  function Source() {
    this.name = null;
    this.contents = null;
    this.next = null;
    this.isLibrary = false;
    this.firstToken = null;
    this.file = null;
  }

  Source.prototype.indexToLineColumn = function(index) {
    var contents = this.contents;
    var column = 0;
    var line = 0;
    var i = 0;

    while (i < index) {
      var c = string_op_get(contents, i);

      if (c === 10) {
        line = line + 1 | 0;
        column = 0;
      }

      else if (c < 56320 || c > 57343) {
        column = column + 1 | 0;
      }

      i = i + 1 | 0;
    }

    var location = new LineColumn();
    location.line = line;
    location.column = column;

    return location;
  };

  function Range() {
    this.source = null;
    this.start = 0;
    this.end = 0;
  }

  Range.prototype.toString = function() {
    return this.source.contents.slice(this.start, this.end);
  };

  Range.prototype.equals = function(other) {
    return this.source === other.source && this.start === other.start && this.end === other.end;
  };

  Range.prototype.enclosingLine = function() {
    var contents = this.source.contents;
    var start = this.start;
    var end = this.start;

    while (start > 0 && string_op_get(contents, start - 1 | 0) !== 10) {
      start = start - 1 | 0;
    }

    var length = contents.length;

    while (end < length && string_op_get(contents, end) !== 10) {
      end = end + 1 | 0;
    }

    return createRange(this.source, start, end);
  };

  Range.prototype.rangeAtEnd = function() {
    return createRange(this.source, this.end, this.end);
  };

  function createRange(source, start, end) {
    __declare.assert(start <= end);
    var range = new Range();
    range.source = source;
    range.start = start;
    range.end = end;

    return range;
  }

  function spanRanges(left, right) {
    __declare.assert(left.source === right.source);
    __declare.assert(left.start <= right.start);
    __declare.assert(left.end <= right.end);

    return createRange(left.source, left.start, right.end);
  }

  function Diagnostic() {
    this.range = null;
    this.message = null;
    this.kind = 0;
    this.next = null;
  }

  Diagnostic.prototype.appendSourceName = function(builder, location) {
    builder.append(this.range.source.name).appendChar(58).append((location.line + 1 | 0).toString()).appendChar(58).append((location.column + 1 | 0).toString()).append(": ");
  };

  Diagnostic.prototype.appendKind = function(builder) {
    builder.append(this.kind === 0 ? "error: " : "warning: ");
  };

  Diagnostic.prototype.appendMessage = function(builder) {
    builder.append(this.message).appendChar(10);
  };

  Diagnostic.prototype.appendLineContents = function(builder, location) {
    var range = this.range.enclosingLine();
    builder.appendSlice(range.source.contents, range.start, range.end).appendChar(10);
  };

  Diagnostic.prototype.appendRange = function(builder, location) {
    var range = this.range;
    var column = location.column;
    var contents = range.source.contents;

    while (column > 0) {
      builder.appendChar(32);
      column = column - 1 | 0;
    }

    if ((range.end - range.start | 0) <= 1) {
      builder.appendChar(94);
    }

    else {
      var i = range.start;

      while (i < range.end && string_op_get(contents, i) !== 10) {
        builder.appendChar(126);
        i = i + 1 | 0;
      }
    }

    builder.appendChar(10);
  };

  function Log() {
    this.first = null;
    this.last = null;
  }

  Log.prototype.error = function(range, message) {
    this.append(range, message, 0);
  };

  Log.prototype.warning = function(range, message) {
    this.append(range, message, 1);
  };

  Log.prototype.append = function(range, message, kind) {
    var diagnostic = new Diagnostic();
    diagnostic.range = range;
    diagnostic.message = message;
    diagnostic.kind = kind;

    if (this.first === null) {
      this.first = diagnostic;
    }

    else {
      this.last.next = diagnostic;
    }

    this.last = diagnostic;
  };

  Log.prototype.toString = function() {
    var builder = StringBuilder_new();
    var diagnostic = this.first;

    while (diagnostic !== null) {
      var location = diagnostic.range.source.indexToLineColumn(diagnostic.range.start);
      diagnostic.appendSourceName(builder, location);
      diagnostic.appendKind(builder);
      diagnostic.appendMessage(builder);
      diagnostic.appendLineContents(builder, location);
      diagnostic.appendRange(builder, location);
      diagnostic = diagnostic.next;
    }

    return builder.finish();
  };

  Log.prototype.hasErrors = function() {
    var diagnostic = this.first;

    while (diagnostic !== null) {
      if (diagnostic.kind === 0) {
        return true;
      }

      diagnostic = diagnostic.next;
    }

    return false;
  };

  __extern.Color = {
    DEFAULT: 0,
    BOLD: 1,
    RED: 2,
    GREEN: 3,
    MAGENTA: 4
  };

  function writeLogToTerminal(log) {
    var diagnostic = log.first;

    while (diagnostic !== null) {
      var location = diagnostic.range.source.indexToLineColumn(diagnostic.range.start);
      var builder = StringBuilder_new();
      diagnostic.appendSourceName(builder, location);
      __declare.Terminal_setColor(1);
      __declare.Terminal_write(builder.finish());
      builder = StringBuilder_new();
      diagnostic.appendKind(builder);
      __declare.Terminal_setColor(diagnostic.kind === 0 ? 2 : 4);
      __declare.Terminal_write(builder.finish());
      builder = StringBuilder_new();
      diagnostic.appendMessage(builder);
      __declare.Terminal_setColor(1);
      __declare.Terminal_write(builder.finish());
      builder = StringBuilder_new();
      diagnostic.appendLineContents(builder, location);
      __declare.Terminal_setColor(0);
      __declare.Terminal_write(builder.finish());
      builder = StringBuilder_new();
      diagnostic.appendRange(builder, location);
      __declare.Terminal_setColor(3);
      __declare.Terminal_write(builder.finish());
      diagnostic = diagnostic.next;
    }

    __declare.Terminal_setColor(0);
  }

  function printError(text) {
    __declare.Terminal_setColor(2);
    __declare.Terminal_write("error: ");
    __declare.Terminal_setColor(1);
    __declare.Terminal_write(text);
    __declare.Terminal_write("\n");
    __declare.Terminal_setColor(0);
  }

  function CommandLineArgument() {
    this.text = null;
    this.next = null;
  }

  var firstArgument = null;
  var lastArgument = null;

  var main_addArgument = __extern.main_addArgument = function(text) {
    var argument = new CommandLineArgument();
    argument.text = text;

    if (firstArgument === null) {
      firstArgument = argument;
    }

    else {
      lastArgument.next = argument;
    }

    lastArgument = argument;
  };

  var main_reset = __extern.main_reset = function() {
    firstArgument = null;
    lastArgument = null;
  };

  function printUsage() {
    __declare.Terminal_write("\nUsage: thinc [FLAGS] [INPUTS]\n\n  --help           Print this message.\n  --out [PATH]     Save the generated code to PATH.\n  --define [NAME]  Define the flag NAME in all input files.\n\nExamples:\n\n  thinc main.thin --out main.js\n  thinc src/*.thin --out main.wasm\n  thinc native.thin --out main.c --define ENABLE_TESTS\n\n");
  }

  var main_entry = __extern.main_entry = function() {
    var target = 0;
    var argument = firstArgument;
    var inputCount = 0;
    var output = null;

    if (firstArgument === null) {
      printUsage();

      return 1;
    }

    while (argument !== null) {
      var text = argument.text;

      if (string_startsWith(text, "-")) {
        if (text === "-h" || text === "-help" || text === "--help" || text === "/?") {
          printUsage();

          return 0;
        }

        else if (text === "--c") {
          target = 1;
        }

        else if (text === "--js") {
          target = 2;
        }

        else if (text === "--wasm") {
          target = 3;
        }

        else if (text === "--define" && argument.next !== null) {
          argument = argument.next;
        }

        else if (text === "--out" && argument.next !== null) {
          argument = argument.next;
          output = argument.text;
        }

        else {
          printError(StringBuilder_new().append("Invalid flag: ").append(text).finish());

          return 1;
        }
      }

      else {
        inputCount = inputCount + 1 | 0;
      }

      argument = argument.next;
    }

    if (inputCount === 0) {
      printError("No input files");

      return 1;
    }

    if (output === null) {
      printError("Missing an output file (use the --out flag)");

      return 1;
    }

    if (target === 0) {
      if (string_endsWith(output, ".c")) {
        target = 1;
      }

      else if (string_endsWith(output, ".js")) {
        target = 2;
      }

      else if (string_endsWith(output, ".wasm")) {
        target = 3;
      }

      else {
        printError("Missing a target (use either --c, --js, or --wasm)");

        return 1;
      }
    }

    var compiler = new Compiler();
    compiler.initialize(target);
    argument = firstArgument;

    while (argument !== null) {
      var text = argument.text;

      if (text === "--define") {
        argument = argument.next;
        compiler.preprocessor.define(argument.text, true);
      }

      else if (text === "--out") {
        argument = argument.next;
      }

      else if (!string_startsWith(text, "-")) {
        var contents = __declare.IO_readTextFile(text);

        if (contents === null) {
          printError(StringBuilder_new().append("Cannot read from ").append(text).finish());

          return 1;
        }

        compiler.addInput(text, contents);
      }

      argument = argument.next;
    }

    compiler.finish();
    writeLogToTerminal(compiler.log);

    if (!compiler.log.hasErrors()) {
      if (target === 1 && __declare.IO_writeTextFile(output, compiler.output_c) || target === 2 && __declare.IO_writeTextFile(output, compiler.output_js) || target === 3 && __declare.IO_writeBinaryFile(output, compiler.output_wasm)) {
        return 0;
      }

      printError(StringBuilder_new().append("Cannot write to ").append(output).finish());
    }

    return 1;
  };

  function isUnary(kind) {
    return kind >= 33 && kind <= 43;
  }

  function isUnaryPostfix(kind) {
    return kind >= 40 && kind <= 41;
  }

  function isBinary(kind) {
    return kind >= 44 && kind <= 63;
  }

  function invertedBinaryKind(kind) {
    if (kind === 50) {
      return 59;
    }

    if (kind === 59) {
      return 50;
    }

    if (kind === 52) {
      return 55;
    }

    if (kind === 53) {
      return 54;
    }

    if (kind === 54) {
      return 53;
    }

    if (kind === 55) {
      return 52;
    }

    return kind;
  }

  function isExpression(node) {
    return node.kind >= 17 && node.kind <= 63;
  }

  function isCompactNodeKind(kind) {
    return kind === 6 || kind === 10 || kind === 15;
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

  Node.prototype.become = function(node) {
    __declare.assert(node !== this);
    __declare.assert(node.parent === null);
    this.kind = node.kind;
    this.flags = node.flags;
    this.firstFlag = node.firstFlag;
    this.range = node.range;
    this.internalRange = node.internalRange;
    this.intValue = node.intValue;
    this.stringValue = node.stringValue;
    this.resolvedType = node.resolvedType;
    this.symbol = node.symbol;
    this.scope = node.scope;
  };

  Node.prototype.becomeSymbolReference = function(symbol) {
    this.kind = 25;
    this.symbol = symbol;
    this.stringValue = symbol.name;
    this.resolvedType = symbol.resolvedType;
    this.removeChildren();
  };

  Node.prototype.becomeIntegerConstant = function(value) {
    this.kind = 24;
    this.symbol = null;
    this.intValue = value;
    this.removeChildren();
  };

  Node.prototype.becomeBooleanConstant = function(value) {
    this.kind = 18;
    this.symbol = null;
    this.intValue = value ? 1 : 0;
    this.removeChildren();
  };

  Node.prototype.isNegativeInteger = function() {
    return this.kind === 24 && this.intValue < 0;
  };

  Node.prototype.isNonNegativeInteger = function() {
    return this.kind === 24 && this.intValue >= 0;
  };

  Node.prototype.isDeclare = function() {
    return (this.flags & 1) !== 0;
  };

  Node.prototype.isExtern = function() {
    return (this.flags & 4) !== 0;
  };

  Node.prototype.isDeclareOrExtern = function() {
    return (this.flags & 5) !== 0;
  };

  Node.prototype.isGet = function() {
    return (this.flags & 8) !== 0;
  };

  Node.prototype.isSet = function() {
    return (this.flags & 512) !== 0;
  };

  Node.prototype.isOperator = function() {
    return (this.flags & 16) !== 0;
  };

  Node.prototype.isPositive = function() {
    return (this.flags & 32) !== 0;
  };

  Node.prototype.isPrivate = function() {
    return (this.flags & 64) !== 0;
  };

  Node.prototype.isUnsafe = function() {
    return (this.flags & 2048) !== 0;
  };

  Node.prototype.isUnsignedOperator = function() {
    return (this.flags & 4096) !== 0;
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

  Node.prototype.insertChildBefore = function(after, before) {
    if (before === null) {
      return;
    }

    __declare.assert(before !== after);
    __declare.assert(before.parent === null);
    __declare.assert(before.previousSibling === null);
    __declare.assert(before.nextSibling === null);
    __declare.assert(after === null || after.parent === this);

    if (after === null) {
      this.appendChild(before);

      return;
    }

    before.parent = this;
    before.previousSibling = after.previousSibling;
    before.nextSibling = after;

    if (after.previousSibling !== null) {
      __declare.assert(after === after.previousSibling.nextSibling);
      after.previousSibling.nextSibling = before;
    }

    else {
      __declare.assert(after === this.firstChild);
      this.firstChild = before;
    }

    after.previousSibling = before;
  };

  Node.prototype.remove = function() {
    __declare.assert(this.parent !== null);

    if (this.previousSibling !== null) {
      __declare.assert(this.previousSibling.nextSibling === this);
      this.previousSibling.nextSibling = this.nextSibling;
    }

    else {
      __declare.assert(this.parent.firstChild === this);
      this.parent.firstChild = this.nextSibling;
    }

    if (this.nextSibling !== null) {
      __declare.assert(this.nextSibling.previousSibling === this);
      this.nextSibling.previousSibling = this.previousSibling;
    }

    else {
      __declare.assert(this.parent.lastChild === this);
      this.parent.lastChild = this.previousSibling;
    }

    this.parent = null;
    this.previousSibling = null;
    this.nextSibling = null;

    return this;
  };

  Node.prototype.removeChildren = function() {
    while (this.lastChild !== null) {
      this.lastChild.remove();
    }
  };

  Node.prototype.replaceWith = function(node) {
    __declare.assert(node !== this);
    __declare.assert(this.parent !== null);
    __declare.assert(node.parent === null);
    __declare.assert(node.previousSibling === null);
    __declare.assert(node.nextSibling === null);
    node.parent = this.parent;
    node.previousSibling = this.previousSibling;
    node.nextSibling = this.nextSibling;

    if (this.previousSibling !== null) {
      __declare.assert(this.previousSibling.nextSibling === this);
      this.previousSibling.nextSibling = node;
    }

    else {
      __declare.assert(this.parent.firstChild === this);
      this.parent.firstChild = node;
    }

    if (this.nextSibling !== null) {
      __declare.assert(this.nextSibling.previousSibling === this);
      this.nextSibling.previousSibling = node;
    }

    else {
      __declare.assert(this.parent.lastChild === this);
      this.parent.lastChild = node;
    }

    this.parent = null;
    this.previousSibling = null;
    this.nextSibling = null;
  };

  Node.prototype.isType = function() {
    return this.kind === 32 || this.kind === 38 || this.symbol !== null && isType(this.symbol.kind);
  };

  Node.prototype.isCallValue = function() {
    return this.parent.kind === 19 && this === this.parent.callValue();
  };

  Node.prototype.isAssignTarget = function() {
    return this.parent.kind === 45 && this === this.parent.binaryLeft();
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
    __declare.assert(this.kind === 11);
    __declare.assert(this.childCount() >= 2);
    __declare.assert(this.symbol !== null);

    return this.symbol.kind === 4 ? this.firstChild.nextSibling : this.firstChild;
  };

  Node.prototype.functionReturnType = function() {
    __declare.assert(this.kind === 11);
    __declare.assert(this.childCount() >= 2);
    __declare.assert(isExpression(this.lastChild.previousSibling));

    return this.lastChild.previousSibling;
  };

  Node.prototype.functionBody = function() {
    __declare.assert(this.kind === 11);
    __declare.assert(this.childCount() >= 2);
    __declare.assert(this.lastChild.kind === 3 || this.lastChild.kind === 8);
    var body = this.lastChild;

    return body.kind === 3 ? body : null;
  };

  Node.prototype.newType = function() {
    __declare.assert(this.kind === 26);
    __declare.assert(this.childCount() >= 1);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.callValue = function() {
    __declare.assert(this.kind === 19);
    __declare.assert(this.childCount() >= 1);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.castValue = function() {
    __declare.assert(this.kind === 20);
    __declare.assert(this.childCount() === 2);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.castType = function() {
    __declare.assert(this.kind === 20);
    __declare.assert(this.childCount() === 2);
    __declare.assert(isExpression(this.lastChild));

    return this.lastChild;
  };

  Node.prototype.alignOfType = function() {
    __declare.assert(this.kind === 17);
    __declare.assert(this.childCount() === 1);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.sizeOfType = function() {
    __declare.assert(this.kind === 29);
    __declare.assert(this.childCount() === 1);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.dotTarget = function() {
    __declare.assert(this.kind === 21);
    __declare.assert(this.childCount() === 1);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.returnValue = function() {
    __declare.assert(this.kind === 13);
    __declare.assert(this.childCount() <= 1);
    __declare.assert(this.firstChild === null || isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.variableType = function() {
    __declare.assert(this.kind === 2);
    __declare.assert(this.childCount() <= 2);
    __declare.assert(isExpression(this.firstChild) || this.firstChild.kind === 8);
    var type = this.firstChild;

    return type.kind !== 8 ? type : null;
  };

  Node.prototype.variableValue = function() {
    __declare.assert(this.kind === 2);
    __declare.assert(this.childCount() <= 2);
    __declare.assert(this.firstChild.nextSibling === null || isExpression(this.firstChild.nextSibling));

    return this.firstChild.nextSibling;
  };

  Node.prototype.expressionValue = function() {
    __declare.assert(this.kind === 10);
    __declare.assert(this.childCount() === 1);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.binaryLeft = function() {
    __declare.assert(isBinary(this.kind));
    __declare.assert(this.childCount() === 2);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.binaryRight = function() {
    __declare.assert(isBinary(this.kind));
    __declare.assert(this.childCount() === 2);
    __declare.assert(isExpression(this.lastChild));

    return this.lastChild;
  };

  Node.prototype.unaryValue = function() {
    __declare.assert(isUnary(this.kind));
    __declare.assert(this.childCount() === 1);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.whileValue = function() {
    __declare.assert(this.kind === 16);
    __declare.assert(this.childCount() === 2);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.whileBody = function() {
    __declare.assert(this.kind === 16);
    __declare.assert(this.childCount() === 2);
    __declare.assert(this.lastChild.kind === 3);

    return this.lastChild;
  };

  Node.prototype.hookValue = function() {
    __declare.assert(this.kind === 22);
    __declare.assert(this.childCount() === 3);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.hookTrue = function() {
    __declare.assert(this.kind === 22);
    __declare.assert(this.childCount() === 3);
    __declare.assert(isExpression(this.firstChild.nextSibling));

    return this.firstChild.nextSibling;
  };

  Node.prototype.hookFalse = function() {
    __declare.assert(this.kind === 22);
    __declare.assert(this.childCount() === 3);
    __declare.assert(isExpression(this.lastChild));

    return this.lastChild;
  };

  Node.prototype.indexTarget = function() {
    __declare.assert(this.kind === 23);
    __declare.assert(this.childCount() >= 1);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.ifValue = function() {
    __declare.assert(this.kind === 12);
    __declare.assert(this.childCount() === 2 || this.childCount() === 3);
    __declare.assert(isExpression(this.firstChild));

    return this.firstChild;
  };

  Node.prototype.ifTrue = function() {
    __declare.assert(this.kind === 12);
    __declare.assert(this.childCount() === 2 || this.childCount() === 3);
    __declare.assert(this.firstChild.nextSibling.kind === 3);

    return this.firstChild.nextSibling;
  };

  Node.prototype.ifFalse = function() {
    __declare.assert(this.kind === 12);
    __declare.assert(this.childCount() === 2 || this.childCount() === 3);
    __declare.assert(this.firstChild.nextSibling.nextSibling === null || this.firstChild.nextSibling.nextSibling.kind === 3);

    return this.firstChild.nextSibling.nextSibling;
  };

  Node.prototype.expandCallIntoOperatorTree = function() {
    if (this.kind !== 19) {
      return false;
    }

    var value = this.callValue();
    var symbol = value.symbol;

    if (value.kind === 21 && symbol.node.isOperator() && symbol.node.isDeclare()) {
      var binaryKind = 27;

      if (symbol.name === "%") {
        binaryKind = 60;
      }

      else if (symbol.name === "&") {
        binaryKind = 46;
      }

      else if (symbol.name === "*") {
        binaryKind = 58;
      }

      else if (symbol.name === "**") {
        binaryKind = 51;
      }

      else if (symbol.name === "/") {
        binaryKind = 49;
      }

      else if (symbol.name === "<") {
        binaryKind = 54;
      }

      else if (symbol.name === "<<") {
        binaryKind = 61;
      }

      else if (symbol.name === "==") {
        binaryKind = 50;
      }

      else if (symbol.name === ">") {
        binaryKind = 52;
      }

      else if (symbol.name === ">>") {
        binaryKind = 62;
      }

      else if (symbol.name === "[]") {
        binaryKind = 23;
      }

      else if (symbol.name === "^") {
        binaryKind = 48;
      }

      else if (symbol.name === "|") {
        binaryKind = 47;
      }

      if (binaryKind !== 27) {
        this.kind = binaryKind;
        value.remove();
        this.insertChildBefore(this.firstChild, value.dotTarget().remove());

        return true;
      }

      else if (symbol.name === "[]=") {
        this.kind = 45;
        var target = createIndex(value.remove().dotTarget().remove());
        target.appendChild(this.firstChild.remove());
        this.insertChildBefore(this.firstChild, target);

        return true;
      }
    }

    return false;
  };

  function createNew(type) {
    __declare.assert(isExpression(type));
    var node = new Node();
    node.kind = 26;
    node.appendChild(type);

    return node;
  }

  function createHook(test, primary, secondary) {
    __declare.assert(isExpression(test));
    __declare.assert(isExpression(primary));
    __declare.assert(isExpression(secondary));
    var node = new Node();
    node.kind = 22;
    node.appendChild(test);
    node.appendChild(primary);
    node.appendChild(secondary);

    return node;
  }

  function createIndex(target) {
    __declare.assert(isExpression(target));
    var node = new Node();
    node.kind = 23;
    node.appendChild(target);

    return node;
  }

  function createNull() {
    var node = new Node();
    node.kind = 27;

    return node;
  }

  function createThis() {
    var node = new Node();
    node.kind = 31;

    return node;
  }

  function createAddressOf(value) {
    __declare.assert(isExpression(value));
    var node = new Node();
    node.kind = 33;
    node.appendChild(value);

    return node;
  }

  function createDereference(value) {
    __declare.assert(isExpression(value));
    var node = new Node();
    node.kind = 35;
    node.appendChild(value);

    return node;
  }

  function createAlignOf(type) {
    __declare.assert(isExpression(type));
    var node = new Node();
    node.kind = 17;
    node.appendChild(type);

    return node;
  }

  function createSizeOf(type) {
    __declare.assert(isExpression(type));
    var node = new Node();
    node.kind = 29;
    node.appendChild(type);

    return node;
  }

  function createBool(value) {
    var node = new Node();
    node.kind = 18;
    node.intValue = value ? 1 : 0;

    return node;
  }

  function createInt(value) {
    var node = new Node();
    node.kind = 24;
    node.intValue = value;

    return node;
  }

  function createString(value) {
    var node = new Node();
    node.kind = 30;
    node.stringValue = value;

    return node;
  }

  function createName(value) {
    var node = new Node();
    node.kind = 25;
    node.stringValue = value;

    return node;
  }

  function createType(type) {
    __declare.assert(type !== null);
    var node = new Node();
    node.kind = 32;
    node.resolvedType = type;

    return node;
  }

  function createEmpty() {
    var node = new Node();
    node.kind = 8;

    return node;
  }

  function createExpression(value) {
    __declare.assert(isExpression(value));
    var node = new Node();
    node.kind = 10;
    node.appendChild(value);

    return node;
  }

  function createBlock() {
    var node = new Node();
    node.kind = 3;

    return node;
  }

  function createClass(name) {
    var node = new Node();
    node.kind = 5;
    node.stringValue = name;

    return node;
  }

  function createEnum(name) {
    var node = new Node();
    node.kind = 9;
    node.stringValue = name;

    return node;
  }

  function createIf(value, trueBranch, falseBranch) {
    __declare.assert(isExpression(value));
    __declare.assert(trueBranch.kind === 3);
    __declare.assert(falseBranch === null || falseBranch.kind === 3);
    var node = new Node();
    node.kind = 12;
    node.appendChild(value);
    node.appendChild(trueBranch);

    if (falseBranch !== null) {
      node.appendChild(falseBranch);
    }

    return node;
  }

  function createWhile(value, body) {
    __declare.assert(isExpression(value));
    __declare.assert(body.kind === 3);
    var node = new Node();
    node.kind = 16;
    node.appendChild(value);
    node.appendChild(body);

    return node;
  }

  function createReturn(value) {
    __declare.assert(value === null || isExpression(value));
    var node = new Node();
    node.kind = 13;

    if (value !== null) {
      node.appendChild(value);
    }

    return node;
  }

  function createVariables() {
    var node = new Node();
    node.kind = 15;

    return node;
  }

  function createConstants() {
    var node = new Node();
    node.kind = 6;

    return node;
  }

  function createVariable(name, type, value) {
    __declare.assert(type === null || isExpression(type));
    __declare.assert(value === null || isExpression(value));
    var node = new Node();
    node.kind = 2;
    node.stringValue = name;
    node.appendChild(type !== null ? type : createEmpty());

    if (value !== null) {
      node.appendChild(value);
    }

    return node;
  }

  function createFunction(name) {
    var node = new Node();
    node.kind = 11;
    node.stringValue = name;

    return node;
  }

  function createUnary(kind, value) {
    __declare.assert(isUnary(kind));
    __declare.assert(isExpression(value));
    var node = new Node();
    node.kind = kind;
    node.appendChild(value);

    return node;
  }

  function createBinary(kind, left, right) {
    __declare.assert(isBinary(kind));
    __declare.assert(isExpression(left));
    __declare.assert(isExpression(right));
    var node = new Node();
    node.kind = kind;
    node.appendChild(left);
    node.appendChild(right);

    return node;
  }

  function createCall(value) {
    __declare.assert(isExpression(value));
    var node = new Node();
    node.kind = 19;
    node.appendChild(value);

    return node;
  }

  function createCast(value, type) {
    __declare.assert(isExpression(value));
    __declare.assert(isExpression(type));
    var node = new Node();
    node.kind = 20;
    node.appendChild(value);
    node.appendChild(type);

    return node;
  }

  function createDot(value, name) {
    __declare.assert(isExpression(value));
    var node = new Node();
    node.kind = 21;
    node.stringValue = name;
    node.appendChild(value);

    return node;
  }

  function createSymbolReference(symbol) {
    var node = createName(symbol.name);
    node.symbol = symbol;
    node.resolvedType = symbol.resolvedType;

    return node;
  }

  function createMemberReference(value, symbol) {
    var node = createDot(value, symbol.name);
    node.symbol = symbol;
    node.resolvedType = symbol.resolvedType;

    return node;
  }

  function createParseError() {
    var node = new Node();
    node.kind = 28;

    return node;
  }

  function isRightAssociative(precedence) {
    return precedence === 1 || precedence === 12;
  }

  function ParserContext() {
    this.previous = null;
    this.current = null;
    this.log = null;
    this.lastError = null;
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
    if (this.lastError !== this.current) {
      this.lastError = this.current;
      this.log.error(this.current.range, StringBuilder_new().append("Unexpected ").append(tokenToString(this.current.kind)).finish());
    }
  };

  ParserContext.prototype.expect = function(kind) {
    if (!this.peek(kind)) {
      if (this.lastError !== this.current) {
        this.lastError = this.current;
        var previousLine = this.previous.range.enclosingLine();
        var currentLine = this.current.range.enclosingLine();

        if (kind !== 2 && !previousLine.equals(currentLine)) {
          this.log.error(previousLine.rangeAtEnd(), StringBuilder_new().append("Expected ").append(tokenToString(kind)).finish());
        }

        else {
          this.log.error(this.current.range, StringBuilder_new().append("Expected ").append(tokenToString(kind)).append(" but found ").append(tokenToString(this.current.kind)).finish());
        }
      }

      return false;
    }

    this.advance();

    return true;
  };

  ParserContext.prototype.parseUnaryPrefix = function(kind, mode) {
    __declare.assert(isUnary(kind));
    var token = this.current;
    this.advance();
    var value = this.parseExpression(13, mode);

    if (value === null) {
      return null;
    }

    return createUnary(kind, value).withRange(spanRanges(token.range, value.range)).withInternalRange(token.range);
  };

  ParserContext.prototype.parseBinary = function(kind, left, localPrecedence, operatorPrecedence) {
    if (localPrecedence >= operatorPrecedence) {
      return left;
    }

    var token = this.current;
    this.advance();
    var precedence = isRightAssociative(operatorPrecedence) ? operatorPrecedence - 1 | 0 : operatorPrecedence;
    var right = this.parseExpression(precedence, 0);

    if (right === null) {
      return null;
    }

    return createBinary(kind, left, right).withRange(spanRanges(left.range, right.range)).withInternalRange(token.range);
  };

  ParserContext.prototype.parseUnaryPostfix = function(kind, value, localPrecedence) {
    if (localPrecedence >= 14) {
      return value;
    }

    var token = this.current;
    this.advance();

    return createUnary(kind, value).withRange(spanRanges(value.range, token.range)).withInternalRange(token.range);
  };

  ParserContext.prototype.parseQuotedString = function(range) {
    __declare.assert((range.end - range.start | 0) >= 2);
    var text = range.source.contents;
    var end = range.start + 1 | 0;
    var limit = range.end - 1 | 0;
    var start = end;
    var builder = StringBuilder_new();

    while (end < limit) {
      var c = string_op_get(text, end);

      if (c === 92) {
        builder.appendSlice(text, start, end);
        end = end + 1 | 0;
        start = end + 1 | 0;
        c = string_op_get(text, end);

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

    if (this.peek(15)) {
      splitToken(this.current, 27, 27);
    }

    if (this.peek(27)) {
      return this.parseUnaryPrefix(mode === 1 ? 38 : 35, mode);
    }

    if (mode === 0) {
      if (this.eat(60)) {
        return createNull().withRange(token.range);
      }

      if (this.eat(68)) {
        return createThis().withRange(token.range);
      }

      if (this.peek(1)) {
        var text = this.parseQuotedString(token.range);

        if (text === null) {
          return null;
        }

        this.advance();

        if (text.length !== 1) {
          this.log.error(token.range, "Invalid character literal (strings use double quotes)");

          return createParseError().withRange(token.range);
        }

        return createInt(string_op_get(text, 0)).withRange(token.range);
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

      if (this.eat(69)) {
        return createBool(true).withRange(token.range);
      }

      if (this.eat(52)) {
        return createBool(false).withRange(token.range);
      }

      if (this.eat(59)) {
        var type = this.parseType();

        if (type === null) {
          return null;
        }

        return this.parseArgumentList(token.range, createNew(type));
      }

      if (this.eat(40)) {
        if (!this.expect(20)) {
          return null;
        }

        var type = this.parseType();

        if (type === null) {
          return null;
        }

        var close = this.current;

        if (!this.expect(36)) {
          return null;
        }

        return createAlignOf(type).withRange(spanRanges(token.range, close.range));
      }

      if (this.eat(66)) {
        if (!this.expect(20)) {
          return null;
        }

        var type = this.parseType();

        if (type === null) {
          return null;
        }

        var close = this.current;

        if (!this.expect(36)) {
          return null;
        }

        return createSizeOf(type).withRange(spanRanges(token.range, close.range));
      }

      if (this.eat(20)) {
        var value = this.parseExpression(0, 0);

        if (value === null || !this.expect(36)) {
          return null;
        }

        return value;
      }

      if (this.peek(6)) {
        return this.parseUnaryPrefix(33, 0);
      }

      if (this.peek(11)) {
        return this.parseUnaryPrefix(34, 0);
      }

      if (this.peek(25)) {
        return this.parseUnaryPrefix(36, 0);
      }

      if (this.peek(26)) {
        return this.parseUnaryPrefix(42, 0);
      }

      if (this.peek(28)) {
        return this.parseUnaryPrefix(37, 0);
      }

      if (this.peek(30)) {
        return this.parseUnaryPrefix(39, 0);
      }

      if (this.peek(31)) {
        return this.parseUnaryPrefix(43, 0);
      }
    }

    this.unexpectedToken();

    return null;
  };

  ParserContext.prototype.parseInfix = function(precedence, node, mode) {
    var token = this.current.range;

    if (this.peek(13) && precedence < 15) {
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
        return this.parseBinary(45, node, precedence, 1);
      }

      if (this.peek(6)) {
        return this.parseBinary(46, node, precedence, 6);
      }

      if (this.peek(7)) {
        return this.parseBinary(47, node, precedence, 4);
      }

      if (this.peek(8)) {
        return this.parseBinary(48, node, precedence, 5);
      }

      if (this.peek(12)) {
        return this.parseBinary(49, node, precedence, 11);
      }

      if (this.peek(14)) {
        return this.parseBinary(50, node, precedence, 7);
      }

      if (this.peek(15)) {
        return this.parseBinary(51, node, precedence, 12);
      }

      if (this.peek(16)) {
        return this.parseBinary(52, node, precedence, 8);
      }

      if (this.peek(17)) {
        return this.parseBinary(53, node, precedence, 8);
      }

      if (this.peek(21)) {
        return this.parseBinary(54, node, precedence, 8);
      }

      if (this.peek(22)) {
        return this.parseBinary(55, node, precedence, 8);
      }

      if (this.peek(23)) {
        return this.parseBinary(56, node, precedence, 3);
      }

      if (this.peek(24)) {
        return this.parseBinary(57, node, precedence, 2);
      }

      if (this.peek(25)) {
        return this.parseBinary(63, node, precedence, 10);
      }

      if (this.peek(27)) {
        return this.parseBinary(58, node, precedence, 11);
      }

      if (this.peek(29)) {
        return this.parseBinary(59, node, precedence, 7);
      }

      if (this.peek(30)) {
        return this.parseBinary(44, node, precedence, 10);
      }

      if (this.peek(33)) {
        return this.parseBinary(60, node, precedence, 11);
      }

      if (this.peek(38)) {
        return this.parseBinary(61, node, precedence, 9);
      }

      if (this.peek(39)) {
        return this.parseBinary(62, node, precedence, 9);
      }

      if (this.peek(31)) {
        return this.parseUnaryPostfix(41, node, precedence);
      }

      if (this.peek(26)) {
        return this.parseUnaryPostfix(40, node, precedence);
      }

      if (this.peek(41) && precedence < 13) {
        this.advance();
        var type = this.parseType();

        if (type === null) {
          return null;
        }

        return createCast(node, type).withRange(spanRanges(node.range, type.range)).withInternalRange(token);
      }

      var isIndex = this.peek(19);

      if ((isIndex || this.peek(20)) && precedence < 14) {
        return this.parseArgumentList(node.range, isIndex ? createIndex(node) : createCall(node));
      }

      if (this.peek(32) && precedence < 1) {
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
    var isIndex = node.kind === 23;
    var left = isIndex ? 19 : 20;
    var right = isIndex ? 35 : 36;

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

    __declare.assert(node.range !== null);

    while (true) {
      var result = this.parseInfix(precedence, node, mode);

      if (result === null) {
        return null;
      }

      if (result === node) {
        break;
      }

      node = result;
      __declare.assert(node.range !== null);
    }

    return node;
  };

  ParserContext.prototype.parseType = function() {
    return this.parseExpression(14, 1);
  };

  ParserContext.prototype.parseIf = function() {
    var token = this.current;
    __declare.assert(token.kind === 54);
    this.advance();

    if (!this.expect(20)) {
      return null;
    }

    var value = null;

    if (this.peek(36)) {
      this.unexpectedToken();
      this.advance();
      value = createParseError();
    }

    else {
      value = this.parseExpression(0, 0);

      if (value === null || !this.expect(36)) {
        return null;
      }
    }

    var trueBranch = this.parseBody();

    if (trueBranch === null) {
      return null;
    }

    var falseBranch = null;

    if (this.eat(47)) {
      falseBranch = this.parseBody();

      if (falseBranch === null) {
        return null;
      }
    }

    return createIf(value, trueBranch, falseBranch).withRange(spanRanges(token.range, (falseBranch !== null ? falseBranch : trueBranch).range));
  };

  ParserContext.prototype.parseWhile = function() {
    var token = this.current;
    __declare.assert(token.kind === 72);
    this.advance();

    if (!this.expect(20)) {
      return null;
    }

    var value = null;

    if (this.peek(36)) {
      this.unexpectedToken();
      this.advance();
      value = createParseError();
    }

    else {
      value = this.parseExpression(0, 0);

      if (value === null || !this.expect(36)) {
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

    if (node.kind === 3) {
      return node;
    }

    var block = createBlock();
    block.appendChild(node);

    return block.withRange(node.range);
  };

  ParserContext.prototype.parseBlock = function() {
    var open = this.current;

    if (!this.expect(18)) {
      return null;
    }

    var block = createBlock();

    if (!this.parseStatements(block)) {
      return null;
    }

    var close = this.current;

    if (!this.expect(34)) {
      return null;
    }

    return block.withRange(spanRanges(open.range, close.range));
  };

  ParserContext.prototype.parseReturn = function() {
    var token = this.current;
    __declare.assert(token.kind === 65);
    this.advance();
    var value = null;

    if (!this.peek(37)) {
      value = this.parseExpression(0, 0);

      if (value === null) {
        return null;
      }
    }

    var semicolon = this.current;
    this.expect(37);

    return createReturn(value).withRange(spanRanges(token.range, semicolon.range));
  };

  ParserContext.prototype.parseEmpty = function() {
    var token = this.current;
    this.advance();

    return createEmpty().withRange(token.range);
  };

  ParserContext.prototype.parseEnum = function(firstFlag) {
    var token = this.current;
    __declare.assert(token.kind === 48);
    this.advance();
    var name = this.current;

    if (!this.expect(2) || !this.expect(18)) {
      return null;
    }

    var text = name.range.toString();
    var node = createEnum(text);
    node.firstFlag = firstFlag;
    node.flags = allFlags(firstFlag);

    while (!this.peek(0) && !this.peek(34)) {
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

      if (this.peek(37)) {
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

    if (!this.expect(34)) {
      return null;
    }

    return node.withRange(spanRanges(token.range, close.range)).withInternalRange(name.range);
  };

  ParserContext.prototype.parseClass = function(firstFlag) {
    var token = this.current;
    __declare.assert(token.kind === 43);
    this.advance();
    var name = this.current;

    if (!this.expect(2) || !this.expect(18)) {
      return null;
    }

    var node = createClass(name.range.toString());
    node.firstFlag = firstFlag;
    node.flags = allFlags(firstFlag);

    while (!this.peek(0) && !this.peek(34)) {
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

      if (text === "operator" && !this.peek(20) && !this.peek(2)) {
        childName.kind = 61;
        this.current = childName;

        if (this.parseFunction(childFlags, node) === null) {
          return null;
        }

        continue;
      }

      else if (this.peek(2)) {
        var isGet = text === "get";
        var isSet = text === "set";

        if (isGet || isSet) {
          childFlags = appendFlag(childFlags, isGet ? 8 : 512, childName.range);
          childName = this.current;
          this.advance();
        }

        else if (oldKind === 53) {
          this.log.error(childName.range, "Instance functions don't need the 'function' keyword");
          childName = this.current;
          this.advance();
        }

        else if (oldKind === 44 || oldKind === 58 || oldKind === 71) {
          this.log.error(childName.range, StringBuilder_new().append("Instance variables don't need the '").append(childName.range.toString()).append("' keyword").finish());
          childName = this.current;
          this.advance();
        }
      }

      if (this.peek(20)) {
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

    if (!this.expect(34)) {
      return null;
    }

    return node.withRange(spanRanges(token.range, close.range)).withInternalRange(name.range);
  };

  ParserContext.prototype.parseFunction = function(firstFlag, parent) {
    var isOperator = false;
    var token = this.current;
    var nameRange = null;
    var name = null;

    if (parent !== null && this.eat(61)) {
      var end = this.current;

      if (this.eat(19)) {
        if (!this.expect(35)) {
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

        isOperator = true;
      }

      else if (this.eat(6) || this.eat(7) || this.eat(8) || this.eat(11) || this.eat(12) || this.eat(14) || this.eat(15) || this.eat(21) || this.eat(16) || this.eat(25) || this.eat(26) || this.eat(27) || this.eat(30) || this.eat(31) || this.eat(33) || this.eat(38) || this.eat(39)) {
        nameRange = end.range;
        name = nameRange.toString();
        isOperator = true;
      }

      else if (this.eat(5) || this.eat(17) || this.eat(22) || this.eat(23) || this.eat(24) || this.eat(28) || this.eat(29)) {
        nameRange = end.range;
        name = nameRange.toString();
        this.log.error(nameRange, StringBuilder_new().append("The operator '").append(name).append("' cannot be implemented").append(end.kind === 29 ? " (it is automatically derived from '==')" : end.kind === 22 ? " (it is automatically derived from '>')" : end.kind === 17 ? " (it is automatically derived from '<')" : "").finish());
      }

      else {
        this.unexpectedToken();
      }
    }

    else {
      if (parent === null) {
        __declare.assert(token.kind === 53);
        this.advance();
      }

      nameRange = this.current.range;

      if (!this.expect(2)) {
        return null;
      }

      name = nameRange.toString();
    }

    if (!this.expect(20)) {
      return null;
    }

    var node = createFunction(name);
    node.firstFlag = firstFlag;
    node.flags = allFlags(firstFlag);

    if (isOperator) {
      node.flags = node.flags | 16;
    }

    if (!this.peek(36)) {
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

          else if (this.peek(10) || this.peek(36)) {
            type = createParseError();
          }

          else {
            return null;
          }
        }

        else if (this.peek(10) || this.peek(36)) {
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

    if (!this.expect(36)) {
      return null;
    }

    var returnType = null;

    if (this.expect(9)) {
      returnType = this.parseType();

      if (returnType === null) {
        if (this.peek(37) || this.peek(18)) {
          returnType = createParseError();
        }

        else {
          return null;
        }
      }
    }

    else if (this.peek(37) || this.peek(18)) {
      returnType = createParseError();
    }

    else {
      return null;
    }

    node.appendChild(returnType);
    var block = null;
    var semicolon = this.current;

    if (this.eat(37)) {
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
      __declare.assert(token.kind === 44 || token.kind === 58 || token.kind === 71);
      this.advance();
    }

    var node = token.kind === 44 ? createConstants() : createVariables();
    node.firstFlag = firstFlag;

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
    this.expect(37);

    return node.withRange(spanRanges(token.range, semicolon.range));
  };

  ParserContext.prototype.parseLoopJump = function(kind) {
    var token = this.current;
    this.advance();
    this.expect(37);
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

      if (this.eat(46)) {
        flag = 1;
      }

      else if (this.eat(49)) {
        flag = 2;
      }

      else if (this.eat(51)) {
        flag = 4;
      }

      else if (this.eat(62)) {
        flag = 64;
      }

      else if (this.eat(63)) {
        flag = 128;
      }

      else if (this.eat(64)) {
        flag = 256;
      }

      else if (this.eat(67)) {
        flag = 1024;
      }

      else if (this.eat(70)) {
        flag = 2048;
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

    node.flags = node.flags | 2048;

    return node.withRange(spanRanges(token.range, node.range));
  };

  ParserContext.prototype.parseStatement = function(mode) {
    var firstFlag = mode === 1 ? this.parseFlags() : null;

    if (this.peek(70) && firstFlag === null) {
      return this.parseUnsafe();
    }

    if (this.peek(44) || this.peek(58) || this.peek(71)) {
      return this.parseVariables(firstFlag, null);
    }

    if (this.peek(53)) {
      return this.parseFunction(firstFlag, null);
    }

    if (this.peek(43)) {
      return this.parseClass(firstFlag);
    }

    if (this.peek(48)) {
      return this.parseEnum(firstFlag);
    }

    if (firstFlag !== null) {
      this.unexpectedToken();

      return null;
    }

    if (this.peek(18)) {
      return this.parseBlock();
    }

    if (this.peek(42)) {
      return this.parseLoopJump(4);
    }

    if (this.peek(45)) {
      return this.parseLoopJump(7);
    }

    if (this.peek(54)) {
      return this.parseIf();
    }

    if (this.peek(72)) {
      return this.parseWhile();
    }

    if (this.peek(65)) {
      return this.parseReturn();
    }

    if (this.peek(37)) {
      return this.parseEmpty();
    }

    var value = this.parseExpression(0, 0);

    if (value === null) {
      return null;
    }

    var semicolon = this.current;
    this.expect(37);

    return createExpression(value).withRange(spanRanges(value.range, semicolon.range));
  };

  ParserContext.prototype.parseStatements = function(parent) {
    while (!this.peek(0) && !this.peek(34)) {
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

    if (string_op_get(contents, i) === 48 && (i + 1 | 0) < limit) {
      var c = string_op_get(contents, i + 1 | 0);

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
      var c = string_op_get(contents, i);
      var digit = (c >= 65 && c <= 70 ? c - 55 | 0 : c >= 97 && c <= 102 ? c - 87 | 0 : c - 48 >>> 0) >>> 0;
      var baseValue = __imul(value, base) >>> 0;

      if (baseValue / base >>> 0 !== value || baseValue > 4294967295 - digit >>> 0) {
        this.log.error(range, "Integer literal is too big to fit in 32 bits");

        return false;
      }

      value = baseValue + digit >>> 0;
      i = i + 1 | 0;
    }

    node.intValue = value | 0;
    node.flags = 32;

    return true;
  };

  function parse(firstToken, log) {
    var context = new ParserContext();
    context.current = firstToken;
    context.log = log;
    var file = new Node();
    file.kind = 0;

    if (!context.parseStatements(file)) {
      return null;
    }

    return file;
  }

  function PreprocessorFlag() {
    this.isDefined = false;
    this.name = null;
    this.next = null;
  }

  function Preprocessor() {
    this.firstFlag = null;
    this.isDefineAndUndefAllowed = false;
    this.previous = null;
    this.current = null;
    this.log = null;
  }

  Preprocessor.prototype.peek = function(kind) {
    return this.current.kind === kind;
  };

  Preprocessor.prototype.eat = function(kind) {
    if (this.peek(kind)) {
      this.advance();

      return true;
    }

    return false;
  };

  Preprocessor.prototype.advance = function() {
    if (!this.peek(0)) {
      this.previous = this.current;
      this.current = this.current.next;
    }
  };

  Preprocessor.prototype.unexpectedToken = function() {
    this.log.error(this.current.range, StringBuilder_new().append("Unexpected ").append(tokenToString(this.current.kind)).finish());
  };

  Preprocessor.prototype.expect = function(kind) {
    if (!this.peek(kind)) {
      this.log.error(this.current.range, StringBuilder_new().append("Expected ").append(tokenToString(kind)).append(" but found ").append(tokenToString(this.current.kind)).finish());

      return false;
    }

    this.advance();

    return true;
  };

  Preprocessor.prototype.removeTokensFrom = function(before) {
    before.next = this.current;
    this.previous = before;
  };

  Preprocessor.prototype.isDefined = function(name) {
    var flag = this.firstFlag;

    while (flag !== null) {
      if (flag.name === name) {
        return flag.isDefined;
      }

      flag = flag.next;
    }

    return false;
  };

  Preprocessor.prototype.define = function(name, isDefined) {
    var flag = new PreprocessorFlag();
    flag.isDefined = isDefined;
    flag.name = name;
    flag.next = this.firstFlag;
    this.firstFlag = flag;
  };

  Preprocessor.prototype.run = function(source, log) {
    var firstToken = source.firstToken;

    if (firstToken !== null && firstToken.kind === 79) {
      var firstFlag = this.firstFlag;
      this.isDefineAndUndefAllowed = true;
      this.previous = firstToken;
      this.current = firstToken.next;
      this.log = log;

      if (!this.scan(true)) {
        source.firstToken = null;

        return;
      }

      if (!this.peek(0)) {
        this.unexpectedToken();
      }

      this.firstFlag = firstFlag;
      source.firstToken = source.firstToken.next;
    }
  };

  Preprocessor.prototype.scan = function(isParentLive) {
    while (!this.peek(0) && !this.peek(74) && !this.peek(75) && !this.peek(76)) {
      var previous = this.previous;
      var current = this.current;

      if (this.eat(73) || this.eat(81)) {
        if (this.expect(2) && isParentLive) {
          this.define(this.previous.range.toString(), current.kind === 73);
        }

        if (this.eat(52) || this.eat(3) && this.previous.range.toString() === "0") {
          this.log.error(this.previous.range, "Use '#undef' to turn a preprocessor flag off");
        }

        if (!this.peek(0) && !this.expect(80)) {
          while (!this.eat(80) && !this.eat(0)) {
            this.advance();
          }
        }

        if (!this.isDefineAndUndefAllowed) {
          this.log.error(spanRanges(current.range, this.previous.range), "All '#define' and '#undef' directives must be at the top of the file");
        }

        this.removeTokensFrom(previous);
      }

      else if (this.eat(82) || this.eat(77)) {
        var next = this.current;

        while (!this.peek(80) && !this.peek(0)) {
          this.advance();
        }

        if (isParentLive) {
          var range = this.current === next ? current.range : spanRanges(next.range, this.previous.range);
          this.log.append(range, range.toString(), current.kind === 82 ? 1 : 0);
        }

        this.eat(80);
        this.removeTokensFrom(previous);
      }

      else if (this.eat(78)) {
        var isLive = isParentLive;

        while (true) {
          var condition = this.parseExpression(0);

          if (condition === 2 || !this.expect(80)) {
            return false;
          }

          this.removeTokensFrom(previous);

          if (!this.scan(isLive && condition === 1)) {
            return false;
          }

          if (!isLive || condition === 0) {
            this.removeTokensFrom(previous);
          }

          else {
            isLive = false;
          }

          previous = this.previous;

          if (this.eat(74)) {
            continue;
          }

          if (this.eat(75)) {
            if (!this.expect(80)) {
              return false;
            }

            this.removeTokensFrom(previous);

            if (!this.scan(isLive)) {
              return false;
            }

            if (!isLive) {
              this.removeTokensFrom(previous);
            }
          }

          break;
        }

        previous = this.previous;

        if (!this.expect(76) || !this.peek(0) && !this.expect(80)) {
          return false;
        }

        this.removeTokensFrom(previous);
      }

      else {
        this.isDefineAndUndefAllowed = false;
        this.advance();
      }
    }

    return true;
  };

  Preprocessor.prototype.parsePrefix = function() {
    var isDefinedOperator = false;
    var start = this.current;

    if (this.eat(69)) {
      return 1;
    }

    if (this.eat(52)) {
      return 0;
    }

    if (this.eat(2)) {
      var name = this.previous.range.toString();

      if (this.peek(20) && name === "defined") {
        isDefinedOperator = true;
      }

      else {
        var isTrue = this.isDefined(name);

        return isTrue ? 1 : 0;
      }
    }

    if (this.eat(28)) {
      var value = this.parseExpression(13);

      if (value === 2) {
        return 2;
      }

      return value === 1 ? 0 : 1;
    }

    if (this.eat(20)) {
      var first = this.current;
      var value = this.parseExpression(0);

      if (value === 2 || !this.expect(36)) {
        return 2;
      }

      if (isDefinedOperator) {
        var builder = StringBuilder_new().append("There is no 'defined' operator");

        if (first.kind === 2 && this.previous === first.next) {
          builder.append(" (just use '").append(first.range.toString()).append("' instead)");
        }

        this.log.error(spanRanges(start.range, this.previous.range), builder.finish());
      }

      return value;
    }

    if (this.eat(3)) {
      var isTrue = this.previous.range.toString() !== "0";
      this.log.error(this.previous.range, StringBuilder_new().append("Unexpected integer (did you mean '").append(isTrue ? "true" : "false").append("')?").finish());

      return isTrue ? 1 : 0;
    }

    this.unexpectedToken();

    return 2;
  };

  Preprocessor.prototype.parseInfix = function(precedence, left) {
    var operator = this.current.kind;

    if (precedence < 7 && (this.eat(14) || this.eat(29))) {
      var right = this.parseExpression(7);

      if (right === 2) {
        return 2;
      }

      return operator === 14 === (left === right) ? 1 : 0;
    }

    if (precedence < 3 && this.eat(23)) {
      var right = this.parseExpression(3);

      if (right === 2) {
        return 2;
      }

      return left === 1 && right === 1 ? 1 : 0;
    }

    if (precedence < 2 && this.eat(24)) {
      var right = this.parseExpression(2);

      if (right === 2) {
        return 2;
      }

      return left === 1 || right === 1 ? 1 : 0;
    }

    if (precedence === 0 && this.eat(32)) {
      var middle = this.parseExpression(0);

      if (middle === 2 || !this.expect(9)) {
        return 2;
      }

      var right = this.parseExpression(0);

      if (right === 2) {
        return 2;
      }

      return left === 1 ? middle : right;
    }

    return left;
  };

  Preprocessor.prototype.parseExpression = function(precedence) {
    var value = this.parsePrefix();

    if (value === 2) {
      return 2;
    }

    while (true) {
      var current = this.current;
      value = this.parseInfix(precedence, value);

      if (value === 2) {
        return 2;
      }

      if (this.current === current) {
        break;
      }
    }

    return value;
  };

  function Scope() {
    this.parent = null;
    this.symbol = null;
    this.firstSymbol = null;
    this.lastSymbol = null;
  }

  Scope.prototype.findLocal = function(name, hint) {
    var symbol = this.firstSymbol;
    var fallback = null;

    while (symbol !== null) {
      if (symbol.name === name) {
        if (hint === 5 && symbol.isSetter() || hint === 6 && symbol.isGetter()) {
          fallback = symbol;
        }

        else if ((hint !== 2 || !symbol.isGetter()) && (hint !== 3 || !symbol.isSetter()) && (hint !== 1 || !symbol.isBinaryOperator()) && (hint !== 4 || !symbol.isUnaryOperator())) {
          return symbol;
        }
      }

      symbol = symbol.next;
    }

    return fallback;
  };

  Scope.prototype.findNested = function(name, hint, mode) {
    var scope = this;

    while (scope !== null) {
      if (scope.symbol === null || scope.symbol.kind !== 0 || mode === 1) {
        var local = scope.findLocal(name, hint);

        if (local !== null) {
          return local;
        }
      }

      scope = scope.parent;
    }

    return null;
  };

  Scope.prototype.define = function(log, symbol, hint) {
    var existing = this.findLocal(symbol.name, hint);

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

  Scope.prototype.defineNativeType = function(log, name) {
    var symbol = new Symbol();
    symbol.kind = 3;
    symbol.name = name;
    symbol.resolvedType = new Type();
    symbol.resolvedType.symbol = symbol;
    symbol.state = 2;
    this.define(log, symbol, 0);

    return symbol.resolvedType;
  };

  function treeShakingMarkAllUsed(node) {
    var symbol = node.symbol;

    if (symbol !== null && !symbol.isUsed() && isFunction(symbol.kind) && symbol.node !== null) {
      symbol.flags = symbol.flags | 64;
      treeShakingMarkAllUsed(symbol.node);

      if (node === symbol.node) {
        return;
      }
    }

    if (node.kind === 26) {
      var type = node.newType().resolvedType;

      if (type.symbol !== null) {
        type.symbol.flags = type.symbol.flags | 64;
      }
    }

    var child = node.firstChild;

    while (child !== null) {
      treeShakingMarkAllUsed(child);
      child = child.nextSibling;
    }
  }

  function treeShakingSearchForUsed(node) {
    if (node.kind === 11 && node.isExtern()) {
      treeShakingMarkAllUsed(node);
    }

    else if (node.kind === 1 || node.kind === 5) {
      var child = node.firstChild;

      while (child !== null) {
        treeShakingSearchForUsed(child);
        child = child.nextSibling;
      }

      if (node.kind === 5 && node.isExtern()) {
        node.symbol.flags = node.symbol.flags | 64;
      }
    }
  }

  function treeShakingRemoveUnused(node) {
    if (node.kind === 11 && !node.symbol.isUsed() && node.range.source.isLibrary) {
      node.remove();
    }

    else if (node.kind === 1 || node.kind === 5) {
      var child = node.firstChild;

      while (child !== null) {
        var next = child.nextSibling;
        treeShakingRemoveUnused(child);
        child = next;
      }

      if (node.kind === 5 && !node.symbol.isUsed() && !node.isDeclare() && node.range.source.isLibrary) {
        node.remove();
      }
    }
  }

  function treeShaking(node) {
    treeShakingSearchForUsed(node);
    treeShakingRemoveUnused(node);
  }

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

  function StringBuilder_appendQuoted(sb, text) {
    var end = 0;
    var limit = text.length;
    var start = end;
    sb.appendChar(34);

    while (end < limit) {
      var c = string_op_get(text, end);

      if (c === 34) {
        sb.appendSlice(text, start, end).append("\\\"");
      }

      else if (c === 0) {
        sb.appendSlice(text, start, end).append("\\0");
      }

      else if (c === 9) {
        sb.appendSlice(text, start, end).append("\\t");
      }

      else if (c === 13) {
        sb.appendSlice(text, start, end).append("\\r");
      }

      else if (c === 10) {
        sb.appendSlice(text, start, end).append("\\n");
      }

      else if (c === 92) {
        sb.appendSlice(text, start, end).append("\\\\");
      }

      else {
        end = end + 1 | 0;

        continue;
      }

      end = end + 1 | 0;
      start = end;
    }

    sb.appendSlice(text, start, end).appendChar(34);
  }

  function StringBuilder() {
    this.next = null;
    this._text = null;
  }

  StringBuilder.prototype.clear = function() {
    this._text = "";
  };

  StringBuilder.prototype.appendChar = function(c) {
    this._text = __declare.StringBuilder_appendChar(this._text, c);

    return this;
  };

  StringBuilder.prototype.appendSlice = function(text, start, end) {
    this._text = __declare.StringBuilder_append(this._text, text.slice(start, end));

    return this;
  };

  StringBuilder.prototype.append = function(text) {
    this._text = __declare.StringBuilder_append(this._text, text);

    return this;
  };

  StringBuilder.prototype.finish = function() {
    this.next = stringBuilderPool;
    stringBuilderPool = this;

    return this._text;
  };

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
    this.rename = null;
    this.offset = 0;
  }

  Symbol.prototype.isEnumValue = function() {
    return this.node.parent.kind === 9;
  };

  Symbol.prototype.isUnsafe = function() {
    return this.node !== null && this.node.isUnsafe();
  };

  Symbol.prototype.isGetter = function() {
    return this.node.isGet();
  };

  Symbol.prototype.isSetter = function() {
    return this.node.isSet();
  };

  Symbol.prototype.isBinaryOperator = function() {
    return (this.flags & 2) !== 0;
  };

  Symbol.prototype.isUnaryOperator = function() {
    return (this.flags & 8) !== 0;
  };

  Symbol.prototype.shouldConvertInstanceToGlobal = function() {
    return (this.flags & 1) !== 0;
  };

  Symbol.prototype.isUsed = function() {
    return (this.flags & 64) !== 0;
  };

  Symbol.prototype.parent = function() {
    var parent = this.node.parent;

    return parent.kind === 5 ? parent.symbol : null;
  };

  Symbol.prototype.resolvedTypeUnderlyingIfEnumValue = function(context) {
    return this.isEnumValue() ? this.resolvedType.underlyingType(context) : this.resolvedType;
  };

  Symbol.prototype.determineClassLayout = function(context) {
    __declare.assert(this.kind === 0);

    if (this.byteSize !== 0) {
      return;
    }

    var offset = 0;
    var child = this.node.firstChild;
    var maxAlignment = 1;

    while (child !== null) {
      if (child.kind === 2) {
        var type = child.symbol.resolvedType;

        if (type !== context.errorType) {
          var alignmentOf = type.variableAlignmentOf(context);
          offset = alignToNextMultipleOf(offset, alignmentOf);

          if (alignmentOf > maxAlignment) {
            maxAlignment = alignmentOf;
          }

          child.symbol.offset = offset;
          offset = offset + type.variableSizeOf(context) | 0;
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
    this.pointerTo = null;
    this.cachedToString = null;
    this.cachedPointerType = null;
  }

  Type.prototype.isClass = function() {
    return this.symbol !== null && this.symbol.kind === 0;
  };

  Type.prototype.isEnum = function() {
    return this.symbol !== null && this.symbol.kind === 1;
  };

  Type.prototype.isInteger = function() {
    return this.symbol !== null && (this.symbol.flags & 32) !== 0 || this.isEnum();
  };

  Type.prototype.isUnsigned = function() {
    return this.symbol !== null && (this.symbol.flags & 16) !== 0;
  };

  Type.prototype.isReference = function() {
    return this.pointerTo !== null || this.symbol !== null && (this.symbol.flags & 4) !== 0;
  };

  Type.prototype.underlyingType = function(context) {
    return this.isEnum() ? context.intType : this.pointerTo !== null ? context.uintType : this;
  };

  Type.prototype.integerBitCount = function(context) {
    return this.symbol !== null ? this.symbol.byteSize << 3 : 0;
  };

  Type.prototype.integerBitMask = function(context) {
    return 4294967295 >>> ((32 - this.integerBitCount(context) | 0) >>> 0);
  };

  Type.prototype.allocationSizeOf = function(context) {
    return this.symbol === null ? context.pointerByteSize : this.symbol.byteSize;
  };

  Type.prototype.allocationAlignmentOf = function(context) {
    return this.allocationSizeOf(context);
  };

  Type.prototype.variableSizeOf = function(context) {
    return this.isReference() ? context.pointerByteSize : this.symbol.byteSize;
  };

  Type.prototype.variableAlignmentOf = function(context) {
    return this.variableSizeOf(context);
  };

  Type.prototype.pointerType = function() {
    var type = this.cachedPointerType;

    if (type === null) {
      type = new Type();
      type.pointerTo = this;
      this.cachedPointerType = type;
    }

    return type;
  };

  Type.prototype.toString = function() {
    if (this.cachedToString === null) {
      this.cachedToString = this.pointerTo !== null ? StringBuilder_new().appendChar(42).append(this.pointerTo.toString()).finish() : this.symbol.name;
    }

    return this.cachedToString;
  };

  Type.prototype.findMember = function(name, hint) {
    var symbol = this.symbol;

    return symbol !== null && symbol.scope !== null ? symbol.scope.findLocal(name, hint) : null;
  };

  Type.prototype.hasInstanceMembers = function() {
    var symbol = this.symbol;

    return symbol !== null && (symbol.kind === 0 || symbol.kind === 3);
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
    __declare.assert(a.returnType !== null);
    __declare.assert(b.returnType !== null);
    __declare.assert(a.returnType.next === null);
    __declare.assert(b.returnType.next === null);
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
    __declare.assert(returnType !== null);
    __declare.assert(returnType.next === null);
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
      wasmWriteLengthPrefixedASCII(array, current.module);
      wasmWriteLengthPrefixedASCII(array, current.name);
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
        wasmWriteLengthPrefixedASCII(array, fn.name);
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
    var initializerLength = memoryInitializer.length();
    var initialHeapPointer = alignToNextMultipleOf(initializerLength + 8 | 0, 8);
    ByteArray_set32(memoryInitializer, this.currentHeapPointer, initialHeapPointer);
    ByteArray_set32(memoryInitializer, this.originalHeapPointer, initialHeapPointer);
    var section = wasmStartSection(array, "data_segments");
    wasmWriteVarUnsigned(array, 1);
    wasmWriteVarUnsigned(array, 8);
    wasmWriteVarUnsigned(array, initializerLength);
    var i = 0;

    while (i < initializerLength) {
      array.append(memoryInitializer.get(i));
      i = i + 1 | 0;
    }

    wasmFinishSection(array, section);
  };

  WasmModule.prototype.prepareToEmit = function(node) {
    if (node.kind === 30) {
      var text = node.stringValue;
      var length = text.length;
      var offset = this.context.allocateGlobalVariableOffset((length << 1) + 4 | 0, 4);
      node.intValue = offset;
      this.growMemoryInitializer();
      var memoryInitializer = this.memoryInitializer;
      ByteArray_set32(memoryInitializer, offset, length);
      ByteArray_setString(memoryInitializer, offset + 4 | 0, text);
    }

    else if (node.kind === 2) {
      var symbol = node.symbol;

      if (symbol.kind === 8) {
        var sizeOf = symbol.resolvedType.variableSizeOf(this.context);
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
          __declare.assert(false);
        }

        if (symbol.name === "currentHeapPointer") {
          __declare.assert(this.currentHeapPointer === -1);
          this.currentHeapPointer = symbol.offset;
        }

        else if (symbol.name === "originalHeapPointer") {
          __declare.assert(this.originalHeapPointer === -1);
          this.originalHeapPointer = symbol.offset;
        }
      }
    }

    else if (node.kind === 11) {
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
        var moduleName = symbol.kind === 4 ? symbol.parent().name : "global";
        symbol.offset = this.importCount;
        this.allocateImport(signatureIndex, moduleName, symbol.name);
        node = node.nextSibling;

        return;
      }

      symbol.offset = this.functionCount;
      var fn = this.allocateFunction(symbol.name, signatureIndex, body);

      if (symbol.kind === 5 && symbol.name === "malloc") {
        __declare.assert(this.mallocFunctionIndex === -1);
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
    var sizeOf = type.variableSizeOf(this.context);

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
      __declare.assert(false);
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
    var sizeOf = type.variableSizeOf(this.context);

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
      __declare.assert(false);
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
    __declare.assert(!isExpression(node) || node.resolvedType !== null);

    if (node.kind === 3) {
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

    else if (node.kind === 16) {
      var value = node.whileValue();
      var body = node.whileBody();

      if (value.kind === 18 && value.intValue === 0) {
        return 0;
      }

      array.append(2);
      var offset = array.length();
      wasmWriteVarUnsigned(array, -1);
      var count = 0;

      if (value.kind !== 18) {
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

    else if (node.kind === 4 || node.kind === 7) {
      var label = 0;
      var parent = node.parent;

      while (parent !== null && parent.kind !== 16) {
        if (parent.kind === 3) {
          label = label + 1 | 0;
        }

        parent = parent.parent;
      }

      __declare.assert(label > 0);
      array.append(6);
      wasmWriteVarUnsigned(array, label - (node.kind === 4 ? 0 : 1) | 0);
      array.append(0);
    }

    else if (node.kind === 8) {
      return 0;
    }

    else if (node.kind === 10) {
      this.emitNode(array, node.expressionValue());
    }

    else if (node.kind === 13) {
      var value = node.returnValue();
      array.append(20);

      if (value !== null) {
        this.emitNode(array, value);
      }
    }

    else if (node.kind === 15) {
      var count = 0;
      var child = node.firstChild;

      while (child !== null) {
        __declare.assert(child.kind === 2);
        count = count + this.emitNode(array, child) | 0;
        child = child.nextSibling;
      }

      return count;
    }

    else if (node.kind === 12) {
      var branch = node.ifFalse();
      array.append(branch === null ? 3 : 4);
      this.emitNode(array, node.ifValue());
      this.emitNode(array, node.ifTrue());

      if (branch !== null) {
        this.emitNode(array, branch);
      }
    }

    else if (node.kind === 22) {
      array.append(4);
      this.emitNode(array, node.hookValue());
      this.emitNode(array, node.hookTrue());
      this.emitNode(array, node.hookFalse());
    }

    else if (node.kind === 2) {
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
        __declare.assert(false);
      }
    }

    else if (node.kind === 25) {
      var symbol = node.symbol;

      if (symbol.kind === 6 || symbol.kind === 10) {
        array.append(14);
        wasmWriteVarUnsigned(array, symbol.offset);
      }

      else if (symbol.kind === 8) {
        this.emitLoadFromMemory(array, symbol.resolvedType, null, symbol.offset + 8 | 0);
      }

      else {
        __declare.assert(false);
      }
    }

    else if (node.kind === 35) {
      this.emitLoadFromMemory(array, node.resolvedType.underlyingType(this.context), node.unaryValue(), 0);
    }

    else if (node.kind === 27) {
      array.append(10);
      wasmWriteVarSigned(array, 0);
    }

    else if (node.kind === 24 || node.kind === 18) {
      array.append(10);
      wasmWriteVarSigned(array, node.intValue);
    }

    else if (node.kind === 30) {
      array.append(10);
      wasmWriteVarSigned(array, node.intValue + 8 | 0);
    }

    else if (node.kind === 19) {
      var value = node.callValue();
      var symbol = value.symbol;
      __declare.assert(isFunction(symbol.kind));
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

    else if (node.kind === 26) {
      var type = node.newType();
      var size = type.resolvedType.allocationSizeOf(this.context);
      array.append(18);
      wasmWriteVarUnsigned(array, this.mallocFunctionIndex);
      __declare.assert(size > 0);
      array.append(10);
      wasmWriteVarSigned(array, size);
    }

    else if (node.kind === 39) {
      this.emitNode(array, node.unaryValue());
    }

    else if (node.kind === 36) {
      array.append(65);
      array.append(10);
      wasmWriteVarSigned(array, 0);
      this.emitNode(array, node.unaryValue());
    }

    else if (node.kind === 34) {
      array.append(73);
      array.append(10);
      wasmWriteVarSigned(array, -1);
      this.emitNode(array, node.unaryValue());
    }

    else if (node.kind === 37) {
      array.append(90);
      this.emitNode(array, node.unaryValue());
    }

    else if (node.kind === 20) {
      var value = node.castValue();
      var context = this.context;
      var from = value.resolvedType.underlyingType(context);
      var type = node.resolvedType.underlyingType(context);
      var fromSize = from.variableSizeOf(context);
      var typeSize = type.variableSizeOf(context);

      if (from === type || fromSize < typeSize) {
        this.emitNode(array, value);
      }

      else if (type === context.sbyteType || type === context.shortType) {
        var shift = 32 - (typeSize << 3) | 0;
        array.append(76);
        array.append(74);
        this.emitNode(array, value);
        array.append(10);
        wasmWriteVarSigned(array, shift);
        array.append(10);
        wasmWriteVarSigned(array, shift);
      }

      else if (type === context.byteType || type === context.ushortType) {
        array.append(71);
        this.emitNode(array, value);
        array.append(10);
        wasmWriteVarSigned(array, type.integerBitMask(this.context) | 0);
      }

      else {
        this.emitNode(array, value);
      }
    }

    else if (node.kind === 21) {
      var symbol = node.symbol;

      if (symbol.kind === 9) {
        this.emitLoadFromMemory(array, symbol.resolvedType, node.dotTarget(), symbol.offset);
      }

      else {
        __declare.assert(false);
      }
    }

    else if (node.kind === 45) {
      var left = node.binaryLeft();
      var right = node.binaryRight();
      var symbol = left.symbol;

      if (left.kind === 35) {
        this.emitStoreToMemory(array, left.resolvedType.underlyingType(this.context), left.unaryValue(), 0, right);
      }

      else if (symbol.kind === 9) {
        this.emitStoreToMemory(array, symbol.resolvedType, left.dotTarget(), symbol.offset, right);
      }

      else if (symbol.kind === 8) {
        this.emitStoreToMemory(array, symbol.resolvedType, null, symbol.offset + 8 | 0, right);
      }

      else if (symbol.kind === 6 || symbol.kind === 10) {
        array.append(15);
        wasmWriteVarUnsigned(array, symbol.offset);
        this.emitNode(array, right);
      }

      else {
        __declare.assert(false);
      }
    }

    else if (node.kind === 56) {
      array.append(4);
      this.emitNode(array, node.binaryLeft());
      this.emitNode(array, node.binaryRight());
      array.append(10);
      wasmWriteVarSigned(array, 0);
    }

    else if (node.kind === 57) {
      array.append(4);
      this.emitNode(array, node.binaryLeft());
      array.append(10);
      wasmWriteVarSigned(array, 1);
      this.emitNode(array, node.binaryRight());
    }

    else {
      var isUnsigned = node.isUnsignedOperator();

      if (node.kind === 44) {
        var left = node.binaryLeft();
        var right = node.binaryRight();
        array.append(64);
        this.emitNode(array, left);

        if (left.resolvedType.pointerTo === null) {
          this.emitNode(array, right);
        }

        else {
          __declare.assert(right.resolvedType.isInteger());
          var size = left.resolvedType.pointerTo.allocationSizeOf(this.context);

          if (size === 2) {
            if (right.kind === 24) {
              array.append(10);
              wasmWriteVarSigned(array, right.intValue << 1);
            }

            else {
              array.append(74);
              this.emitNode(array, right);
              array.append(10);
              wasmWriteVarSigned(array, 1);
            }
          }

          else if (size === 4) {
            if (right.kind === 24) {
              array.append(10);
              wasmWriteVarSigned(array, right.intValue << 2);
            }

            else {
              array.append(74);
              this.emitNode(array, right);
              array.append(10);
              wasmWriteVarSigned(array, 2);
            }
          }

          else {
            this.emitNode(array, right);
          }
        }
      }

      else if (node.kind === 46) {
        this.emitBinaryExpression(array, node, 71);
      }

      else if (node.kind === 47) {
        this.emitBinaryExpression(array, node, 72);
      }

      else if (node.kind === 48) {
        this.emitBinaryExpression(array, node, 73);
      }

      else if (node.kind === 50) {
        this.emitBinaryExpression(array, node, 77);
      }

      else if (node.kind === 58) {
        this.emitBinaryExpression(array, node, 66);
      }

      else if (node.kind === 59) {
        this.emitBinaryExpression(array, node, 78);
      }

      else if (node.kind === 61) {
        this.emitBinaryExpression(array, node, 74);
      }

      else if (node.kind === 63) {
        this.emitBinaryExpression(array, node, 65);
      }

      else if (node.kind === 49) {
        this.emitBinaryExpression(array, node, isUnsigned ? 68 : 67);
      }

      else if (node.kind === 52) {
        this.emitBinaryExpression(array, node, isUnsigned ? 85 : 83);
      }

      else if (node.kind === 53) {
        this.emitBinaryExpression(array, node, isUnsigned ? 86 : 84);
      }

      else if (node.kind === 54) {
        this.emitBinaryExpression(array, node, isUnsigned ? 81 : 79);
      }

      else if (node.kind === 55) {
        this.emitBinaryExpression(array, node, isUnsigned ? 82 : 80);
      }

      else if (node.kind === 60) {
        this.emitBinaryExpression(array, node, isUnsigned ? 70 : 69);
      }

      else if (node.kind === 62) {
        this.emitBinaryExpression(array, node, isUnsigned ? 75 : 76);
      }

      else {
        __declare.assert(false);
      }
    }

    return 1;
  };

  WasmModule.prototype.getWasmType = function(type) {
    var context = this.context;

    if (type === context.boolType || type.isInteger() || type.isReference()) {
      return 1;
    }

    if (type === context.voidType) {
      return 0;
    }

    __declare.assert(false);

    return 0;
  };

  function wasmPatchVarUnsigned(array, offset, value, maxValue) {
    var current = value >>> 0;
    var max = maxValue >>> 0;

    while (true) {
      var element = current & 127;
      current = current >>> 7;
      max = max >>> 7;

      if (max !== 0) {
        element = element | 128;
      }

      array.set(offset, element & 255);
      offset = offset + 1 | 0;

      if (max === 0) {
        break;
      }
    }
  }

  function wasmWriteVarUnsigned(array, value) {
    var current = value >>> 0;

    while (true) {
      var element = current & 127;
      current = current >>> 7;

      if (current !== 0) {
        element = element | 128;
      }

      array.append(element & 255);

      if (current === 0) {
        break;
      }
    }
  }

  function wasmWriteVarSigned(array, value) {
    while (true) {
      var element = value & 127;
      value = value >> 7;
      var done = value === 0 && (element & 64) === 0 || value === -1 && (element & 64) !== 0;

      if (!done) {
        element = element | 128;
      }

      array.append(element & 255);

      if (done) {
        break;
      }
    }
  }

  function wasmWriteLengthPrefixedASCII(array, value) {
    var length = value.length;
    wasmWriteVarUnsigned(array, length);
    var index = array.length();
    array.resize(index + length | 0);
    var i = 0;

    while (i < length) {
      array.set(index + i | 0, string_op_get(value, i) & 255);
      i = i + 1 | 0;
    }
  }

  function wasmStartSection(array, name) {
    var offset = array.length();
    wasmWriteVarUnsigned(array, -1);
    wasmWriteLengthPrefixedASCII(array, name);

    return offset;
  }

  function wasmFinishSection(array, offset) {
    wasmPatchVarUnsigned(array, offset, (array.length() - offset | 0) - 5 | 0, -1);
  }

  function wasmWrapType(id) {
    __declare.assert(id === 0 || id === 1);
    var type = new WasmWrappedType();
    type.id = id;

    return type;
  }

  function WasmSharedOffset() {
    this.nextLocalOffset = 0;
    this.intLocalCount = 0;
  }

  function wasmAssignLocalVariableOffsets(node, shared) {
    if (node.kind === 2) {
      __declare.assert(node.symbol.kind === 10);
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

  function wasmEmit(compiler) {
    var module = new WasmModule();
    module.context = compiler.context;
    module.memoryInitializer = new ByteArray();
    module.mallocFunctionIndex = -1;
    module.currentHeapPointer = -1;
    module.originalHeapPointer = -1;
    module.prepareToEmit(compiler.global);
    __declare.assert(module.mallocFunctionIndex !== -1);
    __declare.assert(module.currentHeapPointer !== -1);
    __declare.assert(module.originalHeapPointer !== -1);
    compiler.output_wasm = new ByteArray();
    module.emitModule(compiler.output_wasm);
  }

  var __imul = Math.imul || function(a, b) {
    return (a * (b >>> 16) << 16) + a * (b & 65535) | 0;
  };
}(
  typeof global !== 'undefined' ? global : this,
  typeof exports !== 'undefined' ? exports : this
));
