function main(text: String): void {
  var source = new Source();
  source.name = String_new("<stdin>");
  source.contents = text;

  var log = new Log();
  var token = tokenize(source, log);

  if (token != null) {
    var global = parse(token, log);

    if (global != null) {
      var context = check(global, log);

      if (log.first == null) {
        var array = ByteArray_new();
        wasmEmit(global, context, array);
      }
    }
  }

  IO_print(logToString(log));
}
