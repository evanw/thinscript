// Other
const NODE_GLOBAL = 0;
const NODE_VARIABLE = 1;

// Statements
const NODE_BLOCK = 2;
const NODE_BREAK = 3;
const NODE_CLASS = 4;
const NODE_CONSTANTS = 5;
const NODE_CONTINUE = 6;
const NODE_EMPTY = 7;
const NODE_EXPRESSION = 8;
const NODE_FUNCTION = 9;
const NODE_IF = 10;
const NODE_RETURN = 11;
const NODE_VARIABLES = 12;
const NODE_WHILE = 13;

// Expressions
const NODE_BOOL = 14;
const NODE_CALL = 15;
const NODE_CAST = 16;
const NODE_DOT = 17;
const NODE_HOOK = 18;
const NODE_INT = 19;
const NODE_NAME = 20;
const NODE_NEW = 21;
const NODE_NULL = 22;
const NODE_STRING = 23;
const NODE_THIS = 24;
const NODE_TYPE = 25;

// Unary expressions
const NODE_COMPLEMENT = 26;
const NODE_NEGATIVE = 27;
const NODE_NOT = 28;
const NODE_POSITIVE = 29;
const NODE_POSTFIX_DECREMENT = 30;
const NODE_POSTFIX_INCREMENT = 31;
const NODE_PREFIX_DECREMENT = 32;
const NODE_PREFIX_INCREMENT = 33;

// Binary expressions
const NODE_ADD = 34;
const NODE_ASSIGN = 35;
const NODE_BITWISE_AND = 36;
const NODE_BITWISE_OR = 37;
const NODE_BITWISE_XOR = 38;
const NODE_DIVIDE = 39;
const NODE_EQUAL = 40;
const NODE_GREATER_THAN = 41;
const NODE_GREATER_THAN_EQUAL = 42;
const NODE_LESS_THAN = 43;
const NODE_LESS_THAN_EQUAL = 44;
const NODE_LOGICAL_AND = 45;
const NODE_LOGICAL_OR = 46;
const NODE_MULTIPLY = 47;
const NODE_NOT_EQUAL = 48;
const NODE_REMAINDER = 49;
const NODE_SHIFT_LEFT = 50;
const NODE_SHIFT_RIGHT = 51;
const NODE_SUBTRACT = 52;

function isUnary(kind: int): bool {
  return kind >= NODE_COMPLEMENT && kind <= NODE_PREFIX_INCREMENT;
}

function isUnaryPostfix(kind: int): bool {
  return kind >= NODE_POSTFIX_DECREMENT && kind <= NODE_POSTFIX_INCREMENT;
}

function isBinary(kind: int): bool {
  return kind >= NODE_ADD && kind <= NODE_SUBTRACT;
}

function isExpression(node: Node): bool {
  return node.kind >= NODE_BOOL && node.kind <= NODE_SUBTRACT;
}

const NODE_FLAG_EXTERN = 1;

class Node {
  kind: int;
  flags: int;
  range: Range;
  internalRange: Range;
  parent: Node;
  firstChild: Node;
  lastChild: Node;
  previousSibling: Node;
  nextSibling: Node;
  intValue: int;
  stringValue: String;
  resolvedType: Type;
  symbol: Symbol;
  scope: Scope;

  childCount(): int {
    var count = 0;
    var child = this.firstChild;
    while (child != null) {
      count = count + 1;
      child = child.nextSibling;
    }
    return count;
  }

  appendChild(child: Node): void {
    child.parent = this;

    if (this.firstChild == null) {
      this.firstChild = child;
      this.lastChild = child;
    }

    else {
      child.previousSibling = this.lastChild;
      this.lastChild.nextSibling = child;
      this.lastChild = child;
    }
  }

  insertChildBefore(after: Node, before: Node): void {
    if (before == null) {
      return;
    }

    assert(before != after);
    assert(before.parent == null);
    assert(before.previousSibling == null);
    assert(before.nextSibling == null);
    assert(after == null || after.parent == this);

    if (after == null) {
      this.appendChild(before);
      return;
    }

    before.parent = this;
    before.previousSibling = after.previousSibling;
    before.nextSibling = after;

    if (after.previousSibling != null) {
      assert(after == after.previousSibling.nextSibling);
      after.previousSibling.nextSibling = before;
    } else {
      assert(after == this.firstChild);
      this.firstChild = before;
    }

    after.previousSibling = before;
  }

  remove(): void {
    assert(this.parent != null);

    if (this.previousSibling != null) {
      assert(this.previousSibling.nextSibling == this);
      this.previousSibling.nextSibling = this.nextSibling;
    } else {
      assert(this.parent.firstChild == this);
      this.parent.firstChild = this.nextSibling;
    }

    if (this.nextSibling != null) {
      assert(this.nextSibling.previousSibling == this);
      this.nextSibling.previousSibling = this.previousSibling;
    } else {
      assert(this.parent.lastChild == this);
      this.parent.lastChild = this.previousSibling;
    }

    this.parent = null;
    this.previousSibling = null;
    this.nextSibling = null;
  }

