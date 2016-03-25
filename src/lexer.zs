const TOKEN_END_OF_FILE = 0;

// Literals
const TOKEN_CHARACTER = 1;
const TOKEN_IDENTIFIER = 2;
const TOKEN_INT = 3;
const TOKEN_STRING = 4;

// Punctuation
const TOKEN_ASSIGN = 5;
const TOKEN_BITWISE_AND = 6;
const TOKEN_BITWISE_OR = 7;
const TOKEN_BITWISE_XOR = 8;
const TOKEN_COLON = 9;
const TOKEN_COMMA = 10;
const TOKEN_COMPLEMENT = 11;
const TOKEN_DIVIDE = 12;
const TOKEN_DOT = 13;
const TOKEN_EQUAL = 14;
const TOKEN_GREATER_THAN = 15;
const TOKEN_GREATER_THAN_EQUAL = 16;
const TOKEN_LEFT_BRACE = 17;
const TOKEN_LEFT_PARENTHESIS = 18;
const TOKEN_LESS_THAN = 19;
const TOKEN_LESS_THAN_EQUAL = 20;
const TOKEN_LOGICAL_AND = 21;
const TOKEN_LOGICAL_OR = 22;
const TOKEN_MINUS = 23;
const TOKEN_MINUS_MINUS = 24;
const TOKEN_MULTIPLY = 25;
const TOKEN_NOT = 26;
const TOKEN_NOT_EQUAL = 27;
const TOKEN_PLUS = 28;
const TOKEN_PLUS_PLUS = 29;
const TOKEN_QUESTION_MARK = 30;
const TOKEN_REMAINDER = 31;
const TOKEN_RIGHT_BRACE = 32;
const TOKEN_RIGHT_PARENTHESIS = 33;
const TOKEN_SEMICOLON = 34;
const TOKEN_SHIFT_LEFT = 35;
const TOKEN_SHIFT_RIGHT = 36;

// Keywords
const TOKEN_BREAK = 37;
const TOKEN_CLASS = 38;
const TOKEN_CONST = 39;
const TOKEN_CONTINUE = 40;
const TOKEN_ELSE = 41;
const TOKEN_EXPORT = 42;
const TOKEN_EXTENDS = 43;
const TOKEN_EXTERN = 44;
const TOKEN_FALSE = 45;
const TOKEN_FUNCTION = 46;
const TOKEN_IF = 47;
const TOKEN_IMPLEMENTS = 48;
const TOKEN_IMPORT = 49;
const TOKEN_INTERFACE = 50;
const TOKEN_NEW = 51;
const TOKEN_NULL = 52;
const TOKEN_RETURN = 53;
const TOKEN_THIS = 54;
const TOKEN_TRUE = 55;
const TOKEN_VAR = 56;
const TOKEN_WHILE = 57;

class Token {
  kind: int;
  range: Range;
  next: Token;
}

