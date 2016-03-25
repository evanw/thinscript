class ParserContext {
  current: Token;
  log: Log;
}

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

function peek(context: ParserContext, kind: int): bool {
  return context.current.kind == kind;
}

function eat(context: ParserContext, kind: int): bool {
  if (peek(context, kind)) {
    advance(context);
    return true;
  }

  return false;
}

function advance(context: ParserContext): void {
  if (!peek(context, TOKEN_END_OF_FILE)) {
    context.current = context.current.next;
  }
}

function unexpectedToken(context: ParserContext): void {
  error(context.log, context.current.range, String_append(
    String_new("Unexpected "),
    String_new(tokenToString(context.current.kind))));
}

function expect(context: ParserContext, kind: int): bool {
  if (!peek(context, kind)) {
    error(context.log, context.current.range, String_append(String_append(String_append(
      String_new("Expected "),
      String_new(tokenToString(kind))),
      String_new(" but found ")),
      String_new(tokenToString(context.current.kind))));
    return false;
  }

  advance(context);
  return true;
}

function parseInt(range: Range): int {
  var i = range.start;
  var value = 0;

  while (i < range.end) {
    value = value * 10 + String_get(range.source.contents, i) - '0';
    i = i + 1;
  }

  return value;
}

function parseUnaryPrefix(context: ParserContext, kind: int): Node {
  assert(isUnary(kind));

  var token = context.current;
  advance(context);

  var value = parseExpression(context, PRECEDENCE_UNARY_PREFIX);
  if (value == null) {
    return null;
  }

  return withRange(createUnary(kind, value), spanRanges(token.range, value.range));
}

function parseBinary(context: ParserContext, kind: int, left: Node, localPrecedence: int, operatorPrecedence: int): Node {
  if (localPrecedence >= operatorPrecedence) {
    return left;
  }

  advance(context);
  var right = parseExpression(context, operatorPrecedence == PRECEDENCE_ASSIGN ? PRECEDENCE_LOWEST : operatorPrecedence); // PRECEDENCE_ASSIGN is right-associative

  if (right == null) {
    return null;
  }

  return withRange(createBinary(kind, left, right), spanRanges(left.range, right.range));
}

function parseUnaryPostfix(context: ParserContext, kind: int, value: Node, localPrecedence: int): Node {
  if (localPrecedence >= PRECEDENCE_UNARY_POSTFIX) {
    return value;
  }

  var token = context.current;
  advance(context);
  return withRange(createUnary(kind, value), spanRanges(value.range, token.range));
}

function parseQuotedString(context: ParserContext, range: Range): String {
  assert(range.end - range.start >= 2);
  var text = rangeToString(range);
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
        error(context.log, escape, String_append(String_append(
          String_new("Invalid escape code '"),
          rangeToString(escape)),
          String_new("'")));
        return null;
      }
    }

    end = end + 1;
  }

  return String_append(result, String_slice(text, start, end));
}

