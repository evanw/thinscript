// Control flow operators
const WASM_OPCODE_NOP = 0;
const WASM_OPCODE_BLOCK = 1;
const WASM_OPCODE_LOOP = 2;
const WASM_OPCODE_IF = 3;
const WASM_OPCODE_IF_ELSE = 4;
const WASM_OPCODE_SELECT = 5;
const WASM_OPCODE_BR = 6;
const WASM_OPCODE_BR_IF = 7;
const WASM_OPCODE_BR_TABLE = 8;
const WASM_OPCODE_RETURN = 20;
const WASM_OPCODE_UNREACHABLE = 21;

// Basic operators
const WASM_OPCODE_I32_CONST = 10;
const WASM_OPCODE_I64_CONST = 11;
const WASM_OPCODE_F64_CONST = 12;
const WASM_OPCODE_F32_CONST = 13;
const WASM_OPCODE_GET_LOCAL = 14;
const WASM_OPCODE_SET_LOCAL = 15;
const WASM_OPCODE_CALL = 18;
const WASM_OPCODE_CALL_INDIRECT = 19;
const WASM_OPCODE_CALL_IMPORT = 31;

// Memory-related operators
const WASM_OPCODE_I32_LOAD8_S = 32;
const WASM_OPCODE_I32_LOAD8_U = 33;
const WASM_OPCODE_I32_LOAD16_S = 34;
const WASM_OPCODE_I32_LOAD16_U = 35;
const WASM_OPCODE_I64_LOAD8_S = 36;
const WASM_OPCODE_I64_LOAD8_U = 37;
const WASM_OPCODE_I64_LOAD16_S = 38;
const WASM_OPCODE_I64_LOAD16_U = 39;
const WASM_OPCODE_I64_LOAD32_S = 40;
const WASM_OPCODE_I64_LOAD32_U = 41;
const WASM_OPCODE_I32_LOAD = 42;
const WASM_OPCODE_I64_LOAD = 43;
const WASM_OPCODE_F32_LOAD = 44;
const WASM_OPCODE_F64_LOAD = 45;
const WASM_OPCODE_I32_STORE8 = 46;
const WASM_OPCODE_I32_STORE16 = 47;
const WASM_OPCODE_I64_STORE8 = 48;
const WASM_OPCODE_I64_STORE16 = 49;
const WASM_OPCODE_I64_STORE32 = 50;
const WASM_OPCODE_I32_STORE = 51;
const WASM_OPCODE_I64_STORE = 52;
const WASM_OPCODE_F32_STORE = 53;
const WASM_OPCODE_F64_STORE = 54;
const WASM_OPCODE_MEMORY_SIZE = 59;
const WASM_OPCODE_GROW_MEMORY = 57;

