class JsResult {
  context: CheckContext;
  code: String;
  indent: int;

  appendIndent(): void {
    var i = this.indent;
    while (i > 0) {
      this.code = String_appendNew(this.code, "  ");
      i = i - 1;
    }
  }

  emitText(text: string): void {
    this.code = String_appendNew(this.code, text);
  }

  emitString(text: String): void {
    this.code = String_append(this.code, text);
  }

  emitBlock(node: Node): void {
    this.emitText("{\n");
    this.indent = this.indent + 1;
    var child = node.firstChild;

    while (child != null) {
      this.emitStatement(child);
      child = child.nextSibling;
    }

    this.indent = this.indent - 1;
    this.appendIndent();
    this.emitText("}");
  }

  emitUnary(node: Node, parentPrecedence: int, operator: string): void {
    var isPostfix = isUnaryPostfix(node.kind);
    var operatorPrecedence = isPostfix ? PRECEDENCE_UNARY_POSTFIX : PRECEDENCE_UNARY_PREFIX;

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
  }

  emitBinary(node: Node, parentPrecedence: int, operator: string, operatorPrecedence: int): void {
    var isRightAssociative = node.kind == NODE_ASSIGN;

    if (parentPrecedence > operatorPrecedence) {
      this.emitText("(");
    }

    this.emitExpression(node.binaryLeft(), isRightAssociative ? operatorPrecedence + 1 : operatorPrecedence);
    this.emitText(operator);
    this.emitExpression(node.binaryRight(), isRightAssociative ? operatorPrecedence : operatorPrecedence + 1);

    if (parentPrecedence > operatorPrecedence) {
      this.emitText(")");
    }
  }

