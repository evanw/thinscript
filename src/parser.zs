const PRECEDENCE_LOWEST = 0;
const PRECEDENCE_ASSIGN = 1;
const PRECEDENCE_LOGICAL_OR = 2;
const PRECEDENCE_LOGICAL_AND = 3;
const PRECEDENCE_BITWISE_OR = 4;
const PRECEDENCE_BITWISE_XOR = 5;
const PRECEDENCE_BITWISE_AND = 6;
const PRECEDENCE_EQUAL = 7;
const PRECEDENCE_COMPARE = 8;
const PRECEDENCE_SHIFT = 9;
const PRECEDENCE_ADD = 10;
const PRECEDENCE_MULTIPLY = 11;
const PRECEDENCE_UNARY_PREFIX = 12;
const PRECEDENCE_UNARY_POSTFIX = 13;
const PRECEDENCE_MEMBER = 14;

function parseInt(range: Range): int {
  var i = range.start;
  var value = 0;

  while (i < range.end) {
    value = value * 10 + String_get(range.source.contents, i) - '0';
    i = i + 1;
  }

  return value;
}

class ParserContext {
  current: Token;
  log: Log;

  peek(kind: int): bool {
    return this.current.kind == kind;
  }

  eat(kind: int): bool {
    if (this.peek(kind)) {
      this.advance();
      return true;
    }

    return false;
  }

  advance(): void {
    if (!this.peek(TOKEN_END_OF_FILE)) {
      this.current = this.current.next;
    }
  }

  unexpectedToken(): void {
    this.log.error(this.current.range, String_append(
      String_new("Unexpected "),
      String_new(tokenToString(this.current.kind))));
  }

  expect(kind: int): bool {
    if (!this.peek(kind)) {
      this.log.error(this.current.range, String_append(String_append(String_append(
        String_new("Expected "),
        String_new(tokenToString(kind))),
        String_new(" but found ")),
        String_new(tokenToString(this.current.kind))));
      return false;
    }

    this.advance();
    return true;
  }

  parseUnaryPrefix(kind: int): Node {
    assert(isUnary(kind));

    var token = this.current;
    this.advance();

    var value = this.parseExpression(PRECEDENCE_UNARY_PREFIX);
    if (value == null) {
      return null;
    }

    return createUnary(kind, value).withRange(spanRanges(token.range, value.range));
  }

  parseBinary(kind: int, left: Node, localPrecedence: int, operatorPrecedence: int): Node {
    if (localPrecedence >= operatorPrecedence) {
      return left;
    }

    this.advance();
    var right = this.parseExpression(operatorPrecedence == PRECEDENCE_ASSIGN ? PRECEDENCE_LOWEST : operatorPrecedence); // PRECEDENCE_ASSIGN is right-associative

    if (right == null) {
      return null;
    }

    return createBinary(kind, left, right).withRange(spanRanges(left.range, right.range));
  }

  parseUnaryPostfix(kind: int, value: Node, localPrecedence: int): Node {
    if (localPrecedence >= PRECEDENCE_UNARY_POSTFIX) {
      return value;
    }

    var token = this.current;
    this.advance();
    return createUnary(kind, value).withRange(spanRanges(value.range, token.range));
  }

  parseQuotedString(range: Range): String {
    assert(range.end - range.start >= 2);
    var text = range.toString();
    var end = 1;
    var limit = String_length(text) - 1;
    var start = end;
    var result = String_new("");

    while (end < limit) {
      var c = String_get(text, end);

      if (c == '\\') {
        result = String_append(result, String_slice(text, start, end));
        end = end + 1;
        start = end + 1;
        c = String_get(text, end);

        if (c == '0') result = String_appendNew(result, "\0");
        else if (c == 't') result = String_appendNew(result, "\t");
        else if (c == 'n') result = String_appendNew(result, "\n");
        else if (c == 'r') result = String_appendNew(result, "\r");
        else if (c == '"' || c == '\'' || c == '`' || c == '\n' || c == '\\') start = end;
        else {
          var escape = createRange(range.source, range.start + end - 1, range.start + end + 1);
          this.log.error(escape, String_append(String_append(
            String_new("Invalid escape code '"),
            escape.toString()),
            String_new("'")));
          return null;
        }
      }

      end = end + 1;
    }

    return String_append(result, String_slice(text, start, end));
  }