// Simple operators
const WASM_OPCODE_I32_ADD = 64;
const WASM_OPCODE_I32_SUB = 65;
const WASM_OPCODE_I32_MUL = 66;
const WASM_OPCODE_I32_DIV_S = 67;
const WASM_OPCODE_I32_DIV_U = 68;
const WASM_OPCODE_I32_REM_S = 69;
const WASM_OPCODE_I32_REM_U = 70;
const WASM_OPCODE_I32_AND = 71;
const WASM_OPCODE_I32_OR = 72;
const WASM_OPCODE_I32_XOR = 73;
const WASM_OPCODE_I32_SHL = 74;
const WASM_OPCODE_I32_SHR_U = 75;
const WASM_OPCODE_I32_SHR_S = 76;
const WASM_OPCODE_I32_ROTR = 182;
const WASM_OPCODE_I32_ROTL = 183;
const WASM_OPCODE_I32_EQ = 77;
const WASM_OPCODE_I32_NE = 78;
const WASM_OPCODE_I32_LT_S = 79;
const WASM_OPCODE_I32_LE_S = 80;
const WASM_OPCODE_I32_LT_U = 81;
const WASM_OPCODE_I32_LE_U = 82;
const WASM_OPCODE_I32_GT_S = 83;
const WASM_OPCODE_I32_GE_S = 84;
const WASM_OPCODE_I32_GT_U = 85;
const WASM_OPCODE_I32_GE_U = 86;
const WASM_OPCODE_I32_CLZ = 87;
const WASM_OPCODE_I32_CTZ = 88;
const WASM_OPCODE_I32_POPCNT = 89;
const WASM_OPCODE_I32_EQZ = 90;
const WASM_OPCODE_I64_ADD = 91;
const WASM_OPCODE_I64_SUB = 92;
const WASM_OPCODE_I64_MUL = 93;
const WASM_OPCODE_I64_DIV_S = 94;
const WASM_OPCODE_I64_DIV_U = 95;
const WASM_OPCODE_I64_REM_S = 96;
const WASM_OPCODE_I64_REM_U = 97;
const WASM_OPCODE_I64_AND = 98;
const WASM_OPCODE_I64_OR = 99;
const WASM_OPCODE_I64_XOR = 100;
const WASM_OPCODE_I64_SHL = 101;
const WASM_OPCODE_I64_SHR_U = 102;
const WASM_OPCODE_I64_SHR_S = 103;
const WASM_OPCODE_I64_ROTR = 184;
const WASM_OPCODE_I64_ROTL = 185;
const WASM_OPCODE_I64_EQ = 104;
const WASM_OPCODE_I64_NE = 105;
const WASM_OPCODE_I64_LT_S = 106;
const WASM_OPCODE_I64_LE_S = 107;
const WASM_OPCODE_I64_LT_U = 108;
const WASM_OPCODE_I64_LE_U = 109;
const WASM_OPCODE_I64_GT_S = 110;
const WASM_OPCODE_I64_GE_S = 111;
const WASM_OPCODE_I64_GT_U = 112;
const WASM_OPCODE_I64_GE_U = 113;
const WASM_OPCODE_I64_CLZ = 114;
const WASM_OPCODE_I64_CTZ = 115;
const WASM_OPCODE_I64_POPCNT = 116;
const WASM_OPCODE_I64_EQZ = 186;
const WASM_OPCODE_F32_ADD = 117;
const WASM_OPCODE_F32_SUB = 118;
const WASM_OPCODE_F32_MUL = 119;
const WASM_OPCODE_F32_DIV = 120;
const WASM_OPCODE_F32_MIN = 121;
const WASM_OPCODE_F32_MAX = 122;
const WASM_OPCODE_F32_ABS = 123;
const WASM_OPCODE_F32_NEG = 124;
const WASM_OPCODE_F32_COPYSIGN = 125;
const WASM_OPCODE_F32_CEIL = 126;
const WASM_OPCODE_F32_FLOOR = 127;
const WASM_OPCODE_F32_TRUNC = 128;
const WASM_OPCODE_F32_NEAREST = 129;
const WASM_OPCODE_F32_SQRT = 130;
const WASM_OPCODE_F32_EQ = 131;
const WASM_OPCODE_F32_NE = 132;
const WASM_OPCODE_F32_LT = 133;
const WASM_OPCODE_F32_LE = 134;
const WASM_OPCODE_F32_GT = 135;
const WASM_OPCODE_F32_GE = 136;
const WASM_OPCODE_F64_ADD = 137;
const WASM_OPCODE_F64_SUB = 138;
const WASM_OPCODE_F64_MUL = 139;
const WASM_OPCODE_F64_DIV = 140;
const WASM_OPCODE_F64_MIN = 141;
const WASM_OPCODE_F64_MAX = 142;
const WASM_OPCODE_F64_ABS = 143;
const WASM_OPCODE_F64_NEG = 144;
const WASM_OPCODE_F64_COPYSIGN = 145;
const WASM_OPCODE_F64_CEIL = 146;
const WASM_OPCODE_F64_FLOOR = 147;
const WASM_OPCODE_F64_TRUNC = 148;
const WASM_OPCODE_F64_NEAREST = 149;
const WASM_OPCODE_F64_SQRT = 150;
const WASM_OPCODE_F64_EQ = 151;
const WASM_OPCODE_F64_NE = 152;
const WASM_OPCODE_F64_LT = 153;
const WASM_OPCODE_F64_LE = 154;
const WASM_OPCODE_F64_GT = 155;
const WASM_OPCODE_F64_GE = 156;
const WASM_OPCODE_I32_TRUNC_S_F32 = 157;
const WASM_OPCODE_I32_TRUNC_S_F64 = 158;
const WASM_OPCODE_I32_TRUNC_U_F32 = 159;
const WASM_OPCODE_I32_TRUNC_U_F64 = 160;
const WASM_OPCODE_I32_WRAP_I64 = 161;
const WASM_OPCODE_I64_TRUNC_S_F32 = 162;
const WASM_OPCODE_I64_TRUNC_S_F64 = 163;
const WASM_OPCODE_I64_TRUNC_U_F32 = 164;
const WASM_OPCODE_I64_TRUNC_U_F64 = 165;
const WASM_OPCODE_I64_EXTEND_S_I32 = 166;
const WASM_OPCODE_I64_EXTEND_U_I32 = 167;
const WASM_OPCODE_F32_CONVERT_S_I32 = 168;
const WASM_OPCODE_F32_CONVERT_U_I32 = 169;
const WASM_OPCODE_F32_CONVERT_S_I64 = 170;
const WASM_OPCODE_F32_CONVERT_U_I64 = 171;
const WASM_OPCODE_F32_DEMOTE_F64 = 172;
const WASM_OPCODE_F32_REINTERPRET_I32 = 173;
const WASM_OPCODE_F64_CONVERT_S_I32 = 174;
const WASM_OPCODE_F64_CONVERT_U_I32 = 175;
const WASM_OPCODE_F64_CONVERT_S_I64 = 176;
const WASM_OPCODE_F64_CONVERT_U_I64 = 177;
const WASM_OPCODE_F64_PROMOTE_F32 = 178;
const WASM_OPCODE_F64_REINTERPRET_I64 = 179;
const WASM_OPCODE_I32_REINTERPRET_F32 = 180;
const WASM_OPCODE_I64_REINTERPRET_F64 = 181;