  emitExpression(node: Node, parentPrecedence: int): void {
    if (node.kind == NODE_NAME) {
      this.emitString(node.symbol.name);
    }

    else if (node.kind == NODE_NULL) {
      this.emitText("null");
    }

    else if (node.kind == NODE_BOOL) {
      this.emitText(node.intValue != 0 ? "true" : "false");
    }

    else if (node.kind == NODE_INT) {
      this.emitString(String_toString(node.intValue));
    }

    else if (node.kind == NODE_STRING) {
      this.emitString(String_quote(node.stringValue));
    }

    else if (node.kind == NODE_DOT) {
      this.emitExpression(node.dotTarget(), PRECEDENCE_MEMBER);
      this.emitText(".");
      this.emitString(node.symbol.name);
    }

    else if (node.kind == NODE_HOOK) {
      if (parentPrecedence > PRECEDENCE_ASSIGN) {
        this.emitText("(");
      }

      this.emitExpression(node.hookValue(), PRECEDENCE_LOGICAL_OR);
      this.emitText(" ? ");
      this.emitExpression(node.hookTrue(), PRECEDENCE_ASSIGN);
      this.emitText(" : ");
      this.emitExpression(node.hookFalse(), PRECEDENCE_ASSIGN);

      if (parentPrecedence > PRECEDENCE_ASSIGN) {
        this.emitText(")");
      }
    }

    else if (node.kind == NODE_CALL) {
      var value = node.callValue();
      if (value.symbol.node.functionBody() == null) {
        this.emitText("__imports.");
      }
      this.emitExpression(value, PRECEDENCE_UNARY_POSTFIX);
      this.emitText("(");

      var child = value.nextSibling;
      while (child != null) {
        this.emitExpression(child, PRECEDENCE_LOWEST);
        child = child.nextSibling;
        if (child != null) {
          this.emitText(", ");
        }
      }

      this.emitText(")");
    }

    else if (node.kind == NODE_NEW) {
      this.emitText("new ");
      this.emitExpression(node.newType(), PRECEDENCE_UNARY_POSTFIX);
      this.emitText("()");
    }

    else if (node.kind == NODE_COMPLEMENT) this.emitUnary(node, parentPrecedence, "~");
    else if (node.kind == NODE_NEGATIVE) this.emitUnary(node, parentPrecedence, "-");
    else if (node.kind == NODE_NOT) this.emitUnary(node, parentPrecedence, "!");
    else if (node.kind == NODE_POSITIVE) this.emitUnary(node, parentPrecedence, "+");
    else if (node.kind == NODE_PREFIX_INCREMENT) this.emitUnary(node, parentPrecedence, "++");
    else if (node.kind == NODE_PREFIX_DECREMENT) this.emitUnary(node, parentPrecedence, "--");
    else if (node.kind == NODE_POSTFIX_INCREMENT) this.emitUnary(node, parentPrecedence, "++");
    else if (node.kind == NODE_POSTFIX_DECREMENT) this.emitUnary(node, parentPrecedence, "--");

    else if (node.kind == NODE_ADD) this.emitBinary(node, parentPrecedence, " + ", PRECEDENCE_ADD);
    else if (node.kind == NODE_ASSIGN) this.emitBinary(node, parentPrecedence, " = ", PRECEDENCE_ASSIGN);
    else if (node.kind == NODE_BITWISE_AND) this.emitBinary(node, parentPrecedence, " & ", PRECEDENCE_BITWISE_AND);
    else if (node.kind == NODE_BITWISE_OR) this.emitBinary(node, parentPrecedence, " | ", PRECEDENCE_BITWISE_OR);
    else if (node.kind == NODE_BITWISE_XOR) this.emitBinary(node, parentPrecedence, " ^ ", PRECEDENCE_BITWISE_XOR);
    else if (node.kind == NODE_DIVIDE) this.emitBinary(node, parentPrecedence, " / ", PRECEDENCE_MULTIPLY); // TODO: This isn't accurate for integer division
    else if (node.kind == NODE_EQUAL) this.emitBinary(node, parentPrecedence, " === ", PRECEDENCE_EQUAL);
    else if (node.kind == NODE_GREATER_THAN) this.emitBinary(node, parentPrecedence, " > ", PRECEDENCE_COMPARE);
    else if (node.kind == NODE_GREATER_THAN_EQUAL) this.emitBinary(node, parentPrecedence, " >= ", PRECEDENCE_COMPARE);
    else if (node.kind == NODE_LESS_THAN) this.emitBinary(node, parentPrecedence, " < ", PRECEDENCE_COMPARE);
    else if (node.kind == NODE_LESS_THAN_EQUAL) this.emitBinary(node, parentPrecedence, " <= ", PRECEDENCE_COMPARE);
    else if (node.kind == NODE_LOGICAL_AND) this.emitBinary(node, parentPrecedence, " && ", PRECEDENCE_LOGICAL_AND);
    else if (node.kind == NODE_LOGICAL_OR) this.emitBinary(node, parentPrecedence, " || ", PRECEDENCE_LOGICAL_OR);
    else if (node.kind == NODE_MULTIPLY) this.emitBinary(node, parentPrecedence, " * ", PRECEDENCE_MULTIPLY);
    else if (node.kind == NODE_NOT_EQUAL) this.emitBinary(node, parentPrecedence, " !== ", PRECEDENCE_EQUAL);
    else if (node.kind == NODE_REMAINDER) this.emitBinary(node, parentPrecedence, " % ", PRECEDENCE_MULTIPLY);
    else if (node.kind == NODE_SHIFT_LEFT) this.emitBinary(node, parentPrecedence, " << ", PRECEDENCE_SHIFT);
    else if (node.kind == NODE_SHIFT_RIGHT) this.emitBinary(node, parentPrecedence, " >> ", PRECEDENCE_SHIFT);
    else if (node.kind == NODE_SUBTRACT) this.emitBinary(node, parentPrecedence, " - ", PRECEDENCE_ADD);

    else {
      assert(false);
    }
  }

