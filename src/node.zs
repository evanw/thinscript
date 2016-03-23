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

// Unary expressions
const NODE_COMPLEMENT = 24;
const NODE_NEGATIVE = 25;
const NODE_NOT = 26;
const NODE_POSITIVE = 27;
const NODE_POSTFIX_DECREMENT = 28;
const NODE_POSTFIX_INCREMENT = 29;
const NODE_PREFIX_DECREMENT = 30;
const NODE_PREFIX_INCREMENT = 31;

// Binary expressions
const NODE_ADD = 32;
const NODE_ASSIGN = 33;
const NODE_BITWISE_AND = 34;
const NODE_BITWISE_OR = 35;
const NODE_BITWISE_XOR = 36;
const NODE_DIVIDE = 37;
const NODE_EQUAL = 38;
const NODE_GREATER_THAN = 39;
const NODE_GREATER_THAN_EQUAL = 40;
const NODE_LESS_THAN = 41;
const NODE_LESS_THAN_EQUAL = 42;
const NODE_LOGICAL_AND = 43;
const NODE_LOGICAL_OR = 44;
const NODE_MULTIPLY = 45;
const NODE_NOT_EQUAL = 46;
const NODE_REMAINDER = 47;
const NODE_SHIFT_LEFT = 48;
const NODE_SHIFT_RIGHT = 49;
const NODE_SUBTRACT = 50;

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

class Node {
  kind: int;
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
}

function childCount(node: Node): int {
  var count = 0;
  var child = node.firstChild;
  while (child != null) {
    count = count + 1;
    child = child.nextSibling;
  }
  return count;
}

function appendChild(node: Node, child: Node): void {
  child.parent = node;

  if (node.firstChild == null) {
    node.firstChild = child;
    node.lastChild = child;
  }

  else {
    child.previousSibling = node.lastChild;
    node.lastChild.nextSibling = child;
    node.lastChild = child;
  }
}

function withRange(node: Node, range: Range): Node {
  node.range = range;
  return node;
}

function withInternalRange(node: Node, range: Range): Node {
  node.internalRange = range;
  return node;
}

function createNew(type: Node): Node {
  assert(isExpression(type));
  var node = new Node();
  node.kind = NODE_NEW;
  appendChild(node, type);
  return node;
}

function createHook(test: Node, primary: Node, secondary: Node): Node {
  assert(isExpression(test));
  assert(isExpression(primary));
  assert(isExpression(secondary));
  var node = new Node();
  node.kind = NODE_HOOK;
  appendChild(node, test);
  appendChild(node, primary);
  appendChild(node, secondary);
  return node;
}