const WASM_MAGIC = 1836278016;
const WASM_VERSION = 10;
const WASM_I32_LOAD_STORE_ALIGNMENT = 2; // 1 << 2 is 4, and 4 is sizeof(int)
const WASM_SIZE_IN_PAGES = 256;
const WASM_MEMORY_INITIALIZER_OFFSET = 8; // Leave space for "null"

const WASM_TYPE_VOID = 0;
const WASM_TYPE_I32 = 1;
const WASM_TYPE_I64 = 2;
const WASM_TYPE_F32 = 3;
const WASM_TYPE_F64 = 4;

class WasmType {
  id: int;
  next: WasmType;
}

class WasmSignature {
  argumentTypes: WasmType;
  returnType: WasmType;
  next: WasmSignature;
}

function wasmAreSignaturesEqual(a: WasmSignature, b: WasmSignature): bool {
  assert(a.returnType != null);
  assert(b.returnType != null);
  assert(a.returnType.next == null);
  assert(b.returnType.next == null);

  var x = a.argumentTypes;
  var y = b.argumentTypes;

  while (x != null && y != null) {
    if (x.id != y.id) {
      return false;
    }

    x = x.next;
    y = y.next;
  }

  if (x != null || y != null) {
    return false;
  }

  if (a.returnType.id != b.returnType.id) {
    return false;
  }

  return true;
}

class WasmFunction {
  name: String;
  signatureIndex: int;
  body: Node;
  isExported: bool;
  intLocalCount: int;
  next: WasmFunction;
}

class WasmImport {
  signatureIndex: int;
  module: String;
  name: String;
  next: WasmImport;
}

class WasmModule {
  firstImport: WasmImport;
  lastImport: WasmImport;
  importCount: int;

  firstFunction: WasmFunction;
  lastFunction: WasmFunction;
  functionCount: int;

  firstSignature: WasmSignature;
  lastSignature: WasmSignature;
  signatureCount: int;

  memoryInitializer: ByteArray;
}

function wasmAllocateImport(module: WasmModule, signatureIndex: int, mod: String, name: String): WasmImport {
  var result = new WasmImport();
  result.signatureIndex = signatureIndex;
  result.module = mod;
  result.name = name;

  if (module.firstImport == null) module.firstImport = result;
  else module.lastImport.next = result;
  module.lastImport = result;

  module.importCount = module.importCount + 1;
  return result;
}

function wasmAllocateFunction(module: WasmModule, name: String, signatureIndex: int, body: Node): WasmFunction {
  var fn = new WasmFunction();
  fn.name = name;
  fn.signatureIndex = signatureIndex;
  fn.body = body;

  if (module.firstFunction == null) module.firstFunction = fn;
  else module.lastFunction.next = fn;
  module.lastFunction = fn;

  module.functionCount = module.functionCount + 1;
  return fn;
}

function wasmAllocateSignature(module: WasmModule, argumentTypes: WasmType, returnType: WasmType): int {
  assert(returnType != null);
  assert(returnType.next == null);

  var signature = new WasmSignature();
  signature.argumentTypes = argumentTypes;
  signature.returnType = returnType;

  var check = module.firstSignature;
  var i = 0;

  while (check != null) {
    if (wasmAreSignaturesEqual(signature, check)) {
      return i;
    }

    check = check.next;
    i = i + 1;
  }

  if (module.firstSignature == null) module.firstSignature = signature;
  else module.lastSignature.next = signature;
  module.lastSignature = signature;

  module.signatureCount = module.signatureCount + 1;
  return i;
}

function wasmPatchVarUnsigned(array: ByteArray, offset: int, value: int, maxValue: int): void {
  while (true) {
    var byte = value & 127;
    value = (value >> 7) & 33554431;
    maxValue = (maxValue >> 7) & 33554431;
    if (maxValue != 0) {
      byte = byte | 128;
    }
    ByteArray_setByte(array, offset, byte);
    offset = offset + 1;
    if (maxValue == 0) {
      break;
    }
  }
}

function wasmWriteVarUnsigned(array: ByteArray, value: int): void {
  while (true) {
    var byte = value & 127;
    value = (value >> 7) & 33554431; // Unsigned right shift
    if (value != 0) {
      byte = byte | 128;
    }
    ByteArray_appendByte(array, byte);
    if (value == 0) {
      break;
    }
  }
}

