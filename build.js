var fs = require('fs');

eval(fs.readFileSync('./www/common.js', 'utf8'));

// Always build all targets to catch errors in other targets
function compile(compiler, sources) {
  var compiled = compileJavaScript(compiler);

  var compilerJS = compiled(sources, CompileTarget.JAVASCRIPT, ['TERMINAL']);
  if (compilerJS.log) process.stdout.write(compilerJS.log);
  if (!compilerJS.success) process.exit(1);

  var compilerWASM = compiled(sources, CompileTarget.WEBASSEMBLY);
  if (compilerWASM.log) process.stdout.write(compilerWASM.log);
  if (!compilerWASM.success) process.exit(1);

  return {
    wasm: compilerWASM.wasm,
    js: compilerJS.js,
  };
}

var sourceDir = __dirname + '/src';
var sources = [];

fs.readdirSync(sourceDir).forEach(function(entry) {
  if (/\.thin$/.test(entry)) {
    sources.push({
      name: entry,
      contents: fs.readFileSync(sourceDir + '/' + entry, 'utf8'),
    });
  }
});

var compiler = fs.readFileSync(__dirname + '/www/compiled.js', 'utf8');

console.log('compiling...');
var compiler = compile(compiler, sources);

console.log('compiling again...');
var compiler = compile(compiler.js, sources);

console.log('compiling again...');
var compiler = compile(compiler.js, sources);

fs.writeFileSync(__dirname + '/www/compiled.wasm', Buffer(compiler.wasm));
console.log('wrote to "www/compiled.wasm"');

fs.writeFileSync(__dirname + '/www/compiled.js', compiler.js);
console.log('wrote to "www/compiled.js"');
