class CompileResult {
  log: Log;
  global: Node;
  context: CheckContext;
  wasm: ByteArray;
  js: String;
}

extern function CompileResult_new(): CompileResult {
  var result = new CompileResult();
  result.log = new Log();
  result.global = new Node();
  result.global.kind = NODE_GLOBAL;
  return result;
}

extern function CompileResult_addInput(result: CompileResult, name: String, contents: String): void {
  var source = new Source();
  source.name = name;
  source.contents = contents;

  var token = tokenize(source, result.log);

  if (token != null) {
    var file = parse(token, result.log);

    if (file != null) {
      while (file.firstChild != null) {
        var child = file.firstChild;
        child.remove();
        result.global.appendChild(child);
      }
    }
  }
}

extern function CompileResult_finish(result: CompileResult): void {
  if (result.log.first == null) {
    result.context = check(result.global, result.log);

    if (result.log.first == null) {
      result.wasm = ByteArray_new();
      wasmEmit(result.global, result.context, result.wasm);

      result.js = jsEmit(result.global, result.context);
    }
  }
}

extern function CompileResult_wasm(result: CompileResult): ByteArray {
  return result.wasm;
}

extern function CompileResult_js(result: CompileResult): String {
  return result.js;
}

extern function CompileResult_log(result: CompileResult): String {
  return result.log.toString();
}
