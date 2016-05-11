#include "compiled.h"
#include <stdlib.h>
#include <string.h>

#ifdef THINSCRIPT_BIG_ENDIAN
  #define S(a, b) (((a) << 16) | (b))
#else
  #define S(a, b) ((a) | ((b) << 16))
#endif

static const uint32_t __string_0_2147483648[] = {11, S('-', '2'), S('1', '4'), S('7', '4'), S('8', '3'), S('6', '4'), S('8', 0)};
static const uint32_t __string_1_0[] = {1, S('0', 0)};
static const uint32_t __string_2_1[] = {2, S('-', '1')};
static const uint32_t __string_3_1[] = {1, S('1', 0)};
static const uint32_t __string_4[] = {2, S(' ', ' ')};
static const uint32_t __string_5[] = {2, S('{', '\n')};
static const uint32_t __string_6[] = {2, S(',', ' ')};
static const uint32_t __string_7_NULL[] = {4, S('N', 'U'), S('L', 'L')};
static const uint32_t __string_8___string_[] = {9, S('_', '_'), S('s', 't'), S('r', 'i'), S('n', 'g'), S('_', 0)};
static const uint32_t __string_9_ifdef_THINSCRIPT_BIG_ENDIAN[] = {120, S('\n', '#'), S('i', 'f'), S('d', 'e'), S('f', ' '), S('T', 'H'), S('I', 'N'), S('S', 'C'), S('R', 'I'), S('P', 'T'), S('_', 'B'), S('I',
  'G'), S('_', 'E'), S('N', 'D'), S('I', 'A'), S('N', '\n'), S(' ', ' '), S('#', 'd'), S('e', 'f'), S('i', 'n'), S('e', ' '), S('S', '('), S('a', ','), S(' ', 'b'), S(')', ' '), S('(', '('), S('(', 'a'), S(')',
  ' '), S('<', '<'), S(' ', '1'), S('6', ')'), S(' ', '|'), S(' ', '('), S('b', ')'), S(')', '\n'), S('#', 'e'), S('l', 's'), S('e', '\n'), S(' ', ' '), S('#', 'd'), S('e', 'f'), S('i', 'n'), S('e', ' '), S('S',
  '('), S('a', ','), S(' ', 'b'), S(')', ' '), S('(', '('), S('a', ')'), S(' ', '|'), S(' ', '('), S('(', 'b'), S(')', ' '), S('<', '<'), S(' ', '1'), S('6', ')'), S(')', '\n'), S('#', 'e'), S('n', 'd'), S('i',
  'f'), S('\n', '\n')};
static const uint32_t __string_10_static_const_uint32_t[] = {22, S('s', 't'), S('a', 't'), S('i', 'c'), S(' ', 'c'), S('o', 'n'), S('s', 't'), S(' ', 'u'), S('i', 'n'), S('t', '3'), S('2', '_'), S('t',
  ' ')};
static const uint32_t __string_11[] = {6, S('[', ']'), S(' ', '='), S(' ', '{')};
static const uint32_t __string_12_S[] = {4, S(',', ' '), S('S', '(')};
static const uint32_t __string_13[] = {4, S(',', '\n'), S(' ', ' ')};
static const uint32_t __string_14[] = {2, S(',', ' ')};
static const uint32_t __string_15_0[] = {4, S(',', ' '), S('0', ')')};
static const uint32_t __string_16[] = {3, S('}', ';'), S('\n', 0)};
static const uint32_t __string_17_const_uint16_t[] = {18, S('(', 'c'), S('o', 'n'), S('s', 't'), S(' ', 'u'), S('i', 'n'), S('t', '1'), S('6', '_'), S('t', ' '), S('*', ')')};
static const uint32_t __string_18[] = {2, S('-', '>')};
static const uint32_t __string_19[] = {1, S('.', 0)};
static const uint32_t __string_20[] = {3, S(' ', '?'), S(' ', 0)};
static const uint32_t __string_21[] = {3, S(' ', ':'), S(' ', 0)};
static const uint32_t __string_22[] = {2, S(',', ' ')};
static const uint32_t __string_23_calloc_1_sizeof[] = {17, S('c', 'a'), S('l', 'l'), S('o', 'c'), S('(', '1'), S(',', ' '), S('s', 'i'), S('z', 'e'), S('o', 'f'), S('(', 0)};
static const uint32_t __string_24[] = {2, S(')', ')')};
static const uint32_t __string_25[] = {1, S('~', 0)};
static const uint32_t __string_26[] = {1, S('*', 0)};
static const uint32_t __string_27[] = {1, S('-', 0)};
static const uint32_t __string_28[] = {1, S('!', 0)};
static const uint32_t __string_29[] = {1, S('+', 0)};
static const uint32_t __string_30[] = {2, S('-', '-')};
static const uint32_t __string_31[] = {2, S('+', '+')};
static const uint32_t __string_32[] = {2, S('-', '-')};
static const uint32_t __string_33[] = {2, S('+', '+')};
static const uint32_t __string_34[] = {3, S(' ', '+'), S(' ', 0)};
static const uint32_t __string_35[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_36[] = {3, S(' ', '&'), S(' ', 0)};
static const uint32_t __string_37[] = {3, S(' ', '|'), S(' ', 0)};
static const uint32_t __string_38[] = {3, S(' ', '^'), S(' ', 0)};
static const uint32_t __string_39[] = {3, S(' ', '/'), S(' ', 0)};
static const uint32_t __string_40[] = {4, S(' ', '='), S('=', ' ')};
static const uint32_t __string_41[] = {3, S(' ', '>'), S(' ', 0)};
static const uint32_t __string_42[] = {4, S(' ', '>'), S('=', ' ')};
static const uint32_t __string_43[] = {3, S(' ', '<'), S(' ', 0)};
static const uint32_t __string_44[] = {4, S(' ', '<'), S('=', ' ')};
static const uint32_t __string_45[] = {4, S(' ', '&'), S('&', ' ')};
static const uint32_t __string_46[] = {4, S(' ', '|'), S('|', ' ')};
static const uint32_t __string_47[] = {3, S(' ', '*'), S(' ', 0)};
static const uint32_t __string_48[] = {4, S(' ', '!'), S('=', ' ')};
static const uint32_t __string_49[] = {3, S(' ', '%'), S(' ', 0)};
static const uint32_t __string_50[] = {4, S(' ', '<'), S('<', ' ')};
static const uint32_t __string_51[] = {4, S(' ', '>'), S('>', ' ')};
static const uint32_t __string_52[] = {3, S(' ', '-'), S(' ', 0)};
static const uint32_t __string_53_struct[] = {7, S('s', 't'), S('r', 'u'), S('c', 't'), S(' ', 0)};
static const uint32_t __string_54_uint8_t[] = {7, S('u', 'i'), S('n', 't'), S('8', '_'), S('t', 0)};
static const uint32_t __string_55_int8_t[] = {6, S('i', 'n'), S('t', '8'), S('_', 't')};
static const uint32_t __string_56_int32_t[] = {7, S('i', 'n'), S('t', '3'), S('2', '_'), S('t', 0)};
static const uint32_t __string_57_int16_t[] = {7, S('i', 'n'), S('t', '1'), S('6', '_'), S('t', 0)};
static const uint32_t __string_58_const_uint16_t[] = {14, S('c', 'o'), S('n', 's'), S('t', ' '), S('u', 'i'), S('n', 't'), S('1', '6'), S('_', 't')};
static const uint32_t __string_59_uint32_t[] = {8, S('u', 'i'), S('n', 't'), S('3', '2'), S('_', 't')};
static const uint32_t __string_60_uint16_t[] = {8, S('u', 'i'), S('n', 't'), S('1', '6'), S('_', 't')};
static const uint32_t __string_61[] = {2, S(' ', '*')};
static const uint32_t __string_62_if[] = {4, S('i', 'f'), S(' ', '(')};
static const uint32_t __string_63[] = {2, S(')', ' ')};
static const uint32_t __string_64[] = {2, S('\n', '\n')};
static const uint32_t __string_65_else[] = {5, S('e', 'l'), S('s', 'e'), S(' ', 0)};
static const uint32_t __string_66_while[] = {7, S('w', 'h'), S('i', 'l'), S('e', ' '), S('(', 0)};
static const uint32_t __string_67[] = {2, S(')', ' ')};
static const uint32_t __string_68_break[] = {7, S('b', 'r'), S('e', 'a'), S('k', ';'), S('\n', 0)};
static const uint32_t __string_69_continue[] = {10, S('c', 'o'), S('n', 't'), S('i', 'n'), S('u', 'e'), S(';', '\n')};
static const uint32_t __string_70[] = {2, S(';', '\n')};
static const uint32_t __string_71_return[] = {7, S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 0)};
static const uint32_t __string_72[] = {2, S(';', '\n')};
static const uint32_t __string_73_return[] = {8, S('r', 'e'), S('t', 'u'), S('r', 'n'), S(';', '\n')};
static const uint32_t __string_74[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_75[] = {2, S(';', '\n')};
static const uint32_t __string_76_include_stdint_h[] = {20, S('#', 'i'), S('n', 'c'), S('l', 'u'), S('d', 'e'), S(' ', '<'), S('s', 't'), S('d', 'i'), S('n', 't'), S('.', 'h'), S('>', '\n')};
static const uint32_t __string_77_include[] = {10, S('#', 'i'), S('n', 'c'), S('l', 'u'), S('d', 'e'), S(' ', '"')};
static const uint32_t __string_78[] = {2, S('"', '\n')};
static const uint32_t __string_79_include_stdlib_h[] = {20, S('#', 'i'), S('n', 'c'), S('l', 'u'), S('d', 'e'), S(' ', '<'), S('s', 't'), S('d', 'l'), S('i', 'b'), S('.', 'h'), S('>', '\n')};
static const uint32_t __string_80_include_string_h[] = {20, S('#', 'i'), S('n', 'c'), S('l', 'u'), S('d', 'e'), S(' ', '<'), S('s', 't'), S('r', 'i'), S('n', 'g'), S('.', 'h'), S('>', '\n')};
static const uint32_t __string_81_struct[] = {7, S('s', 't'), S('r', 'u'), S('c', 't'), S(' ', 0)};
static const uint32_t __string_82[] = {2, S(';', '\n')};
static const uint32_t __string_83_struct[] = {7, S('s', 't'), S('r', 'u'), S('c', 't'), S(' ', 0)};
static const uint32_t __string_84[] = {3, S(' ', '{'), S('\n', 0)};
static const uint32_t __string_85[] = {2, S(';', '\n')};
static const uint32_t __string_86[] = {3, S('}', ';'), S('\n', 0)};
static const uint32_t __string_87_enum[] = {7, S('e', 'n'), S('u', 'm'), S(' ', '{'), S('\n', 0)};
static const uint32_t __string_88__[] = {1, S('_', 0)};
static const uint32_t __string_89[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_90[] = {2, S(',', '\n')};
static const uint32_t __string_91[] = {1, S('\n', 0)};
static const uint32_t __string_92[] = {3, S('}', ';'), S('\n', 0)};
static const uint32_t __string_93_malloc[] = {6, S('m', 'a'), S('l', 'l'), S('o', 'c')};
static const uint32_t __string_94_memcpy[] = {6, S('m', 'e'), S('m', 'c'), S('p', 'y')};
static const uint32_t __string_95_memcmp[] = {6, S('m', 'e'), S('m', 'c'), S('m', 'p')};
static const uint32_t __string_96_static[] = {7, S('s', 't'), S('a', 't'), S('i', 'c'), S(' ', 0)};
static const uint32_t __string_97___this[] = {6, S('_', '_'), S('t', 'h'), S('i', 's')};
static const uint32_t __string_98[] = {2, S(',', ' ')};
static const uint32_t __string_99[] = {3, S(')', ';'), S('\n', 0)};
static const uint32_t __string_100_static[] = {7, S('s', 't'), S('a', 't'), S('i', 'c'), S(' ', 0)};
static const uint32_t __string_101[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_102[] = {2, S(';', '\n')};
static const uint32_t __string_103_static[] = {7, S('s', 't'), S('a', 't'), S('i', 'c'), S(' ', 0)};
static const uint32_t __string_104[] = {2, S(',', ' ')};
static const uint32_t __string_105[] = {2, S(')', ' ')};
static const uint32_t __string_106_undef_S[] = {10, S('\n', '#'), S('u', 'n'), S('d', 'e'), S('f', ' '), S('S', '\n')};
static const uint32_t __string_107_0[] = {4, S('\'', '\\'), S('0', '\'')};
static const uint32_t __string_108_r[] = {4, S('\'', '\\'), S('r', '\'')};
static const uint32_t __string_109_n[] = {4, S('\'', '\\'), S('n', '\'')};
static const uint32_t __string_110_t[] = {4, S('\'', '\\'), S('t', '\'')};
static const uint32_t __string_111_h[] = {2, S('.', 'h')};
static const uint32_t __string_112_This_statement_is_not_allowed_he[] = {34, S('T', 'h'), S('i', 's'), S(' ', 's'), S('t', 'a'), S('t', 'e'), S('m', 'e'), S('n', 't'), S(' ', 'i'), S('s', ' '), S('n', 'o'), S('t',
  ' '), S('a', 'l'), S('l', 'o'), S('w', 'e'), S('d', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_113[] = {1, S('+', 0)};
static const uint32_t __string_114[] = {1, S('-', 0)};
static const uint32_t __string_115[] = {1, S('+', 0)};
static const uint32_t __string_116_op_positive[] = {11, S('o', 'p'), S('_', 'p'), S('o', 's'), S('i', 't'), S('i', 'v'), S('e', 0)};
static const uint32_t __string_117_op_negative[] = {11, S('o', 'p'), S('_', 'n'), S('e', 'g'), S('a', 't'), S('i', 'v'), S('e', 0)};
static const uint32_t __string_118[] = {1, S('+', 0)};
static const uint32_t __string_119_op_add[] = {6, S('o', 'p'), S('_', 'a'), S('d', 'd')};
static const uint32_t __string_120_op_subtract[] = {11, S('o', 'p'), S('_', 's'), S('u', 'b'), S('t', 'r'), S('a', 'c'), S('t', 0)};
static const uint32_t __string_121[] = {1, S('%', 0)};
static const uint32_t __string_122_op_remainder[] = {12, S('o', 'p'), S('_', 'r'), S('e', 'm'), S('a', 'i'), S('n', 'd'), S('e', 'r')};
static const uint32_t __string_123[] = {1, S('&', 0)};
static const uint32_t __string_124_op_and[] = {6, S('o', 'p'), S('_', 'a'), S('n', 'd')};
static const uint32_t __string_125[] = {1, S('*', 0)};
static const uint32_t __string_126_op_multiply[] = {11, S('o', 'p'), S('_', 'm'), S('u', 'l'), S('t', 'i'), S('p', 'l'), S('y', 0)};
static const uint32_t __string_127[] = {2, S('*', '*')};
static const uint32_t __string_128_op_exponent[] = {11, S('o', 'p'), S('_', 'e'), S('x', 'p'), S('o', 'n'), S('e', 'n'), S('t', 0)};
static const uint32_t __string_129[] = {2, S('+', '+')};
static const uint32_t __string_130_op_increment[] = {12, S('o', 'p'), S('_', 'i'), S('n', 'c'), S('r', 'e'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_131[] = {2, S('-', '-')};
static const uint32_t __string_132_op_decrement[] = {12, S('o', 'p'), S('_', 'd'), S('e', 'c'), S('r', 'e'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_133[] = {1, S('/', 0)};
static const uint32_t __string_134_op_divide[] = {9, S('o', 'p'), S('_', 'd'), S('i', 'v'), S('i', 'd'), S('e', 0)};
static const uint32_t __string_135[] = {1, S('<', 0)};
static const uint32_t __string_136_op_lessThan[] = {11, S('o', 'p'), S('_', 'l'), S('e', 's'), S('s', 'T'), S('h', 'a'), S('n', 0)};
static const uint32_t __string_137[] = {2, S('<', '<')};
static const uint32_t __string_138_op_shiftLeft[] = {12, S('o', 'p'), S('_', 's'), S('h', 'i'), S('f', 't'), S('L', 'e'), S('f', 't')};
static const uint32_t __string_139[] = {2, S('=', '=')};
static const uint32_t __string_140_op_equals[] = {9, S('o', 'p'), S('_', 'e'), S('q', 'u'), S('a', 'l'), S('s', 0)};
static const uint32_t __string_141[] = {1, S('>', 0)};
static const uint32_t __string_142_op_greaterThan[] = {14, S('o', 'p'), S('_', 'g'), S('r', 'e'), S('a', 't'), S('e', 'r'), S('T', 'h'), S('a', 'n')};
static const uint32_t __string_143[] = {2, S('>', '>')};
static const uint32_t __string_144_op_shiftRight[] = {13, S('o', 'p'), S('_', 's'), S('h', 'i'), S('f', 't'), S('R', 'i'), S('g', 'h'), S('t', 0)};
static const uint32_t __string_145[] = {2, S('[', ']')};
static const uint32_t __string_146_op_get[] = {6, S('o', 'p'), S('_', 'g'), S('e', 't')};
static const uint32_t __string_147[] = {3, S('[', ']'), S('=', 0)};
static const uint32_t __string_148_op_set[] = {6, S('o', 'p'), S('_', 's'), S('e', 't')};
static const uint32_t __string_149[] = {1, S('^', 0)};
static const uint32_t __string_150_op_xor[] = {6, S('o', 'p'), S('_', 'x'), S('o', 'r')};
static const uint32_t __string_151[] = {1, S('|', 0)};
static const uint32_t __string_152_op_or[] = {5, S('o', 'p'), S('_', 'o'), S('r', 0)};
static const uint32_t __string_153[] = {1, S('~', 0)};
static const uint32_t __string_154_op_complement[] = {13, S('o', 'p'), S('_', 'c'), S('o', 'm'), S('p', 'l'), S('e', 'm'), S('e', 'n'), S('t', 0)};
static const uint32_t __string_155_this[] = {4, S('t', 'h'), S('i', 's')};
static const uint32_t __string_156_bool[] = {4, S('b', 'o'), S('o', 'l')};
static const uint32_t __string_157_byte[] = {4, S('b', 'y'), S('t', 'e')};
static const uint32_t __string_158_int[] = {3, S('i', 'n'), S('t', 0)};
static const uint32_t __string_159_sbyte[] = {5, S('s', 'b'), S('y', 't'), S('e', 0)};
static const uint32_t __string_160_short[] = {5, S('s', 'h'), S('o', 'r'), S('t', 0)};
static const uint32_t __string_161_string[] = {6, S('s', 't'), S('r', 'i'), S('n', 'g')};
static const uint32_t __string_162_uint[] = {4, S('u', 'i'), S('n', 't')};
static const uint32_t __string_163_ushort[] = {6, S('u', 's'), S('h', 'o'), S('r', 't')};
static const uint32_t __string_164_Unsupported_flag_export[] = {25, S('U', 'n'), S('s', 'u'), S('p', 'p'), S('o', 'r'), S('t', 'e'), S('d', ' '), S('f', 'l'), S('a', 'g'), S(' ', '\''), S('e', 'x'), S('p',
  'o'), S('r', 't'), S('\'', 0)};
static const uint32_t __string_165_Unsupported_flag_protected[] = {28, S('U', 'n'), S('s', 'u'), S('p', 'p'), S('o', 'r'), S('t', 'e'), S('d', ' '), S('f', 'l'), S('a', 'g'), S(' ', '\''), S('p', 'r'), S('o',
  't'), S('e', 'c'), S('t', 'e'), S('d', '\'')};
static const uint32_t __string_166_Unsupported_flag_static[] = {25, S('U', 'n'), S('s', 'u'), S('p', 'p'), S('o', 'r'), S('t', 'e'), S('d', ' '), S('f', 'l'), S('a', 'g'), S(' ', '\''), S('s', 't'), S('a',
  't'), S('i', 'c'), S('\'', 0)};
static const uint32_t __string_167_Cannot_use_get_on_a_class[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('g', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a',
  ' '), S('c', 'l'), S('a', 's'), S('s', 0)};
static const uint32_t __string_168_Cannot_use_set_on_a_class[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('s', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a',
  ' '), S('c', 'l'), S('a', 's'), S('s', 0)};
static const uint32_t __string_169_Cannot_use_public_on_a_class[] = {30, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'u'), S('b', 'l'), S('i', 'c'), S('\'', ' '), S('o',
  'n'), S(' ', 'a'), S(' ', 'c'), S('l', 'a'), S('s', 's')};
static const uint32_t __string_170_Cannot_use_private_on_a_class[] = {31, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', '\''), S(' ',
  'o'), S('n', ' '), S('a', ' '), S('c', 'l'), S('a', 's'), S('s', 0)};
static const uint32_t __string_171_Cannot_use_get_on_an_enum[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('g', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a',
  'n'), S(' ', 'e'), S('n', 'u'), S('m', 0)};
static const uint32_t __string_172_Cannot_use_set_on_an_enum[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('s', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a',
  'n'), S(' ', 'e'), S('n', 'u'), S('m', 0)};
static const uint32_t __string_173_Cannot_use_public_on_an_enum[] = {30, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'u'), S('b', 'l'), S('i', 'c'), S('\'', ' '), S('o',
  'n'), S(' ', 'a'), S('n', ' '), S('e', 'n'), S('u', 'm')};
static const uint32_t __string_174_Cannot_use_private_on_an_enum[] = {31, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', '\''), S(' ',
  'o'), S('n', ' '), S('a', 'n'), S(' ', 'e'), S('n', 'u'), S('m', 0)};
static const uint32_t __string_175_Cannot_use_get_here[] = {21, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('g', 'e'), S('t', '\''), S(' ', 'h'), S('e', 'r'), S('e', 0)};
static const uint32_t __string_176_Cannot_use_set_here[] = {21, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('s', 'e'), S('t', '\''), S(' ', 'h'), S('e', 'r'), S('e', 0)};
static const uint32_t __string_177_Cannot_use_public_here[] = {24, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'u'), S('b', 'l'), S('i', 'c'), S('\'', ' '), S('h',
  'e'), S('r', 'e')};
static const uint32_t __string_178_Cannot_use_private_here[] = {25, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', '\''), S(' ',
  'h'), S('e', 'r'), S('e', 0)};
static const uint32_t __string_179_Cannot_use_both_get_and_set[] = {31, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 'b'), S('o', 't'), S('h', ' '), S('\'', 'g'), S('e', 't'), S('\'',
  ' '), S('a', 'n'), S('d', ' '), S('\'', 's'), S('e', 't'), S('\'', 0)};
static const uint32_t __string_180_Getters_must_not_have_any_argume[] = {35, S('G', 'e'), S('t', 't'), S('e', 'r'), S('s', ' '), S('m', 'u'), S('s', 't'), S(' ', 'n'), S('o', 't'), S(' ', 'h'), S('a', 'v'), S('e',
  ' '), S('a', 'n'), S('y', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't'), S('s', 0)};
static const uint32_t __string_181_set_[] = {4, S('s', 'e'), S('t', '_')};
static const uint32_t __string_182_Setters_must_have_exactly_one_ar[] = {38, S('S', 'e'), S('t', 't'), S('e', 'r'), S('s', ' '), S('m', 'u'), S('s', 't'), S(' ', 'h'), S('a', 'v'), S('e', ' '), S('e', 'x'), S('a',
  'c'), S('t', 'l'), S('y', ' '), S('o', 'n'), S('e', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_183[] = {1, S('~', 0)};
static const uint32_t __string_184[] = {2, S('+', '+')};
static const uint32_t __string_185[] = {2, S('-', '-')};
static const uint32_t __string_186_Operator[] = {10, S('O', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\'')};
static const uint32_t __string_187_must_not_have_any_arguments[] = {29, S('\'', ' '), S('m', 'u'), S('s', 't'), S(' ', 'n'), S('o', 't'), S(' ', 'h'), S('a', 'v'), S('e', ' '), S('a', 'n'), S('y', ' '), S('a',
  'r'), S('g', 'u'), S('m', 'e'), S('n', 't'), S('s', 0)};
static const uint32_t __string_188[] = {1, S('+', 0)};
static const uint32_t __string_189[] = {1, S('-', 0)};
static const uint32_t __string_190_Operator[] = {10, S('O', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\'')};
static const uint32_t __string_191_must_have_at_most_one_argument[] = {32, S('\'', ' '), S('m', 'u'), S('s', 't'), S(' ', 'h'), S('a', 'v'), S('e', ' '), S('a', 't'), S(' ', 'm'), S('o', 's'), S('t', ' '), S('o',
  'n'), S('e', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_192[] = {3, S('[', ']'), S('=', 0)};
static const uint32_t __string_193_Operator_must_have_at_leas[] = {46, S('O', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\''), S('[', ']'), S('=', '\''), S(' ', 'm'), S('u', 's'), S('t', ' '), S('h',
  'a'), S('v', 'e'), S(' ', 'a'), S('t', ' '), S('l', 'e'), S('a', 's'), S('t', ' '), S('o', 'n'), S('e', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_194_Operator[] = {10, S('O', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\'')};
static const uint32_t __string_195_must_have_exactly_one_argument[] = {32, S('\'', ' '), S('m', 'u'), S('s', 't'), S(' ', 'h'), S('a', 'v'), S('e', ' '), S('e', 'x'), S('a', 'c'), S('t', 'l'), S('y', ' '), S('o',
  'n'), S('e', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_196_Cannot_use_extern_on_an_instan[] = {43, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('e', 'x'), S('t', 'e'), S('r', 'n'), S('\'', ' '), S('o',
  'n'), S(' ', 'a'), S('n', ' '), S('i', 'n'), S('s', 't'), S('a', 'n'), S('c', 'e'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', 0)};
static const uint32_t __string_197_Cannot_use_declare_on_an_insta[] = {44, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', '\''), S(' ',
  'o'), S('n', ' '), S('a', 'n'), S(' ', 'i'), S('n', 's'), S('t', 'a'), S('n', 'c'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n')};
static const uint32_t __string_198_Must_implement_this_function[] = {28, S('M', 'u'), S('s', 't'), S(' ', 'i'), S('m', 'p'), S('l', 'e'), S('m', 'e'), S('n', 't'), S(' ', 't'), S('h', 'i'), S('s', ' '), S('f',
  'u'), S('n', 'c'), S('t', 'i'), S('o', 'n')};
static const uint32_t __string_199_this[] = {4, S('t', 'h'), S('i', 's')};
static const uint32_t __string_200___this[] = {6, S('_', '_'), S('t', 'h'), S('i', 's')};
static const uint32_t __string_201_Cannot_use_extern_on_an_unimpl[] = {48, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('e', 'x'), S('t', 'e'), S('r', 'n'), S('\'', ' '), S('o',
  'n'), S(' ', 'a'), S('n', ' '), S('u', 'n'), S('i', 'm'), S('p', 'l'), S('e', 'm'), S('e', 'n'), S('t', 'e'), S('d', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n')};
static const uint32_t __string_202_Declared_functions_must_be_prefi[] = {50, S('D', 'e'), S('c', 'l'), S('a', 'r'), S('e', 'd'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', 's'), S(' ', 'm'), S('u',
  's'), S('t', ' '), S('b', 'e'), S(' ', 'p'), S('r', 'e'), S('f', 'i'), S('x', 'e'), S('d', ' '), S('w', 'i'), S('t', 'h'), S(' ', '\''), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', '\'')};
static const uint32_t __string_203_Cannot_use_declare_on_a_functi[] = {57, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', '\''), S(' ',
  'o'), S('n', ' '), S('a', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'w'), S('i', 't'), S('h', ' '), S('a', 'n'), S(' ', 'i'), S('m', 'p'), S('l', 'e'), S('m', 'e'), S('n', 't'), S('a',
  't'), S('i', 'o'), S('n', 0)};
static const uint32_t __string_204_Cannot_use_get_on_a_variable[] = {30, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('g', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a',
  ' '), S('v', 'a'), S('r', 'i'), S('a', 'b'), S('l', 'e')};
static const uint32_t __string_205_Cannot_use_set_on_a_variable[] = {30, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('s', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a',
  ' '), S('v', 'a'), S('r', 'i'), S('a', 'b'), S('l', 'e')};
static const uint32_t __string_206_Cannot_use_public_here[] = {24, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'u'), S('b', 'l'), S('i', 'c'), S('\'', ' '), S('h',
  'e'), S('r', 'e')};
static const uint32_t __string_207_Cannot_use_private_here[] = {25, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', '\''), S(' ',
  'h'), S('e', 'r'), S('e', 0)};
static const uint32_t __string_208_Cannot_create_untyped_variables[] = {31, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('r', 'e'), S('a', 't'), S('e', ' '), S('u', 'n'), S('t', 'y'), S('p', 'e'), S('d',
  ' '), S('v', 'a'), S('r', 'i'), S('a', 'b'), S('l', 'e'), S('s', 0)};
static const uint32_t __string_209_Cannot_create_a_variable_with_ty[] = {36, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('r', 'e'), S('a', 't'), S('e', ' '), S('a', ' '), S('v', 'a'), S('r', 'i'), S('a',
  'b'), S('l', 'e'), S(' ', 'w'), S('i', 't'), S('h', ' '), S('t', 'y'), S('p', 'e'), S(' ', '\'')};
static const uint32_t __string_210_Invalid_constant_initializer[] = {28, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('c', 'o'), S('n', 's'), S('t', 'a'), S('n', 't'), S(' ', 'i'), S('n', 'i'), S('t',
  'i'), S('a', 'l'), S('i', 'z'), S('e', 'r')};
static const uint32_t __string_211_Constants_must_be_initialized[] = {29, S('C', 'o'), S('n', 's'), S('t', 'a'), S('n', 't'), S('s', ' '), S('m', 'u'), S('s', 't'), S(' ', 'b'), S('e', ' '), S('i', 'n'), S('i',
  't'), S('i', 'a'), S('l', 'i'), S('z', 'e'), S('d', 0)};
static const uint32_t __string_212_The_symbol[] = {12, S('T', 'h'), S('e', ' '), S('s', 'y'), S('m', 'b'), S('o', 'l'), S(' ', '\'')};
static const uint32_t __string_213_shadows_another_symbol_with_th[] = {61, S('\'', ' '), S('s', 'h'), S('a', 'd'), S('o', 'w'), S('s', ' '), S('a', 'n'), S('o', 't'), S('h', 'e'), S('r', ' '), S('s', 'y'), S('m',
  'b'), S('o', 'l'), S(' ', 'w'), S('i', 't'), S('h', ' '), S('t', 'h'), S('e', ' '), S('s', 'a'), S('m', 'e'), S(' ', 'n'), S('a', 'm'), S('e', ' '), S('i', 'n'), S(' ', 'a'), S(' ', 'p'), S('a', 'r'), S('e',
  'n'), S('t', ' '), S('s', 'c'), S('o', 'p'), S('e', 0)};
static const uint32_t __string_214_Expected_expression_but_found_ty[] = {34, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 'e'), S('x', 'p'), S('r', 'e'), S('s', 's'), S('i', 'o'), S('n', ' '), S('b',
  'u'), S('t', ' '), S('f', 'o'), S('u', 'n'), S('d', ' '), S('t', 'y'), S('p', 'e')};
static const uint32_t __string_215_This_expression_does_not_return[] = {39, S('T', 'h'), S('i', 's'), S(' ', 'e'), S('x', 'p'), S('r', 'e'), S('s', 's'), S('i', 'o'), S('n', ' '), S('d', 'o'), S('e', 's'), S(' ',
  'n'), S('o', 't'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('a', ' '), S('v', 'a'), S('l', 'u'), S('e', 0)};
static const uint32_t __string_216_Expected_type_but_found_expressi[] = {34, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('b', 'u'), S('t', ' '), S('f', 'o'), S('u',
  'n'), S('d', ' '), S('e', 'x'), S('p', 'r'), S('e', 's'), S('s', 'i'), S('o', 'n')};
static const uint32_t __string_217_Cannot_convert_from_type[] = {26, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('o', 'n'), S('v', 'e'), S('r', 't'), S(' ', 'f'), S('r', 'o'), S('m', ' '), S('t',
  'y'), S('p', 'e'), S(' ', '\'')};
static const uint32_t __string_218_to_type[] = {11, S('\'', ' '), S('t', 'o'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_219_without_a_cast[] = {16, S('\'', ' '), S('w', 'i'), S('t', 'h'), S('o', 'u'), S('t', ' '), S('a', ' '), S('c', 'a'), S('s', 't')};
static const uint32_t __string_220[] = {1, S('\'', 0)};
static const uint32_t __string_221_Cannot_store_to_this_location[] = {29, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 's'), S('t', 'o'), S('r', 'e'), S(' ', 't'), S('o', ' '), S('t', 'h'), S('i', 's'), S(' ',
  'l'), S('o', 'c'), S('a', 't'), S('i', 'o'), S('n', 0)};
static const uint32_t __string_222_Cannot_use_symbol[] = {19, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 's'), S('y', 'm'), S('b', 'o'), S('l', ' '), S('\'', 0)};
static const uint32_t __string_223_outside_an_unsafe_block[] = {27, S('\'', ' '), S('o', 'u'), S('t', 's'), S('i', 'd'), S('e', ' '), S('a', 'n'), S(' ', '\''), S('u', 'n'), S('s', 'a'), S('f', 'e'), S('\'',
  ' '), S('b', 'l'), S('o', 'c'), S('k', 0)};
static const uint32_t __string_224_Cannot_access_private_symbol[] = {30, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'a'), S('c', 'c'), S('e', 's'), S('s', ' '), S('p', 'r'), S('i', 'v'), S('a', 't'), S('e',
  ' '), S('s', 'y'), S('m', 'b'), S('o', 'l'), S(' ', '\'')};
static const uint32_t __string_225_here[] = {6, S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_226_Cannot_use_setter[] = {19, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 's'), S('e', 't'), S('t', 'e'), S('r', ' '), S('\'', 0)};
static const uint32_t __string_227_here[] = {6, S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_228_Must_call_function[] = {20, S('M', 'u'), S('s', 't'), S(' ', 'c'), S('a', 'l'), S('l', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', '\'')};
static const uint32_t __string_229_Global_initializers_must_be_comp[] = {50, S('G', 'l'), S('o', 'b'), S('a', 'l'), S(' ', 'i'), S('n', 'i'), S('t', 'i'), S('a', 'l'), S('i', 'z'), S('e', 'r'), S('s', ' '), S('m',
  'u'), S('s', 't'), S(' ', 'b'), S('e', ' '), S('c', 'o'), S('m', 'p'), S('i', 'l'), S('e', '-'), S('t', 'i'), S('m', 'e'), S(' ', 'c'), S('o', 'n'), S('s', 't'), S('a', 'n'), S('t', 's')};
static const uint32_t __string_230_Cannot_use_this_statement_outsid[] = {43, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 't'), S('h', 'i'), S('s', ' '), S('s', 't'), S('a', 't'), S('e',
  'm'), S('e', 'n'), S('t', ' '), S('o', 'u'), S('t', 's'), S('i', 'd'), S('e', ' '), S('o', 'f'), S(' ', 'a'), S(' ', 'l'), S('o', 'o'), S('p', 0)};
static const uint32_t __string_231[] = {2, S('[', ']')};
static const uint32_t __string_232_Cannot_index_into_type[] = {24, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'i'), S('n', 'd'), S('e', 'x'), S(' ', 'i'), S('n', 't'), S('o', ' '), S('t', 'y'), S('p',
  'e'), S(' ', '\'')};
static const uint32_t __string_233_this[] = {4, S('t', 'h'), S('i', 's')};
static const uint32_t __string_234_Cannot_use_this_here[] = {22, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('t', 'h'), S('i', 's'), S('\'', ' '), S('h', 'e'), S('r',
  'e')};
static const uint32_t __string_235_No_symbol_named[] = {17, S('N', 'o'), S(' ', 's'), S('y', 'm'), S('b', 'o'), S('l', ' '), S('n', 'a'), S('m', 'e'), S('d', ' '), S('\'', 0)};
static const uint32_t __string_236_here[] = {6, S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_237_did_you_mean_this[] = {21, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('t', 'h'), S('i', 's'), S('.', 0)};
static const uint32_t __string_238[] = {2, S('\'', '?')};
static const uint32_t __string_239_number[] = {6, S('n', 'u'), S('m', 'b'), S('e', 'r')};
static const uint32_t __string_240_did_you_mean_int[] = {21, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('i', 'n'), S('t', '\''), S('?', 0)};
static const uint32_t __string_241_boolean[] = {7, S('b', 'o'), S('o', 'l'), S('e', 'a'), S('n', 0)};
static const uint32_t __string_242_did_you_mean_bool[] = {22, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('b', 'o'), S('o', 'l'), S('\'',
  '?')};
static const uint32_t __string_243_Cyclic_reference_to_symbol[] = {28, S('C', 'y'), S('c', 'l'), S('i', 'c'), S(' ', 'r'), S('e', 'f'), S('e', 'r'), S('e', 'n'), S('c', 'e'), S(' ', 't'), S('o', ' '), S('s',
  'y'), S('m', 'b'), S('o', 'l'), S(' ', '\'')};
static const uint32_t __string_244_here[] = {6, S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_245_No_member_named[] = {17, S('N', 'o'), S(' ', 'm'), S('e', 'm'), S('b', 'e'), S('r', ' '), S('n', 'a'), S('m', 'e'), S('d', ' '), S('\'', 0)};
static const uint32_t __string_246_on_type[] = {11, S('\'', ' '), S('o', 'n'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_247_The_type[] = {10, S('T', 'h'), S('e', ' '), S('t', 'y'), S('p', 'e'), S(' ', '\'')};
static const uint32_t __string_248_has_no_members[] = {16, S('\'', ' '), S('h', 'a'), S('s', ' '), S('n', 'o'), S(' ', 'm'), S('e', 'm'), S('b', 'e'), S('r', 's')};
static const uint32_t __string_249_Cannot_call_value_of_type[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('a', 'l'), S('l', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('o', 'f'), S(' ',
  't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_250_Not_enough_arguments_for_functio[] = {35, S('N', 'o'), S('t', ' '), S('e', 'n'), S('o', 'u'), S('g', 'h'), S(' ', 'a'), S('r', 'g'), S('u', 'm'), S('e', 'n'), S('t', 's'), S(' ',
  'f'), S('o', 'r'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('\'', 0)};
static const uint32_t __string_251_Too_many_arguments_for_function[] = {33, S('T', 'o'), S('o', ' '), S('m', 'a'), S('n', 'y'), S(' ', 'a'), S('r', 'g'), S('u', 'm'), S('e', 'n'), S('t', 's'), S(' ', 'f'), S('o',
  'r'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('\'', 0)};
static const uint32_t __string_252_Unexpected_return_value_in_funct[] = {52, S('U', 'n'), S('e', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('v', 'a'), S('l',
  'u'), S('e', ' '), S('i', 'n'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S('i', 'n'), S('g', ' '), S('\'', 'v'), S('o', 'i'), S('d', '\'')};
static const uint32_t __string_253_Expected_return_value_in_functio[] = {45, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('v', 'a'), S('l', 'u'), S('e',
  ' '), S('i', 'n'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S('i', 'n'), S('g', ' '), S('\'', 0)};
static const uint32_t __string_254_Generics_are_not_implemented_yet[] = {32, S('G', 'e'), S('n', 'e'), S('r', 'i'), S('c', 's'), S(' ', 'a'), S('r', 'e'), S(' ', 'n'), S('o', 't'), S(' ', 'i'), S('m', 'p'), S('l',
  'e'), S('m', 'e'), S('n', 't'), S('e', 'd'), S(' ', 'y'), S('e', 't')};
static const uint32_t __string_255_Subclassing_is_not_implemented_y[] = {34, S('S', 'u'), S('b', 'c'), S('l', 'a'), S('s', 's'), S('i', 'n'), S('g', ' '), S('i', 's'), S(' ', 'n'), S('o', 't'), S(' ', 'i'), S('m',
  'p'), S('l', 'e'), S('m', 'e'), S('n', 't'), S('e', 'd'), S(' ', 'y'), S('e', 't')};
static const uint32_t __string_256_Interfaces_are_not_implemented_y[] = {34, S('I', 'n'), S('t', 'e'), S('r', 'f'), S('a', 'c'), S('e', 's'), S(' ', 'a'), S('r', 'e'), S(' ', 'n'), S('o', 't'), S(' ', 'i'), S('m',
  'p'), S('l', 'e'), S('m', 'e'), S('n', 't'), S('e', 'd'), S(' ', 'y'), S('e', 't')};
static const uint32_t __string_257_Type[] = {6, S('T', 'y'), S('p', 'e'), S(' ', '\'')};
static const uint32_t __string_258_is_not_the_same_as_type[] = {27, S('\'', ' '), S('i', 's'), S(' ', 'n'), S('o', 't'), S(' ', 't'), S('h', 'e'), S(' ', 's'), S('a', 'm'), S('e', ' '), S('a', 's'), S(' ',
  't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_259[] = {3, S('[', ']'), S('=', 0)};
static const uint32_t __string_260_Cannot_index_into_type[] = {24, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'i'), S('n', 'd'), S('e', 'x'), S(' ', 'i'), S('n', 't'), S('o', ' '), S('t', 'y'), S('p',
  'e'), S(' ', '\'')};
static const uint32_t __string_261_Cannot_construct_type[] = {23, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('o', 'n'), S('s', 't'), S('r', 'u'), S('c', 't'), S(' ', 't'), S('y', 'p'), S('e',
  ' '), S('\'', 0)};
static const uint32_t __string_262_Constructors_with_arguments_are[] = {49, S('C', 'o'), S('n', 's'), S('t', 'r'), S('u', 'c'), S('t', 'o'), S('r', 's'), S(' ', 'w'), S('i', 't'), S('h', ' '), S('a', 'r'), S('g',
  'u'), S('m', 'e'), S('n', 't'), S('s', ' '), S('a', 'r'), S('e', ' '), S('n', 'o'), S('t', ' '), S('s', 'u'), S('p', 'p'), S('o', 'r'), S('t', 'e'), S('d', ' '), S('y', 'e'), S('t', 0)};
static const uint32_t __string_263_Cannot_use_pointers_when_compili[] = {48, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 'p'), S('o', 'i'), S('n', 't'), S('e', 'r'), S('s', ' '), S('w',
  'h'), S('e', 'n'), S(' ', 'c'), S('o', 'm'), S('p', 'i'), S('l', 'i'), S('n', 'g'), S(' ', 't'), S('o', ' '), S('J', 'a'), S('v', 'a'), S('S', 'c'), S('r', 'i'), S('p', 't')};
static const uint32_t __string_264_Cannot_use_pointers_outside_an[] = {45, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 'p'), S('o', 'i'), S('n', 't'), S('e', 'r'), S('s', ' '), S('o',
  'u'), S('t', 's'), S('i', 'd'), S('e', ' '), S('a', 'n'), S(' ', '\''), S('u', 'n'), S('s', 'a'), S('f', 'e'), S('\'', ' '), S('b', 'l'), S('o', 'c'), S('k', 0)};
static const uint32_t __string_265_Cannot_create_a_pointer_to_non_i[] = {45, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('r', 'e'), S('a', 't'), S('e', ' '), S('a', ' '), S('p', 'o'), S('i', 'n'), S('t',
  'e'), S('r', ' '), S('t', 'o'), S(' ', 'n'), S('o', 'n'), S('-', 'i'), S('n', 't'), S('e', 'g'), S('e', 'r'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_266_Cannot_dereference_type[] = {25, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'd'), S('e', 'r'), S('e', 'f'), S('e', 'r'), S('e', 'n'), S('c', 'e'), S(' ', 't'), S('y',
  'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_267_The_address_of_operator_is_not_s[] = {40, S('T', 'h'), S('e', ' '), S('a', 'd'), S('d', 'r'), S('e', 's'), S('s', '-'), S('o', 'f'), S(' ', 'o'), S('p', 'e'), S('r', 'a'), S('t',
  'o'), S('r', ' '), S('i', 's'), S(' ', 'n'), S('o', 't'), S(' ', 's'), S('u', 'p'), S('p', 'o'), S('r', 't'), S('e', 'd')};
static const uint32_t __string_268_Cannot_use_unary_operator[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 'u'), S('n', 'a'), S('r', 'y'), S(' ', 'o'), S('p', 'e'), S('r',
  'a'), S('t', 'o'), S('r', ' '), S('\'', 0)};
static const uint32_t __string_269_with_type[] = {13, S('\'', ' '), S('w', 'i'), S('t', 'h'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_270_Cannot_compare_type[] = {21, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('o', 'm'), S('p', 'a'), S('r', 'e'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_271_with_type[] = {13, S('\'', ' '), S('w', 'i'), S('t', 'h'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_272_This_operator_is_not_currently_s[] = {40, S('T', 'h'), S('i', 's'), S(' ', 'o'), S('p', 'e'), S('r', 'a'), S('t', 'o'), S('r', ' '), S('i', 's'), S(' ', 'n'), S('o', 't'), S(' ',
  'c'), S('u', 'r'), S('r', 'e'), S('n', 't'), S('l', 'y'), S(' ', 's'), S('u', 'p'), S('p', 'o'), S('r', 't'), S('e', 'd')};
static const uint32_t __string_273[] = {2, S('=', '=')};
static const uint32_t __string_274[] = {1, S('>', 0)};
static const uint32_t __string_275[] = {1, S('<', 0)};
static const uint32_t __string_276_Cannot_compare_type[] = {21, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('o', 'm'), S('p', 'a'), S('r', 'e'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_277_with_type[] = {13, S('\'', ' '), S('w', 'i'), S('t', 'h'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_278_Cannot_use_binary_operator[] = {28, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 'b'), S('i', 'n'), S('a', 'r'), S('y', ' '), S('o', 'p'), S('e',
  'r'), S('a', 't'), S('o', 'r'), S(' ', '\'')};
static const uint32_t __string_279_with_type[] = {13, S('\'', ' '), S('w', 'i'), S('t', 'h'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_280_native[] = {8, S('<', 'n'), S('a', 't'), S('i', 'v'), S('e', '>')};
static const uint32_t __string_281_C[] = {1, S('C', 0)};
static const uint32_t __string_282_JS[] = {2, S('J', 'S')};
static const uint32_t __string_283_WASM[] = {4, S('W', 'A'), S('S', 'M')};
static const uint32_t __string_284_error[] = {7, S('<', 'e'), S('r', 'r'), S('o', 'r'), S('>', 0)};
static const uint32_t __string_285_null[] = {4, S('n', 'u'), S('l', 'l')};
static const uint32_t __string_286_void[] = {4, S('v', 'o'), S('i', 'd')};
static const uint32_t __string_287_lexing[] = {6, S('l', 'e'), S('x', 'i'), S('n', 'g')};
static const uint32_t __string_288_preprocessing[] = {13, S('p', 'r'), S('e', 'p'), S('r', 'o'), S('c', 'e'), S('s', 's'), S('i', 'n'), S('g', 0)};
static const uint32_t __string_289_parsing[] = {7, S('p', 'a'), S('r', 's'), S('i', 'n'), S('g', 0)};
static const uint32_t __string_290_checking[] = {8, S('c', 'h'), S('e', 'c'), S('k', 'i'), S('n', 'g')};
static const uint32_t __string_291_shaking[] = {7, S('s', 'h'), S('a', 'k'), S('i', 'n'), S('g', 0)};
static const uint32_t __string_292_emitting[] = {8, S('e', 'm'), S('i', 't'), S('t', 'i'), S('n', 'g')};
static const uint32_t __string_293[] = {1, S('.', 0)};
static const uint32_t __string_294[] = {1, S('/', 0)};
static const uint32_t __string_295[] = {1, S('\\', 0)};
static const uint32_t __string_296[] = {2, S(' ', ' ')};
static const uint32_t __string_297[] = {2, S('{', '\n')};
static const uint32_t __string_298_0[] = {6, S(' ', '>'), S('>', '>'), S(' ', '0')};
static const uint32_t __string_299_0[] = {4, S(' ', '|'), S(' ', '0')};
static const uint32_t __string_300_0[] = {6, S(' ', '>'), S('>', '>'), S(' ', '0')};
static const uint32_t __string_301_0[] = {4, S(' ', '|'), S(' ', '0')};
static const uint32_t __string_302[] = {2, S(',', ' ')};
static const uint32_t __string_303___declare[] = {10, S('_', '_'), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', '.')};
static const uint32_t __string_304_null[] = {4, S('n', 'u'), S('l', 'l')};
static const uint32_t __string_305_true[] = {4, S('t', 'r'), S('u', 'e')};
static const uint32_t __string_306_false[] = {5, S('f', 'a'), S('l', 's'), S('e', 0)};
static const uint32_t __string_307[] = {4, S(' ', '<'), S('<', ' ')};
static const uint32_t __string_308[] = {4, S(' ', '>'), S('>', ' ')};
static const uint32_t __string_309[] = {3, S(' ', '&'), S(' ', 0)};
static const uint32_t __string_310_0[] = {4, S(' ', '|'), S(' ', '0')};
static const uint32_t __string_311_0[] = {6, S(' ', '>'), S('>', '>'), S(' ', '0')};
static const uint32_t __string_312[] = {3, S(' ', '?'), S(' ', 0)};
static const uint32_t __string_313[] = {3, S(' ', ':'), S(' ', 0)};
static const uint32_t __string_314_new[] = {4, S('n', 'e'), S('w', ' ')};
static const uint32_t __string_315[] = {2, S('(', ')')};
static const uint32_t __string_316[] = {1, S('!', 0)};
static const uint32_t __string_317[] = {1, S('~', 0)};
static const uint32_t __string_318[] = {1, S('-', 0)};
static const uint32_t __string_319[] = {1, S('+', 0)};
static const uint32_t __string_320[] = {2, S('+', '+')};
static const uint32_t __string_321[] = {2, S('-', '-')};
static const uint32_t __string_322[] = {2, S('+', '+')};
static const uint32_t __string_323[] = {2, S('-', '-')};
static const uint32_t __string_324[] = {3, S(' ', '+'), S(' ', 0)};
static const uint32_t __string_325[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_326[] = {3, S(' ', '&'), S(' ', 0)};
static const uint32_t __string_327[] = {3, S(' ', '|'), S(' ', 0)};
static const uint32_t __string_328[] = {3, S(' ', '^'), S(' ', 0)};
static const uint32_t __string_329[] = {3, S(' ', '/'), S(' ', 0)};
static const uint32_t __string_330[] = {5, S(' ', '='), S('=', '='), S(' ', 0)};
static const uint32_t __string_331[] = {3, S(' ', '>'), S(' ', 0)};
static const uint32_t __string_332[] = {4, S(' ', '>'), S('=', ' ')};
static const uint32_t __string_333[] = {3, S(' ', '<'), S(' ', 0)};
static const uint32_t __string_334[] = {4, S(' ', '<'), S('=', ' ')};
static const uint32_t __string_335[] = {4, S(' ', '&'), S('&', ' ')};
static const uint32_t __string_336[] = {4, S(' ', '|'), S('|', ' ')};
static const uint32_t __string_337[] = {5, S(' ', '!'), S('=', '='), S(' ', 0)};
static const uint32_t __string_338[] = {3, S(' ', '%'), S(' ', 0)};
static const uint32_t __string_339[] = {4, S(' ', '<'), S('<', ' ')};
static const uint32_t __string_340[] = {5, S(' ', '>'), S('>', '>'), S(' ', 0)};
static const uint32_t __string_341[] = {4, S(' ', '>'), S('>', ' ')};
static const uint32_t __string_342[] = {3, S(' ', '-'), S(' ', 0)};
static const uint32_t __string_343___imul[] = {7, S('_', '_'), S('i', 'm'), S('u', 'l'), S('(', 0)};
static const uint32_t __string_344[] = {2, S(',', ' ')};
static const uint32_t __string_345_0[] = {6, S(' ', '>'), S('>', '>'), S(' ', '0')};
static const uint32_t __string_346_prototype[] = {11, S('.', 'p'), S('r', 'o'), S('t', 'o'), S('t', 'y'), S('p', 'e'), S('.', 0)};
static const uint32_t __string_347_function[] = {11, S(' ', '='), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', 0)};
static const uint32_t __string_348_var[] = {4, S('v', 'a'), S('r', ' ')};
static const uint32_t __string_349___extern[] = {12, S(' ', '='), S(' ', '_'), S('_', 'e'), S('x', 't'), S('e', 'r'), S('n', '.')};
static const uint32_t __string_350_function[] = {11, S(' ', '='), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', 0)};
static const uint32_t __string_351_function[] = {9, S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 0)};
static const uint32_t __string_352[] = {2, S(',', ' ')};
static const uint32_t __string_353[] = {2, S(')', ' ')};
static const uint32_t __string_354[] = {2, S(';', '\n')};
static const uint32_t __string_355[] = {1, S('\n', 0)};
static const uint32_t __string_356_if[] = {4, S('i', 'f'), S(' ', '(')};
static const uint32_t __string_357[] = {2, S(')', ' ')};
static const uint32_t __string_358[] = {2, S('\n', '\n')};
static const uint32_t __string_359_else[] = {5, S('e', 'l'), S('s', 'e'), S(' ', 0)};
static const uint32_t __string_360_while[] = {7, S('w', 'h'), S('i', 'l'), S('e', ' '), S('(', 0)};
static const uint32_t __string_361[] = {2, S(')', ' ')};
static const uint32_t __string_362_break[] = {7, S('b', 'r'), S('e', 'a'), S('k', ';'), S('\n', 0)};
static const uint32_t __string_363_continue[] = {10, S('c', 'o'), S('n', 't'), S('i', 'n'), S('u', 'e'), S(';', '\n')};
static const uint32_t __string_364[] = {2, S(';', '\n')};
static const uint32_t __string_365_return[] = {7, S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 0)};
static const uint32_t __string_366[] = {2, S(';', '\n')};
static const uint32_t __string_367_return[] = {8, S('r', 'e'), S('t', 'u'), S('r', 'n'), S(';', '\n')};
static const uint32_t __string_368_var[] = {4, S('v', 'a'), S('r', ' ')};
static const uint32_t __string_369[] = {2, S(',', ' ')};
static const uint32_t __string_370[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_371[] = {2, S(';', '\n')};
static const uint32_t __string_372_function[] = {9, S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 0)};
static const uint32_t __string_373[] = {5, S('(', ')'), S(' ', '{'), S('\n', 0)};
static const uint32_t __string_374_this[] = {5, S('t', 'h'), S('i', 's'), S('.', 0)};
static const uint32_t __string_375[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_376[] = {2, S(';', '\n')};
static const uint32_t __string_377[] = {2, S('}', '\n')};
static const uint32_t __string_378___extern[] = {9, S('_', '_'), S('e', 'x'), S('t', 'e'), S('r', 'n'), S('.', 0)};
static const uint32_t __string_379[] = {5, S(' ', '='), S(' ', '{'), S('\n', 0)};
static const uint32_t __string_380[] = {2, S(':', ' ')};
static const uint32_t __string_381[] = {2, S(',', '\n')};
static const uint32_t __string_382[] = {1, S('\n', 0)};
static const uint32_t __string_383[] = {3, S('}', ';'), S('\n', 0)};
static const uint32_t __string_384_function___declare___extern[] = {33, S('(', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', '('), S('_', '_'), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ','), S(' ',
  '_'), S('_', 'e'), S('x', 't'), S('e', 'r'), S('n', ')'), S(' ', '{'), S('\n', 0)};
static const uint32_t __string_385_var___imul_Math_imul_functi[] = {43, S('v', 'a'), S('r', ' '), S('_', '_'), S('i', 'm'), S('u', 'l'), S(' ', '='), S(' ', 'M'), S('a', 't'), S('h', '.'), S('i', 'm'), S('u',
  'l'), S(' ', '|'), S('|', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S('(', 'a'), S(',', ' '), S('b', ')'), S(' ', '{'), S('\n', 0)};
static const uint32_t __string_386_return_a_b_16_16[] = {53, S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '('), S('a', ' '), S('*', ' '), S('(', 'b'), S(' ', '>'), S('>', '>'), S(' ', '1'), S('6',
  ')'), S(' ', '<'), S('<', ' '), S('1', '6'), S(')', ' '), S('+', ' '), S('a', ' '), S('*', ' '), S('(', 'b'), S(' ', '&'), S(' ', '6'), S('5', '5'), S('3', '5'), S(')', ' '), S('|', ' '), S('0', ';'), S('\n', 0)};
static const uint32_t __string_387[] = {3, S('}', ';'), S('\n', 0)};
static const uint32_t __string_388[] = {3, S('}', '('), S('\n', 0)};
static const uint32_t __string_389_typeof_global_undefined[] = {47, S('t', 'y'), S('p', 'e'), S('o', 'f'), S(' ', 'g'), S('l', 'o'), S('b', 'a'), S('l', ' '), S('!', '='), S('=', ' '), S('\'', 'u'), S('n',
  'd'), S('e', 'f'), S('i', 'n'), S('e', 'd'), S('\'', ' '), S('?', ' '), S('g', 'l'), S('o', 'b'), S('a', 'l'), S(' ', ':'), S(' ', 't'), S('h', 'i'), S('s', ','), S('\n', 0)};
static const uint32_t __string_390_typeof_exports_undefined[] = {48, S('t', 'y'), S('p', 'e'), S('o', 'f'), S(' ', 'e'), S('x', 'p'), S('o', 'r'), S('t', 's'), S(' ', '!'), S('=', '='), S(' ', '\''), S('u',
  'n'), S('d', 'e'), S('f', 'i'), S('n', 'e'), S('d', '\''), S(' ', '?'), S(' ', 'e'), S('x', 'p'), S('o', 'r'), S('t', 's'), S(' ', ':'), S(' ', 't'), S('h', 'i'), S('s', '\n')};
static const uint32_t __string_391[] = {4, S(')', ')'), S(';', '\n')};
static const uint32_t __string_392_end_of_file[] = {11, S('e', 'n'), S('d', ' '), S('o', 'f'), S(' ', 'f'), S('i', 'l'), S('e', 0)};
static const uint32_t __string_393_character_literal[] = {17, S('c', 'h'), S('a', 'r'), S('a', 'c'), S('t', 'e'), S('r', ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', 0)};
static const uint32_t __string_394_identifier[] = {10, S('i', 'd'), S('e', 'n'), S('t', 'i'), S('f', 'i'), S('e', 'r')};
static const uint32_t __string_395_integer_literal[] = {15, S('i', 'n'), S('t', 'e'), S('g', 'e'), S('r', ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', 0)};
static const uint32_t __string_396_string_literal[] = {14, S('s', 't'), S('r', 'i'), S('n', 'g'), S(' ', 'l'), S('i', 't'), S('e', 'r'), S('a', 'l')};
static const uint32_t __string_397[] = {3, S('\'', '='), S('\'', 0)};
static const uint32_t __string_398[] = {3, S('\'', '&'), S('\'', 0)};
static const uint32_t __string_399[] = {3, S('\'', '|'), S('\'', 0)};
static const uint32_t __string_400[] = {3, S('\'', '^'), S('\'', 0)};
static const uint32_t __string_401[] = {3, S('\'', ':'), S('\'', 0)};
static const uint32_t __string_402[] = {3, S('\'', ','), S('\'', 0)};
static const uint32_t __string_403[] = {3, S('\'', '~'), S('\'', 0)};
static const uint32_t __string_404[] = {3, S('\'', '/'), S('\'', 0)};
static const uint32_t __string_405[] = {3, S('\'', '.'), S('\'', 0)};
static const uint32_t __string_406[] = {4, S('\'', '='), S('=', '\'')};
static const uint32_t __string_407[] = {4, S('\'', '*'), S('*', '\'')};
static const uint32_t __string_408[] = {3, S('\'', '>'), S('\'', 0)};
static const uint32_t __string_409[] = {4, S('\'', '>'), S('=', '\'')};
static const uint32_t __string_410[] = {3, S('\'', '{'), S('\'', 0)};
static const uint32_t __string_411[] = {3, S('\'', '['), S('\'', 0)};
static const uint32_t __string_412[] = {3, S('\'', '('), S('\'', 0)};
static const uint32_t __string_413[] = {3, S('\'', '<'), S('\'', 0)};
static const uint32_t __string_414[] = {4, S('\'', '<'), S('=', '\'')};
static const uint32_t __string_415[] = {4, S('\'', '&'), S('&', '\'')};
static const uint32_t __string_416[] = {4, S('\'', '|'), S('|', '\'')};
static const uint32_t __string_417[] = {3, S('\'', '-'), S('\'', 0)};
static const uint32_t __string_418[] = {4, S('\'', '-'), S('-', '\'')};
static const uint32_t __string_419[] = {3, S('\'', '*'), S('\'', 0)};
static const uint32_t __string_420[] = {3, S('\'', '!'), S('\'', 0)};
static const uint32_t __string_421[] = {4, S('\'', '!'), S('=', '\'')};
static const uint32_t __string_422[] = {3, S('\'', '+'), S('\'', 0)};
static const uint32_t __string_423[] = {4, S('\'', '+'), S('+', '\'')};
static const uint32_t __string_424[] = {3, S('\'', '?'), S('\'', 0)};
static const uint32_t __string_425[] = {3, S('\'', '%'), S('\'', 0)};
static const uint32_t __string_426[] = {3, S('\'', '}'), S('\'', 0)};
static const uint32_t __string_427[] = {3, S('\'', ']'), S('\'', 0)};
static const uint32_t __string_428[] = {3, S('\'', ')'), S('\'', 0)};
static const uint32_t __string_429[] = {3, S('\'', ';'), S('\'', 0)};
static const uint32_t __string_430[] = {4, S('\'', '<'), S('<', '\'')};
static const uint32_t __string_431[] = {4, S('\'', '>'), S('>', '\'')};
static const uint32_t __string_432_alignof[] = {9, S('\'', 'a'), S('l', 'i'), S('g', 'n'), S('o', 'f'), S('\'', 0)};
static const uint32_t __string_433_as[] = {4, S('\'', 'a'), S('s', '\'')};
static const uint32_t __string_434_break[] = {7, S('\'', 'b'), S('r', 'e'), S('a', 'k'), S('\'', 0)};
static const uint32_t __string_435_class[] = {7, S('\'', 'c'), S('l', 'a'), S('s', 's'), S('\'', 0)};
static const uint32_t __string_436_const[] = {7, S('\'', 'c'), S('o', 'n'), S('s', 't'), S('\'', 0)};
static const uint32_t __string_437_continue[] = {10, S('\'', 'c'), S('o', 'n'), S('t', 'i'), S('n', 'u'), S('e', '\'')};
static const uint32_t __string_438_declare[] = {9, S('\'', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S('\'', 0)};
static const uint32_t __string_439_else[] = {6, S('\'', 'e'), S('l', 's'), S('e', '\'')};
static const uint32_t __string_440_enum[] = {6, S('\'', 'e'), S('n', 'u'), S('m', '\'')};
static const uint32_t __string_441_export[] = {8, S('\'', 'e'), S('x', 'p'), S('o', 'r'), S('t', '\'')};
static const uint32_t __string_442_extends[] = {9, S('\'', 'e'), S('x', 't'), S('e', 'n'), S('d', 's'), S('\'', 0)};
static const uint32_t __string_443_extern[] = {8, S('\'', 'e'), S('x', 't'), S('e', 'r'), S('n', '\'')};
static const uint32_t __string_444_false[] = {7, S('\'', 'f'), S('a', 'l'), S('s', 'e'), S('\'', 0)};
static const uint32_t __string_445_function[] = {10, S('\'', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', '\'')};
static const uint32_t __string_446_if[] = {4, S('\'', 'i'), S('f', '\'')};
static const uint32_t __string_447_implements[] = {12, S('\'', 'i'), S('m', 'p'), S('l', 'e'), S('m', 'e'), S('n', 't'), S('s', '\'')};
static const uint32_t __string_448_import[] = {8, S('\'', 'i'), S('m', 'p'), S('o', 'r'), S('t', '\'')};
static const uint32_t __string_449_interface[] = {11, S('\'', 'i'), S('n', 't'), S('e', 'r'), S('f', 'a'), S('c', 'e'), S('\'', 0)};
static const uint32_t __string_450_let[] = {5, S('\'', 'l'), S('e', 't'), S('\'', 0)};
static const uint32_t __string_451_new[] = {5, S('\'', 'n'), S('e', 'w'), S('\'', 0)};
static const uint32_t __string_452_null[] = {6, S('\'', 'n'), S('u', 'l'), S('l', '\'')};
static const uint32_t __string_453_operator[] = {10, S('\'', 'o'), S('p', 'e'), S('r', 'a'), S('t', 'o'), S('r', '\'')};
static const uint32_t __string_454_private[] = {9, S('\'', 'p'), S('r', 'i'), S('v', 'a'), S('t', 'e'), S('\'', 0)};
static const uint32_t __string_455_protected[] = {11, S('\'', 'p'), S('r', 'o'), S('t', 'e'), S('c', 't'), S('e', 'd'), S('\'', 0)};
static const uint32_t __string_456_public[] = {8, S('\'', 'p'), S('u', 'b'), S('l', 'i'), S('c', '\'')};
static const uint32_t __string_457_return[] = {8, S('\'', 'r'), S('e', 't'), S('u', 'r'), S('n', '\'')};
static const uint32_t __string_458_sizeof[] = {8, S('\'', 's'), S('i', 'z'), S('e', 'o'), S('f', '\'')};
static const uint32_t __string_459_static[] = {8, S('\'', 's'), S('t', 'a'), S('t', 'i'), S('c', '\'')};
static const uint32_t __string_460_this[] = {6, S('\'', 't'), S('h', 'i'), S('s', '\'')};
static const uint32_t __string_461_true[] = {6, S('\'', 't'), S('r', 'u'), S('e', '\'')};
static const uint32_t __string_462_unsafe[] = {8, S('\'', 'u'), S('n', 's'), S('a', 'f'), S('e', '\'')};
static const uint32_t __string_463_var[] = {5, S('\'', 'v'), S('a', 'r'), S('\'', 0)};
static const uint32_t __string_464_while[] = {7, S('\'', 'w'), S('h', 'i'), S('l', 'e'), S('\'', 0)};
static const uint32_t __string_465_define[] = {9, S('\'', '#'), S('d', 'e'), S('f', 'i'), S('n', 'e'), S('\'', 0)};
static const uint32_t __string_466_elif[] = {7, S('\'', '#'), S('e', 'l'), S('i', 'f'), S('\'', 0)};
static const uint32_t __string_467_else[] = {7, S('\'', '#'), S('e', 'l'), S('s', 'e'), S('\'', 0)};
static const uint32_t __string_468_endif[] = {8, S('\'', '#'), S('e', 'n'), S('d', 'i'), S('f', '\'')};
static const uint32_t __string_469_error[] = {8, S('\'', '#'), S('e', 'r'), S('r', 'o'), S('r', '\'')};
static const uint32_t __string_470_if[] = {5, S('\'', '#'), S('i', 'f'), S('\'', 0)};
static const uint32_t __string_471_newline[] = {7, S('n', 'e'), S('w', 'l'), S('i', 'n'), S('e', 0)};
static const uint32_t __string_472_undef[] = {8, S('\'', '#'), S('u', 'n'), S('d', 'e'), S('f', '\'')};
static const uint32_t __string_473_warning[] = {10, S('\'', '#'), S('w', 'a'), S('r', 'n'), S('i', 'n'), S('g', '\'')};
static const uint32_t __string_474_as[] = {2, S('a', 's')};
static const uint32_t __string_475_if[] = {2, S('i', 'f')};
static const uint32_t __string_476_let[] = {3, S('l', 'e'), S('t', 0)};
static const uint32_t __string_477_new[] = {3, S('n', 'e'), S('w', 0)};
static const uint32_t __string_478_var[] = {3, S('v', 'a'), S('r', 0)};
static const uint32_t __string_479_else[] = {4, S('e', 'l'), S('s', 'e')};
static const uint32_t __string_480_enum[] = {4, S('e', 'n'), S('u', 'm')};
static const uint32_t __string_481_null[] = {4, S('n', 'u'), S('l', 'l')};
static const uint32_t __string_482_this[] = {4, S('t', 'h'), S('i', 's')};
static const uint32_t __string_483_true[] = {4, S('t', 'r'), S('u', 'e')};
static const uint32_t __string_484_break[] = {5, S('b', 'r'), S('e', 'a'), S('k', 0)};
static const uint32_t __string_485_class[] = {5, S('c', 'l'), S('a', 's'), S('s', 0)};
static const uint32_t __string_486_const[] = {5, S('c', 'o'), S('n', 's'), S('t', 0)};
static const uint32_t __string_487_false[] = {5, S('f', 'a'), S('l', 's'), S('e', 0)};
static const uint32_t __string_488_while[] = {5, S('w', 'h'), S('i', 'l'), S('e', 0)};
static const uint32_t __string_489_export[] = {6, S('e', 'x'), S('p', 'o'), S('r', 't')};
static const uint32_t __string_490_extern[] = {6, S('e', 'x'), S('t', 'e'), S('r', 'n')};
static const uint32_t __string_491_import[] = {6, S('i', 'm'), S('p', 'o'), S('r', 't')};
static const uint32_t __string_492_public[] = {6, S('p', 'u'), S('b', 'l'), S('i', 'c')};
static const uint32_t __string_493_return[] = {6, S('r', 'e'), S('t', 'u'), S('r', 'n')};
static const uint32_t __string_494_sizeof[] = {6, S('s', 'i'), S('z', 'e'), S('o', 'f')};
static const uint32_t __string_495_static[] = {6, S('s', 't'), S('a', 't'), S('i', 'c')};
static const uint32_t __string_496_unsafe[] = {6, S('u', 'n'), S('s', 'a'), S('f', 'e')};
static const uint32_t __string_497_alignof[] = {7, S('a', 'l'), S('i', 'g'), S('n', 'o'), S('f', 0)};
static const uint32_t __string_498_declare[] = {7, S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', 0)};
static const uint32_t __string_499_extends[] = {7, S('e', 'x'), S('t', 'e'), S('n', 'd'), S('s', 0)};
static const uint32_t __string_500_private[] = {7, S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', 0)};
static const uint32_t __string_501_continue[] = {8, S('c', 'o'), S('n', 't'), S('i', 'n'), S('u', 'e')};
static const uint32_t __string_502_function[] = {8, S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n')};
static const uint32_t __string_503_implements[] = {10, S('i', 'm'), S('p', 'l'), S('e', 'm'), S('e', 'n'), S('t', 's')};
static const uint32_t __string_504_interface[] = {9, S('i', 'n'), S('t', 'e'), S('r', 'f'), S('a', 'c'), S('e', 0)};
static const uint32_t __string_505_protected[] = {9, S('p', 'r'), S('o', 't'), S('e', 'c'), S('t', 'e'), S('d', 0)};
static const uint32_t __string_506_Invalid_integer_literal[] = {26, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('i', 'n'), S('t', 'e'), S('g', 'e'), S('r', ' '), S('l', 'i'), S('t', 'e'), S('r',
  'a'), S('l', ':'), S(' ', '\'')};
static const uint32_t __string_507_Unterminated_character_literal[] = {30, S('U', 'n'), S('t', 'e'), S('r', 'm'), S('i', 'n'), S('a', 't'), S('e', 'd'), S(' ', 'c'), S('h', 'a'), S('r', 'a'), S('c', 't'), S('e',
  'r'), S(' ', 'l'), S('i', 't'), S('e', 'r'), S('a', 'l')};
static const uint32_t __string_508_Unterminated_template_literal[] = {29, S('U', 'n'), S('t', 'e'), S('r', 'm'), S('i', 'n'), S('a', 't'), S('e', 'd'), S(' ', 't'), S('e', 'm'), S('p', 'l'), S('a', 't'), S('e',
  ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', 0)};
static const uint32_t __string_509_Unterminated_string_literal[] = {27, S('U', 'n'), S('t', 'e'), S('r', 'm'), S('i', 'n'), S('a', 't'), S('e', 'd'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('l',
  'i'), S('t', 'e'), S('r', 'a'), S('l', 0)};
static const uint32_t __string_510_Unterminated_multi_line_comment[] = {31, S('U', 'n'), S('t', 'e'), S('r', 'm'), S('i', 'n'), S('a', 't'), S('e', 'd'), S(' ', 'm'), S('u', 'l'), S('t', 'i'), S('-', 'l'), S('i',
  'n'), S('e', ' '), S('c', 'o'), S('m', 'm'), S('e', 'n'), S('t', 0)};
static const uint32_t __string_511_Use_instead_of[] = {25, S('U', 's'), S('e', ' '), S('\'', '!'), S('=', '\''), S(' ', 'i'), S('n', 's'), S('t', 'e'), S('a', 'd'), S(' ', 'o'), S('f', ' '), S('\'',
  '!'), S('=', '='), S('\'', 0)};
static const uint32_t __string_512_Use_instead_of[] = {25, S('U', 's'), S('e', ' '), S('\'', '='), S('=', '\''), S(' ', 'i'), S('n', 's'), S('t', 'e'), S('a', 'd'), S(' ', 'o'), S('f', ' '), S('\'',
  '='), S('=', '='), S('\'', 0)};
static const uint32_t __string_513_define[] = {7, S('#', 'd'), S('e', 'f'), S('i', 'n'), S('e', 0)};
static const uint32_t __string_514_elif[] = {5, S('#', 'e'), S('l', 'i'), S('f', 0)};
static const uint32_t __string_515_else[] = {5, S('#', 'e'), S('l', 's'), S('e', 0)};
static const uint32_t __string_516_endif[] = {6, S('#', 'e'), S('n', 'd'), S('i', 'f')};
static const uint32_t __string_517_error[] = {6, S('#', 'e'), S('r', 'r'), S('o', 'r')};
static const uint32_t __string_518_if[] = {3, S('#', 'i'), S('f', 0)};
static const uint32_t __string_519_undef[] = {6, S('#', 'u'), S('n', 'd'), S('e', 'f')};
static const uint32_t __string_520_warning[] = {8, S('#', 'w'), S('a', 'r'), S('n', 'i'), S('n', 'g')};
static const uint32_t __string_521[] = {1, S('#', 0)};
static const uint32_t __string_522_Invalid_preprocessor_token[] = {28, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('p', 'r'), S('e', 'p'), S('r', 'o'), S('c', 'e'), S('s', 's'), S('o', 'r'), S(' ',
  't'), S('o', 'k'), S('e', 'n'), S(' ', '\'')};
static const uint32_t __string_523_ifdef[] = {6, S('#', 'i'), S('f', 'd'), S('e', 'f')};
static const uint32_t __string_524_did_you_mean_if[] = {21, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('#', 'i'), S('f', '\''), S('?', 0)};
static const uint32_t __string_525_elsif[] = {6, S('#', 'e'), S('l', 's'), S('i', 'f')};
static const uint32_t __string_526_elseif[] = {7, S('#', 'e'), S('l', 's'), S('e', 'i'), S('f', 0)};
static const uint32_t __string_527_did_you_mean_elif[] = {23, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('#', 'e'), S('l', 'i'), S('f',
  '\''), S('?', 0)};
static const uint32_t __string_528_end[] = {4, S('#', 'e'), S('n', 'd')};
static const uint32_t __string_529_did_you_mean_endif[] = {24, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('#', 'e'), S('n', 'd'), S('i',
  'f'), S('\'', '?')};
static const uint32_t __string_530_Expected_newline_before[] = {24, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 'n'), S('e', 'w'), S('l', 'i'), S('n', 'e'), S(' ', 'b'), S('e', 'f'), S('o',
  'r'), S('e', ' ')};
static const uint32_t __string_531_Syntax_error[] = {15, S('S', 'y'), S('n', 't'), S('a', 'x'), S(' ', 'e'), S('r', 'r'), S('o', 'r'), S(':', ' '), S('\'', 0)};
static const uint32_t __string_532_if_WASM_These_will_be_fi[] = {12490, S('\n', '#'), S('i', 'f'), S(' ', 'W'), S('A', 'S'), S('M', '\n'), S('\n', ' '), S(' ', '/'), S('/', ' '), S('T', 'h'), S('e', 's'), S('e',
  ' '), S('w', 'i'), S('l', 'l'), S(' ', 'b'), S('e', ' '), S('f', 'i'), S('l', 'l'), S('e', 'd'), S(' ', 'i'), S('n', ' '), S('b', 'y'), S(' ', 't'), S('h', 'e'), S(' ', 'W'), S('e', 'b'), S('A', 's'), S('s',
  'e'), S('m', 'b'), S('l', 'y'), S(' ', 'c'), S('o', 'd'), S('e', ' '), S('g', 'e'), S('n', 'e'), S('r', 'a'), S('t', 'o'), S('r', '\n'), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', 'v'), S('a',
  'r'), S(' ', 'c'), S('u', 'r'), S('r', 'e'), S('n', 't'), S('H', 'e'), S('a', 'p'), S('P', 'o'), S('i', 'n'), S('t', 'e'), S('r', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '='), S(' ', 'n'), S('u',
  'l'), S('l', ';'), S('\n', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('v', 'a'), S('r', ' '), S('o', 'r'), S('i', 'g'), S('i', 'n'), S('a', 'l'), S('H', 'e'), S('a', 'p'), S('P', 'o'), S('i',
  'n'), S('t', 'e'), S('r', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '='), S(' ', 'n'), S('u', 'l'), S('l', ';'), S('\n', '\n'), S(' ', ' '), S('e', 'x'), S('t', 'e'), S('r', 'n'), S(' ', 'u'), S('n',
  's'), S('a', 'f'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'm'), S('a', 'l'), S('l', 'o'), S('c', '('), S('s', 'i'), S('z', 'e'), S('O', 'f'), S(':', ' '), S('u', 'i'), S('n',
  't'), S(')', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('A', 'l'), S('i', 'g'), S('n', ' '), S('a', 'l'), S('l', ' '), S('a', 'l'), S('l',
  'o'), S('c', 'a'), S('t', 'i'), S('o', 'n'), S('s', ' '), S('t', 'o'), S(' ', '8'), S(' ', 'b'), S('y', 't'), S('e', 's'), S('\n', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'o'), S('f', 'f'), S('s',
  'e'), S('t', ' '), S('=', ' '), S('(', '('), S('c', 'u'), S('r', 'r'), S('e', 'n'), S('t', 'H'), S('e', 'a'), S('p', 'P'), S('o', 'i'), S('n', 't'), S('e', 'r'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n',
  't'), S(' ', '+'), S(' ', '7'), S(')', ' '), S('&', ' '), S('~', '7'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(')', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(';', '\n'), S(' ',
  ' '), S(' ', ' '), S('s', 'i'), S('z', 'e'), S('O', 'f'), S(' ', '='), S(' ', '('), S('s', 'i'), S('z', 'e'), S('O', 'f'), S(' ', '+'), S(' ', '7'), S(')', ' '), S('&', ' '), S('~', '7'), S(' ', 'a'), S('s',
  ' '), S('u', 'i'), S('n', 't'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('U', 's'), S('e', ' '), S('a', ' '), S('s', 'i'), S('m', 'p'), S('l', 'e'), S(' ', 'b'), S('u', 'm'), S('p',
  ' '), S('a', 'l'), S('l', 'o'), S('c', 'a'), S('t', 'o'), S('r', ' '), S('f', 'o'), S('r', ' '), S('n', 'o'), S('w', '\n'), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('l', 'i'), S('m', 'i'), S('t',
  ' '), S('=', ' '), S('o', 'f'), S('f', 's'), S('e', 't'), S(' ', '+'), S(' ', 's'), S('i', 'z'), S('e', 'O'), S('f', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'c'), S('u', 'r'), S('r', 'e'), S('n', 't'), S('H',
  'e'), S('a', 'p'), S('P', 'o'), S('i', 'n'), S('t', 'e'), S('r', ' '), S('=', ' '), S('l', 'i'), S('m', 'i'), S('t', ';'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'M'), S('a', 'k'), S('e',
  ' '), S('s', 'u'), S('r', 'e'), S(' ', 't'), S('h', 'e'), S(' ', 'm'), S('e', 'm'), S('o', 'r'), S('y', ' '), S('s', 't'), S('a', 'r'), S('t', 's'), S(' ', 'o'), S('f', 'f'), S(' ', 'a'), S('t', ' '), S('z',
  'e'), S('r', 'o'), S('\n', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'p'), S('t', 'r'), S(' ', '='), S(' ', 'o'), S('f', 'f'), S('s', 'e'), S('t', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'w'), S('h',
  'i'), S('l', 'e'), S(' ', '('), S('p', 't'), S('r', ' '), S('<', ' '), S('l', 'i'), S('m', 'i'), S('t', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('(', 'p'), S('t', 'r'), S(' ',
  'a'), S('s', ' '), S('*', 'i'), S('n', 't'), S(')', ' '), S('=', ' '), S('0', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'p'), S('t', 'r'), S(' ', '='), S(' ', 'p'), S('t', 'r'), S(' ', '+'), S(' ',
  '4'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('o', 'f'), S('f', 's'), S('e', 't'), S(';', '\n'), S(' ', ' '), S('}',
  '\n'), S('\n', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'p'), S('y', '('), S('t', 'a'), S('r', 'g'), S('e',
  't'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ','), S(' ', 's'), S('o', 'u'), S('r', 'c'), S('e', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(',', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(':',
  ' '), S('u', 'i'), S('n', 't'), S(')', ':'), S(' ', 'v'), S('o', 'i'), S('d', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'N'), S('o', '-'), S('o', 'p'), S(' ', 'i'), S('f', ' '), S('e',
  'i'), S('t', 'h'), S('e', 'r'), S(' ', 'o'), S('f', ' '), S('t', 'h'), S('e', ' '), S('i', 'n'), S('p', 'u'), S('t', 's'), S(' ', 'a'), S('r', 'e'), S(' ', 'n'), S('u', 'l'), S('l', '\n'), S(' ', ' '), S(' ',
  ' '), S('i', 'f'), S(' ', '('), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', '='), S('=', ' '), S('n', 'u'), S('l', 'l'), S(' ', '|'), S('|', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '='), S('=',
  ' '), S('n', 'u'), S('l', 'l'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ',
  ' '), S(' ', '/'), S('/', ' '), S('O', 'p'), S('t', 'i'), S('m', 'i'), S('z', 'e'), S('d', ' '), S('a', 'l'), S('i', 'g'), S('n', 'e'), S('d', ' '), S('c', 'o'), S('p', 'y'), S('\n', ' '), S(' ', ' '), S(' ',
  'i'), S('f', ' '), S('(', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('>', '='), S(' ', '1'), S('6', ' '), S('&', '&'), S(' ', '('), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', 'a'), S('s', ' '), S('u',
  'i'), S('n', 't'), S(')', ' '), S('%', ' '), S('4', ' '), S('=', '='), S(' ', '('), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(')', ' '), S('%', ' '), S('4',
  ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('P', 'i'), S('c', 'k'), S(' ', 'o'), S('f', 'f'), S(' ', 't'), S('h', 'e'), S(' ', 'b'), S('e', 'g'), S('i', 'n'), S('n',
  'i'), S('n', 'g'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('(', 't'), S('a', 'r'), S('g', 'e'), S('t', ' '), S('a', 's'), S(' ', 'u'), S('i', 'n'), S('t',
  ')'), S(' ', '%'), S(' ', '4'), S(' ', '!'), S('=', ' '), S('0', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '='), S(' ',
  '*'), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '='), S(' ', 't'), S('a', 'r'), S('g', 'e'), S('t',
  ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 's'), S('o', 'u'), S('r', 'c'), S('e', ' '), S('=', ' '), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', '+'), S(' ',
  '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('-', ' '), S('1', ';'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'P'), S('i', 'c'), S('k', ' '), S('o', 'f'), S('f', ' '), S('t', 'h'), S('e', ' '), S('e',
  'n'), S('d', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('w', 'h'), S('i', 'l'), S('e', ' '), S('(', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('%', ' '), S('4', ' '), S('!', '='), S(' ', '0'), S(')',
  ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('-', ' '), S('1', ';'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('(', 't'), S('a', 'r'), S('g', 'e'), S('t', ' '), S('+', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(')', ' '), S('=', ' '), S('*', '('), S('s',
  'o'), S('u', 'r'), S('c', 'e'), S(' ', '+'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  '/'), S('/', ' '), S('Z', 'i'), S('p', ' '), S('o', 'v'), S('e', 'r'), S(' ', 't'), S('h', 'e'), S(' ', 'm'), S('i', 'd'), S('d', 'l'), S('e', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r',
  ' '), S('e', 'n'), S('d', ' '), S('=', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '+'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'w'), S('h',
  'i'), S('l', 'e'), S(' ', '('), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '<'), S(' ', 'e'), S('n', 'd'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('*', '('), S('t',
  'a'), S('r', 'g'), S('e', 't'), S(' ', 'a'), S('s', ' '), S('*', 'i'), S('n', 't'), S(')', ' '), S('=', ' '), S('*', '('), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', 'a'), S('s', ' '), S('*', 'i'), S('n',
  't'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 't'), S('a', 'r'), S('g', 'e'), S('t', ' '), S('=', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '+'), S(' ', '4'), S(';',
  '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', '='), S(' ', 's'), S('o', 'u'), S('r', 'c'), S('e', ' '), S('+', ' '), S('4', ';'), S('\n', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'S'), S('l', 'o'), S('w', ' '), S('u', 'n'), S('a', 'l'), S('i', 'g'), S('n',
  'e'), S('d', ' '), S('c', 'o'), S('p', 'y'), S('\n', ' '), S(' ', ' '), S(' ', 'e'), S('l', 's'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('e', 'n'), S('d',
  ' '), S('=', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '+'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ',
  '('), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '<'), S(' ', 'e'), S('n', 'd'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('*', 't'), S('a', 'r'), S('g', 'e'), S('t',
  ' '), S('=', ' '), S('*', 's'), S('o', 'u'), S('r', 'c'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 't'), S('a', 'r'), S('g', 'e'), S('t', ' '), S('=', ' '), S('t', 'a'), S('r',
  'g'), S('e', 't'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', '='), S(' ', 's'), S('o', 'u'), S('r', 'c'), S('e',
  ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f',
  'e'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('m', 'e'), S('m', 'c'), S('m', 'p'), S('(', 'a'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ','), S(' ', 'b'), S(':', ' '), S('*',
  'b'), S('y', 't'), S('e', ','), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ':'), S(' ', 'u'), S('i', 'n'), S('t', ')'), S(':', ' '), S('i', 'n'), S('t', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('/',
  '/'), S(' ', 'N'), S('o', '-'), S('o', 'p'), S(' ', 'i'), S('f', ' '), S('e', 'i'), S('t', 'h'), S('e', 'r'), S(' ', 'o'), S('f', ' '), S('t', 'h'), S('e', ' '), S('i', 'n'), S('p', 'u'), S('t', 's'), S(' ',
  'a'), S('r', 'e'), S(' ', 'n'), S('u', 'l'), S('l', '\n'), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('a', ' '), S('=', '='), S(' ', 'n'), S('u', 'l'), S('l', ' '), S('|', '|'), S(' ', 'b'), S(' ',
  '='), S('=', ' '), S('n', 'u'), S('l', 'l'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}',
  '\n'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('R', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('h', 'e'), S(' ', 'f'), S('i', 'r'), S('s', 't'), S(' ', 'n'), S('o', 'n'), S('-', 'z'), S('e',
  'r'), S('o', ' '), S('d', 'i'), S('f', 'f'), S('e', 'r'), S('e', 'n'), S('c', 'e'), S('\n', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ',
  '>'), S(' ', '0'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('d', 'e'), S('l', 't'), S('a', ' '), S('=', ' '), S('*', 'a'), S(' ', 'a'), S('s', ' '), S('i',
  'n'), S('t', ' '), S('-', ' '), S('*', 'b'), S(' ', 'a'), S('s', ' '), S('i', 'n'), S('t', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 'd'), S('e', 'l'), S('t', 'a'), S(' ',
  '!'), S('=', ' '), S('0', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('d', 'e'), S('l', 't'), S('a', ';'), S('\n', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'a'), S(' ', '='), S(' ', 'a'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('b', ' '), S('=',
  ' '), S('b', ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('=', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '-'), S(' ',
  '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('B', 'o'), S('t', 'h'), S(' ', 'i'), S('n', 'p'), S('u', 't'), S('s', ' '), S('a', 'r'), S('e',
  ' '), S('i', 'd'), S('e', 'n'), S('t', 'i'), S('c', 'a'), S('l', '\n'), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '0'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', '#'), S('e',
  'l'), S('i', 'f'), S(' ', 'C'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n',
  ' '), S('m', 'a'), S('l', 'l'), S('o', 'c'), S('(', 's'), S('i', 'z'), S('e', 'O'), S('f', ':'), S(' ', 'u'), S('i', 'n'), S('t', ')'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ';'), S('\n', ' '), S(' ',
  'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'p'), S('y', '('), S('t',
  'a'), S('r', 'g'), S('e', 't'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ','), S(' ', 's'), S('o', 'u'), S('r', 'c'), S('e', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(',', ' '), S('l', 'e'), S('n',
  'g'), S('t', 'h'), S(':', ' '), S('u', 'i'), S('n', 't'), S(')', ':'), S(' ', 'v'), S('o', 'i'), S('d', ';'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'u'), S('n', 's'), S('a',
  'f'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'm'), S('p', '('), S('a', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(',', ' '), S('b', ':'), S(' ',
  '*'), S('b', 'y'), S('t', 'e'), S(',', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(':', ' '), S('u', 'i'), S('n', 't'), S(')', ':'), S(' ', 'i'), S('n', 't'), S(';', '\n'), S('\n', '#'), S('e', 'n'), S('d',
  'i'), S('f', '\n'), S('\n', '#'), S('i', 'f'), S(' ', 'W'), S('A', 'S'), S('M', ' '), S('|', '|'), S(' ', 'C'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a',
  's'), S('s', ' '), S('b', 'o'), S('o', 'l'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g',
  ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('h', 'i'), S('s', ' '), S('?', ' '), S('"', 't'), S('r', 'u'), S('e', '"'), S(' ', ':'), S(' ',
  '"'), S('f', 'a'), S('l', 's'), S('e', '"'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l',
  'a'), S('s', 's'), S(' ', 's'), S('b', 'y'), S('t', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i',
  'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('i', 'n'), S('t', ')'), S('.',
  't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e',
  ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('b', 'y'), S('t', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t',
  'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n',
  't'), S(')', '.'), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l',
  'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')',
  ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s',
  ' '), S('i', 'n'), S('t', ')'), S('.', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d',
  'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i',
  'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '('), S('t', 'h'), S('i',
  's'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(')', '.'), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}',
  '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 'i'), S('n', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t',
  'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'S'), S('p', 'e'), S('c', 'i'), S('a',
  'l'), S('-', 'c'), S('a', 's'), S('e', ' '), S('t', 'h'), S('i', 's'), S(' ', 't'), S('o', ' '), S('k', 'e'), S('e', 'p'), S(' ', 't'), S('h', 'e'), S(' ', 'r'), S('e', 's'), S('t', ' '), S('o', 'f'), S(' ',
  't'), S('h', 'e'), S(' ', 'c'), S('o', 'd'), S('e', ' '), S('s', 'i'), S('m', 'p'), S('l', 'e'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 't'), S('h', 'i'), S('s', ' '), S('=',
  '='), S(' ', '-'), S('2', '1'), S('4', '7'), S('4', '8'), S('3', '6'), S('4', '8'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ',
  '"'), S('-', '2'), S('1', '4'), S('7', '4'), S('8', '3'), S('6', '4'), S('8', '"'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '/'), S('/',
  ' '), S('T', 'r'), S('e', 'a'), S('t', ' '), S('t', 'h'), S('i', 's'), S(' ', 'l'), S('i', 'k'), S('e', ' '), S('a', 'n'), S(' ', 'u'), S('n', 's'), S('i', 'g'), S('n', 'e'), S('d', ' '), S('i', 'n'), S('t',
  'e'), S('g', 'e'), S('r', ' '), S('p', 'r'), S('e', 'f'), S('i', 'x'), S('e', 'd'), S(' ', 'b'), S('y', ' '), S('\'', '-'), S('\'', ' '), S('i', 'f'), S(' ', 'i'), S('t', '\''), S('s', ' '), S('n', 'e'), S('g',
  'a'), S('t', 'i'), S('v', 'e'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('i', 'n'), S('t', 'e'), S('r', 'n'), S('a', 'l'), S('I', 'n'), S('t', 'T'), S('o',
  'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S('(', 't'), S('h', 'i'), S('s', ' '), S('<', ' '), S('0', ' '), S('?', ' '), S('-', 't'), S('h', 'i'), S('s', ' '), S(':', ' '), S('t', 'h'), S('i', 's'), S(')',
  ' '), S('a', 's'), S(' ', 'u'), S('i', 'n'), S('t', ','), S(' ', 't'), S('h', 'i'), S('s', ' '), S('<', ' '), S('0', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}', '\n'), S('\n',
  ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 'u'), S('i', 'n'), S('t', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('t', 'o'), S('S', 't'), S('r',
  'i'), S('n', 'g'), S('(', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('i', 'n'), S('t',
  'e'), S('r', 'n'), S('a', 'l'), S('I', 'n'), S('t', 'T'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S('t', 'h'), S('i', 's'), S(',', ' '), S('f', 'a'), S('l', 's'), S('e', ')'), S(';', '\n'), S(' ',
  ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('i', 'n'), S('t', 'e'), S('r', 'n'), S('a', 'l'), S('I', 'n'), S('t',
  'T'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S('v', 'a'), S('l', 'u'), S('e', ':'), S(' ', 'u'), S('i', 'n'), S('t', ','), S(' ', 's'), S('i', 'g'), S('n', ':'), S(' ', 'b'), S('o', 'o'), S('l',
  ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('A', 'v'), S('o', 'i'), S('d', ' '), S('a', 'l'), S('l', 'o'), S('c', 'a'), S('t',
  'i'), S('o', 'n'), S(' ', 'f'), S('o', 'r'), S(' ', 'c'), S('o', 'm'), S('m', 'o'), S('n', ' '), S('c', 'a'), S('s', 'e'), S('s', '\n'), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('v', 'a'), S('l',
  'u'), S('e', ' '), S('=', '='), S(' ', '0'), S(')', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '"'), S('0', '"'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('v', 'a'), S('l',
  'u'), S('e', ' '), S('=', '='), S(' ', '1'), S(')', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 's'), S('i', 'g'), S('n', ' '), S('?', ' '), S('"', '-'), S('1', '"'), S(' ', ':'), S(' ', '"'), S('1',
  '"'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'D'), S('e', 't'), S('e', 'r'), S('m',
  'i'), S('n', 'e'), S(' ', 'h'), S('o', 'w'), S(' ', 'm'), S('a', 'n'), S('y', ' '), S('d', 'i'), S('g', 'i'), S('t', 's'), S(' ', 'w'), S('e', ' '), S('n', 'e'), S('e', 'd'), S('\n', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('=', ' '), S('(', '('), S('s', 'i'), S('g', 'n'), S(' ', '?'), S(' ', '1'), S(' ', ':'), S(' ', '0'), S(')', ' '), S('+',
  ' '), S('(', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('>', '='), S(' ', '1'), S('0', '0'), S('0', '0'), S('0', '0'), S('0', '0'), S(' ', '?'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'l'), S('u', 'e'), S(' ', '>'), S('=', ' '), S('1', '0'), S('0', '0'), S('0', '0'), S('0', '0'), S('0', '0'), S(' ', '?'), S(' ',
  '1'), S('0', ' '), S(':', ' '), S('9', ' '), S(':', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('>', '='), S(' ', '1'), S('0', '0'), S('0', '0'), S(' ',
  '?'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'l'), S('u', 'e'), S(' ', '>'), S('=', ' '), S('1', '0'), S('0', '0'), S('0', '0'), S('0', ' '), S('?', '\n'), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('>', '='), S(' ', '1'), S('0', '0'), S('0', '0'), S('0', '0'), S('0', ' '), S('?', ' '), S('8',
  ' '), S(':', ' '), S('7', ' '), S(':', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('>', '='), S(' ', '1'), S('0', '0'), S('0',
  '0'), S('0', ' '), S('?', ' '), S('6', ' '), S(':', ' '), S('5', ' '), S(':', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('>', '='), S(' ',
  '1'), S('0', '0'), S(' ', '?'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'l'), S('u', 'e'), S(' ', '>'), S('=', ' '), S('1', '0'), S('0', '0'), S(' ',
  '?'), S(' ', '4'), S(' ', ':'), S(' ', '3'), S(' ', ':'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'l'), S('u', 'e'), S(' ', '>'), S('=', ' '), S('1',
  '0'), S(' ', '?'), S(' ', '2'), S(' ', ':'), S(' ', '1'), S(')', ')'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ',
  'p'), S('t', 'r'), S(' ', '='), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', '_'), S('n', 'e'), S('w', '('), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(')', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t',
  'e'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('e', 'n'), S('d', ' '), S('=', ' '), S('p', 't'), S('r', ' '), S('+', ' '), S('4', ' '), S('+', ' '), S('l', 'e'), S('n',
  'g'), S('t', 'h'), S(' ', '*'), S(' ', '2'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 's'), S('i', 'g'), S('n', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', '*'), S('(', '('), S('p', 't'), S('r', ' '), S('+', ' '), S('4', ')'), S(' ', 'a'), S('s', ' '), S('*', 'u'), S('s', 'h'), S('o', 'r'), S('t', ')'), S(' ', '='), S(' ', '\''), S('-',
  '\''), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('v', 'a'), S('l', 'u'), S('e', ' '), S('!',
  '='), S(' ', '0'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('e', 'n'), S('d', ' '), S('=', ' '), S('e', 'n'), S('d', ' '), S('+', ' '), S('-', '2'), S(';', '\n'), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('*', '('), S('e', 'n'), S('d', ' '), S('a', 's'), S(' ', '*'), S('u', 's'), S('h', 'o'), S('r', 't'), S(')', ' '), S('=', ' '), S('(', 'v'), S('a', 'l'), S('u',
  'e'), S(' ', '%'), S(' ', '1'), S('0', ' '), S('+', ' '), S('\'', '0'), S('\'', ')'), S(' ', 'a'), S('s', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('=', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('/', ' '), S('1', '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('p', 't'), S('r', ' '), S('a', 's'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n',
  ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', '_'), S('n', 'e'), S('w', '('), S('l', 'e'), S('n', 'g'), S('t',
  'h'), S(':', ' '), S('u', 'i'), S('n', 't'), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', '{'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'p'), S('t', 'r'), S(' ', '='), S(' ', 'm'), S('a', 'l'), S('l', 'o'), S('c', '('), S('4', ' '), S('+', ' '), S('l', 'e'), S('n', 'g'), S('t',
  'h'), S(' ', '*'), S(' ', '2'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('(', 'p'), S('t', 'r'), S(' ', 'a'), S('s', ' '), S('*', 'u'), S('i', 'n'), S('t', ')'), S(' ', '='), S(' ',
  'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('p', 't'), S('r', ' '), S('a', 's'), S(' ', 's'), S('t', 'r'), S('i',
  'n'), S('g', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('s',
  't'), S('r', 'i'), S('n', 'g'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 'c'), S('h', 'a'), S('r', 'A'), S('t', '('), S('i', 'n'), S('d', 'e'), S('x', ':'), S(' ', 'i'), S('n', 't'), S(')', ':'), S(' ',
  's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('h', 'i'), S('s', '.'), S('s', 'l'), S('i', 'c'), S('e',
  '('), S('i', 'n'), S('d', 'e'), S('x', ','), S(' ', 'i'), S('n', 'd'), S('e', 'x'), S(' ', '+'), S(' ', '1'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('c',
  'h'), S('a', 'r'), S('C', 'o'), S('d', 'e'), S('A', 't'), S('(', 'i'), S('n', 'd'), S('e', 'x'), S(':', ' '), S('i', 'n'), S('t', ')'), S(':', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('t', 'h'), S('i', 's'), S('[', 'i'), S('n', 'd'), S('e', 'x'), S(']', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n',
  '\n'), S(' ', ' '), S(' ', ' '), S('g', 'e'), S('t', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S('(', ')'), S(':', ' '), S('i', 'n'), S('t', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('u',
  'n'), S('s', 'a'), S('f', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('*', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s',
  ' '), S('*', 'i'), S('n', 't'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('o', 'p'), S('e', 'r'), S('a',
  't'), S('o', 'r'), S(' ', '['), S(']', ' '), S('(', 'i'), S('n', 'd'), S('e', 'x'), S(':', ' '), S('i', 'n'), S('t', ')'), S(':', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S('\n', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 'i'), S('n', 'd'), S('e', 'x'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(' ', '<'), S(' ', 't'), S('h', 'i'), S('s', '.'), S('l', 'e'), S('n',
  'g'), S('t', 'h'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', '{'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('*', '('), S('(', 't'), S('h', 'i'), S('s', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t',
  'e'), S(' ', '+'), S(' ', '4'), S(' ', '+'), S(' ', 'i'), S('n', 'd'), S('e', 'x'), S(' ', '*'), S(' ', '2'), S(')', ' '), S('a', 's'), S(' ', '*'), S('u', 's'), S('h', 'o'), S('r', 't'), S(')', ';'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('0',
  ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '='), S('=', ' '), S('(', 'o'), S('t', 'h'), S('e', 'r'), S(':',
  ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'b'), S('o', 'o'), S('l', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', '{'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 't'), S('h', 'i'), S('s', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '='), S('=', ' '), S('o', 't'), S('h',
  'e'), S('r', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(')', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('r', 'u'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', 'i'), S('f', ' '), S('(', 't'), S('h', 'i'), S('s', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '='), S('=', ' '), S('n', 'u'), S('l', 'l'), S(' ', '|'), S('|', ' '), S('o',
  't'), S('h', 'e'), S('r', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '='), S('=', ' '), S('n', 'u'), S('l', 'l'), S(')', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 'f'), S('a',
  'l'), S('s', 'e'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 't'), S('h', 'i'), S('s', '.'), S('l',
  'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '!'), S('=', ' '), S('o', 't'), S('h',
  'e'), S('r', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(')', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 'f'), S('a', 'l'), S('s', 'e'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'm'), S('p', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4',
  ','), S(' ', 'o'), S('t', 'h'), S('e', 'r'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ','), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('a', 's'), S(' ',
  'u'), S('i', 'n'), S('t', ' '), S('*', ' '), S('2', ')'), S(' ', '='), S('=', ' '), S('0', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ',
  ' '), S(' ', ' '), S('s', 'l'), S('i', 'c'), S('e', '('), S('s', 't'), S('a', 'r'), S('t', ':'), S(' ', 'i'), S('n', 't'), S(',', ' '), S('e', 'n'), S('d', ':'), S(' ', 'i'), S('n', 't'), S(')', ':'), S(' ',
  's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 't'), S('h', 'i'), S('s',
  '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 's'), S('t', 'a'), S('r', 't'), S(' ', '<'), S(' ', '0'), S(')', ' '), S('s',
  't'), S('a', 'r'), S('t', ' '), S('=', ' '), S('s', 't'), S('a', 'r'), S('t', ' '), S('+', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ',
  '('), S('e', 'n'), S('d', ' '), S('<', ' '), S('0', ')'), S(' ', 'e'), S('n', 'd'), S(' ', '='), S(' ', 'e'), S('n', 'd'), S(' ', '+'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', '\n'), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('s', 't'), S('a', 'r'), S('t', ' '), S('<', ' '), S('0', ')'), S(' ', 's'), S('t', 'a'), S('r', 't'), S(' ', '='), S(' ', '0'), S(';', '\n'), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S('e', 'l'), S('s', 'e'), S(' ', 'i'), S('f', ' '), S('(', 's'), S('t', 'a'), S('r', 't'), S(' ', '>'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', 's'), S('t',
  'a'), S('r', 't'), S(' ', '='), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('e', 'n'), S('d', ' '), S('<', ' '), S('s',
  't'), S('a', 'r'), S('t', ')'), S(' ', 'e'), S('n', 'd'), S(' ', '='), S(' ', 's'), S('t', 'a'), S('r', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('e', 'l'), S('s', 'e'), S(' ', 'i'), S('f',
  ' '), S('(', 'e'), S('n', 'd'), S(' ', '>'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', 'e'), S('n', 'd'), S(' ', '='), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', '\n'), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'r'), S('a', 'n'), S('g', 'e'), S(' ',
  '='), S(' ', '('), S('e', 'n'), S('d', ' '), S('-', ' '), S('s', 't'), S('a', 'r'), S('t', ')'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S('v', 'a'), S('r', ' '), S('p', 't'), S('r', ' '), S('=', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S('_', 'n'), S('e', 'w'), S('(', 'r'), S('a', 'n'), S('g', 'e'), S(')', ';'), S('\n', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', 'm'), S('e', 'm'), S('c', 'p'), S('y', '('), S('p', 't'), S('r', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '+'), S(' ', '4'), S(',', ' '), S('t',
  'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ' '), S('+', ' '), S('s', 't'), S('a', 'r'), S('t', ' '), S('*', ' '), S('2', ','), S(' ', 'r'), S('a',
  'n'), S('g', 'e'), S(' ', '*'), S(' ', '2'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('p', 't'), S('r', ';'), S('\n', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('s', 't'), S('a', 'r'), S('t', 's'), S('W', 'i'), S('t', 'h'), S('(', 't'), S('e', 'x'), S('t',
  ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ')'), S(':', ' '), S('b', 'o'), S('o', 'l'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 't'), S('e', 'x'), S('t',
  'L'), S('e', 'n'), S('g', 't'), S('h', ' '), S('=', ' '), S('t', 'e'), S('x', 't'), S('.', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(',
  't'), S('h', 'i'), S('s', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '<'), S(' ', 't'), S('e', 'x'), S('t', 'L'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n',
  ' '), S('f', 'a'), S('l', 's'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r',
  'e'), S('t', 'u'), S('r', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'm'), S('p', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ','), S(' ',
  't'), S('e', 'x'), S('t', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '+'), S(' ', '4'), S(',', ' '), S('t', 'e'), S('x', 't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', 'a'), S('s',
  ' '), S('u', 'i'), S('n', 't'), S(' ', '*'), S(' ', '2'), S(')', ' '), S('=', '='), S(' ', '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n',
  ' '), S(' ', ' '), S(' ', 'e'), S('n', 'd'), S('s', 'W'), S('i', 't'), S('h', '('), S('t', 'e'), S('x', 't'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'b'), S('o', 'o'), S('l',
  ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('t', 'h'), S('i', 's'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 't'), S('h', 'i'), S('s', '.'), S('l',
  'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('t', 'e'), S('x', 't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 't'), S('e',
  'x'), S('t', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('t', 'h'), S('i', 's'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ',
  '<'), S(' ', 't'), S('e', 'x'), S('t', 'L'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('f', 'a'), S('l', 's'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'm'), S('p',
  '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ' '), S('+', ' '), S('(', 't'), S('h', 'i'), S('s', 'L'), S('e', 'n'), S('g', 't'), S('h',
  ' '), S('-', ' '), S('t', 'e'), S('x', 't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(')', ' '), S('*', ' '), S('2', ','), S(' ', 't'), S('e', 'x'), S('t', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t',
  'e'), S(' ', '+'), S(' ', '4'), S(',', ' '), S('t', 'e'), S('x', 't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(' ', '*'), S(' ', '2'), S(')', ' '), S('=',
  '='), S(' ', '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', 'i'), S('n', 'd'), S('e', 'x'), S('O', 'f'), S('(',
  't'), S('e', 'x'), S('t', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ')'), S(':', ' '), S('i', 'n'), S('t', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('t',
  'h'), S('i', 's'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 't'), S('h', 'i'), S('s', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v',
  'a'), S('r', ' '), S('t', 'e'), S('x', 't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 't'), S('e', 'x'), S('t', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('t', 'h'), S('i', 's'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '>'), S('=', ' '), S('t', 'e'), S('x', 't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(')',
  ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('i', ' '), S('=', ' '), S('0', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'w'), S('h',
  'i'), S('l', 'e'), S(' ', '('), S('i', ' '), S('<', ' '), S('t', 'h'), S('i', 's'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '-'), S(' ', 't'), S('e', 'x'), S('t', 'L'), S('e', 'n'), S('g', 't'), S('h',
  ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('m', 'e'), S('m', 'c'), S('m', 'p'), S('(', 't'), S('h', 'i'), S('s', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '+'), S(' ', '4'), S(' ',
  '+'), S(' ', 'i'), S(' ', '*'), S(' ', '2'), S(',', ' '), S('t', 'e'), S('x', 't'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ','), S(' ', 't'), S('e', 'x'), S('t',
  'L'), S('e', 'n'), S('g', 't'), S('h', ' '), S('a', 's'), S(' ', 'u'), S('i', 'n'), S('t', ' '), S('*', ' '), S('2', ')'), S(' ', '='), S('=', ' '), S('0', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('i', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S(' ', '='), S(' ', 'i'), S(' ', '+'), S(' ',
  '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r',
  'n'), S(' ', '-'), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('l', 'a'), S('s', 't'), S('I', 'n'), S('d', 'e'), S('x', 'O'), S('f', '('), S('t', 'e'), S('x',
  't'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'i'), S('n', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 't'), S('h', 'i'), S('s',
  'L'), S('e', 'n'), S('g', 't'), S('h', ' '), S('=', ' '), S('t', 'h'), S('i', 's'), S('.', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ',
  't'), S('e', 'x'), S('t', 'L'), S('e', 'n'), S('g', 't'), S('h', ' '), S('=', ' '), S('t', 'e'), S('x', 't'), S('.', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  'i'), S('f', ' '), S('(', 't'), S('h', 'i'), S('s', 'L'), S('e', 'n'), S('g', 't'), S('h', ' '), S('>', '='), S(' ', 't'), S('e', 'x'), S('t', 'L'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', '{'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'i'), S(' ', '='), S(' ', 't'), S('h', 'i'), S('s', 'L'), S('e', 'n'), S('g', 't'), S('h', ' '), S('-', ' '), S('t', 'e'), S('x',
  't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('w', 'h'), S('i', 'l'), S('e', ' '), S('(', 'i'), S(' ', '>'), S('=', ' '), S('0', ')'), S(' ',
  '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S('i', 'f'), S(' ', '('), S('m', 'e'), S('m', 'c'), S('m', 'p'), S('(', 't'), S('h', 'i'), S('s', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '+'), S(' ', '4'), S(' ', '+'), S(' ',
  'i'), S(' ', '*'), S(' ', '2'), S(',', ' '), S('t', 'e'), S('x', 't'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ','), S(' ', 't'), S('e', 'x'), S('t', 'L'), S('e',
  'n'), S('g', 't'), S('h', ' '), S('a', 's'), S(' ', 'u'), S('i', 'n'), S('t', ' '), S('*', ' '), S('2', ')'), S(' ', '='), S('=', ' '), S('0', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('i', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S(' ', '='), S(' ', 'i'), S(' ', '-'), S(' ', '1'), S(';',
  '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ',
  '-'), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S('#', 'e'), S('l', 's'), S('e', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ',
  'c'), S('l', 'a'), S('s', 's'), S(' ', 'b'), S('o', 'o'), S('l', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(':', ' '), S('s', 't'), S('r',
  'i'), S('n', 'g'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 's'), S('b', 'y'), S('t', 'e'), S(' ',
  '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ',
  ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('b', 'y'), S('t', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i',
  'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a',
  's'), S('s', ' '), S('s', 'h'), S('o', 'r'), S('t', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n',
  'g'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 'u'), S('s', 'h'), S('o', 'r'), S('t', ' '), S('{',
  '\n'), S(' ', ' '), S(' ', ' '), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ',
  'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 'i'), S('n', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g',
  '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s',
  ' '), S('u', 'i'), S('n', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n',
  ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(' ', '{'), S('\n', ' '), S(' ',
  ' '), S(' ', 'c'), S('h', 'a'), S('r', 'A'), S('t', '('), S('i', 'n'), S('d', 'e'), S('x', ':'), S(' ', 'i'), S('n', 't'), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', ' '), S(' ',
  ' '), S(' ', 'c'), S('h', 'a'), S('r', 'C'), S('o', 'd'), S('e', 'A'), S('t', '('), S('i', 'n'), S('d', 'e'), S('x', ':'), S(' ', 'i'), S('n', 't'), S(')', ':'), S(' ', 'u'), S('s', 'h'), S('o', 'r'), S('t',
  ';'), S('\n', ' '), S(' ', ' '), S(' ', 'g'), S('e', 't'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', '('), S(')', ':'), S(' ', 'i'), S('n', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('i', 'n'), S('d',
  'e'), S('x', 'O'), S('f', '('), S('t', 'e'), S('x', 't'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'i'), S('n', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('l', 'a'), S('s',
  't'), S('I', 'n'), S('d', 'e'), S('x', 'O'), S('f', '('), S('t', 'e'), S('x', 't'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'i'), S('n', 't'), S(';', '\n'), S(' ', ' '), S(' ',
  ' '), S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '='), S('=', ' '), S('(', 'o'), S('t', 'h'), S('e', 'r'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'b'), S('o',
  'o'), S('l', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'o'), S('p', 'e'), S('r', 'a'), S('t', 'o'), S('r', ' '), S('[', ']'), S(' ', '('), S('i', 'n'), S('d', 'e'), S('x', ':'), S(' ', 'i'), S('n', 't'), S(')',
  ':'), S(' ', 'u'), S('s', 'h'), S('o', 'r'), S('t', ' '), S('{', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('h', 'i'), S('s', '.'), S('c', 'h'), S('a', 'r'), S('C', 'o'), S('d', 'e'), S('A',
  't'), S('(', 'i'), S('n', 'd'), S('e', 'x'), S(')', ';'), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', 's'), S('l', 'i'), S('c', 'e'), S('(', 's'), S('t', 'a'), S('r', 't'), S(':', ' '), S('i', 'n'), S('t',
  ','), S(' ', 'e'), S('n', 'd'), S(':', ' '), S('i', 'n'), S('t', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', '#'), S('i', 'f'), S(' ', 'J'), S('S',
  '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('s', 't'), S('a', 'r'), S('t', 's'), S('W', 'i'), S('t', 'h'), S('(', 't'), S('e', 'x'), S('t', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ')'), S(':',
  ' '), S('b', 'o'), S('o', 'l'), S(' ', '{'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('t', 'h'), S('i', 's'), S('.', 's'), S('l', 'i'), S('c', 'e'), S('(', '0'), S(',', ' '), S('t', 'e'), S('x',
  't'), S('.', 'l'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', '='), S('=', ' '), S('t', 'e'), S('x', 't'), S(';', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('e', 'n'), S('d', 's'), S('W',
  'i'), S('t', 'h'), S('(', 't'), S('e', 'x'), S('t', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ')'), S(':', ' '), S('b', 'o'), S('o', 'l'), S(' ', '{'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n',
  ' '), S('t', 'h'), S('i', 's'), S('.', 's'), S('l', 'i'), S('c', 'e'), S('(', '-'), S('t', 'e'), S('x', 't'), S('.', 'l'), S('e', 'n'), S('g', 't'), S('h', ','), S(' ', 't'), S('h', 'i'), S('s', '.'), S('l',
  'e'), S('n', 'g'), S('t', 'h'), S(')', ' '), S('=', '='), S(' ', 't'), S('e', 'x'), S('t', ';'), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '#'), S('e', 'l'), S('s', 'e'), S('\n', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', 's'), S('t', 'a'), S('r', 't'), S('s', 'W'), S('i', 't'), S('h', '('), S('t', 'e'), S('x', 't'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'b'), S('o', 'o'), S('l',
  ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'e'), S('n', 'd'), S('s', 'W'), S('i', 't'), S('h', '('), S('t', 'e'), S('x', 't'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ',
  'b'), S('o', 'o'), S('l', ';'), S('\n', ' '), S(' ', ' '), S(' ', '#'), S('e', 'n'), S('d', 'i'), S('f', '\n'), S(' ', ' '), S('}', '\n'), S('\n', '#'), S('e', 'n'), S('d', 'i'), S('f', '\n'), S('\n', '#'), S('i',
  'f'), S(' ', 'C'), S('\n', '\n'), S(' ', ' '), S('e', 'x'), S('t', 'e'), S('r', 'n'), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'c'), S('s',
  't'), S('r', 'i'), S('n', 'g'), S('_', 't'), S('o', '_'), S('u', 't'), S('f', '1'), S('6', '('), S('u', 't'), S('f', '8'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ')'), S(':', ' '), S('s', 't'), S('r',
  'i'), S('n', 'g'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 'u'), S('t', 'f'), S('8', ' '), S('=', '='), S(' ', 'n'), S('u', 'l'), S('l', ')'), S(' ', '{'), S('\n', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('n', 'u'), S('l', 'l'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ',
  'u'), S('t', 'f'), S('1', '6'), S('_', 'l'), S('e', 'n'), S('g', 't'), S('h', ':'), S(' ', 'u'), S('i', 'n'), S('t', ' '), S('=', ' '), S('0', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ',
  'a'), S(':', ' '), S('b', 'y'), S('t', 'e'), S(',', ' '), S('b', ':'), S(' ', 'b'), S('y', 't'), S('e', ','), S(' ', 'c'), S(':', ' '), S('b', 'y'), S('t', 'e'), S(',', ' '), S('d', ':'), S(' ', 'b'), S('y',
  't'), S('e', ';'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'M'), S('e', 'a'), S('s', 'u'), S('r', 'e'), S(' ', 't'), S('e', 'x'), S('t', '\n'), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r',
  ' '), S('i', ':'), S(' ', 'u'), S('i', 'n'), S('t', ' '), S('=', ' '), S('0', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('(', 'a'), S(' ', '='), S(' ', '*'), S('(',
  'u'), S('t', 'f'), S('8', ' '), S('+', ' '), S('i', ')'), S(')', ' '), S('!', '='), S(' ', '\''), S('\\', '0'), S('\'', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S(' ', '='), S(' ',
  'i'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ':'), S(' ', 'u'), S('i', 'n'), S('t',
  ';'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'D'), S('e', 'c'), S('o', 'd'), S('e', ' '), S('U', 'T'), S('F', '-'), S('8', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i',
  'f'), S(' ', '('), S('(', 'b'), S(' ', '='), S(' ', '*'), S('(', 'u'), S('t', 'f'), S('8', ' '), S('+', ' '), S('i', ')'), S(')', ' '), S('!', '='), S(' ', '\''), S('\\', '0'), S('\'', ' '), S('&', '&'), S(' ',
  'a'), S(' ', '>'), S('=', ' '), S('0', 'x'), S('C', '0'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', ' '), S('=', ' '), S('i', ' '), S('+', ' '), S('1', ';'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', '('), S('c', ' '), S('=', ' '), S('*', '('), S('u', 't'), S('f', '8'), S(' ', '+'), S(' ', 'i'), S(')', ')'), S(' ', '!'), S('=',
  ' '), S('\'', '\\'), S('0', '\''), S(' ', '&'), S('&', ' '), S('a', ' '), S('>', '='), S(' ', '0'), S('x', 'E'), S('0', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  'i'), S(' ', '='), S(' ', 'i'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('(', 'd'), S(' ', '='), S(' ', '*'), S('(',
  'u'), S('t', 'f'), S('8', ' '), S('+', ' '), S('i', ')'), S(')', ' '), S('!', '='), S(' ', '\''), S('\\', '0'), S('\'', ' '), S('&', '&'), S(' ', 'a'), S(' ', '>'), S('=', ' '), S('0', 'x'), S('F', '0'), S(')',
  ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', ' '), S('=', ' '), S('i', ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n', 't'), S(' ', '='), S(' ', '('), S('(', 'a'), S(' ', '&'), S(' ', '0'), S('x', '0'), S('7', ')'), S(' ', '<'), S('<',
  ' '), S('1', '8'), S(')', ' '), S('|', ' '), S('(', '('), S('b', ' '), S('&', ' '), S('0', 'x'), S('3', 'F'), S(')', ' '), S('<', '<'), S(' ', '1'), S('2', ')'), S(' ', '|'), S(' ', '('), S('(', 'c'), S(' ',
  '&'), S(' ', '0'), S('x', '3'), S('F', ')'), S(' ', '<'), S('<', ' '), S('6', ')'), S(' ', '|'), S(' ', '('), S('d', ' '), S('&', ' '), S('0', 'x'), S('3', 'F'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S(' ', 'e'), S('l', 's'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('c', 'o'), S('d', 'e'), S('P',
  'o'), S('i', 'n'), S('t', ' '), S('=', ' '), S('(', '('), S('a', ' '), S('&', ' '), S('0', 'x'), S('0', 'F'), S(')', ' '), S('<', '<'), S(' ', '1'), S('2', ')'), S(' ', '|'), S(' ', '('), S('(', 'b'), S(' ',
  '&'), S(' ', '0'), S('x', '3'), S('F', ')'), S(' ', '<'), S('<', ' '), S('6', ')'), S(' ', '|'), S(' ', '('), S('c', ' '), S('&', ' '), S('0', 'x'), S('3', 'F'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S(' ', 'e'), S('l', 's'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('=', ' '), S('(', '('), S('a', ' '), S('&', ' '), S('0', 'x'), S('1', 'F'), S(')', ' '), S('<', '<'), S(' ', '6'), S(')',
  ' '), S('|', ' '), S('(', 'b'), S(' ', '&'), S(' ', '0'), S('x', '3'), S('F', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}',
  ' '), S('e', 'l'), S('s', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n', 't'), S(' ', '='), S(' ', 'a'), S(';', '\n'), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('E', 'n'), S('c', 'o'), S('d', 'e'), S(' ', 'U'), S('T', 'F'), S('-', '1'), S('6', '\n'), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S('u', 't'), S('f', '1'), S('6', '_'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 'u'), S('t', 'f'), S('1', '6'), S('_', 'l'), S('e', 'n'), S('g', 't'), S('h',
  ' '), S('+', ' '), S('(', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n', 't'), S(' ', '<'), S(' ', '0'), S('x', '1'), S('0', '0'), S('0', '0'), S(' ', '?'), S(' ', '1'), S(' ', ':'), S(' ', '2'), S(')',
  ' '), S('a', 's'), S(' ', 'u'), S('i', 'n'), S('t', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('o', 'u'), S('t', 'p'), S('u', 't'), S(' ',
  '='), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', '_'), S('n', 'e'), S('w', '('), S('u', 't'), S('f', '1'), S('6', '_'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ',
  'v'), S('a', 'r'), S(' ', 'u'), S('t', 'f'), S('1', '6'), S(' ', '='), S(' ', 'o'), S('u', 't'), S('p', 'u'), S('t', ' '), S('a', 's'), S(' ', '*'), S('u', 's'), S('h', 'o'), S('r', 't'), S(' ', '+'), S(' ',
  '2'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('C', 'o'), S('n', 'v'), S('e', 'r'), S('t', ' '), S('t', 'e'), S('x', 't'), S('\n', ' '), S(' ', ' '), S(' ', 'i'), S(' ', '='), S(' ',
  '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('w', 'h'), S('i', 'l'), S('e', ' '), S('(', '('), S('a', ' '), S('=', ' '), S('*', '('), S('u', 't'), S('f', '8'), S(' ', '+'), S(' ', 'i'), S(')', ')'), S(' ',
  '!'), S('=', ' '), S('\'', '\\'), S('0', '\''), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', ' '), S('=', ' '), S('i', ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n', 't'), S(':', ' '), S('u', 'i'), S('n', 't'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '/'), S('/',
  ' '), S('D', 'e'), S('c', 'o'), S('d', 'e'), S(' ', 'U'), S('T', 'F'), S('-', '8'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', '('), S('b', ' '), S('=', ' '), S('*', '('), S('u',
  't'), S('f', '8'), S(' ', '+'), S(' ', 'i'), S(')', ')'), S(' ', '!'), S('=', ' '), S('\'', '\\'), S('0', '\''), S(' ', '&'), S('&', ' '), S('a', ' '), S('>', '='), S(' ', '0'), S('x', 'C'), S('0', ')'), S(' ',
  '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S(' ', '='), S(' ', 'i'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ',
  '('), S('(', 'c'), S(' ', '='), S(' ', '*'), S('(', 'u'), S('t', 'f'), S('8', ' '), S('+', ' '), S('i', ')'), S(')', ' '), S('!', '='), S(' ', '\''), S('\\', '0'), S('\'', ' '), S('&', '&'), S(' ', 'a'), S(' ',
  '>'), S('=', ' '), S('0', 'x'), S('E', '0'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', ' '), S('=', ' '), S('i', ' '), S('+', ' '), S('1', ';'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', '('), S('d', ' '), S('=', ' '), S('*', '('), S('u', 't'), S('f', '8'), S(' ', '+'), S(' ', 'i'), S(')', ')'), S(' ',
  '!'), S('=', ' '), S('\'', '\\'), S('0', '\''), S(' ', '&'), S('&', ' '), S('a', ' '), S('>', '='), S(' ', '0'), S('x', 'F'), S('0', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', 'i'), S(' ', '='), S(' ', 'i'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('c', 'o'), S('d', 'e'), S('P',
  'o'), S('i', 'n'), S('t', ' '), S('=', ' '), S('(', '('), S('a', ' '), S('&', ' '), S('0', 'x'), S('0', '7'), S(')', ' '), S('<', '<'), S(' ', '1'), S('8', ')'), S(' ', '|'), S(' ', '('), S('(', 'b'), S(' ',
  '&'), S(' ', '0'), S('x', '3'), S('F', ')'), S(' ', '<'), S('<', ' '), S('1', '2'), S(')', ' '), S('|', ' '), S('(', '('), S('c', ' '), S('&', ' '), S('0', 'x'), S('3', 'F'), S(')', ' '), S('<', '<'), S(' ',
  '6'), S(')', ' '), S('|', ' '), S('(', 'd'), S(' ', '&'), S(' ', '0'), S('x', '3'), S('F', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', ' '), S('e', 'l'), S('s',
  'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n', 't'), S(' ', '='), S(' ', '('), S('(', 'a'), S(' ',
  '&'), S(' ', '0'), S('x', '0'), S('F', ')'), S(' ', '<'), S('<', ' '), S('1', '2'), S(')', ' '), S('|', ' '), S('(', '('), S('b', ' '), S('&', ' '), S('0', 'x'), S('3', 'F'), S(')', ' '), S('<', '<'), S(' ',
  '6'), S(')', ' '), S('|', ' '), S('(', 'c'), S(' ', '&'), S(' ', '0'), S('x', '3'), S('F', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S('}', ' '), S('e', 'l'), S('s', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n',
  't'), S(' ', '='), S(' ', '('), S('(', 'a'), S(' ', '&'), S(' ', '0'), S('x', '1'), S('F', ')'), S(' ', '<'), S('<', ' '), S('6', ')'), S(' ', '|'), S(' ', '('), S('b', ' '), S('&', ' '), S('0', 'x'), S('3',
  'F'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S(' ', 'e'), S('l', 's'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('=', ' '), S('a', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S('/', '/'), S(' ', 'E'), S('n', 'c'), S('o', 'd'), S('e', ' '), S('U', 'T'), S('F', '-'), S('1', '6'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 'c'), S('o',
  'd'), S('e', 'P'), S('o', 'i'), S('n', 't'), S(' ', '<'), S(' ', '0'), S('x', '1'), S('0', '0'), S('0', '0'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('*', 'u'), S('t',
  'f'), S('1', '6'), S(' ', '='), S(' ', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n', 't'), S(' ', 'a'), S('s', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ',
  ' '), S('}', ' '), S('e', 'l'), S('s', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('u', 't'), S('f', '1'), S('6', ' '), S('=', ' '), S('(', '('), S('c', 'o'), S('d',
  'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('>', '>'), S(' ', '1'), S('0', ')'), S(' ', '+'), S(' ', '('), S('0', 'x'), S('D', '8'), S('0', '0'), S(' ', '-'), S(' ', '('), S('0', 'x'), S('1', '0'), S('0',
  '0'), S('0', ' '), S('>', '>'), S(' ', '1'), S('0', ')'), S(')', ')'), S(' ', 'a'), S('s', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('u',
  't'), S('f', '1'), S('6', ' '), S('=', ' '), S('u', 't'), S('f', '1'), S('6', ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('u', 't'), S('f', '1'), S('6',
  ' '), S('=', ' '), S('(', '('), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('&', ' '), S('0', 'x'), S('3', 'F'), S('F', ')'), S(' ', '+'), S(' ', '0'), S('x', 'D'), S('C', '0'), S('0',
  ')'), S(' ', 'a'), S('s', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('u', 't'), S('f', '1'), S('6',
  ' '), S('=', ' '), S('u', 't'), S('f', '1'), S('6', ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ',
  'o'), S('u', 't'), S('p', 'u'), S('t', ';'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('e', 'x'), S('t', 'e'), S('r', 'n'), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('f', 'u'), S('n',
  'c'), S('t', 'i'), S('o', 'n'), S(' ', 'u'), S('t', 'f'), S('1', '6'), S('_', 't'), S('o', '_'), S('c', 's'), S('t', 'r'), S('i', 'n'), S('g', '('), S('i', 'n'), S('p', 'u'), S('t', ':'), S(' ', 's'), S('t',
  'r'), S('i', 'n'), S('g', ')'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('i', 'n'), S('p', 'u'), S('t', ' '), S('a', 's'), S(' ',
  '*'), S('u', 'i'), S('n', 't'), S(' ', '='), S('=', ' '), S('n', 'u'), S('l', 'l'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 'n'), S('u',
  'l'), S('l', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('u', 't'), S('f', '1'), S('6', '_'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ',
  '='), S(' ', '*'), S('(', 'i'), S('n', 'p'), S('u', 't'), S(' ', 'a'), S('s', ' '), S('*', 'u'), S('i', 'n'), S('t', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('u', 't'), S('f',
  '8'), S('_', 'l'), S('e', 'n'), S('g', 't'), S('h', ':'), S(' ', 'u'), S('i', 'n'), S('t', ' '), S('=', ' '), S('0', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'u'), S('t', 'f'), S('1',
  '6'), S(' ', '='), S(' ', 'i'), S('n', 'p'), S('u', 't'), S(' ', 'a'), S('s', ' '), S('*', 'u'), S('s', 'h'), S('o', 'r'), S('t', ' '), S('+', ' '), S('2', ';'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('/',
  '/'), S(' ', 'M'), S('e', 'a'), S('s', 'u'), S('r', 'e'), S(' ', 't'), S('e', 'x'), S('t', '\n'), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('i', ':'), S(' ', 'u'), S('i', 'n'), S('t', ' '), S('=',
  ' '), S('0', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('i', ' '), S('<', ' '), S('u', 't'), S('f', '1'), S('6', '_'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(')',
  ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ':'), S(' ', 'u'), S('i', 'n'), S('t', ';'), S('\n', '\n'), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'D'), S('e', 'c'), S('o', 'd'), S('e', ' '), S('U', 'T'), S('F', '-'), S('1', '6'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ',
  'a'), S(' ', '='), S(' ', '*'), S('(', 'u'), S('t', 'f'), S('1', '6'), S(' ', '+'), S(' ', 'i'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S(' ', '='), S(' ', 'i'), S(' ', '+'), S(' ',
  '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('i', ' '), S('<', ' '), S('u', 't'), S('f', '1'), S('6', '_'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '&'), S('&',
  ' '), S('a', ' '), S('>', '='), S(' ', '0'), S('x', 'D'), S('8', '0'), S('0', ' '), S('&', '&'), S(' ', 'a'), S(' ', '<'), S('=', ' '), S('0', 'x'), S('D', 'B'), S('F', 'F'), S(')', ' '), S('{', '\n'), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('b', ' '), S('=', ' '), S('*', '('), S('u', 't'), S('f', '1'), S('6', ' '), S('+', ' '), S('i', ')'), S(';', '\n'), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S('i', ' '), S('=', ' '), S('i', ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n',
  't'), S(' ', '='), S(' ', '('), S('a', ' '), S('<', '<'), S(' ', '1'), S('0', ')'), S(' ', '+'), S(' ', 'b'), S(' ', '+'), S(' ', '('), S('0', 'x'), S('1', '0'), S('0', '0'), S('0', ' '), S('-', ' '), S('(',
  '0'), S('x', 'D'), S('8', '0'), S('0', ' '), S('<', '<'), S(' ', '1'), S('0', ')'), S(' ', '-'), S(' ', '0'), S('x', 'D'), S('C', '0'), S('0', ')'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(';',
  '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', ' '), S('e', 'l'), S('s', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n',
  't'), S(' ', '='), S(' ', 'a'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('E', 'n'), S('c', 'o'), S('d', 'e'), S(' ',
  'U'), S('T', 'F'), S('-', '8'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'u'), S('t', 'f'), S('8', '_'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 'u'), S('t', 'f'), S('8', '_'), S('l',
  'e'), S('n', 'g'), S('t', 'h'), S(' ', '+'), S(' ', '('), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n', 't'), S(' ', '<'), S(' ', '0'), S('x',
  '8'), S('0', ' '), S('?', ' '), S('1', ' '), S(':', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('<', ' '), S('0', 'x'), S('8',
  '0'), S('0', ' '), S('?', ' '), S('2', ' '), S(':', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('<', ' '), S('0', 'x'), S('1',
  '0'), S('0', '0'), S('0', ' '), S('?', ' '), S('3', ' '), S(':', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('4', ')'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(';', '\n'), S(' ',
  ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'u'), S('t', 'f'), S('8', ' '), S('=', ' '), S('m', 'a'), S('l', 'l'), S('o', 'c'), S('(', 'u'), S('t', 'f'), S('8',
  '_'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '+'), S(' ', '1'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'n'), S('e', 'x'), S('t', ' '), S('=', ' '), S('u', 't'), S('f',
  '8'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('C', 'o'), S('n', 'v'), S('e', 'r'), S('t', ' '), S('t', 'e'), S('x', 't'), S('\n', ' '), S(' ', ' '), S(' ', 'i'), S(' ', '='), S(' ',
  '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('w', 'h'), S('i', 'l'), S('e', ' '), S('(', 'i'), S(' ', '<'), S(' ', 'u'), S('t', 'f'), S('1', '6'), S('_', 'l'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ',
  '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'c'), S('o', 'd'), S('e', 'P'), S('o', 'i'), S('n', 't'), S(':', ' '), S('u', 'i'), S('n', 't'), S(';', '\n'), S('\n', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('D', 'e'), S('c', 'o'), S('d', 'e'), S(' ', 'U'), S('T', 'F'), S('-', '1'), S('6', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('a',
  ' '), S('=', ' '), S('*', '('), S('u', 't'), S('f', '1'), S('6', ' '), S('+', ' '), S('i', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', ' '), S('=', ' '), S('i', ' '), S('+', ' '), S('1',
  ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 'i'), S(' ', '<'), S(' ', 'u'), S('t', 'f'), S('1', '6'), S('_', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('&', '&'), S(' ',
  'a'), S(' ', '>'), S('=', ' '), S('0', 'x'), S('D', '8'), S('0', '0'), S(' ', '&'), S('&', ' '), S('a', ' '), S('<', '='), S(' ', '0'), S('x', 'D'), S('B', 'F'), S('F', ')'), S(' ', '{'), S('\n', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'b'), S(' ', '='), S(' ', '*'), S('(', 'u'), S('t', 'f'), S('1', '6'), S(' ', '+'), S(' ', 'i'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', 'i'), S(' ', '='), S(' ', 'i'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t',
  ' '), S('=', ' '), S('(', 'a'), S(' ', '<'), S('<', ' '), S('1', '0'), S(')', ' '), S('+', ' '), S('b', ' '), S('+', ' '), S('(', '0'), S('x', '1'), S('0', '0'), S('0', '0'), S(' ', '-'), S(' ', '('), S('0',
  'x'), S('D', '8'), S('0', '0'), S(' ', '<'), S('<', ' '), S('1', '0'), S(')', ' '), S('-', ' '), S('0', 'x'), S('D', 'C'), S('0', '0'), S(')', ' '), S('a', 's'), S(' ', 'u'), S('i', 'n'), S('t', ';'), S('\n',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S(' ', 'e'), S('l', 's'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t',
  ' '), S('=', ' '), S('a', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'E'), S('n', 'c'), S('o', 'd'), S('e', ' '), S('U',
  'T'), S('F', '-'), S('8', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('<', ' '), S('0', 'x'), S('8', '0'), S(')',
  ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('*', 'n'), S('e', 'x'), S('t', ' '), S('=', ' '), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('a', 's'), S(' ',
  'b'), S('y', 't'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S(' ', 'e'), S('l', 's'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ',
  '('), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('<', ' '), S('0', 'x'), S('8', '0'), S('0', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  '*'), S('n', 'e'), S('x', 't'), S(' ', '='), S(' ', '('), S('(', '('), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('>', '>'), S(' ', '6'), S(')', ' '), S('&', ' '), S('0', 'x'), S('1',
  'F'), S(')', ' '), S('|', ' '), S('0', 'x'), S('C', '0'), S(')', ' '), S('a', 's'), S(' ', 'b'), S('y', 't'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S(' ', 'e'), S('l',
  's'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('<', ' '), S('0',
  'x'), S('1', '0'), S('0', '0'), S('0', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('n', 'e'), S('x', 't'), S(' ', '='), S(' ', '('), S('(',
  '('), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('>', '>'), S(' ', '1'), S('2', ')'), S(' ', '&'), S(' ', '0'), S('x', '0'), S('F', ')'), S(' ', '|'), S(' ', '0'), S('x', 'E'), S('0',
  ')'), S(' ', 'a'), S('s', ' '), S('b', 'y'), S('t', 'e'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', ' '), S('e', 'l'), S('s', 'e'), S(' ', '{'), S('\n', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('n', 'e'), S('x', 't'), S(' ', '='), S(' ', '('), S('(', '('), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('>',
  '>'), S(' ', '1'), S('8', ')'), S(' ', '&'), S(' ', '0'), S('x', '0'), S('7', ')'), S(' ', '|'), S(' ', '0'), S('x', 'F'), S('0', ')'), S(' ', 'a'), S('s', ' '), S('b', 'y'), S('t', 'e'), S(';', '\n'), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('n', 'e'), S('x', 't'), S(' ', '='), S(' ', 'n'), S('e', 'x'), S('t', ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('n', 'e'), S('x', 't'), S(' ', '='), S(' ', '('), S('(', '('), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t', ' '), S('>', '>'), S(' ',
  '1'), S('2', ')'), S(' ', '&'), S(' ', '0'), S('x', '3'), S('F', ')'), S(' ', '|'), S(' ', '0'), S('x', '8'), S('0', ')'), S(' ', 'a'), S('s', ' '), S('b', 'y'), S('t', 'e'), S(';', '\n'), S(' ', ' '), S(' ',
  ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('n', 'e'), S('x', 't'), S(' ', '='), S(' ', 'n'), S('e', 'x'), S('t', ' '), S('+',
  ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('n', 'e'), S('x', 't'), S(' ', '='), S(' ', '('), S('(', '('), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i',
  'n'), S('t', ' '), S('>', '>'), S(' ', '6'), S(')', ' '), S('&', ' '), S('0', 'x'), S('3', 'F'), S(')', ' '), S('|', ' '), S('0', 'x'), S('8', '0'), S(')', ' '), S('a', 's'), S(' ', 'b'), S('y', 't'), S('e',
  ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'n'), S('e', 'x'), S('t', ' '), S('=', ' '), S('n', 'e'), S('x', 't'), S(' ',
  '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('*', 'n'), S('e', 'x'), S('t', ' '), S('=', ' '), S('(', '('), S('c', 'o'), S('d', 'e'), S('P', 'o'), S('i', 'n'), S('t',
  ' '), S('&', ' '), S('0', 'x'), S('3', 'F'), S(')', ' '), S('|', ' '), S('0', 'x'), S('8', '0'), S(')', ' '), S('a', 's'), S(' ', 'b'), S('y', 't'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ',
  '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'n'), S('e', 'x'), S('t', ' '), S('=', ' '), S('n', 'e'), S('x', 't'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n',
  ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('C', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S('s', ' '), S('a', 'r'), S('e', ' '), S('n', 'u'), S('l', 'l'), S('-', 't'), S('e', 'r'), S('m', 'i'), S('n',
  'a'), S('t', 'e'), S('d', '\n'), S(' ', ' '), S(' ', ' '), S('*', 'n'), S('e', 'x'), S('t', ' '), S('=', ' '), S('\'', '\\'), S('0', '\''), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u',
  'r'), S('n', ' '), S('u', 't'), S('f', '8'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', '#'), S('e', 'n'), S('d', 'i'), S('f', '\n')};
static const uint32_t __string_533[] = {2, S(':', ' ')};
static const uint32_t __string_534_error[] = {7, S('e', 'r'), S('r', 'o'), S('r', ':'), S(' ', 0)};
static const uint32_t __string_535_warning[] = {9, S('w', 'a'), S('r', 'n'), S('i', 'n'), S('g', ':'), S(' ', 0)};
static const uint32_t __string_536_error[] = {7, S('e', 'r'), S('r', 'o'), S('r', ':'), S(' ', 0)};
static const uint32_t __string_537[] = {1, S('\n', 0)};
static const uint32_t __string_538_Usage_thinc_FLAGS_INPUTS[] = {346, S('\n', 'U'), S('s', 'a'), S('g', 'e'), S(':', ' '), S('t', 'h'), S('i', 'n'), S('c', ' '), S('[', 'F'), S('L', 'A'), S('G', 'S'), S(']',
  ' '), S('[', 'I'), S('N', 'P'), S('U', 'T'), S('S', ']'), S('\n', '\n'), S(' ', ' '), S('-', '-'), S('h', 'e'), S('l', 'p'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'P'), S('r',
  'i'), S('n', 't'), S(' ', 't'), S('h', 'i'), S('s', ' '), S('m', 'e'), S('s', 's'), S('a', 'g'), S('e', '.'), S('\n', ' '), S(' ', '-'), S('-', 'o'), S('u', 't'), S(' ', '['), S('P', 'A'), S('T', 'H'), S(']',
  ' '), S(' ', ' '), S(' ', ' '), S('E', 'm'), S('i', 't'), S(' ', 'c'), S('o', 'd'), S('e', ' '), S('t', 'o'), S(' ', 'P'), S('A', 'T'), S('H', ' '), S('(', 't'), S('h', 'e'), S(' ', 't'), S('a', 'r'), S('g',
  'e'), S('t', ' '), S('f', 'o'), S('r', 'm'), S('a', 't'), S(' ', 'i'), S('s', ' '), S('t', 'h'), S('e', ' '), S('f', 'i'), S('l', 'e'), S(' ', 'e'), S('x', 't'), S('e', 'n'), S('s', 'i'), S('o', 'n'), S(')',
  '.'), S('\n', ' '), S(' ', '-'), S('-', 'd'), S('e', 'f'), S('i', 'n'), S('e', ' '), S('[', 'N'), S('A', 'M'), S('E', ']'), S(' ', ' '), S('D', 'e'), S('f', 'i'), S('n', 'e'), S(' ', 't'), S('h', 'e'), S(' ',
  'f'), S('l', 'a'), S('g', ' '), S('N', 'A'), S('M', 'E'), S(' ', 'i'), S('n', ' '), S('a', 'l'), S('l', ' '), S('i', 'n'), S('p', 'u'), S('t', ' '), S('f', 'i'), S('l', 'e'), S('s', '.'), S('\n', '\n'), S('E',
  'x'), S('a', 'm'), S('p', 'l'), S('e', 's'), S(':', '\n'), S('\n', ' '), S(' ', 't'), S('h', 'i'), S('n', 'c'), S(' ', 'm'), S('a', 'i'), S('n', '.'), S('t', 'h'), S('i', 'n'), S(' ', '-'), S('-', 'o'), S('u',
  't'), S(' ', 'm'), S('a', 'i'), S('n', '.'), S('j', 's'), S('\n', ' '), S(' ', 't'), S('h', 'i'), S('n', 'c'), S(' ', 's'), S('r', 'c'), S('/', '*'), S('.', 't'), S('h', 'i'), S('n', ' '), S('-', '-'), S('o',
  'u'), S('t', ' '), S('m', 'a'), S('i', 'n'), S('.', 'w'), S('a', 's'), S('m', '\n'), S(' ', ' '), S('t', 'h'), S('i', 'n'), S('c', ' '), S('n', 'a'), S('t', 'i'), S('v', 'e'), S('.', 't'), S('h', 'i'), S('n',
  ' '), S('-', '-'), S('o', 'u'), S('t', ' '), S('m', 'a'), S('i', 'n'), S('.', 'c'), S(' ', '-'), S('-', 'd'), S('e', 'f'), S('i', 'n'), S('e', ' '), S('E', 'N'), S('A', 'B'), S('L', 'E'), S('_', 'T'), S('E',
  'S'), S('T', 'S'), S('\n', '\n')};
static const uint32_t __string_539[] = {1, S('-', 0)};
static const uint32_t __string_540_h[] = {2, S('-', 'h')};
static const uint32_t __string_541_help[] = {5, S('-', 'h'), S('e', 'l'), S('p', 0)};
static const uint32_t __string_542_help[] = {6, S('-', '-'), S('h', 'e'), S('l', 'p')};
static const uint32_t __string_543[] = {2, S('/', '?')};
static const uint32_t __string_544_c[] = {3, S('-', '-'), S('c', 0)};
static const uint32_t __string_545_js[] = {4, S('-', '-'), S('j', 's')};
static const uint32_t __string_546_wasm[] = {6, S('-', '-'), S('w', 'a'), S('s', 'm')};
static const uint32_t __string_547_define[] = {8, S('-', '-'), S('d', 'e'), S('f', 'i'), S('n', 'e')};
static const uint32_t __string_548_out[] = {5, S('-', '-'), S('o', 'u'), S('t', 0)};
static const uint32_t __string_549_Invalid_flag[] = {14, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('f', 'l'), S('a', 'g'), S(':', ' ')};
static const uint32_t __string_550_No_input_files[] = {14, S('N', 'o'), S(' ', 'i'), S('n', 'p'), S('u', 't'), S(' ', 'f'), S('i', 'l'), S('e', 's')};
static const uint32_t __string_551_Missing_an_output_file_use_the[] = {43, S('M', 'i'), S('s', 's'), S('i', 'n'), S('g', ' '), S('a', 'n'), S(' ', 'o'), S('u', 't'), S('p', 'u'), S('t', ' '), S('f', 'i'), S('l',
  'e'), S(' ', '('), S('u', 's'), S('e', ' '), S('t', 'h'), S('e', 160), S('-', '-'), S('o', 'u'), S('t', ' '), S('f', 'l'), S('a', 'g'), S(')', 0)};
static const uint32_t __string_552_c[] = {2, S('.', 'c')};
static const uint32_t __string_553_js[] = {3, S('.', 'j'), S('s', 0)};
static const uint32_t __string_554_wasm[] = {5, S('.', 'w'), S('a', 's'), S('m', 0)};
static const uint32_t __string_555_Missing_a_target_use_either_c[] = {50, S('M', 'i'), S('s', 's'), S('i', 'n'), S('g', ' '), S('a', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '('), S('u', 's'), S('e',
  ' '), S('e', 'i'), S('t', 'h'), S('e', 'r'), S(' ', '-'), S('-', 'c'), S(',', ' '), S('-', '-'), S('j', 's'), S(',', ' '), S('o', 'r'), S(' ', '-'), S('-', 'w'), S('a', 's'), S('m', ')')};
static const uint32_t __string_556_define[] = {8, S('-', '-'), S('d', 'e'), S('f', 'i'), S('n', 'e')};
static const uint32_t __string_557_out[] = {5, S('-', '-'), S('o', 'u'), S('t', 0)};
static const uint32_t __string_558[] = {1, S('-', 0)};
static const uint32_t __string_559_Cannot_read_from[] = {17, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'r'), S('e', 'a'), S('d', ' '), S('f', 'r'), S('o', 'm'), S(' ', 0)};
static const uint32_t __string_560_h[] = {2, S('.', 'h')};
static const uint32_t __string_561_Cannot_write_to[] = {16, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'w'), S('r', 'i'), S('t', 'e'), S(' ', 't'), S('o', ' ')};
static const uint32_t __string_562[] = {1, S('%', 0)};
static const uint32_t __string_563[] = {1, S('&', 0)};
static const uint32_t __string_564[] = {1, S('*', 0)};
static const uint32_t __string_565[] = {2, S('*', '*')};
static const uint32_t __string_566[] = {1, S('/', 0)};
static const uint32_t __string_567[] = {1, S('<', 0)};
static const uint32_t __string_568[] = {2, S('<', '<')};
static const uint32_t __string_569[] = {2, S('=', '=')};
static const uint32_t __string_570[] = {1, S('>', 0)};
static const uint32_t __string_571[] = {2, S('>', '>')};
static const uint32_t __string_572[] = {2, S('[', ']')};
static const uint32_t __string_573[] = {1, S('^', 0)};
static const uint32_t __string_574[] = {1, S('|', 0)};
static const uint32_t __string_575[] = {3, S('[', ']'), S('=', 0)};
static const uint32_t __string_576_Unexpected[] = {11, S('U', 'n'), S('e', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 0)};
static const uint32_t __string_577_Expected[] = {9, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 0)};
static const uint32_t __string_578_Expected[] = {9, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 0)};
static const uint32_t __string_579_but_found[] = {11, S(' ', 'b'), S('u', 't'), S(' ', 'f'), S('o', 'u'), S('n', 'd'), S(' ', 0)};
static const uint32_t __string_580_Invalid_escape_code[] = {21, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('e', 's'), S('c', 'a'), S('p', 'e'), S(' ', 'c'), S('o', 'd'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_581_Invalid_character_literal_strin[] = {53, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('c', 'h'), S('a', 'r'), S('a', 'c'), S('t', 'e'), S('r', ' '), S('l', 'i'), S('t',
  'e'), S('r', 'a'), S('l', ' '), S('(', 's'), S('t', 'r'), S('i', 'n'), S('g', 's'), S(' ', 'u'), S('s', 'e'), S(' ', 'd'), S('o', 'u'), S('b', 'l'), S('e', ' '), S('q', 'u'), S('o', 't'), S('e', 's'), S(')', 0)};
static const uint32_t __string_582_operator[] = {8, S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r')};
static const uint32_t __string_583_get[] = {3, S('g', 'e'), S('t', 0)};
static const uint32_t __string_584_set[] = {3, S('s', 'e'), S('t', 0)};
static const uint32_t __string_585_Instance_functions_don_t_need_th[] = {52, S('I', 'n'), S('s', 't'), S('a', 'n'), S('c', 'e'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', 's'), S(' ', 'd'), S('o',
  'n'), S('\'', 't'), S(' ', 'n'), S('e', 'e'), S('d', ' '), S('t', 'h'), S('e', ' '), S('\'', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', '\''), S(' ', 'k'), S('e', 'y'), S('w', 'o'), S('r', 'd')};
static const uint32_t __string_586_Instance_variables_don_t_need_th[] = {35, S('I', 'n'), S('s', 't'), S('a', 'n'), S('c', 'e'), S(' ', 'v'), S('a', 'r'), S('i', 'a'), S('b', 'l'), S('e', 's'), S(' ', 'd'), S('o',
  'n'), S('\'', 't'), S(' ', 'n'), S('e', 'e'), S('d', ' '), S('t', 'h'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_587_keyword[] = {9, S('\'', ' '), S('k', 'e'), S('y', 'w'), S('o', 'r'), S('d', 0)};
static const uint32_t __string_588[] = {3, S('[', ']'), S('=', 0)};
static const uint32_t __string_589[] = {2, S('[', ']')};
static const uint32_t __string_590_The_operator[] = {14, S('T', 'h'), S('e', ' '), S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\'')};
static const uint32_t __string_591_cannot_be_implemented[] = {23, S('\'', ' '), S('c', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'b'), S('e', ' '), S('i', 'm'), S('p', 'l'), S('e', 'm'), S('e', 'n'), S('t',
  'e'), S('d', 0)};
static const uint32_t __string_592_it_is_automatically_derived_fr[] = {40, S(' ', '('), S('i', 't'), S(' ', 'i'), S('s', ' '), S('a', 'u'), S('t', 'o'), S('m', 'a'), S('t', 'i'), S('c', 'a'), S('l', 'l'), S('y',
  ' '), S('d', 'e'), S('r', 'i'), S('v', 'e'), S('d', ' '), S('f', 'r'), S('o', 'm'), S(' ', '\''), S('=', '='), S('\'', ')')};
static const uint32_t __string_593_it_is_automatically_derived_fr[] = {39, S(' ', '('), S('i', 't'), S(' ', 'i'), S('s', ' '), S('a', 'u'), S('t', 'o'), S('m', 'a'), S('t', 'i'), S('c', 'a'), S('l', 'l'), S('y',
  ' '), S('d', 'e'), S('r', 'i'), S('v', 'e'), S('d', ' '), S('f', 'r'), S('o', 'm'), S(' ', '\''), S('>', '\''), S(')', 0)};
static const uint32_t __string_594_it_is_automatically_derived_fr[] = {39, S(' ', '('), S('i', 't'), S(' ', 'i'), S('s', ' '), S('a', 'u'), S('t', 'o'), S('m', 'a'), S('t', 'i'), S('c', 'a'), S('l', 'l'), S('y',
  ' '), S('d', 'e'), S('r', 'i'), S('v', 'e'), S('d', ' '), S('f', 'r'), S('o', 'm'), S(' ', '\''), S('<', '\''), S(')', 0)};
static const uint32_t __string_595[] = {0};
static const uint32_t __string_596_Inline_initialization_of_instanc[] = {64, S('I', 'n'), S('l', 'i'), S('n', 'e'), S(' ', 'i'), S('n', 'i'), S('t', 'i'), S('a', 'l'), S('i', 'z'), S('a', 't'), S('i', 'o'), S('n',
  ' '), S('o', 'f'), S(' ', 'i'), S('n', 's'), S('t', 'a'), S('n', 'c'), S('e', ' '), S('v', 'a'), S('r', 'i'), S('a', 'b'), S('l', 'e'), S('s', ' '), S('i', 's'), S(' ', 'n'), S('o', 't'), S(' ', 's'), S('u',
  'p'), S('p', 'o'), S('r', 't'), S('e', 'd'), S(' ', 'y'), S('e', 't')};
static const uint32_t __string_597_Use_the_0o_prefix_for_octal_in[] = {38, S('U', 's'), S('e', ' '), S('t', 'h'), S('e', ' '), S('\'', '0'), S('o', '\''), S(' ', 'p'), S('r', 'e'), S('f', 'i'), S('x', ' '), S('f',
  'o'), S('r', ' '), S('o', 'c'), S('t', 'a'), S('l', ' '), S('i', 'n'), S('t', 'e'), S('g', 'e'), S('r', 's')};
static const uint32_t __string_598_Integer_literal_is_too_big_to_fi[] = {44, S('I', 'n'), S('t', 'e'), S('g', 'e'), S('r', ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', ' '), S('i', 's'), S(' ', 't'), S('o',
  'o'), S(' ', 'b'), S('i', 'g'), S(' ', 't'), S('o', ' '), S('f', 'i'), S('t', ' '), S('i', 'n'), S(' ', '3'), S('2', ' '), S('b', 'i'), S('t', 's')};
static const uint32_t __string_599_Unexpected[] = {11, S('U', 'n'), S('e', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 0)};
static const uint32_t __string_600_Expected[] = {9, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 0)};
static const uint32_t __string_601_but_found[] = {11, S(' ', 'b'), S('u', 't'), S(' ', 'f'), S('o', 'u'), S('n', 'd'), S(' ', 0)};
static const uint32_t __string_602_0[] = {1, S('0', 0)};
static const uint32_t __string_603_Use_undef_to_turn_a_preproces[] = {44, S('U', 's'), S('e', ' '), S('\'', '#'), S('u', 'n'), S('d', 'e'), S('f', '\''), S(' ', 't'), S('o', ' '), S('t', 'u'), S('r', 'n'), S(' ',
  'a'), S(' ', 'p'), S('r', 'e'), S('p', 'r'), S('o', 'c'), S('e', 's'), S('s', 'o'), S('r', ' '), S('f', 'l'), S('a', 'g'), S(' ', 'o'), S('f', 'f')};
static const uint32_t __string_604_All_define_and_undef_direc[] = {68, S('A', 'l'), S('l', ' '), S('\'', '#'), S('d', 'e'), S('f', 'i'), S('n', 'e'), S('\'', ' '), S('a', 'n'), S('d', ' '), S('\'', '#'), S('u',
  'n'), S('d', 'e'), S('f', '\''), S(' ', 'd'), S('i', 'r'), S('e', 'c'), S('t', 'i'), S('v', 'e'), S('s', ' '), S('m', 'u'), S('s', 't'), S(' ', 'b'), S('e', ' '), S('a', 't'), S(' ', 't'), S('h', 'e'), S(' ',
  't'), S('o', 'p'), S(' ', 'o'), S('f', ' '), S('t', 'h'), S('e', ' '), S('f', 'i'), S('l', 'e')};
static const uint32_t __string_605_defined[] = {7, S('d', 'e'), S('f', 'i'), S('n', 'e'), S('d', 0)};
static const uint32_t __string_606_There_is_no_defined_operator[] = {30, S('T', 'h'), S('e', 'r'), S('e', ' '), S('i', 's'), S(' ', 'n'), S('o', ' '), S('\'', 'd'), S('e', 'f'), S('i', 'n'), S('e', 'd'), S('\'',
  ' '), S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r')};
static const uint32_t __string_607_just_use[] = {12, S(' ', '('), S('j', 'u'), S('s', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\'')};
static const uint32_t __string_608_instead[] = {10, S('\'', ' '), S('i', 'n'), S('s', 't'), S('e', 'a'), S('d', ')')};
static const uint32_t __string_609_0[] = {1, S('0', 0)};
static const uint32_t __string_610_Unexpected_integer_did_you_mean[] = {34, S('U', 'n'), S('e', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 'i'), S('n', 't'), S('e', 'g'), S('e', 'r'), S(' ', '('), S('d',
  'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\'')};
static const uint32_t __string_611_true[] = {4, S('t', 'r'), S('u', 'e')};
static const uint32_t __string_612_false[] = {5, S('f', 'a'), S('l', 's'), S('e', 0)};
static const uint32_t __string_613[] = {3, S('\'', ')'), S('?', 0)};
static const uint32_t __string_614_Duplicate_symbol[] = {18, S('D', 'u'), S('p', 'l'), S('i', 'c'), S('a', 't'), S('e', ' '), S('s', 'y'), S('m', 'b'), S('o', 'l'), S(' ', '\'')};
static const uint32_t __string_615[] = {1, S('\'', 0)};
static const uint32_t __string_616[] = {2, S('\\', '"')};
static const uint32_t __string_617_0[] = {2, S('\\', '0')};
static const uint32_t __string_618_t[] = {2, S('\\', 't')};
static const uint32_t __string_619_r[] = {2, S('\\', 'r')};
static const uint32_t __string_620_n[] = {2, S('\\', 'n')};
static const uint32_t __string_621[] = {2, S('\\', '\\')};
static const uint32_t __string_622_type[] = {4, S('t', 'y'), S('p', 'e')};
static const uint32_t __string_623_import[] = {6, S('i', 'm'), S('p', 'o'), S('r', 't')};
static const uint32_t __string_624_function[] = {8, S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n')};
static const uint32_t __string_625_memory[] = {6, S('m', 'e'), S('m', 'o'), S('r', 'y')};
static const uint32_t __string_626_export[] = {6, S('e', 'x'), S('p', 'o'), S('r', 't')};
static const uint32_t __string_627_code[] = {4, S('c', 'o'), S('d', 'e')};
static const uint32_t __string_628_data[] = {4, S('d', 'a'), S('t', 'a')};
static const uint32_t __string_629_name[] = {4, S('n', 'a'), S('m', 'e')};
static const uint32_t __string_630_currentHeapPointer[] = {18, S('c', 'u'), S('r', 'r'), S('e', 'n'), S('t', 'H'), S('e', 'a'), S('p', 'P'), S('o', 'i'), S('n', 't'), S('e', 'r')};
static const uint32_t __string_631_originalHeapPointer[] = {19, S('o', 'r'), S('i', 'g'), S('i', 'n'), S('a', 'l'), S('H', 'e'), S('a', 'p'), S('P', 'o'), S('i', 'n'), S('t', 'e'), S('r', 0)};
static const uint32_t __string_632_global[] = {6, S('g', 'l'), S('o', 'b'), S('a', 'l')};
static const uint32_t __string_633_malloc[] = {6, S('m', 'a'), S('l', 'l'), S('o', 'c')};

#undef S

struct CResult;
struct CheckContext;
struct Compiler;
struct JsResult;
struct Token;
struct LineColumn;
struct Source;
struct Range;
struct Diagnostic;
struct Log;
struct CommandLineArgument;
struct NodeFlag;
struct Node;
struct ParserContext;
struct PreprocessorFlag;
struct Preprocessor;
struct Scope;
struct StringBuilder;
struct Symbol;
struct Type;
struct WasmWrappedType;
struct WasmSignature;
struct WasmFunction;
struct WasmImport;
struct WasmModule;
struct WasmSharedOffset;

struct ByteArray {
  uint8_t *_data;
  uint32_t _length;
  uint32_t _capacity;
};

struct CResult {
  struct CheckContext *context;
  struct StringBuilder *code;
  struct StringBuilder *codePrefix;
  const uint16_t *headerName;
  int32_t indent;
  uint8_t hasStrings;
  struct Node *previousNode;
  int32_t nextStringLiteral;
};

struct CheckContext {
  struct Log *log;
  int32_t target;
  int32_t pointerByteSize;
  uint8_t isUnsafeAllowed;
  struct Symbol *enclosingClass;
  struct Type *currentReturnType;
  int32_t nextGlobalVariableOffset;
  struct Type *boolType;
  struct Type *sbyteType;
  struct Type *errorType;
  struct Type *intType;
  struct Type *nullType;
  struct Type *shortType;
  struct Type *stringType;
  struct Type *byteType;
  struct Type *uintType;
  struct Type *ushortType;
  struct Type *voidType;
};

struct Compiler {
  struct Log *log;
  struct Node *global;
  struct Source *firstSource;
  struct Source *lastSource;
  struct Preprocessor *preprocessor;
  int32_t target;
  struct CheckContext *context;
  struct Source *librarySource;
  const uint16_t *outputName;
  struct ByteArray *outputWASM;
  const uint16_t *outputJS;
  const uint16_t *outputC;
  const uint16_t *outputH;
};

struct JsResult {
  struct CheckContext *context;
  struct StringBuilder *code;
  int32_t indent;
  uint8_t foundMultiply;
  struct Node *previousNode;
};

struct Token {
  int32_t kind;
  struct Range *range;
  struct Token *next;
};

struct LineColumn {
  int32_t line;
  int32_t column;
};

struct Source {
  const uint16_t *name;
  const uint16_t *contents;
  struct Source *next;
  uint8_t isLibrary;
  struct Token *firstToken;
  struct Node *file;
};

struct Range {
  struct Source *source;
  int32_t start;
  int32_t end;
};

struct Diagnostic {
  struct Range *range;
  const uint16_t *message;
  int32_t kind;
  struct Diagnostic *next;
};

struct Log {
  struct Diagnostic *first;
  struct Diagnostic *last;
};

struct CommandLineArgument {
  const uint16_t *text;
  struct CommandLineArgument *next;
};

struct NodeFlag {
  int32_t flag;
  struct Range *range;
  struct NodeFlag *next;
};

struct Node {
  int32_t kind;
  int32_t flags;
  struct NodeFlag *firstFlag;
  struct Range *range;
  struct Range *internalRange;
  struct Node *parent;
  struct Node *firstChild;
  struct Node *lastChild;
  struct Node *previousSibling;
  struct Node *nextSibling;
  int32_t intValue;
  const uint16_t *stringValue;
  struct Type *resolvedType;
  struct Symbol *symbol;
  struct Scope *scope;
};

struct ParserContext {
  struct Token *previous;
  struct Token *current;
  struct Log *log;
  struct Token *lastError;
};

struct PreprocessorFlag {
  uint8_t isDefined;
  const uint16_t *name;
  struct PreprocessorFlag *next;
};

struct Preprocessor {
  struct PreprocessorFlag *firstFlag;
  uint8_t isDefineAndUndefAllowed;
  struct Token *previous;
  struct Token *current;
  struct Log *log;
};

struct Scope {
  struct Scope *parent;
  struct Symbol *symbol;
  struct Symbol *firstSymbol;
  struct Symbol *lastSymbol;
};

struct StringBuilder {
  struct StringBuilder *next;
  struct ByteArray *_bytes;
};

struct Symbol {
  int32_t kind;
  const uint16_t *name;
  struct Node *node;
  struct Range *range;
  struct Scope *scope;
  struct Type *resolvedType;
  struct Symbol *next;
  int32_t state;
  int32_t flags;
  int32_t byteSize;
  int32_t maxAlignment;
  const uint16_t *rename;
  int32_t offset;
};

struct Type {
  struct Symbol *symbol;
  struct Type *pointerTo;
  const uint16_t *cachedToString;
  struct Type *cachedPointerType;
};

struct WasmWrappedType {
  int32_t id;
  struct WasmWrappedType *next;
};

struct WasmSignature {
  struct WasmWrappedType *argumentTypes;
  struct WasmWrappedType *returnType;
  struct WasmSignature *next;
};

struct WasmFunction {
  struct Symbol *symbol;
  int32_t signatureIndex;
  uint8_t isExported;
  int32_t intLocalCount;
  struct WasmFunction *next;
};

struct WasmImport {
  int32_t signatureIndex;
  const uint16_t *module;
  const uint16_t *name;
  struct WasmImport *next;
};

struct WasmModule {
  struct WasmImport *firstImport;
  struct WasmImport *lastImport;
  int32_t importCount;
  struct WasmFunction *firstFunction;
  struct WasmFunction *lastFunction;
  int32_t functionCount;
  struct WasmSignature *firstSignature;
  struct WasmSignature *lastSignature;
  int32_t signatureCount;
  struct ByteArray *memoryInitializer;
  int32_t currentHeapPointer;
  int32_t originalHeapPointer;
  int32_t mallocFunctionIndex;
  struct CheckContext *context;
};

struct WasmSharedOffset {
  int32_t nextLocalOffset;
  int32_t intLocalCount;
};

static const uint16_t *ushort_toString(uint16_t __this);
static const uint16_t *int_toString(int32_t __this);
static const uint16_t *uint_toString(uint32_t __this);
static const uint16_t *internalIntToString(uint32_t value, uint8_t sign);
static const uint16_t *string_new(uint32_t length);
static int32_t string_length(const uint16_t *__this);
static uint16_t string_op_get(const uint16_t *__this, int32_t index);
static uint8_t string_op_equals(const uint16_t *__this, const uint16_t *other);
static const uint16_t *string_slice(const uint16_t *__this, int32_t start, int32_t end);
static uint8_t string_startsWith(const uint16_t *__this, const uint16_t *text);
static uint8_t string_endsWith(const uint16_t *__this, const uint16_t *text);
static int32_t string_lastIndexOf(const uint16_t *__this, const uint16_t *text);
const uint16_t *cstring_to_utf16(uint8_t *utf8);
uint8_t *utf16_to_cstring(const uint16_t *input);
static void ByteArray_set16(struct ByteArray *array, int32_t index, int32_t value);
static void ByteArray_set32(struct ByteArray *array, int32_t index, int32_t value);
static void ByteArray_append32(struct ByteArray *array, int32_t value);
static void ByteArray_setString(struct ByteArray *array, int32_t index, const uint16_t *text);
int32_t ByteArray_length(struct ByteArray *__this);
uint8_t *ByteArray_bytes(struct ByteArray *__this);
void ByteArray_clear(struct ByteArray *__this);
uint8_t ByteArray_get(struct ByteArray *__this, int32_t index);
void ByteArray_set(struct ByteArray *__this, int32_t index, uint8_t value);
void ByteArray_append(struct ByteArray *__this, uint8_t value);
void ByteArray_resize(struct ByteArray *__this, int32_t length);
static void CResult_emitIndent(struct CResult *__this);
static void CResult_emitNewlineBefore(struct CResult *__this, struct Node *node);
static void CResult_emitNewlineAfter(struct CResult *__this, struct Node *node);
static void CResult_emitStatements(struct CResult *__this, struct Node *node);
static void CResult_emitBlock(struct CResult *__this, struct Node *node);
static void CResult_emitUnary(struct CResult *__this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator);
static void CResult_emitBinary(struct CResult *__this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator, int32_t operatorPrecedence);
static void CResult_emitCommaSeparatedExpressions(struct CResult *__this, struct Node *start, struct Node *stop);
static void CResult_emitSymbolName(struct CResult *__this, struct Symbol *symbol);
static void CResult_emitExpression(struct CResult *__this, struct Node *node, int32_t parentPrecedence);
static uint8_t CResult_shouldEmitClass(struct CResult *__this, struct Node *node);
static void CResult_emitType(struct CResult *__this, struct Type *originalType, int32_t mode);
static void CResult_emitStatement(struct CResult *__this, struct Node *node);
static void CResult_emitIncludes(struct CResult *__this, struct StringBuilder *code, int32_t mode);
static void CResult_emitTypeDeclarations(struct CResult *__this, struct Node *node, int32_t mode);
static void CResult_emitTypeDefinitions(struct CResult *__this, struct Node *node, int32_t mode);
static uint8_t CResult_shouldEmitFunction(struct CResult *__this, struct Symbol *symbol);
static void CResult_emitFunctionDeclarations(struct CResult *__this, struct Node *node, int32_t mode);
static void CResult_emitGlobalVariables(struct CResult *__this, struct Node *node, int32_t mode);
static void CResult_emitFunctionDefinitions(struct CResult *__this, struct Node *node);
static void CResult_finishImplementation(struct CResult *__this);
static void cEmitCharacter(struct StringBuilder *builder, uint16_t c);
static void cEmit(struct Compiler *compiler);
static int32_t CheckContext_allocateGlobalVariableOffset(struct CheckContext *__this, int32_t sizeOf, int32_t alignmentOf);
static void addScopeToSymbol(struct Symbol *symbol, struct Scope *parentScope);
static void linkSymbolToNode(struct Symbol *symbol, struct Node *node);
static void initialize(struct CheckContext *context, struct Node *node, struct Scope *parentScope, int32_t mode);
static void prepareNativeType(struct Type *type, int32_t byteSizeAndMaxAlignment, int32_t flags);
static void forbidFlag(struct CheckContext *context, struct Node *node, int32_t flag, const uint16_t *text);
static void requireFlag(struct CheckContext *context, struct Node *node, int32_t flag, const uint16_t *text);
static void initializeSymbol(struct CheckContext *context, struct Symbol *symbol);
static void resolveChildren(struct CheckContext *context, struct Node *node, struct Scope *parentScope);
static void resolveChildrenAsExpressions(struct CheckContext *context, struct Node *node, struct Scope *parentScope);
static void resolveAsExpression(struct CheckContext *context, struct Node *node, struct Scope *parentScope);
static void resolveAsType(struct CheckContext *context, struct Node *node, struct Scope *parentScope);
static uint8_t canConvert(struct CheckContext *context, struct Node *node, struct Type *to, int32_t kind);
static void checkConversion(struct CheckContext *context, struct Node *node, struct Type *to, int32_t kind);
static void checkStorage(struct CheckContext *context, struct Node *target);
static struct Node *createDefaultValueForType(struct CheckContext *context, struct Type *type);
static void simplifyBinary(struct Node *node);
static uint8_t binaryHasUnsignedArguments(struct Node *node);
static uint8_t isSymbolAccessAllowed(struct CheckContext *context, struct Symbol *symbol, struct Node *node, struct Range *range);
static void resolve(struct CheckContext *context, struct Node *node, struct Scope *parentScope);
static void Compiler_initialize(struct Compiler *__this, int32_t target, const uint16_t *outputName);
static void Compiler_createGlobals(struct Compiler *__this);
static struct Source *Compiler_addInput(struct Compiler *__this, const uint16_t *name, const uint16_t *contents);
static uint8_t Compiler_finish(struct Compiler *__this);
static const uint16_t *replaceFileExtension(const uint16_t *path, const uint16_t *extension);
void assert(uint8_t truth);
void Profiler_begin();
void Profiler_end(const uint16_t *text);
static uint8_t isPositivePowerOf2(int32_t value);
static int32_t alignToNextMultipleOf(int32_t offset, int32_t alignment);
static void JsResult_emitIndent(struct JsResult *__this);
static void JsResult_emitNewlineBefore(struct JsResult *__this, struct Node *node);
static void JsResult_emitNewlineAfter(struct JsResult *__this, struct Node *node);
static void JsResult_emitStatements(struct JsResult *__this, struct Node *node);
static void JsResult_emitBlock(struct JsResult *__this, struct Node *node);
static void JsResult_emitUnary(struct JsResult *__this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator);
static void JsResult_emitBinary(struct JsResult *__this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator, int32_t operatorPrecedence, int32_t mode);
static void JsResult_emitCommaSeparatedExpressions(struct JsResult *__this, struct Node *start, struct Node *stop);
static void JsResult_emitExpression(struct JsResult *__this, struct Node *node, int32_t parentPrecedence);
static void JsResult_emitSymbolName(struct JsResult *__this, struct Symbol *symbol);
static void JsResult_emitStatement(struct JsResult *__this, struct Node *node);
static uint8_t jsKindCastsOperandsToInt(int32_t kind);
static void jsEmit(struct Compiler *compiler);
static uint8_t isKeyword(int32_t kind);
static void splitToken(struct Token *first, int32_t firstKind, int32_t secondKind);
static const uint16_t *tokenToString(int32_t token);
static uint8_t isAlpha(uint16_t c);
static uint8_t isASCII(uint16_t c);
static uint8_t isNumber(uint16_t c);
static uint8_t isDigit(uint16_t c, uint8_t base);
static struct Token *tokenize(struct Source *source, struct Log *log);
static const uint16_t *library();
static struct LineColumn *Source_indexToLineColumn(struct Source *__this, int32_t index);
static const uint16_t *Range_toString(struct Range *__this);
static uint8_t Range_equals(struct Range *__this, struct Range *other);
static struct Range *Range_enclosingLine(struct Range *__this);
static struct Range *Range_rangeAtEnd(struct Range *__this);
static struct Range *createRange(struct Source *source, int32_t start, int32_t end);
static struct Range *spanRanges(struct Range *left, struct Range *right);
static void Diagnostic_appendSourceName(struct Diagnostic *__this, struct StringBuilder *builder, struct LineColumn *location);
static void Diagnostic_appendKind(struct Diagnostic *__this, struct StringBuilder *builder);
static void Diagnostic_appendMessage(struct Diagnostic *__this, struct StringBuilder *builder);
static void Diagnostic_appendLineContents(struct Diagnostic *__this, struct StringBuilder *builder, struct LineColumn *location);
static void Diagnostic_appendRange(struct Diagnostic *__this, struct StringBuilder *builder, struct LineColumn *location);
static void Log_error(struct Log *__this, struct Range *range, const uint16_t *message);
static void Log_warning(struct Log *__this, struct Range *range, const uint16_t *message);
static void Log_append(struct Log *__this, struct Range *range, const uint16_t *message, int32_t kind);
static const uint16_t *Log_toString(struct Log *__this);
static uint8_t Log_hasErrors(struct Log *__this);
void Terminal_setColor(int32_t color);
void Terminal_write(const uint16_t *text);
const uint16_t *IO_readTextFile(const uint16_t *path);
uint8_t IO_writeTextFile(const uint16_t *path, const uint16_t *contents);
uint8_t IO_writeBinaryFile(const uint16_t *path, struct ByteArray *contents);
static void writeLogToTerminal(struct Log *log);
static void printError(const uint16_t *text);
void main_addArgument(const uint16_t *text);
void main_reset();
static void printUsage();
int32_t main_entry();
static uint8_t isUnary(int32_t kind);
static uint8_t isUnaryPostfix(int32_t kind);
static uint8_t isBinary(int32_t kind);
static int32_t invertedBinaryKind(int32_t kind);
static uint8_t isExpression(struct Node *node);
static uint8_t isCompactNodeKind(int32_t kind);
static struct NodeFlag *appendFlag(struct NodeFlag *first, int32_t flag, struct Range *range);
static int32_t allFlags(struct NodeFlag *link);
static struct Range *rangeForFlag(struct NodeFlag *link, int32_t flag);
static void Node_become(struct Node *__this, struct Node *node);
static void Node_becomeSymbolReference(struct Node *__this, struct Symbol *symbol);
static void Node_becomeIntegerConstant(struct Node *__this, int32_t value);
static void Node_becomeBooleanConstant(struct Node *__this, uint8_t value);
static uint8_t Node_isNegativeInteger(struct Node *__this);
static uint8_t Node_isNonNegativeInteger(struct Node *__this);
static uint8_t Node_isDeclare(struct Node *__this);
static uint8_t Node_isExtern(struct Node *__this);
static uint8_t Node_isDeclareOrExtern(struct Node *__this);
static uint8_t Node_isGet(struct Node *__this);
static uint8_t Node_isSet(struct Node *__this);
static uint8_t Node_isOperator(struct Node *__this);
static uint8_t Node_isPositive(struct Node *__this);
static uint8_t Node_isPrivate(struct Node *__this);
static uint8_t Node_isUnsafe(struct Node *__this);
static uint8_t Node_isUnsignedOperator(struct Node *__this);
static int32_t Node_childCount(struct Node *__this);
static void Node_appendChild(struct Node *__this, struct Node *child);
static void Node_insertChildBefore(struct Node *__this, struct Node *after, struct Node *before);
static struct Node *Node_remove(struct Node *__this);
static void Node_removeChildren(struct Node *__this);
static void Node_replaceWith(struct Node *__this, struct Node *node);
static uint8_t Node_isType(struct Node *__this);
static uint8_t Node_isCallValue(struct Node *__this);
static uint8_t Node_isAssignTarget(struct Node *__this);
static struct Node *Node_withRange(struct Node *__this, struct Range *range);
static struct Node *Node_withInternalRange(struct Node *__this, struct Range *range);
static struct Node *Node_functionFirstArgument(struct Node *__this);
static struct Node *Node_functionFirstArgumentIgnoringThis(struct Node *__this);
static struct Node *Node_functionReturnType(struct Node *__this);
static struct Node *Node_functionBody(struct Node *__this);
static struct Node *Node_newType(struct Node *__this);
static struct Node *Node_callValue(struct Node *__this);
static struct Node *Node_castValue(struct Node *__this);
static struct Node *Node_castType(struct Node *__this);
static struct Node *Node_alignOfType(struct Node *__this);
static struct Node *Node_sizeOfType(struct Node *__this);
static struct Node *Node_dotTarget(struct Node *__this);
static struct Node *Node_returnValue(struct Node *__this);
static struct Node *Node_extendsType(struct Node *__this);
static struct Node *Node_variableType(struct Node *__this);
static struct Node *Node_variableValue(struct Node *__this);
static struct Node *Node_expressionValue(struct Node *__this);
static struct Node *Node_binaryLeft(struct Node *__this);
static struct Node *Node_binaryRight(struct Node *__this);
static struct Node *Node_unaryValue(struct Node *__this);
static struct Node *Node_whileValue(struct Node *__this);
static struct Node *Node_whileBody(struct Node *__this);
static struct Node *Node_hookValue(struct Node *__this);
static struct Node *Node_hookTrue(struct Node *__this);
static struct Node *Node_hookFalse(struct Node *__this);
static struct Node *Node_indexTarget(struct Node *__this);
static struct Node *Node_ifValue(struct Node *__this);
static struct Node *Node_ifTrue(struct Node *__this);
static struct Node *Node_ifFalse(struct Node *__this);
static uint8_t Node_expandCallIntoOperatorTree(struct Node *__this);
static struct Node *createNew(struct Node *type);
static struct Node *createHook(struct Node *test, struct Node *primary, struct Node *secondary);
static struct Node *createIndex(struct Node *target);
static struct Node *createNull();
static struct Node *createThis();
static struct Node *createAddressOf(struct Node *value);
static struct Node *createDereference(struct Node *value);
static struct Node *createAlignOf(struct Node *type);
static struct Node *createSizeOf(struct Node *type);
static struct Node *createBool(uint8_t value);
static struct Node *createInt(int32_t value);
static struct Node *createString(const uint16_t *value);
static struct Node *createName(const uint16_t *value);
static struct Node *createType(struct Type *type);
static struct Node *createEmpty();
static struct Node *createExpression(struct Node *value);
static struct Node *createBlock();
static struct Node *createClass(const uint16_t *name);
static struct Node *createEnum(const uint16_t *name);
static struct Node *createIf(struct Node *value, struct Node *trueBranch, struct Node *falseBranch);
static struct Node *createWhile(struct Node *value, struct Node *body);
static struct Node *createReturn(struct Node *value);
static struct Node *createVariables();
static struct Node *createConstants();
static struct Node *createParameters();
static struct Node *createExtends(struct Node *type);
static struct Node *createImplements();
static struct Node *createParameter(const uint16_t *name);
static struct Node *createVariable(const uint16_t *name, struct Node *type, struct Node *value);
static struct Node *createFunction(const uint16_t *name);
static struct Node *createUnary(int32_t kind, struct Node *value);
static struct Node *createBinary(int32_t kind, struct Node *left, struct Node *right);
static struct Node *createCall(struct Node *value);
static struct Node *createCast(struct Node *value, struct Node *type);
static struct Node *createDot(struct Node *value, const uint16_t *name);
static struct Node *createSymbolReference(struct Symbol *symbol);
static struct Node *createMemberReference(struct Node *value, struct Symbol *symbol);
static struct Node *createParseError();
static uint8_t isRightAssociative(int32_t precedence);
static uint8_t ParserContext_peek(struct ParserContext *__this, int32_t kind);
static uint8_t ParserContext_eat(struct ParserContext *__this, int32_t kind);
static void ParserContext_advance(struct ParserContext *__this);
static void ParserContext_unexpectedToken(struct ParserContext *__this);
static uint8_t ParserContext_expect(struct ParserContext *__this, int32_t kind);
static struct Node *ParserContext_parseUnaryPrefix(struct ParserContext *__this, int32_t kind, int32_t mode);
static struct Node *ParserContext_parseBinary(struct ParserContext *__this, int32_t kind, struct Node *left, int32_t localPrecedence, int32_t operatorPrecedence);
static struct Node *ParserContext_parseUnaryPostfix(struct ParserContext *__this, int32_t kind, struct Node *value, int32_t localPrecedence);
static const uint16_t *ParserContext_parseQuotedString(struct ParserContext *__this, struct Range *range);
static struct Node *ParserContext_parsePrefix(struct ParserContext *__this, int32_t mode);
static struct Node *ParserContext_parseInfix(struct ParserContext *__this, int32_t precedence, struct Node *node, int32_t mode);
static struct Node *ParserContext_parseArgumentList(struct ParserContext *__this, struct Range *start, struct Node *node);
static struct Node *ParserContext_parseExpression(struct ParserContext *__this, int32_t precedence, int32_t mode);
static struct Node *ParserContext_parseType(struct ParserContext *__this);
static struct Node *ParserContext_parseIf(struct ParserContext *__this);
static struct Node *ParserContext_parseWhile(struct ParserContext *__this);
static struct Node *ParserContext_parseBody(struct ParserContext *__this);
static struct Node *ParserContext_parseBlock(struct ParserContext *__this);
static struct Node *ParserContext_parseReturn(struct ParserContext *__this);
static struct Node *ParserContext_parseEmpty(struct ParserContext *__this);
static struct Node *ParserContext_parseEnum(struct ParserContext *__this, struct NodeFlag *firstFlag);
static struct Node *ParserContext_parseParameters(struct ParserContext *__this);
static struct Node *ParserContext_parseClass(struct ParserContext *__this, struct NodeFlag *firstFlag);
static struct Node *ParserContext_parseFunction(struct ParserContext *__this, struct NodeFlag *firstFlag, struct Node *parent);
static struct Node *ParserContext_parseVariables(struct ParserContext *__this, struct NodeFlag *firstFlag, struct Node *parent);
static struct Node *ParserContext_parseLoopJump(struct ParserContext *__this, int32_t kind);
static struct NodeFlag *ParserContext_parseFlags(struct ParserContext *__this);
static struct Node *ParserContext_parseUnsafe(struct ParserContext *__this);
static struct Node *ParserContext_parseStatement(struct ParserContext *__this, int32_t mode);
static uint8_t ParserContext_parseStatements(struct ParserContext *__this, struct Node *parent);
static uint8_t ParserContext_parseInt(struct ParserContext *__this, struct Range *range, struct Node *node);
static struct Node *parse(struct Token *firstToken, struct Log *log);
static uint8_t Preprocessor_peek(struct Preprocessor *__this, int32_t kind);
static uint8_t Preprocessor_eat(struct Preprocessor *__this, int32_t kind);
static void Preprocessor_advance(struct Preprocessor *__this);
static void Preprocessor_unexpectedToken(struct Preprocessor *__this);
static uint8_t Preprocessor_expect(struct Preprocessor *__this, int32_t kind);
static void Preprocessor_removeTokensFrom(struct Preprocessor *__this, struct Token *before);
static uint8_t Preprocessor_isDefined(struct Preprocessor *__this, const uint16_t *name);
static void Preprocessor_define(struct Preprocessor *__this, const uint16_t *name, uint8_t isDefined);
static void Preprocessor_run(struct Preprocessor *__this, struct Source *source, struct Log *log);
static uint8_t Preprocessor_scan(struct Preprocessor *__this, uint8_t isParentLive);
static int32_t Preprocessor_parsePrefix(struct Preprocessor *__this);
static int32_t Preprocessor_parseInfix(struct Preprocessor *__this, int32_t precedence, int32_t left);
static int32_t Preprocessor_parseExpression(struct Preprocessor *__this, int32_t precedence);
static struct Symbol *Scope_findLocal(struct Scope *__this, const uint16_t *name, int32_t hint);
static struct Symbol *Scope_findNested(struct Scope *__this, const uint16_t *name, int32_t hint, int32_t mode);
static uint8_t Scope_define(struct Scope *__this, struct Log *log, struct Symbol *symbol, int32_t hint);
static struct Type *Scope_defineNativeType(struct Scope *__this, struct Log *log, const uint16_t *name);
static void treeShakingMarkAllUsed(struct Node *node);
static void treeShakingSearchForUsed(struct Node *node);
static void treeShakingRemoveUnused(struct Node *node);
static void treeShaking(struct Node *node);
static struct StringBuilder *StringBuilder_new();
static void StringBuilder_appendQuoted(struct StringBuilder *sb, const uint16_t *text);
static void StringBuilder_clear(struct StringBuilder *__this);
static struct StringBuilder *StringBuilder_appendChar(struct StringBuilder *__this, uint16_t c);
static struct StringBuilder *StringBuilder_appendSlice(struct StringBuilder *__this, const uint16_t *text, int32_t start, int32_t end);
static struct StringBuilder *StringBuilder_append(struct StringBuilder *__this, const uint16_t *text);
static const uint16_t *StringBuilder_finish(struct StringBuilder *__this);
static uint8_t isType(int32_t kind);
static uint8_t isFunction(int32_t kind);
static uint8_t isVariable(int32_t kind);
static uint8_t Symbol_isEnumValue(struct Symbol *__this);
static uint8_t Symbol_isUnsafe(struct Symbol *__this);
static uint8_t Symbol_isGetter(struct Symbol *__this);
static uint8_t Symbol_isSetter(struct Symbol *__this);
static uint8_t Symbol_isBinaryOperator(struct Symbol *__this);
static uint8_t Symbol_isUnaryOperator(struct Symbol *__this);
static uint8_t Symbol_shouldConvertInstanceToGlobal(struct Symbol *__this);
static uint8_t Symbol_isUsed(struct Symbol *__this);
static struct Symbol *Symbol_parent(struct Symbol *__this);
static struct Type *Symbol_resolvedTypeUnderlyingIfEnumValue(struct Symbol *__this, struct CheckContext *context);
static void Symbol_determineClassLayout(struct Symbol *__this, struct CheckContext *context);
static uint8_t Type_isClass(struct Type *__this);
static uint8_t Type_isEnum(struct Type *__this);
static uint8_t Type_isInteger(struct Type *__this);
static uint8_t Type_isUnsigned(struct Type *__this);
static uint8_t Type_isReference(struct Type *__this);
static struct Type *Type_underlyingType(struct Type *__this, struct CheckContext *context);
static int32_t Type_integerBitCount(struct Type *__this, struct CheckContext *context);
static uint32_t Type_integerBitMask(struct Type *__this, struct CheckContext *context);
static int32_t Type_allocationSizeOf(struct Type *__this, struct CheckContext *context);
static int32_t Type_allocationAlignmentOf(struct Type *__this, struct CheckContext *context);
static int32_t Type_variableSizeOf(struct Type *__this, struct CheckContext *context);
static int32_t Type_variableAlignmentOf(struct Type *__this, struct CheckContext *context);
static struct Type *Type_pointerType(struct Type *__this);
static const uint16_t *Type_toString(struct Type *__this);
static struct Symbol *Type_findMember(struct Type *__this, const uint16_t *name, int32_t hint);
static uint8_t Type_hasInstanceMembers(struct Type *__this);
static uint8_t wasmAreSignaturesEqual(struct WasmSignature *a, struct WasmSignature *b);
static void WasmModule_growMemoryInitializer(struct WasmModule *__this);
static struct WasmImport *WasmModule_allocateImport(struct WasmModule *__this, int32_t signatureIndex, const uint16_t *mod, const uint16_t *name);
static struct WasmFunction *WasmModule_allocateFunction(struct WasmModule *__this, struct Symbol *symbol, int32_t signatureIndex);
static int32_t WasmModule_allocateSignature(struct WasmModule *__this, struct WasmWrappedType *argumentTypes, struct WasmWrappedType *returnType);
static void WasmModule_emitModule(struct WasmModule *__this, struct ByteArray *array);
static void WasmModule_emitSignatures(struct WasmModule *__this, struct ByteArray *array);
static void WasmModule_emitImportTable(struct WasmModule *__this, struct ByteArray *array);
static void WasmModule_emitFunctionSignatures(struct WasmModule *__this, struct ByteArray *array);
static void WasmModule_emitMemory(struct WasmModule *__this, struct ByteArray *array);
static void WasmModule_emitExportTable(struct WasmModule *__this, struct ByteArray *array);
static void WasmModule_emitFunctionBodies(struct WasmModule *__this, struct ByteArray *array);
static void WasmModule_emitDataSegments(struct WasmModule *__this, struct ByteArray *array);
static void WasmModule_emitNames(struct WasmModule *__this, struct ByteArray *array);
static void WasmModule_prepareToEmit(struct WasmModule *__this, struct Node *node);
static void WasmModule_emitBinaryExpression(struct WasmModule *__this, struct ByteArray *array, struct Node *node, uint8_t opcode);
static void WasmModule_emitLoadFromMemory(struct WasmModule *__this, struct ByteArray *array, struct Type *type, struct Node *relativeBase, int32_t offset);
static void WasmModule_emitStoreToMemory(struct WasmModule *__this, struct ByteArray *array, struct Type *type, struct Node *relativeBase, int32_t offset, struct Node *value);
static void WasmModule_emitNode(struct WasmModule *__this, struct ByteArray *array, struct Node *node);
static int32_t WasmModule_getWasmType(struct WasmModule *__this, struct Type *type);
static void wasmPatchVarUnsigned(struct ByteArray *array, int32_t offset, int32_t value, int32_t maxValue);
static void wasmWriteVarUnsigned(struct ByteArray *array, int32_t value);
static void wasmWriteVarSigned(struct ByteArray *array, int32_t value);
static void wasmWriteLengthPrefixedASCII(struct ByteArray *array, const uint16_t *value);
static int32_t wasmStartSection(struct ByteArray *array, const uint16_t *name);
static void wasmFinishSection(struct ByteArray *array, int32_t offset);
static struct WasmWrappedType *wasmWrapType(int32_t id);
static void wasmAssignLocalVariableOffsets(struct Node *node, struct WasmSharedOffset *shared);
static void wasmEmit(struct Compiler *compiler);

static struct CommandLineArgument *firstArgument = NULL;
static struct CommandLineArgument *lastArgument = NULL;
static struct StringBuilder *stringBuilderPool = NULL;

static const uint16_t *ushort_toString(uint16_t __this) {
  return uint_toString((uint32_t)__this);
}

static const uint16_t *int_toString(int32_t __this) {
  if (__this == -2147483648) {
    return (const uint16_t *)__string_0_2147483648;
  }

  return internalIntToString((uint32_t)(__this < 0 ? -__this : __this), __this < 0);
}

static const uint16_t *uint_toString(uint32_t __this) {
  return internalIntToString(__this, 0);
}

static const uint16_t *internalIntToString(uint32_t value, uint8_t sign) {
  if (value == 0) {
    return (const uint16_t *)__string_1_0;
  }

  if (value == 1) {
    return sign ? (const uint16_t *)__string_2_1 : (const uint16_t *)__string_3_1;
  }

  uint32_t length = (uint32_t)((sign ? 1 : 0) + (value >= 100000000 ? value >= 1000000000 ? 10 : 9 : value >= 10000 ? value >= 1000000 ? value >= 10000000 ? 8 : 7 : value >= 100000 ? 6 : 5 : value >= 100 ? value >= 1000 ? 4 : 3 : value >= 10 ? 2 : 1));
  uint8_t *ptr = (uint8_t *)string_new(length);
  uint8_t *end = ptr + 4 + (length << 1);

  if (sign) {
    *(uint16_t *)(ptr + 4) = 45;
  }

  while (value != 0) {
    end = end + -2;
    *(uint16_t *)end = (uint16_t)(value % 10 + 48);
    value = value / 10;
  }

  return (const uint16_t *)ptr;
}

static const uint16_t *string_new(uint32_t length) {
  uint8_t *ptr = malloc((length << 1) + 4);
  *(uint32_t *)ptr = length;

  return (const uint16_t *)ptr;
}

static int32_t string_length(const uint16_t *__this) {
  return *(int32_t *)__this;
}

static uint16_t string_op_get(const uint16_t *__this, int32_t index) {
  if ((uint32_t)index < (uint32_t)string_length(__this)) {
    return *(uint16_t *)((uint8_t *)__this + 4 + (index << 1));
  }

  return 0;
}

static uint8_t string_op_equals(const uint16_t *__this, const uint16_t *other) {
  if ((uint8_t *)__this == (uint8_t *)other) {
    return 1;
  }

  if ((uint8_t *)__this == NULL || (uint8_t *)other == NULL) {
    return 0;
  }

  int32_t length = string_length(__this);

  if (length != string_length(other)) {
    return 0;
  }

  return memcmp((uint8_t *)__this + 4, (uint8_t *)other + 4, (uint32_t)length << 1) == 0;
}

static const uint16_t *string_slice(const uint16_t *__this, int32_t start, int32_t end) {
  int32_t length = string_length(__this);

  if (start < 0) {
    start = start + length;
  }

  if (end < 0) {
    end = end + length;
  }

  if (start < 0) {
    start = 0;
  }

  else if (start > length) {
    start = length;
  }

  if (end < start) {
    end = start;
  }

  else if (end > length) {
    end = length;
  }

  uint32_t range = (uint32_t)(end - start);
  const uint16_t *ptr = string_new(range);
  memcpy((uint8_t *)ptr + 4, (uint8_t *)__this + 4 + (start << 1), range << 1);

  return ptr;
}

static uint8_t string_startsWith(const uint16_t *__this, const uint16_t *text) {
  int32_t textLength = string_length(text);

  if (string_length(__this) < textLength) {
    return 0;
  }

  return memcmp((uint8_t *)__this + 4, (uint8_t *)text + 4, (uint32_t)textLength << 1) == 0;
}

static uint8_t string_endsWith(const uint16_t *__this, const uint16_t *text) {
  int32_t thisLength = string_length(__this);
  int32_t textLength = string_length(text);

  if (thisLength < textLength) {
    return 0;
  }

  return memcmp((uint8_t *)__this + 4 + ((thisLength - textLength) << 1), (uint8_t *)text + 4, (uint32_t)textLength << 1) == 0;
}

static int32_t string_lastIndexOf(const uint16_t *__this, const uint16_t *text) {
  int32_t thisLength = string_length(__this);
  int32_t textLength = string_length(text);

  if (thisLength >= textLength) {
    int32_t i = thisLength - textLength;

    while (i >= 0) {
      if (memcmp((uint8_t *)__this + 4 + (i << 1), (uint8_t *)text + 4, (uint32_t)textLength << 1) == 0) {
        return i;
      }

      i = i - 1;
    }
  }

  return -1;
}

const uint16_t *cstring_to_utf16(uint8_t *utf8) {
  if (utf8 == NULL) {
    return NULL;
  }

  uint32_t utf16_length = 0;
  uint8_t a = 0;
  uint8_t b = 0;
  uint8_t c = 0;
  uint8_t d = 0;
  uint32_t i = 0;

  while ((a = *(utf8 + i)) != 0) {
    i = i + 1;
    uint32_t codePoint = 0;

    if ((b = *(utf8 + i)) != 0 && a >= 192) {
      i = i + 1;

      if ((c = *(utf8 + i)) != 0 && a >= 224) {
        i = i + 1;

        if ((d = *(utf8 + i)) != 0 && a >= 240) {
          i = i + 1;
          codePoint = (a & 7) << 18 | (b & 63) << 12 | (c & 63) << 6 | (d & 63);
        }

        else {
          codePoint = (a & 15) << 12 | (b & 63) << 6 | (c & 63);
        }
      }

      else {
        codePoint = (a & 31) << 6 | (b & 63);
      }
    }

    else {
      codePoint = a;
    }

    utf16_length = utf16_length + (uint32_t)(codePoint < 65536 ? 1 : 2);
  }

  const uint16_t *output = string_new(utf16_length);
  uint16_t *utf16 = (uint16_t *)output + 2;
  i = 0;

  while ((a = *(utf8 + i)) != 0) {
    i = i + 1;
    uint32_t codePoint = 0;

    if ((b = *(utf8 + i)) != 0 && a >= 192) {
      i = i + 1;

      if ((c = *(utf8 + i)) != 0 && a >= 224) {
        i = i + 1;

        if ((d = *(utf8 + i)) != 0 && a >= 240) {
          i = i + 1;
          codePoint = (a & 7) << 18 | (b & 63) << 12 | (c & 63) << 6 | (d & 63);
        }

        else {
          codePoint = (a & 15) << 12 | (b & 63) << 6 | (c & 63);
        }
      }

      else {
        codePoint = (a & 31) << 6 | (b & 63);
      }
    }

    else {
      codePoint = a;
    }

    if (codePoint < 65536) {
      *utf16 = (uint16_t)codePoint;
    }

    else {
      *utf16 = (uint16_t)((codePoint >> 10) + 55232);
      utf16 = utf16 + 1;
      *utf16 = (uint16_t)((codePoint & 1023) + 56320);
    }

    utf16 = utf16 + 1;
  }

  return output;
}

uint8_t *utf16_to_cstring(const uint16_t *input) {
  if ((uint32_t *)input == NULL) {
    return NULL;
  }

  uint32_t utf16_length = *(uint32_t *)input;
  uint32_t utf8_length = 0;
  uint16_t *utf16 = (uint16_t *)input + 2;
  uint32_t i = 0;

  while (i < utf16_length) {
    uint32_t codePoint = 0;
    uint16_t a = *(utf16 + i);
    i = i + 1;

    if (i < utf16_length && a >= 55296 && a <= 56319) {
      uint16_t b = *(utf16 + i);
      i = i + 1;
      codePoint = (a << 10) + b - 56613888;
    }

    else {
      codePoint = a;
    }

    utf8_length = utf8_length + (uint32_t)(codePoint < 128 ? 1 : codePoint < 2048 ? 2 : codePoint < 65536 ? 3 : 4);
  }

  uint8_t *utf8 = malloc(utf8_length + 1);
  uint8_t *next = utf8;
  i = 0;

  while (i < utf16_length) {
    uint32_t codePoint = 0;
    uint16_t a = *(utf16 + i);
    i = i + 1;

    if (i < utf16_length && a >= 55296 && a <= 56319) {
      uint16_t b = *(utf16 + i);
      i = i + 1;
      codePoint = (a << 10) + b - 56613888;
    }

    else {
      codePoint = a;
    }

    if (codePoint < 128) {
      *next = (uint8_t)codePoint;
    }

    else {
      if (codePoint < 2048) {
        *next = (uint8_t)((codePoint >> 6 & 31) | 192);
      }

      else {
        if (codePoint < 65536) {
          *next = (uint8_t)((codePoint >> 12 & 15) | 224);
        }

        else {
          *next = (uint8_t)((codePoint >> 18 & 7) | 240);
          next = next + 1;
          *next = (uint8_t)((codePoint >> 12 & 63) | 128);
        }

        next = next + 1;
        *next = (uint8_t)((codePoint >> 6 & 63) | 128);
      }

      next = next + 1;
      *next = (uint8_t)((codePoint & 63) | 128);
    }

    next = next + 1;
  }

  *next = 0;

  return utf8;
}

static void ByteArray_set16(struct ByteArray *array, int32_t index, int32_t value) {
  ByteArray_set(array, index, (uint8_t)value);
  ByteArray_set(array, index + 1, (uint8_t)(value >> 8));
}

static void ByteArray_set32(struct ByteArray *array, int32_t index, int32_t value) {
  ByteArray_set(array, index, (uint8_t)value);
  ByteArray_set(array, index + 1, (uint8_t)(value >> 8));
  ByteArray_set(array, index + 2, (uint8_t)(value >> 16));
  ByteArray_set(array, index + 3, (uint8_t)(value >> 24));
}

static void ByteArray_append32(struct ByteArray *array, int32_t value) {
  ByteArray_append(array, (uint8_t)value);
  ByteArray_append(array, (uint8_t)(value >> 8));
  ByteArray_append(array, (uint8_t)(value >> 16));
  ByteArray_append(array, (uint8_t)(value >> 24));
}

static void ByteArray_setString(struct ByteArray *array, int32_t index, const uint16_t *text) {
  int32_t length = string_length(text);
  assert(index >= 0 && index + (length << 1) <= ByteArray_length(array));
  memcpy(array->_data + index, (uint8_t *)text + 4, (uint32_t)length << 1);
}

int32_t ByteArray_length(struct ByteArray *__this) {
  return (int32_t)__this->_length;
}

uint8_t *ByteArray_bytes(struct ByteArray *__this) {
  return __this->_data;
}

void ByteArray_clear(struct ByteArray *__this) {
  __this->_length = 0;
}

uint8_t ByteArray_get(struct ByteArray *__this, int32_t index) {
  assert((uint32_t)index < __this->_length);

  return *(__this->_data + index);
}

void ByteArray_set(struct ByteArray *__this, int32_t index, uint8_t value) {
  assert((uint32_t)index < __this->_length);
  *(__this->_data + index) = value;
}

void ByteArray_append(struct ByteArray *__this, uint8_t value) {
  uint32_t offset = __this->_length;
  ByteArray_resize(__this, (int32_t)offset + 1);
  *(__this->_data + offset) = value;
}

void ByteArray_resize(struct ByteArray *__this, int32_t length) {
  if ((uint32_t)length > __this->_capacity) {
    uint32_t capacity = (uint32_t)length << 1;
    uint8_t *data = malloc(capacity);
    memcpy(data, __this->_data, __this->_length);
    __this->_capacity = capacity;
    __this->_data = data;
  }

  __this->_length = (uint32_t)length;
}

static void CResult_emitIndent(struct CResult *__this) {
  int32_t i = __this->indent;

  while (i > 0) {
    StringBuilder_append(__this->code, (const uint16_t *)__string_4);
    i = i - 1;
  }
}

static void CResult_emitNewlineBefore(struct CResult *__this, struct Node *node) {
  if (__this->previousNode != NULL && (!isCompactNodeKind(__this->previousNode->kind) || !isCompactNodeKind(node->kind))) {
    StringBuilder_appendChar(__this->code, 10);
  }

  __this->previousNode = NULL;
}

static void CResult_emitNewlineAfter(struct CResult *__this, struct Node *node) {
  __this->previousNode = node;
}

static void CResult_emitStatements(struct CResult *__this, struct Node *node) {
  while (node != NULL) {
    CResult_emitStatement(__this, node);
    node = node->nextSibling;
  }
}

static void CResult_emitBlock(struct CResult *__this, struct Node *node) {
  __this->previousNode = NULL;
  StringBuilder_append(__this->code, (const uint16_t *)__string_5);
  __this->indent = __this->indent + 1;
  CResult_emitStatements(__this, node->firstChild);
  __this->indent = __this->indent - 1;
  CResult_emitIndent(__this);
  StringBuilder_appendChar(__this->code, 125);
  __this->previousNode = NULL;
}

static void CResult_emitUnary(struct CResult *__this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator) {
  uint8_t isPostfix = isUnaryPostfix(node->kind);
  int32_t operatorPrecedence = isPostfix ? 14 : 13;
  struct StringBuilder *code = __this->code;

  if (parentPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 40);
  }

  if (!isPostfix) {
    StringBuilder_append(code, operator);
  }

  CResult_emitExpression(__this, Node_unaryValue(node), operatorPrecedence);

  if (isPostfix) {
    StringBuilder_append(code, operator);
  }

  if (parentPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 41);
  }
}

static void CResult_emitBinary(struct CResult *__this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator, int32_t operatorPrecedence) {
  int32_t kind = node->kind;
  uint8_t isRightAssociative = kind == 49;
  uint8_t needsParentheses = parentPrecedence > operatorPrecedence;
  int32_t parentKind = node->parent->kind;
  struct StringBuilder *code = __this->code;

  if ((parentKind == 61 && kind == 60) || (parentKind == 51 && kind == 50) || ((parentKind == 54 || parentKind == 63) && (kind == 54 || kind == 63)) || ((kind == 48 || kind == 67) && (parentKind == 50 || parentKind == 51 || parentKind == 52 || parentKind == 65 || parentKind == 66))) {
    needsParentheses = 1;
  }

  if (needsParentheses) {
    StringBuilder_appendChar(code, 40);
  }

  CResult_emitExpression(__this, Node_binaryLeft(node), isRightAssociative ? (int32_t)((int32_t)operatorPrecedence + 1) : operatorPrecedence);
  StringBuilder_append(code, operator);
  CResult_emitExpression(__this, Node_binaryRight(node), isRightAssociative ? operatorPrecedence : (int32_t)((int32_t)operatorPrecedence + 1));

  if (needsParentheses) {
    StringBuilder_appendChar(code, 41);
  }
}

static void CResult_emitCommaSeparatedExpressions(struct CResult *__this, struct Node *start, struct Node *stop) {
  while (start != stop) {
    CResult_emitExpression(__this, start, 0);
    start = start->nextSibling;

    if (start != stop) {
      StringBuilder_append(__this->code, (const uint16_t *)__string_6);
    }
  }
}

static void CResult_emitSymbolName(struct CResult *__this, struct Symbol *symbol) {
  if (symbol->kind == 4) {
    StringBuilder_appendChar(StringBuilder_append(__this->code, Symbol_parent(symbol)->name), 95);
  }

  StringBuilder_append(__this->code, !string_op_equals(symbol->rename, NULL) ? symbol->rename : symbol->name);
}

static void CResult_emitExpression(struct CResult *__this, struct Node *node, int32_t parentPrecedence) {
  struct StringBuilder *code = __this->code;
  assert(node->resolvedType != NULL);

  if (node->kind == 29) {
    CResult_emitSymbolName(__this, node->symbol);
  }

  else if (node->kind == 31) {
    StringBuilder_append(code, (const uint16_t *)__string_7_NULL);
  }

  else if (node->kind == 22) {
    StringBuilder_appendChar(code, node->intValue != 0 ? 49 : 48);
  }

  else if (node->kind == 28) {
    StringBuilder_append(code, Type_isUnsigned(node->resolvedType) ? uint_toString((uint32_t)node->intValue) : int_toString(node->intValue));
  }

  else if (node->kind == 34) {
    int32_t id = __this->nextStringLiteral;
    struct StringBuilder *builder = StringBuilder_new();
    StringBuilder_append(StringBuilder_append(builder, (const uint16_t *)__string_8___string_), int_toString(id));
    const uint16_t *value = node->stringValue;
    struct StringBuilder *codePrefix = __this->codePrefix;
    int32_t length = string_length(value);
    int32_t i = 0;

    if (!__this->hasStrings) {
      StringBuilder_append(codePrefix, (const uint16_t *)__string_9_ifdef_THINSCRIPT_BIG_ENDIAN);
      __this->hasStrings = 1;
    }

    uint8_t underscore = 1;
    i = 0;

    while (i < length && i < 32) {
      uint16_t c = string_op_get(value, i);

      if (isAlpha(c) || isNumber(c)) {
        if (underscore) {
          StringBuilder_appendChar(builder, 95);
          underscore = 0;
        }

        StringBuilder_appendChar(builder, c);
      }

      else {
        underscore = 1;
      }

      i = i + 1;
    }

    const uint16_t *name = StringBuilder_finish(builder);
    StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(codePrefix, (const uint16_t *)__string_10_static_const_uint32_t), name), (const uint16_t *)__string_11), int_toString(length));
    i = 0;

    while (i < length) {
      StringBuilder_append(codePrefix, (const uint16_t *)__string_12_S);
      cEmitCharacter(codePrefix, string_op_get(value, i));

      if (i + 1 < length) {
        StringBuilder_append(codePrefix, i % 32 == 20 ? (const uint16_t *)__string_13 : (const uint16_t *)__string_14);
        cEmitCharacter(codePrefix, string_op_get(value, i + 1));
        StringBuilder_appendChar(codePrefix, 41);
      }

      else {
        StringBuilder_append(codePrefix, (const uint16_t *)__string_15_0);
      }

      i = i + 2;
    }

    StringBuilder_append(codePrefix, (const uint16_t *)__string_16);
    __this->nextStringLiteral = __this->nextStringLiteral + 1;
    StringBuilder_append(StringBuilder_append(code, (const uint16_t *)__string_17_const_uint16_t), name);
  }

  else if (node->kind == 24) {
    if (parentPrecedence > 13) {
      StringBuilder_appendChar(code, 40);
    }

    StringBuilder_appendChar(code, 40);
    CResult_emitType(__this, node->resolvedType, 0);
    StringBuilder_appendChar(code, 41);
    CResult_emitExpression(__this, Node_castValue(node), 13);

    if (parentPrecedence > 13) {
      StringBuilder_appendChar(code, 41);
    }
  }

  else if (node->kind == 25) {
    struct Node *target = Node_dotTarget(node);
    CResult_emitExpression(__this, target, 15);
    StringBuilder_append(code, Type_isReference(target->resolvedType) ? (const uint16_t *)__string_18 : (const uint16_t *)__string_19);
    CResult_emitSymbolName(__this, node->symbol);
  }

  else if (node->kind == 26) {
    if (parentPrecedence > 1) {
      StringBuilder_appendChar(code, 40);
    }

    CResult_emitExpression(__this, Node_hookValue(node), 2);
    StringBuilder_append(code, (const uint16_t *)__string_20);
    CResult_emitExpression(__this, Node_hookTrue(node), 1);
    StringBuilder_append(code, (const uint16_t *)__string_21);
    CResult_emitExpression(__this, Node_hookFalse(node), 1);

    if (parentPrecedence > 1) {
      StringBuilder_appendChar(code, 41);
    }
  }

  else if (node->kind == 23) {
    struct Node *value = Node_callValue(node);
    CResult_emitSymbolName(__this, value->symbol);
    StringBuilder_appendChar(code, 40);

    if (value->kind == 25) {
      CResult_emitExpression(__this, Node_dotTarget(value), 0);

      if (value->nextSibling != NULL) {
        StringBuilder_append(code, (const uint16_t *)__string_22);
      }
    }

    CResult_emitCommaSeparatedExpressions(__this, value->nextSibling, NULL);
    StringBuilder_appendChar(code, 41);
  }

  else if (node->kind == 30) {
    StringBuilder_append(code, (const uint16_t *)__string_23_calloc_1_sizeof);
    CResult_emitType(__this, node->resolvedType, 2);
    StringBuilder_append(code, (const uint16_t *)__string_24);
  }

  else if (node->kind == 38) {
    CResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_25);
  }

  else if (node->kind == 39) {
    CResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_26);
  }

  else if (node->kind == 40) {
    CResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_27);
  }

  else if (node->kind == 41) {
    CResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_28);
  }

  else if (node->kind == 43) {
    CResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_29);
  }

  else if (node->kind == 44) {
    CResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_30);
  }

  else if (node->kind == 45) {
    CResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_31);
  }

  else if (node->kind == 46) {
    CResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_32);
  }

  else if (node->kind == 47) {
    CResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_33);
  }

  else if (node->kind == 48) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_34, 10);
  }

  else if (node->kind == 49) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_35, 1);
  }

  else if (node->kind == 50) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_36, 6);
  }

  else if (node->kind == 51) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_37, 4);
  }

  else if (node->kind == 52) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_38, 5);
  }

  else if (node->kind == 53) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_39, 11);
  }

  else if (node->kind == 54) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_40, 7);
  }

  else if (node->kind == 56) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_41, 8);
  }

  else if (node->kind == 57) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_42, 8);
  }

  else if (node->kind == 58) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_43, 8);
  }

  else if (node->kind == 59) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_44, 8);
  }

  else if (node->kind == 60) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_45, 3);
  }

  else if (node->kind == 61) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_46, 2);
  }

  else if (node->kind == 62) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_47, 11);
  }

  else if (node->kind == 63) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_48, 7);
  }

  else if (node->kind == 64) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_49, 11);
  }

  else if (node->kind == 65) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_50, 9);
  }

  else if (node->kind == 66) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_51, 9);
  }

  else if (node->kind == 67) {
    CResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_52, 10);
  }

  else {
    assert(0);
  }
}

static uint8_t CResult_shouldEmitClass(struct CResult *__this, struct Node *node) {
  assert(node->kind == 9);

  return node->symbol->kind == 0 && node->symbol != __this->context->stringType->symbol;
}

static void CResult_emitType(struct CResult *__this, struct Type *originalType, int32_t mode) {
  struct CheckContext *context = __this->context;
  struct StringBuilder *code = __this->code;
  struct Type *type = originalType;

  if (Type_isEnum(type)) {
    type = Type_underlyingType(type, __this->context);
  }

  else {
    while (type->pointerTo != NULL) {
      type = type->pointerTo;
    }
  }

  if (Type_isClass(type)) {
    StringBuilder_append(code, (const uint16_t *)__string_53_struct);
  }

  if (type == context->boolType || type == context->byteType) {
    StringBuilder_append(code, (const uint16_t *)__string_54_uint8_t);
  }

  else if (type == context->sbyteType) {
    StringBuilder_append(code, (const uint16_t *)__string_55_int8_t);
  }

  else if (type == context->intType) {
    StringBuilder_append(code, (const uint16_t *)__string_56_int32_t);
  }

  else if (type == context->shortType) {
    StringBuilder_append(code, (const uint16_t *)__string_57_int16_t);
  }

  else if (type == context->stringType) {
    StringBuilder_append(code, (const uint16_t *)__string_58_const_uint16_t);
  }

  else if (type == context->uintType) {
    StringBuilder_append(code, (const uint16_t *)__string_59_uint32_t);
  }

  else if (type == context->ushortType) {
    StringBuilder_append(code, (const uint16_t *)__string_60_uint16_t);
  }

  else {
    CResult_emitSymbolName(__this, type->symbol);
  }

  if (originalType->pointerTo != NULL) {
    StringBuilder_appendChar(code, 32);

    while (originalType->pointerTo != NULL) {
      StringBuilder_appendChar(code, 42);
      originalType = originalType->pointerTo;
    }
  }

  else if (mode != 2) {
    if (Type_isReference(type)) {
      StringBuilder_append(code, (const uint16_t *)__string_61);
    }

    else if (mode == 1) {
      StringBuilder_appendChar(code, 32);
    }
  }
}

static void CResult_emitStatement(struct CResult *__this, struct Node *node) {
  struct StringBuilder *code = __this->code;

  if (node->kind == 16) {
    CResult_emitNewlineBefore(__this, node);
    CResult_emitIndent(__this);

    while (1) {
      StringBuilder_append(code, (const uint16_t *)__string_62_if);
      CResult_emitExpression(__this, Node_ifValue(node), 0);
      StringBuilder_append(code, (const uint16_t *)__string_63);
      CResult_emitBlock(__this, Node_ifTrue(node));
      struct Node *no = Node_ifFalse(node);

      if (no == NULL) {
        StringBuilder_appendChar(code, 10);

        break;
      }

      StringBuilder_append(code, (const uint16_t *)__string_64);
      CResult_emitIndent(__this);
      StringBuilder_append(code, (const uint16_t *)__string_65_else);

      if (no->firstChild == NULL || no->firstChild != no->lastChild || no->firstChild->kind != 16) {
        CResult_emitBlock(__this, no);
        StringBuilder_appendChar(code, 10);

        break;
      }

      node = no->firstChild;
    }

    CResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 20) {
    CResult_emitNewlineBefore(__this, node);
    CResult_emitIndent(__this);
    StringBuilder_append(code, (const uint16_t *)__string_66_while);
    CResult_emitExpression(__this, Node_whileValue(node), 0);
    StringBuilder_append(code, (const uint16_t *)__string_67);
    CResult_emitBlock(__this, Node_whileBody(node));
    StringBuilder_appendChar(code, 10);
    CResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 8) {
    CResult_emitNewlineBefore(__this, node);
    CResult_emitIndent(__this);
    StringBuilder_append(code, (const uint16_t *)__string_68_break);
    CResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 11) {
    CResult_emitNewlineBefore(__this, node);
    CResult_emitIndent(__this);
    StringBuilder_append(code, (const uint16_t *)__string_69_continue);
    CResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 14) {
    CResult_emitNewlineBefore(__this, node);
    CResult_emitIndent(__this);
    CResult_emitExpression(__this, Node_expressionValue(node), 0);
    StringBuilder_append(code, (const uint16_t *)__string_70);
    CResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 12) {
  }

  else if (node->kind == 17) {
    struct Node *value = Node_returnValue(node);
    CResult_emitNewlineBefore(__this, node);
    CResult_emitIndent(__this);

    if (value != NULL) {
      StringBuilder_append(code, (const uint16_t *)__string_71_return);
      CResult_emitExpression(__this, value, 0);
      StringBuilder_append(code, (const uint16_t *)__string_72);
    }

    else {
      StringBuilder_append(code, (const uint16_t *)__string_73_return);
    }

    CResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 7) {
    if (node->parent->kind == 7) {
      CResult_emitStatements(__this, node->firstChild);
    }

    else {
      CResult_emitNewlineBefore(__this, node);
      CResult_emitIndent(__this);
      CResult_emitBlock(__this, node);
      StringBuilder_appendChar(code, 10);
      CResult_emitNewlineAfter(__this, node);
    }
  }

  else if (node->kind == 19) {
    CResult_emitNewlineBefore(__this, node);
    struct Node *child = node->firstChild;

    while (child != NULL) {
      struct Node *value = Node_variableValue(child);
      CResult_emitIndent(__this);
      CResult_emitType(__this, child->symbol->resolvedType, 1);
      CResult_emitSymbolName(__this, child->symbol);
      assert(value != NULL);
      StringBuilder_append(code, (const uint16_t *)__string_74);
      CResult_emitExpression(__this, value, 0);
      StringBuilder_append(code, (const uint16_t *)__string_75);
      child = child->nextSibling;
    }

    CResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 10 || node->kind == 13) {
  }

  else {
    assert(0);
  }
}

static void CResult_emitIncludes(struct CResult *__this, struct StringBuilder *code, int32_t mode) {
  if (mode == 0) {
    StringBuilder_append(code, (const uint16_t *)__string_76_include_stdint_h);
  }

  else {
    StringBuilder_append(StringBuilder_append(StringBuilder_append(code, (const uint16_t *)__string_77_include), __this->headerName), (const uint16_t *)__string_78);
    StringBuilder_append(code, (const uint16_t *)__string_79_include_stdlib_h);
    StringBuilder_append(code, (const uint16_t *)__string_80_include_string_h);
  }
}

static void CResult_emitTypeDeclarations(struct CResult *__this, struct Node *node, int32_t mode) {
  struct StringBuilder *code = __this->code;

  while (node != NULL) {
    if (node->kind == 9) {
      if (CResult_shouldEmitClass(__this, node) && (Node_isDeclareOrExtern(node) ? mode == 0 : mode == 1)) {
        CResult_emitNewlineBefore(__this, node);
        StringBuilder_append(StringBuilder_append(StringBuilder_append(code, (const uint16_t *)__string_81_struct), node->symbol->name), (const uint16_t *)__string_82);
      }
    }

    node = node->nextSibling;
  }
}

static void CResult_emitTypeDefinitions(struct CResult *__this, struct Node *node, int32_t mode) {
  struct StringBuilder *code = __this->code;

  while (node != NULL) {
    if (node->kind == 9) {
      if (CResult_shouldEmitClass(__this, node) && mode != 0) {
        CResult_emitNewlineBefore(__this, node);
        StringBuilder_append(code, (const uint16_t *)__string_83_struct);
        CResult_emitSymbolName(__this, node->symbol);
        StringBuilder_append(code, (const uint16_t *)__string_84);
        __this->indent = __this->indent + 1;
        struct Node *child = node->firstChild;

        while (child != NULL) {
          if (child->kind == 6) {
            CResult_emitIndent(__this);
            CResult_emitType(__this, child->symbol->resolvedType, 1);
            CResult_emitSymbolName(__this, child->symbol);
            StringBuilder_append(code, (const uint16_t *)__string_85);
          }

          child = child->nextSibling;
        }

        __this->indent = __this->indent - 1;
        StringBuilder_append(code, (const uint16_t *)__string_86);
        CResult_emitNewlineAfter(__this, node);
      }
    }

    else if (node->kind == 13) {
      if (mode == 0 && Node_isExtern(node)) {
        CResult_emitNewlineBefore(__this, node);
        StringBuilder_append(code, (const uint16_t *)__string_87_enum);
        __this->indent = __this->indent + 1;
        struct Node *child = node->firstChild;

        while (child != NULL) {
          assert(child->kind == 6);
          CResult_emitIndent(__this);
          CResult_emitSymbolName(__this, node->symbol);
          StringBuilder_append(code, (const uint16_t *)__string_88__);
          CResult_emitSymbolName(__this, child->symbol);
          StringBuilder_append(code, (const uint16_t *)__string_89);
          StringBuilder_append(code, int_toString(child->symbol->offset));
          child = child->nextSibling;
          StringBuilder_append(code, child != NULL ? (const uint16_t *)__string_90 : (const uint16_t *)__string_91);
        }

        __this->indent = __this->indent - 1;
        CResult_emitIndent(__this);
        StringBuilder_append(code, (const uint16_t *)__string_92);
        CResult_emitNewlineAfter(__this, node);
      }
    }

    node = node->nextSibling;
  }
}

static uint8_t CResult_shouldEmitFunction(struct CResult *__this, struct Symbol *symbol) {
  return symbol->kind != 5 || (!string_op_equals(symbol->name, (const uint16_t *)__string_93_malloc) && !string_op_equals(symbol->name, (const uint16_t *)__string_94_memcpy) && !string_op_equals(symbol->name, (const uint16_t *)__string_95_memcmp));
}

static void CResult_emitFunctionDeclarations(struct CResult *__this, struct Node *node, int32_t mode) {
  struct StringBuilder *code = __this->code;

  while (node != NULL) {
    if (node->kind == 15 && (mode != 0 || Node_isDeclareOrExtern(node))) {
      struct Symbol *symbol = node->symbol;

      if (CResult_shouldEmitFunction(__this, symbol)) {
        struct Node *returnType = Node_functionReturnType(node);
        struct Node *child = Node_functionFirstArgument(node);
        CResult_emitNewlineBefore(__this, node);

        if (!Node_isDeclareOrExtern(node)) {
          StringBuilder_append(code, (const uint16_t *)__string_96_static);
        }

        CResult_emitType(__this, returnType->resolvedType, 1);
        CResult_emitSymbolName(__this, symbol);
        StringBuilder_appendChar(code, 40);

        if (symbol->kind == 4) {
          child->symbol->rename = (const uint16_t *)__string_97___this;
        }

        while (child != returnType) {
          assert(child->kind == 6);
          CResult_emitType(__this, child->symbol->resolvedType, 1);
          CResult_emitSymbolName(__this, child->symbol);
          child = child->nextSibling;

          if (child != returnType) {
            StringBuilder_append(code, (const uint16_t *)__string_98);
          }
        }

        StringBuilder_append(code, (const uint16_t *)__string_99);
      }
    }

    else if (node->kind == 9) {
      CResult_emitFunctionDeclarations(__this, node->firstChild, mode);
    }

    node = node->nextSibling;
  }
}

static void CResult_emitGlobalVariables(struct CResult *__this, struct Node *node, int32_t mode) {
  struct StringBuilder *code = __this->code;

  while (node != NULL) {
    if (node->kind == 6 && (mode != 0 || Node_isExtern(node))) {
      struct Node *value = Node_variableValue(node);
      CResult_emitNewlineBefore(__this, node);

      if (!Node_isDeclareOrExtern(node)) {
        StringBuilder_append(code, (const uint16_t *)__string_100_static);
      }

      CResult_emitType(__this, node->symbol->resolvedType, 1);
      CResult_emitSymbolName(__this, node->symbol);
      StringBuilder_append(code, (const uint16_t *)__string_101);
      CResult_emitExpression(__this, value, 0);
      StringBuilder_append(code, (const uint16_t *)__string_102);
    }

    else if (node->kind == 19) {
      CResult_emitGlobalVariables(__this, node->firstChild, mode);
    }

    node = node->nextSibling;
  }
}

static void CResult_emitFunctionDefinitions(struct CResult *__this, struct Node *node) {
  struct StringBuilder *code = __this->code;

  while (node != NULL) {
    if (node->kind == 15) {
      struct Node *body = Node_functionBody(node);
      struct Symbol *symbol = node->symbol;

      if (body != NULL && CResult_shouldEmitFunction(__this, symbol)) {
        struct Node *returnType = Node_functionReturnType(node);
        struct Node *child = node->firstChild;
        CResult_emitNewlineBefore(__this, node);

        if (!Node_isDeclareOrExtern(node)) {
          StringBuilder_append(code, (const uint16_t *)__string_103_static);
        }

        CResult_emitType(__this, returnType->resolvedType, 1);
        CResult_emitSymbolName(__this, symbol);
        StringBuilder_appendChar(code, 40);

        while (child != returnType) {
          assert(child->kind == 6);
          CResult_emitType(__this, child->symbol->resolvedType, 1);
          CResult_emitSymbolName(__this, child->symbol);
          child = child->nextSibling;

          if (child != returnType) {
            StringBuilder_append(code, (const uint16_t *)__string_104);
          }
        }

        StringBuilder_append(code, (const uint16_t *)__string_105);
        CResult_emitBlock(__this, Node_functionBody(node));
        StringBuilder_appendChar(code, 10);
        CResult_emitNewlineAfter(__this, node);
      }
    }

    else if (node->kind == 9) {
      CResult_emitFunctionDefinitions(__this, node->firstChild);
    }

    node = node->nextSibling;
  }
}

static void CResult_finishImplementation(struct CResult *__this) {
  if (__this->hasStrings) {
    StringBuilder_append(__this->codePrefix, (const uint16_t *)__string_106_undef_S);
  }
}

static void cEmitCharacter(struct StringBuilder *builder, uint16_t c) {
  if (isASCII(c)) {
    StringBuilder_appendChar(builder, 39);

    if (c == 92 || c == 39) {
      StringBuilder_appendChar(builder, 92);
    }

    StringBuilder_appendChar(builder, c);
    StringBuilder_appendChar(builder, 39);
  }

  else if (c == 0) {
    StringBuilder_append(builder, (const uint16_t *)__string_107_0);
  }

  else if (c == 13) {
    StringBuilder_append(builder, (const uint16_t *)__string_108_r);
  }

  else if (c == 10) {
    StringBuilder_append(builder, (const uint16_t *)__string_109_n);
  }

  else if (c == 9) {
    StringBuilder_append(builder, (const uint16_t *)__string_110_t);
  }

  else {
    StringBuilder_append(builder, ushort_toString(c));
  }
}

static void cEmit(struct Compiler *compiler) {
  struct Node *child = compiler->global->firstChild;
  struct StringBuilder *temporaryCode = StringBuilder_new();
  struct StringBuilder *headerCode = StringBuilder_new();
  struct StringBuilder *implementationCode = StringBuilder_new();
  struct CResult *result = calloc(1, sizeof(struct CResult));
  result->context = compiler->context;
  result->code = temporaryCode;
  result->codePrefix = implementationCode;
  result->headerName = replaceFileExtension(compiler->outputName, (const uint16_t *)__string_111_h);

  if (child != NULL) {
    CResult_emitIncludes(result, implementationCode, 1);
    CResult_emitNewlineAfter(result, child);
    CResult_emitTypeDeclarations(result, child, 1);
    CResult_emitNewlineAfter(result, child);
    CResult_emitTypeDefinitions(result, child, 1);
    CResult_emitNewlineAfter(result, child);
    CResult_emitFunctionDeclarations(result, child, 1);
    CResult_emitNewlineAfter(result, child);
    CResult_emitGlobalVariables(result, child, 1);
    CResult_emitNewlineAfter(result, child);
    CResult_emitFunctionDefinitions(result, child);
    CResult_finishImplementation(result);
    StringBuilder_append(implementationCode, StringBuilder_finish(temporaryCode));
    result->code = headerCode;
    CResult_emitIncludes(result, headerCode, 0);
    CResult_emitNewlineAfter(result, child);
    CResult_emitTypeDeclarations(result, child, 0);
    CResult_emitNewlineAfter(result, child);
    CResult_emitTypeDefinitions(result, child, 0);
    CResult_emitNewlineAfter(result, child);
    CResult_emitFunctionDeclarations(result, child, 0);
    CResult_emitNewlineAfter(result, child);
    CResult_emitGlobalVariables(result, child, 0);
    CResult_emitNewlineAfter(result, child);
  }

  compiler->outputC = StringBuilder_finish(implementationCode);
  compiler->outputH = StringBuilder_finish(headerCode);
}

static int32_t CheckContext_allocateGlobalVariableOffset(struct CheckContext *__this, int32_t sizeOf, int32_t alignmentOf) {
  int32_t offset = alignToNextMultipleOf(__this->nextGlobalVariableOffset, alignmentOf);
  __this->nextGlobalVariableOffset = offset + sizeOf;

  return offset;
}

static void addScopeToSymbol(struct Symbol *symbol, struct Scope *parentScope) {
  struct Scope *scope = calloc(1, sizeof(struct Scope));
  scope->parent = parentScope;
  scope->symbol = symbol;
  symbol->scope = scope;
}

static void linkSymbolToNode(struct Symbol *symbol, struct Node *node) {
  node->symbol = symbol;
  node->scope = symbol->scope;
  symbol->range = node->internalRange != NULL ? node->internalRange : node->range;
  symbol->node = node;
}

static void initialize(struct CheckContext *context, struct Node *node, struct Scope *parentScope, int32_t mode) {
  int32_t kind = node->kind;

  if (node->parent != NULL) {
    int32_t parentKind = node->parent->kind;

    if (kind != 6 && kind != 19 && (kind != 15 || parentKind != 9) && (parentKind == 1) != (kind == 9 || kind == 13 || kind == 15 || kind == 10)) {
      Log_error(context->log, node->range, (const uint16_t *)__string_112_This_statement_is_not_allowed_he);
    }
  }

  if (kind == 9 || kind == 13) {
    assert(node->symbol == NULL);
    struct Symbol *symbol = calloc(1, sizeof(struct Symbol));
    symbol->kind = kind == 9 ? 0 : 1;
    symbol->name = node->stringValue;
    symbol->resolvedType = calloc(1, sizeof(struct Type));
    symbol->resolvedType->symbol = symbol;
    symbol->flags = 4;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    Scope_define(parentScope, context->log, symbol, 0);
    parentScope = symbol->scope;
  }

  else if (kind == 15) {
    assert(node->symbol == NULL);
    struct Symbol *symbol = calloc(1, sizeof(struct Symbol));
    symbol->kind = node->parent->kind == 9 ? 4 : 5;
    symbol->name = node->stringValue;

    if (Node_isOperator(node)) {
      if (string_op_equals(symbol->name, (const uint16_t *)__string_113) || string_op_equals(symbol->name, (const uint16_t *)__string_114)) {
        if (Node_functionFirstArgument(node) == Node_functionReturnType(node)) {
          symbol->flags = 8;
          symbol->rename = string_op_equals(symbol->name, (const uint16_t *)__string_115) ? (const uint16_t *)__string_116_op_positive : (const uint16_t *)__string_117_op_negative;
        }

        else {
          symbol->flags = 2;
          symbol->rename = string_op_equals(symbol->name, (const uint16_t *)__string_118) ? (const uint16_t *)__string_119_op_add : (const uint16_t *)__string_120_op_subtract;
        }
      }

      else {
        symbol->rename = string_op_equals(symbol->name, (const uint16_t *)__string_121) ? (const uint16_t *)__string_122_op_remainder : string_op_equals(symbol->name, (const uint16_t *)__string_123) ? (const uint16_t *)__string_124_op_and : string_op_equals(symbol->name, (const uint16_t *)__string_125) ? (const uint16_t *)__string_126_op_multiply : string_op_equals(symbol->name, (const uint16_t *)__string_127) ? (const uint16_t *)__string_128_op_exponent : string_op_equals(symbol->name, (const uint16_t *)__string_129) ? (const uint16_t *)__string_130_op_increment : string_op_equals(symbol->name, (const uint16_t *)__string_131) ? (const uint16_t *)__string_132_op_decrement : string_op_equals(symbol->name, (const uint16_t *)__string_133) ? (const uint16_t *)__string_134_op_divide : string_op_equals(symbol->name, (const uint16_t *)__string_135) ? (const uint16_t *)__string_136_op_lessThan : string_op_equals(symbol->name, (const uint16_t *)__string_137) ? (const uint16_t *)__string_138_op_shiftLeft : string_op_equals(symbol->name, (const uint16_t *)__string_139) ? (const uint16_t *)__string_140_op_equals : string_op_equals(symbol->name, (const uint16_t *)__string_141) ? (const uint16_t *)__string_142_op_greaterThan : string_op_equals(symbol->name, (const uint16_t *)__string_143) ? (const uint16_t *)__string_144_op_shiftRight : string_op_equals(symbol->name, (const uint16_t *)__string_145) ? (const uint16_t *)__string_146_op_get : string_op_equals(symbol->name, (const uint16_t *)__string_147) ? (const uint16_t *)__string_148_op_set : string_op_equals(symbol->name, (const uint16_t *)__string_149) ? (const uint16_t *)__string_150_op_xor : string_op_equals(symbol->name, (const uint16_t *)__string_151) ? (const uint16_t *)__string_152_op_or : string_op_equals(symbol->name, (const uint16_t *)__string_153) ? (const uint16_t *)__string_154_op_complement : NULL;
      }
    }

    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    Scope_define(parentScope, context->log, symbol, Symbol_isSetter(symbol) ? 2 : Symbol_isGetter(symbol) ? 3 : Symbol_isBinaryOperator(symbol) ? 4 : Symbol_isUnaryOperator(symbol) ? 1 : 0);
    parentScope = symbol->scope;

    if (symbol->kind == 4) {
      struct Symbol *parent = Symbol_parent(symbol);
      initializeSymbol(context, parent);
      Node_insertChildBefore(node, Node_functionFirstArgument(node), createVariable((const uint16_t *)__string_155_this, createType(parent->resolvedType), NULL));
    }
  }

  else if (kind == 6) {
    assert(node->symbol == NULL);
    struct Symbol *symbol = calloc(1, sizeof(struct Symbol));
    symbol->kind = node->parent->kind == 9 ? 9 : node->parent->kind == 15 ? 6 : node->parent->kind == 10 || node->parent->kind == 13 ? 7 : node->parent->kind == 19 && node->parent->parent->kind == 1 ? 8 : 10;
    symbol->name = node->stringValue;
    symbol->scope = parentScope;
    linkSymbolToNode(symbol, node);
    Scope_define(parentScope, context->log, symbol, 0);
  }

  else if (kind == 7) {
    if (node->parent->kind != 15) {
      struct Scope *scope = calloc(1, sizeof(struct Scope));
      scope->parent = parentScope;
      parentScope = scope;
    }

    node->scope = parentScope;
  }

  struct Node *child = node->firstChild;

  while (child != NULL) {
    initialize(context, child, parentScope, mode);
    child = child->nextSibling;
  }

  if (kind == 1 && mode == 1) {
    context->boolType = Scope_findLocal(parentScope, (const uint16_t *)__string_156_bool, 0)->resolvedType;
    context->byteType = Scope_findLocal(parentScope, (const uint16_t *)__string_157_byte, 0)->resolvedType;
    context->intType = Scope_findLocal(parentScope, (const uint16_t *)__string_158_int, 0)->resolvedType;
    context->sbyteType = Scope_findLocal(parentScope, (const uint16_t *)__string_159_sbyte, 0)->resolvedType;
    context->shortType = Scope_findLocal(parentScope, (const uint16_t *)__string_160_short, 0)->resolvedType;
    context->stringType = Scope_findLocal(parentScope, (const uint16_t *)__string_161_string, 0)->resolvedType;
    context->uintType = Scope_findLocal(parentScope, (const uint16_t *)__string_162_uint, 0)->resolvedType;
    context->ushortType = Scope_findLocal(parentScope, (const uint16_t *)__string_163_ushort, 0)->resolvedType;
    prepareNativeType(context->boolType, 1, 0);
    prepareNativeType(context->byteType, 1, 48);
    prepareNativeType(context->intType, 4, 32);
    prepareNativeType(context->sbyteType, 1, 32);
    prepareNativeType(context->shortType, 2, 32);
    prepareNativeType(context->stringType, 4, 4);
    prepareNativeType(context->uintType, 4, 48);
    prepareNativeType(context->ushortType, 2, 48);
  }
}

static void prepareNativeType(struct Type *type, int32_t byteSizeAndMaxAlignment, int32_t flags) {
  struct Symbol *symbol = type->symbol;
  symbol->kind = 3;
  symbol->byteSize = byteSizeAndMaxAlignment;
  symbol->maxAlignment = byteSizeAndMaxAlignment;
  symbol->flags = flags;
}

static void forbidFlag(struct CheckContext *context, struct Node *node, int32_t flag, const uint16_t *text) {
  if ((node->flags & flag) != 0) {
    struct Range *range = rangeForFlag(node->firstFlag, flag);

    if (range != NULL) {
      node->flags = node->flags & ~flag;
      Log_error(context->log, range, text);
    }
  }
}

static void requireFlag(struct CheckContext *context, struct Node *node, int32_t flag, const uint16_t *text) {
  if ((node->flags & flag) == 0) {
    node->flags = node->flags | flag;
    Log_error(context->log, node->range, text);
  }
}

static void initializeSymbol(struct CheckContext *context, struct Symbol *symbol) {
  if (symbol->state == 2) {
    assert(symbol->resolvedType != NULL);

    return;
  }

  assert(symbol->state == 0);
  symbol->state = 1;
  struct Node *node = symbol->node;
  forbidFlag(context, node, 2, (const uint16_t *)__string_164_Unsupported_flag_export);
  forbidFlag(context, node, 128, (const uint16_t *)__string_165_Unsupported_flag_protected);
  forbidFlag(context, node, 1024, (const uint16_t *)__string_166_Unsupported_flag_static);

  if (symbol->kind == 0 || symbol->kind == 3) {
    forbidFlag(context, node, 8, (const uint16_t *)__string_167_Cannot_use_get_on_a_class);
    forbidFlag(context, node, 512, (const uint16_t *)__string_168_Cannot_use_set_on_a_class);
    forbidFlag(context, node, 256, (const uint16_t *)__string_169_Cannot_use_public_on_a_class);
    forbidFlag(context, node, 64, (const uint16_t *)__string_170_Cannot_use_private_on_a_class);
  }

  else if (symbol->kind == 1) {
    forbidFlag(context, node, 8, (const uint16_t *)__string_171_Cannot_use_get_on_an_enum);
    forbidFlag(context, node, 512, (const uint16_t *)__string_172_Cannot_use_set_on_an_enum);
    forbidFlag(context, node, 256, (const uint16_t *)__string_173_Cannot_use_public_on_an_enum);
    forbidFlag(context, node, 64, (const uint16_t *)__string_174_Cannot_use_private_on_an_enum);
    symbol->resolvedType = calloc(1, sizeof(struct Type));
    symbol->resolvedType->symbol = symbol;
    struct Symbol *underlyingSymbol = Type_underlyingType(symbol->resolvedType, context)->symbol;
    symbol->byteSize = underlyingSymbol->byteSize;
    symbol->maxAlignment = underlyingSymbol->maxAlignment;
  }

  else if (isFunction(symbol->kind)) {
    if (node->firstChild->kind == 5) {
      resolve(context, node->firstChild, symbol->scope);
    }

    struct Node *body = Node_functionBody(node);
    struct Node *returnType = Node_functionReturnType(node);
    uint8_t oldUnsafeAllowed = context->isUnsafeAllowed;
    context->isUnsafeAllowed = Node_isUnsafe(node);
    resolveAsType(context, returnType, symbol->scope->parent);
    int32_t argumentCount = 0;
    struct Node *child = Node_functionFirstArgument(node);

    while (child != returnType) {
      assert(child->kind == 6);
      assert(child->symbol->kind == 6);
      initializeSymbol(context, child->symbol);
      child->symbol->offset = argumentCount;
      argumentCount = argumentCount + 1;
      child = child->nextSibling;
    }

    if (symbol->kind != 4) {
      forbidFlag(context, node, 8, (const uint16_t *)__string_175_Cannot_use_get_here);
      forbidFlag(context, node, 512, (const uint16_t *)__string_176_Cannot_use_set_here);
      forbidFlag(context, node, 256, (const uint16_t *)__string_177_Cannot_use_public_here);
      forbidFlag(context, node, 64, (const uint16_t *)__string_178_Cannot_use_private_here);
    }

    else if (Node_isGet(node)) {
      forbidFlag(context, node, 512, (const uint16_t *)__string_179_Cannot_use_both_get_and_set);

      if (argumentCount != 1) {
        Log_error(context->log, symbol->range, (const uint16_t *)__string_180_Getters_must_not_have_any_argume);
      }
    }

    else if (Node_isSet(node)) {
      symbol->rename = StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_181_set_), symbol->name));

      if (argumentCount != 2) {
        Log_error(context->log, symbol->range, (const uint16_t *)__string_182_Setters_must_have_exactly_one_ar);
      }
    }

    else if (Node_isOperator(node)) {
      if (string_op_equals(symbol->name, (const uint16_t *)__string_183) || string_op_equals(symbol->name, (const uint16_t *)__string_184) || string_op_equals(symbol->name, (const uint16_t *)__string_185)) {
        if (argumentCount != 1) {
          Log_error(context->log, symbol->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_186_Operator), symbol->name), (const uint16_t *)__string_187_must_not_have_any_arguments)));
        }
      }

      else if (string_op_equals(symbol->name, (const uint16_t *)__string_188) || string_op_equals(symbol->name, (const uint16_t *)__string_189)) {
        if (argumentCount > 2) {
          Log_error(context->log, symbol->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_190_Operator), symbol->name), (const uint16_t *)__string_191_must_have_at_most_one_argument)));
        }
      }

      else if (string_op_equals(symbol->name, (const uint16_t *)__string_192)) {
        if (argumentCount < 2) {
          Log_error(context->log, symbol->range, (const uint16_t *)__string_193_Operator_must_have_at_leas);
        }
      }

      else if (argumentCount != 2) {
        Log_error(context->log, symbol->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_194_Operator), symbol->name), (const uint16_t *)__string_195_must_have_exactly_one_argument)));
      }
    }

    symbol->resolvedType = calloc(1, sizeof(struct Type));
    symbol->resolvedType->symbol = symbol;

    if (symbol->kind == 4) {
      struct Symbol *parent = Symbol_parent(symbol);
      uint8_t shouldConvertInstanceToGlobal = 0;
      forbidFlag(context, node, 4, (const uint16_t *)__string_196_Cannot_use_extern_on_an_instan);
      forbidFlag(context, node, 1, (const uint16_t *)__string_197_Cannot_use_declare_on_an_insta);

      if (Node_isDeclare(parent->node)) {
        if (body == NULL) {
          node->flags = node->flags | 1;
        }

        else {
          shouldConvertInstanceToGlobal = 1;
        }
      }

      else {
        if (body == NULL) {
          Log_error(context->log, node->lastChild->range, (const uint16_t *)__string_198_Must_implement_this_function);
        }

        if (Node_isExtern(parent->node)) {
          node->flags = node->flags | 4;
        }
      }

      if (shouldConvertInstanceToGlobal) {
        symbol->kind = 5;
        symbol->flags = symbol->flags | 1;
        symbol->rename = StringBuilder_finish(StringBuilder_append(StringBuilder_appendChar(StringBuilder_append(StringBuilder_new(), parent->name), 95), !string_op_equals(symbol->rename, NULL) ? symbol->rename : symbol->name));
        struct Node *argument = Node_functionFirstArgument(node);
        assert(string_op_equals(argument->symbol->name, (const uint16_t *)__string_199_this));
        argument->symbol->rename = (const uint16_t *)__string_200___this;
      }
    }

    else if (body == NULL) {
      forbidFlag(context, node, 4, (const uint16_t *)__string_201_Cannot_use_extern_on_an_unimpl);
      requireFlag(context, node, 1, (const uint16_t *)__string_202_Declared_functions_must_be_prefi);
    }

    else {
      forbidFlag(context, node, 1, (const uint16_t *)__string_203_Cannot_use_declare_on_a_functi);
    }

    context->isUnsafeAllowed = oldUnsafeAllowed;
  }

  else if (isVariable(symbol->kind)) {
    forbidFlag(context, node, 8, (const uint16_t *)__string_204_Cannot_use_get_on_a_variable);
    forbidFlag(context, node, 512, (const uint16_t *)__string_205_Cannot_use_set_on_a_variable);
    struct Node *type = Node_variableType(node);
    struct Node *value = Node_variableValue(node);
    uint8_t oldUnsafeAllowed = context->isUnsafeAllowed;
    context->isUnsafeAllowed = context->isUnsafeAllowed || Node_isUnsafe(node);

    if (symbol->kind != 9) {
      forbidFlag(context, node, 256, (const uint16_t *)__string_206_Cannot_use_public_here);
      forbidFlag(context, node, 64, (const uint16_t *)__string_207_Cannot_use_private_here);
    }

    if (type != NULL) {
      resolveAsType(context, type, symbol->scope);
      symbol->resolvedType = type->resolvedType;
    }

    else if (value != NULL) {
      resolveAsExpression(context, value, symbol->scope);
      symbol->resolvedType = value->resolvedType;
    }

    else {
      Log_error(context->log, node->internalRange, (const uint16_t *)__string_208_Cannot_create_untyped_variables);
      symbol->resolvedType = context->errorType;
    }

    if (symbol->resolvedType == context->voidType || symbol->resolvedType == context->nullType) {
      Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_209_Cannot_create_a_variable_with_ty), Type_toString(symbol->resolvedType)), 39)));
      symbol->resolvedType = context->errorType;
    }

    if (symbol->kind == 7) {
      if (value != NULL) {
        resolveAsExpression(context, value, symbol->scope);
        checkConversion(context, value, Symbol_resolvedTypeUnderlyingIfEnumValue(symbol, context), 0);

        if (value->kind == 28 || value->kind == 22) {
          symbol->offset = value->intValue;
        }

        else if (value->resolvedType != context->errorType) {
          Log_error(context->log, value->range, (const uint16_t *)__string_210_Invalid_constant_initializer);
          symbol->resolvedType = context->errorType;
        }
      }

      else if (Symbol_isEnumValue(symbol)) {
        if (node->previousSibling != NULL) {
          struct Symbol *previousSymbol = node->previousSibling->symbol;
          initializeSymbol(context, previousSymbol);
          symbol->offset = previousSymbol->offset + 1;
        }

        else {
          symbol->offset = 0;
        }
      }

      else {
        Log_error(context->log, node->internalRange, (const uint16_t *)__string_211_Constants_must_be_initialized);
      }
    }

    if (symbol->scope->symbol == NULL) {
      struct Scope *scope = symbol->scope->parent;

      while (scope != NULL) {
        struct Symbol *shadowed = Scope_findLocal(scope, symbol->name, 0);

        if (shadowed != NULL) {
          Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_212_The_symbol), symbol->name), (const uint16_t *)__string_213_shadows_another_symbol_with_th)));

          break;
        }

        if (scope->symbol != NULL) {
          break;
        }

        scope = scope->parent;
      }
    }

    context->isUnsafeAllowed = oldUnsafeAllowed;
  }

  else {
    assert(0);
  }

  assert(symbol->resolvedType != NULL);
  symbol->state = 2;
}

static void resolveChildren(struct CheckContext *context, struct Node *node, struct Scope *parentScope) {
  struct Node *child = node->firstChild;

  while (child != NULL) {
    resolve(context, child, parentScope);
    assert(child->resolvedType != NULL);
    child = child->nextSibling;
  }
}

static void resolveChildrenAsExpressions(struct CheckContext *context, struct Node *node, struct Scope *parentScope) {
  struct Node *child = node->firstChild;

  while (child != NULL) {
    resolveAsExpression(context, child, parentScope);
    child = child->nextSibling;
  }
}

static void resolveAsExpression(struct CheckContext *context, struct Node *node, struct Scope *parentScope) {
  assert(isExpression(node));
  resolve(context, node, parentScope);
  assert(node->resolvedType != NULL);

  if (node->resolvedType != context->errorType) {
    if (Node_isType(node)) {
      Log_error(context->log, node->range, (const uint16_t *)__string_214_Expected_expression_but_found_ty);
      node->resolvedType = context->errorType;
    }

    else if (node->resolvedType == context->voidType && node->parent->kind != 14) {
      Log_error(context->log, node->range, (const uint16_t *)__string_215_This_expression_does_not_return);
      node->resolvedType = context->errorType;
    }
  }
}

static void resolveAsType(struct CheckContext *context, struct Node *node, struct Scope *parentScope) {
  assert(isExpression(node));
  resolve(context, node, parentScope);
  assert(node->resolvedType != NULL);

  if (node->resolvedType != context->errorType && !Node_isType(node)) {
    Log_error(context->log, node->range, (const uint16_t *)__string_216_Expected_type_but_found_expressi);
    node->resolvedType = context->errorType;
  }
}

static uint8_t canConvert(struct CheckContext *context, struct Node *node, struct Type *to, int32_t kind) {
  struct Type *from = node->resolvedType;
  assert(isExpression(node));
  assert(from != NULL);
  assert(to != NULL);

  if (from == to || from == context->errorType || to == context->errorType) {
    return 1;
  }

  else if (from == context->nullType && Type_isReference(to)) {
    return 1;
  }

  else if (context->isUnsafeAllowed && (Type_isReference(from) || Type_isReference(to))) {
    if (kind == 1) {
      return 1;
    }
  }

  else if (Type_isInteger(from) && Type_isInteger(to)) {
    uint32_t mask = Type_integerBitMask(to, context);

    if (Type_isEnum(from) && to == Type_underlyingType(from, context)) {
      return 1;
    }

    if (kind == 1 || from->symbol->byteSize < to->symbol->byteSize || (node->kind == 28 && (Type_isUnsigned(to) ? node->intValue >= 0 && (uint32_t)node->intValue <= mask : node->intValue >= (int32_t)~mask >> 1 && node->intValue <= (int32_t)(mask >> 1)))) {
      return 1;
    }
  }

  return 0;
}

static void checkConversion(struct CheckContext *context, struct Node *node, struct Type *to, int32_t kind) {
  if (!canConvert(context, node, to, kind)) {
    Log_error(context->log, node->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_217_Cannot_convert_from_type), Type_toString(node->resolvedType)), (const uint16_t *)__string_218_to_type), Type_toString(to)), kind == 0 && canConvert(context, node, to, 1) ? (const uint16_t *)__string_219_without_a_cast : (const uint16_t *)__string_220)));
    node->resolvedType = context->errorType;
  }
}

static void checkStorage(struct CheckContext *context, struct Node *target) {
  assert(isExpression(target));

  if (target->resolvedType != context->errorType && target->kind != 27 && target->kind != 39 && ((target->kind != 29 && target->kind != 25) || (target->symbol != NULL && (!isVariable(target->symbol->kind) || target->symbol->kind == 7)))) {
    Log_error(context->log, target->range, (const uint16_t *)__string_221_Cannot_store_to_this_location);
    target->resolvedType = context->errorType;
  }
}

static struct Node *createDefaultValueForType(struct CheckContext *context, struct Type *type) {
  if (Type_isInteger(type)) {
    return createInt(0);
  }

  if (type == context->boolType) {
    return createBool(0);
  }

  assert(Type_isReference(type));

  return createNull();
}

static void simplifyBinary(struct Node *node) {
  struct Node *left = Node_binaryLeft(node);
  struct Node *right = Node_binaryRight(node);

  if ((node->kind == 48 || node->kind == 62 || node->kind == 50 || node->kind == 51 || node->kind == 52) && left->kind == 28 && right->kind != 28) {
    Node_appendChild(node, Node_remove(left));
    left = Node_binaryLeft(node);
    right = Node_binaryRight(node);
  }

  if ((node->kind == 62 || ((node->kind == 53 || node->kind == 64) && Type_isUnsigned(node->resolvedType))) && right->kind == 28 && isPositivePowerOf2(right->intValue)) {
    int32_t shift = -1;
    int32_t value = right->intValue;

    while (value != 0) {
      value = value >> 1;
      shift = shift + 1;
    }

    if (node->kind == 62) {
      node->kind = 65;
      right->intValue = shift;
    }

    else if (node->kind == 53) {
      node->kind = 66;
      right->intValue = shift;
    }

    else if (node->kind == 64) {
      node->kind = 50;
      right->intValue = right->intValue - 1;
    }

    else {
      assert(0);
    }
  }

  else if (node->kind == 48 && right->kind == 40) {
    node->kind = 67;
    Node_replaceWith(right, Node_remove(Node_unaryValue(right)));
  }

  else if (node->kind == 48 && Node_isNegativeInteger(right)) {
    node->kind = 67;
    right->intValue = -right->intValue;
  }
}

static uint8_t binaryHasUnsignedArguments(struct Node *node) {
  struct Node *left = Node_binaryLeft(node);
  struct Node *right = Node_binaryRight(node);
  struct Type *leftType = left->resolvedType;
  struct Type *rightType = right->resolvedType;

  return (Type_isUnsigned(leftType) && Type_isUnsigned(rightType)) || (Type_isUnsigned(leftType) && Node_isNonNegativeInteger(right)) || (Node_isNonNegativeInteger(left) && Type_isUnsigned(rightType));
}

static uint8_t isSymbolAccessAllowed(struct CheckContext *context, struct Symbol *symbol, struct Node *node, struct Range *range) {
  if (Symbol_isUnsafe(symbol) && !context->isUnsafeAllowed) {
    Log_error(context->log, range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_222_Cannot_use_symbol), symbol->name), (const uint16_t *)__string_223_outside_an_unsafe_block)));

    return 0;
  }

  if (symbol->node != NULL && Node_isPrivate(symbol->node)) {
    struct Symbol *parent = Symbol_parent(symbol);

    if (parent != NULL && context->enclosingClass != parent) {
      Log_error(context->log, range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_224_Cannot_access_private_symbol), symbol->name), (const uint16_t *)__string_225_here)));

      return 0;
    }
  }

  if (isFunction(symbol->kind) && (Symbol_isSetter(symbol) ? !Node_isAssignTarget(node) : !Node_isCallValue(node))) {
    if (Symbol_isSetter(symbol)) {
      Log_error(context->log, range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_226_Cannot_use_setter), symbol->name), (const uint16_t *)__string_227_here)));
    }

    else {
      Log_error(context->log, range, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_228_Must_call_function), symbol->name), 39)));
    }

    return 0;
  }

  return 1;
}

static void resolve(struct CheckContext *context, struct Node *node, struct Scope *parentScope) {
  int32_t kind = node->kind;
  assert(kind == 1 || parentScope != NULL);

  if (node->resolvedType != NULL) {
    return;
  }

  node->resolvedType = context->errorType;

  if (kind == 1 || kind == 2) {
    resolveChildren(context, node, parentScope);
  }

  else if (kind == 9) {
    struct Symbol *oldEnclosingClass = context->enclosingClass;
    initializeSymbol(context, node->symbol);
    context->enclosingClass = node->symbol;
    resolveChildren(context, node, node->scope);

    if (node->symbol->kind == 0) {
      Symbol_determineClassLayout(node->symbol, context);
    }

    context->enclosingClass = oldEnclosingClass;
  }

  else if (kind == 13) {
    initializeSymbol(context, node->symbol);
    resolveChildren(context, node, node->scope);
  }

  else if (kind == 15) {
    struct Node *body = Node_functionBody(node);
    initializeSymbol(context, node->symbol);

    if (body != NULL) {
      struct Type *oldReturnType = context->currentReturnType;
      uint8_t oldUnsafeAllowed = context->isUnsafeAllowed;
      context->currentReturnType = Node_functionReturnType(node)->resolvedType;
      context->isUnsafeAllowed = Node_isUnsafe(node);
      resolveChildren(context, body, node->scope);
      context->currentReturnType = oldReturnType;
      context->isUnsafeAllowed = oldUnsafeAllowed;
    }
  }

  else if (kind == 6) {
    struct Symbol *symbol = node->symbol;
    initializeSymbol(context, symbol);
    uint8_t oldUnsafeAllowed = context->isUnsafeAllowed;
    context->isUnsafeAllowed = context->isUnsafeAllowed || Node_isUnsafe(node);
    struct Node *value = Node_variableValue(node);

    if (value != NULL) {
      resolveAsExpression(context, value, parentScope);
      checkConversion(context, value, Symbol_resolvedTypeUnderlyingIfEnumValue(symbol, context), 0);

      if (symbol->kind == 8 && value->kind != 28 && value->kind != 22 && value->kind != 31) {
        Log_error(context->log, value->range, (const uint16_t *)__string_229_Global_initializers_must_be_comp);
      }
    }

    else if (symbol->resolvedType != context->errorType) {
      value = createDefaultValueForType(context, symbol->resolvedType);
      resolveAsExpression(context, value, parentScope);
      Node_appendChild(node, value);
    }

    if (symbol->kind == 8 && symbol->resolvedType != context->errorType) {
      symbol->offset = CheckContext_allocateGlobalVariableOffset(context, Type_variableSizeOf(symbol->resolvedType, context), Type_variableAlignmentOf(symbol->resolvedType, context));
    }

    context->isUnsafeAllowed = oldUnsafeAllowed;
  }

  else if (kind == 8 || kind == 11) {
    uint8_t found = 0;
    struct Node *n = node;

    while (n != NULL) {
      if (n->kind == 20) {
        found = 1;

        break;
      }

      n = n->parent;
    }

    if (!found) {
      Log_error(context->log, node->range, (const uint16_t *)__string_230_Cannot_use_this_statement_outsid);
    }
  }

  else if (kind == 7) {
    uint8_t oldUnsafeAllowed = context->isUnsafeAllowed;

    if (Node_isUnsafe(node)) {
      context->isUnsafeAllowed = 1;
    }

    resolveChildren(context, node, node->scope);
    context->isUnsafeAllowed = oldUnsafeAllowed;
  }

  else if (kind == 10 || kind == 19) {
    resolveChildren(context, node, parentScope);
  }

  else if (kind == 28) {
    node->resolvedType = node->intValue < 0 && !Node_isPositive(node) ? context->uintType : context->intType;
  }

  else if (kind == 34) {
    node->resolvedType = context->stringType;
  }

  else if (kind == 22) {
    node->resolvedType = context->boolType;
  }

  else if (kind == 31) {
    node->resolvedType = context->nullType;
  }

  else if (kind == 27) {
    resolveChildrenAsExpressions(context, node, parentScope);
    struct Node *target = Node_indexTarget(node);
    struct Type *type = target->resolvedType;

    if (type != context->errorType) {
      struct Symbol *symbol = Type_hasInstanceMembers(type) ? Type_findMember(type, (const uint16_t *)__string_231, 0) : NULL;

      if (symbol == NULL) {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_232_Cannot_index_into_type), Type_toString(target->resolvedType)), 39)));
      }

      else {
        assert(symbol->kind == 4 || (symbol->kind == 5 && Symbol_shouldConvertInstanceToGlobal(symbol)));
        node->kind = 23;
        Node_remove(target);
        Node_insertChildBefore(node, node->firstChild, createMemberReference(target, symbol));
        node->resolvedType = NULL;
        resolveAsExpression(context, node, parentScope);
      }
    }
  }

  else if (kind == 21) {
    struct Node *type = Node_alignOfType(node);
    resolveAsType(context, type, parentScope);
    node->resolvedType = context->intType;

    if (type->resolvedType != context->errorType) {
      Node_becomeIntegerConstant(node, Type_allocationAlignmentOf(type->resolvedType, context));
    }
  }

  else if (kind == 33) {
    struct Node *type = Node_sizeOfType(node);
    resolveAsType(context, type, parentScope);
    node->resolvedType = context->intType;

    if (type->resolvedType != context->errorType) {
      Node_becomeIntegerConstant(node, Type_allocationSizeOf(type->resolvedType, context));
    }
  }

  else if (kind == 35) {
    struct Symbol *symbol = Scope_findNested(parentScope, (const uint16_t *)__string_233_this, 0, 0);

    if (symbol == NULL) {
      Log_error(context->log, node->range, (const uint16_t *)__string_234_Cannot_use_this_here);
    }

    else {
      Node_becomeSymbolReference(node, symbol);
    }
  }

  else if (kind == 32) {
    node->resolvedType = context->errorType;
  }

  else if (kind == 29) {
    const uint16_t *name = node->stringValue;
    struct Symbol *symbol = Scope_findNested(parentScope, name, 0, 0);

    if (symbol == NULL) {
      struct StringBuilder *builder = StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_235_No_symbol_named), name), (const uint16_t *)__string_236_here);
      symbol = Scope_findNested(parentScope, name, 0, 1);

      if (symbol != NULL) {
        StringBuilder_append(StringBuilder_append(StringBuilder_append(builder, (const uint16_t *)__string_237_did_you_mean_this), symbol->name), (const uint16_t *)__string_238);
      }

      else if (string_op_equals(name, (const uint16_t *)__string_239_number)) {
        StringBuilder_append(builder, (const uint16_t *)__string_240_did_you_mean_int);
      }

      else if (string_op_equals(name, (const uint16_t *)__string_241_boolean)) {
        StringBuilder_append(builder, (const uint16_t *)__string_242_did_you_mean_bool);
      }

      Log_error(context->log, node->range, StringBuilder_finish(builder));
    }

    else if (symbol->state == 1) {
      Log_error(context->log, node->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_243_Cyclic_reference_to_symbol), name), (const uint16_t *)__string_244_here)));
    }

    else if (isSymbolAccessAllowed(context, symbol, node, node->range)) {
      initializeSymbol(context, symbol);
      node->symbol = symbol;
      node->resolvedType = symbol->resolvedType;

      if (symbol->kind == 7) {
        if (symbol->resolvedType == context->boolType) {
          Node_becomeBooleanConstant(node, symbol->offset != 0);
        }

        else {
          Node_becomeIntegerConstant(node, symbol->offset);
        }
      }
    }
  }

  else if (kind == 24) {
    struct Node *value = Node_castValue(node);
    struct Node *type = Node_castType(node);
    resolveAsExpression(context, value, parentScope);
    resolveAsType(context, type, parentScope);
    struct Type *castedType = type->resolvedType;
    checkConversion(context, value, castedType, 1);
    node->resolvedType = castedType;

    if (value->kind == 28 && Type_isInteger(castedType)) {
      int32_t result = value->intValue;
      int32_t shift = 32 - Type_integerBitCount(castedType, context);
      Node_becomeIntegerConstant(node, Type_isUnsigned(castedType) ? (int32_t)Type_integerBitMask(castedType, context) & result : result << shift >> shift);
    }
  }

  else if (kind == 25) {
    struct Node *target = Node_dotTarget(node);
    resolve(context, target, parentScope);

    if (target->resolvedType != context->errorType) {
      if ((Node_isType(target) && Type_isEnum(target->resolvedType)) || (!Node_isType(target) && Type_hasInstanceMembers(target->resolvedType))) {
        const uint16_t *name = node->stringValue;

        if (string_length(name) > 0) {
          struct Symbol *symbol = Type_findMember(target->resolvedType, name, Node_isAssignTarget(node) ? 6 : 5);

          if (symbol == NULL) {
            Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_245_No_member_named), name), (const uint16_t *)__string_246_on_type), Type_toString(target->resolvedType)), 39)));
          }

          else if (Symbol_isGetter(symbol)) {
            node->kind = 23;
            Node_appendChild(node, createMemberReference(Node_remove(target), symbol));
            node->resolvedType = NULL;
            resolveAsExpression(context, node, parentScope);

            return;
          }

          else if (isSymbolAccessAllowed(context, symbol, node, node->internalRange)) {
            initializeSymbol(context, symbol);
            node->symbol = symbol;
            node->resolvedType = symbol->resolvedType;

            if (symbol->kind == 7) {
              Node_becomeIntegerConstant(node, symbol->offset);
            }
          }
        }
      }

      else {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_247_The_type), Type_toString(target->resolvedType)), (const uint16_t *)__string_248_has_no_members)));
      }
    }
  }

  else if (kind == 23) {
    struct Node *value = Node_callValue(node);
    resolveAsExpression(context, value, parentScope);

    if (value->resolvedType != context->errorType) {
      struct Symbol *symbol = value->symbol;

      if (symbol == NULL || !isFunction(symbol->kind)) {
        Log_error(context->log, value->range, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_249_Cannot_call_value_of_type), Type_toString(value->resolvedType)), 39)));
      }

      else {
        initializeSymbol(context, symbol);

        if (Symbol_shouldConvertInstanceToGlobal(symbol)) {
          struct Node *name = createSymbolReference(symbol);
          Node_insertChildBefore(node, value, Node_withRange(name, value->internalRange));
          Node_insertChildBefore(node, value, Node_remove(Node_dotTarget(value)));
          Node_remove(value);
          value = name;
        }

        struct Node *returnType = Node_functionReturnType(symbol->node);
        struct Node *argumentVariable = Node_functionFirstArgumentIgnoringThis(symbol->node);
        struct Node *argumentValue = value->nextSibling;

        while (argumentVariable != returnType && argumentValue != NULL) {
          resolveAsExpression(context, argumentValue, parentScope);
          checkConversion(context, argumentValue, argumentVariable->symbol->resolvedType, 0);
          argumentVariable = argumentVariable->nextSibling;
          argumentValue = argumentValue->nextSibling;
        }

        if (argumentVariable != returnType) {
          Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_250_Not_enough_arguments_for_functio), symbol->name), 39)));
        }

        else if (argumentValue != NULL) {
          while (argumentValue != NULL) {
            resolveAsExpression(context, argumentValue, parentScope);
            argumentValue = argumentValue->nextSibling;
          }

          Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_251_Too_many_arguments_for_function), symbol->name), 39)));
        }

        node->resolvedType = returnType->resolvedType;
      }
    }
  }

  else if (kind == 17) {
    struct Node *value = Node_returnValue(node);

    if (value != NULL) {
      resolveAsExpression(context, value, parentScope);

      if (context->currentReturnType != NULL) {
        if (context->currentReturnType != context->voidType) {
          checkConversion(context, value, context->currentReturnType, 0);
        }

        else {
          Log_error(context->log, value->range, (const uint16_t *)__string_252_Unexpected_return_value_in_funct);
        }
      }
    }

    else if (context->currentReturnType != NULL && context->currentReturnType != context->voidType) {
      Log_error(context->log, node->range, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_253_Expected_return_value_in_functio), Type_toString(context->currentReturnType)), 39)));
    }
  }

  else if (kind == 12) {
  }

  else if (kind == 5) {
    Log_error(context->log, node->range, (const uint16_t *)__string_254_Generics_are_not_implemented_yet);
  }

  else if (kind == 0) {
    resolveAsType(context, Node_extendsType(node), parentScope);
    Log_error(context->log, node->range, (const uint16_t *)__string_255_Subclassing_is_not_implemented_y);
  }

  else if (kind == 3) {
    struct Node *child = node->firstChild;

    while (child != NULL) {
      resolveAsType(context, child, parentScope);
      child = child->nextSibling;
    }

    Log_error(context->log, node->range, (const uint16_t *)__string_256_Interfaces_are_not_implemented_y);
  }

  else if (kind == 14) {
    resolveAsExpression(context, Node_expressionValue(node), parentScope);
  }

  else if (kind == 20) {
    struct Node *value = Node_whileValue(node);
    struct Node *body = Node_whileBody(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context->boolType, 0);
    resolve(context, body, parentScope);
  }

  else if (kind == 16) {
    struct Node *value = Node_ifValue(node);
    struct Node *yes = Node_ifTrue(node);
    struct Node *no = Node_ifFalse(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context->boolType, 0);
    resolve(context, yes, parentScope);

    if (no != NULL) {
      resolve(context, no, parentScope);
    }
  }

  else if (kind == 26) {
    struct Node *value = Node_hookValue(node);
    struct Node *yes = Node_hookTrue(node);
    struct Node *no = Node_hookFalse(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context->boolType, 0);
    resolve(context, yes, parentScope);
    resolve(context, no, parentScope);
    struct Type *commonType = (yes->resolvedType == context->nullType ? no : yes)->resolvedType;

    if (yes->resolvedType != commonType && (yes->resolvedType != context->nullType || !Type_isReference(commonType)) && no->resolvedType != commonType && (no->resolvedType != context->nullType || !Type_isReference(commonType))) {
      Log_error(context->log, spanRanges(yes->range, no->range), StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_257_Type), Type_toString(yes->resolvedType)), (const uint16_t *)__string_258_is_not_the_same_as_type), Type_toString(no->resolvedType)), 39)));
    }

    node->resolvedType = commonType;
  }

  else if (kind == 49) {
    struct Node *left = Node_binaryLeft(node);
    struct Node *right = Node_binaryRight(node);

    if (left->kind == 27) {
      resolveChildrenAsExpressions(context, left, parentScope);
      struct Node *target = Node_indexTarget(left);
      struct Type *type = target->resolvedType;

      if (type != context->errorType) {
        struct Symbol *symbol = Type_hasInstanceMembers(type) ? Type_findMember(type, (const uint16_t *)__string_259, 0) : NULL;

        if (symbol == NULL) {
          Log_error(context->log, left->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_260_Cannot_index_into_type), Type_toString(target->resolvedType)), 39)));
        }

        else {
          assert(symbol->kind == 4);
          node->kind = 23;
          Node_remove(target);
          Node_remove(left);

          while (left->lastChild != NULL) {
            Node_insertChildBefore(node, node->firstChild, Node_remove(left->lastChild));
          }

          Node_insertChildBefore(node, node->firstChild, createMemberReference(target, symbol));
          node->internalRange = spanRanges(left->internalRange, right->range);
          node->resolvedType = NULL;
          resolveAsExpression(context, node, parentScope);

          return;
        }
      }
    }

    resolveAsExpression(context, left, parentScope);

    if (left->symbol != NULL && Symbol_isSetter(left->symbol)) {
      node->kind = 23;
      node->internalRange = left->internalRange;
      node->resolvedType = NULL;
      resolveAsExpression(context, node, parentScope);

      return;
    }

    resolveAsExpression(context, right, parentScope);
    checkConversion(context, right, left->resolvedType, 0);
    checkStorage(context, left);
    node->resolvedType = left->resolvedType;
  }

  else if (kind == 30) {
    struct Node *type = Node_newType(node);
    resolveAsType(context, type, parentScope);

    if (type->resolvedType != context->errorType) {
      if (!Type_isClass(type->resolvedType)) {
        Log_error(context->log, type->range, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_261_Cannot_construct_type), Type_toString(type->resolvedType)), 39)));
      }

      else {
        node->resolvedType = type->resolvedType;
      }
    }

    if (type->nextSibling != NULL) {
      Log_error(context->log, node->internalRange, (const uint16_t *)__string_262_Constructors_with_arguments_are);
    }
  }

  else if (kind == 42) {
    struct Node *value = Node_unaryValue(node);
    resolveAsType(context, value, parentScope);

    if (context->target == 2) {
      Log_error(context->log, node->internalRange, (const uint16_t *)__string_263_Cannot_use_pointers_when_compili);
    }

    else if (!context->isUnsafeAllowed) {
      Log_error(context->log, node->internalRange, (const uint16_t *)__string_264_Cannot_use_pointers_outside_an);
    }

    else {
      struct Type *type = value->resolvedType;

      if (type != context->errorType) {
        if (!Type_isInteger(type) && type->pointerTo == NULL) {
          Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_265_Cannot_create_a_pointer_to_non_i), Type_toString(type)), 39)));
        }

        else {
          node->resolvedType = Type_pointerType(type);
        }
      }
    }
  }

  else if (kind == 39) {
    struct Node *value = Node_unaryValue(node);
    resolveAsExpression(context, value, parentScope);
    struct Type *type = value->resolvedType;

    if (type != context->errorType) {
      if (type->pointerTo == NULL) {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_266_Cannot_dereference_type), Type_toString(type)), 39)));
      }

      else {
        node->resolvedType = type->pointerTo;
      }
    }
  }

  else if (kind == 37) {
    struct Node *value = Node_unaryValue(node);
    resolveAsExpression(context, value, parentScope);
    Log_error(context->log, node->internalRange, (const uint16_t *)__string_267_The_address_of_operator_is_not_s);
  }

  else if (isUnary(kind)) {
    struct Node *value = Node_unaryValue(node);
    resolveAsExpression(context, value, parentScope);

    if (kind == 41) {
      checkConversion(context, value, context->boolType, 0);
      node->resolvedType = context->boolType;
    }

    else if (Type_isInteger(value->resolvedType)) {
      if (Type_isUnsigned(value->resolvedType)) {
        node->flags = node->flags | 4096;
        node->resolvedType = context->uintType;
      }

      else {
        node->resolvedType = context->intType;
      }

      if (value->kind == 28) {
        int32_t input = value->intValue;
        int32_t output = input;

        if (kind == 38) {
          output = ~input;
        }

        else if (kind == 40) {
          output = -input;
        }

        Node_becomeIntegerConstant(node, output);
      }
    }

    else if (value->resolvedType != context->errorType) {
      const uint16_t *name = Range_toString(node->internalRange);
      struct Symbol *symbol = Type_findMember(value->resolvedType, name, 1);

      if (symbol != NULL) {
        Node_appendChild(node, Node_withInternalRange(Node_withRange(createMemberReference(Node_remove(value), symbol), node->range), node->internalRange));
        node->kind = 23;
        node->resolvedType = NULL;
        resolveAsExpression(context, node, parentScope);
      }

      else {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_268_Cannot_use_unary_operator), name), (const uint16_t *)__string_269_with_type), Type_toString(value->resolvedType)), 39)));
      }
    }
  }

  else if (isBinary(kind)) {
    struct Node *left = Node_binaryLeft(node);
    struct Node *right = Node_binaryRight(node);
    resolveAsExpression(context, left, parentScope);
    resolveAsExpression(context, right, parentScope);
    struct Type *leftType = left->resolvedType;
    struct Type *rightType = right->resolvedType;

    if (kind == 61 || kind == 60) {
      checkConversion(context, left, context->boolType, 0);
      checkConversion(context, right, context->boolType, 0);
      node->resolvedType = context->boolType;
    }

    else if (kind == 48 && leftType->pointerTo != NULL && Type_isInteger(rightType)) {
      node->resolvedType = leftType;
    }

    else if ((kind == 58 || kind == 59 || kind == 56 || kind == 57) && (leftType->pointerTo != NULL || rightType->pointerTo != NULL)) {
      node->resolvedType = context->boolType;

      if (leftType != rightType) {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_270_Cannot_compare_type), Type_toString(leftType)), (const uint16_t *)__string_271_with_type), Type_toString(rightType)), 39)));
      }
    }

    else if (Type_isInteger(leftType) && kind != 54 && kind != 63) {
      if (kind == 48 || kind == 67 || kind == 62 || kind == 53 || kind == 64 || kind == 50 || kind == 51 || kind == 52 || kind == 65 || kind == 66) {
        uint8_t isUnsigned = binaryHasUnsignedArguments(node);
        struct Type *commonType = isUnsigned ? context->uintType : context->intType;

        if (isUnsigned) {
          node->flags = node->flags | 4096;
        }

        checkConversion(context, left, commonType, 0);
        checkConversion(context, right, commonType, 0);
        node->resolvedType = commonType;

        if (left->kind == 28 && right->kind == 28) {
          int32_t inputLeft = left->intValue;
          int32_t inputRight = right->intValue;
          int32_t output = 0;

          if (kind == 48) {
            output = inputLeft + inputRight;
          }

          else if (kind == 50) {
            output = inputLeft & inputRight;
          }

          else if (kind == 51) {
            output = inputLeft | inputRight;
          }

          else if (kind == 52) {
            output = inputLeft ^ inputRight;
          }

          else if (kind == 53) {
            output = inputLeft / inputRight;
          }

          else if (kind == 62) {
            output = inputLeft * inputRight;
          }

          else if (kind == 64) {
            output = inputLeft % inputRight;
          }

          else if (kind == 65) {
            output = inputLeft << inputRight;
          }

          else if (kind == 66) {
            output = isUnsigned ? (int32_t)((uint32_t)inputLeft >> (uint32_t)inputRight) : inputLeft >> inputRight;
          }

          else if (kind == 67) {
            output = inputLeft - inputRight;
          }

          else {
            return;
          }

          Node_becomeIntegerConstant(node, output);
        }

        else {
          simplifyBinary(node);
        }
      }

      else if (kind == 58 || kind == 59 || kind == 56 || kind == 57) {
        struct Type *expectedType = binaryHasUnsignedArguments(node) ? context->uintType : context->intType;

        if (expectedType == context->uintType) {
          node->flags = node->flags | 4096;
        }

        if (leftType != rightType) {
          checkConversion(context, left, expectedType, 0);
          checkConversion(context, right, expectedType, 0);
        }

        node->resolvedType = context->boolType;
      }

      else {
        Log_error(context->log, node->internalRange, (const uint16_t *)__string_272_This_operator_is_not_currently_s);
      }
    }

    else if (leftType != context->errorType) {
      const uint16_t *name = Range_toString(node->internalRange);
      struct Symbol *symbol = Type_findMember(leftType, kind == 63 ? (const uint16_t *)__string_273 : kind == 59 ? (const uint16_t *)__string_274 : kind == 57 ? (const uint16_t *)__string_275 : name, 4);

      if (symbol != NULL) {
        left = Node_withInternalRange(Node_withRange(createMemberReference(Node_remove(left), symbol), node->range), node->internalRange);
        Node_remove(right);

        if (kind == 63 || kind == 59 || kind == 57) {
          struct Node *call = createCall(left);
          Node_appendChild(call, right);
          node->kind = 41;
          Node_appendChild(node, Node_withInternalRange(Node_withRange(call, node->range), node->range));
        }

        else {
          Node_appendChild(node, left);
          Node_appendChild(node, right);
          node->kind = 23;
        }

        node->resolvedType = NULL;
        resolveAsExpression(context, node, parentScope);
      }

      else if (kind == 54 || kind == 63) {
        node->resolvedType = context->boolType;

        if (leftType != context->errorType && rightType != context->errorType && leftType != rightType && !canConvert(context, right, leftType, 0) && !canConvert(context, left, rightType, 0)) {
          Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_276_Cannot_compare_type), Type_toString(leftType)), (const uint16_t *)__string_277_with_type), Type_toString(rightType)), 39)));
        }
      }

      else {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_278_Cannot_use_binary_operator), name), (const uint16_t *)__string_279_with_type), Type_toString(leftType)), 39)));
      }
    }
  }

  else {
    assert(0);
  }
}

static void Compiler_initialize(struct Compiler *__this, int32_t target, const uint16_t *outputName) {
  assert(__this->log == NULL);
  __this->log = calloc(1, sizeof(struct Log));
  __this->preprocessor = calloc(1, sizeof(struct Preprocessor));
  __this->target = target;
  __this->outputName = outputName;
  __this->librarySource = Compiler_addInput(__this, (const uint16_t *)__string_280_native, library());
  __this->librarySource->isLibrary = 1;
  Compiler_createGlobals(__this);

  if (target == 1) {
    Preprocessor_define(__this->preprocessor, (const uint16_t *)__string_281_C, 1);
  }

  else if (target == 2) {
    Preprocessor_define(__this->preprocessor, (const uint16_t *)__string_282_JS, 1);
  }

  else if (target == 3) {
    Preprocessor_define(__this->preprocessor, (const uint16_t *)__string_283_WASM, 1);
  }
}

static void Compiler_createGlobals(struct Compiler *__this) {
  struct CheckContext *context = calloc(1, sizeof(struct CheckContext));
  context->log = __this->log;
  context->target = __this->target;
  context->pointerByteSize = 4;
  struct Node *global = calloc(1, sizeof(struct Node));
  global->kind = 2;
  struct Scope *scope = calloc(1, sizeof(struct Scope));
  global->scope = scope;
  context->errorType = Scope_defineNativeType(scope, context->log, (const uint16_t *)__string_284_error);
  context->nullType = Scope_defineNativeType(scope, context->log, (const uint16_t *)__string_285_null);
  context->voidType = Scope_defineNativeType(scope, context->log, (const uint16_t *)__string_286_void);
  __this->context = context;
  __this->global = global;
}

static struct Source *Compiler_addInput(struct Compiler *__this, const uint16_t *name, const uint16_t *contents) {
  struct Source *source = calloc(1, sizeof(struct Source));
  source->name = name;
  source->contents = contents;

  if (__this->firstSource == NULL) {
    __this->firstSource = source;
  }

  else {
    __this->lastSource->next = source;
  }

  __this->lastSource = source;

  return source;
}

static uint8_t Compiler_finish(struct Compiler *__this) {
  Profiler_begin();
  struct Source *source = __this->firstSource;

  while (source != NULL) {
    source->firstToken = tokenize(source, __this->log);
    source = source->next;
  }

  Profiler_end((const uint16_t *)__string_287_lexing);
  Profiler_begin();
  source = __this->firstSource;

  while (source != NULL) {
    Preprocessor_run(__this->preprocessor, source, __this->log);
    source = source->next;
  }

  Profiler_end((const uint16_t *)__string_288_preprocessing);
  Profiler_begin();
  source = __this->firstSource;

  while (source != NULL) {
    if (source->firstToken != NULL) {
      source->file = parse(source->firstToken, __this->log);
    }

    source = source->next;
  }

  Profiler_end((const uint16_t *)__string_289_parsing);
  Profiler_begin();
  struct Node *global = __this->global;
  struct CheckContext *context = __this->context;
  uint8_t fullResolve = 1;
  source = __this->firstSource;

  while (source != NULL) {
    struct Node *file = source->file;

    if (file != NULL) {
      if (source == __this->librarySource) {
        initialize(context, file, global->scope, 1);
        resolve(context, file, global->scope);
      }

      else {
        initialize(context, file, global->scope, 0);
      }

      while (file->firstChild != NULL) {
        struct Node *child = file->firstChild;
        Node_remove(child);
        Node_appendChild(global, child);
      }
    }

    if (source == __this->librarySource && Log_hasErrors(__this->log)) {
      fullResolve = 0;

      break;
    }

    source = source->next;
  }

  if (fullResolve) {
    resolve(context, global, global->scope);
  }

  Profiler_end((const uint16_t *)__string_290_checking);

  if (Log_hasErrors(__this->log)) {
    return 0;
  }

  Profiler_begin();
  treeShaking(global);
  Profiler_end((const uint16_t *)__string_291_shaking);
  Profiler_begin();

  if (__this->target == 1) {
    cEmit(__this);
  }

  else if (__this->target == 2) {
    jsEmit(__this);
  }

  else if (__this->target == 3) {
    wasmEmit(__this);
  }

  Profiler_end((const uint16_t *)__string_292_emitting);

  return 1;
}

static const uint16_t *replaceFileExtension(const uint16_t *path, const uint16_t *extension) {
  struct StringBuilder *builder = StringBuilder_new();
  int32_t dot = string_lastIndexOf(path, (const uint16_t *)__string_293);
  int32_t forward = string_lastIndexOf(path, (const uint16_t *)__string_294);
  int32_t backward = string_lastIndexOf(path, (const uint16_t *)__string_295);

  if (dot > 0 && dot > forward && dot > backward) {
    path = string_slice(path, 0, dot);
  }

  return StringBuilder_finish(StringBuilder_append(StringBuilder_append(builder, path), extension));
}

static uint8_t isPositivePowerOf2(int32_t value) {
  return value > 0 && (value & (value - 1)) == 0;
}

static int32_t alignToNextMultipleOf(int32_t offset, int32_t alignment) {
  assert(isPositivePowerOf2(alignment));

  return (offset + alignment - 1) & -alignment;
}

static void JsResult_emitIndent(struct JsResult *__this) {
  int32_t i = __this->indent;

  while (i > 0) {
    StringBuilder_append(__this->code, (const uint16_t *)__string_296);
    i = i - 1;
  }
}

static void JsResult_emitNewlineBefore(struct JsResult *__this, struct Node *node) {
  if (__this->previousNode != NULL && (!isCompactNodeKind(__this->previousNode->kind) || !isCompactNodeKind(node->kind))) {
    StringBuilder_appendChar(__this->code, 10);
  }

  __this->previousNode = NULL;
}

static void JsResult_emitNewlineAfter(struct JsResult *__this, struct Node *node) {
  __this->previousNode = node;
}

static void JsResult_emitStatements(struct JsResult *__this, struct Node *node) {
  while (node != NULL) {
    JsResult_emitStatement(__this, node);
    node = node->nextSibling;
  }
}

static void JsResult_emitBlock(struct JsResult *__this, struct Node *node) {
  __this->previousNode = NULL;
  StringBuilder_append(__this->code, (const uint16_t *)__string_297);
  __this->indent = __this->indent + 1;
  JsResult_emitStatements(__this, node->firstChild);
  __this->indent = __this->indent - 1;
  JsResult_emitIndent(__this);
  StringBuilder_appendChar(__this->code, 125);
  __this->previousNode = NULL;
}

static void JsResult_emitUnary(struct JsResult *__this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator) {
  uint8_t isPostfix = isUnaryPostfix(node->kind);
  uint8_t shouldCastToInt = node->kind == 40 && !jsKindCastsOperandsToInt(node->parent->kind);
  uint8_t isUnsigned = Node_isUnsignedOperator(node);
  int32_t operatorPrecedence = shouldCastToInt ? isUnsigned ? 9 : 4 : isPostfix ? 14 : 13;
  struct StringBuilder *code = __this->code;

  if (parentPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 40);
  }

  if (!isPostfix) {
    StringBuilder_append(code, operator);
  }

  JsResult_emitExpression(__this, Node_unaryValue(node), operatorPrecedence);

  if (isPostfix) {
    StringBuilder_append(code, operator);
  }

  if (shouldCastToInt) {
    StringBuilder_append(code, isUnsigned ? (const uint16_t *)__string_298_0 : (const uint16_t *)__string_299_0);
  }

  if (parentPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 41);
  }
}

static void JsResult_emitBinary(struct JsResult *__this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator, int32_t operatorPrecedence, int32_t mode) {
  uint8_t isRightAssociative = node->kind == 49;
  uint8_t isUnsigned = Node_isUnsignedOperator(node);
  struct StringBuilder *code = __this->code;
  uint8_t shouldCastToInt = mode == 1 && (isUnsigned || !jsKindCastsOperandsToInt(node->parent->kind));
  int32_t selfPrecedence = shouldCastToInt ? isUnsigned ? 9 : 4 : parentPrecedence;

  if (parentPrecedence > selfPrecedence) {
    StringBuilder_appendChar(code, 40);
  }

  if (selfPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 40);
  }

  JsResult_emitExpression(__this, Node_binaryLeft(node), isRightAssociative ? (int32_t)((int32_t)operatorPrecedence + 1) : operatorPrecedence);
  StringBuilder_append(code, operator);
  JsResult_emitExpression(__this, Node_binaryRight(node), isRightAssociative ? operatorPrecedence : (int32_t)((int32_t)operatorPrecedence + 1));

  if (selfPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 41);
  }

  if (shouldCastToInt) {
    StringBuilder_append(code, isUnsigned ? (const uint16_t *)__string_300_0 : (const uint16_t *)__string_301_0);
  }

  if (parentPrecedence > selfPrecedence) {
    StringBuilder_appendChar(code, 41);
  }
}

static void JsResult_emitCommaSeparatedExpressions(struct JsResult *__this, struct Node *start, struct Node *stop) {
  while (start != stop) {
    JsResult_emitExpression(__this, start, 0);
    start = start->nextSibling;

    if (start != stop) {
      StringBuilder_append(__this->code, (const uint16_t *)__string_302);
    }
  }
}

static void JsResult_emitExpression(struct JsResult *__this, struct Node *node, int32_t parentPrecedence) {
  struct StringBuilder *code = __this->code;

  if (node->kind == 29) {
    struct Symbol *symbol = node->symbol;

    if (symbol->kind == 5 && Node_isDeclare(symbol->node)) {
      StringBuilder_append(code, (const uint16_t *)__string_303___declare);
    }

    JsResult_emitSymbolName(__this, symbol);
  }

  else if (node->kind == 31) {
    StringBuilder_append(code, (const uint16_t *)__string_304_null);
  }

  else if (node->kind == 22) {
    StringBuilder_append(code, node->intValue != 0 ? (const uint16_t *)__string_305_true : (const uint16_t *)__string_306_false);
  }

  else if (node->kind == 28) {
    if (parentPrecedence == 15) {
      StringBuilder_appendChar(code, 40);
    }

    StringBuilder_append(code, Type_isUnsigned(node->resolvedType) ? uint_toString((uint32_t)node->intValue) : int_toString(node->intValue));

    if (parentPrecedence == 15) {
      StringBuilder_appendChar(code, 41);
    }
  }

  else if (node->kind == 34) {
    StringBuilder_appendQuoted(code, node->stringValue);
  }

  else if (node->kind == 24) {
    struct CheckContext *context = __this->context;
    struct Node *value = Node_castValue(node);
    struct Type *from = Type_underlyingType(value->resolvedType, context);
    struct Type *type = Type_underlyingType(node->resolvedType, context);
    int32_t fromSize = Type_variableSizeOf(from, context);
    int32_t typeSize = Type_variableSizeOf(type, context);

    if (from == type || fromSize < typeSize) {
      JsResult_emitExpression(__this, value, parentPrecedence);
    }

    else if (type == context->sbyteType || type == context->shortType) {
      if (parentPrecedence > 9) {
        StringBuilder_appendChar(code, 40);
      }

      const uint16_t *shift = int_toString(32 - (typeSize << 3));
      JsResult_emitExpression(__this, value, 9);
      StringBuilder_append(code, (const uint16_t *)__string_307);
      StringBuilder_append(code, shift);
      StringBuilder_append(code, (const uint16_t *)__string_308);
      StringBuilder_append(code, shift);

      if (parentPrecedence > 9) {
        StringBuilder_appendChar(code, 41);
      }
    }

    else if (type == context->byteType || type == context->ushortType) {
      if (parentPrecedence > 6) {
        StringBuilder_appendChar(code, 40);
      }

      JsResult_emitExpression(__this, value, 6);
      StringBuilder_append(code, (const uint16_t *)__string_309);
      StringBuilder_append(code, uint_toString(Type_integerBitMask(type, context)));

      if (parentPrecedence > 6) {
        StringBuilder_appendChar(code, 41);
      }
    }

    else if (type == context->intType) {
      if (parentPrecedence > 4) {
        StringBuilder_appendChar(code, 40);
      }

      JsResult_emitExpression(__this, value, 4);
      StringBuilder_append(code, (const uint16_t *)__string_310_0);

      if (parentPrecedence > 4) {
        StringBuilder_appendChar(code, 41);
      }
    }

    else if (type == context->uintType) {
      if (parentPrecedence > 9) {
        StringBuilder_appendChar(code, 40);
      }

      JsResult_emitExpression(__this, value, 9);
      StringBuilder_append(code, (const uint16_t *)__string_311_0);

      if (parentPrecedence > 9) {
        StringBuilder_appendChar(code, 41);
      }
    }

    else {
      JsResult_emitExpression(__this, value, parentPrecedence);
    }
  }

  else if (node->kind == 25) {
    JsResult_emitExpression(__this, Node_dotTarget(node), 15);
    StringBuilder_appendChar(code, 46);
    JsResult_emitSymbolName(__this, node->symbol);
  }

  else if (node->kind == 26) {
    if (parentPrecedence > 1) {
      StringBuilder_appendChar(code, 40);
    }

    JsResult_emitExpression(__this, Node_hookValue(node), 2);
    StringBuilder_append(code, (const uint16_t *)__string_312);
    JsResult_emitExpression(__this, Node_hookTrue(node), 1);
    StringBuilder_append(code, (const uint16_t *)__string_313);
    JsResult_emitExpression(__this, Node_hookFalse(node), 1);

    if (parentPrecedence > 1) {
      StringBuilder_appendChar(code, 41);
    }
  }

  else if (node->kind == 27) {
    struct Node *value = Node_indexTarget(node);
    JsResult_emitExpression(__this, value, 14);
    StringBuilder_appendChar(code, 91);
    JsResult_emitCommaSeparatedExpressions(__this, value->nextSibling, NULL);
    StringBuilder_appendChar(code, 93);
  }

  else if (node->kind == 23) {
    if (Node_expandCallIntoOperatorTree(node)) {
      JsResult_emitExpression(__this, node, parentPrecedence);
    }

    else {
      struct Node *value = Node_callValue(node);
      JsResult_emitExpression(__this, value, 14);

      if (value->symbol == NULL || !Symbol_isGetter(value->symbol)) {
        StringBuilder_appendChar(code, 40);
        JsResult_emitCommaSeparatedExpressions(__this, value->nextSibling, NULL);
        StringBuilder_appendChar(code, 41);
      }
    }
  }

  else if (node->kind == 30) {
    StringBuilder_append(code, (const uint16_t *)__string_314_new);
    JsResult_emitExpression(__this, Node_newType(node), 14);
    StringBuilder_append(code, (const uint16_t *)__string_315);
  }

  else if (node->kind == 41) {
    struct Node *value = Node_unaryValue(node);
    Node_expandCallIntoOperatorTree(value);
    int32_t invertedKind = invertedBinaryKind(value->kind);

    if (invertedKind != value->kind) {
      value->kind = invertedKind;
      JsResult_emitExpression(__this, value, parentPrecedence);
    }

    else {
      JsResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_316);
    }
  }

  else if (node->kind == 38) {
    JsResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_317);
  }

  else if (node->kind == 40) {
    JsResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_318);
  }

  else if (node->kind == 43) {
    JsResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_319);
  }

  else if (node->kind == 47) {
    JsResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_320);
  }

  else if (node->kind == 46) {
    JsResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_321);
  }

  else if (node->kind == 45) {
    JsResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_322);
  }

  else if (node->kind == 44) {
    JsResult_emitUnary(__this, node, parentPrecedence, (const uint16_t *)__string_323);
  }

  else if (node->kind == 48) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_324, 10, 1);
  }

  else if (node->kind == 49) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_325, 1, 0);
  }

  else if (node->kind == 50) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_326, 6, 0);
  }

  else if (node->kind == 51) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_327, 4, 0);
  }

  else if (node->kind == 52) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_328, 5, 0);
  }

  else if (node->kind == 53) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_329, 11, 1);
  }

  else if (node->kind == 54) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_330, 7, 0);
  }

  else if (node->kind == 56) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_331, 8, 0);
  }

  else if (node->kind == 57) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_332, 8, 0);
  }

  else if (node->kind == 58) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_333, 8, 0);
  }

  else if (node->kind == 59) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_334, 8, 0);
  }

  else if (node->kind == 60) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_335, 3, 0);
  }

  else if (node->kind == 61) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_336, 2, 0);
  }

  else if (node->kind == 63) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_337, 7, 0);
  }

  else if (node->kind == 64) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_338, 11, 1);
  }

  else if (node->kind == 65) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_339, 9, 0);
  }

  else if (node->kind == 66) {
    JsResult_emitBinary(__this, node, parentPrecedence, Node_isUnsignedOperator(node) ? (const uint16_t *)__string_340 : (const uint16_t *)__string_341, 9, 0);
  }

  else if (node->kind == 67) {
    JsResult_emitBinary(__this, node, parentPrecedence, (const uint16_t *)__string_342, 10, 1);
  }

  else if (node->kind == 62) {
    struct Node *left = Node_binaryLeft(node);
    struct Node *right = Node_binaryRight(node);
    uint8_t isUnsigned = Node_isUnsignedOperator(node);

    if (isUnsigned && parentPrecedence > 9) {
      StringBuilder_appendChar(code, 40);
    }

    StringBuilder_append(code, (const uint16_t *)__string_343___imul);
    JsResult_emitExpression(__this, left, 0);
    StringBuilder_append(code, (const uint16_t *)__string_344);
    JsResult_emitExpression(__this, right, 0);
    StringBuilder_appendChar(code, 41);
    __this->foundMultiply = 1;

    if (isUnsigned) {
      StringBuilder_append(code, (const uint16_t *)__string_345_0);

      if (parentPrecedence > 9) {
        StringBuilder_appendChar(code, 41);
      }
    }
  }

  else {
    assert(0);
  }
}

static void JsResult_emitSymbolName(struct JsResult *__this, struct Symbol *symbol) {
  StringBuilder_append(__this->code, !string_op_equals(symbol->rename, NULL) ? symbol->rename : symbol->name);
}

static void JsResult_emitStatement(struct JsResult *__this, struct Node *node) {
  struct StringBuilder *code = __this->code;

  if (node->kind == 15) {
    struct Node *body = Node_functionBody(node);

    if (body == NULL) {
      return;
    }

    struct Symbol *symbol = node->symbol;
    uint8_t needsSemicolon = 0;
    JsResult_emitNewlineBefore(__this, node);
    JsResult_emitIndent(__this);

    if (symbol->kind == 4) {
      JsResult_emitSymbolName(__this, Symbol_parent(symbol));
      StringBuilder_append(code, (const uint16_t *)__string_346_prototype);
      JsResult_emitSymbolName(__this, symbol);
      StringBuilder_append(code, (const uint16_t *)__string_347_function);
      needsSemicolon = 1;
    }

    else if (Node_isExtern(node)) {
      StringBuilder_append(code, (const uint16_t *)__string_348_var);
      JsResult_emitSymbolName(__this, symbol);
      StringBuilder_append(code, (const uint16_t *)__string_349___extern);
      JsResult_emitSymbolName(__this, symbol);
      StringBuilder_append(code, (const uint16_t *)__string_350_function);
      needsSemicolon = 1;
    }

    else {
      StringBuilder_append(code, (const uint16_t *)__string_351_function);
      JsResult_emitSymbolName(__this, symbol);
    }

    StringBuilder_appendChar(code, 40);
    struct Node *returnType = Node_functionReturnType(node);
    struct Node *child = Node_functionFirstArgumentIgnoringThis(node);

    while (child != returnType) {
      assert(child->kind == 6);
      JsResult_emitSymbolName(__this, child->symbol);
      child = child->nextSibling;

      if (child != returnType) {
        StringBuilder_append(code, (const uint16_t *)__string_352);
      }
    }

    StringBuilder_append(code, (const uint16_t *)__string_353);
    JsResult_emitBlock(__this, Node_functionBody(node));
    StringBuilder_append(code, needsSemicolon ? (const uint16_t *)__string_354 : (const uint16_t *)__string_355);
    JsResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 16) {
    JsResult_emitNewlineBefore(__this, node);
    JsResult_emitIndent(__this);

    while (1) {
      StringBuilder_append(code, (const uint16_t *)__string_356_if);
      JsResult_emitExpression(__this, Node_ifValue(node), 0);
      StringBuilder_append(code, (const uint16_t *)__string_357);
      JsResult_emitBlock(__this, Node_ifTrue(node));
      struct Node *no = Node_ifFalse(node);

      if (no == NULL) {
        StringBuilder_appendChar(code, 10);

        break;
      }

      StringBuilder_append(code, (const uint16_t *)__string_358);
      JsResult_emitIndent(__this);
      StringBuilder_append(code, (const uint16_t *)__string_359_else);

      if (no->firstChild == NULL || no->firstChild != no->lastChild || no->firstChild->kind != 16) {
        JsResult_emitBlock(__this, no);
        StringBuilder_appendChar(code, 10);

        break;
      }

      node = no->firstChild;
    }

    JsResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 20) {
    JsResult_emitNewlineBefore(__this, node);
    JsResult_emitIndent(__this);
    StringBuilder_append(code, (const uint16_t *)__string_360_while);
    JsResult_emitExpression(__this, Node_whileValue(node), 0);
    StringBuilder_append(code, (const uint16_t *)__string_361);
    JsResult_emitBlock(__this, Node_whileBody(node));
    StringBuilder_appendChar(code, 10);
    JsResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 8) {
    JsResult_emitNewlineBefore(__this, node);
    JsResult_emitIndent(__this);
    StringBuilder_append(code, (const uint16_t *)__string_362_break);
    JsResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 11) {
    JsResult_emitNewlineBefore(__this, node);
    JsResult_emitIndent(__this);
    StringBuilder_append(code, (const uint16_t *)__string_363_continue);
    JsResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 14) {
    JsResult_emitNewlineBefore(__this, node);
    JsResult_emitIndent(__this);
    JsResult_emitExpression(__this, Node_expressionValue(node), 0);
    StringBuilder_append(code, (const uint16_t *)__string_364);
    JsResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 12) {
  }

  else if (node->kind == 17) {
    struct Node *value = Node_returnValue(node);
    JsResult_emitNewlineBefore(__this, node);
    JsResult_emitIndent(__this);

    if (value != NULL) {
      StringBuilder_append(code, (const uint16_t *)__string_365_return);
      JsResult_emitExpression(__this, value, 0);
      StringBuilder_append(code, (const uint16_t *)__string_366);
    }

    else {
      StringBuilder_append(code, (const uint16_t *)__string_367_return);
    }

    JsResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 7) {
    if (node->parent->kind == 7) {
      JsResult_emitStatements(__this, node->firstChild);
    }

    else {
      JsResult_emitNewlineBefore(__this, node);
      JsResult_emitIndent(__this);
      JsResult_emitBlock(__this, node);
      StringBuilder_appendChar(code, 10);
      JsResult_emitNewlineAfter(__this, node);
    }
  }

  else if (node->kind == 19) {
    JsResult_emitNewlineBefore(__this, node);
    JsResult_emitIndent(__this);
    StringBuilder_append(code, (const uint16_t *)__string_368_var);
    struct Node *child = node->firstChild;

    while (child != NULL) {
      struct Node *value = Node_variableValue(child);
      JsResult_emitSymbolName(__this, child->symbol);
      child = child->nextSibling;

      if (child != NULL) {
        StringBuilder_append(code, (const uint16_t *)__string_369);
      }

      assert(value != NULL);
      StringBuilder_append(code, (const uint16_t *)__string_370);
      JsResult_emitExpression(__this, value, 0);
    }

    StringBuilder_append(code, (const uint16_t *)__string_371);
    JsResult_emitNewlineAfter(__this, node);
  }

  else if (node->kind == 9) {
    if (!Node_isDeclare(node)) {
      JsResult_emitNewlineBefore(__this, node);
      JsResult_emitIndent(__this);
      StringBuilder_append(code, (const uint16_t *)__string_372_function);
      JsResult_emitSymbolName(__this, node->symbol);
      StringBuilder_append(code, (const uint16_t *)__string_373);
      __this->indent = __this->indent + 1;
      struct Node *argument = node->firstChild;

      while (argument != NULL) {
        if (argument->kind == 6) {
          JsResult_emitIndent(__this);
          StringBuilder_append(code, (const uint16_t *)__string_374_this);
          JsResult_emitSymbolName(__this, argument->symbol);
          StringBuilder_append(code, (const uint16_t *)__string_375);
          JsResult_emitExpression(__this, Node_variableValue(argument), 0);
          StringBuilder_append(code, (const uint16_t *)__string_376);
        }

        argument = argument->nextSibling;
      }

      __this->indent = __this->indent - 1;
      JsResult_emitIndent(__this);
      StringBuilder_append(code, (const uint16_t *)__string_377);
      JsResult_emitNewlineAfter(__this, node);
    }

    struct Node *child = node->firstChild;

    while (child != NULL) {
      if (child->kind == 15) {
        JsResult_emitStatement(__this, child);
      }

      child = child->nextSibling;
    }
  }

  else if (node->kind == 13) {
    if (Node_isExtern(node)) {
      JsResult_emitNewlineBefore(__this, node);
      JsResult_emitIndent(__this);
      StringBuilder_append(code, (const uint16_t *)__string_378___extern);
      JsResult_emitSymbolName(__this, node->symbol);
      StringBuilder_append(code, (const uint16_t *)__string_379);
      __this->indent = __this->indent + 1;
      struct Node *child = node->firstChild;

      while (child != NULL) {
        assert(child->kind == 6);
        JsResult_emitIndent(__this);
        JsResult_emitSymbolName(__this, child->symbol);
        StringBuilder_append(code, (const uint16_t *)__string_380);
        StringBuilder_append(code, int_toString(child->symbol->offset));
        child = child->nextSibling;
        StringBuilder_append(code, child != NULL ? (const uint16_t *)__string_381 : (const uint16_t *)__string_382);
      }

      __this->indent = __this->indent - 1;
      JsResult_emitIndent(__this);
      StringBuilder_append(code, (const uint16_t *)__string_383);
      JsResult_emitNewlineAfter(__this, node);
    }
  }

  else if (node->kind == 10) {
  }

  else {
    assert(0);
  }
}

static uint8_t jsKindCastsOperandsToInt(int32_t kind) {
  return kind == 65 || kind == 66 || kind == 51 || kind == 50 || kind == 52;
}

static void jsEmit(struct Compiler *compiler) {
  struct StringBuilder *code = StringBuilder_new();
  struct JsResult *result = calloc(1, sizeof(struct JsResult));
  result->context = compiler->context;
  result->code = code;
  StringBuilder_append(code, (const uint16_t *)__string_384_function___declare___extern);
  result->indent = 1;
  JsResult_emitStatements(result, compiler->global->firstChild);

  if (result->foundMultiply) {
    StringBuilder_appendChar(code, 10);
    JsResult_emitIndent(result);
    StringBuilder_append(code, (const uint16_t *)__string_385_var___imul_Math_imul_functi);
    result->indent = 2;
    JsResult_emitIndent(result);
    StringBuilder_append(code, (const uint16_t *)__string_386_return_a_b_16_16);
    result->indent = 1;
    JsResult_emitIndent(result);
    StringBuilder_append(code, (const uint16_t *)__string_387);
  }

  StringBuilder_append(code, (const uint16_t *)__string_388);
  JsResult_emitIndent(result);
  StringBuilder_append(code, (const uint16_t *)__string_389_typeof_global_undefined);
  JsResult_emitIndent(result);
  StringBuilder_append(code, (const uint16_t *)__string_390_typeof_exports_undefined);
  StringBuilder_append(code, (const uint16_t *)__string_391);
  compiler->outputJS = StringBuilder_finish(code);
}

static uint8_t isKeyword(int32_t kind) {
  return kind >= 40 && kind <= 72;
}

static void splitToken(struct Token *first, int32_t firstKind, int32_t secondKind) {
  struct Range *range = first->range;
  assert(range->end - range->start >= 2);
  struct Token *second = calloc(1, sizeof(struct Token));
  second->kind = secondKind;
  second->range = createRange(range->source, range->start + 1, range->end);
  second->next = first->next;
  first->kind = firstKind;
  first->next = second;
  range->end = range->start + 1;
}

static const uint16_t *tokenToString(int32_t token) {
  if (token == 0) {
    return (const uint16_t *)__string_392_end_of_file;
  }

  if (token == 1) {
    return (const uint16_t *)__string_393_character_literal;
  }

  if (token == 2) {
    return (const uint16_t *)__string_394_identifier;
  }

  if (token == 3) {
    return (const uint16_t *)__string_395_integer_literal;
  }

  if (token == 4) {
    return (const uint16_t *)__string_396_string_literal;
  }

  if (token == 5) {
    return (const uint16_t *)__string_397;
  }

  if (token == 6) {
    return (const uint16_t *)__string_398;
  }

  if (token == 7) {
    return (const uint16_t *)__string_399;
  }

  if (token == 8) {
    return (const uint16_t *)__string_400;
  }

  if (token == 9) {
    return (const uint16_t *)__string_401;
  }

  if (token == 10) {
    return (const uint16_t *)__string_402;
  }

  if (token == 11) {
    return (const uint16_t *)__string_403;
  }

  if (token == 12) {
    return (const uint16_t *)__string_404;
  }

  if (token == 13) {
    return (const uint16_t *)__string_405;
  }

  if (token == 14) {
    return (const uint16_t *)__string_406;
  }

  if (token == 15) {
    return (const uint16_t *)__string_407;
  }

  if (token == 16) {
    return (const uint16_t *)__string_408;
  }

  if (token == 17) {
    return (const uint16_t *)__string_409;
  }

  if (token == 18) {
    return (const uint16_t *)__string_410;
  }

  if (token == 19) {
    return (const uint16_t *)__string_411;
  }

  if (token == 20) {
    return (const uint16_t *)__string_412;
  }

  if (token == 21) {
    return (const uint16_t *)__string_413;
  }

  if (token == 22) {
    return (const uint16_t *)__string_414;
  }

  if (token == 23) {
    return (const uint16_t *)__string_415;
  }

  if (token == 24) {
    return (const uint16_t *)__string_416;
  }

  if (token == 25) {
    return (const uint16_t *)__string_417;
  }

  if (token == 26) {
    return (const uint16_t *)__string_418;
  }

  if (token == 27) {
    return (const uint16_t *)__string_419;
  }

  if (token == 28) {
    return (const uint16_t *)__string_420;
  }

  if (token == 29) {
    return (const uint16_t *)__string_421;
  }

  if (token == 30) {
    return (const uint16_t *)__string_422;
  }

  if (token == 31) {
    return (const uint16_t *)__string_423;
  }

  if (token == 32) {
    return (const uint16_t *)__string_424;
  }

  if (token == 33) {
    return (const uint16_t *)__string_425;
  }

  if (token == 34) {
    return (const uint16_t *)__string_426;
  }

  if (token == 35) {
    return (const uint16_t *)__string_427;
  }

  if (token == 36) {
    return (const uint16_t *)__string_428;
  }

  if (token == 37) {
    return (const uint16_t *)__string_429;
  }

  if (token == 38) {
    return (const uint16_t *)__string_430;
  }

  if (token == 39) {
    return (const uint16_t *)__string_431;
  }

  if (token == 40) {
    return (const uint16_t *)__string_432_alignof;
  }

  if (token == 41) {
    return (const uint16_t *)__string_433_as;
  }

  if (token == 42) {
    return (const uint16_t *)__string_434_break;
  }

  if (token == 43) {
    return (const uint16_t *)__string_435_class;
  }

  if (token == 44) {
    return (const uint16_t *)__string_436_const;
  }

  if (token == 45) {
    return (const uint16_t *)__string_437_continue;
  }

  if (token == 46) {
    return (const uint16_t *)__string_438_declare;
  }

  if (token == 47) {
    return (const uint16_t *)__string_439_else;
  }

  if (token == 48) {
    return (const uint16_t *)__string_440_enum;
  }

  if (token == 49) {
    return (const uint16_t *)__string_441_export;
  }

  if (token == 50) {
    return (const uint16_t *)__string_442_extends;
  }

  if (token == 51) {
    return (const uint16_t *)__string_443_extern;
  }

  if (token == 52) {
    return (const uint16_t *)__string_444_false;
  }

  if (token == 53) {
    return (const uint16_t *)__string_445_function;
  }

  if (token == 54) {
    return (const uint16_t *)__string_446_if;
  }

  if (token == 55) {
    return (const uint16_t *)__string_447_implements;
  }

  if (token == 56) {
    return (const uint16_t *)__string_448_import;
  }

  if (token == 57) {
    return (const uint16_t *)__string_449_interface;
  }

  if (token == 58) {
    return (const uint16_t *)__string_450_let;
  }

  if (token == 59) {
    return (const uint16_t *)__string_451_new;
  }

  if (token == 60) {
    return (const uint16_t *)__string_452_null;
  }

  if (token == 61) {
    return (const uint16_t *)__string_453_operator;
  }

  if (token == 62) {
    return (const uint16_t *)__string_454_private;
  }

  if (token == 63) {
    return (const uint16_t *)__string_455_protected;
  }

  if (token == 64) {
    return (const uint16_t *)__string_456_public;
  }

  if (token == 65) {
    return (const uint16_t *)__string_457_return;
  }

  if (token == 66) {
    return (const uint16_t *)__string_458_sizeof;
  }

  if (token == 67) {
    return (const uint16_t *)__string_459_static;
  }

  if (token == 68) {
    return (const uint16_t *)__string_460_this;
  }

  if (token == 69) {
    return (const uint16_t *)__string_461_true;
  }

  if (token == 70) {
    return (const uint16_t *)__string_462_unsafe;
  }

  if (token == 71) {
    return (const uint16_t *)__string_463_var;
  }

  if (token == 72) {
    return (const uint16_t *)__string_464_while;
  }

  if (token == 73) {
    return (const uint16_t *)__string_465_define;
  }

  if (token == 74) {
    return (const uint16_t *)__string_466_elif;
  }

  if (token == 75) {
    return (const uint16_t *)__string_467_else;
  }

  if (token == 76) {
    return (const uint16_t *)__string_468_endif;
  }

  if (token == 77) {
    return (const uint16_t *)__string_469_error;
  }

  if (token == 78) {
    return (const uint16_t *)__string_470_if;
  }

  if (token == 80) {
    return (const uint16_t *)__string_471_newline;
  }

  if (token == 81) {
    return (const uint16_t *)__string_472_undef;
  }

  if (token == 82) {
    return (const uint16_t *)__string_473_warning;
  }

  assert(0);

  return NULL;
}

static uint8_t isAlpha(uint16_t c) {
  return (c >= 97 && c <= 122) || (c >= 65 && c <= 90) || c == 95;
}

static uint8_t isASCII(uint16_t c) {
  return c >= 32 && c <= 126;
}

static uint8_t isNumber(uint16_t c) {
  return c >= 48 && c <= 57;
}

static uint8_t isDigit(uint16_t c, uint8_t base) {
  if (base == 16) {
    return isNumber(c) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102);
  }

  return c >= 48 && c < base + 48;
}

static struct Token *tokenize(struct Source *source, struct Log *log) {
  struct Token *first = NULL;
  struct Token *last = NULL;
  const uint16_t *contents = source->contents;
  int32_t limit = string_length(contents);
  uint8_t needsPreprocessor = 0;
  uint8_t wantNewline = 0;
  int32_t i = 0;

  while (i < limit) {
    int32_t start = i;
    uint16_t c = string_op_get(contents, i);
    i = i + 1;

    if (c == 32 || c == 9 || c == 13) {
      continue;
    }

    int32_t kind = 0;

    if (c == 10) {
      if (!wantNewline) {
        continue;
      }

      kind = 80;
      wantNewline = 0;
    }

    else if (isAlpha(c)) {
      kind = 2;

      while (i < limit && (isAlpha(string_op_get(contents, i)) || isNumber(string_op_get(contents, i)))) {
        i = i + 1;
      }

      int32_t length = i - start;

      if (length >= 2 && length <= 10) {
        const uint16_t *text = string_slice(contents, start, i);

        if (length == 2) {
          if (string_op_equals(text, (const uint16_t *)__string_474_as)) {
            kind = 41;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_475_if)) {
            kind = 54;
          }
        }

        else if (length == 3) {
          if (string_op_equals(text, (const uint16_t *)__string_476_let)) {
            kind = 58;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_477_new)) {
            kind = 59;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_478_var)) {
            kind = 71;
          }
        }

        else if (length == 4) {
          if (string_op_equals(text, (const uint16_t *)__string_479_else)) {
            kind = 47;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_480_enum)) {
            kind = 48;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_481_null)) {
            kind = 60;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_482_this)) {
            kind = 68;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_483_true)) {
            kind = 69;
          }
        }

        else if (length == 5) {
          if (string_op_equals(text, (const uint16_t *)__string_484_break)) {
            kind = 42;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_485_class)) {
            kind = 43;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_486_const)) {
            kind = 44;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_487_false)) {
            kind = 52;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_488_while)) {
            kind = 72;
          }
        }

        else if (length == 6) {
          if (string_op_equals(text, (const uint16_t *)__string_489_export)) {
            kind = 49;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_490_extern)) {
            kind = 51;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_491_import)) {
            kind = 56;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_492_public)) {
            kind = 64;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_493_return)) {
            kind = 65;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_494_sizeof)) {
            kind = 66;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_495_static)) {
            kind = 67;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_496_unsafe)) {
            kind = 70;
          }
        }

        else if (length == 7) {
          if (string_op_equals(text, (const uint16_t *)__string_497_alignof)) {
            kind = 40;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_498_declare)) {
            kind = 46;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_499_extends)) {
            kind = 50;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_500_private)) {
            kind = 62;
          }
        }

        else if (string_op_equals(text, (const uint16_t *)__string_501_continue)) {
          kind = 45;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_502_function)) {
          kind = 53;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_503_implements)) {
          kind = 55;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_504_interface)) {
          kind = 57;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_505_protected)) {
          kind = 63;
        }
      }
    }

    else if (isNumber(c)) {
      kind = 3;

      if (i < limit) {
        uint16_t next = string_op_get(contents, i);
        uint8_t base = 10;

        if (c == 48 && i + 1 < limit) {
          if (next == 98 || next == 66) {
            base = 2;
          }

          else if (next == 111 || next == 79) {
            base = 8;
          }

          else if (next == 120 || next == 88) {
            base = 16;
          }

          if (base != 10) {
            if (isDigit(string_op_get(contents, i + 1), base)) {
              i = i + 2;
            }

            else {
              base = 10;
            }
          }
        }

        while (i < limit && isDigit(string_op_get(contents, i), base)) {
          i = i + 1;
        }

        if (i < limit && (isAlpha(string_op_get(contents, i)) || isNumber(string_op_get(contents, i)))) {
          i = i + 1;

          while (i < limit && (isAlpha(string_op_get(contents, i)) || isNumber(string_op_get(contents, i)))) {
            i = i + 1;
          }

          Log_error(log, createRange(source, start, i), StringBuilder_finish(StringBuilder_appendChar(StringBuilder_appendSlice(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_506_Invalid_integer_literal), contents, start, i), 39)));

          return NULL;
        }
      }
    }

    else if (c == 34 || c == 39 || c == 96) {
      while (i < limit) {
        uint16_t next = string_op_get(contents, i);

        if (i + 1 < limit && next == 92) {
          i = i + 2;
        }

        else if (next == 10 && c != 96) {
          break;
        }

        else {
          i = i + 1;

          if (next == c) {
            kind = c == 39 ? 1 : 4;

            break;
          }
        }
      }

      if (kind == 0) {
        Log_error(log, createRange(source, start, i), c == 39 ? (const uint16_t *)__string_507_Unterminated_character_literal : c == 96 ? (const uint16_t *)__string_508_Unterminated_template_literal : (const uint16_t *)__string_509_Unterminated_string_literal);

        return NULL;
      }
    }

    else if (c == 37) {
      kind = 33;
    }

    else if (c == 40) {
      kind = 20;
    }

    else if (c == 41) {
      kind = 36;
    }

    else if (c == 44) {
      kind = 10;
    }

    else if (c == 46) {
      kind = 13;
    }

    else if (c == 58) {
      kind = 9;
    }

    else if (c == 59) {
      kind = 37;
    }

    else if (c == 63) {
      kind = 32;
    }

    else if (c == 91) {
      kind = 19;
    }

    else if (c == 93) {
      kind = 35;
    }

    else if (c == 94) {
      kind = 8;
    }

    else if (c == 123) {
      kind = 18;
    }

    else if (c == 125) {
      kind = 34;
    }

    else if (c == 126) {
      kind = 11;
    }

    else if (c == 42) {
      kind = 27;

      if (i < limit && string_op_get(contents, i) == 42) {
        kind = 15;
        i = i + 1;
      }
    }

    else if (c == 47) {
      kind = 12;

      if (i < limit && string_op_get(contents, i) == 47) {
        i = i + 1;

        while (i < limit && string_op_get(contents, i) != 10) {
          i = i + 1;
        }

        continue;
      }

      if (i < limit && string_op_get(contents, i) == 42) {
        i = i + 1;
        uint8_t foundEnd = 0;

        while (i < limit) {
          uint16_t next = string_op_get(contents, i);

          if (next == 42 && i + 1 < limit && string_op_get(contents, i + 1) == 47) {
            foundEnd = 1;
            i = i + 2;

            break;
          }

          i = i + 1;
        }

        if (!foundEnd) {
          Log_error(log, createRange(source, start, start + 2), (const uint16_t *)__string_510_Unterminated_multi_line_comment);

          return NULL;
        }

        continue;
      }
    }

    else if (c == 33) {
      kind = 28;

      if (i < limit && string_op_get(contents, i) == 61) {
        kind = 29;
        i = i + 1;

        if (i < limit && string_op_get(contents, i) == 61) {
          i = i + 1;
          Log_error(log, createRange(source, start, i), (const uint16_t *)__string_511_Use_instead_of);
        }
      }
    }

    else if (c == 61) {
      kind = 5;

      if (i < limit && string_op_get(contents, i) == 61) {
        kind = 14;
        i = i + 1;

        if (i < limit && string_op_get(contents, i) == 61) {
          i = i + 1;
          Log_error(log, createRange(source, start, i), (const uint16_t *)__string_512_Use_instead_of);
        }
      }
    }

    else if (c == 43) {
      kind = 30;

      if (i < limit && string_op_get(contents, i) == 43) {
        kind = 31;
        i = i + 1;
      }
    }

    else if (c == 45) {
      kind = 25;

      if (i < limit && string_op_get(contents, i) == 45) {
        kind = 26;
        i = i + 1;
      }
    }

    else if (c == 38) {
      kind = 6;

      if (i < limit && string_op_get(contents, i) == 38) {
        kind = 23;
        i = i + 1;
      }
    }

    else if (c == 124) {
      kind = 7;

      if (i < limit && string_op_get(contents, i) == 124) {
        kind = 24;
        i = i + 1;
      }
    }

    else if (c == 60) {
      kind = 21;

      if (i < limit) {
        c = string_op_get(contents, i);

        if (c == 60) {
          kind = 38;
          i = i + 1;
        }

        else if (c == 61) {
          kind = 22;
          i = i + 1;
        }
      }
    }

    else if (c == 62) {
      kind = 16;

      if (i < limit) {
        c = string_op_get(contents, i);

        if (c == 62) {
          kind = 39;
          i = i + 1;
        }

        else if (c == 61) {
          kind = 17;
          i = i + 1;
        }
      }
    }

    else if (c == 35) {
      while (i < limit && (isAlpha(string_op_get(contents, i)) || isNumber(string_op_get(contents, i)))) {
        i = i + 1;
      }

      const uint16_t *text = string_slice(contents, start, i);

      if (string_op_equals(text, (const uint16_t *)__string_513_define)) {
        kind = 73;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_514_elif)) {
        kind = 74;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_515_else)) {
        kind = 75;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_516_endif)) {
        kind = 76;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_517_error)) {
        kind = 77;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_518_if)) {
        kind = 78;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_519_undef)) {
        kind = 81;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_520_warning)) {
        kind = 82;
      }

      else if (start == 0 && string_op_equals(text, (const uint16_t *)__string_521) && i < limit && string_op_get(contents, i) == 33) {
        while (i < limit && string_op_get(contents, i) != 10) {
          i = i + 1;
        }

        continue;
      }

      else {
        struct StringBuilder *builder = StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_522_Invalid_preprocessor_token), text), 39);

        if (string_op_equals(text, (const uint16_t *)__string_523_ifdef)) {
          StringBuilder_append(builder, (const uint16_t *)__string_524_did_you_mean_if);
          kind = 78;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_525_elsif) || string_op_equals(text, (const uint16_t *)__string_526_elseif)) {
          StringBuilder_append(builder, (const uint16_t *)__string_527_did_you_mean_elif);
          kind = 74;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_528_end)) {
          StringBuilder_append(builder, (const uint16_t *)__string_529_did_you_mean_endif);
          kind = 76;
        }

        Log_error(log, createRange(source, start, i), StringBuilder_finish(builder));
      }

      if (last != NULL && last->kind != 80) {
        int32_t end = last->range->end;
        int32_t j = i - 1;

        while (j >= end) {
          if (string_op_get(contents, j) == 10) {
            break;
          }

          j = j - 1;
        }

        if (j < end) {
          Log_error(log, createRange(source, start, i), StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_530_Expected_newline_before), tokenToString(kind))));
        }
      }

      needsPreprocessor = 1;
      wantNewline = 1;
    }

    struct Range *range = createRange(source, start, i);

    if (kind == 0) {
      Log_error(log, range, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_appendSlice(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_531_Syntax_error), contents, start, start + 1), 39)));

      return NULL;
    }

    struct Token *token = calloc(1, sizeof(struct Token));
    token->kind = kind;
    token->range = range;

    if (first == NULL) {
      first = token;
    }

    else {
      last->next = token;
    }

    last = token;
  }

  struct Token *eof = calloc(1, sizeof(struct Token));
  eof->kind = 0;
  eof->range = createRange(source, limit, limit);

  if (first == NULL) {
    first = eof;
  }

  else {
    last->next = eof;
  }

  last = eof;

  if (needsPreprocessor) {
    struct Token *token = calloc(1, sizeof(struct Token));
    token->kind = 79;
    token->next = first;

    return token;
  }

  return first;
}

static const uint16_t *library() {
  return (const uint16_t *)__string_532_if_WASM_These_will_be_fi;
}

static struct LineColumn *Source_indexToLineColumn(struct Source *__this, int32_t index) {
  const uint16_t *contents = __this->contents;
  int32_t column = 0;
  int32_t line = 0;
  int32_t i = 0;

  while (i < index) {
    uint16_t c = string_op_get(contents, i);

    if (c == 10) {
      line = line + 1;
      column = 0;
    }

    else if (c < 56320 || c > 57343) {
      column = column + 1;
    }

    i = i + 1;
  }

  struct LineColumn *location = calloc(1, sizeof(struct LineColumn));
  location->line = line;
  location->column = column;

  return location;
}

static const uint16_t *Range_toString(struct Range *__this) {
  return string_slice(__this->source->contents, __this->start, __this->end);
}

static uint8_t Range_equals(struct Range *__this, struct Range *other) {
  return __this->source == other->source && __this->start == other->start && __this->end == other->end;
}

static struct Range *Range_enclosingLine(struct Range *__this) {
  const uint16_t *contents = __this->source->contents;
  int32_t start = __this->start;
  int32_t end = __this->start;

  while (start > 0 && string_op_get(contents, start - 1) != 10) {
    start = start - 1;
  }

  int32_t length = string_length(contents);

  while (end < length && string_op_get(contents, end) != 10) {
    end = end + 1;
  }

  return createRange(__this->source, start, end);
}

static struct Range *Range_rangeAtEnd(struct Range *__this) {
  return createRange(__this->source, __this->end, __this->end);
}

static struct Range *createRange(struct Source *source, int32_t start, int32_t end) {
  assert(start <= end);
  struct Range *range = calloc(1, sizeof(struct Range));
  range->source = source;
  range->start = start;
  range->end = end;

  return range;
}

static struct Range *spanRanges(struct Range *left, struct Range *right) {
  assert(left->source == right->source);
  assert(left->start <= right->start);
  assert(left->end <= right->end);

  return createRange(left->source, left->start, right->end);
}

static void Diagnostic_appendSourceName(struct Diagnostic *__this, struct StringBuilder *builder, struct LineColumn *location) {
  StringBuilder_append(StringBuilder_append(StringBuilder_appendChar(StringBuilder_append(StringBuilder_appendChar(StringBuilder_append(builder, __this->range->source->name), 58), int_toString(location->line + 1)), 58), int_toString(location->column + 1)), (const uint16_t *)__string_533);
}

static void Diagnostic_appendKind(struct Diagnostic *__this, struct StringBuilder *builder) {
  StringBuilder_append(builder, __this->kind == 0 ? (const uint16_t *)__string_534_error : (const uint16_t *)__string_535_warning);
}

static void Diagnostic_appendMessage(struct Diagnostic *__this, struct StringBuilder *builder) {
  StringBuilder_appendChar(StringBuilder_append(builder, __this->message), 10);
}

static void Diagnostic_appendLineContents(struct Diagnostic *__this, struct StringBuilder *builder, struct LineColumn *location) {
  struct Range *range = Range_enclosingLine(__this->range);
  StringBuilder_appendChar(StringBuilder_appendSlice(builder, range->source->contents, range->start, range->end), 10);
}

static void Diagnostic_appendRange(struct Diagnostic *__this, struct StringBuilder *builder, struct LineColumn *location) {
  struct Range *range = __this->range;
  int32_t column = location->column;
  const uint16_t *contents = range->source->contents;

  while (column > 0) {
    StringBuilder_appendChar(builder, 32);
    column = column - 1;
  }

  if (range->end - range->start <= 1) {
    StringBuilder_appendChar(builder, 94);
  }

  else {
    int32_t i = range->start;

    while (i < range->end && string_op_get(contents, i) != 10) {
      StringBuilder_appendChar(builder, 126);
      i = i + 1;
    }
  }

  StringBuilder_appendChar(builder, 10);
}

static void Log_error(struct Log *__this, struct Range *range, const uint16_t *message) {
  Log_append(__this, range, message, 0);
}

static void Log_warning(struct Log *__this, struct Range *range, const uint16_t *message) {
  Log_append(__this, range, message, 1);
}

static void Log_append(struct Log *__this, struct Range *range, const uint16_t *message, int32_t kind) {
  struct Diagnostic *diagnostic = calloc(1, sizeof(struct Diagnostic));
  diagnostic->range = range;
  diagnostic->message = message;
  diagnostic->kind = kind;

  if (__this->first == NULL) {
    __this->first = diagnostic;
  }

  else {
    __this->last->next = diagnostic;
  }

  __this->last = diagnostic;
}

static const uint16_t *Log_toString(struct Log *__this) {
  struct StringBuilder *builder = StringBuilder_new();
  struct Diagnostic *diagnostic = __this->first;

  while (diagnostic != NULL) {
    struct LineColumn *location = Source_indexToLineColumn(diagnostic->range->source, diagnostic->range->start);
    Diagnostic_appendSourceName(diagnostic, builder, location);
    Diagnostic_appendKind(diagnostic, builder);
    Diagnostic_appendMessage(diagnostic, builder);
    Diagnostic_appendLineContents(diagnostic, builder, location);
    Diagnostic_appendRange(diagnostic, builder, location);
    diagnostic = diagnostic->next;
  }

  return StringBuilder_finish(builder);
}

static uint8_t Log_hasErrors(struct Log *__this) {
  struct Diagnostic *diagnostic = __this->first;

  while (diagnostic != NULL) {
    if (diagnostic->kind == 0) {
      return 1;
    }

    diagnostic = diagnostic->next;
  }

  return 0;
}

static void writeLogToTerminal(struct Log *log) {
  struct Diagnostic *diagnostic = log->first;

  while (diagnostic != NULL) {
    struct LineColumn *location = Source_indexToLineColumn(diagnostic->range->source, diagnostic->range->start);
    struct StringBuilder *builder = StringBuilder_new();
    Diagnostic_appendSourceName(diagnostic, builder, location);
    Terminal_setColor(1);
    Terminal_write(StringBuilder_finish(builder));
    builder = StringBuilder_new();
    Diagnostic_appendKind(diagnostic, builder);
    Terminal_setColor(diagnostic->kind == 0 ? 2 : 4);
    Terminal_write(StringBuilder_finish(builder));
    builder = StringBuilder_new();
    Diagnostic_appendMessage(diagnostic, builder);
    Terminal_setColor(1);
    Terminal_write(StringBuilder_finish(builder));
    builder = StringBuilder_new();
    Diagnostic_appendLineContents(diagnostic, builder, location);
    Terminal_setColor(0);
    Terminal_write(StringBuilder_finish(builder));
    builder = StringBuilder_new();
    Diagnostic_appendRange(diagnostic, builder, location);
    Terminal_setColor(3);
    Terminal_write(StringBuilder_finish(builder));
    diagnostic = diagnostic->next;
  }

  Terminal_setColor(0);
}

static void printError(const uint16_t *text) {
  Terminal_setColor(2);
  Terminal_write((const uint16_t *)__string_536_error);
  Terminal_setColor(1);
  Terminal_write(text);
  Terminal_write((const uint16_t *)__string_537);
  Terminal_setColor(0);
}

void main_addArgument(const uint16_t *text) {
  struct CommandLineArgument *argument = calloc(1, sizeof(struct CommandLineArgument));
  argument->text = text;

  if (firstArgument == NULL) {
    firstArgument = argument;
  }

  else {
    lastArgument->next = argument;
  }

  lastArgument = argument;
}

void main_reset() {
  firstArgument = NULL;
  lastArgument = NULL;
}

static void printUsage() {
  Terminal_write((const uint16_t *)__string_538_Usage_thinc_FLAGS_INPUTS);
}

int32_t main_entry() {
  int32_t target = 0;
  struct CommandLineArgument *argument = firstArgument;
  int32_t inputCount = 0;
  const uint16_t *output = NULL;

  if (firstArgument == NULL) {
    printUsage();

    return 1;
  }

  while (argument != NULL) {
    const uint16_t *text = argument->text;

    if (string_startsWith(text, (const uint16_t *)__string_539)) {
      if (string_op_equals(text, (const uint16_t *)__string_540_h) || string_op_equals(text, (const uint16_t *)__string_541_help) || string_op_equals(text, (const uint16_t *)__string_542_help) || string_op_equals(text, (const uint16_t *)__string_543)) {
        printUsage();

        return 0;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_544_c)) {
        target = 1;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_545_js)) {
        target = 2;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_546_wasm)) {
        target = 3;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_547_define) && argument->next != NULL) {
        argument = argument->next;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_548_out) && argument->next != NULL) {
        argument = argument->next;
        output = argument->text;
      }

      else {
        printError(StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_549_Invalid_flag), text)));

        return 1;
      }
    }

    else {
      inputCount = inputCount + 1;
    }

    argument = argument->next;
  }

  if (inputCount == 0) {
    printError((const uint16_t *)__string_550_No_input_files);

    return 1;
  }

  if (string_op_equals(output, NULL)) {
    printError((const uint16_t *)__string_551_Missing_an_output_file_use_the);

    return 1;
  }

  if (target == 0) {
    if (string_endsWith(output, (const uint16_t *)__string_552_c)) {
      target = 1;
    }

    else if (string_endsWith(output, (const uint16_t *)__string_553_js)) {
      target = 2;
    }

    else if (string_endsWith(output, (const uint16_t *)__string_554_wasm)) {
      target = 3;
    }

    else {
      printError((const uint16_t *)__string_555_Missing_a_target_use_either_c);

      return 1;
    }
  }

  struct Compiler *compiler = calloc(1, sizeof(struct Compiler));
  Compiler_initialize(compiler, target, output);
  argument = firstArgument;

  while (argument != NULL) {
    const uint16_t *text = argument->text;

    if (string_op_equals(text, (const uint16_t *)__string_556_define)) {
      argument = argument->next;
      Preprocessor_define(compiler->preprocessor, argument->text, 1);
    }

    else if (string_op_equals(text, (const uint16_t *)__string_557_out)) {
      argument = argument->next;
    }

    else if (!string_startsWith(text, (const uint16_t *)__string_558)) {
      const uint16_t *contents = IO_readTextFile(text);

      if (string_op_equals(contents, NULL)) {
        printError(StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_559_Cannot_read_from), text)));

        return 1;
      }

      Compiler_addInput(compiler, text, contents);
    }

    argument = argument->next;
  }

  Compiler_finish(compiler);
  writeLogToTerminal(compiler->log);

  if (!Log_hasErrors(compiler->log)) {
    if ((target == 1 && IO_writeTextFile(output, compiler->outputC) && IO_writeTextFile(replaceFileExtension(output, (const uint16_t *)__string_560_h), compiler->outputH)) || (target == 2 && IO_writeTextFile(output, compiler->outputJS)) || (target == 3 && IO_writeBinaryFile(output, compiler->outputWASM))) {
      return 0;
    }

    printError(StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_561_Cannot_write_to), output)));
  }

  return 1;
}

static uint8_t isUnary(int32_t kind) {
  return kind >= 37 && kind <= 47;
}

static uint8_t isUnaryPostfix(int32_t kind) {
  return kind >= 44 && kind <= 45;
}

static uint8_t isBinary(int32_t kind) {
  return kind >= 48 && kind <= 67;
}

static int32_t invertedBinaryKind(int32_t kind) {
  if (kind == 54) {
    return 63;
  }

  if (kind == 63) {
    return 54;
  }

  if (kind == 56) {
    return 59;
  }

  if (kind == 57) {
    return 58;
  }

  if (kind == 58) {
    return 57;
  }

  if (kind == 59) {
    return 56;
  }

  return kind;
}

static uint8_t isExpression(struct Node *node) {
  return node->kind >= 21 && node->kind <= 67;
}

static uint8_t isCompactNodeKind(int32_t kind) {
  return kind == 10 || kind == 14 || kind == 19;
}

static struct NodeFlag *appendFlag(struct NodeFlag *first, int32_t flag, struct Range *range) {
  struct NodeFlag *link = calloc(1, sizeof(struct NodeFlag));
  link->flag = flag;
  link->range = range;

  if (first == NULL) {
    return link;
  }

  struct NodeFlag *secondToLast = first;

  while (secondToLast->next != NULL) {
    secondToLast = secondToLast->next;
  }

  secondToLast->next = link;

  return first;
}

static int32_t allFlags(struct NodeFlag *link) {
  int32_t all = 0;

  while (link != NULL) {
    all = all | link->flag;
    link = link->next;
  }

  return all;
}

static struct Range *rangeForFlag(struct NodeFlag *link, int32_t flag) {
  while (link != NULL) {
    if (link->flag == flag) {
      return link->range;
    }

    link = link->next;
  }

  return NULL;
}

static void Node_become(struct Node *__this, struct Node *node) {
  assert(node != __this);
  assert(node->parent == NULL);
  __this->kind = node->kind;
  __this->flags = node->flags;
  __this->firstFlag = node->firstFlag;
  __this->range = node->range;
  __this->internalRange = node->internalRange;
  __this->intValue = node->intValue;
  __this->stringValue = node->stringValue;
  __this->resolvedType = node->resolvedType;
  __this->symbol = node->symbol;
  __this->scope = node->scope;
}

static void Node_becomeSymbolReference(struct Node *__this, struct Symbol *symbol) {
  __this->kind = 29;
  __this->symbol = symbol;
  __this->stringValue = symbol->name;
  __this->resolvedType = symbol->resolvedType;
  Node_removeChildren(__this);
}

static void Node_becomeIntegerConstant(struct Node *__this, int32_t value) {
  __this->kind = 28;
  __this->symbol = NULL;
  __this->intValue = value;
  Node_removeChildren(__this);
}

static void Node_becomeBooleanConstant(struct Node *__this, uint8_t value) {
  __this->kind = 22;
  __this->symbol = NULL;
  __this->intValue = value ? 1 : 0;
  Node_removeChildren(__this);
}

static uint8_t Node_isNegativeInteger(struct Node *__this) {
  return __this->kind == 28 && __this->intValue < 0;
}

static uint8_t Node_isNonNegativeInteger(struct Node *__this) {
  return __this->kind == 28 && __this->intValue >= 0;
}

static uint8_t Node_isDeclare(struct Node *__this) {
  return (__this->flags & 1) != 0;
}

static uint8_t Node_isExtern(struct Node *__this) {
  return (__this->flags & 4) != 0;
}

static uint8_t Node_isDeclareOrExtern(struct Node *__this) {
  return (__this->flags & 5) != 0;
}

static uint8_t Node_isGet(struct Node *__this) {
  return (__this->flags & 8) != 0;
}

static uint8_t Node_isSet(struct Node *__this) {
  return (__this->flags & 512) != 0;
}

static uint8_t Node_isOperator(struct Node *__this) {
  return (__this->flags & 16) != 0;
}

static uint8_t Node_isPositive(struct Node *__this) {
  return (__this->flags & 32) != 0;
}

static uint8_t Node_isPrivate(struct Node *__this) {
  return (__this->flags & 64) != 0;
}

static uint8_t Node_isUnsafe(struct Node *__this) {
  return (__this->flags & 2048) != 0;
}

static uint8_t Node_isUnsignedOperator(struct Node *__this) {
  return (__this->flags & 4096) != 0;
}

static int32_t Node_childCount(struct Node *__this) {
  int32_t count = 0;
  struct Node *child = __this->firstChild;

  while (child != NULL) {
    count = count + 1;
    child = child->nextSibling;
  }

  return count;
}

static void Node_appendChild(struct Node *__this, struct Node *child) {
  child->parent = __this;

  if (__this->firstChild == NULL) {
    __this->firstChild = child;
  }

  else {
    child->previousSibling = __this->lastChild;
    __this->lastChild->nextSibling = child;
  }

  __this->lastChild = child;
}

static void Node_insertChildBefore(struct Node *__this, struct Node *after, struct Node *before) {
  if (before == NULL) {
    return;
  }

  assert(before != after);
  assert(before->parent == NULL);
  assert(before->previousSibling == NULL);
  assert(before->nextSibling == NULL);
  assert(after == NULL || after->parent == __this);

  if (after == NULL) {
    Node_appendChild(__this, before);

    return;
  }

  before->parent = __this;
  before->previousSibling = after->previousSibling;
  before->nextSibling = after;

  if (after->previousSibling != NULL) {
    assert(after == after->previousSibling->nextSibling);
    after->previousSibling->nextSibling = before;
  }

  else {
    assert(after == __this->firstChild);
    __this->firstChild = before;
  }

  after->previousSibling = before;
}

static struct Node *Node_remove(struct Node *__this) {
  assert(__this->parent != NULL);

  if (__this->previousSibling != NULL) {
    assert(__this->previousSibling->nextSibling == __this);
    __this->previousSibling->nextSibling = __this->nextSibling;
  }

  else {
    assert(__this->parent->firstChild == __this);
    __this->parent->firstChild = __this->nextSibling;
  }

  if (__this->nextSibling != NULL) {
    assert(__this->nextSibling->previousSibling == __this);
    __this->nextSibling->previousSibling = __this->previousSibling;
  }

  else {
    assert(__this->parent->lastChild == __this);
    __this->parent->lastChild = __this->previousSibling;
  }

  __this->parent = NULL;
  __this->previousSibling = NULL;
  __this->nextSibling = NULL;

  return __this;
}

static void Node_removeChildren(struct Node *__this) {
  while (__this->lastChild != NULL) {
    Node_remove(__this->lastChild);
  }
}

static void Node_replaceWith(struct Node *__this, struct Node *node) {
  assert(node != __this);
  assert(__this->parent != NULL);
  assert(node->parent == NULL);
  assert(node->previousSibling == NULL);
  assert(node->nextSibling == NULL);
  node->parent = __this->parent;
  node->previousSibling = __this->previousSibling;
  node->nextSibling = __this->nextSibling;

  if (__this->previousSibling != NULL) {
    assert(__this->previousSibling->nextSibling == __this);
    __this->previousSibling->nextSibling = node;
  }

  else {
    assert(__this->parent->firstChild == __this);
    __this->parent->firstChild = node;
  }

  if (__this->nextSibling != NULL) {
    assert(__this->nextSibling->previousSibling == __this);
    __this->nextSibling->previousSibling = node;
  }

  else {
    assert(__this->parent->lastChild == __this);
    __this->parent->lastChild = node;
  }

  __this->parent = NULL;
  __this->previousSibling = NULL;
  __this->nextSibling = NULL;
}

static uint8_t Node_isType(struct Node *__this) {
  return __this->kind == 36 || __this->kind == 42 || (__this->symbol != NULL && isType(__this->symbol->kind));
}

static uint8_t Node_isCallValue(struct Node *__this) {
  return __this->parent->kind == 23 && __this == Node_callValue(__this->parent);
}

static uint8_t Node_isAssignTarget(struct Node *__this) {
  return __this->parent->kind == 49 && __this == Node_binaryLeft(__this->parent);
}

static struct Node *Node_withRange(struct Node *__this, struct Range *range) {
  __this->range = range;

  return __this;
}

static struct Node *Node_withInternalRange(struct Node *__this, struct Range *range) {
  __this->internalRange = range;

  return __this;
}

static struct Node *Node_functionFirstArgument(struct Node *__this) {
  assert(__this->kind == 15);
  assert(Node_childCount(__this) >= 2);
  struct Node *child = __this->firstChild;

  if (child->kind == 5) {
    child = child->nextSibling;
  }

  return child;
}

static struct Node *Node_functionFirstArgumentIgnoringThis(struct Node *__this) {
  assert(__this->kind == 15);
  assert(Node_childCount(__this) >= 2);
  assert(__this->symbol != NULL);
  struct Node *child = Node_functionFirstArgument(__this);

  if (__this->symbol->kind == 4) {
    child = child->nextSibling;
  }

  return child;
}

static struct Node *Node_functionReturnType(struct Node *__this) {
  assert(__this->kind == 15);
  assert(Node_childCount(__this) >= 2);
  assert(isExpression(__this->lastChild->previousSibling));

  return __this->lastChild->previousSibling;
}

static struct Node *Node_functionBody(struct Node *__this) {
  assert(__this->kind == 15);
  assert(Node_childCount(__this) >= 2);
  assert(__this->lastChild->kind == 7 || __this->lastChild->kind == 12);
  struct Node *body = __this->lastChild;

  return body->kind == 7 ? body : NULL;
}

static struct Node *Node_newType(struct Node *__this) {
  assert(__this->kind == 30);
  assert(Node_childCount(__this) >= 1);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_callValue(struct Node *__this) {
  assert(__this->kind == 23);
  assert(Node_childCount(__this) >= 1);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_castValue(struct Node *__this) {
  assert(__this->kind == 24);
  assert(Node_childCount(__this) == 2);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_castType(struct Node *__this) {
  assert(__this->kind == 24);
  assert(Node_childCount(__this) == 2);
  assert(isExpression(__this->lastChild));

  return __this->lastChild;
}

static struct Node *Node_alignOfType(struct Node *__this) {
  assert(__this->kind == 21);
  assert(Node_childCount(__this) == 1);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_sizeOfType(struct Node *__this) {
  assert(__this->kind == 33);
  assert(Node_childCount(__this) == 1);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_dotTarget(struct Node *__this) {
  assert(__this->kind == 25);
  assert(Node_childCount(__this) == 1);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_returnValue(struct Node *__this) {
  assert(__this->kind == 17);
  assert(Node_childCount(__this) <= 1);
  assert(__this->firstChild == NULL || isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_extendsType(struct Node *__this) {
  assert(__this->kind == 0);
  assert(Node_childCount(__this) == 1);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_variableType(struct Node *__this) {
  assert(__this->kind == 6);
  assert(Node_childCount(__this) <= 2);
  assert(isExpression(__this->firstChild) || __this->firstChild->kind == 12);
  struct Node *type = __this->firstChild;

  return type->kind != 12 ? type : NULL;
}

static struct Node *Node_variableValue(struct Node *__this) {
  assert(__this->kind == 6);
  assert(Node_childCount(__this) <= 2);
  assert(__this->firstChild->nextSibling == NULL || isExpression(__this->firstChild->nextSibling));

  return __this->firstChild->nextSibling;
}

static struct Node *Node_expressionValue(struct Node *__this) {
  assert(__this->kind == 14);
  assert(Node_childCount(__this) == 1);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_binaryLeft(struct Node *__this) {
  assert(isBinary(__this->kind));
  assert(Node_childCount(__this) == 2);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_binaryRight(struct Node *__this) {
  assert(isBinary(__this->kind));
  assert(Node_childCount(__this) == 2);
  assert(isExpression(__this->lastChild));

  return __this->lastChild;
}

static struct Node *Node_unaryValue(struct Node *__this) {
  assert(isUnary(__this->kind));
  assert(Node_childCount(__this) == 1);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_whileValue(struct Node *__this) {
  assert(__this->kind == 20);
  assert(Node_childCount(__this) == 2);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_whileBody(struct Node *__this) {
  assert(__this->kind == 20);
  assert(Node_childCount(__this) == 2);
  assert(__this->lastChild->kind == 7);

  return __this->lastChild;
}

static struct Node *Node_hookValue(struct Node *__this) {
  assert(__this->kind == 26);
  assert(Node_childCount(__this) == 3);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_hookTrue(struct Node *__this) {
  assert(__this->kind == 26);
  assert(Node_childCount(__this) == 3);
  assert(isExpression(__this->firstChild->nextSibling));

  return __this->firstChild->nextSibling;
}

static struct Node *Node_hookFalse(struct Node *__this) {
  assert(__this->kind == 26);
  assert(Node_childCount(__this) == 3);
  assert(isExpression(__this->lastChild));

  return __this->lastChild;
}

static struct Node *Node_indexTarget(struct Node *__this) {
  assert(__this->kind == 27);
  assert(Node_childCount(__this) >= 1);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_ifValue(struct Node *__this) {
  assert(__this->kind == 16);
  assert(Node_childCount(__this) == 2 || Node_childCount(__this) == 3);
  assert(isExpression(__this->firstChild));

  return __this->firstChild;
}

static struct Node *Node_ifTrue(struct Node *__this) {
  assert(__this->kind == 16);
  assert(Node_childCount(__this) == 2 || Node_childCount(__this) == 3);
  assert(__this->firstChild->nextSibling->kind == 7);

  return __this->firstChild->nextSibling;
}

static struct Node *Node_ifFalse(struct Node *__this) {
  assert(__this->kind == 16);
  assert(Node_childCount(__this) == 2 || Node_childCount(__this) == 3);
  assert(__this->firstChild->nextSibling->nextSibling == NULL || __this->firstChild->nextSibling->nextSibling->kind == 7);

  return __this->firstChild->nextSibling->nextSibling;
}

static uint8_t Node_expandCallIntoOperatorTree(struct Node *__this) {
  if (__this->kind != 23) {
    return 0;
  }

  struct Node *value = Node_callValue(__this);
  struct Symbol *symbol = value->symbol;

  if (value->kind == 25 && Node_isOperator(symbol->node) && Node_isDeclare(symbol->node)) {
    int32_t binaryKind = 31;

    if (string_op_equals(symbol->name, (const uint16_t *)__string_562)) {
      binaryKind = 64;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_563)) {
      binaryKind = 50;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_564)) {
      binaryKind = 62;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_565)) {
      binaryKind = 55;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_566)) {
      binaryKind = 53;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_567)) {
      binaryKind = 58;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_568)) {
      binaryKind = 65;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_569)) {
      binaryKind = 54;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_570)) {
      binaryKind = 56;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_571)) {
      binaryKind = 66;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_572)) {
      binaryKind = 27;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_573)) {
      binaryKind = 52;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_574)) {
      binaryKind = 51;
    }

    if (binaryKind != 31) {
      __this->kind = binaryKind;
      Node_remove(value);
      Node_insertChildBefore(__this, __this->firstChild, Node_remove(Node_dotTarget(value)));

      return 1;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_575)) {
      __this->kind = 49;
      struct Node *target = createIndex(Node_remove(Node_dotTarget(Node_remove(value))));
      Node_appendChild(target, Node_remove(__this->firstChild));
      Node_insertChildBefore(__this, __this->firstChild, target);

      return 1;
    }
  }

  return 0;
}

static struct Node *createNew(struct Node *type) {
  assert(isExpression(type));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 30;
  Node_appendChild(node, type);

  return node;
}

static struct Node *createHook(struct Node *test, struct Node *primary, struct Node *secondary) {
  assert(isExpression(test));
  assert(isExpression(primary));
  assert(isExpression(secondary));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 26;
  Node_appendChild(node, test);
  Node_appendChild(node, primary);
  Node_appendChild(node, secondary);

  return node;
}

static struct Node *createIndex(struct Node *target) {
  assert(isExpression(target));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 27;
  Node_appendChild(node, target);

  return node;
}

static struct Node *createNull() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 31;

  return node;
}

static struct Node *createThis() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 35;

  return node;
}

static struct Node *createAddressOf(struct Node *value) {
  assert(isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 37;
  Node_appendChild(node, value);

  return node;
}

static struct Node *createDereference(struct Node *value) {
  assert(isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 39;
  Node_appendChild(node, value);

  return node;
}

static struct Node *createAlignOf(struct Node *type) {
  assert(isExpression(type));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 21;
  Node_appendChild(node, type);

  return node;
}

static struct Node *createSizeOf(struct Node *type) {
  assert(isExpression(type));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 33;
  Node_appendChild(node, type);

  return node;
}

static struct Node *createBool(uint8_t value) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 22;
  node->intValue = value ? 1 : 0;

  return node;
}

static struct Node *createInt(int32_t value) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 28;
  node->intValue = value;

  return node;
}

static struct Node *createString(const uint16_t *value) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 34;
  node->stringValue = value;

  return node;
}

static struct Node *createName(const uint16_t *value) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 29;
  node->stringValue = value;

  return node;
}

static struct Node *createType(struct Type *type) {
  assert(type != NULL);
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 36;
  node->resolvedType = type;

  return node;
}

static struct Node *createEmpty() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 12;

  return node;
}

static struct Node *createExpression(struct Node *value) {
  assert(isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 14;
  Node_appendChild(node, value);

  return node;
}

static struct Node *createBlock() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 7;

  return node;
}

static struct Node *createClass(const uint16_t *name) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 9;
  node->stringValue = name;

  return node;
}

static struct Node *createEnum(const uint16_t *name) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 13;
  node->stringValue = name;

  return node;
}

static struct Node *createIf(struct Node *value, struct Node *trueBranch, struct Node *falseBranch) {
  assert(isExpression(value));
  assert(trueBranch->kind == 7);
  assert(falseBranch == NULL || falseBranch->kind == 7);
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 16;
  Node_appendChild(node, value);
  Node_appendChild(node, trueBranch);

  if (falseBranch != NULL) {
    Node_appendChild(node, falseBranch);
  }

  return node;
}

static struct Node *createWhile(struct Node *value, struct Node *body) {
  assert(isExpression(value));
  assert(body->kind == 7);
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 20;
  Node_appendChild(node, value);
  Node_appendChild(node, body);

  return node;
}

static struct Node *createReturn(struct Node *value) {
  assert(value == NULL || isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 17;

  if (value != NULL) {
    Node_appendChild(node, value);
  }

  return node;
}

static struct Node *createVariables() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 19;

  return node;
}

static struct Node *createConstants() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 10;

  return node;
}

static struct Node *createParameters() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 5;

  return node;
}

static struct Node *createExtends(struct Node *type) {
  assert(isExpression(type));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 0;
  Node_appendChild(node, type);

  return node;
}

static struct Node *createImplements() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 3;

  return node;
}

static struct Node *createParameter(const uint16_t *name) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 4;
  node->stringValue = name;

  return node;
}

static struct Node *createVariable(const uint16_t *name, struct Node *type, struct Node *value) {
  assert(type == NULL || isExpression(type));
  assert(value == NULL || isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 6;
  node->stringValue = name;
  Node_appendChild(node, type != NULL ? type : createEmpty());

  if (value != NULL) {
    Node_appendChild(node, value);
  }

  return node;
}

static struct Node *createFunction(const uint16_t *name) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 15;
  node->stringValue = name;

  return node;
}

static struct Node *createUnary(int32_t kind, struct Node *value) {
  assert(isUnary(kind));
  assert(isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = kind;
  Node_appendChild(node, value);

  return node;
}

static struct Node *createBinary(int32_t kind, struct Node *left, struct Node *right) {
  assert(isBinary(kind));
  assert(isExpression(left));
  assert(isExpression(right));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = kind;
  Node_appendChild(node, left);
  Node_appendChild(node, right);

  return node;
}

static struct Node *createCall(struct Node *value) {
  assert(isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 23;
  Node_appendChild(node, value);

  return node;
}

static struct Node *createCast(struct Node *value, struct Node *type) {
  assert(isExpression(value));
  assert(isExpression(type));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 24;
  Node_appendChild(node, value);
  Node_appendChild(node, type);

  return node;
}

static struct Node *createDot(struct Node *value, const uint16_t *name) {
  assert(isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 25;
  node->stringValue = name;
  Node_appendChild(node, value);

  return node;
}

static struct Node *createSymbolReference(struct Symbol *symbol) {
  struct Node *node = createName(symbol->name);
  node->symbol = symbol;
  node->resolvedType = symbol->resolvedType;

  return node;
}

static struct Node *createMemberReference(struct Node *value, struct Symbol *symbol) {
  struct Node *node = createDot(value, symbol->name);
  node->symbol = symbol;
  node->resolvedType = symbol->resolvedType;

  return node;
}

static struct Node *createParseError() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 32;

  return node;
}

static uint8_t isRightAssociative(int32_t precedence) {
  return precedence == 1 || precedence == 12;
}

static uint8_t ParserContext_peek(struct ParserContext *__this, int32_t kind) {
  return __this->current->kind == kind;
}

static uint8_t ParserContext_eat(struct ParserContext *__this, int32_t kind) {
  if (ParserContext_peek(__this, kind)) {
    ParserContext_advance(__this);

    return 1;
  }

  return 0;
}

static void ParserContext_advance(struct ParserContext *__this) {
  if (!ParserContext_peek(__this, 0)) {
    __this->previous = __this->current;
    __this->current = __this->current->next;
  }
}

static void ParserContext_unexpectedToken(struct ParserContext *__this) {
  if (__this->lastError != __this->current) {
    __this->lastError = __this->current;
    Log_error(__this->log, __this->current->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_576_Unexpected), tokenToString(__this->current->kind))));
  }
}

static uint8_t ParserContext_expect(struct ParserContext *__this, int32_t kind) {
  if (!ParserContext_peek(__this, kind)) {
    if (__this->lastError != __this->current) {
      __this->lastError = __this->current;
      struct Range *previousLine = Range_enclosingLine(__this->previous->range);
      struct Range *currentLine = Range_enclosingLine(__this->current->range);

      if (kind != 2 && !Range_equals(previousLine, currentLine)) {
        Log_error(__this->log, Range_rangeAtEnd(previousLine), StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_577_Expected), tokenToString(kind))));
      }

      else {
        Log_error(__this->log, __this->current->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_578_Expected), tokenToString(kind)), (const uint16_t *)__string_579_but_found), tokenToString(__this->current->kind))));
      }
    }

    return 0;
  }

  ParserContext_advance(__this);

  return 1;
}

static struct Node *ParserContext_parseUnaryPrefix(struct ParserContext *__this, int32_t kind, int32_t mode) {
  assert(isUnary(kind));
  struct Token *token = __this->current;
  ParserContext_advance(__this);
  struct Node *value = ParserContext_parseExpression(__this, 13, mode);

  if (value == NULL) {
    return NULL;
  }

  return Node_withInternalRange(Node_withRange(createUnary(kind, value), spanRanges(token->range, value->range)), token->range);
}

static struct Node *ParserContext_parseBinary(struct ParserContext *__this, int32_t kind, struct Node *left, int32_t localPrecedence, int32_t operatorPrecedence) {
  if (localPrecedence >= operatorPrecedence) {
    return left;
  }

  struct Token *token = __this->current;
  ParserContext_advance(__this);
  int32_t precedence = isRightAssociative(operatorPrecedence) ? (int32_t)((int32_t)operatorPrecedence - 1) : operatorPrecedence;
  struct Node *right = ParserContext_parseExpression(__this, precedence, 0);

  if (right == NULL) {
    return NULL;
  }

  return Node_withInternalRange(Node_withRange(createBinary(kind, left, right), spanRanges(left->range, right->range)), token->range);
}

static struct Node *ParserContext_parseUnaryPostfix(struct ParserContext *__this, int32_t kind, struct Node *value, int32_t localPrecedence) {
  if (localPrecedence >= 14) {
    return value;
  }

  struct Token *token = __this->current;
  ParserContext_advance(__this);

  return Node_withInternalRange(Node_withRange(createUnary(kind, value), spanRanges(value->range, token->range)), token->range);
}

static const uint16_t *ParserContext_parseQuotedString(struct ParserContext *__this, struct Range *range) {
  assert(range->end - range->start >= 2);
  const uint16_t *text = range->source->contents;
  int32_t end = range->start + 1;
  int32_t limit = range->end - 1;
  int32_t start = end;
  struct StringBuilder *builder = StringBuilder_new();

  while (end < limit) {
    uint16_t c = string_op_get(text, end);

    if (c == 92) {
      StringBuilder_appendSlice(builder, text, start, end);
      end = end + 1;
      start = end + 1;
      c = string_op_get(text, end);

      if (c == 48) {
        StringBuilder_appendChar(builder, 0);
      }

      else if (c == 116) {
        StringBuilder_appendChar(builder, 9);
      }

      else if (c == 110) {
        StringBuilder_appendChar(builder, 10);
      }

      else if (c == 114) {
        StringBuilder_appendChar(builder, 13);
      }

      else if (c == 34 || c == 39 || c == 96 || c == 10 || c == 92) {
        start = end;
      }

      else {
        struct Range *escape = createRange(range->source, range->start + end - 1, range->start + end + 1);
        Log_error(__this->log, escape, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_580_Invalid_escape_code), Range_toString(escape)), 39)));

        return NULL;
      }
    }

    end = end + 1;
  }

  return StringBuilder_finish(StringBuilder_appendSlice(builder, text, start, end));
}

static struct Node *ParserContext_parsePrefix(struct ParserContext *__this, int32_t mode) {
  struct Token *token = __this->current;

  if (ParserContext_peek(__this, 2)) {
    ParserContext_advance(__this);

    return Node_withRange(createName(Range_toString(token->range)), token->range);
  }

  if (ParserContext_peek(__this, 15)) {
    splitToken(__this->current, 27, 27);
  }

  if (ParserContext_peek(__this, 27)) {
    return ParserContext_parseUnaryPrefix(__this, mode == 1 ? 42 : 39, mode);
  }

  if (mode == 0) {
    if (ParserContext_eat(__this, 60)) {
      return Node_withRange(createNull(), token->range);
    }

    if (ParserContext_eat(__this, 68)) {
      return Node_withRange(createThis(), token->range);
    }

    if (ParserContext_peek(__this, 1)) {
      const uint16_t *text = ParserContext_parseQuotedString(__this, token->range);

      if (string_op_equals(text, NULL)) {
        return NULL;
      }

      ParserContext_advance(__this);

      if (string_length(text) != 1) {
        Log_error(__this->log, token->range, (const uint16_t *)__string_581_Invalid_character_literal_strin);

        return Node_withRange(createParseError(), token->range);
      }

      return Node_withRange(createInt(string_op_get(text, 0)), token->range);
    }

    if (ParserContext_peek(__this, 4)) {
      const uint16_t *text = ParserContext_parseQuotedString(__this, token->range);

      if (string_op_equals(text, NULL)) {
        return NULL;
      }

      ParserContext_advance(__this);

      return Node_withRange(createString(text), token->range);
    }

    if (ParserContext_peek(__this, 3)) {
      struct Node *value = createInt(0);

      if (!ParserContext_parseInt(__this, token->range, value)) {
        value = createParseError();
      }

      ParserContext_advance(__this);

      return Node_withRange(value, token->range);
    }

    if (ParserContext_eat(__this, 69)) {
      return Node_withRange(createBool(1), token->range);
    }

    if (ParserContext_eat(__this, 52)) {
      return Node_withRange(createBool(0), token->range);
    }

    if (ParserContext_eat(__this, 59)) {
      struct Node *type = ParserContext_parseType(__this);

      if (type == NULL) {
        return NULL;
      }

      return ParserContext_parseArgumentList(__this, token->range, createNew(type));
    }

    if (ParserContext_eat(__this, 40)) {
      if (!ParserContext_expect(__this, 20)) {
        return NULL;
      }

      struct Node *type = ParserContext_parseType(__this);
      struct Token *close = __this->current;

      if (type == NULL || !ParserContext_expect(__this, 36)) {
        return NULL;
      }

      return Node_withRange(createAlignOf(type), spanRanges(token->range, close->range));
    }

    if (ParserContext_eat(__this, 66)) {
      if (!ParserContext_expect(__this, 20)) {
        return NULL;
      }

      struct Node *type = ParserContext_parseType(__this);
      struct Token *close = __this->current;

      if (type == NULL || !ParserContext_expect(__this, 36)) {
        return NULL;
      }

      return Node_withRange(createSizeOf(type), spanRanges(token->range, close->range));
    }

    if (ParserContext_eat(__this, 20)) {
      struct Node *value = ParserContext_parseExpression(__this, 0, 0);
      struct Token *close = __this->current;

      if (value == NULL || !ParserContext_expect(__this, 36)) {
        return NULL;
      }

      return Node_withRange(value, spanRanges(token->range, close->range));
    }

    if (ParserContext_peek(__this, 6)) {
      return ParserContext_parseUnaryPrefix(__this, 37, 0);
    }

    if (ParserContext_peek(__this, 11)) {
      return ParserContext_parseUnaryPrefix(__this, 38, 0);
    }

    if (ParserContext_peek(__this, 25)) {
      return ParserContext_parseUnaryPrefix(__this, 40, 0);
    }

    if (ParserContext_peek(__this, 26)) {
      return ParserContext_parseUnaryPrefix(__this, 46, 0);
    }

    if (ParserContext_peek(__this, 28)) {
      return ParserContext_parseUnaryPrefix(__this, 41, 0);
    }

    if (ParserContext_peek(__this, 30)) {
      return ParserContext_parseUnaryPrefix(__this, 43, 0);
    }

    if (ParserContext_peek(__this, 31)) {
      return ParserContext_parseUnaryPrefix(__this, 47, 0);
    }
  }

  ParserContext_unexpectedToken(__this);

  return NULL;
}

static struct Node *ParserContext_parseInfix(struct ParserContext *__this, int32_t precedence, struct Node *node, int32_t mode) {
  struct Range *token = __this->current->range;

  if (ParserContext_peek(__this, 13) && precedence < 15) {
    ParserContext_advance(__this);
    struct Token *name = __this->current;
    struct Range *range = name->range;

    if (isKeyword(name->kind)) {
      ParserContext_advance(__this);
    }

    else if (!ParserContext_expect(__this, 2)) {
      range = createRange(range->source, token->end, token->end);
    }

    return Node_withInternalRange(Node_withRange(createDot(node, Range_toString(range)), spanRanges(node->range, range)), range);
  }

  if (mode == 0) {
    if (ParserContext_peek(__this, 5)) {
      return ParserContext_parseBinary(__this, 49, node, precedence, 1);
    }

    if (ParserContext_peek(__this, 6)) {
      return ParserContext_parseBinary(__this, 50, node, precedence, 6);
    }

    if (ParserContext_peek(__this, 7)) {
      return ParserContext_parseBinary(__this, 51, node, precedence, 4);
    }

    if (ParserContext_peek(__this, 8)) {
      return ParserContext_parseBinary(__this, 52, node, precedence, 5);
    }

    if (ParserContext_peek(__this, 12)) {
      return ParserContext_parseBinary(__this, 53, node, precedence, 11);
    }

    if (ParserContext_peek(__this, 14)) {
      return ParserContext_parseBinary(__this, 54, node, precedence, 7);
    }

    if (ParserContext_peek(__this, 15)) {
      return ParserContext_parseBinary(__this, 55, node, precedence, 12);
    }

    if (ParserContext_peek(__this, 16)) {
      return ParserContext_parseBinary(__this, 56, node, precedence, 8);
    }

    if (ParserContext_peek(__this, 17)) {
      return ParserContext_parseBinary(__this, 57, node, precedence, 8);
    }

    if (ParserContext_peek(__this, 21)) {
      return ParserContext_parseBinary(__this, 58, node, precedence, 8);
    }

    if (ParserContext_peek(__this, 22)) {
      return ParserContext_parseBinary(__this, 59, node, precedence, 8);
    }

    if (ParserContext_peek(__this, 23)) {
      return ParserContext_parseBinary(__this, 60, node, precedence, 3);
    }

    if (ParserContext_peek(__this, 24)) {
      return ParserContext_parseBinary(__this, 61, node, precedence, 2);
    }

    if (ParserContext_peek(__this, 25)) {
      return ParserContext_parseBinary(__this, 67, node, precedence, 10);
    }

    if (ParserContext_peek(__this, 27)) {
      return ParserContext_parseBinary(__this, 62, node, precedence, 11);
    }

    if (ParserContext_peek(__this, 29)) {
      return ParserContext_parseBinary(__this, 63, node, precedence, 7);
    }

    if (ParserContext_peek(__this, 30)) {
      return ParserContext_parseBinary(__this, 48, node, precedence, 10);
    }

    if (ParserContext_peek(__this, 33)) {
      return ParserContext_parseBinary(__this, 64, node, precedence, 11);
    }

    if (ParserContext_peek(__this, 38)) {
      return ParserContext_parseBinary(__this, 65, node, precedence, 9);
    }

    if (ParserContext_peek(__this, 39)) {
      return ParserContext_parseBinary(__this, 66, node, precedence, 9);
    }

    if (ParserContext_peek(__this, 31)) {
      return ParserContext_parseUnaryPostfix(__this, 45, node, precedence);
    }

    if (ParserContext_peek(__this, 26)) {
      return ParserContext_parseUnaryPostfix(__this, 44, node, precedence);
    }

    if (ParserContext_peek(__this, 41) && precedence < 13) {
      ParserContext_advance(__this);
      struct Node *type = ParserContext_parseType(__this);

      if (type == NULL) {
        return NULL;
      }

      return Node_withInternalRange(Node_withRange(createCast(node, type), spanRanges(node->range, type->range)), token);
    }

    uint8_t isIndex = ParserContext_peek(__this, 19);

    if ((isIndex || ParserContext_peek(__this, 20)) && precedence < 14) {
      return ParserContext_parseArgumentList(__this, node->range, isIndex ? createIndex(node) : createCall(node));
    }

    if (ParserContext_peek(__this, 32) && precedence < 1) {
      ParserContext_advance(__this);
      struct Node *middle = ParserContext_parseExpression(__this, 0, 0);

      if (middle == NULL || !ParserContext_expect(__this, 9)) {
        return NULL;
      }

      struct Node *right = ParserContext_parseExpression(__this, 0, 0);

      if (right == NULL) {
        return NULL;
      }

      return Node_withRange(createHook(node, middle, right), spanRanges(node->range, right->range));
    }
  }

  return node;
}

static struct Node *ParserContext_parseArgumentList(struct ParserContext *__this, struct Range *start, struct Node *node) {
  struct Range *open = __this->current->range;
  uint8_t isIndex = node->kind == 27;
  int32_t left = isIndex ? 19 : 20;
  int32_t right = isIndex ? 35 : 36;

  if (!ParserContext_expect(__this, left)) {
    return NULL;
  }

  if (!ParserContext_peek(__this, right)) {
    while (1) {
      struct Node *value = ParserContext_parseExpression(__this, 0, 0);

      if (value == NULL) {
        return NULL;
      }

      Node_appendChild(node, value);

      if (!ParserContext_eat(__this, 10)) {
        break;
      }
    }
  }

  struct Range *close = __this->current->range;

  if (!ParserContext_expect(__this, right)) {
    return NULL;
  }

  return Node_withInternalRange(Node_withRange(node, spanRanges(start, close)), spanRanges(open, close));
}

static struct Node *ParserContext_parseExpression(struct ParserContext *__this, int32_t precedence, int32_t mode) {
  struct Node *node = ParserContext_parsePrefix(__this, mode);

  if (node == NULL) {
    return NULL;
  }

  assert(node->range != NULL);

  while (1) {
    struct Node *result = ParserContext_parseInfix(__this, precedence, node, mode);

    if (result == NULL) {
      return NULL;
    }

    if (result == node) {
      break;
    }

    node = result;
    assert(node->range != NULL);
  }

  return node;
}

static struct Node *ParserContext_parseType(struct ParserContext *__this) {
  return ParserContext_parseExpression(__this, 14, 1);
}

static struct Node *ParserContext_parseIf(struct ParserContext *__this) {
  struct Token *token = __this->current;
  assert(token->kind == 54);
  ParserContext_advance(__this);

  if (!ParserContext_expect(__this, 20)) {
    return NULL;
  }

  struct Node *value = NULL;

  if (ParserContext_peek(__this, 36)) {
    ParserContext_unexpectedToken(__this);
    ParserContext_advance(__this);
    value = createParseError();
  }

  else {
    value = ParserContext_parseExpression(__this, 0, 0);

    if (value == NULL || !ParserContext_expect(__this, 36)) {
      return NULL;
    }
  }

  struct Node *trueBranch = ParserContext_parseBody(__this);

  if (trueBranch == NULL) {
    return NULL;
  }

  struct Node *falseBranch = NULL;

  if (ParserContext_eat(__this, 47)) {
    falseBranch = ParserContext_parseBody(__this);

    if (falseBranch == NULL) {
      return NULL;
    }
  }

  return Node_withRange(createIf(value, trueBranch, falseBranch), spanRanges(token->range, (falseBranch != NULL ? falseBranch : trueBranch)->range));
}

static struct Node *ParserContext_parseWhile(struct ParserContext *__this) {
  struct Token *token = __this->current;
  assert(token->kind == 72);
  ParserContext_advance(__this);

  if (!ParserContext_expect(__this, 20)) {
    return NULL;
  }

  struct Node *value = NULL;

  if (ParserContext_peek(__this, 36)) {
    ParserContext_unexpectedToken(__this);
    ParserContext_advance(__this);
    value = createParseError();
  }

  else {
    value = ParserContext_parseExpression(__this, 0, 0);

    if (value == NULL || !ParserContext_expect(__this, 36)) {
      return NULL;
    }
  }

  struct Node *body = ParserContext_parseBody(__this);

  if (body == NULL) {
    return NULL;
  }

  return Node_withRange(createWhile(value, body), spanRanges(token->range, body->range));
}

static struct Node *ParserContext_parseBody(struct ParserContext *__this) {
  struct Node *node = ParserContext_parseStatement(__this, 0);

  if (node == NULL) {
    return NULL;
  }

  if (node->kind == 7) {
    return node;
  }

  struct Node *block = createBlock();
  Node_appendChild(block, node);

  return Node_withRange(block, node->range);
}

static struct Node *ParserContext_parseBlock(struct ParserContext *__this) {
  struct Token *open = __this->current;

  if (!ParserContext_expect(__this, 18)) {
    return NULL;
  }

  struct Node *block = createBlock();

  if (!ParserContext_parseStatements(__this, block)) {
    return NULL;
  }

  struct Token *close = __this->current;

  if (!ParserContext_expect(__this, 34)) {
    return NULL;
  }

  return Node_withRange(block, spanRanges(open->range, close->range));
}

static struct Node *ParserContext_parseReturn(struct ParserContext *__this) {
  struct Token *token = __this->current;
  assert(token->kind == 65);
  ParserContext_advance(__this);
  struct Node *value = NULL;

  if (!ParserContext_peek(__this, 37)) {
    value = ParserContext_parseExpression(__this, 0, 0);

    if (value == NULL) {
      return NULL;
    }
  }

  struct Token *semicolon = __this->current;
  ParserContext_expect(__this, 37);

  return Node_withRange(createReturn(value), spanRanges(token->range, semicolon->range));
}

static struct Node *ParserContext_parseEmpty(struct ParserContext *__this) {
  struct Token *token = __this->current;
  ParserContext_advance(__this);

  return Node_withRange(createEmpty(), token->range);
}

static struct Node *ParserContext_parseEnum(struct ParserContext *__this, struct NodeFlag *firstFlag) {
  struct Token *token = __this->current;
  assert(token->kind == 48);
  ParserContext_advance(__this);
  struct Token *name = __this->current;

  if (!ParserContext_expect(__this, 2) || !ParserContext_expect(__this, 18)) {
    return NULL;
  }

  const uint16_t *text = Range_toString(name->range);
  struct Node *node = createEnum(text);
  node->firstFlag = firstFlag;
  node->flags = allFlags(firstFlag);

  while (!ParserContext_peek(__this, 0) && !ParserContext_peek(__this, 34)) {
    struct Range *member = __this->current->range;
    struct Node *value = NULL;

    if (!ParserContext_expect(__this, 2)) {
      return NULL;
    }

    if (ParserContext_eat(__this, 5)) {
      value = ParserContext_parseExpression(__this, 0, 0);

      if (value == NULL) {
        return NULL;
      }
    }

    struct Node *variable = createVariable(Range_toString(member), createName(text), value);
    Node_appendChild(node, Node_withInternalRange(Node_withRange(variable, value != NULL ? spanRanges(member, value->range) : member), member));

    if (ParserContext_peek(__this, 37)) {
      ParserContext_expect(__this, 10);
      ParserContext_advance(__this);
    }

    else if (ParserContext_peek(__this, 2)) {
      ParserContext_expect(__this, 10);
    }

    else if (!ParserContext_eat(__this, 10)) {
      break;
    }
  }

  struct Token *close = __this->current;

  if (!ParserContext_expect(__this, 34)) {
    return NULL;
  }

  return Node_withInternalRange(Node_withRange(node, spanRanges(token->range, close->range)), name->range);
}

static struct Node *ParserContext_parseParameters(struct ParserContext *__this) {
  struct Node *node = createParameters();
  struct Token *open = __this->current;
  struct Token *close = NULL;
  assert(open->kind == 21);
  ParserContext_advance(__this);

  while (1) {
    struct Token *name = __this->current;

    if (!ParserContext_expect(__this, 2)) {
      close = __this->current;

      if (ParserContext_eat(__this, 16)) {
        break;
      }

      return NULL;
    }

    Node_appendChild(node, Node_withRange(createParameter(Range_toString(name->range)), name->range));

    if (!ParserContext_eat(__this, 10)) {
      close = __this->current;

      if (!ParserContext_expect(__this, 16)) {
        return NULL;
      }

      break;
    }
  }

  return Node_withRange(node, spanRanges(open->range, close->range));
}

static struct Node *ParserContext_parseClass(struct ParserContext *__this, struct NodeFlag *firstFlag) {
  struct Token *token = __this->current;
  assert(token->kind == 43);
  ParserContext_advance(__this);
  struct Token *name = __this->current;

  if (!ParserContext_expect(__this, 2)) {
    return NULL;
  }

  struct Node *node = createClass(Range_toString(name->range));
  node->firstFlag = firstFlag;
  node->flags = allFlags(firstFlag);

  if (ParserContext_peek(__this, 21)) {
    struct Node *parameters = ParserContext_parseParameters(__this);

    if (parameters == NULL) {
      return NULL;
    }

    Node_appendChild(node, parameters);
  }

  struct Token *extendsToken = __this->current;

  if (ParserContext_eat(__this, 50)) {
    struct Node *type = NULL;

    if (ParserContext_peek(__this, 18) || ParserContext_peek(__this, 55)) {
      ParserContext_unexpectedToken(__this);
      type = createParseError();
    }

    else {
      type = ParserContext_parseType(__this);

      if (type == NULL) {
        return NULL;
      }
    }

    Node_appendChild(node, Node_withRange(createExtends(type), type->range != NULL ? spanRanges(extendsToken->range, type->range) : extendsToken->range));
  }

  struct Token *implementsToken = __this->current;

  if (ParserContext_eat(__this, 55)) {
    struct Node *list = createImplements();
    struct Node *type = NULL;

    while (1) {
      if (ParserContext_peek(__this, 18)) {
        ParserContext_unexpectedToken(__this);

        break;
      }

      type = ParserContext_parseType(__this);

      if (type == NULL) {
        return NULL;
      }

      Node_appendChild(list, type);

      if (!ParserContext_eat(__this, 10)) {
        break;
      }
    }

    Node_appendChild(node, Node_withRange(list, type != NULL ? spanRanges(implementsToken->range, type->range) : implementsToken->range));
  }

  if (!ParserContext_expect(__this, 18)) {
    return NULL;
  }

  while (!ParserContext_peek(__this, 0) && !ParserContext_peek(__this, 34)) {
    struct NodeFlag *childFlags = ParserContext_parseFlags(__this);
    struct Token *childName = __this->current;
    int32_t oldKind = childName->kind;

    if (isKeyword(childName->kind)) {
      childName->kind = 2;
      ParserContext_advance(__this);
    }

    if (!ParserContext_expect(__this, 2)) {
      return NULL;
    }

    const uint16_t *text = Range_toString(childName->range);

    if (string_op_equals(text, (const uint16_t *)__string_582_operator) && !ParserContext_peek(__this, 20) && !ParserContext_peek(__this, 2)) {
      childName->kind = 61;
      __this->current = childName;

      if (ParserContext_parseFunction(__this, childFlags, node) == NULL) {
        return NULL;
      }

      continue;
    }

    else if (ParserContext_peek(__this, 2)) {
      uint8_t isGet = string_op_equals(text, (const uint16_t *)__string_583_get);
      uint8_t isSet = string_op_equals(text, (const uint16_t *)__string_584_set);

      if (isGet || isSet) {
        childFlags = appendFlag(childFlags, isGet ? 8 : 512, childName->range);
        childName = __this->current;
        ParserContext_advance(__this);
      }

      else if (oldKind == 53) {
        Log_error(__this->log, childName->range, (const uint16_t *)__string_585_Instance_functions_don_t_need_th);
        childName = __this->current;
        ParserContext_advance(__this);
      }

      else if (oldKind == 44 || oldKind == 58 || oldKind == 71) {
        Log_error(__this->log, childName->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_586_Instance_variables_don_t_need_th), Range_toString(childName->range)), (const uint16_t *)__string_587_keyword)));
        childName = __this->current;
        ParserContext_advance(__this);
      }
    }

    if (ParserContext_peek(__this, 20) || ParserContext_peek(__this, 21)) {
      __this->current = childName;

      if (ParserContext_parseFunction(__this, childFlags, node) == NULL) {
        return NULL;
      }
    }

    else {
      __this->current = childName;

      if (ParserContext_parseVariables(__this, childFlags, node) == NULL) {
        return NULL;
      }
    }
  }

  struct Token *close = __this->current;

  if (!ParserContext_expect(__this, 34)) {
    return NULL;
  }

  return Node_withInternalRange(Node_withRange(node, spanRanges(token->range, close->range)), name->range);
}

static struct Node *ParserContext_parseFunction(struct ParserContext *__this, struct NodeFlag *firstFlag, struct Node *parent) {
  uint8_t isOperator = 0;
  struct Token *token = __this->current;
  struct Range *nameRange = NULL;
  const uint16_t *name = NULL;

  if (parent != NULL && ParserContext_eat(__this, 61)) {
    struct Token *end = __this->current;

    if (ParserContext_eat(__this, 19)) {
      if (!ParserContext_expect(__this, 35)) {
        return NULL;
      }

      if (ParserContext_peek(__this, 5)) {
        nameRange = spanRanges(token->range, __this->current->range);
        name = (const uint16_t *)__string_588;
        ParserContext_advance(__this);
      }

      else {
        nameRange = spanRanges(token->range, end->range);
        name = (const uint16_t *)__string_589;
      }

      isOperator = 1;
    }

    else if (ParserContext_eat(__this, 6) || ParserContext_eat(__this, 7) || ParserContext_eat(__this, 8) || ParserContext_eat(__this, 11) || ParserContext_eat(__this, 12) || ParserContext_eat(__this, 14) || ParserContext_eat(__this, 15) || ParserContext_eat(__this, 21) || ParserContext_eat(__this, 16) || ParserContext_eat(__this, 25) || ParserContext_eat(__this, 26) || ParserContext_eat(__this, 27) || ParserContext_eat(__this, 30) || ParserContext_eat(__this, 31) || ParserContext_eat(__this, 33) || ParserContext_eat(__this, 38) || ParserContext_eat(__this, 39)) {
      nameRange = end->range;
      name = Range_toString(nameRange);
      isOperator = 1;
    }

    else if (ParserContext_eat(__this, 5) || ParserContext_eat(__this, 17) || ParserContext_eat(__this, 22) || ParserContext_eat(__this, 23) || ParserContext_eat(__this, 24) || ParserContext_eat(__this, 28) || ParserContext_eat(__this, 29)) {
      nameRange = end->range;
      name = Range_toString(nameRange);
      Log_error(__this->log, nameRange, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_590_The_operator), name), (const uint16_t *)__string_591_cannot_be_implemented), end->kind == 29 ? (const uint16_t *)__string_592_it_is_automatically_derived_fr : end->kind == 22 ? (const uint16_t *)__string_593_it_is_automatically_derived_fr : end->kind == 17 ? (const uint16_t *)__string_594_it_is_automatically_derived_fr : (const uint16_t *)__string_595)));
    }

    else {
      ParserContext_unexpectedToken(__this);
    }
  }

  else {
    if (parent == NULL) {
      assert(token->kind == 53);
      ParserContext_advance(__this);
    }

    nameRange = __this->current->range;

    if (!ParserContext_expect(__this, 2)) {
      return NULL;
    }

    name = Range_toString(nameRange);
  }

  struct Node *node = createFunction(name);
  node->firstFlag = firstFlag;
  node->flags = allFlags(firstFlag);

  if (isOperator) {
    node->flags = node->flags | 16;
  }

  if (ParserContext_peek(__this, 21)) {
    struct Node *parameters = ParserContext_parseParameters(__this);

    if (parameters == NULL) {
      return NULL;
    }

    Node_appendChild(node, parameters);
  }

  if (!ParserContext_expect(__this, 20)) {
    return NULL;
  }

  if (!ParserContext_peek(__this, 36)) {
    while (1) {
      struct NodeFlag *firstArgumentFlag = ParserContext_parseFlags(__this);
      struct Token *argument = __this->current;

      if (!ParserContext_expect(__this, 2)) {
        return NULL;
      }

      struct Node *type = NULL;
      struct Range *range = argument->range;

      if (ParserContext_expect(__this, 9)) {
        type = ParserContext_parseType(__this);

        if (type != NULL) {
          range = spanRanges(range, type->range);
        }

        else if (ParserContext_peek(__this, 10) || ParserContext_peek(__this, 36)) {
          type = createParseError();
        }

        else {
          return NULL;
        }
      }

      else if (ParserContext_peek(__this, 10) || ParserContext_peek(__this, 36)) {
        type = createParseError();
      }

      struct Node *variable = createVariable(Range_toString(argument->range), type, NULL);
      variable->firstFlag = firstArgumentFlag;
      variable->flags = allFlags(firstArgumentFlag);
      Node_appendChild(node, Node_withInternalRange(Node_withRange(variable, range), argument->range));

      if (!ParserContext_eat(__this, 10)) {
        break;
      }
    }
  }

  if (!ParserContext_expect(__this, 36)) {
    return NULL;
  }

  struct Node *returnType = NULL;

  if (ParserContext_expect(__this, 9)) {
    returnType = ParserContext_parseType(__this);

    if (returnType == NULL) {
      if (ParserContext_peek(__this, 37) || ParserContext_peek(__this, 18)) {
        returnType = createParseError();
      }

      else {
        return NULL;
      }
    }
  }

  else if (ParserContext_peek(__this, 37) || ParserContext_peek(__this, 18)) {
    returnType = createParseError();
  }

  else {
    return NULL;
  }

  Node_appendChild(node, returnType);
  struct Node *block = NULL;
  struct Token *semicolon = __this->current;

  if (ParserContext_eat(__this, 37)) {
    block = Node_withRange(createEmpty(), semicolon->range);
  }

  else {
    block = ParserContext_parseBlock(__this);

    if (block == NULL) {
      return NULL;
    }
  }

  if (parent != NULL) {
    Node_appendChild(parent, node);
  }

  Node_appendChild(node, block);

  return Node_withInternalRange(Node_withRange(node, spanRanges(token->range, block->range)), nameRange);
}

static struct Node *ParserContext_parseVariables(struct ParserContext *__this, struct NodeFlag *firstFlag, struct Node *parent) {
  struct Token *token = __this->current;

  if (parent == NULL) {
    assert(token->kind == 44 || token->kind == 58 || token->kind == 71);
    ParserContext_advance(__this);
  }

  struct Node *node = token->kind == 44 ? createConstants() : createVariables();
  node->firstFlag = firstFlag;

  while (1) {
    struct Token *name = __this->current;

    if (!ParserContext_expect(__this, 2)) {
      return NULL;
    }

    struct Node *type = NULL;

    if (ParserContext_eat(__this, 9)) {
      type = ParserContext_parseType(__this);

      if (type == NULL) {
        return NULL;
      }
    }

    struct Node *value = NULL;

    if (ParserContext_eat(__this, 5)) {
      value = ParserContext_parseExpression(__this, 0, 0);

      if (value == NULL) {
        return NULL;
      }

      if (parent != NULL) {
        Log_error(__this->log, value->range, (const uint16_t *)__string_596_Inline_initialization_of_instanc);
      }
    }

    struct Range *range = value != NULL ? spanRanges(name->range, value->range) : type != NULL ? spanRanges(name->range, type->range) : name->range;
    struct Node *variable = createVariable(Range_toString(name->range), type, value);
    variable->firstFlag = firstFlag;
    variable->flags = allFlags(firstFlag);
    Node_appendChild(parent != NULL ? parent : node, Node_withInternalRange(Node_withRange(variable, range), name->range));

    if (!ParserContext_eat(__this, 10)) {
      break;
    }
  }

  struct Token *semicolon = __this->current;
  ParserContext_expect(__this, 37);

  return Node_withRange(node, spanRanges(token->range, semicolon->range));
}

static struct Node *ParserContext_parseLoopJump(struct ParserContext *__this, int32_t kind) {
  struct Token *token = __this->current;
  ParserContext_advance(__this);
  ParserContext_expect(__this, 37);
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = kind;

  return Node_withRange(node, token->range);
}

static struct NodeFlag *ParserContext_parseFlags(struct ParserContext *__this) {
  struct NodeFlag *firstFlag = NULL;
  struct NodeFlag *lastFlag = NULL;

  while (1) {
    struct Token *token = __this->current;
    int32_t flag = 0;

    if (ParserContext_eat(__this, 46)) {
      flag = 1;
    }

    else if (ParserContext_eat(__this, 49)) {
      flag = 2;
    }

    else if (ParserContext_eat(__this, 51)) {
      flag = 4;
    }

    else if (ParserContext_eat(__this, 62)) {
      flag = 64;
    }

    else if (ParserContext_eat(__this, 63)) {
      flag = 128;
    }

    else if (ParserContext_eat(__this, 64)) {
      flag = 256;
    }

    else if (ParserContext_eat(__this, 67)) {
      flag = 1024;
    }

    else if (ParserContext_eat(__this, 70)) {
      flag = 2048;
    }

    else {
      return firstFlag;
    }

    struct NodeFlag *link = calloc(1, sizeof(struct NodeFlag));
    link->flag = flag;
    link->range = token->range;

    if (firstFlag == NULL) {
      firstFlag = link;
    }

    else {
      lastFlag->next = link;
    }

    lastFlag = link;
  }
}

static struct Node *ParserContext_parseUnsafe(struct ParserContext *__this) {
  struct Token *token = __this->current;
  ParserContext_advance(__this);
  struct Node *node = ParserContext_parseBlock(__this);

  if (node == NULL) {
    return NULL;
  }

  node->flags = node->flags | 2048;

  return Node_withRange(node, spanRanges(token->range, node->range));
}

static struct Node *ParserContext_parseStatement(struct ParserContext *__this, int32_t mode) {
  struct NodeFlag *firstFlag = mode == 1 ? ParserContext_parseFlags(__this) : NULL;

  if (ParserContext_peek(__this, 70) && firstFlag == NULL) {
    return ParserContext_parseUnsafe(__this);
  }

  if (ParserContext_peek(__this, 44) || ParserContext_peek(__this, 58) || ParserContext_peek(__this, 71)) {
    return ParserContext_parseVariables(__this, firstFlag, NULL);
  }

  if (ParserContext_peek(__this, 53)) {
    return ParserContext_parseFunction(__this, firstFlag, NULL);
  }

  if (ParserContext_peek(__this, 43)) {
    return ParserContext_parseClass(__this, firstFlag);
  }

  if (ParserContext_peek(__this, 48)) {
    return ParserContext_parseEnum(__this, firstFlag);
  }

  if (firstFlag != NULL) {
    ParserContext_unexpectedToken(__this);

    return NULL;
  }

  if (ParserContext_peek(__this, 18)) {
    return ParserContext_parseBlock(__this);
  }

  if (ParserContext_peek(__this, 42)) {
    return ParserContext_parseLoopJump(__this, 8);
  }

  if (ParserContext_peek(__this, 45)) {
    return ParserContext_parseLoopJump(__this, 11);
  }

  if (ParserContext_peek(__this, 54)) {
    return ParserContext_parseIf(__this);
  }

  if (ParserContext_peek(__this, 72)) {
    return ParserContext_parseWhile(__this);
  }

  if (ParserContext_peek(__this, 65)) {
    return ParserContext_parseReturn(__this);
  }

  if (ParserContext_peek(__this, 37)) {
    return ParserContext_parseEmpty(__this);
  }

  struct Node *value = ParserContext_parseExpression(__this, 0, 0);

  if (value == NULL) {
    return NULL;
  }

  struct Token *semicolon = __this->current;
  ParserContext_expect(__this, 37);

  return Node_withRange(createExpression(value), spanRanges(value->range, semicolon->range));
}

static uint8_t ParserContext_parseStatements(struct ParserContext *__this, struct Node *parent) {
  while (!ParserContext_peek(__this, 0) && !ParserContext_peek(__this, 34)) {
    struct Node *child = ParserContext_parseStatement(__this, parent->kind == 1 ? 1 : 0);

    if (child == NULL) {
      return 0;
    }

    Node_appendChild(parent, child);
  }

  return 1;
}

static uint8_t ParserContext_parseInt(struct ParserContext *__this, struct Range *range, struct Node *node) {
  struct Source *source = range->source;
  const uint16_t *contents = source->contents;
  int32_t i = range->start;
  int32_t limit = range->end;
  uint32_t value = 0;
  uint32_t base = 10;

  if (string_op_get(contents, i) == 48 && i + 1 < limit) {
    uint16_t c = string_op_get(contents, i + 1);

    if (c == 98 || c == 66) {
      base = 2;
    }

    else if (c == 111 || c == 79) {
      base = 8;
    }

    else if (c == 120 || c == 88) {
      base = 16;
    }

    else {
      Log_error(__this->log, range, (const uint16_t *)__string_597_Use_the_0o_prefix_for_octal_in);

      return 0;
    }

    if (base != 10) {
      i = i + 2;
    }
  }

  while (i < limit) {
    uint16_t c = string_op_get(contents, i);
    uint32_t digit = (uint32_t)(c >= 65 && c <= 70 ? c - 55 : c >= 97 && c <= 102 ? c - 87 : c - 48);
    uint32_t baseValue = value * base;

    if (baseValue / base != value || baseValue > 4294967295 - digit) {
      Log_error(__this->log, range, (const uint16_t *)__string_598_Integer_literal_is_too_big_to_fi);

      return 0;
    }

    value = baseValue + digit;
    i = i + 1;
  }

  node->intValue = (int32_t)value;
  node->flags = 32;

  return 1;
}

static struct Node *parse(struct Token *firstToken, struct Log *log) {
  struct ParserContext *context = calloc(1, sizeof(struct ParserContext));
  context->current = firstToken;
  context->log = log;
  struct Node *file = calloc(1, sizeof(struct Node));
  file->kind = 1;

  if (!ParserContext_parseStatements(context, file)) {
    return NULL;
  }

  return file;
}

static uint8_t Preprocessor_peek(struct Preprocessor *__this, int32_t kind) {
  return __this->current->kind == kind;
}

static uint8_t Preprocessor_eat(struct Preprocessor *__this, int32_t kind) {
  if (Preprocessor_peek(__this, kind)) {
    Preprocessor_advance(__this);

    return 1;
  }

  return 0;
}

static void Preprocessor_advance(struct Preprocessor *__this) {
  if (!Preprocessor_peek(__this, 0)) {
    __this->previous = __this->current;
    __this->current = __this->current->next;
  }
}

static void Preprocessor_unexpectedToken(struct Preprocessor *__this) {
  Log_error(__this->log, __this->current->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_599_Unexpected), tokenToString(__this->current->kind))));
}

static uint8_t Preprocessor_expect(struct Preprocessor *__this, int32_t kind) {
  if (!Preprocessor_peek(__this, kind)) {
    Log_error(__this->log, __this->current->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_600_Expected), tokenToString(kind)), (const uint16_t *)__string_601_but_found), tokenToString(__this->current->kind))));

    return 0;
  }

  Preprocessor_advance(__this);

  return 1;
}

static void Preprocessor_removeTokensFrom(struct Preprocessor *__this, struct Token *before) {
  before->next = __this->current;
  __this->previous = before;
}

static uint8_t Preprocessor_isDefined(struct Preprocessor *__this, const uint16_t *name) {
  struct PreprocessorFlag *flag = __this->firstFlag;

  while (flag != NULL) {
    if (string_op_equals(flag->name, name)) {
      return flag->isDefined;
    }

    flag = flag->next;
  }

  return 0;
}

static void Preprocessor_define(struct Preprocessor *__this, const uint16_t *name, uint8_t isDefined) {
  struct PreprocessorFlag *flag = calloc(1, sizeof(struct PreprocessorFlag));
  flag->isDefined = isDefined;
  flag->name = name;
  flag->next = __this->firstFlag;
  __this->firstFlag = flag;
}

static void Preprocessor_run(struct Preprocessor *__this, struct Source *source, struct Log *log) {
  struct Token *firstToken = source->firstToken;

  if (firstToken != NULL && firstToken->kind == 79) {
    struct PreprocessorFlag *firstFlag = __this->firstFlag;
    __this->isDefineAndUndefAllowed = 1;
    __this->previous = firstToken;
    __this->current = firstToken->next;
    __this->log = log;

    if (!Preprocessor_scan(__this, 1)) {
      source->firstToken = NULL;

      return;
    }

    if (!Preprocessor_peek(__this, 0)) {
      Preprocessor_unexpectedToken(__this);
    }

    __this->firstFlag = firstFlag;
    source->firstToken = source->firstToken->next;
  }
}

static uint8_t Preprocessor_scan(struct Preprocessor *__this, uint8_t isParentLive) {
  while (!Preprocessor_peek(__this, 0) && !Preprocessor_peek(__this, 74) && !Preprocessor_peek(__this, 75) && !Preprocessor_peek(__this, 76)) {
    struct Token *previous = __this->previous;
    struct Token *current = __this->current;

    if (Preprocessor_eat(__this, 73) || Preprocessor_eat(__this, 81)) {
      if (Preprocessor_expect(__this, 2) && isParentLive) {
        Preprocessor_define(__this, Range_toString(__this->previous->range), current->kind == 73);
      }

      if (Preprocessor_eat(__this, 52) || (Preprocessor_eat(__this, 3) && string_op_equals(Range_toString(__this->previous->range), (const uint16_t *)__string_602_0))) {
        Log_error(__this->log, __this->previous->range, (const uint16_t *)__string_603_Use_undef_to_turn_a_preproces);
      }

      if (!Preprocessor_peek(__this, 0) && !Preprocessor_expect(__this, 80)) {
        while (!Preprocessor_eat(__this, 80) && !Preprocessor_eat(__this, 0)) {
          Preprocessor_advance(__this);
        }
      }

      if (!__this->isDefineAndUndefAllowed) {
        Log_error(__this->log, spanRanges(current->range, __this->previous->range), (const uint16_t *)__string_604_All_define_and_undef_direc);
      }

      Preprocessor_removeTokensFrom(__this, previous);
    }

    else if (Preprocessor_eat(__this, 82) || Preprocessor_eat(__this, 77)) {
      struct Token *next = __this->current;

      while (!Preprocessor_peek(__this, 80) && !Preprocessor_peek(__this, 0)) {
        Preprocessor_advance(__this);
      }

      if (isParentLive) {
        struct Range *range = __this->current == next ? current->range : spanRanges(next->range, __this->previous->range);
        Log_append(__this->log, range, Range_toString(range), current->kind == 82 ? 1 : 0);
      }

      Preprocessor_eat(__this, 80);
      Preprocessor_removeTokensFrom(__this, previous);
    }

    else if (Preprocessor_eat(__this, 78)) {
      uint8_t isLive = isParentLive;

      while (1) {
        int32_t condition = Preprocessor_parseExpression(__this, 0);

        if (condition == 2 || !Preprocessor_expect(__this, 80)) {
          return 0;
        }

        Preprocessor_removeTokensFrom(__this, previous);

        if (!Preprocessor_scan(__this, isLive && condition == 1)) {
          return 0;
        }

        if (!isLive || condition == 0) {
          Preprocessor_removeTokensFrom(__this, previous);
        }

        else {
          isLive = 0;
        }

        previous = __this->previous;

        if (Preprocessor_eat(__this, 74)) {
          continue;
        }

        if (Preprocessor_eat(__this, 75)) {
          if (!Preprocessor_expect(__this, 80)) {
            return 0;
          }

          Preprocessor_removeTokensFrom(__this, previous);

          if (!Preprocessor_scan(__this, isLive)) {
            return 0;
          }

          if (!isLive) {
            Preprocessor_removeTokensFrom(__this, previous);
          }
        }

        break;
      }

      previous = __this->previous;

      if (!Preprocessor_expect(__this, 76) || (!Preprocessor_peek(__this, 0) && !Preprocessor_expect(__this, 80))) {
        return 0;
      }

      Preprocessor_removeTokensFrom(__this, previous);
    }

    else {
      __this->isDefineAndUndefAllowed = 0;
      Preprocessor_advance(__this);
    }
  }

  return 1;
}

static int32_t Preprocessor_parsePrefix(struct Preprocessor *__this) {
  uint8_t isDefinedOperator = 0;
  struct Token *start = __this->current;

  if (Preprocessor_eat(__this, 69)) {
    return 1;
  }

  if (Preprocessor_eat(__this, 52)) {
    return 0;
  }

  if (Preprocessor_eat(__this, 2)) {
    const uint16_t *name = Range_toString(__this->previous->range);

    if (Preprocessor_peek(__this, 20) && string_op_equals(name, (const uint16_t *)__string_605_defined)) {
      isDefinedOperator = 1;
    }

    else {
      uint8_t isTrue = Preprocessor_isDefined(__this, name);

      return isTrue ? 1 : 0;
    }
  }

  if (Preprocessor_eat(__this, 28)) {
    int32_t value = Preprocessor_parseExpression(__this, 13);

    if (value == 2) {
      return 2;
    }

    return value == 1 ? 0 : 1;
  }

  if (Preprocessor_eat(__this, 20)) {
    struct Token *first = __this->current;
    int32_t value = Preprocessor_parseExpression(__this, 0);

    if (value == 2 || !Preprocessor_expect(__this, 36)) {
      return 2;
    }

    if (isDefinedOperator) {
      struct StringBuilder *builder = StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_606_There_is_no_defined_operator);

      if (first->kind == 2 && __this->previous == first->next) {
        StringBuilder_append(StringBuilder_append(StringBuilder_append(builder, (const uint16_t *)__string_607_just_use), Range_toString(first->range)), (const uint16_t *)__string_608_instead);
      }

      Log_error(__this->log, spanRanges(start->range, __this->previous->range), StringBuilder_finish(builder));
    }

    return value;
  }

  if (Preprocessor_eat(__this, 3)) {
    uint8_t isTrue = !string_op_equals(Range_toString(__this->previous->range), (const uint16_t *)__string_609_0);
    Log_error(__this->log, __this->previous->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_610_Unexpected_integer_did_you_mean), isTrue ? (const uint16_t *)__string_611_true : (const uint16_t *)__string_612_false), (const uint16_t *)__string_613)));

    return isTrue ? 1 : 0;
  }

  Preprocessor_unexpectedToken(__this);

  return 2;
}

static int32_t Preprocessor_parseInfix(struct Preprocessor *__this, int32_t precedence, int32_t left) {
  int32_t operator = __this->current->kind;

  if (precedence < 7 && (Preprocessor_eat(__this, 14) || Preprocessor_eat(__this, 29))) {
    int32_t right = Preprocessor_parseExpression(__this, 7);

    if (right == 2) {
      return 2;
    }

    return (operator == 14) == (left == right) ? 1 : 0;
  }

  if (precedence < 3 && Preprocessor_eat(__this, 23)) {
    int32_t right = Preprocessor_parseExpression(__this, 3);

    if (right == 2) {
      return 2;
    }

    return left == 1 && right == 1 ? 1 : 0;
  }

  if (precedence < 2 && Preprocessor_eat(__this, 24)) {
    int32_t right = Preprocessor_parseExpression(__this, 2);

    if (right == 2) {
      return 2;
    }

    return left == 1 || right == 1 ? 1 : 0;
  }

  if (precedence == 0 && Preprocessor_eat(__this, 32)) {
    int32_t middle = Preprocessor_parseExpression(__this, 0);

    if (middle == 2 || !Preprocessor_expect(__this, 9)) {
      return 2;
    }

    int32_t right = Preprocessor_parseExpression(__this, 0);

    if (right == 2) {
      return 2;
    }

    return left == 1 ? middle : right;
  }

  return left;
}

static int32_t Preprocessor_parseExpression(struct Preprocessor *__this, int32_t precedence) {
  int32_t value = Preprocessor_parsePrefix(__this);

  if (value == 2) {
    return 2;
  }

  while (1) {
    struct Token *current = __this->current;
    value = Preprocessor_parseInfix(__this, precedence, value);

    if (value == 2) {
      return 2;
    }

    if (__this->current == current) {
      break;
    }
  }

  return value;
}

static struct Symbol *Scope_findLocal(struct Scope *__this, const uint16_t *name, int32_t hint) {
  struct Symbol *symbol = __this->firstSymbol;
  struct Symbol *fallback = NULL;

  while (symbol != NULL) {
    if (string_op_equals(symbol->name, name)) {
      if ((hint == 5 && Symbol_isSetter(symbol)) || (hint == 6 && Symbol_isGetter(symbol))) {
        fallback = symbol;
      }

      else if ((hint != 2 || !Symbol_isGetter(symbol)) && (hint != 3 || !Symbol_isSetter(symbol)) && (hint != 1 || !Symbol_isBinaryOperator(symbol)) && (hint != 4 || !Symbol_isUnaryOperator(symbol))) {
        return symbol;
      }
    }

    symbol = symbol->next;
  }

  return fallback;
}

static struct Symbol *Scope_findNested(struct Scope *__this, const uint16_t *name, int32_t hint, int32_t mode) {
  struct Scope *scope = __this;

  while (scope != NULL) {
    if (scope->symbol == NULL || scope->symbol->kind != 0 || mode == 1) {
      struct Symbol *local = Scope_findLocal(scope, name, hint);

      if (local != NULL) {
        return local;
      }
    }

    scope = scope->parent;
  }

  return NULL;
}

static uint8_t Scope_define(struct Scope *__this, struct Log *log, struct Symbol *symbol, int32_t hint) {
  struct Symbol *existing = Scope_findLocal(__this, symbol->name, hint);

  if (existing != NULL) {
    Log_error(log, symbol->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_614_Duplicate_symbol), symbol->name), (const uint16_t *)__string_615)));

    return 0;
  }

  if (__this->firstSymbol == NULL) {
    __this->firstSymbol = symbol;
  }

  else {
    __this->lastSymbol->next = symbol;
  }

  __this->lastSymbol = symbol;

  return 1;
}

static struct Type *Scope_defineNativeType(struct Scope *__this, struct Log *log, const uint16_t *name) {
  struct Symbol *symbol = calloc(1, sizeof(struct Symbol));
  symbol->kind = 3;
  symbol->name = name;
  symbol->resolvedType = calloc(1, sizeof(struct Type));
  symbol->resolvedType->symbol = symbol;
  symbol->state = 2;
  Scope_define(__this, log, symbol, 0);

  return symbol->resolvedType;
}

static void treeShakingMarkAllUsed(struct Node *node) {
  struct Symbol *symbol = node->symbol;

  if (symbol != NULL && !Symbol_isUsed(symbol) && isFunction(symbol->kind) && symbol->node != NULL) {
    symbol->flags = symbol->flags | 64;
    treeShakingMarkAllUsed(symbol->node);

    if (node == symbol->node) {
      return;
    }
  }

  if (node->kind == 30) {
    struct Type *type = Node_newType(node)->resolvedType;

    if (type->symbol != NULL) {
      type->symbol->flags = type->symbol->flags | 64;
    }
  }

  struct Node *child = node->firstChild;

  while (child != NULL) {
    treeShakingMarkAllUsed(child);
    child = child->nextSibling;
  }
}

static void treeShakingSearchForUsed(struct Node *node) {
  if (node->kind == 15 && Node_isExtern(node)) {
    treeShakingMarkAllUsed(node);
  }

  else if (node->kind == 2 || node->kind == 9) {
    struct Node *child = node->firstChild;

    while (child != NULL) {
      treeShakingSearchForUsed(child);
      child = child->nextSibling;
    }

    if (node->kind == 9 && Node_isExtern(node)) {
      node->symbol->flags = node->symbol->flags | 64;
    }
  }
}

static void treeShakingRemoveUnused(struct Node *node) {
  if (node->kind == 15 && !Symbol_isUsed(node->symbol) && node->range->source->isLibrary) {
    Node_remove(node);
  }

  else if (node->kind == 2 || node->kind == 9) {
    struct Node *child = node->firstChild;

    while (child != NULL) {
      struct Node *next = child->nextSibling;
      treeShakingRemoveUnused(child);
      child = next;
    }

    if (node->kind == 9 && !Symbol_isUsed(node->symbol) && !Node_isDeclare(node) && node->range->source->isLibrary) {
      Node_remove(node);
    }
  }
}

static void treeShaking(struct Node *node) {
  treeShakingSearchForUsed(node);
  treeShakingRemoveUnused(node);
}

static struct StringBuilder *StringBuilder_new() {
  struct StringBuilder *sb = stringBuilderPool;

  if (sb != NULL) {
    stringBuilderPool = sb->next;
  }

  else {
    sb = calloc(1, sizeof(struct StringBuilder));
  }

  StringBuilder_clear(sb);

  return sb;
}

static void StringBuilder_appendQuoted(struct StringBuilder *sb, const uint16_t *text) {
  int32_t end = 0;
  int32_t limit = string_length(text);
  int32_t start = end;
  StringBuilder_appendChar(sb, 34);

  while (end < limit) {
    uint16_t c = string_op_get(text, end);

    if (c == 34) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_616);
    }

    else if (c == 0) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_617_0);
    }

    else if (c == 9) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_618_t);
    }

    else if (c == 13) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_619_r);
    }

    else if (c == 10) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_620_n);
    }

    else if (c == 92) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_621);
    }

    else {
      end = end + 1;

      continue;
    }

    end = end + 1;
    start = end;
  }

  StringBuilder_appendChar(StringBuilder_appendSlice(sb, text, start, end), 34);
}

static void StringBuilder_clear(struct StringBuilder *__this) {
  struct ByteArray *bytes = __this->_bytes;

  if (bytes == NULL) {
    bytes = calloc(1, sizeof(struct ByteArray));
    __this->_bytes = bytes;
  }

  else {
    ByteArray_clear(bytes);
  }
}

static struct StringBuilder *StringBuilder_appendChar(struct StringBuilder *__this, uint16_t c) {
  ByteArray_append(__this->_bytes, (uint8_t)c);
  ByteArray_append(__this->_bytes, (uint8_t)(c >> 8));

  return __this;
}

static struct StringBuilder *StringBuilder_appendSlice(struct StringBuilder *__this, const uint16_t *text, int32_t start, int32_t end) {
  return StringBuilder_append(__this, string_slice(text, start, end));
}

static struct StringBuilder *StringBuilder_append(struct StringBuilder *__this, const uint16_t *text) {
  struct ByteArray *bytes = __this->_bytes;
  uint32_t index = bytes->_length;
  int32_t length = string_length(text);
  ByteArray_resize(bytes, (int32_t)index + (length << 1));
  memcpy(bytes->_data + index, (uint8_t *)text + 4, (uint32_t)length << 1);

  return __this;
}

static const uint16_t *StringBuilder_finish(struct StringBuilder *__this) {
  __this->next = stringBuilderPool;
  stringBuilderPool = __this;
  struct ByteArray *bytes = __this->_bytes;
  uint32_t length = (uint32_t)bytes->_length >> 1;
  const uint16_t *ptr = string_new(length);
  memcpy((uint8_t *)ptr + 4, bytes->_data, length << 1);

  return ptr;
}

static uint8_t isType(int32_t kind) {
  return kind >= 0 && kind <= 3;
}

static uint8_t isFunction(int32_t kind) {
  return kind >= 4 && kind <= 5;
}

static uint8_t isVariable(int32_t kind) {
  return kind >= 6 && kind <= 10;
}

static uint8_t Symbol_isEnumValue(struct Symbol *__this) {
  return __this->node->parent->kind == 13;
}

static uint8_t Symbol_isUnsafe(struct Symbol *__this) {
  return __this->node != NULL && Node_isUnsafe(__this->node);
}

static uint8_t Symbol_isGetter(struct Symbol *__this) {
  return Node_isGet(__this->node);
}

static uint8_t Symbol_isSetter(struct Symbol *__this) {
  return Node_isSet(__this->node);
}

static uint8_t Symbol_isBinaryOperator(struct Symbol *__this) {
  return (__this->flags & 2) != 0;
}

static uint8_t Symbol_isUnaryOperator(struct Symbol *__this) {
  return (__this->flags & 8) != 0;
}

static uint8_t Symbol_shouldConvertInstanceToGlobal(struct Symbol *__this) {
  return (__this->flags & 1) != 0;
}

static uint8_t Symbol_isUsed(struct Symbol *__this) {
  return (__this->flags & 64) != 0;
}

static struct Symbol *Symbol_parent(struct Symbol *__this) {
  struct Node *parent = __this->node->parent;

  return parent->kind == 9 ? parent->symbol : NULL;
}

static struct Type *Symbol_resolvedTypeUnderlyingIfEnumValue(struct Symbol *__this, struct CheckContext *context) {
  return Symbol_isEnumValue(__this) ? Type_underlyingType(__this->resolvedType, context) : __this->resolvedType;
}

static void Symbol_determineClassLayout(struct Symbol *__this, struct CheckContext *context) {
  assert(__this->kind == 0);

  if (__this->byteSize != 0) {
    return;
  }

  int32_t offset = 0;
  struct Node *child = __this->node->firstChild;
  int32_t maxAlignment = 1;

  while (child != NULL) {
    if (child->kind == 6) {
      struct Type *type = child->symbol->resolvedType;

      if (type != context->errorType) {
        int32_t alignmentOf = Type_variableAlignmentOf(type, context);
        offset = alignToNextMultipleOf(offset, alignmentOf);

        if (alignmentOf > maxAlignment) {
          maxAlignment = alignmentOf;
        }

        child->symbol->offset = offset;
        offset = offset + Type_variableSizeOf(type, context);
      }
    }

    child = child->nextSibling;
  }

  if (offset == 0) {
    offset = 1;
  }

  offset = alignToNextMultipleOf(offset, maxAlignment);
  __this->byteSize = offset;
  __this->maxAlignment = maxAlignment;
}

static uint8_t Type_isClass(struct Type *__this) {
  return __this->symbol != NULL && __this->symbol->kind == 0;
}

static uint8_t Type_isEnum(struct Type *__this) {
  return __this->symbol != NULL && __this->symbol->kind == 1;
}

static uint8_t Type_isInteger(struct Type *__this) {
  return (__this->symbol != NULL && (__this->symbol->flags & 32) != 0) || Type_isEnum(__this);
}

static uint8_t Type_isUnsigned(struct Type *__this) {
  return __this->symbol != NULL && (__this->symbol->flags & 16) != 0;
}

static uint8_t Type_isReference(struct Type *__this) {
  return __this->pointerTo != NULL || (__this->symbol != NULL && (__this->symbol->flags & 4) != 0);
}

static struct Type *Type_underlyingType(struct Type *__this, struct CheckContext *context) {
  return Type_isEnum(__this) ? context->intType : __this->pointerTo != NULL ? context->uintType : __this;
}

static int32_t Type_integerBitCount(struct Type *__this, struct CheckContext *context) {
  return __this->symbol != NULL ? __this->symbol->byteSize << 3 : 0;
}

static uint32_t Type_integerBitMask(struct Type *__this, struct CheckContext *context) {
  return 4294967295 >> (uint32_t)(32 - Type_integerBitCount(__this, context));
}

static int32_t Type_allocationSizeOf(struct Type *__this, struct CheckContext *context) {
  return __this->symbol == NULL ? context->pointerByteSize : __this->symbol->byteSize;
}

static int32_t Type_allocationAlignmentOf(struct Type *__this, struct CheckContext *context) {
  return Type_allocationSizeOf(__this, context);
}

static int32_t Type_variableSizeOf(struct Type *__this, struct CheckContext *context) {
  return Type_isReference(__this) ? context->pointerByteSize : __this->symbol->byteSize;
}

static int32_t Type_variableAlignmentOf(struct Type *__this, struct CheckContext *context) {
  return Type_variableSizeOf(__this, context);
}

static struct Type *Type_pointerType(struct Type *__this) {
  struct Type *type = __this->cachedPointerType;

  if (type == NULL) {
    type = calloc(1, sizeof(struct Type));
    type->pointerTo = __this;
    __this->cachedPointerType = type;
  }

  return type;
}

static const uint16_t *Type_toString(struct Type *__this) {
  if (string_op_equals(__this->cachedToString, NULL)) {
    __this->cachedToString = __this->pointerTo != NULL ? StringBuilder_finish(StringBuilder_append(StringBuilder_appendChar(StringBuilder_new(), 42), Type_toString(__this->pointerTo))) : __this->symbol->name;
  }

  return __this->cachedToString;
}

static struct Symbol *Type_findMember(struct Type *__this, const uint16_t *name, int32_t hint) {
  struct Symbol *symbol = __this->symbol;

  return symbol != NULL && symbol->scope != NULL ? Scope_findLocal(symbol->scope, name, hint) : NULL;
}

static uint8_t Type_hasInstanceMembers(struct Type *__this) {
  struct Symbol *symbol = __this->symbol;

  return symbol != NULL && (symbol->kind == 0 || symbol->kind == 3);
}

static uint8_t wasmAreSignaturesEqual(struct WasmSignature *a, struct WasmSignature *b) {
  assert(a->returnType != NULL);
  assert(b->returnType != NULL);
  assert(a->returnType->next == NULL);
  assert(b->returnType->next == NULL);
  struct WasmWrappedType *x = a->argumentTypes;
  struct WasmWrappedType *y = b->argumentTypes;

  while (x != NULL && y != NULL) {
    if (x->id != y->id) {
      return 0;
    }

    x = x->next;
    y = y->next;
  }

  if (x != NULL || y != NULL) {
    return 0;
  }

  if (a->returnType->id != b->returnType->id) {
    return 0;
  }

  return 1;
}

static void WasmModule_growMemoryInitializer(struct WasmModule *__this) {
  struct ByteArray *array = __this->memoryInitializer;
  int32_t current = ByteArray_length(array);
  int32_t length = __this->context->nextGlobalVariableOffset;

  while (current < length) {
    ByteArray_append(array, 0);
    current = current + 1;
  }
}

static struct WasmImport *WasmModule_allocateImport(struct WasmModule *__this, int32_t signatureIndex, const uint16_t *mod, const uint16_t *name) {
  struct WasmImport *result = calloc(1, sizeof(struct WasmImport));
  result->signatureIndex = signatureIndex;
  result->module = mod;
  result->name = name;

  if (__this->firstImport == NULL) {
    __this->firstImport = result;
  }

  else {
    __this->lastImport->next = result;
  }

  __this->lastImport = result;
  __this->importCount = __this->importCount + 1;

  return result;
}

static struct WasmFunction *WasmModule_allocateFunction(struct WasmModule *__this, struct Symbol *symbol, int32_t signatureIndex) {
  struct WasmFunction *fn = calloc(1, sizeof(struct WasmFunction));
  fn->symbol = symbol;
  fn->signatureIndex = signatureIndex;

  if (__this->firstFunction == NULL) {
    __this->firstFunction = fn;
  }

  else {
    __this->lastFunction->next = fn;
  }

  __this->lastFunction = fn;
  __this->functionCount = __this->functionCount + 1;

  return fn;
}

static int32_t WasmModule_allocateSignature(struct WasmModule *__this, struct WasmWrappedType *argumentTypes, struct WasmWrappedType *returnType) {
  assert(returnType != NULL);
  assert(returnType->next == NULL);
  struct WasmSignature *signature = calloc(1, sizeof(struct WasmSignature));
  signature->argumentTypes = argumentTypes;
  signature->returnType = returnType;
  struct WasmSignature *check = __this->firstSignature;
  int32_t i = 0;

  while (check != NULL) {
    if (wasmAreSignaturesEqual(signature, check)) {
      return i;
    }

    check = check->next;
    i = i + 1;
  }

  if (__this->firstSignature == NULL) {
    __this->firstSignature = signature;
  }

  else {
    __this->lastSignature->next = signature;
  }

  __this->lastSignature = signature;
  __this->signatureCount = __this->signatureCount + 1;

  return i;
}

static void WasmModule_emitModule(struct WasmModule *__this, struct ByteArray *array) {
  ByteArray_append32(array, 1836278016);
  ByteArray_append32(array, 11);
  WasmModule_emitSignatures(__this, array);
  WasmModule_emitImportTable(__this, array);
  WasmModule_emitFunctionSignatures(__this, array);
  WasmModule_emitMemory(__this, array);
  WasmModule_emitExportTable(__this, array);
  WasmModule_emitFunctionBodies(__this, array);
  WasmModule_emitDataSegments(__this, array);
  WasmModule_emitNames(__this, array);
}

static void WasmModule_emitSignatures(struct WasmModule *__this, struct ByteArray *array) {
  int32_t section = wasmStartSection(array, (const uint16_t *)__string_622_type);
  wasmWriteVarUnsigned(array, __this->signatureCount);
  struct WasmSignature *signature = __this->firstSignature;

  while (signature != NULL) {
    int32_t count = 0;
    struct WasmWrappedType *type = signature->argumentTypes;

    while (type != NULL) {
      count = count + 1;
      type = type->next;
    }

    ByteArray_append(array, 64);
    wasmWriteVarUnsigned(array, count);
    type = signature->argumentTypes;

    while (type != NULL) {
      wasmWriteVarUnsigned(array, (int32_t)type->id);
      type = type->next;
    }

    if (signature->returnType->id != 0) {
      ByteArray_append(array, 1);
      wasmWriteVarUnsigned(array, (int32_t)signature->returnType->id);
    }

    else {
      ByteArray_append(array, 0);
    }

    signature = signature->next;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitImportTable(struct WasmModule *__this, struct ByteArray *array) {
  if (__this->firstImport == NULL) {
    return;
  }

  int32_t section = wasmStartSection(array, (const uint16_t *)__string_623_import);
  wasmWriteVarUnsigned(array, __this->importCount);
  struct WasmImport *current = __this->firstImport;

  while (current != NULL) {
    wasmWriteVarUnsigned(array, current->signatureIndex);
    wasmWriteLengthPrefixedASCII(array, current->module);
    wasmWriteLengthPrefixedASCII(array, current->name);
    current = current->next;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitFunctionSignatures(struct WasmModule *__this, struct ByteArray *array) {
  if (__this->firstFunction == NULL) {
    return;
  }

  int32_t section = wasmStartSection(array, (const uint16_t *)__string_624_function);
  wasmWriteVarUnsigned(array, __this->functionCount);
  struct WasmFunction *fn = __this->firstFunction;

  while (fn != NULL) {
    wasmWriteVarUnsigned(array, fn->signatureIndex);
    fn = fn->next;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitMemory(struct WasmModule *__this, struct ByteArray *array) {
  int32_t section = wasmStartSection(array, (const uint16_t *)__string_625_memory);
  wasmWriteVarUnsigned(array, 256);
  wasmWriteVarUnsigned(array, 256);
  wasmWriteVarUnsigned(array, 1);
  wasmFinishSection(array, section);
}

static void WasmModule_emitExportTable(struct WasmModule *__this, struct ByteArray *array) {
  int32_t exportedCount = 0;
  struct WasmFunction *fn = __this->firstFunction;

  while (fn != NULL) {
    if (fn->isExported) {
      exportedCount = exportedCount + 1;
    }

    fn = fn->next;
  }

  if (exportedCount == 0) {
    return;
  }

  int32_t section = wasmStartSection(array, (const uint16_t *)__string_626_export);
  wasmWriteVarUnsigned(array, exportedCount);
  int32_t i = 0;
  fn = __this->firstFunction;

  while (fn != NULL) {
    if (fn->isExported) {
      wasmWriteVarUnsigned(array, i);
      wasmWriteLengthPrefixedASCII(array, fn->symbol->name);
    }

    fn = fn->next;
    i = i + 1;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitFunctionBodies(struct WasmModule *__this, struct ByteArray *array) {
  if (__this->firstFunction == NULL) {
    return;
  }

  int32_t section = wasmStartSection(array, (const uint16_t *)__string_627_code);
  wasmWriteVarUnsigned(array, __this->functionCount);
  struct WasmFunction *fn = __this->firstFunction;

  while (fn != NULL) {
    int32_t bodyLength = ByteArray_length(array);
    wasmWriteVarUnsigned(array, -1);

    if (fn->intLocalCount > 0) {
      wasmWriteVarUnsigned(array, 1);
      wasmWriteVarUnsigned(array, fn->intLocalCount);
      ByteArray_append(array, 1);
    }

    else {
      wasmWriteVarUnsigned(array, 0);
    }

    struct Node *child = Node_functionBody(fn->symbol->node)->firstChild;

    while (child != NULL) {
      WasmModule_emitNode(__this, array, child);
      child = child->nextSibling;
    }

    wasmPatchVarUnsigned(array, bodyLength, ByteArray_length(array) - bodyLength - 5, -1);
    fn = fn->next;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitDataSegments(struct WasmModule *__this, struct ByteArray *array) {
  WasmModule_growMemoryInitializer(__this);
  struct ByteArray *memoryInitializer = __this->memoryInitializer;
  int32_t initializerLength = ByteArray_length(memoryInitializer);
  int32_t initialHeapPointer = alignToNextMultipleOf(initializerLength + 8, 8);
  ByteArray_set32(memoryInitializer, __this->currentHeapPointer, initialHeapPointer);
  ByteArray_set32(memoryInitializer, __this->originalHeapPointer, initialHeapPointer);
  int32_t section = wasmStartSection(array, (const uint16_t *)__string_628_data);
  wasmWriteVarUnsigned(array, 1);
  wasmWriteVarUnsigned(array, 8);
  wasmWriteVarUnsigned(array, initializerLength);
  int32_t i = 0;

  while (i < initializerLength) {
    ByteArray_append(array, ByteArray_get(memoryInitializer, i));
    i = i + 1;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitNames(struct WasmModule *__this, struct ByteArray *array) {
  int32_t section = wasmStartSection(array, (const uint16_t *)__string_629_name);
  wasmWriteVarUnsigned(array, __this->functionCount);
  struct WasmFunction *fn = __this->firstFunction;

  while (fn != NULL) {
    const uint16_t *name = fn->symbol->name;

    if (fn->symbol->kind == 4) {
      name = StringBuilder_finish(StringBuilder_append(StringBuilder_appendChar(StringBuilder_append(StringBuilder_new(), Symbol_parent(fn->symbol)->name), 46), name));
    }

    wasmWriteLengthPrefixedASCII(array, name);
    wasmWriteVarUnsigned(array, 0);
    fn = fn->next;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_prepareToEmit(struct WasmModule *__this, struct Node *node) {
  if (node->kind == 34) {
    const uint16_t *text = node->stringValue;
    int32_t length = string_length(text);
    int32_t offset = CheckContext_allocateGlobalVariableOffset(__this->context, (length << 1) + 4, 4);
    node->intValue = offset;
    WasmModule_growMemoryInitializer(__this);
    struct ByteArray *memoryInitializer = __this->memoryInitializer;
    ByteArray_set32(memoryInitializer, offset, length);
    ByteArray_setString(memoryInitializer, offset + 4, text);
  }

  else if (node->kind == 6) {
    struct Symbol *symbol = node->symbol;

    if (symbol->kind == 8) {
      int32_t sizeOf = Type_variableSizeOf(symbol->resolvedType, __this->context);
      int32_t value = Node_variableValue(symbol->node)->intValue;
      struct ByteArray *memoryInitializer = __this->memoryInitializer;
      WasmModule_growMemoryInitializer(__this);

      if (sizeOf == 1) {
        ByteArray_set(memoryInitializer, symbol->offset, (uint8_t)value);
      }

      else if (sizeOf == 2) {
        ByteArray_set16(memoryInitializer, symbol->offset, value);
      }

      else if (sizeOf == 4) {
        ByteArray_set32(memoryInitializer, symbol->offset, value);
      }

      else {
        assert(0);
      }

      if (string_op_equals(symbol->name, (const uint16_t *)__string_630_currentHeapPointer)) {
        assert(__this->currentHeapPointer == -1);
        __this->currentHeapPointer = symbol->offset;
      }

      else if (string_op_equals(symbol->name, (const uint16_t *)__string_631_originalHeapPointer)) {
        assert(__this->originalHeapPointer == -1);
        __this->originalHeapPointer = symbol->offset;
      }
    }
  }

  else if (node->kind == 15) {
    struct Node *returnType = Node_functionReturnType(node);
    struct WasmSharedOffset *shared = calloc(1, sizeof(struct WasmSharedOffset));
    struct WasmWrappedType *argumentTypesFirst = NULL;
    struct WasmWrappedType *argumentTypesLast = NULL;
    struct Node *argument = Node_functionFirstArgument(node);

    while (argument != returnType) {
      struct WasmWrappedType *type = wasmWrapType(WasmModule_getWasmType(__this, Node_variableType(argument)->resolvedType));

      if (argumentTypesFirst == NULL) {
        argumentTypesFirst = type;
      }

      else {
        argumentTypesLast->next = type;
      }

      argumentTypesLast = type;
      shared->nextLocalOffset = shared->nextLocalOffset + 1;
      argument = argument->nextSibling;
    }

    int32_t signatureIndex = WasmModule_allocateSignature(__this, argumentTypesFirst, wasmWrapType(WasmModule_getWasmType(__this, returnType->resolvedType)));
    struct Node *body = Node_functionBody(node);
    struct Symbol *symbol = node->symbol;

    if (body == NULL) {
      const uint16_t *moduleName = symbol->kind == 4 ? Symbol_parent(symbol)->name : (const uint16_t *)__string_632_global;
      symbol->offset = __this->importCount;
      WasmModule_allocateImport(__this, signatureIndex, moduleName, symbol->name);
      node = node->nextSibling;

      return;
    }

    symbol->offset = __this->functionCount;
    struct WasmFunction *fn = WasmModule_allocateFunction(__this, symbol, signatureIndex);

    if (symbol->kind == 5 && string_op_equals(symbol->name, (const uint16_t *)__string_633_malloc)) {
      assert(__this->mallocFunctionIndex == -1);
      __this->mallocFunctionIndex = symbol->offset;
    }

    if (Node_isExtern(node)) {
      fn->isExported = 1;
    }

    wasmAssignLocalVariableOffsets(body, shared);
    fn->intLocalCount = shared->intLocalCount;
  }

  struct Node *child = node->firstChild;

  while (child != NULL) {
    WasmModule_prepareToEmit(__this, child);
    child = child->nextSibling;
  }
}

static void WasmModule_emitBinaryExpression(struct WasmModule *__this, struct ByteArray *array, struct Node *node, uint8_t opcode) {
  WasmModule_emitNode(__this, array, Node_binaryLeft(node));
  WasmModule_emitNode(__this, array, Node_binaryRight(node));
  ByteArray_append(array, opcode);
}

static void WasmModule_emitLoadFromMemory(struct WasmModule *__this, struct ByteArray *array, struct Type *type, struct Node *relativeBase, int32_t offset) {
  if (relativeBase != NULL) {
    WasmModule_emitNode(__this, array, relativeBase);
  }

  else {
    ByteArray_append(array, 16);
    wasmWriteVarUnsigned(array, 0);
  }

  int32_t sizeOf = Type_variableSizeOf(type, __this->context);

  if (sizeOf == 1) {
    ByteArray_append(array, Type_isUnsigned(type) ? 33 : 32);
    wasmWriteVarUnsigned(array, 0);
  }

  else if (sizeOf == 2) {
    ByteArray_append(array, Type_isUnsigned(type) ? 35 : 34);
    wasmWriteVarUnsigned(array, 1);
  }

  else if (sizeOf == 4) {
    ByteArray_append(array, 42);
    wasmWriteVarUnsigned(array, 2);
  }

  else {
    assert(0);
  }

  wasmWriteVarUnsigned(array, offset);
}

static void WasmModule_emitStoreToMemory(struct WasmModule *__this, struct ByteArray *array, struct Type *type, struct Node *relativeBase, int32_t offset, struct Node *value) {
  if (relativeBase != NULL) {
    WasmModule_emitNode(__this, array, relativeBase);
  }

  else {
    ByteArray_append(array, 16);
    wasmWriteVarUnsigned(array, 0);
  }

  WasmModule_emitNode(__this, array, value);
  int32_t sizeOf = Type_variableSizeOf(type, __this->context);

  if (sizeOf == 1) {
    ByteArray_append(array, 46);
    wasmWriteVarUnsigned(array, 0);
  }

  else if (sizeOf == 2) {
    ByteArray_append(array, 47);
    wasmWriteVarUnsigned(array, 1);
  }

  else if (sizeOf == 4) {
    ByteArray_append(array, 51);
    wasmWriteVarUnsigned(array, 2);
  }

  else {
    assert(0);
  }

  wasmWriteVarUnsigned(array, offset);
}

static void WasmModule_emitNode(struct WasmModule *__this, struct ByteArray *array, struct Node *node) {
  assert(!isExpression(node) || node->resolvedType != NULL);

  if (node->kind == 7) {
    ByteArray_append(array, 1);
    struct Node *child = node->firstChild;

    while (child != NULL) {
      WasmModule_emitNode(__this, array, child);
      child = child->nextSibling;
    }

    ByteArray_append(array, 15);
  }

  else if (node->kind == 20) {
    struct Node *value = Node_whileValue(node);
    struct Node *body = Node_whileBody(node);

    if (value->kind == 22 && value->intValue == 0) {
      return;
    }

    ByteArray_append(array, 2);

    if (value->kind != 22) {
      WasmModule_emitNode(__this, array, value);
      ByteArray_append(array, 90);
      ByteArray_append(array, 7);
      ByteArray_append(array, 0);
      wasmWriteVarUnsigned(array, 1);
    }

    struct Node *child = body->firstChild;

    while (child != NULL) {
      WasmModule_emitNode(__this, array, child);
      child = child->nextSibling;
    }

    ByteArray_append(array, 6);
    ByteArray_append(array, 0);
    wasmWriteVarUnsigned(array, 0);
    ByteArray_append(array, 15);
  }

  else if (node->kind == 8 || node->kind == 11) {
    int32_t label = 0;
    struct Node *parent = node->parent;
    struct Node *child = node;

    while (parent != NULL && parent->kind != 20) {
      if (parent->kind == 7) {
        label = label + 1;
      }

      else if (parent->kind == 16 && Node_ifValue(parent) != child) {
        label = label + 1;
      }

      else if (parent->kind == 26 && Node_hookValue(parent) != child) {
        label = label + 1;
      }

      else if (parent->kind == 60 && Node_binaryLeft(parent) != child) {
        label = label + 1;
      }

      else if (parent->kind == 61 && Node_binaryLeft(parent) != child) {
        label = label + 1;
      }

      parent = parent->parent;
      child = child->parent;
    }

    assert(label > 0);
    ByteArray_append(array, 6);
    ByteArray_append(array, 0);
    wasmWriteVarUnsigned(array, label - (node->kind == 8 ? 0 : 1));
  }

  else if (node->kind == 12) {
    return;
  }

  else if (node->kind == 14) {
    WasmModule_emitNode(__this, array, Node_expressionValue(node));
  }

  else if (node->kind == 17) {
    struct Node *value = Node_returnValue(node);

    if (value != NULL) {
      WasmModule_emitNode(__this, array, value);
      ByteArray_append(array, 9);
      ByteArray_append(array, 1);
    }

    else {
      ByteArray_append(array, 9);
      ByteArray_append(array, 0);
    }
  }

  else if (node->kind == 19) {
    struct Node *child = node->firstChild;

    while (child != NULL) {
      assert(child->kind == 6);
      WasmModule_emitNode(__this, array, child);
      child = child->nextSibling;
    }
  }

  else if (node->kind == 16) {
    struct Node *branch = Node_ifFalse(node);
    WasmModule_emitNode(__this, array, Node_ifValue(node));
    ByteArray_append(array, 3);
    WasmModule_emitNode(__this, array, Node_ifTrue(node));

    if (branch != NULL) {
      ByteArray_append(array, 4);
      WasmModule_emitNode(__this, array, branch);
    }

    ByteArray_append(array, 15);
  }

  else if (node->kind == 26) {
    WasmModule_emitNode(__this, array, Node_hookValue(node));
    ByteArray_append(array, 3);
    WasmModule_emitNode(__this, array, Node_hookTrue(node));
    ByteArray_append(array, 4);
    WasmModule_emitNode(__this, array, Node_hookFalse(node));
    ByteArray_append(array, 15);
  }

  else if (node->kind == 6) {
    struct Node *value = Node_variableValue(node);

    if (node->symbol->kind == 10) {
      if (value != NULL) {
        WasmModule_emitNode(__this, array, value);
      }

      else {
        ByteArray_append(array, 16);
        wasmWriteVarSigned(array, 0);
      }

      ByteArray_append(array, 21);
      wasmWriteVarUnsigned(array, node->symbol->offset);
    }

    else {
      assert(0);
    }
  }

  else if (node->kind == 29) {
    struct Symbol *symbol = node->symbol;

    if (symbol->kind == 6 || symbol->kind == 10) {
      ByteArray_append(array, 20);
      wasmWriteVarUnsigned(array, symbol->offset);
    }

    else if (symbol->kind == 8) {
      WasmModule_emitLoadFromMemory(__this, array, symbol->resolvedType, NULL, symbol->offset + 8);
    }

    else {
      assert(0);
    }
  }

  else if (node->kind == 39) {
    WasmModule_emitLoadFromMemory(__this, array, Type_underlyingType(node->resolvedType, __this->context), Node_unaryValue(node), 0);
  }

  else if (node->kind == 31) {
    ByteArray_append(array, 16);
    wasmWriteVarSigned(array, 0);
  }

  else if (node->kind == 28 || node->kind == 22) {
    ByteArray_append(array, 16);
    wasmWriteVarSigned(array, node->intValue);
  }

  else if (node->kind == 34) {
    ByteArray_append(array, 16);
    wasmWriteVarSigned(array, node->intValue + 8);
  }

  else if (node->kind == 23) {
    struct Node *value = Node_callValue(node);
    struct Symbol *symbol = value->symbol;
    assert(isFunction(symbol->kind));
    int32_t count = 0;

    if (symbol->kind == 4) {
      WasmModule_emitNode(__this, array, Node_dotTarget(value));
      count = count + 1;
    }

    struct Node *child = value->nextSibling;

    while (child != NULL) {
      WasmModule_emitNode(__this, array, child);
      count = count + 1;
      child = child->nextSibling;
    }

    ByteArray_append(array, Node_functionBody(symbol->node) == NULL ? 24 : 22);
    wasmWriteVarUnsigned(array, count);
    wasmWriteVarUnsigned(array, symbol->offset);
  }

  else if (node->kind == 30) {
    struct Node *type = Node_newType(node);
    int32_t size = Type_allocationSizeOf(type->resolvedType, __this->context);
    assert(size > 0);
    ByteArray_append(array, 16);
    wasmWriteVarSigned(array, size);
    ByteArray_append(array, 22);
    ByteArray_append(array, 1);
    wasmWriteVarUnsigned(array, __this->mallocFunctionIndex);
  }

  else if (node->kind == 43) {
    WasmModule_emitNode(__this, array, Node_unaryValue(node));
  }

  else if (node->kind == 40) {
    ByteArray_append(array, 16);
    wasmWriteVarSigned(array, 0);
    WasmModule_emitNode(__this, array, Node_unaryValue(node));
    ByteArray_append(array, 65);
  }

  else if (node->kind == 38) {
    ByteArray_append(array, 16);
    wasmWriteVarSigned(array, -1);
    WasmModule_emitNode(__this, array, Node_unaryValue(node));
    ByteArray_append(array, 73);
  }

  else if (node->kind == 41) {
    WasmModule_emitNode(__this, array, Node_unaryValue(node));
    ByteArray_append(array, 90);
  }

  else if (node->kind == 24) {
    struct Node *value = Node_castValue(node);
    struct CheckContext *context = __this->context;
    struct Type *from = Type_underlyingType(value->resolvedType, context);
    struct Type *type = Type_underlyingType(node->resolvedType, context);
    int32_t fromSize = Type_variableSizeOf(from, context);
    int32_t typeSize = Type_variableSizeOf(type, context);

    if (from == type || fromSize < typeSize) {
      WasmModule_emitNode(__this, array, value);
    }

    else if (type == context->sbyteType || type == context->shortType) {
      int32_t shift = 32 - (typeSize << 3);
      WasmModule_emitNode(__this, array, value);
      ByteArray_append(array, 16);
      wasmWriteVarSigned(array, shift);
      ByteArray_append(array, 74);
      ByteArray_append(array, 16);
      wasmWriteVarSigned(array, shift);
      ByteArray_append(array, 76);
    }

    else if (type == context->byteType || type == context->ushortType) {
      WasmModule_emitNode(__this, array, value);
      ByteArray_append(array, 16);
      wasmWriteVarSigned(array, (int32_t)Type_integerBitMask(type, __this->context));
      ByteArray_append(array, 71);
    }

    else {
      WasmModule_emitNode(__this, array, value);
    }
  }

  else if (node->kind == 25) {
    struct Symbol *symbol = node->symbol;

    if (symbol->kind == 9) {
      WasmModule_emitLoadFromMemory(__this, array, symbol->resolvedType, Node_dotTarget(node), symbol->offset);
    }

    else {
      assert(0);
    }
  }

  else if (node->kind == 49) {
    struct Node *left = Node_binaryLeft(node);
    struct Node *right = Node_binaryRight(node);
    struct Symbol *symbol = left->symbol;

    if (left->kind == 39) {
      WasmModule_emitStoreToMemory(__this, array, Type_underlyingType(left->resolvedType, __this->context), Node_unaryValue(left), 0, right);
    }

    else if (symbol->kind == 9) {
      WasmModule_emitStoreToMemory(__this, array, symbol->resolvedType, Node_dotTarget(left), symbol->offset, right);
    }

    else if (symbol->kind == 8) {
      WasmModule_emitStoreToMemory(__this, array, symbol->resolvedType, NULL, symbol->offset + 8, right);
    }

    else if (symbol->kind == 6 || symbol->kind == 10) {
      WasmModule_emitNode(__this, array, right);
      ByteArray_append(array, 21);
      wasmWriteVarUnsigned(array, symbol->offset);
    }

    else {
      assert(0);
    }
  }

  else if (node->kind == 60) {
    WasmModule_emitNode(__this, array, Node_binaryLeft(node));
    ByteArray_append(array, 3);
    WasmModule_emitNode(__this, array, Node_binaryRight(node));
    ByteArray_append(array, 4);
    ByteArray_append(array, 16);
    wasmWriteVarSigned(array, 0);
    ByteArray_append(array, 15);
  }

  else if (node->kind == 61) {
    WasmModule_emitNode(__this, array, Node_binaryLeft(node));
    ByteArray_append(array, 3);
    ByteArray_append(array, 16);
    wasmWriteVarSigned(array, 1);
    ByteArray_append(array, 4);
    WasmModule_emitNode(__this, array, Node_binaryRight(node));
    ByteArray_append(array, 15);
  }

  else {
    uint8_t isUnsigned = Node_isUnsignedOperator(node);

    if (node->kind == 48) {
      struct Node *left = Node_binaryLeft(node);
      struct Node *right = Node_binaryRight(node);
      WasmModule_emitNode(__this, array, left);

      if (left->resolvedType->pointerTo == NULL) {
        WasmModule_emitNode(__this, array, right);
      }

      else {
        assert(Type_isInteger(right->resolvedType));
        int32_t size = Type_allocationSizeOf(left->resolvedType->pointerTo, __this->context);

        if (size == 2) {
          if (right->kind == 28) {
            ByteArray_append(array, 16);
            wasmWriteVarSigned(array, right->intValue << 1);
          }

          else {
            WasmModule_emitNode(__this, array, right);
            ByteArray_append(array, 16);
            wasmWriteVarSigned(array, 1);
            ByteArray_append(array, 74);
          }
        }

        else if (size == 4) {
          if (right->kind == 28) {
            ByteArray_append(array, 16);
            wasmWriteVarSigned(array, right->intValue << 2);
          }

          else {
            WasmModule_emitNode(__this, array, right);
            ByteArray_append(array, 16);
            wasmWriteVarSigned(array, 2);
            ByteArray_append(array, 74);
          }
        }

        else {
          WasmModule_emitNode(__this, array, right);
        }
      }

      ByteArray_append(array, 64);
    }

    else if (node->kind == 50) {
      WasmModule_emitBinaryExpression(__this, array, node, 71);
    }

    else if (node->kind == 51) {
      WasmModule_emitBinaryExpression(__this, array, node, 72);
    }

    else if (node->kind == 52) {
      WasmModule_emitBinaryExpression(__this, array, node, 73);
    }

    else if (node->kind == 54) {
      WasmModule_emitBinaryExpression(__this, array, node, 77);
    }

    else if (node->kind == 62) {
      WasmModule_emitBinaryExpression(__this, array, node, 66);
    }

    else if (node->kind == 63) {
      WasmModule_emitBinaryExpression(__this, array, node, 78);
    }

    else if (node->kind == 65) {
      WasmModule_emitBinaryExpression(__this, array, node, 74);
    }

    else if (node->kind == 67) {
      WasmModule_emitBinaryExpression(__this, array, node, 65);
    }

    else if (node->kind == 53) {
      WasmModule_emitBinaryExpression(__this, array, node, isUnsigned ? 68 : 67);
    }

    else if (node->kind == 56) {
      WasmModule_emitBinaryExpression(__this, array, node, isUnsigned ? 85 : 83);
    }

    else if (node->kind == 57) {
      WasmModule_emitBinaryExpression(__this, array, node, isUnsigned ? 86 : 84);
    }

    else if (node->kind == 58) {
      WasmModule_emitBinaryExpression(__this, array, node, isUnsigned ? 81 : 79);
    }

    else if (node->kind == 59) {
      WasmModule_emitBinaryExpression(__this, array, node, isUnsigned ? 82 : 80);
    }

    else if (node->kind == 64) {
      WasmModule_emitBinaryExpression(__this, array, node, isUnsigned ? 70 : 69);
    }

    else if (node->kind == 66) {
      WasmModule_emitBinaryExpression(__this, array, node, isUnsigned ? 75 : 76);
    }

    else {
      assert(0);
    }
  }
}

static int32_t WasmModule_getWasmType(struct WasmModule *__this, struct Type *type) {
  struct CheckContext *context = __this->context;

  if (type == context->boolType || Type_isInteger(type) || Type_isReference(type)) {
    return 1;
  }

  if (type == context->voidType) {
    return 0;
  }

  assert(0);

  return 0;
}

static void wasmPatchVarUnsigned(struct ByteArray *array, int32_t offset, int32_t value, int32_t maxValue) {
  uint32_t current = (uint32_t)value;
  uint32_t max = (uint32_t)maxValue;

  while (1) {
    uint32_t element = current & 127;
    current = current >> 7;
    max = max >> 7;

    if (max != 0) {
      element = element | 128;
    }

    ByteArray_set(array, offset, (uint8_t)element);
    offset = offset + 1;

    if (max == 0) {
      break;
    }
  }
}

static void wasmWriteVarUnsigned(struct ByteArray *array, int32_t value) {
  uint32_t current = (uint32_t)value;

  while (1) {
    uint32_t element = current & 127;
    current = current >> 7;

    if (current != 0) {
      element = element | 128;
    }

    ByteArray_append(array, (uint8_t)element);

    if (current == 0) {
      break;
    }
  }
}

static void wasmWriteVarSigned(struct ByteArray *array, int32_t value) {
  while (1) {
    int32_t element = value & 127;
    value = value >> 7;
    uint8_t done = (value == 0 && (element & 64) == 0) || (value == -1 && (element & 64) != 0);

    if (!done) {
      element = element | 128;
    }

    ByteArray_append(array, (uint8_t)element);

    if (done) {
      break;
    }
  }
}

static void wasmWriteLengthPrefixedASCII(struct ByteArray *array, const uint16_t *value) {
  int32_t length = string_length(value);
  wasmWriteVarUnsigned(array, length);
  int32_t index = ByteArray_length(array);
  ByteArray_resize(array, index + length);
  int32_t i = 0;

  while (i < length) {
    ByteArray_set(array, index + i, (uint8_t)string_op_get(value, i));
    i = i + 1;
  }
}

static int32_t wasmStartSection(struct ByteArray *array, const uint16_t *name) {
  wasmWriteLengthPrefixedASCII(array, name);
  int32_t offset = ByteArray_length(array);
  wasmWriteVarUnsigned(array, -1);

  return offset;
}

static void wasmFinishSection(struct ByteArray *array, int32_t offset) {
  wasmPatchVarUnsigned(array, offset, ByteArray_length(array) - offset - 5, -1);
}

static struct WasmWrappedType *wasmWrapType(int32_t id) {
  assert(id == 0 || id == 1);
  struct WasmWrappedType *type = calloc(1, sizeof(struct WasmWrappedType));
  type->id = id;

  return type;
}

static void wasmAssignLocalVariableOffsets(struct Node *node, struct WasmSharedOffset *shared) {
  if (node->kind == 6) {
    assert(node->symbol->kind == 10);
    node->symbol->offset = shared->nextLocalOffset;
    shared->nextLocalOffset = shared->nextLocalOffset + 1;
    shared->intLocalCount = shared->intLocalCount + 1;
  }

  struct Node *child = node->firstChild;

  while (child != NULL) {
    wasmAssignLocalVariableOffsets(child, shared);
    child = child->nextSibling;
  }
}

static void wasmEmit(struct Compiler *compiler) {
  struct WasmModule *module = calloc(1, sizeof(struct WasmModule));
  module->context = compiler->context;
  module->memoryInitializer = calloc(1, sizeof(struct ByteArray));
  module->mallocFunctionIndex = -1;
  module->currentHeapPointer = -1;
  module->originalHeapPointer = -1;
  WasmModule_prepareToEmit(module, compiler->global);
  assert(module->mallocFunctionIndex != -1);
  assert(module->currentHeapPointer != -1);
  assert(module->originalHeapPointer != -1);
  compiler->outputWASM = calloc(1, sizeof(struct ByteArray));
  WasmModule_emitModule(module, compiler->outputWASM);
}