function wasmWriteVarSigned(array: ByteArray, value: int): void {
  while (true) {
    var byte = value & 127;
    value = value >> 7; // Signed right shift
    var done =
      value == 0 && (byte & 64) == 0 ||
      value == -1 && (byte & 64) != 0;
    if (!done) {
      byte = byte | 128;
    }
    ByteArray_appendByte(array, byte);
    if (done) {
      break;
    }
  }
}

function wasmWriteLengthPrefixedString(array: ByteArray, value: String): void {
  var length = String_length(value);
  wasmWriteVarUnsigned(array, length);
  var i = 0;
  while (i < length) {
    ByteArray_appendByte(array, String_get(value, i));
    i = i + 1;
  }
}

function wasmStartSection(array: ByteArray, name: String): int {
  var offset = ByteArray_length(array);
  wasmWriteVarUnsigned(array, ~0); // Section length, will be filled in later
  wasmWriteLengthPrefixedString(array, name);
  return offset;
}

function wasmFinishSection(array: ByteArray, offset: int): void {
  wasmPatchVarUnsigned(array, offset, ByteArray_length(array) - offset - 5, ~0);
}

function wasmEmitSignatures(array: ByteArray, module: WasmModule): void {
  var section = wasmStartSection(array, String_new("signatures"));
  wasmWriteVarUnsigned(array, module.signatureCount);

  var signature = module.firstSignature;
  while (signature != null) {
    var count = 0;
    var type = signature.argumentTypes;

    while (type != null) {
      count = count + 1;
      type = type.next;
    }

    wasmWriteVarUnsigned(array, count);
    wasmWriteVarUnsigned(array, signature.returnType.id);

    type = signature.argumentTypes;
    while (type != null) {
      wasmWriteVarUnsigned(array, type.id);
      type = type.next;
    }

    signature = signature.next;
  }

  wasmFinishSection(array, section);
}

function wasmEmitImportTable(array: ByteArray, module: WasmModule): void {
  if (module.firstImport == null) {
    return;
  }

  var section = wasmStartSection(array, String_new("import_table"));
  wasmWriteVarUnsigned(array, module.importCount);

  var current = module.firstImport;
  while (current != null) {
    wasmWriteVarUnsigned(array, current.signatureIndex);
    wasmWriteLengthPrefixedString(array, current.module);
    wasmWriteLengthPrefixedString(array, current.name);
    current = current.next;
  }

  wasmFinishSection(array, section);
}

function wasmEmitFunctionSignatures(array: ByteArray, module: WasmModule): void {
  if (module.firstFunction == null) {
    return;
  }

  var section = wasmStartSection(array, String_new("function_signatures"));
  wasmWriteVarUnsigned(array, module.functionCount);

  var fn = module.firstFunction;
  while (fn != null) {
    wasmWriteVarUnsigned(array, fn.signatureIndex);
    fn = fn.next;
  }

  wasmFinishSection(array, section);
}

function wasmEmitMemory(array: ByteArray, module: WasmModule): void {
  var section = wasmStartSection(array, String_new("memory"));
  wasmWriteVarUnsigned(array, WASM_SIZE_IN_PAGES);
  wasmWriteVarUnsigned(array, WASM_SIZE_IN_PAGES);
  wasmWriteVarUnsigned(array, 1); // The memory array is exported
  wasmFinishSection(array, section);
}

function wasmEmitExportTable(array: ByteArray, module: WasmModule): void {
  var exportedCount = 0;
  var fn = module.firstFunction;
  while (fn != null) {
    if (fn.isExported) {
      exportedCount = exportedCount + 1;
    }
    fn = fn.next;
  }
  if (exportedCount == 0) {
    return;
  }

  var section = wasmStartSection(array, String_new("export_table"));
  wasmWriteVarUnsigned(array, exportedCount);

  var i = 0;
  fn = module.firstFunction;
  while (fn != null) {
    if (fn.isExported) {
      wasmWriteVarUnsigned(array, i);
      wasmWriteLengthPrefixedString(array, fn.name);
    }
    fn = fn.next;
    i = i + 1;
  }

  wasmFinishSection(array, section);
}

function emitBinaryExpression(array: ByteArray, node: Node, opcode: int): void {
  ByteArray_appendByte(array, opcode);
  wasmEmitNode(array, binaryLeft(node));
  wasmEmitNode(array, binaryRight(node));
}

