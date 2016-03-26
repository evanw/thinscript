class JsResult {
  context: CheckContext;
  code: String;
  indent: int;
}

function jsAppendIndent(result: JsResult): void {
  var i = result.indent;
  while (i > 0) {
    result.code = String_appendNew(result.code, "  ");
    i = i - 1;
  }
}

function jsAppendText(result: JsResult, text: string): void {
  result.code = String_appendNew(result.code, text);
}

function jsAppendString(result: JsResult, text: String): void {
  result.code = String_append(result.code, text);
}

function jsEmitChildren(result: JsResult, node: Node): void {
  var child = node.firstChild;
  while (child != null) {
    jsEmitStatement(result, child);
    child = child.nextSibling;
  }
}

function jsEmitBlock(result: JsResult, node: Node): void {
  jsAppendText(result, "{\n");
  result.indent = result.indent + 1;
  jsEmitChildren(result, node);
  result.indent = result.indent - 1;
  jsAppendIndent(result);
  jsAppendText(result, "}");
}

function jsEmitUnary(result: JsResult, node: Node, parentPrecedence: int, operator: string): void {
  var isPostfix = isUnaryPostfix(node.kind);
  var operatorPrecedence = isPostfix ? PRECEDENCE_UNARY_POSTFIX : PRECEDENCE_UNARY_PREFIX;

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

function jsEmitBinary(result: JsResult, node: Node, parentPrecedence: int, operator: string, operatorPrecedence: int): void {
  var isRightAssociative = node.kind == NODE_ASSIGN;

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

function jsEmitExpression(result: JsResult, node: Node, parentPrecedence: int): void {
  if (node.kind == NODE_NAME) {
    jsAppendString(result, node.symbol.name);
  }

  else if (node.kind == NODE_NULL) {
    jsAppendText(result, "null");
  }

  else if (node.kind == NODE_BOOL) {
    jsAppendText(result, node.intValue != 0 ? "true" : "false");
  }

  else if (node.kind == NODE_INT) {
    jsAppendString(result, String_toString(node.intValue));
  }

  else if (node.kind == NODE_STRING) {
    jsAppendString(result, String_quote(node.stringValue));
  }

  else if (node.kind == NODE_DOT) {
    jsEmitExpression(result, dotTarget(node), PRECEDENCE_MEMBER);
    jsAppendText(result, ".");
    jsAppendString(result, node.symbol.name);
  }

  else if (node.kind == NODE_HOOK) {
    if (parentPrecedence > PRECEDENCE_ASSIGN) {
      jsAppendText(result, "(");
    }

    jsEmitExpression(result, hookValue(node), PRECEDENCE_LOGICAL_OR);
    jsAppendText(result, " ? ");
    jsEmitExpression(result, hookTrue(node), PRECEDENCE_ASSIGN);
    jsAppendText(result, " : ");
    jsEmitExpression(result, hookFalse(node), PRECEDENCE_ASSIGN);

    if (parentPrecedence > PRECEDENCE_ASSIGN) {
      jsAppendText(result, ")");
    }
  }

  else if (node.kind == NODE_CALL) {
    var value = callValue(node);
    if (functionBody(value.symbol.node) == null) {
      jsAppendText(result, "__imports.");
    }
    jsEmitExpression(result, value, PRECEDENCE_UNARY_POSTFIX);
    jsAppendText(result, "(");

    var child = value.nextSibling;
    while (child != null) {
      jsEmitExpression(result, child, PRECEDENCE_LOWEST);
      child = child.nextSibling;
      if (child != null) {
        jsAppendText(result, ", ");
      }
    }

    jsAppendText(result, ")");
  }

  else if (node.kind == NODE_NEW) {
    jsAppendText(result, "new ");
    jsEmitExpression(result, newType(node), PRECEDENCE_UNARY_POSTFIX);
    jsAppendText(result, "()");
  }

  else if (node.kind == NODE_COMPLEMENT) jsEmitUnary(result, node, parentPrecedence, "~");
  else if (node.kind == NODE_NEGATIVE) jsEmitUnary(result, node, parentPrecedence, "-");
  else if (node.kind == NODE_NOT) jsEmitUnary(result, node, parentPrecedence, "!");
  else if (node.kind == NODE_POSITIVE) jsEmitUnary(result, node, parentPrecedence, "+");
  else if (node.kind == NODE_PREFIX_INCREMENT) jsEmitUnary(result, node, parentPrecedence, "++");
  else if (node.kind == NODE_PREFIX_DECREMENT) jsEmitUnary(result, node, parentPrecedence, "--");
  else if (node.kind == NODE_POSTFIX_INCREMENT) jsEmitUnary(result, node, parentPrecedence, "++");
  else if (node.kind == NODE_POSTFIX_DECREMENT) jsEmitUnary(result, node, parentPrecedence, "--");

  else if (node.kind == NODE_ADD) jsEmitBinary(result, node, parentPrecedence, " + ", PRECEDENCE_ADD);
  else if (node.kind == NODE_ASSIGN) jsEmitBinary(result, node, parentPrecedence, " = ", PRECEDENCE_ASSIGN);
  else if (node.kind == NODE_BITWISE_AND) jsEmitBinary(result, node, parentPrecedence, " & ", PRECEDENCE_BITWISE_AND);
  else if (node.kind == NODE_BITWISE_OR) jsEmitBinary(result, node, parentPrecedence, " | ", PRECEDENCE_BITWISE_OR);
  else if (node.kind == NODE_BITWISE_XOR) jsEmitBinary(result, node, parentPrecedence, " ^ ", PRECEDENCE_BITWISE_XOR);
  else if (node.kind == NODE_DIVIDE) jsEmitBinary(result, node, parentPrecedence, " / ", PRECEDENCE_MULTIPLY); // TODO: This isn't accurate for integer division
  else if (node.kind == NODE_EQUAL) jsEmitBinary(result, node, parentPrecedence, " === ", PRECEDENCE_EQUAL);
  else if (node.kind == NODE_GREATER_THAN) jsEmitBinary(result, node, parentPrecedence, " > ", PRECEDENCE_COMPARE);
  else if (node.kind == NODE_GREATER_THAN_EQUAL) jsEmitBinary(result, node, parentPrecedence, " >= ", PRECEDENCE_COMPARE);
  else if (node.kind == NODE_LESS_THAN) jsEmitBinary(result, node, parentPrecedence, " < ", PRECEDENCE_COMPARE);
  else if (node.kind == NODE_LESS_THAN_EQUAL) jsEmitBinary(result, node, parentPrecedence, " <= ", PRECEDENCE_COMPARE);
  else if (node.kind == NODE_LOGICAL_AND) jsEmitBinary(result, node, parentPrecedence, " && ", PRECEDENCE_LOGICAL_AND);
  else if (node.kind == NODE_LOGICAL_OR) jsEmitBinary(result, node, parentPrecedence, " || ", PRECEDENCE_LOGICAL_OR);
  else if (node.kind == NODE_MULTIPLY) jsEmitBinary(result, node, parentPrecedence, " * ", PRECEDENCE_MULTIPLY);
  else if (node.kind == NODE_NOT_EQUAL) jsEmitBinary(result, node, parentPrecedence, " !== ", PRECEDENCE_EQUAL);
  else if (node.kind == NODE_REMAINDER) jsEmitBinary(result, node, parentPrecedence, " % ", PRECEDENCE_MULTIPLY);
  else if (node.kind == NODE_SHIFT_LEFT) jsEmitBinary(result, node, parentPrecedence, " << ", PRECEDENCE_SHIFT);
  else if (node.kind == NODE_SHIFT_RIGHT) jsEmitBinary(result, node, parentPrecedence, " >> ", PRECEDENCE_SHIFT);
  else if (node.kind == NODE_SUBTRACT) jsEmitBinary(result, node, parentPrecedence, " - ", PRECEDENCE_ADD);

  else {
    assert(false);
  }
}

function jsEmitStatement(result: JsResult, node: Node): void {
  if (node.kind == NODE_FUNCTION) {
    var body = functionBody(node);
    if (body == null) {
      return;
    }

    var needsSemicolon = false;
    jsAppendIndent(result);
    if (node.parent.kind == NODE_CLASS) {
      jsAppendString(result, node.parent.symbol.name);
      jsAppendText(result, ".prototype.");
      jsAppendString(result, node.symbol.name);
      jsAppendText(result, " = function");
      needsSemicolon = true;
    } else if (isExternSymbol(node.symbol)) {
      jsAppendText(result, "var ");
      jsAppendString(result, node.symbol.name);
      jsAppendText(result, " = exports.");
      jsAppendString(result, node.symbol.name);
      jsAppendText(result, " = function");
      needsSemicolon = true;
    } else {
      jsAppendText(result, "function ");
      jsAppendString(result, node.symbol.name);
    }
    jsAppendText(result, "(");

    var returnType = functionReturnType(node);
    var child = functionFirstArgumentIgnoringThis(node);
    while (child != returnType) {
      assert(child.kind == NODE_VARIABLE);
      jsAppendString(result, child.symbol.name);
      child = child.nextSibling;
      if (child != returnType) {
        jsAppendText(result, ", ");
      }
    }

    jsAppendText(result, ") ");
    jsEmitBlock(result, functionBody(node));
    jsAppendText(result, needsSemicolon ? ";\n" : "\n");
  }

  else if (node.kind == NODE_IF) {
    jsAppendIndent(result);
    while (true) {
      jsAppendText(result, "if (");
      jsEmitExpression(result, ifValue(node), PRECEDENCE_LOWEST);
      jsAppendText(result, ") ");
      jsEmitBlock(result, ifTrue(node));
      var no = ifFalse(node);
      if (no == null) {
        jsAppendText(result, "\n");
        break;
      }
      jsAppendText(result, " else ");
      if (no.firstChild == null || no.firstChild != no.lastChild || no.firstChild.kind != NODE_IF) {
        jsEmitBlock(result, no);
        jsAppendText(result, "\n");
        break;
      }
      node = no.firstChild;
    }
  }

  else if (node.kind == NODE_WHILE) {
    jsAppendIndent(result);
    jsAppendText(result, "while (");
    jsEmitExpression(result, whileValue(node), PRECEDENCE_LOWEST);
    jsAppendText(result, ") ");
    jsEmitBlock(result, whileBody(node));
    jsAppendText(result, "\n");
  }

  else if (node.kind == NODE_BREAK) {
    jsAppendIndent(result);
    jsAppendText(result, "break;\n");
  }

  else if (node.kind == NODE_CONTINUE) {
    jsAppendIndent(result);
    jsAppendText(result, "continue;\n");
  }

  else if (node.kind == NODE_EXPRESSION) {
    jsAppendIndent(result);
    jsEmitExpression(result, expressionValue(node), PRECEDENCE_LOWEST);
    jsAppendText(result, ";\n");
  }

  else if (node.kind == NODE_EMPTY) {
  }

  else if (node.kind == NODE_RETURN) {
    var value = returnValue(node);
    jsAppendIndent(result);
    if (value != null) {
      jsAppendText(result, "return ");
      jsEmitExpression(result, value, PRECEDENCE_LOWEST);
      jsAppendText(result, ";\n");
    } else {
      jsAppendText(result, "return;\n");
    }
  }

  else if (node.kind == NODE_BLOCK) {
    jsAppendIndent(result);
    jsEmitBlock(result, node);
    jsAppendText(result, "\n");
  }

  else if (node.kind == NODE_VARIABLES) {
    jsAppendIndent(result);
    jsAppendText(result, "var ");
    var child = node.firstChild;
    while (child != null) {
      var value = variableValue(child);
      jsAppendString(result, child.symbol.name);
      child = child.nextSibling;
      if (child != null) {
        jsAppendText(result, ", ");
      }
      assert(value != null);
      jsAppendText(result, " = ");
      jsEmitExpression(result, value, PRECEDENCE_LOWEST);
    }
    jsAppendText(result, ";\n");
  }

  else if (node.kind == NODE_CLASS) {
    jsAppendIndent(result);
    jsAppendText(result, "function ");
    jsAppendString(result, node.symbol.name);
    jsAppendText(result, "() {\n");
    result.indent = result.indent + 1;

    // Emit constructor body
    var child = node.firstChild;
    while (child != null) {
      if (child.kind == NODE_VARIABLE) {
        jsAppendIndent(result);
        jsAppendText(result, "this.");
        jsAppendString(result, child.symbol.name);
        jsAppendText(result, " = ");
        jsEmitExpression(result, variableValue(child), PRECEDENCE_LOWEST);
        jsAppendText(result, ";\n");
      }
      child = child.nextSibling;
    }

    result.indent = result.indent - 1;
    jsAppendIndent(result);
    jsAppendText(result, "}\n");

    // Emit instance functions
    child = node.firstChild;
    while (child != null) {
      if (child.kind == NODE_FUNCTION) {
        jsEmitStatement(result, child);
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

function jsEmit(global: Node, context: CheckContext): String {
  var result = new JsResult();
  result.context = context;
  result.code = String_new("");

  var child = global.firstChild;
  while (child != null) {
    jsEmitStatement(result, child);
    child = child.nextSibling;
  }

  return result.code;
}
