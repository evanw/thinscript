#include "../out/compiled.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
  #include <windows.h>

  static HANDLE handle = INVALID_HANDLE_VALUE;
  static CONSOLE_SCREEN_BUFFER_INFO info;
#else
  #include <unistd.h>
#endif

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

void Terminal_setColor(int32_t color) {
  #ifdef _WIN32
    SetConsoleTextAttribute(handle,
      color == Color_BOLD ? info.wAttributes | FOREGROUND_INTENSITY :
      color == Color_RED ? FOREGROUND_RED | FOREGROUND_INTENSITY :
      color == Color_GREEN ? FOREGROUND_GREEN | FOREGROUND_INTENSITY :
      color == Color_MAGENTA ? FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY :
      info.wAttributes);
  #else
    if (isatty(STDOUT_FILENO)) {
      printf("\x1B[0;%dm",
        color == Color_BOLD ? 1 :
        color == Color_RED ? 91 :
        color == Color_GREEN ? 92 :
        color == Color_MAGENTA ? 95 :
        0);
    }
  #endif
}

void Terminal_write(const uint16_t *text) {
  #ifdef _WIN32
    WriteConsoleW(handle, text + 2, *(uint32_t *)text, NULL, NULL);
  #else
    printf("%s", (const char *)utf16_to_cstring(text));
  #endif
}

const uint16_t *IO_readTextFile(const uint16_t *path) {
  FILE *f = fopen((const char *)utf16_to_cstring(path), "r");
  if (f == NULL) return NULL;
  fseek(f, 0, SEEK_END);
  long lengthIncludingCarriageReturns = ftell(f);
  fseek(f, 0, SEEK_SET);
  char *text = malloc(lengthIncludingCarriageReturns + 1);

  // Ignore the return value of fread() and check ftell() instead because
  // on Windows, ftell() treats newlines as "\r\n" while fread() treats them
  // as "\n". This means the counts aren't comparable and will cause errors.
  size_t lengthExcludingCarriageReturns = fread(text, sizeof(char), lengthIncludingCarriageReturns, f);

  if (ftell(f) < lengthIncludingCarriageReturns) {
    fclose(f);
    return NULL;
  }

  // Make sure to end the text at the end of the translated character stream
  text[lengthExcludingCarriageReturns] = '\0';

  fclose(f);
  return cstring_to_utf16((uint8_t *)text);
}

uint8_t IO_writeTextFile(const uint16_t *path, const uint16_t *contents) {
  FILE *f = fopen((const char *)utf16_to_cstring(path), "w");
  if (f == NULL) return 0;
  const char *text = (const char *)utf16_to_cstring(contents);
  size_t length = strlen(text);
  if (fwrite(text, sizeof(char), length, f) < length) {
    fclose(f);
    return 0;
  }
  fclose(f);
  return 1;
}

uint8_t IO_writeBinaryFile(const uint16_t *path, struct ByteArray *contents) {
  FILE *f = fopen((const char *)utf16_to_cstring(path), "wb");
  if (f == NULL) return 0;
  size_t length = ByteArray_length(contents);
  if (fwrite(ByteArray_bytes(contents), sizeof(uint8_t), length, f) < length) {
    fclose(f);
    return 0;
  }
  fclose(f);
  return 1;
}

int main(int argc, char *argv[]) {
  #ifdef _WIN32
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle, &info);
  #endif

  setlocale(LC_ALL, "en_US.UTF-8");

  for (int i = 1; i < argc; i++) {
    main_addArgument(cstring_to_utf16((uint8_t *)argv[i]));
  }

  return main_entry();
}
