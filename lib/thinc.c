#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum {
  COLOR_DEFAULT,
  COLOR_BOLD,
  COLOR_RED,
  COLOR_GREEN,
  COLOR_MAGENTA,
};

struct ByteArray {
  uint8_t *_data;
  uint32_t _length;
  uint32_t _capacity;
};

void main_addArgument(const uint16_t *text);
const uint16_t *main_newString(uint32_t length);
int32_t main_entry();

void Profiler_begin() {
}

void Profiler_end(const uint16_t *text) {
}

void assert(uint8_t truth) {
  if (!truth) {
    puts("Assertion failed");
    abort();
  }
}

static const uint16_t *cstring_to_utf16(const char *utf8) {
  uint32_t utf8_length = strlen(utf8);
  uint32_t utf16_length = 0;

  // Measure text
  for (uint32_t i = 0; i < utf8_length; i++) {
    uint32_t codePoint;

    // Decode UTF-8
    uint8_t a = utf8[i];
    if (i + 1 < utf8_length && a >= 0xC0) {
      uint8_t b = utf8[++i];
      if (i + 1 < utf8_length && a >= 0xE0) {
        uint8_t c = utf8[++i];
        if (i + 1 < utf8_length && a >= 0xF0) {
          uint8_t d = utf8[++i];
          codePoint = ((a & 0x07) << 18) | ((b & 0x3F) << 12) | ((c & 0x3F) << 6) | (d & 0x3F);
        } else {
          codePoint = ((a & 0x0F) << 12) | ((b & 0x3F) << 6) | (c & 0x3F);
        }
      } else {
        codePoint = ((a & 0x1F) << 6) | (b & 0x3F);
      }
    } else {
      codePoint = a;
    }

    // Encode UTF-16
    utf16_length += codePoint < 0x10000 ? 1 : 2;
  }

  uint16_t *output = (uint16_t *)main_newString(utf16_length);
  uint16_t *utf16 = output + 2;

  // Convert text
  for (uint32_t i = 0; i < utf8_length; i++) {
    uint32_t codePoint;

    // Decode UTF-8
    uint8_t a = utf8[i];
    if (i + 1 < utf8_length && a >= 0xC0) {
      uint8_t b = utf8[++i];
      if (i + 1 < utf8_length && a >= 0xE0) {
        uint8_t c = utf8[++i];
        if (i + 1 < utf8_length && a >= 0xF0) {
          uint8_t d = utf8[++i];
          codePoint = ((a & 0x07) << 18) | ((b & 0x3F) << 12) | ((c & 0x3F) << 6) | (d & 0x3F);
        } else {
          codePoint = ((a & 0x0F) << 12) | ((b & 0x3F) << 6) | (c & 0x3F);
        }
      } else {
        codePoint = ((a & 0x1F) << 6) | (b & 0x3F);
      }
    } else {
      codePoint = a;
    }

    // Encode UTF-16
    if (codePoint < 0x10000) {
      *utf16++ = codePoint;
    } else {
      *utf16++ = (codePoint >> 10) + (0xD800 - (0x10000 >> 10));
      *utf16++ = (codePoint & 0x3FF) + 0xDC00;
    }
  }

  assert(utf16 == output + 2 + utf16_length);
  return output;
}

static const char *utf16_to_cstring(const uint16_t *input) {
  uint32_t utf16_length = *(uint32_t *)input;
  uint32_t utf8_length = 0;
  const uint16_t *utf16 = input + 2;

  // Measure text
  for (uint32_t i = 0; i < utf16_length; i++) {
    uint32_t codePoint;

    // Decode UTF-16
    uint16_t a = utf16[i];
    if (i + 1 < utf16_length && a >= 0xD800 && a <= 0xDBFF) {
      uint16_t b = utf16[++i];
      codePoint = (a << 10) + b + (0x10000 - (0xD800 << 10) - 0xDC00);
    } else {
      codePoint = a;
    }

    // Encode UTF-8
    utf8_length +=
      codePoint < 0x80 ? 1 :
      codePoint < 0x800 ? 2 :
      codePoint < 0x10000 ? 3 :
      4;
  }

  char *utf8 = malloc((utf8_length + 1) * sizeof(char));
  char *next = utf8;

  // Convert text
  for (uint32_t i = 0; i < utf16_length; i++) {
    uint32_t codePoint;

    // Decode UTF-16
    uint16_t a = utf16[i];
    if (i + 1 < utf16_length && a >= 0xD800 && a <= 0xDBFF) {
      uint16_t b = utf16[++i];
      codePoint = (a << 10) + b + (0x10000 - (0xD800 << 10) - 0xDC00);
    } else {
      codePoint = a;
    }

    // Encode UTF-8
    if (codePoint < 0x80) {
      *next++ = codePoint;
    } else {
      if (codePoint < 0x800) {
        *next++ = ((codePoint >> 6) & 0x1F) | 0xC0;
      } else {
        if (codePoint < 0x10000) {
          *next++ = ((codePoint >> 12) & 0x0F) | 0xE0;
        } else {
          *next++ = ((codePoint >> 18) & 0x07) | 0xF0;
          *next++ = ((codePoint >> 12) & 0x3F) | 0x80;
        }
        *next++ = ((codePoint >> 6) & 0x3F) | 0x80;
      }
      *next++ += (codePoint & 0x3F) | 0x80;
    }
  }

  // C strings are null-terminated
  *next++ = '\0';

  assert(next == utf8 + utf8_length + 1);
  return utf8;
}

void Terminal_setColor(int32_t color) {
  if (isatty(STDOUT_FILENO)) {
    printf("\x1B[0;%dm",
      color == COLOR_BOLD ? 1 :
      color == COLOR_RED ? 91 :
      color == COLOR_GREEN ? 92 :
      color == COLOR_MAGENTA ? 95 :
      0);
  }
}

void Terminal_write(const uint16_t *text) {
  printf("%s", utf16_to_cstring(text));
}

const uint16_t *IO_readTextFile(const uint16_t *path) {
  FILE *f = fopen(utf16_to_cstring(path), "r");
  if (f == NULL) return NULL;
  fseek(f, 0, SEEK_END);
  size_t length = ftell(f);
  fseek(f, 0, SEEK_SET);
  char *text = calloc(1, length + 1);
  if (fread(text, sizeof(char), length, f) < length) {
    fclose(f);
    return NULL;
  }
  fclose(f);
  return cstring_to_utf16(text);
}

uint8_t IO_writeTextFile(const uint16_t *path, const uint16_t *contents) {
  FILE *f = fopen(utf16_to_cstring(path), "w");
  if (f == NULL) return 0;
  const char *text = utf16_to_cstring(contents);
  size_t length = strlen(text);
  if (fwrite(text, sizeof(char), length, f) < length) {
    fclose(f);
    return 0;
  }
  fclose(f);
  return 1;
}

uint8_t IO_writeBinaryFile(const uint16_t *path, struct ByteArray *contents) {
  FILE *f = fopen(utf16_to_cstring(path), "wb");
  if (f == NULL) return 0;
  if (fwrite(contents->_data, sizeof(uint8_t), contents->_length, f) < contents->_length) {
    fclose(f);
    return 0;
  }
  fclose(f);
  return 1;
}

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "en_US.UTF-8");
  for (int i = 1; i < argc; i++) {
    main_addArgument(cstring_to_utf16(argv[i]));
  }
  return main_entry();
}