  withRange(range: Range): Node {
    this.range = range;
    return this;
  }

  withInternalRange(range: Range): Node {
    this.internalRange = range;
    return this;
  }

  functionFirstArgumentIgnoringThis(): Node {
    assert(this.kind == NODE_FUNCTION);
    assert(this.childCount() >= 2);
    assert(this.symbol != null);
    return this.symbol.kind == FUNCTION_INSTANCE ? this.firstChild.nextSibling : this.firstChild;
  }

  functionReturnType(): Node {
    assert(this.kind == NODE_FUNCTION);
    assert(this.childCount() >= 2);
    assert(isExpression(this.lastChild.previousSibling));
    return this.lastChild.previousSibling;
  }

  functionBody(): Node {
    assert(this.kind == NODE_FUNCTION);
    assert(this.childCount() >= 2);
    assert(this.lastChild.kind == NODE_BLOCK || this.lastChild.kind == NODE_EMPTY);
    var body = this.lastChild;
    return body.kind == NODE_BLOCK ? body : null;
  }

  newType(): Node {
    assert(this.kind == NODE_NEW);
    assert(this.childCount() == 1);
    assert(isExpression(this.firstChild));
    return this.firstChild;
  }

  callValue(): Node {
    assert(this.kind == NODE_CALL);
    assert(this.childCount() >= 1);
    assert(isExpression(this.firstChild));
    return this.firstChild;
  }

  dotTarget(): Node {
    assert(this.kind == NODE_DOT);
    assert(this.childCount() == 1);
    assert(isExpression(this.firstChild));
    return this.firstChild;
  }

  returnValue(): Node {
    assert(this.kind == NODE_RETURN);
    assert(this.childCount() <= 1);
    assert(this.firstChild == null || isExpression(this.firstChild));
    return this.firstChild;
  }

  variableType(): Node {
    assert(this.kind == NODE_VARIABLE);
    assert(this.childCount() <= 2);
    assert(isExpression(this.firstChild) || this.firstChild.kind == NODE_EMPTY);
    var type = this.firstChild;
    return type.kind != NODE_EMPTY ? type : null;
  }

  variableValue(): Node {
    assert(this.kind == NODE_VARIABLE);
    assert(this.childCount() <= 2);
    assert(this.firstChild.nextSibling == null || isExpression(this.firstChild.nextSibling));
    return this.firstChild.nextSibling;
  }

  expressionValue(): Node {
    assert(this.kind == NODE_EXPRESSION);
    assert(this.childCount() == 1);
    assert(isExpression(this.firstChild));
    return this.firstChild;
  }

  binaryLeft(): Node {
    assert(isBinary(this.kind));
    assert(this.childCount() == 2);
    assert(isExpression(this.firstChild));
    return this.firstChild;
  }

  binaryRight(): Node {
    assert(isBinary(this.kind));
    assert(this.childCount() == 2);
    assert(isExpression(this.lastChild));
    return this.lastChild;
  }

  unaryValue(): Node {
    assert(isUnary(this.kind));
    assert(this.childCount() == 1);
    assert(isExpression(this.firstChild));
    return this.firstChild;
  }

  whileValue(): Node {
    assert(this.kind == NODE_WHILE);
    assert(this.childCount() == 2);
    assert(isExpression(this.firstChild));
    return this.firstChild;
  }

  whileBody(): Node {
    assert(this.kind == NODE_WHILE);
    assert(this.childCount() == 2);
    assert(this.lastChild.kind == NODE_BLOCK);
    return this.lastChild;
  }

  hookValue(): Node {
    assert(this.kind == NODE_HOOK);
    assert(this.childCount() == 3);
    assert(isExpression(this.firstChild));
    return this.firstChild;
  }

  hookTrue(): Node {
    assert(this.kind == NODE_HOOK);
    assert(this.childCount() == 3);
    assert(isExpression(this.firstChild.nextSibling));
    return this.firstChild.nextSibling;
  }

  hookFalse(): Node {
    assert(this.kind == NODE_HOOK);
    assert(this.childCount() == 3);
    assert(isExpression(this.lastChild));
    return this.lastChild;
  }

  ifValue(): Node {
    assert(this.kind == NODE_IF);
    assert(this.childCount() == 2 || this.childCount() == 3);
    assert(isExpression(this.firstChild));
    return this.firstChild;
  }

  ifTrue(): Node {
    assert(this.kind == NODE_IF);
    assert(this.childCount() == 2 || this.childCount() == 3);
    assert(this.firstChild.nextSibling.kind == NODE_BLOCK);
    return this.firstChild.nextSibling;
  }