function wasmEmitNode(array: ByteArray, node: Node): int {
  if (node.kind == NODE_BLOCK) {
    ByteArray_appendByte(array, WASM_OPCODE_BLOCK);
    var offset = ByteArray_length(array);
    wasmWriteVarUnsigned(array, ~0);
    var count = 0;
    var child = node.firstChild;
    while (child != null) {
      count = count + wasmEmitNode(array, child);
      child = child.nextSibling;
    }
    wasmPatchVarUnsigned(array, offset, count, ~0);
  }

  else if (node.kind == NODE_WHILE) {
    var value = whileValue(node);
    var body = whileBody(node);

    // Ignore "while (false) { ... }"
    if (value.kind == NODE_BOOL && value.intValue == 0) {
      return 0;
    }

    ByteArray_appendByte(array, WASM_OPCODE_LOOP);
    var offset = ByteArray_length(array);
    wasmWriteVarUnsigned(array, ~0);
    var count = 0;

    // Emit the condition as "loop { if (!condition) break; }" as long as it's not a "while (true)" loop
    if (value.kind != NODE_BOOL) {
      ByteArray_appendByte(array, WASM_OPCODE_BR_IF);
      wasmWriteVarUnsigned(array, 1); // Break out of the immediately enclosing loop
      ByteArray_appendByte(array, WASM_OPCODE_NOP); // This is a statement, not an expression
      ByteArray_appendByte(array, WASM_OPCODE_I32_EQZ); // The conditional is flipped
      wasmEmitNode(array, value);
      count = count + 1;
    }

    var child = body.firstChild;
    while (child != null) {
      count = count + wasmEmitNode(array, child);
      child = child.nextSibling;
    }

    // Jump back to the top (this doesn't happen automatically)
    ByteArray_appendByte(array, WASM_OPCODE_BR);
    wasmWriteVarUnsigned(array, 0); // Continue back to the immediately enclosing loop
    ByteArray_appendByte(array, WASM_OPCODE_NOP); // This is a statement, not an expression
    count = count + 1;

    wasmPatchVarUnsigned(array, offset, count, ~0);
  }

  else if (node.kind == NODE_BREAK || node.kind == NODE_CONTINUE) {
    var label = 0;
    var parent = node.parent;

    while (parent != null && parent.kind != NODE_WHILE) {
      if (parent.kind == NODE_BLOCK) {
        label = label + 1;
      }
      parent = parent.parent;
    }

    assert(label > 0);
    ByteArray_appendByte(array, WASM_OPCODE_BR);
    wasmWriteVarUnsigned(array, label - (node.kind == NODE_BREAK ? 0 : 1));
    ByteArray_appendByte(array, WASM_OPCODE_NOP); // This is a statement, not an expression
  }

  else if (node.kind == NODE_EMPTY) {
    return 0;
  }

  else if (node.kind == NODE_EXPRESSION) {
    wasmEmitNode(array, expressionValue(node));
  }

  else if (node.kind == NODE_RETURN) {
    var value = returnValue(node);
    ByteArray_appendByte(array, WASM_OPCODE_RETURN);
    if (value != null) {
      wasmEmitNode(array, value);
    }
  }

  else if (node.kind == NODE_VARIABLES) {
    var count = 0;
    var child = node.firstChild;
    while (child != null) {
      assert(child.kind == NODE_VARIABLE);
      count = count + wasmEmitNode(array, child);
      child = child.nextSibling;
    }
    return count;
  }

  else if (node.kind == NODE_IF) {
    var branch = ifFalse(node);
    ByteArray_appendByte(array, branch == null ? WASM_OPCODE_IF : WASM_OPCODE_IF_ELSE);
    wasmEmitNode(array, ifValue(node));
    wasmEmitNode(array, ifTrue(node));
    if (branch != null) {
      wasmEmitNode(array, branch);
    }
  }

  else if (node.kind == NODE_HOOK) {
    ByteArray_appendByte(array, WASM_OPCODE_IF_ELSE);
    wasmEmitNode(array, hookValue(node));
    wasmEmitNode(array, hookTrue(node));
    wasmEmitNode(array, hookFalse(node));
  }

  else if (node.kind == NODE_VARIABLE) {
    var value = variableValue(node);

    if (node.symbol.kind == VARIABLE_LOCAL) {
      ByteArray_appendByte(array, WASM_OPCODE_SET_LOCAL);
      wasmWriteVarUnsigned(array, node.symbol.offset);

      if (value != null) {
        wasmEmitNode(array, value);
      }

      // Default initialization
      else {
        ByteArray_appendByte(array, WASM_OPCODE_I32_CONST);
        wasmWriteVarSigned(array, 0);
      }
    }

    else {
      assert(false);
    }
  }

  else if (node.kind == NODE_NAME) {
    if (node.symbol.kind == VARIABLE_ARGUMENT || node.symbol.kind == VARIABLE_LOCAL) {
      ByteArray_appendByte(array, WASM_OPCODE_GET_LOCAL);
      wasmWriteVarUnsigned(array, node.symbol.offset);
    }

    else {
      assert(false);
    }
  }

  else if (node.kind == NODE_NULL) {
    ByteArray_appendByte(array, WASM_OPCODE_I32_CONST);
    wasmWriteVarSigned(array, 0);
  }

  else if (node.kind == NODE_INT || node.kind == NODE_BOOL) {
    ByteArray_appendByte(array, WASM_OPCODE_I32_CONST);
    wasmWriteVarSigned(array, node.intValue);
  }

  else if (node.kind == NODE_STRING) {
    ByteArray_appendByte(array, WASM_OPCODE_I32_CONST);
    wasmWriteVarSigned(array, node.intValue); // The string offset is stored in "intValue"
  }

  else if (node.kind == NODE_CALL) {
    var value = callValue(node);
    var symbol = value.symbol;
    assert(isFunction(symbol.kind));

    if (functionBody(symbol.node) == null) {
      ByteArray_appendByte(array, WASM_OPCODE_CALL_IMPORT);
      wasmWriteVarUnsigned(array, symbol.offset);
    }

    else {
      ByteArray_appendByte(array, WASM_OPCODE_CALL);
      wasmWriteVarUnsigned(array, symbol.offset);
    }

    var child = value.nextSibling;
    while (child != null) {
      wasmEmitNode(array, child);
      child = child.nextSibling;
    }
  }

  else if (node.kind == NODE_NEW) {
    var type = newType(node);
    assert(type.symbol.kind == TYPE_CLASS);

    ByteArray_appendByte(array, WASM_OPCODE_CALL_IMPORT);
    wasmWriteVarUnsigned(array, 0); // Invoke the "new" function

    // Pass the object size as the first argument
    ByteArray_appendByte(array, WASM_OPCODE_I32_CONST);
    wasmWriteVarSigned(array, type.symbol.offset);
  }

  else if (node.kind == NODE_POSITIVE) {
    wasmEmitNode(array, unaryValue(node));
  }

  else if (node.kind == NODE_NEGATIVE) {
    ByteArray_appendByte(array, WASM_OPCODE_I32_SUB);
    ByteArray_appendByte(array, WASM_OPCODE_I32_CONST);
    wasmWriteVarSigned(array, 0);
    wasmEmitNode(array, unaryValue(node));
  }

  else if (node.kind == NODE_COMPLEMENT) {
    ByteArray_appendByte(array, WASM_OPCODE_I32_XOR);
    ByteArray_appendByte(array, WASM_OPCODE_I32_CONST);
    wasmWriteVarSigned(array, ~0);
    wasmEmitNode(array, unaryValue(node));
  }

  else if (node.kind == NODE_NOT) {
    ByteArray_appendByte(array, WASM_OPCODE_I32_EQZ);
    wasmEmitNode(array, unaryValue(node));
  }

  else if (node.kind == NODE_DOT) {
    var symbol = node.symbol;

    if (symbol.kind == VARIABLE_INSTANCE) {
      ByteArray_appendByte(array, WASM_OPCODE_I32_LOAD);
      wasmWriteVarUnsigned(array, WASM_I32_LOAD_STORE_ALIGNMENT); // The alignment shift amount is 2 because 1 << 2 is 4, the size of an int
      wasmWriteVarUnsigned(array, symbol.offset);
      wasmEmitNode(array, dotTarget(node));
    }

    else {
      assert(false);
    }
  }

  else if (node.kind == NODE_ASSIGN) {
    var left = binaryLeft(node);
    var symbol = left.symbol;

    if (symbol.kind == VARIABLE_INSTANCE) {
      assert(left.kind == NODE_DOT);
      ByteArray_appendByte(array, WASM_OPCODE_I32_STORE);
      wasmWriteVarUnsigned(array, WASM_I32_LOAD_STORE_ALIGNMENT); // The alignment shift amount is 2 because 1 << 2 is 4, the size of an int
      wasmWriteVarUnsigned(array, symbol.offset);
      wasmEmitNode(array, dotTarget(left));
      wasmEmitNode(array, binaryRight(node));
    }

    else if (symbol.kind == VARIABLE_ARGUMENT || symbol.kind == VARIABLE_LOCAL) {
      ByteArray_appendByte(array, WASM_OPCODE_SET_LOCAL);
      wasmWriteVarUnsigned(array, symbol.offset);
      wasmEmitNode(array, binaryRight(node));
    }

    else {
      assert(false);
    }
  }

  else if (node.kind == NODE_ADD) emitBinaryExpression(array, node, WASM_OPCODE_I32_ADD);
  else if (node.kind == NODE_SUBTRACT) emitBinaryExpression(array, node, WASM_OPCODE_I32_SUB);
  else if (node.kind == NODE_MULTIPLY) emitBinaryExpression(array, node, WASM_OPCODE_I32_MUL);
  else if (node.kind == NODE_DIVIDE) emitBinaryExpression(array, node, WASM_OPCODE_I32_DIV_S);
  else if (node.kind == NODE_REMAINDER) emitBinaryExpression(array, node, WASM_OPCODE_I32_REM_S);
  else if (node.kind == NODE_SHIFT_LEFT) emitBinaryExpression(array, node, WASM_OPCODE_I32_SHL);
  else if (node.kind == NODE_SHIFT_RIGHT) emitBinaryExpression(array, node, WASM_OPCODE_I32_SHR_S);
  else if (node.kind == NODE_BITWISE_AND) emitBinaryExpression(array, node, WASM_OPCODE_I32_AND);
  else if (node.kind == NODE_BITWISE_OR) emitBinaryExpression(array, node, WASM_OPCODE_I32_OR);
  else if (node.kind == NODE_BITWISE_XOR) emitBinaryExpression(array, node, WASM_OPCODE_I32_XOR);
  else if (node.kind == NODE_EQUAL) emitBinaryExpression(array, node, WASM_OPCODE_I32_EQ);
  else if (node.kind == NODE_NOT_EQUAL) emitBinaryExpression(array, node, WASM_OPCODE_I32_NE);
  else if (node.kind == NODE_LESS_THAN) emitBinaryExpression(array, node, WASM_OPCODE_I32_LT_S);
  else if (node.kind == NODE_LESS_THAN_EQUAL) emitBinaryExpression(array, node, WASM_OPCODE_I32_LE_S);
  else if (node.kind == NODE_GREATER_THAN) emitBinaryExpression(array, node, WASM_OPCODE_I32_GT_S);
  else if (node.kind == NODE_GREATER_THAN_EQUAL) emitBinaryExpression(array, node, WASM_OPCODE_I32_GE_S);

  else if (node.kind == NODE_LOGICAL_AND) {
    ByteArray_appendByte(array, WASM_OPCODE_IF_ELSE);
    wasmEmitNode(array, binaryLeft(node));
    wasmEmitNode(array, binaryRight(node));
    ByteArray_appendByte(array, WASM_OPCODE_I32_CONST);
    wasmWriteVarSigned(array, 0);
  }

  else if (node.kind == NODE_LOGICAL_OR) {
    ByteArray_appendByte(array, WASM_OPCODE_IF_ELSE);
    wasmEmitNode(array, binaryLeft(node));
    ByteArray_appendByte(array, WASM_OPCODE_I32_CONST);
    wasmWriteVarSigned(array, 1);
    wasmEmitNode(array, binaryRight(node));
  }

  else {
    assert(false);
  }

  return 1;
}