function tokenToString(token: int): string {
  if (token == TOKEN_ASSIGN) return "ASSIGN";
  if (token == TOKEN_BITWISE_AND) return "BITWISE_AND";
  if (token == TOKEN_BITWISE_OR) return "BITWISE_OR";
  if (token == TOKEN_BITWISE_XOR) return "BITWISE_XOR";
  if (token == TOKEN_BREAK) return "BREAK";
  if (token == TOKEN_CHARACTER) return "CHARACTER";
  if (token == TOKEN_CLASS) return "CLASS";
  if (token == TOKEN_COLON) return "COLON";
  if (token == TOKEN_COMMA) return "COMMA";
  if (token == TOKEN_COMPLEMENT) return "COMPLEMENT";
  if (token == TOKEN_CONST) return "CONST";
  if (token == TOKEN_CONTINUE) return "CONTINUE";
  if (token == TOKEN_DIVIDE) return "DIVIDE";
  if (token == TOKEN_DOT) return "DOT";
  if (token == TOKEN_ELSE) return "ELSE";
  if (token == TOKEN_END_OF_FILE) return "END_OF_FILE";
  if (token == TOKEN_EQUAL) return "EQUAL";
  if (token == TOKEN_EXPORT) return "EXPORT";
  if (token == TOKEN_EXTENDS) return "EXTENDS";
  if (token == TOKEN_EXTERN) return "EXTERN";
  if (token == TOKEN_FALSE) return "FALSE";
  if (token == TOKEN_FUNCTION) return "FUNCTION";
  if (token == TOKEN_GREATER_THAN) return "GREATER_THAN";
  if (token == TOKEN_GREATER_THAN_EQUAL) return "GREATER_THAN_EQUAL";
  if (token == TOKEN_IDENTIFIER) return "IDENTIFIER";
  if (token == TOKEN_IF) return "IF";
  if (token == TOKEN_IMPLEMENTS) return "IMPLEMENTS";
  if (token == TOKEN_IMPORT) return "IMPORT";
  if (token == TOKEN_INT) return "INT";
  if (token == TOKEN_INTERFACE) return "INTERFACE";
  if (token == TOKEN_LEFT_BRACE) return "LEFT_BRACE";
  if (token == TOKEN_LEFT_PARENTHESIS) return "LEFT_PARENTHESIS";
  if (token == TOKEN_LESS_THAN) return "LESS_THAN";
  if (token == TOKEN_LESS_THAN_EQUAL) return "LESS_THAN_EQUAL";
  if (token == TOKEN_LOGICAL_AND) return "LOGICAL_AND";
  if (token == TOKEN_LOGICAL_OR) return "LOGICAL_OR";
  if (token == TOKEN_MINUS) return "MINUS";
  if (token == TOKEN_MINUS_MINUS) return "MINUS_MINUS";
  if (token == TOKEN_MULTIPLY) return "MULTIPLY";
  if (token == TOKEN_NEW) return "NEW";
  if (token == TOKEN_NOT) return "NOT";
  if (token == TOKEN_NOT_EQUAL) return "NOT_EQUAL";
  if (token == TOKEN_NULL) return "NULL";
  if (token == TOKEN_PLUS) return "PLUS";
  if (token == TOKEN_PLUS_PLUS) return "PLUS_PLUS";
  if (token == TOKEN_QUESTION_MARK) return "QUESTION_MARK";
  if (token == TOKEN_REMAINDER) return "REMAINDER";
  if (token == TOKEN_RETURN) return "RETURN";
  if (token == TOKEN_RIGHT_BRACE) return "RIGHT_BRACE";
  if (token == TOKEN_RIGHT_PARENTHESIS) return "RIGHT_PARENTHESIS";
  if (token == TOKEN_SEMICOLON) return "SEMICOLON";
  if (token == TOKEN_SHIFT_LEFT) return "SHIFT_LEFT";
  if (token == TOKEN_SHIFT_RIGHT) return "SHIFT_RIGHT";
  if (token == TOKEN_STRING) return "STRING";
  if (token == TOKEN_THIS) return "THIS";
  if (token == TOKEN_TRUE) return "TRUE";
  if (token == TOKEN_VAR) return "VAR";
  if (token == TOKEN_WHILE) return "WHILE";
  return null;
}

function isAlpha(c: int): bool {
  return
    c >= 'a' && c <= 'z' ||
    c >= 'A' && c <= 'Z' ||
    c == '_';
}

function isNumber(c: int): bool {
  return c >= '0' && c <= '9';
}

