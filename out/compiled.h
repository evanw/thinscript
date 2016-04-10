#include <stdint.h>

struct ByteArray;

enum {
  Color_DEFAULT = 0,
  Color_BOLD = 1,
  Color_RED = 2,
  Color_GREEN = 3,
  Color_MAGENTA = 4
};

const uint16_t *cstring_to_utf16(uint8_t *utf8);
uint8_t *utf16_to_cstring(const uint16_t *input);
int32_t ByteArray_length(struct ByteArray *__this);
uint8_t *ByteArray_bytes(struct ByteArray *__this);
void ByteArray_clear(struct ByteArray *__this);
uint8_t ByteArray_get(struct ByteArray *__this, int32_t index);
void ByteArray_set(struct ByteArray *__this, int32_t index, uint8_t value);
void ByteArray_append(struct ByteArray *__this, uint8_t value);
void ByteArray_resize(struct ByteArray *__this, int32_t length);
void assert(uint8_t truth);
void Profiler_begin();
void Profiler_end(const uint16_t *text);
void Terminal_setColor(int32_t color);
void Terminal_write(const uint16_t *text);
const uint16_t *IO_readTextFile(const uint16_t *path);
uint8_t IO_writeTextFile(const uint16_t *path, const uint16_t *contents);
uint8_t IO_writeBinaryFile(const uint16_t *path, struct ByteArray *contents);
void main_addArgument(const uint16_t *text);
void main_reset();
int32_t main_entry();