  parsePrefix(): Node {
    var token = this.current;

    if (this.eat(TOKEN_NULL)) {
      return createNull().withRange(token.range);
    }

    if (this.eat(TOKEN_THIS)) {
      return createThis().withRange(token.range);
    }

    if (this.peek(TOKEN_CHARACTER)) {
      var text = this.parseQuotedString(token.range);
      if (text == null) {
        return null;
      }
      if (String_length(text) != 1) {
        this.log.error(token.range, String_new("Invalid character literal"));
        return null;
      }
      this.advance();
      return createInt(String_get(text, 0)).withRange(token.range);
    }

    if (this.peek(TOKEN_STRING)) {
      var text = this.parseQuotedString(token.range);
      if (text == null) {
        return null;
      }
      this.advance();
      return createString(text).withRange(token.range);
    }

    if (this.peek(TOKEN_INT)) {
      var value = parseInt(token.range);
      this.advance();
      return createInt(value).withRange(token.range);
    }

    if (this.eat(TOKEN_TRUE)) {
      return createBool(true).withRange(token.range);
    }

    if (this.eat(TOKEN_FALSE)) {
      return createBool(false).withRange(token.range);
    }

    if (this.peek(TOKEN_IDENTIFIER)) {
      var value = token.range.toString();
      this.advance();
      return createName(value).withRange(token.range);
    }

    if (this.eat(TOKEN_NEW)) {
      var type = this.parseType();
      if (type == null || !this.expect(TOKEN_LEFT_PARENTHESIS)) {
        return null;
      }
      var close = this.current;
      if (!this.expect(TOKEN_RIGHT_PARENTHESIS)) {
        return null;
      }
      return createNew(type).withRange(spanRanges(token.range, close.range));
    }

    if (this.eat(TOKEN_LEFT_PARENTHESIS)) {
      var value = this.parseExpression(PRECEDENCE_LOWEST);
      if (value == null || !this.expect(TOKEN_RIGHT_PARENTHESIS)) {
        return null;
      }
      return value;
    }

    // Unary prefix
    if (this.peek(TOKEN_NOT)) return this.parseUnaryPrefix(NODE_NOT);
    if (this.peek(TOKEN_MINUS)) return this.parseUnaryPrefix(NODE_NEGATIVE);
    if (this.peek(TOKEN_MINUS_MINUS)) return this.parseUnaryPrefix(NODE_PREFIX_DECREMENT);
    if (this.peek(TOKEN_PLUS)) return this.parseUnaryPrefix(NODE_POSITIVE);
    if (this.peek(TOKEN_PLUS_PLUS)) return this.parseUnaryPrefix(NODE_PREFIX_INCREMENT);
    if (this.peek(TOKEN_COMPLEMENT)) return this.parseUnaryPrefix(NODE_COMPLEMENT);

    this.unexpectedToken();
    return null;
  }