function parsePrefix(context: ParserContext): Node {
  var token = context.current;

  if (eat(context, TOKEN_NULL)) {
    return withRange(createNull(), token.range);
  }

  if (peek(context, TOKEN_CHARACTER)) {
    var text = parseQuotedString(context, token.range);
    if (text == null) {
      return null;
    }
    if (String_length(text) != 1) {
      error(context.log, token.range, String_new("Invalid character literal"));
      return null;
    }
    advance(context);
    return withRange(createInt(String_get(text, 0)), token.range);
  }

  if (peek(context, TOKEN_STRING)) {
    var text = parseQuotedString(context, token.range);
    if (text == null) {
      return null;
    }
    advance(context);
    return withRange(createString(text), token.range);
  }

  if (peek(context, TOKEN_INT)) {
    var value = parseInt(token.range);
    advance(context);
    return withRange(createInt(value), token.range);
  }

  if (eat(context, TOKEN_TRUE)) {
    return withRange(createBool(true), token.range);
  }

  if (eat(context, TOKEN_FALSE)) {
    return withRange(createBool(false), token.range);
  }

  if (peek(context, TOKEN_IDENTIFIER)) {
    var value = rangeToString(token.range);
    advance(context);
    return withRange(createName(value), token.range);
  }

  if (eat(context, TOKEN_NEW)) {
    var type = parseType(context);
    if (type == null || !expect(context, TOKEN_LEFT_PARENTHESIS)) {
      return null;
    }
    var close = context.current;
    if (!expect(context, TOKEN_RIGHT_PARENTHESIS)) {
      return null;
    }
    return withRange(createNew(type), spanRanges(token.range, close.range));
  }

  if (eat(context, TOKEN_LEFT_PARENTHESIS)) {
    var value = parseExpression(context, PRECEDENCE_LOWEST);
    if (value == null || !expect(context, TOKEN_RIGHT_PARENTHESIS)) {
      return null;
    }
    return value;
  }

  // Unary prefix
  if (peek(context, TOKEN_NOT)) return parseUnaryPrefix(context, NODE_NOT);
  if (peek(context, TOKEN_MINUS)) return parseUnaryPrefix(context, NODE_NEGATIVE);
  if (peek(context, TOKEN_MINUS_MINUS)) return parseUnaryPrefix(context, NODE_PREFIX_DECREMENT);
  if (peek(context, TOKEN_PLUS)) return parseUnaryPrefix(context, NODE_POSITIVE);
  if (peek(context, TOKEN_PLUS_PLUS)) return parseUnaryPrefix(context, NODE_PREFIX_INCREMENT);
  if (peek(context, TOKEN_COMPLEMENT)) return parseUnaryPrefix(context, NODE_COMPLEMENT);

  unexpectedToken(context);
  return null;
}