  ifFalse(): Node {
    assert(this.kind == NODE_IF);
    assert(this.childCount() == 2 || this.childCount() == 3);
    assert(this.firstChild.nextSibling.nextSibling == null || this.firstChild.nextSibling.nextSibling.kind == NODE_BLOCK);
    return this.firstChild.nextSibling.nextSibling;
  }
}

function createNew(type: Node): Node {
  assert(isExpression(type));
  var node = new Node();
  node.kind = NODE_NEW;
  node.appendChild(type);
  return node;
}

function createHook(test: Node, primary: Node, secondary: Node): Node {
  assert(isExpression(test));
  assert(isExpression(primary));
  assert(isExpression(secondary));
  var node = new Node();
  node.kind = NODE_HOOK;
  node.appendChild(test);
  node.appendChild(primary);
  node.appendChild(secondary);
  return node;
}

function createNull(): Node {
  var node = new Node();
  node.kind = NODE_NULL;
  return node;
}

function createThis(): Node {
  var node = new Node();
  node.kind = NODE_THIS;
  return node;
}

function createBool(value: bool): Node {
  var node = new Node();
  node.kind = NODE_BOOL;
  node.intValue = value ? 1 : 0;
  return node;
}

function createInt(value: int): Node {
  var node = new Node();
  node.kind = NODE_INT;
  node.intValue = value;
  return node;
}

function createString(value: String): Node {
  var node = new Node();
  node.kind = NODE_STRING;
  node.stringValue = value;
  return node;
}

function createName(value: String): Node {
  var node = new Node();
  node.kind = NODE_NAME;
  node.stringValue = value;
  return node;
}

function createType(type: Type): Node {
  var node = new Node();
  node.kind = NODE_TYPE;
  node.resolvedType = type;
  return node;
}

function createEmpty(): Node {
  var node = new Node();
  node.kind = NODE_EMPTY;
  return node;
}

function createExpression(value: Node): Node {
  assert(isExpression(value));
  var node = new Node();
  node.kind = NODE_EXPRESSION;
  node.appendChild(value);
  return node;
}

function createBlock(): Node {
  var node = new Node();
  node.kind = NODE_BLOCK;
  return node;
}

function createClass(name: String): Node {
  var node = new Node();
  node.kind = NODE_CLASS;
  node.stringValue = name;
  return node;
}

function createIf(value: Node, trueBranch: Node, falseBranch: Node): Node {
  assert(isExpression(value));
  assert(trueBranch.kind == NODE_BLOCK);
  assert(falseBranch == null || falseBranch.kind == NODE_BLOCK);
  var node = new Node();
  node.kind = NODE_IF;
  node.appendChild(value);
  node.appendChild(trueBranch);
  if (falseBranch != null) {
    node.appendChild(falseBranch);
  }
  return node;
}

function createWhile(value: Node, body: Node): Node {
  assert(isExpression(value));
  assert(body.kind == NODE_BLOCK);
  var node = new Node();
  node.kind = NODE_WHILE;
  node.appendChild(value);
  node.appendChild(body);
  return node;
}

function createReturn(value: Node): Node {
  assert(value == null || isExpression(value));
  var node = new Node();
  node.kind = NODE_RETURN;
  if (value != null) {
    node.appendChild(value);
  }
  return node;
}

function createVariables(): Node {
  var node = new Node();
  node.kind = NODE_VARIABLES;
  return node;
}

function createConstants(): Node {
  var node = new Node();
  node.kind = NODE_CONSTANTS;
  return node;
}

function createVariable(name: String, type: Node, value: Node): Node {
  assert(type == null || isExpression(type));
  assert(value == null || isExpression(value));

  var node = new Node();
  node.kind = NODE_VARIABLE;
  node.stringValue = name;

  node.appendChild(type != null ? type : createEmpty());
  if (value != null) {
    node.appendChild(value);
  }

  return node;
}

function createFunction(name: String): Node {
  var node = new Node();
  node.kind = NODE_FUNCTION;
  node.stringValue = name;
  return node;
}

function createUnary(kind: int, value: Node): Node {
  assert(isUnary(kind));
  assert(isExpression(value));
  var node = new Node();
  node.kind = kind;
  node.appendChild(value);
  return node;
}

function createBinary(kind: int, left: Node, right: Node): Node {
  assert(isBinary(kind));
  assert(isExpression(left));
  assert(isExpression(right));
  var node = new Node();
  node.kind = kind;
  node.appendChild(left);
  node.appendChild(right);
  return node;
}

function createCall(value: Node): Node {
  assert(isExpression(value));
  var node = new Node();
  node.kind = NODE_CALL;
  node.appendChild(value);
  return node;
}

function createDot(value: Node, name: String): Node {
  assert(isExpression(value));
  var node = new Node();
  node.kind = NODE_DOT;
  node.stringValue = name;
  node.appendChild(value);
  return node;
}
