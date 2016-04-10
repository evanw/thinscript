# ThinScript

ThinScript is an experimental programming language that compiles to JavaScript, WebAssembly, and C.
It's meant to be a thin layer on top of WebAssembly that makes it easier to work with: no dependencies and fast compile times.
The syntax is inspired by TypeScript and the compiler is open source and bootstrapped (it can compile itself).

This is still an experiment and isn't intended for real use yet.
The biggest issue is that the generated code currently doesn't delete anything (garbage collection is planned but not yet implemented).
Also the WebAssembly specification is still being developed and the current binary format will stop working when WebAssembly is officially released.

## Demo

An interactive compiler demo is available online at http://evanw.github.io/thinscript/.
Here's some example code to demonstrate the language (documentation will be written at some point):

```TypeScript
declare function print(text: string): void;

class Link {
  value: int;
  next: Link;
}

class List {
  first: Link;
  last: Link;

  append(value: int): void {
    var link = new Link();
    link.value = value;

    // Append the new link to the end of the chain
    if (this.first == null) this.first = link;
    else this.last.next = link;
    this.last = link;
  }
}

extern function main(): int {
  var list = new List();
  list.append(1);
  list.append(2);
  list.append(3);

  var total = 0;
  var link = list.first;
  while (link != null) {
    total = total + link.value;
    link = link.next;
  }

  #if JS
    print("Hello from JavaScript");
  #elif WASM
    print("Hello from WebAssembly");
  #elif C
    print("Hello from C");
  #else
    print("Unknown target");
  #endif

  return total;
}
```

# Building

Run `node build.js` to build the compiler using itself.
This generates updated versions of `out/compiled.js`, `out/compiled.wasm`, and `out/compiled.c`.
If you have a C compiler installed, this also builds a native version of the compiler by compiling `out/compiled.c` and `lib/thinc.c` together into the `out/thinc` binary.