function parseInfix(context: ParserContext, precedence: int, node: Node): Node {
  var token = context.current;

  // Binary
  if (peek(context, TOKEN_ASSIGN)) return parseBinary(context, NODE_ASSIGN, node, precedence, PRECEDENCE_ASSIGN);
  if (peek(context, TOKEN_BITWISE_AND)) return parseBinary(context, NODE_BITWISE_AND, node, precedence, PRECEDENCE_BITWISE_AND);
  if (peek(context, TOKEN_BITWISE_OR)) return parseBinary(context, NODE_BITWISE_OR, node, precedence, PRECEDENCE_BITWISE_OR);
  if (peek(context, TOKEN_BITWISE_XOR)) return parseBinary(context, NODE_BITWISE_XOR, node, precedence, PRECEDENCE_BITWISE_XOR);
  if (peek(context, TOKEN_DIVIDE)) return parseBinary(context, NODE_DIVIDE, node, precedence, PRECEDENCE_MULTIPLY);
  if (peek(context, TOKEN_EQUAL)) return parseBinary(context, NODE_EQUAL, node, precedence, PRECEDENCE_EQUAL);
  if (peek(context, TOKEN_GREATER_THAN)) return parseBinary(context, NODE_GREATER_THAN, node, precedence, PRECEDENCE_COMPARE);
  if (peek(context, TOKEN_GREATER_THAN_EQUAL)) return parseBinary(context, NODE_GREATER_THAN_EQUAL, node, precedence, PRECEDENCE_COMPARE);
  if (peek(context, TOKEN_LESS_THAN)) return parseBinary(context, NODE_LESS_THAN, node, precedence, PRECEDENCE_COMPARE);
  if (peek(context, TOKEN_LESS_THAN_EQUAL)) return parseBinary(context, NODE_LESS_THAN_EQUAL, node, precedence, PRECEDENCE_COMPARE);
  if (peek(context, TOKEN_LOGICAL_AND)) return parseBinary(context, NODE_LOGICAL_AND, node, precedence, PRECEDENCE_LOGICAL_AND);
  if (peek(context, TOKEN_LOGICAL_OR)) return parseBinary(context, NODE_LOGICAL_OR, node, precedence, PRECEDENCE_LOGICAL_OR);
  if (peek(context, TOKEN_MINUS)) return parseBinary(context, NODE_SUBTRACT, node, precedence, PRECEDENCE_ADD);
  if (peek(context, TOKEN_MULTIPLY)) return parseBinary(context, NODE_MULTIPLY, node, precedence, PRECEDENCE_MULTIPLY);
  if (peek(context, TOKEN_NOT_EQUAL)) return parseBinary(context, NODE_NOT_EQUAL, node, precedence, PRECEDENCE_EQUAL);
  if (peek(context, TOKEN_PLUS)) return parseBinary(context, NODE_ADD, node, precedence, PRECEDENCE_ADD);
  if (peek(context, TOKEN_REMAINDER)) return parseBinary(context, NODE_REMAINDER, node, precedence, PRECEDENCE_MULTIPLY);
  if (peek(context, TOKEN_SHIFT_LEFT)) return parseBinary(context, NODE_SHIFT_LEFT, node, precedence, PRECEDENCE_SHIFT);
  if (peek(context, TOKEN_SHIFT_RIGHT)) return parseBinary(context, NODE_SHIFT_RIGHT, node, precedence, PRECEDENCE_SHIFT);

  // Unary postfix
  if (peek(context, TOKEN_PLUS_PLUS)) return parseUnaryPostfix(context, NODE_POSTFIX_INCREMENT, node, precedence);
  if (peek(context, TOKEN_MINUS_MINUS)) return parseUnaryPostfix(context, NODE_POSTFIX_DECREMENT, node, precedence);

  // Call
  if (peek(context, TOKEN_LEFT_PARENTHESIS) && precedence < PRECEDENCE_UNARY_POSTFIX) {
    advance(context);
    var call = createCall(node);

    if (!peek(context, TOKEN_RIGHT_PARENTHESIS)) {
      while (true) {
        var value = parseExpression(context, PRECEDENCE_LOWEST);
        if (value == null) {
          return null;
        }
        appendChild(call, value);

        if (!eat(context, TOKEN_COMMA)) {
          break;
        }
      }
    }

    var close = context.current;
    if (!expect(context, TOKEN_RIGHT_PARENTHESIS)) {
      return null;
    }

    return withInternalRange(withRange(call, spanRanges(node.range, close.range)), spanRanges(token.range, close.range));
  }

  // Hook
  if (peek(context, TOKEN_QUESTION_MARK) && precedence < PRECEDENCE_ASSIGN) {
    advance(context);

    var middle = parseExpression(context, PRECEDENCE_LOWEST);
    if (middle == null || !expect(context, TOKEN_COLON)) {
      return null;
    }

    var right = parseExpression(context, PRECEDENCE_LOWEST);
    if (right == null) {
      return null;
    }

    return withRange(createHook(node, middle, right), spanRanges(node.range, right.range));
  }

  // Dot
  if (peek(context, TOKEN_DOT) && precedence < PRECEDENCE_MEMBER) {
    advance(context);

    var name = context.current;
    if (!expect(context, TOKEN_IDENTIFIER)) {
      return null;
    }

    return withInternalRange(withRange(createDot(node, rangeToString(name.range)), spanRanges(node.range, name.range)), name.range);
  }

  return node;
}