function createNull(): Node {
  var node = new Node();
  node.kind = NODE_NULL;
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

function createEmpty(): Node {
  var node = new Node();
  node.kind = NODE_EMPTY;
  return node;
}

function createExpression(value: Node): Node {
  assert(isExpression(value));
  var node = new Node();
  node.kind = NODE_EXPRESSION;
  appendChild(node, value);
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
  appendChild(node, value);
  appendChild(node, trueBranch);
  if (falseBranch != null) {
    appendChild(node, falseBranch);
  }
  return node;
}

function createWhile(value: Node, body: Node): Node {
  assert(isExpression(value));
  assert(body.kind == NODE_BLOCK);
  var node = new Node();
  node.kind = NODE_WHILE;
  appendChild(node, value);
  appendChild(node, body);
  return node;
}

function createReturn(value: Node): Node {
  assert(value == null || isExpression(value));
  var node = new Node();
  node.kind = NODE_RETURN;
  if (value != null) {
    appendChild(node, value);
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

  appendChild(node, type != null ? type : createEmpty());
  if (value != null) {
    appendChild(node, value);
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
  appendChild(node, value);
  return node;
}

function createBinary(kind: int, left: Node, right: Node): Node {
  assert(isBinary(kind));
  assert(isExpression(left));
  assert(isExpression(right));
  var node = new Node();
  node.kind = kind;
  appendChild(node, left);
  appendChild(node, right);
  return node;
}

function createCall(value: Node): Node {
  assert(isExpression(value));
  var node = new Node();
  node.kind = NODE_CALL;
  appendChild(node, value);
  return node;
}

function createDot(value: Node, name: String): Node {
  assert(isExpression(value));
  var node = new Node();
  node.kind = NODE_DOT;
  node.stringValue = name;
  appendChild(node, value);
  return node;
}

function functionReturnType(node: Node): Node {
  assert(node.kind == NODE_FUNCTION);
  assert(childCount(node) >= 2);
  assert(isExpression(node.lastChild.previousSibling));
  return node.lastChild.previousSibling;
}

function functionBody(node: Node): Node {
  assert(node.kind == NODE_FUNCTION);
  assert(childCount(node) >= 2);
  assert(node.lastChild.kind == NODE_BLOCK || node.lastChild.kind == NODE_EMPTY);
  var body = node.lastChild;
  return body.kind == NODE_BLOCK ? body : null;
}

function newType(node: Node): Node {
  assert(node.kind == NODE_NEW);
  assert(childCount(node) == 1);
  assert(isExpression(node.firstChild));
  return node.firstChild;
}

function callValue(node: Node): Node {
  assert(node.kind == NODE_CALL);
  assert(childCount(node) >= 1);
  assert(isExpression(node.firstChild));
  return node.firstChild;
}

function dotTarget(node: Node): Node {
  assert(node.kind == NODE_DOT);
  assert(childCount(node) == 1);
  assert(isExpression(node.firstChild));
  return node.firstChild;
}

function returnValue(node: Node): Node {
  assert(node.kind == NODE_RETURN);
  assert(childCount(node) <= 1);
  assert(node.firstChild == null || isExpression(node.firstChild));
  return node.firstChild;
}

function variableType(node: Node): Node {
  assert(node.kind == NODE_VARIABLE);
  assert(childCount(node) <= 2);
  assert(isExpression(node.firstChild) || node.firstChild.kind == NODE_EMPTY);
  var type = node.firstChild;
  return type.kind != NODE_EMPTY ? type : null;
}

function variableValue(node: Node): Node {
  assert(node.kind == NODE_VARIABLE);
  assert(childCount(node) <= 2);
  assert(node.firstChild.nextSibling == null || isExpression(node.firstChild.nextSibling));
  return node.firstChild.nextSibling;
}

function expressionValue(node: Node): Node {
  assert(node.kind == NODE_EXPRESSION);
  assert(childCount(node) == 1);
  assert(isExpression(node.firstChild));
  return node.firstChild;
}

function binaryLeft(node: Node): Node {
  assert(isBinary(node.kind));
  assert(childCount(node) == 2);
  assert(isExpression(node.firstChild));
  return node.firstChild;
}

function binaryRight(node: Node): Node {
  assert(isBinary(node.kind));
  assert(childCount(node) == 2);
  assert(isExpression(node.lastChild));
  return node.lastChild;
}

function unaryValue(node: Node): Node {
  assert(isUnary(node.kind));
  assert(childCount(node) == 1);
  assert(isExpression(node.firstChild));
  return node.firstChild;
}

function whileValue(node: Node): Node {
  assert(node.kind == NODE_WHILE);
  assert(childCount(node) == 2);
  assert(isExpression(node.firstChild));
  return node.firstChild;
}

function whileBody(node: Node): Node {
  assert(node.kind == NODE_WHILE);
  assert(childCount(node) == 2);
  assert(node.lastChild.kind == NODE_BLOCK);
  return node.lastChild;
}

function hookValue(node: Node): Node {
  assert(node.kind == NODE_HOOK);
  assert(childCount(node) == 3);
  assert(isExpression(node.firstChild));
  return node.firstChild;
}

function hookTrue(node: Node): Node {
  assert(node.kind == NODE_HOOK);
  assert(childCount(node) == 3);
  assert(isExpression(node.firstChild.nextSibling));
  return node.firstChild.nextSibling;
}

function hookFalse(node: Node): Node {
  assert(node.kind == NODE_HOOK);
  assert(childCount(node) == 3);
  assert(isExpression(node.lastChild));
  return node.lastChild;
}

function ifValue(node: Node): Node {
  assert(node.kind == NODE_IF);
  assert(childCount(node) == 2 || childCount(node) == 3);
  assert(isExpression(node.firstChild));
  return node.firstChild;
}

function ifTrue(node: Node): Node {
  assert(node.kind == NODE_IF);
  assert(childCount(node) == 2 || childCount(node) == 3);
  assert(node.firstChild.nextSibling.kind == NODE_BLOCK);
  return node.firstChild.nextSibling;
}

function ifFalse(node: Node): Node {
  assert(node.kind == NODE_IF);
  assert(childCount(node) == 2 || childCount(node) == 3);
  assert(node.firstChild.nextSibling.nextSibling == null || node.firstChild.nextSibling.nextSibling.kind == NODE_BLOCK);
  return node.firstChild.nextSibling.nextSibling;
}