function wasmEmitFunctionBodies(array: ByteArray, module: WasmModule): void {
  if (module.firstFunction == null) {
    return;
  }

  var section = wasmStartSection(array, String_new("function_bodies"));
  wasmWriteVarUnsigned(array, module.functionCount);

  var fn = module.firstFunction;
  while (fn != null) {
    var bodyLength = ByteArray_length(array);
    wasmWriteVarUnsigned(array, ~0); // This will be patched later

    if (fn.intLocalCount > 0) {
      wasmWriteVarUnsigned(array, 1);
      wasmWriteVarUnsigned(array, fn.intLocalCount);
      ByteArray_appendByte(array, WASM_TYPE_I32);
    } else {
      wasmWriteVarUnsigned(array, 0);
    }

    var child = fn.body.firstChild;
    while (child != null) {
      wasmEmitNode(array, child);
      child = child.nextSibling;
    }

    wasmPatchVarUnsigned(array, bodyLength, ByteArray_length(array) - bodyLength - 5, ~0);
    fn = fn.next;
  }

  wasmFinishSection(array, section);
}

function wasmEmitDataSegments(array: ByteArray, module: WasmModule): void {
  var section = wasmStartSection(array, String_new("data_segments"));
  wasmWriteVarUnsigned(array, 1);

  var memoryInitializer = module.memoryInitializer;
  var byteOffset = WASM_MEMORY_INITIALIZER_OFFSET;
  var byteCount = ByteArray_length(memoryInitializer);
  var initialHeapOffset = (byteOffset + byteCount + 7) & ~7;
  assert(byteCount >= 4);

  wasmWriteVarUnsigned(array, byteOffset);
  wasmWriteVarUnsigned(array, byteCount);

  // Pass the initial heap offset to the runtime
  ByteArray_setByte(memoryInitializer, 0, initialHeapOffset);
  ByteArray_setByte(memoryInitializer, 1, initialHeapOffset >> 8);
  ByteArray_setByte(memoryInitializer, 2, initialHeapOffset >> 16);
  ByteArray_setByte(memoryInitializer, 3, initialHeapOffset >> 24);

  // Put the string table next after that
  var i = 0;
  while (i < byteCount) {
    ByteArray_appendByte(array, ByteArray_getByte(memoryInitializer, i));
    i = i + 1;
  }

  wasmFinishSection(array, section);
}

