class CompileResult {
  log: Log;
  token: Token;
  global: Node;
  context: CheckContext;
  wasm: ByteArray;
  js: String;
}

extern function main(text: String): CompileResult {
  var source = new Source();
  source.name = String_new("<stdin>");
  source.contents = text;

  var result = new CompileResult();
  result.log = new Log();
  result.token = tokenize(source, result.log);

  if (result.token != null) {
    result.global = parse(result.token, result.log);

    if (result.global != null) {
      result.context = check(result.global, result.log);

      if (result.log.first == null) {
        result.wasm = ByteArray_new();
        wasmEmit(result.global, result.context, result.wasm);

        result.js = jsEmit(result.global, result.context);
      }
    }
  }

  return result;
}

extern function CompileResult_wasm(result: CompileResult): ByteArray {
  return result.wasm;
}

extern function CompileResult_js(result: CompileResult): String {
  return result.js;
}

extern function CompileResult_log(result: CompileResult): String {
  return logToString(result.log);
}