function parseExpression(context: ParserContext, precedence: int): Node {
  // Prefix
  var node = parsePrefix(context);
  if (node == null) {
    return null;
  }
  assert(node.range != null);

  // Infix
  while (true) {
    var result = parseInfix(context, precedence, node);
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

function parseType(context: ParserContext): Node {
  return parseExpression(context, PRECEDENCE_UNARY_POSTFIX);
}

function parseIf(context: ParserContext): Node {
  var token = context.current;
  assert(token.kind == TOKEN_IF);
  advance(context);

  if (!expect(context, TOKEN_LEFT_PARENTHESIS)) {
    return null;
  }

  var value = parseExpression(context, PRECEDENCE_LOWEST);
  if (value == null || !expect(context, TOKEN_RIGHT_PARENTHESIS)) {
    return null;
  }

  var trueBranch = parseBody(context);
  if (trueBranch == null) {
    return null;
  }

  var falseBranch: Node = null;
  if (eat(context, TOKEN_ELSE)) {
    falseBranch = parseBody(context);
    if (falseBranch == null) {
      return null;
    }
  }

  return withRange(createIf(value, trueBranch, falseBranch),
    spanRanges(token.range, (falseBranch != null ? falseBranch : trueBranch).range));
}

function parseWhile(context: ParserContext): Node {
  var token = context.current;
  assert(token.kind == TOKEN_WHILE);
  advance(context);

  if (!expect(context, TOKEN_LEFT_PARENTHESIS)) {
    return null;
  }

  var value = parseExpression(context, PRECEDENCE_LOWEST);
  if (value == null || !expect(context, TOKEN_RIGHT_PARENTHESIS)) {
    return null;
  }

  var body = parseBody(context);
  if (body == null) {
    return null;
  }

  return withRange(createWhile(value, body), spanRanges(token.range, body.range));
}

function parseBody(context: ParserContext): Node {
  var node = parseStatement(context);
  if (node == null) {
    return null;
  }

  if (node.kind == NODE_BLOCK) {
    return node;
  }

  var block = createBlock();
  appendChild(block, node);
  return withRange(block, node.range);
}

function parseBlock(context: ParserContext): Node {
  var open = context.current;
  if (!expect(context, TOKEN_LEFT_BRACE)) {
    return null;
  }

  var block = createBlock();
  if (!parseStatements(context, block)) {
    return null;
  }

  var close = context.current;
  if (!expect(context, TOKEN_RIGHT_BRACE)) {
    return null;
  }

  return withRange(block, spanRanges(open.range, close.range));
}

function parseReturn(context: ParserContext): Node {
  var token = context.current;
  assert(token.kind == TOKEN_RETURN);
  advance(context);

  var value: Node = null;
  if (!peek(context, TOKEN_SEMICOLON)) {
    value = parseExpression(context, PRECEDENCE_LOWEST);
    if (value == null) {
      return null;
    }
  }

  var semicolon = context.current;
  if (!expect(context, TOKEN_SEMICOLON)) {
    return null;
  }

  return withRange(createReturn(value), spanRanges(token.range, semicolon.range));
}

function parseClass(context: ParserContext, flags: int): Node {
  var token = context.current;
  assert(token.kind == TOKEN_CLASS);
  advance(context);

  var name = context.current;
  if (!expect(context, TOKEN_IDENTIFIER) || !expect(context, TOKEN_LEFT_BRACE)) {
    return null;
  }

  var node = createClass(rangeToString(name.range));
  node.flags = flags;

  while (!peek(context, TOKEN_END_OF_FILE) && !peek(context, TOKEN_RIGHT_BRACE)) {
    if (parseVariables(context, 0, node) == null) {
      return null;
    }
  }

  var close = context.current;
  if (!expect(context, TOKEN_RIGHT_BRACE)) {
    return null;
  }

  return withInternalRange(withRange(node, spanRanges(token.range, close.range)), name.range);
}

function parseFunction(context: ParserContext, flags: int): Node {
  var token = context.current;
  assert(token.kind == TOKEN_FUNCTION);
  advance(context);

  var name = context.current;
  if (!expect(context, TOKEN_IDENTIFIER) || !expect(context, TOKEN_LEFT_PARENTHESIS)) {
    return null;
  }

  var node = createFunction(rangeToString(name.range));
  node.flags = flags;

  if (!peek(context, TOKEN_RIGHT_PARENTHESIS)) {
    while (true) {
      var argument = context.current;
      if (!expect(context, TOKEN_IDENTIFIER) || !expect(context, TOKEN_COLON)) {
        return null;
      }

      var type = parseType(context);
      if (type == null) {
        return null;
      }

      var variable = createVariable(rangeToString(argument.range), type, null);
      appendChild(node, withInternalRange(withRange(variable, spanRanges(argument.range, type.range)), argument.range));

      if (!eat(context, TOKEN_COMMA)) {
        break;
      }
    }
  }

  if (!expect(context, TOKEN_RIGHT_PARENTHESIS) || !expect(context, TOKEN_COLON)) {
    return null;
  }

  var returnType = parseType(context);
  if (returnType == null) {
    return null;
  }
  appendChild(node, returnType);
  var block: Node = null;

  // Is this an import?
  var semicolon = context.current;
  if (eat(context, TOKEN_SEMICOLON)) {
    block = withRange(createEmpty(), semicolon.range);
  }

  // Normal functions
  else {
    block = parseBlock(context);
    if (block == null) {
      return null;
    }
  }

  appendChild(node, block);
  return withInternalRange(withRange(node, spanRanges(token.range, block.range)), name.range);
}

function parseVariables(context: ParserContext, flags: int, parent: Node): Node {
  var token = context.current;

  // Variables inside class declarations don't use "var"
  if (parent == null) {
    assert(token.kind == TOKEN_VAR || token.kind == TOKEN_CONST);
    advance(context);
  }

  var node = token.kind == TOKEN_CONST ? createConstants() : createVariables();

  while (true) {
    var name = context.current;
    if (!expect(context, TOKEN_IDENTIFIER)) {
      return null;
    }

    var type: Node = null;
    if (eat(context, TOKEN_COLON)) {
      type = parseType(context);
      if (type == null) {
        return null;
      }
    }

    var value: Node = null;
    if (eat(context, TOKEN_ASSIGN)) {
      value = parseExpression(context, PRECEDENCE_LOWEST);
      if (value == null) {
        return null;
      }

      // TODO: Implement constructors
      if (parent != null) {
        error(context.log, value.range, String_new("Inline initialization of instance variables is not supported yet"));
      }
    }

    var range =
      value != null ? spanRanges(name.range, value.range) :
      type != null ? spanRanges(name.range, type.range) :
      name.range;

    var variable = createVariable(rangeToString(name.range), type, value);
    variable.flags = flags;
    appendChild(parent != null ? parent : node, withInternalRange(withRange(variable, range), name.range));

    if (!eat(context, TOKEN_COMMA)) {
      break;
    }
  }

  var semicolon = context.current;
  if (!expect(context, TOKEN_SEMICOLON)) {
    return null;
  }

  return parent != null ? parent : withRange(node, spanRanges(token.range, semicolon.range));
}

function parseLoopJump(context: ParserContext, kind: int): Node {
  var token = context.current;
  advance(context);

  if (!expect(context, TOKEN_SEMICOLON)) {
    return null;
  }

  var node = new Node();
  node.kind = kind;
  return withRange(node, token.range);
}

function parseStatement(context: ParserContext): Node {
  var flags = 0;

  if (eat(context, TOKEN_EXTERN)) {
    flags = flags | NODE_FLAG_EXTERN;
  }

  if (peek(context, TOKEN_CONST) || peek(context, TOKEN_VAR)) {
    return parseVariables(context, flags, null);
  }

  if (peek(context, TOKEN_FUNCTION)) {
    return parseFunction(context, flags);
  }

  if (peek(context, TOKEN_CLASS)) {
    return parseClass(context, flags);
  }

  // Definition modifiers need to be attached to a definition
  if (flags != 0) {
    unexpectedToken(context);
    return null;
  }

  if (peek(context, TOKEN_LEFT_BRACE)) {
    return parseBlock(context);
  }

  if (peek(context, TOKEN_BREAK)) {
    return parseLoopJump(context, NODE_BREAK);
  }

  if (peek(context, TOKEN_CONTINUE)) {
    return parseLoopJump(context, NODE_CONTINUE);
  }

  if (peek(context, TOKEN_IF)) {
    return parseIf(context);
  }

  if (peek(context, TOKEN_WHILE)) {
    return parseWhile(context);
  }

  if (peek(context, TOKEN_RETURN)) {
    return parseReturn(context);
  }

  if (peek(context, TOKEN_SEMICOLON)) {
    var token = context.current;
    advance(context);
    return withRange(createEmpty(), token.range);
  }

  var value = parseExpression(context, PRECEDENCE_LOWEST);

  if (value == null) {
    return null;
  }

  var semicolon = context.current;
  if (!expect(context, TOKEN_SEMICOLON)) {
    return null;
  }

  return withRange(createExpression(value), spanRanges(value.range, semicolon.range));
}

function parseStatements(context: ParserContext, parent: Node): bool {
  while (!peek(context, TOKEN_END_OF_FILE) && !peek(context, TOKEN_RIGHT_BRACE)) {
    var child = parseStatement(context);
    if (child == null) {
      return false;
    }
    appendChild(parent, child);
  }
  return true;
}

function parse(firstToken: Token, log: Log): Node {
  var context = new ParserContext();
  context.current = firstToken;
  context.log = log;

  var global = new Node();
  global.kind = NODE_GLOBAL;
  if (!parseStatements(context, global)) {
    return null;
  }
  return global;
}