  parseInfix(precedence: int, node: Node): Node {
    var token = this.current;

    // Binary
    if (this.peek(TOKEN_ASSIGN)) return this.parseBinary(NODE_ASSIGN, node, precedence, PRECEDENCE_ASSIGN);
    if (this.peek(TOKEN_BITWISE_AND)) return this.parseBinary(NODE_BITWISE_AND, node, precedence, PRECEDENCE_BITWISE_AND);
    if (this.peek(TOKEN_BITWISE_OR)) return this.parseBinary(NODE_BITWISE_OR, node, precedence, PRECEDENCE_BITWISE_OR);
    if (this.peek(TOKEN_BITWISE_XOR)) return this.parseBinary(NODE_BITWISE_XOR, node, precedence, PRECEDENCE_BITWISE_XOR);
    if (this.peek(TOKEN_DIVIDE)) return this.parseBinary(NODE_DIVIDE, node, precedence, PRECEDENCE_MULTIPLY);
    if (this.peek(TOKEN_EQUAL)) return this.parseBinary(NODE_EQUAL, node, precedence, PRECEDENCE_EQUAL);
    if (this.peek(TOKEN_GREATER_THAN)) return this.parseBinary(NODE_GREATER_THAN, node, precedence, PRECEDENCE_COMPARE);
    if (this.peek(TOKEN_GREATER_THAN_EQUAL)) return this.parseBinary(NODE_GREATER_THAN_EQUAL, node, precedence, PRECEDENCE_COMPARE);
    if (this.peek(TOKEN_LESS_THAN)) return this.parseBinary(NODE_LESS_THAN, node, precedence, PRECEDENCE_COMPARE);
    if (this.peek(TOKEN_LESS_THAN_EQUAL)) return this.parseBinary(NODE_LESS_THAN_EQUAL, node, precedence, PRECEDENCE_COMPARE);
    if (this.peek(TOKEN_LOGICAL_AND)) return this.parseBinary(NODE_LOGICAL_AND, node, precedence, PRECEDENCE_LOGICAL_AND);
    if (this.peek(TOKEN_LOGICAL_OR)) return this.parseBinary(NODE_LOGICAL_OR, node, precedence, PRECEDENCE_LOGICAL_OR);
    if (this.peek(TOKEN_MINUS)) return this.parseBinary(NODE_SUBTRACT, node, precedence, PRECEDENCE_ADD);
    if (this.peek(TOKEN_MULTIPLY)) return this.parseBinary(NODE_MULTIPLY, node, precedence, PRECEDENCE_MULTIPLY);
    if (this.peek(TOKEN_NOT_EQUAL)) return this.parseBinary(NODE_NOT_EQUAL, node, precedence, PRECEDENCE_EQUAL);
    if (this.peek(TOKEN_PLUS)) return this.parseBinary(NODE_ADD, node, precedence, PRECEDENCE_ADD);
    if (this.peek(TOKEN_REMAINDER)) return this.parseBinary(NODE_REMAINDER, node, precedence, PRECEDENCE_MULTIPLY);
    if (this.peek(TOKEN_SHIFT_LEFT)) return this.parseBinary(NODE_SHIFT_LEFT, node, precedence, PRECEDENCE_SHIFT);
    if (this.peek(TOKEN_SHIFT_RIGHT)) return this.parseBinary(NODE_SHIFT_RIGHT, node, precedence, PRECEDENCE_SHIFT);

    // Unary postfix
    if (this.peek(TOKEN_PLUS_PLUS)) return this.parseUnaryPostfix(NODE_POSTFIX_INCREMENT, node, precedence);
    if (this.peek(TOKEN_MINUS_MINUS)) return this.parseUnaryPostfix(NODE_POSTFIX_DECREMENT, node, precedence);

    // Call
    if (this.peek(TOKEN_LEFT_PARENTHESIS) && precedence < PRECEDENCE_UNARY_POSTFIX) {
      this.advance();
      var call = createCall(node);

      if (!this.peek(TOKEN_RIGHT_PARENTHESIS)) {
        while (true) {
          var value = this.parseExpression(PRECEDENCE_LOWEST);
          if (value == null) {
            return null;
          }
          call.appendChild(value);

          if (!this.eat(TOKEN_COMMA)) {
            break;
          }
        }
      }

      var close = this.current;
      if (!this.expect(TOKEN_RIGHT_PARENTHESIS)) {
        return null;
      }

      return call.withRange(spanRanges(node.range, close.range)).withInternalRange(spanRanges(token.range, close.range));
    }

    // Hook
    if (this.peek(TOKEN_QUESTION_MARK) && precedence < PRECEDENCE_ASSIGN) {
      this.advance();

      var middle = this.parseExpression(PRECEDENCE_LOWEST);
      if (middle == null || !this.expect(TOKEN_COLON)) {
        return null;
      }

      var right = this.parseExpression(PRECEDENCE_LOWEST);
      if (right == null) {
        return null;
      }

      return createHook(node, middle, right).withRange(spanRanges(node.range, right.range));
    }

    // Dot
    if (this.peek(TOKEN_DOT) && precedence < PRECEDENCE_MEMBER) {
      this.advance();

      var name = this.current;
      if (!this.expect(TOKEN_IDENTIFIER)) {
        return null;
      }

      return createDot(node, name.range.toString()).withRange(spanRanges(node.range, name.range)).withInternalRange(name.range);
    }

    return node;
  }

  parseExpression(precedence: int): Node {
    // Prefix
    var node = this.parsePrefix();
    if (node == null) {
      return null;
    }
    assert(node.range != null);

    // Infix
    while (true) {
      var result = this.parseInfix(precedence, node);
      if (result == null) {
        return null;
      }
      if (result == node) {
        break;
      }
      node = result;
      assert(node.range != null);
    }

    return node;
  }

  parseType(): Node {
    return this.parseExpression(PRECEDENCE_UNARY_POSTFIX);
  }

  parseIf(): Node {
    var token = this.current;
    assert(token.kind == TOKEN_IF);
    this.advance();

    if (!this.expect(TOKEN_LEFT_PARENTHESIS)) {
      return null;
    }

    var value = this.parseExpression(PRECEDENCE_LOWEST);
    if (value == null || !this.expect(TOKEN_RIGHT_PARENTHESIS)) {
      return null;
    }

    var trueBranch = this.parseBody();
    if (trueBranch == null) {
      return null;
    }

    var falseBranch: Node = null;
    if (this.eat(TOKEN_ELSE)) {
      falseBranch = this.parseBody();
      if (falseBranch == null) {
        return null;
      }
    }

    return createIf(value, trueBranch, falseBranch).withRange(spanRanges(
      token.range, (falseBranch != null ? falseBranch : trueBranch).range));
  }