function wasmEmitModule(array: ByteArray, module: WasmModule): void {
  ByteArray_appendByte(array, WASM_MAGIC);
  ByteArray_appendByte(array, WASM_MAGIC >> 8);
  ByteArray_appendByte(array, WASM_MAGIC >> 16);
  ByteArray_appendByte(array, WASM_MAGIC >> 24);

  ByteArray_appendByte(array, WASM_VERSION);
  ByteArray_appendByte(array, WASM_VERSION >> 8);
  ByteArray_appendByte(array, WASM_VERSION >> 16);
  ByteArray_appendByte(array, WASM_VERSION >> 24);

  wasmEmitSignatures(array, module);
  wasmEmitImportTable(array, module);
  wasmEmitFunctionSignatures(array, module);
  wasmEmitMemory(array, module);
  wasmEmitExportTable(array, module);
  wasmEmitFunctionBodies(array, module);
  wasmEmitDataSegments(array, module);
}

function wasmWrapType(id: int): WasmType {
  assert(id == WASM_TYPE_VOID || id == WASM_TYPE_I32);
  var type = new WasmType();
  type.id = id;
  return type;
}

function wasmGetType(context: CheckContext, type: Type): int {
  if (type == context.boolType || type == context.intType || typeIsReference(context, type)) {
    return WASM_TYPE_I32;
  }

  if (type == context.voidType) {
    return WASM_TYPE_VOID;
  }

  assert(false);
  return WASM_TYPE_VOID;
}