  emitStatement(node: Node): void {
    if (node.kind == NODE_FUNCTION) {
      var body = node.functionBody();
      if (body == null) {
        return;
      }

      var needsSemicolon = false;
      this.appendIndent();

      if (node.parent.kind == NODE_CLASS) {
        this.emitString(node.parent.symbol.name);
        this.emitText(".prototype.");
        this.emitString(node.symbol.name);
        this.emitText(" = function");
        needsSemicolon = true;
      }

      else if (isExternSymbol(node.symbol)) {
        this.emitText("var ");
        this.emitString(node.symbol.name);
        this.emitText(" = exports.");
        this.emitString(node.symbol.name);
        this.emitText(" = function");
        needsSemicolon = true;
      }

      else {
        this.emitText("function ");
        this.emitString(node.symbol.name);
      }

      this.emitText("(");

      var returnType = node.functionReturnType();
      var child = node.functionFirstArgumentIgnoringThis();

      while (child != returnType) {
        assert(child.kind == NODE_VARIABLE);
        this.emitString(child.symbol.name);
        child = child.nextSibling;
        if (child != returnType) {
          this.emitText(", ");
        }
      }

      this.emitText(") ");
      this.emitBlock(node.functionBody());
      this.emitText(needsSemicolon ? ";\n" : "\n");
    }

    else if (node.kind == NODE_IF) {
      this.appendIndent();
      while (true) {
        this.emitText("if (");
        this.emitExpression(node.ifValue(), PRECEDENCE_LOWEST);
        this.emitText(") ");
        this.emitBlock(node.ifTrue());
        var no = node.ifFalse();
        if (no == null) {
          this.emitText("\n");
          break;
        }
        this.emitText(" else ");
        if (no.firstChild == null || no.firstChild != no.lastChild || no.firstChild.kind != NODE_IF) {
          this.emitBlock(no);
          this.emitText("\n");
          break;
        }
        node = no.firstChild;
      }
    }

    else if (node.kind == NODE_WHILE) {
      this.appendIndent();
      this.emitText("while (");
      this.emitExpression(node.whileValue(), PRECEDENCE_LOWEST);
      this.emitText(") ");
      this.emitBlock(node.whileBody());
      this.emitText("\n");
    }

    else if (node.kind == NODE_BREAK) {
      this.appendIndent();
      this.emitText("break;\n");
    }

    else if (node.kind == NODE_CONTINUE) {
      this.appendIndent();
      this.emitText("continue;\n");
    }

    else if (node.kind == NODE_EXPRESSION) {
      this.appendIndent();
      this.emitExpression(node.expressionValue(), PRECEDENCE_LOWEST);
      this.emitText(";\n");
    }

    else if (node.kind == NODE_EMPTY) {
    }

    else if (node.kind == NODE_RETURN) {
      var value = node.returnValue();
      this.appendIndent();
      if (value != null) {
        this.emitText("return ");
        this.emitExpression(value, PRECEDENCE_LOWEST);
        this.emitText(";\n");
      } else {
        this.emitText("return;\n");
      }
    }

    else if (node.kind == NODE_BLOCK) {
      this.appendIndent();
      this.emitBlock(node);
      this.emitText("\n");
    }

    else if (node.kind == NODE_VARIABLES) {
      this.appendIndent();
      this.emitText("var ");
      var child = node.firstChild;
      while (child != null) {
        var value = child.variableValue();
        this.emitString(child.symbol.name);
        child = child.nextSibling;
        if (child != null) {
          this.emitText(", ");
        }
        assert(value != null);
        this.emitText(" = ");
        this.emitExpression(value, PRECEDENCE_LOWEST);
      }
      this.emitText(";\n");
    }

    else if (node.kind == NODE_CLASS) {
      this.appendIndent();
      this.emitText("function ");
      this.emitString(node.symbol.name);
      this.emitText("() {\n");
      this.indent = this.indent + 1;

      // Emit constructor body
      var child = node.firstChild;
      while (child != null) {
        if (child.kind == NODE_VARIABLE) {
          this.appendIndent();
          this.emitText("this.");
          this.emitString(child.symbol.name);
          this.emitText(" = ");
          this.emitExpression(child.variableValue(), PRECEDENCE_LOWEST);
          this.emitText(";\n");
        }
        child = child.nextSibling;
      }

      this.indent = this.indent - 1;
      this.appendIndent();
      this.emitText("}\n");

      // Emit instance functions
      child = node.firstChild;
      while (child != null) {
        if (child.kind == NODE_FUNCTION) {
          this.emitStatement(child);
        }
        child = child.nextSibling;
      }
    }

    else if (node.kind == NODE_CONSTANTS) {
    }

    else {
      assert(false);
    }
  }
}

function jsEmit(global: Node, context: CheckContext): String {
  var result = new JsResult();
  result.context = context;
  result.code = String_new("");

  var child = global.firstChild;
  while (child != null) {
    result.emitStatement(child);
    child = child.nextSibling;
  }

  return result.code;
}
