function assert(truth: bool): void;

// An external string handle for now
class String {}

function String_new(text: string): String;
function String_length(self: String): int;
function String_get(self: String, index: int): int;
function String_append(self: String, other: String): String;
function String_appendNew(self: String, other: string): String;
function String_equal(self: String, other: String): bool;
function String_equalNew(self: String, other: string): bool;
function String_slice(self: String, start: int, end: int): String;
function String_toString(value: int): String;
function String_quote(self: String): String;

// This is an external handle for now
class ByteArray {}

function ByteArray_new(): ByteArray;
function ByteArray_length(self: ByteArray): int;
function ByteArray_getByte(self: ByteArray, index: int): int;
function ByteArray_setByte(self: ByteArray, index: int, byte: int): void;
function ByteArray_appendByte(self: ByteArray, byte: int): void;

class Source {
  name: String;
  contents: String;
}

class Range {
  source: Source;
  start: int;
  end: int;

  toString(): String {
    return String_slice(this.source.contents, this.start, this.end);
  }

  enclosingLine(): Range {
    var contents = this.source.contents;
    var start = this.start;
    var end = this.start;

    while (start > 0 && String_get(contents, start - 1) != '\n') {
      start = start - 1;
    }

    while (end + 1 < String_length(contents) && String_get(contents, end) != '\n') {
      end = end + 1;
    }

    return createRange(this.source, start, end);
  }
}

class Diagnostic {
  range: Range;
  message: String;
  next: Diagnostic;
}

class Log {
  first: Diagnostic;
  last: Diagnostic;

  error(range: Range, message: String): void {
    var diagnostic = new Diagnostic();
    diagnostic.range = range;
    diagnostic.message = message;
    this.append(diagnostic);
  }

  append(diagnostic: Diagnostic): void {
    if (this.first == null) this.first = diagnostic;
    else this.last.next = diagnostic;
    this.last = diagnostic;
  }

  toString(): String {
    var result = String_new("");
    var d = this.first;

    while (d != null) {
      var lineRange = d.range.enclosingLine();
      var column = d.range.start - lineRange.start;
      var line = 0;

      var i = 0;
      while (i < lineRange.start) {
        if (String_get(lineRange.source.contents, i) == '\n') {
          line = line + 1;
        }
        i = i + 1;
      }

      result = String_append(result, d.range.source.name);
      result = String_appendNew(result, ":");
      result = String_append(result, String_toString(line + 1));
      result = String_appendNew(result, ":");
      result = String_append(result, String_toString(column + 1));
      result = String_appendNew(result, ": error: ");
      result = String_append(result, d.message);
      result = String_appendNew(result, "\n");
      result = String_append(result, lineRange.toString());
      result = String_appendNew(result, "\n");

      i = 0;
      while (i < column) {
        result = String_appendNew(result, " ");
        i = i + 1;
      }

      if (d.range.end - d.range.start <= 1) {
        result = String_appendNew(result, "^");
      } else {
        i = d.range.start;
        while (i < d.range.end && i < lineRange.end) {
          result = String_appendNew(result, "~");
          i = i + 1;
        }
      }

      result = String_appendNew(result, "\n");
      d = d.next;
    }

    return result;
  }
}

function createRange(source: Source, start: int, end: int): Range {
  assert(start <= end);
  var range = new Range();
  range.source = source;
  range.start = start;
  range.end = end;
  return range;
}

function spanRanges(left: Range, right: Range): Range {
  assert(left.source == right.source);
  assert(left.end <= right.start);
  return createRange(left.source, left.start, right.end);
}