  parseWhile(): Node {
    var token = this.current;
    assert(token.kind == TOKEN_WHILE);
    this.advance();

    if (!this.expect(TOKEN_LEFT_PARENTHESIS)) {
      return null;
    }

    var value = this.parseExpression(PRECEDENCE_LOWEST);
    if (value == null || !this.expect(TOKEN_RIGHT_PARENTHESIS)) {
      return null;
    }

    var body = this.parseBody();
    if (body == null) {
      return null;
    }

    return createWhile(value, body).withRange(spanRanges(token.range, body.range));
  }

  parseBody(): Node {
    var node = this.parseStatement();
    if (node == null) {
      return null;
    }

    if (node.kind == NODE_BLOCK) {
      return node;
    }

    var block = createBlock();
    block.appendChild(node);
    return block.withRange(node.range);
  }

  parseBlock(): Node {
    var open = this.current;
    if (!this.expect(TOKEN_LEFT_BRACE)) {
      return null;
    }

    var block = createBlock();
    if (!this.parseStatements(block)) {
      return null;
    }

    var close = this.current;
    if (!this.expect(TOKEN_RIGHT_BRACE)) {
      return null;
    }

    return block.withRange(spanRanges(open.range, close.range));
  }

  parseReturn(): Node {
    var token = this.current;
    assert(token.kind == TOKEN_RETURN);
    this.advance();

    var value: Node = null;
    if (!this.peek(TOKEN_SEMICOLON)) {
      value = this.parseExpression(PRECEDENCE_LOWEST);
      if (value == null) {
        return null;
      }
    }

    var semicolon = this.current;
    if (!this.expect(TOKEN_SEMICOLON)) {
      return null;
    }

    return createReturn(value).withRange(spanRanges(token.range, semicolon.range));
  }

  parseClass(flags: int): Node {
    var token = this.current;
    assert(token.kind == TOKEN_CLASS);
    this.advance();

    var name = this.current;
    if (!this.expect(TOKEN_IDENTIFIER) || !this.expect(TOKEN_LEFT_BRACE)) {
      return null;
    }

    var node = createClass(name.range.toString());
    node.flags = flags;

    while (!this.peek(TOKEN_END_OF_FILE) && !this.peek(TOKEN_RIGHT_BRACE)) {
      var start = this.current;

      if (!this.expect(TOKEN_IDENTIFIER)) {
        return null;
      }

      if (this.peek(TOKEN_LEFT_PARENTHESIS)) {
        this.current = start;
        if (this.parseFunction(0, node) == null) {
          return null;
        }
      }

      else {
        this.current = start;
        if (this.parseVariables(0, node) == null) {
          return null;
        }
      }
    }

    var close = this.current;
    if (!this.expect(TOKEN_RIGHT_BRACE)) {
      return null;
    }

    return node.withRange(spanRanges(token.range, close.range)).withInternalRange(name.range);
  }

  parseFunction(flags: int, parent: Node): Node {
    var token = this.current;

    // Functions inside class declarations don't use "
    if (parent == null) {
      assert(token.kind == TOKEN_FUNCTION);
      this.advance();
    }

    var name = this.current;
    if (!this.expect(TOKEN_IDENTIFIER) || !this.expect(TOKEN_LEFT_PARENTHESIS)) {
      return null;
    }

    var node = createFunction(name.range.toString());
    node.flags = flags;

    if (!this.peek(TOKEN_RIGHT_PARENTHESIS)) {
      while (true) {
        var argument = this.current;
        if (!this.expect(TOKEN_IDENTIFIER) || !this.expect(TOKEN_COLON)) {
          return null;
        }

        var type = this.parseType();
        if (type == null) {
          return null;
        }

        var variable = createVariable(argument.range.toString(), type, null);
        node.appendChild(variable.withRange(spanRanges(argument.range, type.range)).withInternalRange(argument.range));

        if (!this.eat(TOKEN_COMMA)) {
          break;
        }
      }
    }

    if (!this.expect(TOKEN_RIGHT_PARENTHESIS) || !this.expect(TOKEN_COLON)) {
      return null;
    }

    var returnType = this.parseType();
    if (returnType == null) {
      return null;
    }
    node.appendChild(returnType);
    var block: Node = null;

    // Is this an import?
    var semicolon = this.current;
    if (this.eat(TOKEN_SEMICOLON)) {
      block = createEmpty().withRange(semicolon.range);
    }

    // Normal functions
    else {
      block = this.parseBlock();
      if (block == null) {
        return null;
      }
    }

    // Add this to the enclosing class
    if (parent != null) {
      parent.appendChild(node);
    }

    node.appendChild(block);
    return node.withRange(spanRanges(token.range, block.range)).withInternalRange(name.range);
  }