function tokenize(source: Source, log: Log): Token {
  var first: Token = null;
  var last: Token = null;
  var contents = source.contents;
  var limit = String_length(contents);
  var i = 0;

  while (i < limit) {
    var start = i;
    var c = String_get(contents, i);
    i = i + 1;

    if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
      continue;
    }

    var kind = TOKEN_END_OF_FILE;

    // Identifier
    if (isAlpha(c)) {
      kind = TOKEN_IDENTIFIER;

      while (i < limit && (isAlpha(String_get(contents, i)) || isNumber(String_get(contents, i)))) {
        i = i + 1;
      }

      // Keywords
      var text = String_slice(contents, start, i);
      if (String_equalNew(text, "break")) kind = TOKEN_BREAK;
      else if (String_equalNew(text, "class")) kind = TOKEN_CLASS;
      else if (String_equalNew(text, "const")) kind = TOKEN_CONST;
      else if (String_equalNew(text, "continue")) kind = TOKEN_CONTINUE;
      else if (String_equalNew(text, "else")) kind = TOKEN_ELSE;
      else if (String_equalNew(text, "export")) kind = TOKEN_EXPORT;
      else if (String_equalNew(text, "extends")) kind = TOKEN_EXTENDS;
      else if (String_equalNew(text, "extern")) kind = TOKEN_EXTERN;
      else if (String_equalNew(text, "false")) kind = TOKEN_FALSE;
      else if (String_equalNew(text, "function")) kind = TOKEN_FUNCTION;
      else if (String_equalNew(text, "if")) kind = TOKEN_IF;
      else if (String_equalNew(text, "implements")) kind = TOKEN_IMPLEMENTS;
      else if (String_equalNew(text, "import")) kind = TOKEN_IMPORT;
      else if (String_equalNew(text, "interface")) kind = TOKEN_INTERFACE;
      else if (String_equalNew(text, "new")) kind = TOKEN_NEW;
      else if (String_equalNew(text, "null")) kind = TOKEN_NULL;
      else if (String_equalNew(text, "return")) kind = TOKEN_RETURN;
      else if (String_equalNew(text, "this")) kind = TOKEN_THIS;
      else if (String_equalNew(text, "true")) kind = TOKEN_TRUE;
      else if (String_equalNew(text, "var")) kind = TOKEN_VAR;
      else if (String_equalNew(text, "while")) kind = TOKEN_WHILE;
    }

    // Integer
    else if (isNumber(c)) {
      kind = TOKEN_INT;

      while (i < limit && isNumber(String_get(contents, i))) {
        i = i + 1;
      }
    }

    // Character or string
    else if (c == '"' || c == '\'') {
      while (i < limit) {
        var next = String_get(contents, i);
        i = i + 1;
        if (i + 1 < limit && next == '\\') {
          i = i + 1;
        } else if (next == c) {
          kind = c == '"' ? TOKEN_STRING : TOKEN_CHARACTER;
          break;
        }
      }
    }

    // Operators
    else if (c == '%') kind = TOKEN_REMAINDER;
    else if (c == '(') kind = TOKEN_LEFT_PARENTHESIS;
    else if (c == ')') kind = TOKEN_RIGHT_PARENTHESIS;
    else if (c == '*') kind = TOKEN_MULTIPLY;
    else if (c == ',') kind = TOKEN_COMMA;
    else if (c == '.') kind = TOKEN_DOT;
    else if (c == ':') kind = TOKEN_COLON;
    else if (c == ';') kind = TOKEN_SEMICOLON;
    else if (c == '?') kind = TOKEN_QUESTION_MARK;
    else if (c == '^') kind = TOKEN_BITWISE_XOR;
    else if (c == '{') kind = TOKEN_LEFT_BRACE;
    else if (c == '}') kind = TOKEN_RIGHT_BRACE;
    else if (c == '~') kind = TOKEN_COMPLEMENT;

    // / or //
    else if (c == '/') {
      kind = TOKEN_DIVIDE;

      if (i < limit && String_get(contents, i) == '/') {
        i = i + 1;

        while (i < limit && String_get(contents, i) != '\n') {
          i = i + 1;
        }

        continue;
      }
    }

    // ! or !=
    else if (c == '!') {
      kind = TOKEN_NOT;

      if (i < limit && String_get(contents, i) == '=') {
        kind = TOKEN_NOT_EQUAL;
        i = i + 1;

        // Recover from !==
        if (i < limit && String_get(contents, i) == '=') {
          i = i + 1;
          error(log, createRange(source, start, i), String_new("Use '!=' instead of '!=='"));
        }
      }
    }

    // = or ==
    else if (c == '=') {
      kind = TOKEN_ASSIGN;

      if (i < limit && String_get(contents, i) == '=') {
        kind = TOKEN_EQUAL;
        i = i + 1;

        // Recover from ===
        if (i < limit && String_get(contents, i) == '=') {
          i = i + 1;
          error(log, createRange(source, start, i), String_new("Use '==' instead of '==='"));
        }
      }
    }

    // + or ++
    else if (c == '+') {
      kind = TOKEN_PLUS;

      if (i < limit && String_get(contents, i) == '+') {
        kind = TOKEN_PLUS_PLUS;
        i = i + 1;
      }
    }

    // - or --
    else if (c == '-') {
      kind = TOKEN_MINUS;

      if (i < limit && String_get(contents, i) == '-') {
        kind = TOKEN_MINUS_MINUS;
        i = i + 1;
      }
    }

    // & or &&
    else if (c == '&') {
      kind = TOKEN_BITWISE_AND;

      if (i < limit && String_get(contents, i) == '&') {
        kind = TOKEN_LOGICAL_AND;
        i = i + 1;
      }
    }

    // | or ||
    else if (c == '|') {
      kind = TOKEN_BITWISE_OR;

      if (i < limit && String_get(contents, i) == '|') {
        kind = TOKEN_LOGICAL_OR;
        i = i + 1;
      }
    }

    // < or << or <=
    else if (c == '<') {
      kind = TOKEN_LESS_THAN;

      if (i < limit) {
        c = String_get(contents, i);

        if (c == '<') {
          kind = TOKEN_SHIFT_LEFT;
          i = i + 1;
        }

        else if (c == '=') {
          kind = TOKEN_LESS_THAN_EQUAL;
          i = i + 1;
        }
      }
    }

    // > or >> or >=
    else if (c == '>') {
      kind = TOKEN_GREATER_THAN;

      if (i < limit) {
        c = String_get(contents, i);

        if (c == '>') {
          kind = TOKEN_SHIFT_RIGHT;
          i = i + 1;
        }

        else if (c == '=') {
          kind = TOKEN_GREATER_THAN_EQUAL;
          i = i + 1;
        }
      }
    }

    var range = createRange(source, start, i);

    if (kind == TOKEN_END_OF_FILE) {
      error(log, range,
        String_appendNew(
          String_append(
            String_new("Syntax error: '"),
            String_slice(contents, start, start + 1)),
          "'"));
      return null;
    }

    var token = new Token();
    token.kind = kind;
    token.range = range;

    if (first == null) {
      first = token;
      last = token;
    }

    else {
      last.next = token;
      last = token;
    }
  }

  var token = new Token();
  token.kind = TOKEN_END_OF_FILE;
  token.range = createRange(source, limit, limit);

  if (first == null) {
    first = token;
    last = token;
  }

  else {
    last.next = token;
    last = token;
  }

  return first;
}