function wasmCollectStrings(module: WasmModule, node: Node): void {
  if (node.kind == NODE_STRING) {
    var memoryInitializer = module.memoryInitializer;
    node.intValue = WASM_MEMORY_INITIALIZER_OFFSET + ByteArray_length(memoryInitializer);
    var text = node.stringValue;
    var i = 0;
    var count = String_length(text);
    while (i < count) {
      ByteArray_appendByte(memoryInitializer, String_get(text, i));
      i = i + 1;
    }
    ByteArray_appendByte(memoryInitializer, 0);
  }

  var child = node.firstChild;
  while (child != null) {
    wasmCollectStrings(module, child);
    child = child.nextSibling;
  }
}

class WasmSharedOffset {
  nextLocalOffset: int;
  intLocalCount: int;
}

function wasmAssignLocalVariableOffsets(node: Node, shared: WasmSharedOffset): void {
  if (node.kind == NODE_VARIABLE) {
    assert(node.symbol.kind == VARIABLE_LOCAL);
    node.symbol.offset = shared.nextLocalOffset;
    shared.nextLocalOffset = shared.nextLocalOffset + 1;
    shared.intLocalCount = shared.intLocalCount + 1;
  }

  var child = node.firstChild;
  while (child != null) {
    wasmAssignLocalVariableOffsets(child, shared);
    child = child.nextSibling;
  }
}

function wasmEmit(global: Node, context: CheckContext, array: ByteArray): void {
  var module = new WasmModule();
  module.memoryInitializer = ByteArray_new();

  // Make room for the initial heap offset
  ByteArray_appendByte(module.memoryInitializer, 0);
  ByteArray_appendByte(module.memoryInitializer, 0);
  ByteArray_appendByte(module.memoryInitializer, 0);
  ByteArray_appendByte(module.memoryInitializer, 0);

  // The "malloc" equivalent is in the standard library
  var imports = String_new("imports");
  var signatureIndex = wasmAllocateSignature(module, wasmWrapType(WASM_TYPE_I32), wasmWrapType(WASM_TYPE_I32));
  wasmAllocateImport(module, signatureIndex, imports, String_new("new"));

  // Build the string table
  wasmCollectStrings(module, global);

  var child = global.firstChild;
  while (child != null) {
    if (child.kind == NODE_FUNCTION) {
      var returnType = functionReturnType(child);
      var shared = new WasmSharedOffset();
      var argumentTypesFirst: WasmType = null;
      var argumentTypesLast: WasmType = null;
      var argument = child.firstChild;
      while (argument != returnType) {
        var type = wasmWrapType(wasmGetType(context, variableType(argument).resolvedType));

        if (argumentTypesFirst == null) argumentTypesFirst = type;
        else argumentTypesLast.next = type;
        argumentTypesLast = type;

        shared.nextLocalOffset = shared.nextLocalOffset + 1;
        argument = argument.nextSibling;
      }
      signatureIndex = wasmAllocateSignature(module, argumentTypesFirst, wasmWrapType(wasmGetType(context, returnType.resolvedType)));
      var body = functionBody(child);

      // Functions without bodies are imports
      if (body == null) {
        child.symbol.offset = module.importCount;
        wasmAllocateImport(module, signatureIndex, imports, child.symbol.name);
        child = child.nextSibling;
        continue;
      }

      child.symbol.offset = module.functionCount;
      var fn = wasmAllocateFunction(module, child.symbol.name, signatureIndex, body);

      // Only export "extern" functions
      if (isExternSymbol(child.symbol)) {
        fn.isExported = true;
      }

      // Assign local variable offsets
      wasmAssignLocalVariableOffsets(body, shared);
      fn.intLocalCount = shared.intLocalCount;
    }
    child = child.nextSibling;
  }

  wasmEmitModule(array, module);
}