  parseVariables(flags: int, parent: Node): Node {
    var token = this.current;

    // Variables inside class declarations don't use "var"
    if (parent == null) {
      assert(token.kind == TOKEN_VAR || token.kind == TOKEN_CONST);
      this.advance();
    }

    var node = token.kind == TOKEN_CONST ? createConstants() : createVariables();

    while (true) {
      var name = this.current;
      if (!this.expect(TOKEN_IDENTIFIER)) {
        return null;
      }

      var type: Node = null;
      if (this.eat(TOKEN_COLON)) {
        type = this.parseType();
        if (type == null) {
          return null;
        }
      }

      var value: Node = null;
      if (this.eat(TOKEN_ASSIGN)) {
        value = this.parseExpression(PRECEDENCE_LOWEST);
        if (value == null) {
          return null;
        }

        // TODO: Implement constructors
        if (parent != null) {
          this.log.error(value.range, String_new("Inline initialization of instance variables is not supported yet"));
        }
      }

      var range =
        value != null ? spanRanges(name.range, value.range) :
        type != null ? spanRanges(name.range, type.range) :
        name.range;

      var variable = createVariable(name.range.toString(), type, value);
      variable.flags = flags;
      (parent != null ? parent : node).appendChild(variable.withRange(range).withInternalRange(name.range));

      if (!this.eat(TOKEN_COMMA)) {
        break;
      }
    }

    var semicolon = this.current;
    if (!this.expect(TOKEN_SEMICOLON)) {
      return null;
    }

    return node.withRange(spanRanges(token.range, semicolon.range));
  }

  parseLoopJump(kind: int): Node {
    var token = this.current;
    this.advance();

    if (!this.expect(TOKEN_SEMICOLON)) {
      return null;
    }

    var node = new Node();
    node.kind = kind;
    return node.withRange(token.range);
  }

  parseStatement(): Node {
    var flags = 0;

    if (this.eat(TOKEN_EXTERN)) {
      flags = flags | NODE_FLAG_EXTERN;
    }

    if (this.peek(TOKEN_CONST) || this.peek(TOKEN_VAR)) {
      return this.parseVariables(flags, null);
    }

    if (this.peek(TOKEN_FUNCTION)) {
      return this.parseFunction(flags, null);
    }

    if (this.peek(TOKEN_CLASS)) {
      return this.parseClass(flags);
    }

    // Definition modifiers need to be attached to a definition
    if (flags != 0) {
      this.unexpectedToken();
      return null;
    }

    if (this.peek(TOKEN_LEFT_BRACE)) {
      return this.parseBlock();
    }

    if (this.peek(TOKEN_BREAK)) {
      return this.parseLoopJump(NODE_BREAK);
    }

    if (this.peek(TOKEN_CONTINUE)) {
      return this.parseLoopJump(NODE_CONTINUE);
    }

    if (this.peek(TOKEN_IF)) {
      return this.parseIf();
    }

    if (this.peek(TOKEN_WHILE)) {
      return this.parseWhile();
    }

    if (this.peek(TOKEN_RETURN)) {
      return this.parseReturn();
    }

    if (this.peek(TOKEN_SEMICOLON)) {
      var token = this.current;
      this.advance();
      return createEmpty().withRange(token.range);
    }

    var value = this.parseExpression(PRECEDENCE_LOWEST);

    if (value == null) {
      return null;
    }

    var semicolon = this.current;
    if (!this.expect(TOKEN_SEMICOLON)) {
      return null;
    }

    return createExpression(value).withRange(spanRanges(value.range, semicolon.range));
  }

  parseStatements(parent: Node): bool {
    while (!this.peek(TOKEN_END_OF_FILE) && !this.peek(TOKEN_RIGHT_BRACE)) {
      var child = this.parseStatement();
      if (child == null) {
        return false;
      }
      parent.appendChild(child);
    }
    return true;
  }
}

function parse(firstToken: Token, log: Log): Node {
  var context = new ParserContext();
  context.current = firstToken;
  context.log = log;

  var global = new Node();
  global.kind = NODE_GLOBAL;
  if (!context.parseStatements(global)) {
    return null;
  }
  return global;
}
