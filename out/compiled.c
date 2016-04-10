#include <stdint.h>
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
static const uint32_t __string_7_0[] = {4, S('\'', '\\'), S('0', '\'')};
static const uint32_t __string_8_r[] = {4, S('\'', '\\'), S('r', '\'')};
static const uint32_t __string_9_n[] = {4, S('\'', '\\'), S('n', '\'')};
static const uint32_t __string_10_t[] = {4, S('\'', '\\'), S('t', '\'')};
static const uint32_t __string_11_NULL[] = {4, S('N', 'U'), S('L', 'L')};
static const uint32_t __string_12___string_[] = {9, S('_', '_'), S('s', 't'), S('r', 'i'), S('n', 'g'), S('_', 0)};
static const uint32_t __string_13_ifdef_THINSCRIPT_BIG_ENDIAN[] = {120, S('\n', '#'), S('i', 'f'), S('d', 'e'), S('f', ' '), S('T', 'H'), S('I', 'N'), S('S', 'C'), S('R', 'I'), S('P', 'T'), S('_', 'B'), S('I', 'G'), S('_', 'E'), S('N', 'D'), S('I', 'A'), S('N', '\n'), S(' ', ' '), S('#', 'd'), S('e', 'f'), S('i', 'n'), S('e', ' '), S('S', '('), S('a', ','), S(' ', 'b'), S(')', ' '), S('(', '('), S('(', 'a'), S(')', ' '), S('<', '<'), S(' ', '1'), S('6', ')'), S(' ', '|'), S(' ', '('), S('b', ')'), S(')', '\n'), S('#', 'e'), S('l', 's'), S('e', '\n'), S(' ', ' '), S('#', 'd'), S('e', 'f'), S('i', 'n'), S('e', ' '), S('S', '('), S('a', ','), S(' ', 'b'), S(')', ' '), S('(', '('), S('a', ')'), S(' ', '|'), S(' ', '('), S('(', 'b'), S(')', ' '), S('<', '<'), S(' ', '1'), S('6', ')'), S(')', '\n'), S('#', 'e'), S('n', 'd'), S('i', 'f'), S('\n', '\n')};
static const uint32_t __string_14_static_const_uint32_t[] = {22, S('s', 't'), S('a', 't'), S('i', 'c'), S(' ', 'c'), S('o', 'n'), S('s', 't'), S(' ', 'u'), S('i', 'n'), S('t', '3'), S('2', '_'), S('t', ' ')};
static const uint32_t __string_15[] = {6, S('[', ']'), S(' ', '='), S(' ', '{')};
static const uint32_t __string_16_S[] = {4, S(',', ' '), S('S', '(')};
static const uint32_t __string_17[] = {2, S(',', ' ')};
static const uint32_t __string_18_0[] = {4, S(',', ' '), S('0', ')')};
static const uint32_t __string_19[] = {3, S('}', ';'), S('\n', 0)};
static const uint32_t __string_20_const_uint16_t[] = {18, S('(', 'c'), S('o', 'n'), S('s', 't'), S(' ', 'u'), S('i', 'n'), S('t', '1'), S('6', '_'), S('t', ' '), S('*', ')')};
static const uint32_t __string_21[] = {2, S('-', '>')};
static const uint32_t __string_22[] = {1, S('.', 0)};
static const uint32_t __string_23[] = {3, S(' ', '?'), S(' ', 0)};
static const uint32_t __string_24[] = {3, S(' ', ':'), S(' ', 0)};
static const uint32_t __string_25[] = {2, S(',', ' ')};
static const uint32_t __string_26_calloc_1_sizeof[] = {17, S('c', 'a'), S('l', 'l'), S('o', 'c'), S('(', '1'), S(',', ' '), S('s', 'i'), S('z', 'e'), S('o', 'f'), S('(', 0)};
static const uint32_t __string_27[] = {2, S(')', ')')};
static const uint32_t __string_28[] = {1, S('~', 0)};
static const uint32_t __string_29[] = {1, S('*', 0)};
static const uint32_t __string_30[] = {1, S('-', 0)};
static const uint32_t __string_31[] = {1, S('!', 0)};
static const uint32_t __string_32[] = {1, S('+', 0)};
static const uint32_t __string_33[] = {2, S('-', '-')};
static const uint32_t __string_34[] = {2, S('+', '+')};
static const uint32_t __string_35[] = {2, S('-', '-')};
static const uint32_t __string_36[] = {2, S('+', '+')};
static const uint32_t __string_37[] = {3, S(' ', '+'), S(' ', 0)};
static const uint32_t __string_38[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_39[] = {3, S(' ', '&'), S(' ', 0)};
static const uint32_t __string_40[] = {3, S(' ', '|'), S(' ', 0)};
static const uint32_t __string_41[] = {3, S(' ', '^'), S(' ', 0)};
static const uint32_t __string_42[] = {3, S(' ', '/'), S(' ', 0)};
static const uint32_t __string_43[] = {4, S(' ', '='), S('=', ' ')};
static const uint32_t __string_44[] = {3, S(' ', '>'), S(' ', 0)};
static const uint32_t __string_45[] = {4, S(' ', '>'), S('=', ' ')};
static const uint32_t __string_46[] = {3, S(' ', '<'), S(' ', 0)};
static const uint32_t __string_47[] = {4, S(' ', '<'), S('=', ' ')};
static const uint32_t __string_48[] = {4, S(' ', '&'), S('&', ' ')};
static const uint32_t __string_49[] = {4, S(' ', '|'), S('|', ' ')};
static const uint32_t __string_50[] = {3, S(' ', '*'), S(' ', 0)};
static const uint32_t __string_51[] = {4, S(' ', '!'), S('=', ' ')};
static const uint32_t __string_52[] = {3, S(' ', '%'), S(' ', 0)};
static const uint32_t __string_53[] = {4, S(' ', '<'), S('<', ' ')};
static const uint32_t __string_54[] = {4, S(' ', '>'), S('>', ' ')};
static const uint32_t __string_55[] = {3, S(' ', '-'), S(' ', 0)};
static const uint32_t __string_56_struct[] = {7, S('s', 't'), S('r', 'u'), S('c', 't'), S(' ', 0)};
static const uint32_t __string_57_uint8_t[] = {7, S('u', 'i'), S('n', 't'), S('8', '_'), S('t', 0)};
static const uint32_t __string_58_int8_t[] = {6, S('i', 'n'), S('t', '8'), S('_', 't')};
static const uint32_t __string_59_int32_t[] = {7, S('i', 'n'), S('t', '3'), S('2', '_'), S('t', 0)};
static const uint32_t __string_60_int16_t[] = {7, S('i', 'n'), S('t', '1'), S('6', '_'), S('t', 0)};
static const uint32_t __string_61_const_uint16_t[] = {14, S('c', 'o'), S('n', 's'), S('t', ' '), S('u', 'i'), S('n', 't'), S('1', '6'), S('_', 't')};
static const uint32_t __string_62_uint32_t[] = {8, S('u', 'i'), S('n', 't'), S('3', '2'), S('_', 't')};
static const uint32_t __string_63_uint16_t[] = {8, S('u', 'i'), S('n', 't'), S('1', '6'), S('_', 't')};
static const uint32_t __string_64[] = {2, S(' ', '*')};
static const uint32_t __string_65_if[] = {4, S('i', 'f'), S(' ', '(')};
static const uint32_t __string_66[] = {2, S(')', ' ')};
static const uint32_t __string_67[] = {2, S('\n', '\n')};
static const uint32_t __string_68_else[] = {5, S('e', 'l'), S('s', 'e'), S(' ', 0)};
static const uint32_t __string_69_while[] = {7, S('w', 'h'), S('i', 'l'), S('e', ' '), S('(', 0)};
static const uint32_t __string_70[] = {2, S(')', ' ')};
static const uint32_t __string_71_break[] = {7, S('b', 'r'), S('e', 'a'), S('k', ';'), S('\n', 0)};
static const uint32_t __string_72_continue[] = {10, S('c', 'o'), S('n', 't'), S('i', 'n'), S('u', 'e'), S(';', '\n')};
static const uint32_t __string_73[] = {2, S(';', '\n')};
static const uint32_t __string_74_return[] = {7, S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 0)};
static const uint32_t __string_75[] = {2, S(';', '\n')};
static const uint32_t __string_76_return[] = {8, S('r', 'e'), S('t', 'u'), S('r', 'n'), S(';', '\n')};
static const uint32_t __string_77[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_78[] = {2, S(';', '\n')};
static const uint32_t __string_79_include_stdint_h[] = {20, S('#', 'i'), S('n', 'c'), S('l', 'u'), S('d', 'e'), S(' ', '<'), S('s', 't'), S('d', 'i'), S('n', 't'), S('.', 'h'), S('>', '\n')};
static const uint32_t __string_80_include_stdlib_h[] = {20, S('#', 'i'), S('n', 'c'), S('l', 'u'), S('d', 'e'), S(' ', '<'), S('s', 't'), S('d', 'l'), S('i', 'b'), S('.', 'h'), S('>', '\n')};
static const uint32_t __string_81_include_string_h[] = {20, S('#', 'i'), S('n', 'c'), S('l', 'u'), S('d', 'e'), S(' ', '<'), S('s', 't'), S('r', 'i'), S('n', 'g'), S('.', 'h'), S('>', '\n')};
static const uint32_t __string_82_struct[] = {7, S('s', 't'), S('r', 'u'), S('c', 't'), S(' ', 0)};
static const uint32_t __string_83[] = {2, S(';', '\n')};
static const uint32_t __string_84_struct[] = {7, S('s', 't'), S('r', 'u'), S('c', 't'), S(' ', 0)};
static const uint32_t __string_85[] = {3, S(' ', '{'), S('\n', 0)};
static const uint32_t __string_86[] = {2, S(';', '\n')};
static const uint32_t __string_87[] = {3, S('}', ';'), S('\n', 0)};
static const uint32_t __string_88_malloc[] = {6, S('m', 'a'), S('l', 'l'), S('o', 'c')};
static const uint32_t __string_89_memcpy[] = {6, S('m', 'e'), S('m', 'c'), S('p', 'y')};
static const uint32_t __string_90_memcmp[] = {6, S('m', 'e'), S('m', 'c'), S('m', 'p')};
static const uint32_t __string_91_static[] = {7, S('s', 't'), S('a', 't'), S('i', 'c'), S(' ', 0)};
static const uint32_t __string_92[] = {2, S(',', ' ')};
static const uint32_t __string_93[] = {3, S(')', ';'), S('\n', 0)};
static const uint32_t __string_94_static[] = {7, S('s', 't'), S('a', 't'), S('i', 'c'), S(' ', 0)};
static const uint32_t __string_95[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_96[] = {2, S(';', '\n')};
static const uint32_t __string_97_static[] = {7, S('s', 't'), S('a', 't'), S('i', 'c'), S(' ', 0)};
static const uint32_t __string_98[] = {2, S(',', ' ')};
static const uint32_t __string_99[] = {2, S(')', ' ')};
static const uint32_t __string_100_undef_S[] = {10, S('\n', '#'), S('u', 'n'), S('d', 'e'), S('f', ' '), S('S', '\n')};
static const uint32_t __string_101_This_statement_is_not_allowed_he[] = {34, S('T', 'h'), S('i', 's'), S(' ', 's'), S('t', 'a'), S('t', 'e'), S('m', 'e'), S('n', 't'), S(' ', 'i'), S('s', ' '), S('n', 'o'), S('t', ' '), S('a', 'l'), S('l', 'o'), S('w', 'e'), S('d', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_102[] = {1, S('+', 0)};
static const uint32_t __string_103[] = {1, S('-', 0)};
static const uint32_t __string_104[] = {1, S('+', 0)};
static const uint32_t __string_105_op_positive[] = {11, S('o', 'p'), S('_', 'p'), S('o', 's'), S('i', 't'), S('i', 'v'), S('e', 0)};
static const uint32_t __string_106_op_negative[] = {11, S('o', 'p'), S('_', 'n'), S('e', 'g'), S('a', 't'), S('i', 'v'), S('e', 0)};
static const uint32_t __string_107[] = {1, S('+', 0)};
static const uint32_t __string_108_op_add[] = {6, S('o', 'p'), S('_', 'a'), S('d', 'd')};
static const uint32_t __string_109_op_subtract[] = {11, S('o', 'p'), S('_', 's'), S('u', 'b'), S('t', 'r'), S('a', 'c'), S('t', 0)};
static const uint32_t __string_110[] = {1, S('%', 0)};
static const uint32_t __string_111_op_remainder[] = {12, S('o', 'p'), S('_', 'r'), S('e', 'm'), S('a', 'i'), S('n', 'd'), S('e', 'r')};
static const uint32_t __string_112[] = {1, S('&', 0)};
static const uint32_t __string_113_op_and[] = {6, S('o', 'p'), S('_', 'a'), S('n', 'd')};
static const uint32_t __string_114[] = {1, S('*', 0)};
static const uint32_t __string_115_op_multiply[] = {11, S('o', 'p'), S('_', 'm'), S('u', 'l'), S('t', 'i'), S('p', 'l'), S('y', 0)};
static const uint32_t __string_116[] = {2, S('*', '*')};
static const uint32_t __string_117_op_exponent[] = {11, S('o', 'p'), S('_', 'e'), S('x', 'p'), S('o', 'n'), S('e', 'n'), S('t', 0)};
static const uint32_t __string_118[] = {2, S('+', '+')};
static const uint32_t __string_119_op_increment[] = {12, S('o', 'p'), S('_', 'i'), S('n', 'c'), S('r', 'e'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_120[] = {2, S('-', '-')};
static const uint32_t __string_121_op_decrement[] = {12, S('o', 'p'), S('_', 'd'), S('e', 'c'), S('r', 'e'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_122[] = {1, S('/', 0)};
static const uint32_t __string_123_op_divide[] = {9, S('o', 'p'), S('_', 'd'), S('i', 'v'), S('i', 'd'), S('e', 0)};
static const uint32_t __string_124[] = {1, S('<', 0)};
static const uint32_t __string_125_op_lessThan[] = {11, S('o', 'p'), S('_', 'l'), S('e', 's'), S('s', 'T'), S('h', 'a'), S('n', 0)};
static const uint32_t __string_126[] = {2, S('<', '<')};
static const uint32_t __string_127_op_shiftLeft[] = {12, S('o', 'p'), S('_', 's'), S('h', 'i'), S('f', 't'), S('L', 'e'), S('f', 't')};
static const uint32_t __string_128[] = {2, S('=', '=')};
static const uint32_t __string_129_op_equals[] = {9, S('o', 'p'), S('_', 'e'), S('q', 'u'), S('a', 'l'), S('s', 0)};
static const uint32_t __string_130[] = {1, S('>', 0)};
static const uint32_t __string_131_op_greaterThan[] = {14, S('o', 'p'), S('_', 'g'), S('r', 'e'), S('a', 't'), S('e', 'r'), S('T', 'h'), S('a', 'n')};
static const uint32_t __string_132[] = {2, S('>', '>')};
static const uint32_t __string_133_op_shiftRight[] = {13, S('o', 'p'), S('_', 's'), S('h', 'i'), S('f', 't'), S('R', 'i'), S('g', 'h'), S('t', 0)};
static const uint32_t __string_134[] = {2, S('[', ']')};
static const uint32_t __string_135_op_get[] = {6, S('o', 'p'), S('_', 'g'), S('e', 't')};
static const uint32_t __string_136[] = {3, S('[', ']'), S('=', 0)};
static const uint32_t __string_137_op_set[] = {6, S('o', 'p'), S('_', 's'), S('e', 't')};
static const uint32_t __string_138[] = {1, S('^', 0)};
static const uint32_t __string_139_op_xor[] = {6, S('o', 'p'), S('_', 'x'), S('o', 'r')};
static const uint32_t __string_140[] = {1, S('|', 0)};
static const uint32_t __string_141_op_or[] = {5, S('o', 'p'), S('_', 'o'), S('r', 0)};
static const uint32_t __string_142[] = {1, S('~', 0)};
static const uint32_t __string_143_op_complement[] = {13, S('o', 'p'), S('_', 'c'), S('o', 'm'), S('p', 'l'), S('e', 'm'), S('e', 'n'), S('t', 0)};
static const uint32_t __string_144_this[] = {4, S('t', 'h'), S('i', 's')};
static const uint32_t __string_145_bool[] = {4, S('b', 'o'), S('o', 'l')};
static const uint32_t __string_146_byte[] = {4, S('b', 'y'), S('t', 'e')};
static const uint32_t __string_147_int[] = {3, S('i', 'n'), S('t', 0)};
static const uint32_t __string_148_sbyte[] = {5, S('s', 'b'), S('y', 't'), S('e', 0)};
static const uint32_t __string_149_short[] = {5, S('s', 'h'), S('o', 'r'), S('t', 0)};
static const uint32_t __string_150_string[] = {6, S('s', 't'), S('r', 'i'), S('n', 'g')};
static const uint32_t __string_151_uint[] = {4, S('u', 'i'), S('n', 't')};
static const uint32_t __string_152_ushort[] = {6, S('u', 's'), S('h', 'o'), S('r', 't')};
static const uint32_t __string_153_Unsupported_flag_export[] = {25, S('U', 'n'), S('s', 'u'), S('p', 'p'), S('o', 'r'), S('t', 'e'), S('d', ' '), S('f', 'l'), S('a', 'g'), S(' ', '\''), S('e', 'x'), S('p', 'o'), S('r', 't'), S('\'', 0)};
static const uint32_t __string_154_Unsupported_flag_protected[] = {28, S('U', 'n'), S('s', 'u'), S('p', 'p'), S('o', 'r'), S('t', 'e'), S('d', ' '), S('f', 'l'), S('a', 'g'), S(' ', '\''), S('p', 'r'), S('o', 't'), S('e', 'c'), S('t', 'e'), S('d', '\'')};
static const uint32_t __string_155_Unsupported_flag_static[] = {25, S('U', 'n'), S('s', 'u'), S('p', 'p'), S('o', 'r'), S('t', 'e'), S('d', ' '), S('f', 'l'), S('a', 'g'), S(' ', '\''), S('s', 't'), S('a', 't'), S('i', 'c'), S('\'', 0)};
static const uint32_t __string_156_Cannot_use_get_on_a_class[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('g', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a', ' '), S('c', 'l'), S('a', 's'), S('s', 0)};
static const uint32_t __string_157_Cannot_use_set_on_a_class[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('s', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a', ' '), S('c', 'l'), S('a', 's'), S('s', 0)};
static const uint32_t __string_158_Cannot_use_public_on_a_class[] = {30, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'u'), S('b', 'l'), S('i', 'c'), S('\'', ' '), S('o', 'n'), S(' ', 'a'), S(' ', 'c'), S('l', 'a'), S('s', 's')};
static const uint32_t __string_159_Cannot_use_private_on_a_class[] = {31, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', '\''), S(' ', 'o'), S('n', ' '), S('a', ' '), S('c', 'l'), S('a', 's'), S('s', 0)};
static const uint32_t __string_160_Cannot_use_get_on_an_enum[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('g', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a', 'n'), S(' ', 'e'), S('n', 'u'), S('m', 0)};
static const uint32_t __string_161_Cannot_use_set_on_an_enum[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('s', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a', 'n'), S(' ', 'e'), S('n', 'u'), S('m', 0)};
static const uint32_t __string_162_Cannot_use_public_on_an_enum[] = {30, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'u'), S('b', 'l'), S('i', 'c'), S('\'', ' '), S('o', 'n'), S(' ', 'a'), S('n', ' '), S('e', 'n'), S('u', 'm')};
static const uint32_t __string_163_Cannot_use_private_on_an_enum[] = {31, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', '\''), S(' ', 'o'), S('n', ' '), S('a', 'n'), S(' ', 'e'), S('n', 'u'), S('m', 0)};
static const uint32_t __string_164_Cannot_use_get_here[] = {21, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('g', 'e'), S('t', '\''), S(' ', 'h'), S('e', 'r'), S('e', 0)};
static const uint32_t __string_165_Cannot_use_set_here[] = {21, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('s', 'e'), S('t', '\''), S(' ', 'h'), S('e', 'r'), S('e', 0)};
static const uint32_t __string_166_Cannot_use_public_here[] = {24, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'u'), S('b', 'l'), S('i', 'c'), S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_167_Cannot_use_private_here[] = {25, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', '\''), S(' ', 'h'), S('e', 'r'), S('e', 0)};
static const uint32_t __string_168_Cannot_use_both_get_and_set[] = {31, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 'b'), S('o', 't'), S('h', ' '), S('\'', 'g'), S('e', 't'), S('\'', ' '), S('a', 'n'), S('d', ' '), S('\'', 's'), S('e', 't'), S('\'', 0)};
static const uint32_t __string_169_Getters_must_not_have_any_argume[] = {35, S('G', 'e'), S('t', 't'), S('e', 'r'), S('s', ' '), S('m', 'u'), S('s', 't'), S(' ', 'n'), S('o', 't'), S(' ', 'h'), S('a', 'v'), S('e', ' '), S('a', 'n'), S('y', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't'), S('s', 0)};
static const uint32_t __string_170_set_[] = {4, S('s', 'e'), S('t', '_')};
static const uint32_t __string_171_Setters_must_have_exactly_one_ar[] = {38, S('S', 'e'), S('t', 't'), S('e', 'r'), S('s', ' '), S('m', 'u'), S('s', 't'), S(' ', 'h'), S('a', 'v'), S('e', ' '), S('e', 'x'), S('a', 'c'), S('t', 'l'), S('y', ' '), S('o', 'n'), S('e', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_172[] = {1, S('~', 0)};
static const uint32_t __string_173[] = {2, S('+', '+')};
static const uint32_t __string_174[] = {2, S('-', '-')};
static const uint32_t __string_175_Operator[] = {10, S('O', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\'')};
static const uint32_t __string_176_must_not_have_any_arguments[] = {29, S('\'', ' '), S('m', 'u'), S('s', 't'), S(' ', 'n'), S('o', 't'), S(' ', 'h'), S('a', 'v'), S('e', ' '), S('a', 'n'), S('y', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't'), S('s', 0)};
static const uint32_t __string_177[] = {1, S('+', 0)};
static const uint32_t __string_178[] = {1, S('-', 0)};
static const uint32_t __string_179_Operator[] = {10, S('O', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\'')};
static const uint32_t __string_180_must_have_at_most_one_argument[] = {32, S('\'', ' '), S('m', 'u'), S('s', 't'), S(' ', 'h'), S('a', 'v'), S('e', ' '), S('a', 't'), S(' ', 'm'), S('o', 's'), S('t', ' '), S('o', 'n'), S('e', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_181[] = {3, S('[', ']'), S('=', 0)};
static const uint32_t __string_182_Operator_must_have_at_leas[] = {46, S('O', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\''), S('[', ']'), S('=', '\''), S(' ', 'm'), S('u', 's'), S('t', ' '), S('h', 'a'), S('v', 'e'), S(' ', 'a'), S('t', ' '), S('l', 'e'), S('a', 's'), S('t', ' '), S('o', 'n'), S('e', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_183_Operator[] = {10, S('O', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\'')};
static const uint32_t __string_184_must_have_exactly_one_argument[] = {32, S('\'', ' '), S('m', 'u'), S('s', 't'), S(' ', 'h'), S('a', 'v'), S('e', ' '), S('e', 'x'), S('a', 'c'), S('t', 'l'), S('y', ' '), S('o', 'n'), S('e', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't')};
static const uint32_t __string_185_Cannot_use_extern_on_an_instan[] = {43, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('e', 'x'), S('t', 'e'), S('r', 'n'), S('\'', ' '), S('o', 'n'), S(' ', 'a'), S('n', ' '), S('i', 'n'), S('s', 't'), S('a', 'n'), S('c', 'e'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', 0)};
static const uint32_t __string_186_Cannot_use_declare_on_an_insta[] = {44, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', '\''), S(' ', 'o'), S('n', ' '), S('a', 'n'), S(' ', 'i'), S('n', 's'), S('t', 'a'), S('n', 'c'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n')};
static const uint32_t __string_187_Must_implement_this_function[] = {28, S('M', 'u'), S('s', 't'), S(' ', 'i'), S('m', 'p'), S('l', 'e'), S('m', 'e'), S('n', 't'), S(' ', 't'), S('h', 'i'), S('s', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n')};
static const uint32_t __string_188_this[] = {4, S('t', 'h'), S('i', 's')};
static const uint32_t __string_189___this[] = {6, S('_', '_'), S('t', 'h'), S('i', 's')};
static const uint32_t __string_190_Cannot_use_extern_on_an_unimpl[] = {48, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('e', 'x'), S('t', 'e'), S('r', 'n'), S('\'', ' '), S('o', 'n'), S(' ', 'a'), S('n', ' '), S('u', 'n'), S('i', 'm'), S('p', 'l'), S('e', 'm'), S('e', 'n'), S('t', 'e'), S('d', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n')};
static const uint32_t __string_191_Declared_functions_must_be_prefi[] = {50, S('D', 'e'), S('c', 'l'), S('a', 'r'), S('e', 'd'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', 's'), S(' ', 'm'), S('u', 's'), S('t', ' '), S('b', 'e'), S(' ', 'p'), S('r', 'e'), S('f', 'i'), S('x', 'e'), S('d', ' '), S('w', 'i'), S('t', 'h'), S(' ', '\''), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', '\'')};
static const uint32_t __string_192_Cannot_use_declare_on_a_functi[] = {57, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', '\''), S(' ', 'o'), S('n', ' '), S('a', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'w'), S('i', 't'), S('h', ' '), S('a', 'n'), S(' ', 'i'), S('m', 'p'), S('l', 'e'), S('m', 'e'), S('n', 't'), S('a', 't'), S('i', 'o'), S('n', 0)};
static const uint32_t __string_193_Cannot_use_get_on_a_variable[] = {30, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('g', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a', ' '), S('v', 'a'), S('r', 'i'), S('a', 'b'), S('l', 'e')};
static const uint32_t __string_194_Cannot_use_set_on_a_variable[] = {30, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('s', 'e'), S('t', '\''), S(' ', 'o'), S('n', ' '), S('a', ' '), S('v', 'a'), S('r', 'i'), S('a', 'b'), S('l', 'e')};
static const uint32_t __string_195_Cannot_use_public_here[] = {24, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'u'), S('b', 'l'), S('i', 'c'), S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_196_Cannot_use_private_here[] = {25, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', '\''), S(' ', 'h'), S('e', 'r'), S('e', 0)};
static const uint32_t __string_197_Cannot_create_untyped_variables[] = {31, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('r', 'e'), S('a', 't'), S('e', ' '), S('u', 'n'), S('t', 'y'), S('p', 'e'), S('d', ' '), S('v', 'a'), S('r', 'i'), S('a', 'b'), S('l', 'e'), S('s', 0)};
static const uint32_t __string_198_Cannot_create_a_variable_with_ty[] = {36, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('r', 'e'), S('a', 't'), S('e', ' '), S('a', ' '), S('v', 'a'), S('r', 'i'), S('a', 'b'), S('l', 'e'), S(' ', 'w'), S('i', 't'), S('h', ' '), S('t', 'y'), S('p', 'e'), S(' ', '\'')};
static const uint32_t __string_199_Invalid_constant_initializer[] = {28, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('c', 'o'), S('n', 's'), S('t', 'a'), S('n', 't'), S(' ', 'i'), S('n', 'i'), S('t', 'i'), S('a', 'l'), S('i', 'z'), S('e', 'r')};
static const uint32_t __string_200_Constants_must_be_initialized[] = {29, S('C', 'o'), S('n', 's'), S('t', 'a'), S('n', 't'), S('s', ' '), S('m', 'u'), S('s', 't'), S(' ', 'b'), S('e', ' '), S('i', 'n'), S('i', 't'), S('i', 'a'), S('l', 'i'), S('z', 'e'), S('d', 0)};
static const uint32_t __string_201_The_symbol[] = {12, S('T', 'h'), S('e', ' '), S('s', 'y'), S('m', 'b'), S('o', 'l'), S(' ', '\'')};
static const uint32_t __string_202_shadows_another_symbol_with_th[] = {61, S('\'', ' '), S('s', 'h'), S('a', 'd'), S('o', 'w'), S('s', ' '), S('a', 'n'), S('o', 't'), S('h', 'e'), S('r', ' '), S('s', 'y'), S('m', 'b'), S('o', 'l'), S(' ', 'w'), S('i', 't'), S('h', ' '), S('t', 'h'), S('e', ' '), S('s', 'a'), S('m', 'e'), S(' ', 'n'), S('a', 'm'), S('e', ' '), S('i', 'n'), S(' ', 'a'), S(' ', 'p'), S('a', 'r'), S('e', 'n'), S('t', ' '), S('s', 'c'), S('o', 'p'), S('e', 0)};
static const uint32_t __string_203_Expected_expression_but_found_ty[] = {34, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 'e'), S('x', 'p'), S('r', 'e'), S('s', 's'), S('i', 'o'), S('n', ' '), S('b', 'u'), S('t', ' '), S('f', 'o'), S('u', 'n'), S('d', ' '), S('t', 'y'), S('p', 'e')};
static const uint32_t __string_204_This_expression_does_not_return[] = {39, S('T', 'h'), S('i', 's'), S(' ', 'e'), S('x', 'p'), S('r', 'e'), S('s', 's'), S('i', 'o'), S('n', ' '), S('d', 'o'), S('e', 's'), S(' ', 'n'), S('o', 't'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('a', ' '), S('v', 'a'), S('l', 'u'), S('e', 0)};
static const uint32_t __string_205_Expected_type_but_found_expressi[] = {34, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('b', 'u'), S('t', ' '), S('f', 'o'), S('u', 'n'), S('d', ' '), S('e', 'x'), S('p', 'r'), S('e', 's'), S('s', 'i'), S('o', 'n')};
static const uint32_t __string_206_Cannot_convert_from_type[] = {26, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('o', 'n'), S('v', 'e'), S('r', 't'), S(' ', 'f'), S('r', 'o'), S('m', ' '), S('t', 'y'), S('p', 'e'), S(' ', '\'')};
static const uint32_t __string_207_to_type[] = {11, S('\'', ' '), S('t', 'o'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_208_without_a_cast[] = {16, S('\'', ' '), S('w', 'i'), S('t', 'h'), S('o', 'u'), S('t', ' '), S('a', ' '), S('c', 'a'), S('s', 't')};
static const uint32_t __string_209[] = {1, S('\'', 0)};
static const uint32_t __string_210_Cannot_store_to_this_location[] = {29, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 's'), S('t', 'o'), S('r', 'e'), S(' ', 't'), S('o', ' '), S('t', 'h'), S('i', 's'), S(' ', 'l'), S('o', 'c'), S('a', 't'), S('i', 'o'), S('n', 0)};
static const uint32_t __string_211_Cannot_use_symbol[] = {19, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 's'), S('y', 'm'), S('b', 'o'), S('l', ' '), S('\'', 0)};
static const uint32_t __string_212_outside_an_unsafe_block[] = {27, S('\'', ' '), S('o', 'u'), S('t', 's'), S('i', 'd'), S('e', ' '), S('a', 'n'), S(' ', '\''), S('u', 'n'), S('s', 'a'), S('f', 'e'), S('\'', ' '), S('b', 'l'), S('o', 'c'), S('k', 0)};
static const uint32_t __string_213_Cannot_access_private_symbol[] = {30, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'a'), S('c', 'c'), S('e', 's'), S('s', ' '), S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', ' '), S('s', 'y'), S('m', 'b'), S('o', 'l'), S(' ', '\'')};
static const uint32_t __string_214_here[] = {6, S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_215_Cannot_use_setter[] = {19, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 's'), S('e', 't'), S('t', 'e'), S('r', ' '), S('\'', 0)};
static const uint32_t __string_216_here[] = {6, S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_217_Must_call_function[] = {20, S('M', 'u'), S('s', 't'), S(' ', 'c'), S('a', 'l'), S('l', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', '\'')};
static const uint32_t __string_218_Global_initializers_must_be_comp[] = {50, S('G', 'l'), S('o', 'b'), S('a', 'l'), S(' ', 'i'), S('n', 'i'), S('t', 'i'), S('a', 'l'), S('i', 'z'), S('e', 'r'), S('s', ' '), S('m', 'u'), S('s', 't'), S(' ', 'b'), S('e', ' '), S('c', 'o'), S('m', 'p'), S('i', 'l'), S('e', '-'), S('t', 'i'), S('m', 'e'), S(' ', 'c'), S('o', 'n'), S('s', 't'), S('a', 'n'), S('t', 's')};
static const uint32_t __string_219_Cannot_use_this_statement_outsid[] = {43, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 't'), S('h', 'i'), S('s', ' '), S('s', 't'), S('a', 't'), S('e', 'm'), S('e', 'n'), S('t', ' '), S('o', 'u'), S('t', 's'), S('i', 'd'), S('e', ' '), S('o', 'f'), S(' ', 'a'), S(' ', 'l'), S('o', 'o'), S('p', 0)};
static const uint32_t __string_220[] = {2, S('[', ']')};
static const uint32_t __string_221_Cannot_index_into_type[] = {24, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'i'), S('n', 'd'), S('e', 'x'), S(' ', 'i'), S('n', 't'), S('o', ' '), S('t', 'y'), S('p', 'e'), S(' ', '\'')};
static const uint32_t __string_222_this[] = {4, S('t', 'h'), S('i', 's')};
static const uint32_t __string_223_Cannot_use_this_here[] = {22, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\''), S('t', 'h'), S('i', 's'), S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_224_No_symbol_named[] = {17, S('N', 'o'), S(' ', 's'), S('y', 'm'), S('b', 'o'), S('l', ' '), S('n', 'a'), S('m', 'e'), S('d', ' '), S('\'', 0)};
static const uint32_t __string_225_here[] = {6, S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_226_did_you_mean_this[] = {21, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('t', 'h'), S('i', 's'), S('.', 0)};
static const uint32_t __string_227[] = {2, S('\'', '?')};
static const uint32_t __string_228_number[] = {6, S('n', 'u'), S('m', 'b'), S('e', 'r')};
static const uint32_t __string_229_did_you_mean_int[] = {21, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('i', 'n'), S('t', '\''), S('?', 0)};
static const uint32_t __string_230_boolean[] = {7, S('b', 'o'), S('o', 'l'), S('e', 'a'), S('n', 0)};
static const uint32_t __string_231_did_you_mean_bool[] = {22, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('b', 'o'), S('o', 'l'), S('\'', '?')};
static const uint32_t __string_232_Cyclic_reference_to_symbol[] = {28, S('C', 'y'), S('c', 'l'), S('i', 'c'), S(' ', 'r'), S('e', 'f'), S('e', 'r'), S('e', 'n'), S('c', 'e'), S(' ', 't'), S('o', ' '), S('s', 'y'), S('m', 'b'), S('o', 'l'), S(' ', '\'')};
static const uint32_t __string_233_here[] = {6, S('\'', ' '), S('h', 'e'), S('r', 'e')};
static const uint32_t __string_234_No_member_named[] = {17, S('N', 'o'), S(' ', 'm'), S('e', 'm'), S('b', 'e'), S('r', ' '), S('n', 'a'), S('m', 'e'), S('d', ' '), S('\'', 0)};
static const uint32_t __string_235_on_type[] = {11, S('\'', ' '), S('o', 'n'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_236_The_type[] = {10, S('T', 'h'), S('e', ' '), S('t', 'y'), S('p', 'e'), S(' ', '\'')};
static const uint32_t __string_237_has_no_members[] = {16, S('\'', ' '), S('h', 'a'), S('s', ' '), S('n', 'o'), S(' ', 'm'), S('e', 'm'), S('b', 'e'), S('r', 's')};
static const uint32_t __string_238_Cannot_call_value_of_type[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('a', 'l'), S('l', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('o', 'f'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_239_Not_enough_arguments_for_functio[] = {35, S('N', 'o'), S('t', ' '), S('e', 'n'), S('o', 'u'), S('g', 'h'), S(' ', 'a'), S('r', 'g'), S('u', 'm'), S('e', 'n'), S('t', 's'), S(' ', 'f'), S('o', 'r'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('\'', 0)};
static const uint32_t __string_240_Too_many_arguments_for_function[] = {33, S('T', 'o'), S('o', ' '), S('m', 'a'), S('n', 'y'), S(' ', 'a'), S('r', 'g'), S('u', 'm'), S('e', 'n'), S('t', 's'), S(' ', 'f'), S('o', 'r'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('\'', 0)};
static const uint32_t __string_241_Unexpected_return_value_in_funct[] = {52, S('U', 'n'), S('e', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('i', 'n'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S('i', 'n'), S('g', ' '), S('\'', 'v'), S('o', 'i'), S('d', '\'')};
static const uint32_t __string_242_Expected_return_value_in_functio[] = {45, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('i', 'n'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S('i', 'n'), S('g', ' '), S('\'', 0)};
static const uint32_t __string_243_Type[] = {6, S('T', 'y'), S('p', 'e'), S(' ', '\'')};
static const uint32_t __string_244_is_not_the_same_as_type[] = {27, S('\'', ' '), S('i', 's'), S(' ', 'n'), S('o', 't'), S(' ', 't'), S('h', 'e'), S(' ', 's'), S('a', 'm'), S('e', ' '), S('a', 's'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_245[] = {3, S('[', ']'), S('=', 0)};
static const uint32_t __string_246_Cannot_index_into_type[] = {24, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'i'), S('n', 'd'), S('e', 'x'), S(' ', 'i'), S('n', 't'), S('o', ' '), S('t', 'y'), S('p', 'e'), S(' ', '\'')};
static const uint32_t __string_247_Cannot_construct_type[] = {23, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('o', 'n'), S('s', 't'), S('r', 'u'), S('c', 't'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_248_Constructors_with_arguments_are[] = {49, S('C', 'o'), S('n', 's'), S('t', 'r'), S('u', 'c'), S('t', 'o'), S('r', 's'), S(' ', 'w'), S('i', 't'), S('h', ' '), S('a', 'r'), S('g', 'u'), S('m', 'e'), S('n', 't'), S('s', ' '), S('a', 'r'), S('e', ' '), S('n', 'o'), S('t', ' '), S('s', 'u'), S('p', 'p'), S('o', 'r'), S('t', 'e'), S('d', ' '), S('y', 'e'), S('t', 0)};
static const uint32_t __string_249_Cannot_use_pointers_when_compili[] = {48, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 'p'), S('o', 'i'), S('n', 't'), S('e', 'r'), S('s', ' '), S('w', 'h'), S('e', 'n'), S(' ', 'c'), S('o', 'm'), S('p', 'i'), S('l', 'i'), S('n', 'g'), S(' ', 't'), S('o', ' '), S('J', 'a'), S('v', 'a'), S('S', 'c'), S('r', 'i'), S('p', 't')};
static const uint32_t __string_250_Cannot_use_pointers_outside_an[] = {45, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 'p'), S('o', 'i'), S('n', 't'), S('e', 'r'), S('s', ' '), S('o', 'u'), S('t', 's'), S('i', 'd'), S('e', ' '), S('a', 'n'), S(' ', '\''), S('u', 'n'), S('s', 'a'), S('f', 'e'), S('\'', ' '), S('b', 'l'), S('o', 'c'), S('k', 0)};
static const uint32_t __string_251_Cannot_create_a_pointer_to_non_i[] = {45, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('r', 'e'), S('a', 't'), S('e', ' '), S('a', ' '), S('p', 'o'), S('i', 'n'), S('t', 'e'), S('r', ' '), S('t', 'o'), S(' ', 'n'), S('o', 'n'), S('-', 'i'), S('n', 't'), S('e', 'g'), S('e', 'r'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_252_Cannot_dereference_type[] = {25, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'd'), S('e', 'r'), S('e', 'f'), S('e', 'r'), S('e', 'n'), S('c', 'e'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_253_The_address_of_operator_is_not_s[] = {40, S('T', 'h'), S('e', ' '), S('a', 'd'), S('d', 'r'), S('e', 's'), S('s', '-'), S('o', 'f'), S(' ', 'o'), S('p', 'e'), S('r', 'a'), S('t', 'o'), S('r', ' '), S('i', 's'), S(' ', 'n'), S('o', 't'), S(' ', 's'), S('u', 'p'), S('p', 'o'), S('r', 't'), S('e', 'd')};
static const uint32_t __string_254_Cannot_use_unary_operator[] = {27, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 'u'), S('n', 'a'), S('r', 'y'), S(' ', 'o'), S('p', 'e'), S('r', 'a'), S('t', 'o'), S('r', ' '), S('\'', 0)};
static const uint32_t __string_255_with_type[] = {13, S('\'', ' '), S('w', 'i'), S('t', 'h'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_256_Cannot_compare_type[] = {21, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('o', 'm'), S('p', 'a'), S('r', 'e'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_257_with_type[] = {13, S('\'', ' '), S('w', 'i'), S('t', 'h'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_258_This_operator_is_not_currently_s[] = {40, S('T', 'h'), S('i', 's'), S(' ', 'o'), S('p', 'e'), S('r', 'a'), S('t', 'o'), S('r', ' '), S('i', 's'), S(' ', 'n'), S('o', 't'), S(' ', 'c'), S('u', 'r'), S('r', 'e'), S('n', 't'), S('l', 'y'), S(' ', 's'), S('u', 'p'), S('p', 'o'), S('r', 't'), S('e', 'd')};
static const uint32_t __string_259[] = {2, S('=', '=')};
static const uint32_t __string_260[] = {1, S('>', 0)};
static const uint32_t __string_261[] = {1, S('<', 0)};
static const uint32_t __string_262_Cannot_compare_type[] = {21, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'c'), S('o', 'm'), S('p', 'a'), S('r', 'e'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_263_with_type[] = {13, S('\'', ' '), S('w', 'i'), S('t', 'h'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_264_Cannot_use_binary_operator[] = {28, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'u'), S('s', 'e'), S(' ', 'b'), S('i', 'n'), S('a', 'r'), S('y', ' '), S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\'')};
static const uint32_t __string_265_with_type[] = {13, S('\'', ' '), S('w', 'i'), S('t', 'h'), S(' ', 't'), S('y', 'p'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_266_native[] = {8, S('<', 'n'), S('a', 't'), S('i', 'v'), S('e', '>')};
static const uint32_t __string_267_C[] = {1, S('C', 0)};
static const uint32_t __string_268_JS[] = {2, S('J', 'S')};
static const uint32_t __string_269_WASM[] = {4, S('W', 'A'), S('S', 'M')};
static const uint32_t __string_270_error[] = {7, S('<', 'e'), S('r', 'r'), S('o', 'r'), S('>', 0)};
static const uint32_t __string_271_null[] = {4, S('n', 'u'), S('l', 'l')};
static const uint32_t __string_272_void[] = {4, S('v', 'o'), S('i', 'd')};
static const uint32_t __string_273_lexing[] = {6, S('l', 'e'), S('x', 'i'), S('n', 'g')};
static const uint32_t __string_274_preprocessing[] = {13, S('p', 'r'), S('e', 'p'), S('r', 'o'), S('c', 'e'), S('s', 's'), S('i', 'n'), S('g', 0)};
static const uint32_t __string_275_parsing[] = {7, S('p', 'a'), S('r', 's'), S('i', 'n'), S('g', 0)};
static const uint32_t __string_276_checking[] = {8, S('c', 'h'), S('e', 'c'), S('k', 'i'), S('n', 'g')};
static const uint32_t __string_277_shaking[] = {7, S('s', 'h'), S('a', 'k'), S('i', 'n'), S('g', 0)};
static const uint32_t __string_278_emitting[] = {8, S('e', 'm'), S('i', 't'), S('t', 'i'), S('n', 'g')};
static const uint32_t __string_279[] = {2, S(' ', ' ')};
static const uint32_t __string_280[] = {2, S('{', '\n')};
static const uint32_t __string_281_0[] = {6, S(' ', '>'), S('>', '>'), S(' ', '0')};
static const uint32_t __string_282_0[] = {4, S(' ', '|'), S(' ', '0')};
static const uint32_t __string_283_0[] = {6, S(' ', '>'), S('>', '>'), S(' ', '0')};
static const uint32_t __string_284_0[] = {4, S(' ', '|'), S(' ', '0')};
static const uint32_t __string_285[] = {2, S(',', ' ')};
static const uint32_t __string_286___declare[] = {10, S('_', '_'), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', '.')};
static const uint32_t __string_287_null[] = {4, S('n', 'u'), S('l', 'l')};
static const uint32_t __string_288_true[] = {4, S('t', 'r'), S('u', 'e')};
static const uint32_t __string_289_false[] = {5, S('f', 'a'), S('l', 's'), S('e', 0)};
static const uint32_t __string_290[] = {4, S(' ', '<'), S('<', ' ')};
static const uint32_t __string_291[] = {4, S(' ', '>'), S('>', ' ')};
static const uint32_t __string_292[] = {3, S(' ', '&'), S(' ', 0)};
static const uint32_t __string_293_0[] = {4, S(' ', '|'), S(' ', '0')};
static const uint32_t __string_294_0[] = {6, S(' ', '>'), S('>', '>'), S(' ', '0')};
static const uint32_t __string_295[] = {3, S(' ', '?'), S(' ', 0)};
static const uint32_t __string_296[] = {3, S(' ', ':'), S(' ', 0)};
static const uint32_t __string_297_new[] = {4, S('n', 'e'), S('w', ' ')};
static const uint32_t __string_298[] = {2, S('(', ')')};
static const uint32_t __string_299[] = {1, S('!', 0)};
static const uint32_t __string_300[] = {1, S('~', 0)};
static const uint32_t __string_301[] = {1, S('-', 0)};
static const uint32_t __string_302[] = {1, S('+', 0)};
static const uint32_t __string_303[] = {2, S('+', '+')};
static const uint32_t __string_304[] = {2, S('-', '-')};
static const uint32_t __string_305[] = {2, S('+', '+')};
static const uint32_t __string_306[] = {2, S('-', '-')};
static const uint32_t __string_307[] = {3, S(' ', '+'), S(' ', 0)};
static const uint32_t __string_308[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_309[] = {3, S(' ', '&'), S(' ', 0)};
static const uint32_t __string_310[] = {3, S(' ', '|'), S(' ', 0)};
static const uint32_t __string_311[] = {3, S(' ', '^'), S(' ', 0)};
static const uint32_t __string_312[] = {3, S(' ', '/'), S(' ', 0)};
static const uint32_t __string_313[] = {5, S(' ', '='), S('=', '='), S(' ', 0)};
static const uint32_t __string_314[] = {3, S(' ', '>'), S(' ', 0)};
static const uint32_t __string_315[] = {4, S(' ', '>'), S('=', ' ')};
static const uint32_t __string_316[] = {3, S(' ', '<'), S(' ', 0)};
static const uint32_t __string_317[] = {4, S(' ', '<'), S('=', ' ')};
static const uint32_t __string_318[] = {4, S(' ', '&'), S('&', ' ')};
static const uint32_t __string_319[] = {4, S(' ', '|'), S('|', ' ')};
static const uint32_t __string_320[] = {5, S(' ', '!'), S('=', '='), S(' ', 0)};
static const uint32_t __string_321[] = {3, S(' ', '%'), S(' ', 0)};
static const uint32_t __string_322[] = {4, S(' ', '<'), S('<', ' ')};
static const uint32_t __string_323[] = {5, S(' ', '>'), S('>', '>'), S(' ', 0)};
static const uint32_t __string_324[] = {4, S(' ', '>'), S('>', ' ')};
static const uint32_t __string_325[] = {3, S(' ', '-'), S(' ', 0)};
static const uint32_t __string_326___imul[] = {7, S('_', '_'), S('i', 'm'), S('u', 'l'), S('(', 0)};
static const uint32_t __string_327[] = {2, S(',', ' ')};
static const uint32_t __string_328_0[] = {6, S(' ', '>'), S('>', '>'), S(' ', '0')};
static const uint32_t __string_329_prototype[] = {11, S('.', 'p'), S('r', 'o'), S('t', 'o'), S('t', 'y'), S('p', 'e'), S('.', 0)};
static const uint32_t __string_330_function[] = {11, S(' ', '='), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', 0)};
static const uint32_t __string_331_var[] = {4, S('v', 'a'), S('r', ' ')};
static const uint32_t __string_332___extern[] = {12, S(' ', '='), S(' ', '_'), S('_', 'e'), S('x', 't'), S('e', 'r'), S('n', '.')};
static const uint32_t __string_333_function[] = {11, S(' ', '='), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', 0)};
static const uint32_t __string_334_function[] = {9, S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 0)};
static const uint32_t __string_335[] = {2, S(',', ' ')};
static const uint32_t __string_336[] = {2, S(')', ' ')};
static const uint32_t __string_337[] = {2, S(';', '\n')};
static const uint32_t __string_338[] = {1, S('\n', 0)};
static const uint32_t __string_339_if[] = {4, S('i', 'f'), S(' ', '(')};
static const uint32_t __string_340[] = {2, S(')', ' ')};
static const uint32_t __string_341[] = {2, S('\n', '\n')};
static const uint32_t __string_342_else[] = {5, S('e', 'l'), S('s', 'e'), S(' ', 0)};
static const uint32_t __string_343_while[] = {7, S('w', 'h'), S('i', 'l'), S('e', ' '), S('(', 0)};
static const uint32_t __string_344[] = {2, S(')', ' ')};
static const uint32_t __string_345_break[] = {7, S('b', 'r'), S('e', 'a'), S('k', ';'), S('\n', 0)};
static const uint32_t __string_346_continue[] = {10, S('c', 'o'), S('n', 't'), S('i', 'n'), S('u', 'e'), S(';', '\n')};
static const uint32_t __string_347[] = {2, S(';', '\n')};
static const uint32_t __string_348_return[] = {7, S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 0)};
static const uint32_t __string_349[] = {2, S(';', '\n')};
static const uint32_t __string_350_return[] = {8, S('r', 'e'), S('t', 'u'), S('r', 'n'), S(';', '\n')};
static const uint32_t __string_351_var[] = {4, S('v', 'a'), S('r', ' ')};
static const uint32_t __string_352[] = {2, S(',', ' ')};
static const uint32_t __string_353[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_354[] = {2, S(';', '\n')};
static const uint32_t __string_355_function[] = {9, S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 0)};
static const uint32_t __string_356[] = {5, S('(', ')'), S(' ', '{'), S('\n', 0)};
static const uint32_t __string_357_this[] = {5, S('t', 'h'), S('i', 's'), S('.', 0)};
static const uint32_t __string_358[] = {3, S(' ', '='), S(' ', 0)};
static const uint32_t __string_359[] = {2, S(';', '\n')};
static const uint32_t __string_360[] = {2, S('}', '\n')};
static const uint32_t __string_361___extern[] = {9, S('_', '_'), S('e', 'x'), S('t', 'e'), S('r', 'n'), S('.', 0)};
static const uint32_t __string_362[] = {5, S(' ', '='), S(' ', '{'), S('\n', 0)};
static const uint32_t __string_363[] = {2, S(':', ' ')};
static const uint32_t __string_364[] = {2, S(',', '\n')};
static const uint32_t __string_365[] = {1, S('\n', 0)};
static const uint32_t __string_366[] = {3, S('}', ';'), S('\n', 0)};
static const uint32_t __string_367_function___declare___extern[] = {33, S('(', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', '('), S('_', '_'), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ','), S(' ', '_'), S('_', 'e'), S('x', 't'), S('e', 'r'), S('n', ')'), S(' ', '{'), S('\n', 0)};
static const uint32_t __string_368_var___imul_Math_imul_functi[] = {43, S('v', 'a'), S('r', ' '), S('_', '_'), S('i', 'm'), S('u', 'l'), S(' ', '='), S(' ', 'M'), S('a', 't'), S('h', '.'), S('i', 'm'), S('u', 'l'), S(' ', '|'), S('|', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S('(', 'a'), S(',', ' '), S('b', ')'), S(' ', '{'), S('\n', 0)};
static const uint32_t __string_369_return_a_b_16_16[] = {53, S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '('), S('a', ' '), S('*', ' '), S('(', 'b'), S(' ', '>'), S('>', '>'), S(' ', '1'), S('6', ')'), S(' ', '<'), S('<', ' '), S('1', '6'), S(')', ' '), S('+', ' '), S('a', ' '), S('*', ' '), S('(', 'b'), S(' ', '&'), S(' ', '6'), S('5', '5'), S('3', '5'), S(')', ' '), S('|', ' '), S('0', ';'), S('\n', 0)};
static const uint32_t __string_370[] = {3, S('}', ';'), S('\n', 0)};
static const uint32_t __string_371[] = {3, S('}', '('), S('\n', 0)};
static const uint32_t __string_372_typeof_global_undefined[] = {47, S('t', 'y'), S('p', 'e'), S('o', 'f'), S(' ', 'g'), S('l', 'o'), S('b', 'a'), S('l', ' '), S('!', '='), S('=', ' '), S('\'', 'u'), S('n', 'd'), S('e', 'f'), S('i', 'n'), S('e', 'd'), S('\'', ' '), S('?', ' '), S('g', 'l'), S('o', 'b'), S('a', 'l'), S(' ', ':'), S(' ', 't'), S('h', 'i'), S('s', ','), S('\n', 0)};
static const uint32_t __string_373_typeof_exports_undefined[] = {48, S('t', 'y'), S('p', 'e'), S('o', 'f'), S(' ', 'e'), S('x', 'p'), S('o', 'r'), S('t', 's'), S(' ', '!'), S('=', '='), S(' ', '\''), S('u', 'n'), S('d', 'e'), S('f', 'i'), S('n', 'e'), S('d', '\''), S(' ', '?'), S(' ', 'e'), S('x', 'p'), S('o', 'r'), S('t', 's'), S(' ', ':'), S(' ', 't'), S('h', 'i'), S('s', '\n')};
static const uint32_t __string_374[] = {4, S(')', ')'), S(';', '\n')};
static const uint32_t __string_375_end_of_file[] = {11, S('e', 'n'), S('d', ' '), S('o', 'f'), S(' ', 'f'), S('i', 'l'), S('e', 0)};
static const uint32_t __string_376_character_literal[] = {17, S('c', 'h'), S('a', 'r'), S('a', 'c'), S('t', 'e'), S('r', ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', 0)};
static const uint32_t __string_377_identifier[] = {10, S('i', 'd'), S('e', 'n'), S('t', 'i'), S('f', 'i'), S('e', 'r')};
static const uint32_t __string_378_integer_literal[] = {15, S('i', 'n'), S('t', 'e'), S('g', 'e'), S('r', ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', 0)};
static const uint32_t __string_379_string_literal[] = {14, S('s', 't'), S('r', 'i'), S('n', 'g'), S(' ', 'l'), S('i', 't'), S('e', 'r'), S('a', 'l')};
static const uint32_t __string_380[] = {3, S('\'', '='), S('\'', 0)};
static const uint32_t __string_381[] = {3, S('\'', '&'), S('\'', 0)};
static const uint32_t __string_382[] = {3, S('\'', '|'), S('\'', 0)};
static const uint32_t __string_383[] = {3, S('\'', '^'), S('\'', 0)};
static const uint32_t __string_384[] = {3, S('\'', ':'), S('\'', 0)};
static const uint32_t __string_385[] = {3, S('\'', ','), S('\'', 0)};
static const uint32_t __string_386[] = {3, S('\'', '~'), S('\'', 0)};
static const uint32_t __string_387[] = {3, S('\'', '/'), S('\'', 0)};
static const uint32_t __string_388[] = {3, S('\'', '.'), S('\'', 0)};
static const uint32_t __string_389[] = {4, S('\'', '='), S('=', '\'')};
static const uint32_t __string_390[] = {4, S('\'', '*'), S('*', '\'')};
static const uint32_t __string_391[] = {3, S('\'', '>'), S('\'', 0)};
static const uint32_t __string_392[] = {4, S('\'', '>'), S('=', '\'')};
static const uint32_t __string_393[] = {3, S('\'', '{'), S('\'', 0)};
static const uint32_t __string_394[] = {3, S('\'', '['), S('\'', 0)};
static const uint32_t __string_395[] = {3, S('\'', '('), S('\'', 0)};
static const uint32_t __string_396[] = {3, S('\'', '<'), S('\'', 0)};
static const uint32_t __string_397[] = {4, S('\'', '<'), S('=', '\'')};
static const uint32_t __string_398[] = {4, S('\'', '&'), S('&', '\'')};
static const uint32_t __string_399[] = {4, S('\'', '|'), S('|', '\'')};
static const uint32_t __string_400[] = {3, S('\'', '-'), S('\'', 0)};
static const uint32_t __string_401[] = {4, S('\'', '-'), S('-', '\'')};
static const uint32_t __string_402[] = {3, S('\'', '*'), S('\'', 0)};
static const uint32_t __string_403[] = {3, S('\'', '!'), S('\'', 0)};
static const uint32_t __string_404[] = {4, S('\'', '!'), S('=', '\'')};
static const uint32_t __string_405[] = {3, S('\'', '+'), S('\'', 0)};
static const uint32_t __string_406[] = {4, S('\'', '+'), S('+', '\'')};
static const uint32_t __string_407[] = {3, S('\'', '?'), S('\'', 0)};
static const uint32_t __string_408[] = {3, S('\'', '%'), S('\'', 0)};
static const uint32_t __string_409[] = {3, S('\'', '}'), S('\'', 0)};
static const uint32_t __string_410[] = {3, S('\'', ']'), S('\'', 0)};
static const uint32_t __string_411[] = {3, S('\'', ')'), S('\'', 0)};
static const uint32_t __string_412[] = {3, S('\'', ';'), S('\'', 0)};
static const uint32_t __string_413[] = {4, S('\'', '<'), S('<', '\'')};
static const uint32_t __string_414[] = {4, S('\'', '>'), S('>', '\'')};
static const uint32_t __string_415_alignof[] = {9, S('\'', 'a'), S('l', 'i'), S('g', 'n'), S('o', 'f'), S('\'', 0)};
static const uint32_t __string_416_as[] = {4, S('\'', 'a'), S('s', '\'')};
static const uint32_t __string_417_break[] = {7, S('\'', 'b'), S('r', 'e'), S('a', 'k'), S('\'', 0)};
static const uint32_t __string_418_class[] = {7, S('\'', 'c'), S('l', 'a'), S('s', 's'), S('\'', 0)};
static const uint32_t __string_419_const[] = {7, S('\'', 'c'), S('o', 'n'), S('s', 't'), S('\'', 0)};
static const uint32_t __string_420_continue[] = {10, S('\'', 'c'), S('o', 'n'), S('t', 'i'), S('n', 'u'), S('e', '\'')};
static const uint32_t __string_421_declare[] = {9, S('\'', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S('\'', 0)};
static const uint32_t __string_422_else[] = {6, S('\'', 'e'), S('l', 's'), S('e', '\'')};
static const uint32_t __string_423_enum[] = {6, S('\'', 'e'), S('n', 'u'), S('m', '\'')};
static const uint32_t __string_424_export[] = {8, S('\'', 'e'), S('x', 'p'), S('o', 'r'), S('t', '\'')};
static const uint32_t __string_425_extends[] = {9, S('\'', 'e'), S('x', 't'), S('e', 'n'), S('d', 's'), S('\'', 0)};
static const uint32_t __string_426_extern[] = {8, S('\'', 'e'), S('x', 't'), S('e', 'r'), S('n', '\'')};
static const uint32_t __string_427_false[] = {7, S('\'', 'f'), S('a', 'l'), S('s', 'e'), S('\'', 0)};
static const uint32_t __string_428_function[] = {10, S('\'', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', '\'')};
static const uint32_t __string_429_if[] = {4, S('\'', 'i'), S('f', '\'')};
static const uint32_t __string_430_implements[] = {12, S('\'', 'i'), S('m', 'p'), S('l', 'e'), S('m', 'e'), S('n', 't'), S('s', '\'')};
static const uint32_t __string_431_import[] = {8, S('\'', 'i'), S('m', 'p'), S('o', 'r'), S('t', '\'')};
static const uint32_t __string_432_interface[] = {11, S('\'', 'i'), S('n', 't'), S('e', 'r'), S('f', 'a'), S('c', 'e'), S('\'', 0)};
static const uint32_t __string_433_let[] = {5, S('\'', 'l'), S('e', 't'), S('\'', 0)};
static const uint32_t __string_434_new[] = {5, S('\'', 'n'), S('e', 'w'), S('\'', 0)};
static const uint32_t __string_435_null[] = {6, S('\'', 'n'), S('u', 'l'), S('l', '\'')};
static const uint32_t __string_436_operator[] = {10, S('\'', 'o'), S('p', 'e'), S('r', 'a'), S('t', 'o'), S('r', '\'')};
static const uint32_t __string_437_private[] = {9, S('\'', 'p'), S('r', 'i'), S('v', 'a'), S('t', 'e'), S('\'', 0)};
static const uint32_t __string_438_protected[] = {11, S('\'', 'p'), S('r', 'o'), S('t', 'e'), S('c', 't'), S('e', 'd'), S('\'', 0)};
static const uint32_t __string_439_public[] = {8, S('\'', 'p'), S('u', 'b'), S('l', 'i'), S('c', '\'')};
static const uint32_t __string_440_return[] = {8, S('\'', 'r'), S('e', 't'), S('u', 'r'), S('n', '\'')};
static const uint32_t __string_441_sizeof[] = {8, S('\'', 's'), S('i', 'z'), S('e', 'o'), S('f', '\'')};
static const uint32_t __string_442_static[] = {8, S('\'', 's'), S('t', 'a'), S('t', 'i'), S('c', '\'')};
static const uint32_t __string_443_this[] = {6, S('\'', 't'), S('h', 'i'), S('s', '\'')};
static const uint32_t __string_444_true[] = {6, S('\'', 't'), S('r', 'u'), S('e', '\'')};
static const uint32_t __string_445_unsafe[] = {8, S('\'', 'u'), S('n', 's'), S('a', 'f'), S('e', '\'')};
static const uint32_t __string_446_var[] = {5, S('\'', 'v'), S('a', 'r'), S('\'', 0)};
static const uint32_t __string_447_while[] = {7, S('\'', 'w'), S('h', 'i'), S('l', 'e'), S('\'', 0)};
static const uint32_t __string_448_define[] = {9, S('\'', '#'), S('d', 'e'), S('f', 'i'), S('n', 'e'), S('\'', 0)};
static const uint32_t __string_449_elif[] = {7, S('\'', '#'), S('e', 'l'), S('i', 'f'), S('\'', 0)};
static const uint32_t __string_450_else[] = {7, S('\'', '#'), S('e', 'l'), S('s', 'e'), S('\'', 0)};
static const uint32_t __string_451_endif[] = {8, S('\'', '#'), S('e', 'n'), S('d', 'i'), S('f', '\'')};
static const uint32_t __string_452_error[] = {8, S('\'', '#'), S('e', 'r'), S('r', 'o'), S('r', '\'')};
static const uint32_t __string_453_if[] = {5, S('\'', '#'), S('i', 'f'), S('\'', 0)};
static const uint32_t __string_454_newline[] = {7, S('n', 'e'), S('w', 'l'), S('i', 'n'), S('e', 0)};
static const uint32_t __string_455_undef[] = {8, S('\'', '#'), S('u', 'n'), S('d', 'e'), S('f', '\'')};
static const uint32_t __string_456_warning[] = {10, S('\'', '#'), S('w', 'a'), S('r', 'n'), S('i', 'n'), S('g', '\'')};
static const uint32_t __string_457_as[] = {2, S('a', 's')};
static const uint32_t __string_458_if[] = {2, S('i', 'f')};
static const uint32_t __string_459_let[] = {3, S('l', 'e'), S('t', 0)};
static const uint32_t __string_460_new[] = {3, S('n', 'e'), S('w', 0)};
static const uint32_t __string_461_var[] = {3, S('v', 'a'), S('r', 0)};
static const uint32_t __string_462_else[] = {4, S('e', 'l'), S('s', 'e')};
static const uint32_t __string_463_enum[] = {4, S('e', 'n'), S('u', 'm')};
static const uint32_t __string_464_null[] = {4, S('n', 'u'), S('l', 'l')};
static const uint32_t __string_465_this[] = {4, S('t', 'h'), S('i', 's')};
static const uint32_t __string_466_true[] = {4, S('t', 'r'), S('u', 'e')};
static const uint32_t __string_467_break[] = {5, S('b', 'r'), S('e', 'a'), S('k', 0)};
static const uint32_t __string_468_class[] = {5, S('c', 'l'), S('a', 's'), S('s', 0)};
static const uint32_t __string_469_const[] = {5, S('c', 'o'), S('n', 's'), S('t', 0)};
static const uint32_t __string_470_false[] = {5, S('f', 'a'), S('l', 's'), S('e', 0)};
static const uint32_t __string_471_while[] = {5, S('w', 'h'), S('i', 'l'), S('e', 0)};
static const uint32_t __string_472_export[] = {6, S('e', 'x'), S('p', 'o'), S('r', 't')};
static const uint32_t __string_473_extern[] = {6, S('e', 'x'), S('t', 'e'), S('r', 'n')};
static const uint32_t __string_474_import[] = {6, S('i', 'm'), S('p', 'o'), S('r', 't')};
static const uint32_t __string_475_public[] = {6, S('p', 'u'), S('b', 'l'), S('i', 'c')};
static const uint32_t __string_476_return[] = {6, S('r', 'e'), S('t', 'u'), S('r', 'n')};
static const uint32_t __string_477_sizeof[] = {6, S('s', 'i'), S('z', 'e'), S('o', 'f')};
static const uint32_t __string_478_static[] = {6, S('s', 't'), S('a', 't'), S('i', 'c')};
static const uint32_t __string_479_unsafe[] = {6, S('u', 'n'), S('s', 'a'), S('f', 'e')};
static const uint32_t __string_480_alignof[] = {7, S('a', 'l'), S('i', 'g'), S('n', 'o'), S('f', 0)};
static const uint32_t __string_481_declare[] = {7, S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', 0)};
static const uint32_t __string_482_extends[] = {7, S('e', 'x'), S('t', 'e'), S('n', 'd'), S('s', 0)};
static const uint32_t __string_483_private[] = {7, S('p', 'r'), S('i', 'v'), S('a', 't'), S('e', 0)};
static const uint32_t __string_484_continue[] = {8, S('c', 'o'), S('n', 't'), S('i', 'n'), S('u', 'e')};
static const uint32_t __string_485_function[] = {8, S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n')};
static const uint32_t __string_486_implements[] = {10, S('i', 'm'), S('p', 'l'), S('e', 'm'), S('e', 'n'), S('t', 's')};
static const uint32_t __string_487_interface[] = {9, S('i', 'n'), S('t', 'e'), S('r', 'f'), S('a', 'c'), S('e', 0)};
static const uint32_t __string_488_protected[] = {9, S('p', 'r'), S('o', 't'), S('e', 'c'), S('t', 'e'), S('d', 0)};
static const uint32_t __string_489_Invalid_integer_literal[] = {26, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('i', 'n'), S('t', 'e'), S('g', 'e'), S('r', ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', ':'), S(' ', '\'')};
static const uint32_t __string_490_Unterminated_character_literal[] = {30, S('U', 'n'), S('t', 'e'), S('r', 'm'), S('i', 'n'), S('a', 't'), S('e', 'd'), S(' ', 'c'), S('h', 'a'), S('r', 'a'), S('c', 't'), S('e', 'r'), S(' ', 'l'), S('i', 't'), S('e', 'r'), S('a', 'l')};
static const uint32_t __string_491_Unterminated_template_literal[] = {29, S('U', 'n'), S('t', 'e'), S('r', 'm'), S('i', 'n'), S('a', 't'), S('e', 'd'), S(' ', 't'), S('e', 'm'), S('p', 'l'), S('a', 't'), S('e', ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', 0)};
static const uint32_t __string_492_Unterminated_string_literal[] = {27, S('U', 'n'), S('t', 'e'), S('r', 'm'), S('i', 'n'), S('a', 't'), S('e', 'd'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', 0)};
static const uint32_t __string_493_Unterminated_multi_line_comment[] = {31, S('U', 'n'), S('t', 'e'), S('r', 'm'), S('i', 'n'), S('a', 't'), S('e', 'd'), S(' ', 'm'), S('u', 'l'), S('t', 'i'), S('-', 'l'), S('i', 'n'), S('e', ' '), S('c', 'o'), S('m', 'm'), S('e', 'n'), S('t', 0)};
static const uint32_t __string_494_Use_instead_of[] = {25, S('U', 's'), S('e', ' '), S('\'', '!'), S('=', '\''), S(' ', 'i'), S('n', 's'), S('t', 'e'), S('a', 'd'), S(' ', 'o'), S('f', ' '), S('\'', '!'), S('=', '='), S('\'', 0)};
static const uint32_t __string_495_Use_instead_of[] = {25, S('U', 's'), S('e', ' '), S('\'', '='), S('=', '\''), S(' ', 'i'), S('n', 's'), S('t', 'e'), S('a', 'd'), S(' ', 'o'), S('f', ' '), S('\'', '='), S('=', '='), S('\'', 0)};
static const uint32_t __string_496_define[] = {7, S('#', 'd'), S('e', 'f'), S('i', 'n'), S('e', 0)};
static const uint32_t __string_497_elif[] = {5, S('#', 'e'), S('l', 'i'), S('f', 0)};
static const uint32_t __string_498_else[] = {5, S('#', 'e'), S('l', 's'), S('e', 0)};
static const uint32_t __string_499_endif[] = {6, S('#', 'e'), S('n', 'd'), S('i', 'f')};
static const uint32_t __string_500_error[] = {6, S('#', 'e'), S('r', 'r'), S('o', 'r')};
static const uint32_t __string_501_if[] = {3, S('#', 'i'), S('f', 0)};
static const uint32_t __string_502_undef[] = {6, S('#', 'u'), S('n', 'd'), S('e', 'f')};
static const uint32_t __string_503_warning[] = {8, S('#', 'w'), S('a', 'r'), S('n', 'i'), S('n', 'g')};
static const uint32_t __string_504[] = {1, S('#', 0)};
static const uint32_t __string_505_Invalid_preprocessor_token[] = {28, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('p', 'r'), S('e', 'p'), S('r', 'o'), S('c', 'e'), S('s', 's'), S('o', 'r'), S(' ', 't'), S('o', 'k'), S('e', 'n'), S(' ', '\'')};
static const uint32_t __string_506_ifdef[] = {6, S('#', 'i'), S('f', 'd'), S('e', 'f')};
static const uint32_t __string_507_did_you_mean_if[] = {21, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('#', 'i'), S('f', '\''), S('?', 0)};
static const uint32_t __string_508_elsif[] = {6, S('#', 'e'), S('l', 's'), S('i', 'f')};
static const uint32_t __string_509_elseif[] = {7, S('#', 'e'), S('l', 's'), S('e', 'i'), S('f', 0)};
static const uint32_t __string_510_did_you_mean_elif[] = {23, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('#', 'e'), S('l', 'i'), S('f', '\''), S('?', 0)};
static const uint32_t __string_511_end[] = {4, S('#', 'e'), S('n', 'd')};
static const uint32_t __string_512_did_you_mean_endif[] = {24, S(',', ' '), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\''), S('#', 'e'), S('n', 'd'), S('i', 'f'), S('\'', '?')};
static const uint32_t __string_513_Expected_newline_before[] = {24, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 'n'), S('e', 'w'), S('l', 'i'), S('n', 'e'), S(' ', 'b'), S('e', 'f'), S('o', 'r'), S('e', ' ')};
static const uint32_t __string_514_Syntax_error[] = {15, S('S', 'y'), S('n', 't'), S('a', 'x'), S(' ', 'e'), S('r', 'r'), S('o', 'r'), S(':', ' '), S('\'', 0)};
static const uint32_t __string_515_if_WASM_These_will_be_fi[] = {7319, S('\n', '#'), S('i', 'f'), S(' ', 'W'), S('A', 'S'), S('M', '\n'), S('\n', ' '), S(' ', '/'), S('/', ' '), S('T', 'h'), S('e', 's'), S('e', ' '), S('w', 'i'), S('l', 'l'), S(' ', 'b'), S('e', ' '), S('f', 'i'), S('l', 'l'), S('e', 'd'), S(' ', 'i'), S('n', ' '), S('b', 'y'), S(' ', 't'), S('h', 'e'), S(' ', 'W'), S('e', 'b'), S('A', 's'), S('s', 'e'), S('m', 'b'), S('l', 'y'), S(' ', 'c'), S('o', 'd'), S('e', ' '), S('g', 'e'), S('n', 'e'), S('r', 'a'), S('t', 'o'), S('r', '\n'), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', 'v'), S('a', 'r'), S(' ', 'c'), S('u', 'r'), S('r', 'e'), S('n', 't'), S('H', 'e'), S('a', 'p'), S('P', 'o'), S('i', 'n'), S('t', 'e'), S('r', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '='), S(' ', 'n'), S('u', 'l'), S('l', ';'), S('\n', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('v', 'a'), S('r', ' '), S('o', 'r'), S('i', 'g'), S('i', 'n'), S('a', 'l'), S('H', 'e'), S('a', 'p'), S('P', 'o'), S('i', 'n'), S('t', 'e'), S('r', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '='), S(' ', 'n'), S('u', 'l'), S('l', ';'), S('\n', '\n'), S(' ', ' '), S('e', 'x'), S('t', 'e'), S('r', 'n'), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'm'), S('a', 'l'), S('l', 'o'), S('c', '('), S('s', 'i'), S('z', 'e'), S('O', 'f'), S(':', ' '), S('u', 'i'), S('n', 't'), S(')', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('A', 'l'), S('i', 'g'), S('n', ' '), S('a', 'l'), S('l', ' '), S('a', 'l'), S('l', 'o'), S('c', 'a'), S('t', 'i'), S('o', 'n'), S('s', ' '), S('t', 'o'), S(' ', '8'), S(' ', 'b'), S('y', 't'), S('e', 's'), S('\n', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'o'), S('f', 'f'), S('s', 'e'), S('t', ' '), S('=', ' '), S('(', '('), S('c', 'u'), S('r', 'r'), S('e', 'n'), S('t', 'H'), S('e', 'a'), S('p', 'P'), S('o', 'i'), S('n', 't'), S('e', 'r'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(' ', '+'), S(' ', '7'), S(')', ' '), S('&', ' '), S('~', '7'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(')', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('s', 'i'), S('z', 'e'), S('O', 'f'), S(' ', '='), S(' ', '('), S('s', 'i'), S('z', 'e'), S('O', 'f'), S(' ', '+'), S(' ', '7'), S(')', ' '), S('&', ' '), S('~', '7'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('U', 's'), S('e', ' '), S('a', ' '), S('s', 'i'), S('m', 'p'), S('l', 'e'), S(' ', 'b'), S('u', 'm'), S('p', ' '), S('a', 'l'), S('l', 'o'), S('c', 'a'), S('t', 'o'), S('r', ' '), S('f', 'o'), S('r', ' '), S('n', 'o'), S('w', '\n'), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('l', 'i'), S('m', 'i'), S('t', ' '), S('=', ' '), S('o', 'f'), S('f', 's'), S('e', 't'), S(' ', '+'), S(' ', 's'), S('i', 'z'), S('e', 'O'), S('f', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'c'), S('u', 'r'), S('r', 'e'), S('n', 't'), S('H', 'e'), S('a', 'p'), S('P', 'o'), S('i', 'n'), S('t', 'e'), S('r', ' '), S('=', ' '), S('l', 'i'), S('m', 'i'), S('t', ';'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'M'), S('a', 'k'), S('e', ' '), S('s', 'u'), S('r', 'e'), S(' ', 't'), S('h', 'e'), S(' ', 'm'), S('e', 'm'), S('o', 'r'), S('y', ' '), S('s', 't'), S('a', 'r'), S('t', 's'), S(' ', 'o'), S('f', 'f'), S(' ', 'a'), S('t', ' '), S('z', 'e'), S('r', 'o'), S('\n', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'p'), S('t', 'r'), S(' ', '='), S(' ', 'o'), S('f', 'f'), S('s', 'e'), S('t', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('p', 't'), S('r', ' '), S('<', ' '), S('l', 'i'), S('m', 'i'), S('t', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('(', 'p'), S('t', 'r'), S(' ', 'a'), S('s', ' '), S('*', 'i'), S('n', 't'), S(')', ' '), S('=', ' '), S('0', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'p'), S('t', 'r'), S(' ', '='), S(' ', 'p'), S('t', 'r'), S(' ', '+'), S(' ', '4'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('o', 'f'), S('f', 's'), S('e', 't'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'p'), S('y', '('), S('t', 'a'), S('r', 'g'), S('e', 't'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ','), S(' ', 's'), S('o', 'u'), S('r', 'c'), S('e', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(',', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(':', ' '), S('u', 'i'), S('n', 't'), S(')', ':'), S(' ', 'v'), S('o', 'i'), S('d', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'N'), S('o', '-'), S('o', 'p'), S(' ', 'i'), S('f', ' '), S('e', 'i'), S('t', 'h'), S('e', 'r'), S(' ', 'o'), S('f', ' '), S('t', 'h'), S('e', ' '), S('i', 'n'), S('p', 'u'), S('t', 's'), S(' ', 'a'), S('r', 'e'), S(' ', 'n'), S('u', 'l'), S('l', '\n'), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', '='), S('=', ' '), S('n', 'u'), S('l', 'l'), S(' ', '|'), S('|', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '='), S('=', ' '), S('n', 'u'), S('l', 'l'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('O', 'p'), S('t', 'i'), S('m', 'i'), S('z', 'e'), S('d', ' '), S('a', 'l'), S('i', 'g'), S('n', 'e'), S('d', ' '), S('c', 'o'), S('p', 'y'), S('\n', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('>', '='), S(' ', '1'), S('6', ' '), S('&', '&'), S(' ', '('), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(')', ' '), S('%', ' '), S('4', ' '), S('=', '='), S(' ', '('), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(')', ' '), S('%', ' '), S('4', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('P', 'i'), S('c', 'k'), S(' ', 'o'), S('f', 'f'), S(' ', 't'), S('h', 'e'), S(' ', 'b'), S('e', 'g'), S('i', 'n'), S('n', 'i'), S('n', 'g'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('(', 't'), S('a', 'r'), S('g', 'e'), S('t', ' '), S('a', 's'), S(' ', 'u'), S('i', 'n'), S('t', ')'), S(' ', '%'), S(' ', '4'), S(' ', '!'), S('=', ' '), S('0', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '='), S(' ', '*'), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '='), S(' ', 't'), S('a', 'r'), S('g', 'e'), S('t', ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 's'), S('o', 'u'), S('r', 'c'), S('e', ' '), S('=', ' '), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('-', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'P'), S('i', 'c'), S('k', ' '), S('o', 'f'), S('f', ' '), S('t', 'h'), S('e', ' '), S('e', 'n'), S('d', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('w', 'h'), S('i', 'l'), S('e', ' '), S('(', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('%', ' '), S('4', ' '), S('!', '='), S(' ', '0'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('-', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('(', 't'), S('a', 'r'), S('g', 'e'), S('t', ' '), S('+', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(')', ' '), S('=', ' '), S('*', '('), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', '+'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('Z', 'i'), S('p', ' '), S('o', 'v'), S('e', 'r'), S(' ', 't'), S('h', 'e'), S(' ', 'm'), S('i', 'd'), S('d', 'l'), S('e', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('e', 'n'), S('d', ' '), S('=', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '+'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '<'), S(' ', 'e'), S('n', 'd'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('*', '('), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', 'a'), S('s', ' '), S('*', 'i'), S('n', 't'), S(')', ' '), S('=', ' '), S('*', '('), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', 'a'), S('s', ' '), S('*', 'i'), S('n', 't'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 't'), S('a', 'r'), S('g', 'e'), S('t', ' '), S('=', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '+'), S(' ', '4'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', '='), S(' ', 's'), S('o', 'u'), S('r', 'c'), S('e', ' '), S('+', ' '), S('4', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'S'), S('l', 'o'), S('w', ' '), S('u', 'n'), S('a', 'l'), S('i', 'g'), S('n', 'e'), S('d', ' '), S('c', 'o'), S('p', 'y'), S('\n', ' '), S(' ', ' '), S(' ', 'e'), S('l', 's'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('e', 'n'), S('d', ' '), S('=', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '+'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '<'), S(' ', 'e'), S('n', 'd'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('*', 't'), S('a', 'r'), S('g', 'e'), S('t', ' '), S('=', ' '), S('*', 's'), S('o', 'u'), S('r', 'c'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 't'), S('a', 'r'), S('g', 'e'), S('t', ' '), S('=', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('s', 'o'), S('u', 'r'), S('c', 'e'), S(' ', '='), S(' ', 's'), S('o', 'u'), S('r', 'c'), S('e', ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('m', 'e'), S('m', 'c'), S('m', 'p'), S('(', 'a'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ','), S(' ', 'b'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ','), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ':'), S(' ', 'u'), S('i', 'n'), S('t', ')'), S(':', ' '), S('i', 'n'), S('t', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'N'), S('o', '-'), S('o', 'p'), S(' ', 'i'), S('f', ' '), S('e', 'i'), S('t', 'h'), S('e', 'r'), S(' ', 'o'), S('f', ' '), S('t', 'h'), S('e', ' '), S('i', 'n'), S('p', 'u'), S('t', 's'), S(' ', 'a'), S('r', 'e'), S(' ', 'n'), S('u', 'l'), S('l', '\n'), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('a', ' '), S('=', '='), S(' ', 'n'), S('u', 'l'), S('l', ' '), S('|', '|'), S(' ', 'b'), S(' ', '='), S('=', ' '), S('n', 'u'), S('l', 'l'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('R', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('h', 'e'), S(' ', 'f'), S('i', 'r'), S('s', 't'), S(' ', 'n'), S('o', 'n'), S('-', 'z'), S('e', 'r'), S('o', ' '), S('d', 'i'), S('f', 'f'), S('e', 'r'), S('e', 'n'), S('c', 'e'), S('\n', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '>'), S(' ', '0'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('d', 'e'), S('l', 't'), S('a', ' '), S('=', ' '), S('*', 'a'), S(' ', 'a'), S('s', ' '), S('i', 'n'), S('t', ' '), S('-', ' '), S('*', 'b'), S(' ', 'a'), S('s', ' '), S('i', 'n'), S('t', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 'd'), S('e', 'l'), S('t', 'a'), S(' ', '!'), S('=', ' '), S('0', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('d', 'e'), S('l', 't'), S('a', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'a'), S(' ', '='), S(' ', 'a'), S(' ', '+'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('b', ' '), S('=', ' '), S('b', ' '), S('+', ' '), S('1', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('=', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '-'), S(' ', '1'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('B', 'o'), S('t', 'h'), S(' ', 'i'), S('n', 'p'), S('u', 't'), S('s', ' '), S('a', 'r'), S('e', ' '), S('i', 'd'), S('e', 'n'), S('t', 'i'), S('c', 'a'), S('l', '\n'), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '0'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', '#'), S('e', 'l'), S('i', 'f'), S(' ', 'C'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('m', 'a'), S('l', 'l'), S('o', 'c'), S('(', 's'), S('i', 'z'), S('e', 'O'), S('f', ':'), S(' ', 'u'), S('i', 'n'), S('t', ')'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ';'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'p'), S('y', '('), S('t', 'a'), S('r', 'g'), S('e', 't'), S(':', ' '), S('*', 'b'), S('y', 't'), S('e', ','), S(' ', 's'), S('o', 'u'), S('r', 'c'), S('e', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(',', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(':', ' '), S('u', 'i'), S('n', 't'), S(')', ':'), S(' ', 'v'), S('o', 'i'), S('d', ';'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'm'), S('p', '('), S('a', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(',', ' '), S('b', ':'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(',', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(':', ' '), S('u', 'i'), S('n', 't'), S(')', ':'), S(' ', 'i'), S('n', 't'), S(';', '\n'), S('\n', '#'), S('e', 'n'), S('d', 'i'), S('f', '\n'), S('\n', '#'), S('i', 'f'), S(' ', 'W'), S('A', 'S'), S('M', ' '), S('|', '|'), S(' ', 'C'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('b', 'o'), S('o', 'l'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('h', 'i'), S('s', ' '), S('?', ' '), S('"', 't'), S('r', 'u'), S('e', '"'), S(' ', ':'), S(' ', '"'), S('f', 'a'), S('l', 's'), S('e', '"'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 's'), S('b', 'y'), S('t', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('i', 'n'), S('t', ')'), S('.', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('b', 'y'), S('t', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(')', '.'), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('i', 'n'), S('t', ')'), S('.', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(')', '.'), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 'i'), S('n', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'S'), S('p', 'e'), S('c', 'i'), S('a', 'l'), S('-', 'c'), S('a', 's'), S('e', ' '), S('t', 'h'), S('i', 's'), S(' ', 't'), S('o', ' '), S('k', 'e'), S('e', 'p'), S(' ', 't'), S('h', 'e'), S(' ', 'r'), S('e', 's'), S('t', ' '), S('o', 'f'), S(' ', 't'), S('h', 'e'), S(' ', 'c'), S('o', 'd'), S('e', ' '), S('s', 'i'), S('m', 'p'), S('l', 'e'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 't'), S('h', 'i'), S('s', ' '), S('=', '='), S(' ', '-'), S('2', '1'), S('4', '7'), S('4', '8'), S('3', '6'), S('4', '8'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '"'), S('-', '2'), S('1', '4'), S('7', '4'), S('8', '3'), S('6', '4'), S('8', '"'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('T', 'r'), S('e', 'a'), S('t', ' '), S('t', 'h'), S('i', 's'), S(' ', 'l'), S('i', 'k'), S('e', ' '), S('a', 'n'), S(' ', 'u'), S('n', 's'), S('i', 'g'), S('n', 'e'), S('d', ' '), S('i', 'n'), S('t', 'e'), S('g', 'e'), S('r', ' '), S('p', 'r'), S('e', 'f'), S('i', 'x'), S('e', 'd'), S(' ', 'b'), S('y', ' '), S('\'', '-'), S('\'', ' '), S('i', 'f'), S(' ', 'i'), S('t', '\''), S('s', ' '), S('n', 'e'), S('g', 'a'), S('t', 'i'), S('v', 'e'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('i', 'n'), S('t', 'e'), S('r', 'n'), S('a', 'l'), S('I', 'n'), S('t', 'T'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S('(', 't'), S('h', 'i'), S('s', ' '), S('<', ' '), S('0', ' '), S('?', ' '), S('-', 't'), S('h', 'i'), S('s', ' '), S(':', ' '), S('t', 'h'), S('i', 's'), S(')', ' '), S('a', 's'), S(' ', 'u'), S('i', 'n'), S('t', ','), S(' ', 't'), S('h', 'i'), S('s', ' '), S('<', ' '), S('0', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 'u'), S('i', 'n'), S('t', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('i', 'n'), S('t', 'e'), S('r', 'n'), S('a', 'l'), S('I', 'n'), S('t', 'T'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S('t', 'h'), S('i', 's'), S(',', ' '), S('f', 'a'), S('l', 's'), S('e', ')'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', ' '), S('i', 'n'), S('t', 'e'), S('r', 'n'), S('a', 'l'), S('I', 'n'), S('t', 'T'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S('v', 'a'), S('l', 'u'), S('e', ':'), S(' ', 'u'), S('i', 'n'), S('t', ','), S(' ', 's'), S('i', 'g'), S('n', ':'), S(' ', 'b'), S('o', 'o'), S('l', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', '/'), S('/', ' '), S('A', 'v'), S('o', 'i'), S('d', ' '), S('a', 'l'), S('l', 'o'), S('c', 'a'), S('t', 'i'), S('o', 'n'), S(' ', 'f'), S('o', 'r'), S(' ', 'c'), S('o', 'm'), S('m', 'o'), S('n', ' '), S('c', 'a'), S('s', 'e'), S('s', '\n'), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('v', 'a'), S('l', 'u'), S('e', ' '), S('=', '='), S(' ', '0'), S(')', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', '"'), S('0', '"'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('v', 'a'), S('l', 'u'), S('e', ' '), S('=', '='), S(' ', '1'), S(')', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 's'), S('i', 'g'), S('n', ' '), S('?', ' '), S('"', '-'), S('1', '"'), S(' ', ':'), S(' ', '"'), S('1', '"'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('/', '/'), S(' ', 'D'), S('e', 't'), S('e', 'r'), S('m', 'i'), S('n', 'e'), S(' ', 'h'), S('o', 'w'), S(' ', 'm'), S('a', 'n'), S('y', ' '), S('d', 'i'), S('g', 'i'), S('t', 's'), S(' ', 'w'), S('e', ' '), S('n', 'e'), S('e', 'd'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('=', ' '), S('(', '('), S('s', 'i'), S('g', 'n'), S(' ', '?'), S(' ', '1'), S(' ', ':'), S(' ', '0'), S(')', ' '), S('+', ' '), S('(', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('>', '='), S(' ', '1'), S('0', '0'), S('0', '0'), S('0', '0'), S('0', '0'), S(' ', '?'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'l'), S('u', 'e'), S(' ', '>'), S('=', ' '), S('1', '0'), S('0', '0'), S('0', '0'), S('0', '0'), S('0', '0'), S(' ', '?'), S(' ', '1'), S('0', ' '), S(':', ' '), S('9', ' '), S(':', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('>', '='), S(' ', '1'), S('0', '0'), S('0', '0'), S(' ', '?'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'l'), S('u', 'e'), S(' ', '>'), S('=', ' '), S('1', '0'), S('0', '0'), S('0', '0'), S('0', ' '), S('?', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('>', '='), S(' ', '1'), S('0', '0'), S('0', '0'), S('0', '0'), S('0', ' '), S('?', ' '), S('8', ' '), S(':', ' '), S('7', ' '), S(':', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('>', '='), S(' ', '1'), S('0', '0'), S('0', '0'), S('0', ' '), S('?', ' '), S('6', ' '), S(':', ' '), S('5', ' '), S(':', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('>', '='), S(' ', '1'), S('0', '0'), S(' ', '?'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'l'), S('u', 'e'), S(' ', '>'), S('=', ' '), S('1', '0'), S('0', '0'), S(' ', '?'), S(' ', '4'), S(' ', ':'), S(' ', '3'), S(' ', ':'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'l'), S('u', 'e'), S(' ', '>'), S('=', ' '), S('1', '0'), S(' ', '?'), S(' ', '2'), S(' ', ':'), S(' ', '1'), S(')', ')'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'p'), S('t', 'r'), S(' ', '='), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', '_'), S('n', 'e'), S('w', '('), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(')', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('e', 'n'), S('d', ' '), S('=', ' '), S('p', 't'), S('r', ' '), S('+', ' '), S('4', ' '), S('+', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '*'), S(' ', '2'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 's'), S('i', 'g'), S('n', ')'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('(', '('), S('p', 't'), S('r', ' '), S('+', ' '), S('4', ')'), S(' ', 'a'), S('s', ' '), S('*', 'u'), S('s', 'h'), S('o', 'r'), S('t', ')'), S(' ', '='), S(' ', '\''), S('-', '\''), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'w'), S('h', 'i'), S('l', 'e'), S(' ', '('), S('v', 'a'), S('l', 'u'), S('e', ' '), S('!', '='), S(' ', '0'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('e', 'n'), S('d', ' '), S('=', ' '), S('e', 'n'), S('d', ' '), S('+', ' '), S('-', '2'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('*', '('), S('e', 'n'), S('d', ' '), S('a', 's'), S(' ', '*'), S('u', 's'), S('h', 'o'), S('r', 't'), S(')', ' '), S('=', ' '), S('(', 'v'), S('a', 'l'), S('u', 'e'), S(' ', '%'), S(' ', '1'), S('0', ' '), S('+', ' '), S('\'', '0'), S('\'', ')'), S(' ', 'a'), S('s', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('=', ' '), S('v', 'a'), S('l', 'u'), S('e', ' '), S('/', ' '), S('1', '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('p', 't'), S('r', ' '), S('a', 's'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', '_'), S('n', 'e'), S('w', '('), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(':', ' '), S('u', 'i'), S('n', 't'), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'p'), S('t', 'r'), S(' ', '='), S(' ', 'm'), S('a', 'l'), S('l', 'o'), S('c', '('), S('4', ' '), S('+', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '*'), S(' ', '2'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '*'), S('(', 'p'), S('t', 'r'), S(' ', 'a'), S('s', ' '), S('*', 'u'), S('i', 'n'), S('t', ')'), S(' ', '='), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('p', 't'), S('r', ' '), S('a', 's'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 'c'), S('h', 'a'), S('r', 'A'), S('t', '('), S('i', 'n'), S('d', 'e'), S('x', ':'), S(' ', 'i'), S('n', 't'), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('h', 'i'), S('s', '.'), S('s', 'l'), S('i', 'c'), S('e', '('), S('i', 'n'), S('d', 'e'), S('x', ','), S(' ', 'i'), S('n', 'd'), S('e', 'x'), S(' ', '+'), S(' ', '1'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('c', 'h'), S('a', 'r'), S('C', 'o'), S('d', 'e'), S('A', 't'), S('(', 'i'), S('n', 'd'), S('e', 'x'), S(':', ' '), S('i', 'n'), S('t', ')'), S(':', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('t', 'h'), S('i', 's'), S('[', 'i'), S('n', 'd'), S('e', 'x'), S(']', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('g', 'e'), S('t', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S('(', ')'), S(':', ' '), S('i', 'n'), S('t', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('*', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('*', 'i'), S('n', 't'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '['), S(']', ' '), S('(', 'i'), S('n', 'd'), S('e', 'x'), S(':', ' '), S('i', 'n'), S('t', ')'), S(':', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 'i'), S('n', 'd'), S('e', 'x'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(' ', '<'), S(' ', 't'), S('h', 'i'), S('s', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(')', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('*', '('), S('(', 't'), S('h', 'i'), S('s', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '+'), S(' ', '4'), S(' ', '+'), S(' ', 'i'), S('n', 'd'), S('e', 'x'), S(' ', '*'), S(' ', '2'), S(')', ' '), S('a', 's'), S(' ', '*'), S('u', 's'), S('h', 'o'), S('r', 't'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('0', ';'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '='), S('=', ' '), S('(', 'o'), S('t', 'h'), S('e', 'r'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'b'), S('o', 'o'), S('l', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 't'), S('h', 'i'), S('s', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '='), S('=', ' '), S('o', 't'), S('h', 'e'), S('r', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(')', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('r', 'u'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 't'), S('h', 'i'), S('s', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '='), S('=', ' '), S('n', 'u'), S('l', 'l'), S(' ', '|'), S('|', ' '), S('o', 't'), S('h', 'e'), S('r', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '='), S('=', ' '), S('n', 'u'), S('l', 'l'), S(')', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 'f'), S('a', 'l'), S('s', 'e'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 't'), S('h', 'i'), S('s', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '!'), S('=', ' '), S('o', 't'), S('h', 'e'), S('r', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(')', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 'f'), S('a', 'l'), S('s', 'e'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'm'), S('p', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ','), S(' ', 'o'), S('t', 'h'), S('e', 'r'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ','), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ' '), S('a', 's'), S(' ', 'u'), S('i', 'n'), S('t', ' '), S('*', ' '), S('2', ')'), S(' ', '='), S('=', ' '), S('0', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('s', 'l'), S('i', 'c'), S('e', '('), S('s', 't'), S('a', 'r'), S('t', ':'), S(' ', 'i'), S('n', 't'), S(',', ' '), S('e', 'n'), S('d', ':'), S(' ', 'i'), S('n', 't'), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 't'), S('h', 'i'), S('s', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 's'), S('t', 'a'), S('r', 't'), S(' ', '<'), S(' ', '0'), S(')', ' '), S('s', 't'), S('a', 'r'), S('t', ' '), S('=', ' '), S('s', 't'), S('a', 'r'), S('t', ' '), S('+', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('e', 'n'), S('d', ' '), S('<', ' '), S('0', ')'), S(' ', 'e'), S('n', 'd'), S(' ', '='), S(' ', 'e'), S('n', 'd'), S(' ', '+'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('s', 't'), S('a', 'r'), S('t', ' '), S('<', ' '), S('0', ')'), S(' ', 's'), S('t', 'a'), S('r', 't'), S(' ', '='), S(' ', '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('e', 'l'), S('s', 'e'), S(' ', 'i'), S('f', ' '), S('(', 's'), S('t', 'a'), S('r', 't'), S(' ', '>'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', 's'), S('t', 'a'), S('r', 't'), S(' ', '='), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('e', 'n'), S('d', ' '), S('<', ' '), S('s', 't'), S('a', 'r'), S('t', ')'), S(' ', 'e'), S('n', 'd'), S(' ', '='), S(' ', 's'), S('t', 'a'), S('r', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('e', 'l'), S('s', 'e'), S(' ', 'i'), S('f', ' '), S('(', 'e'), S('n', 'd'), S(' ', '>'), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', 'e'), S('n', 'd'), S(' ', '='), S(' ', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('u', 'n'), S('s', 'a'), S('f', 'e'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 'r'), S('a', 'n'), S('g', 'e'), S(' ', '='), S(' ', '('), S('e', 'n'), S('d', ' '), S('-', ' '), S('s', 't'), S('a', 'r'), S('t', ')'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('p', 't'), S('r', ' '), S('=', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S('_', 'n'), S('e', 'w'), S('(', 'r'), S('a', 'n'), S('g', 'e'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'm'), S('e', 'm'), S('c', 'p'), S('y', '('), S('p', 't'), S('r', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '+'), S(' ', '4'), S(',', ' '), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ' '), S('+', ' '), S('s', 't'), S('a', 'r'), S('t', ' '), S('*', ' '), S('2', ','), S(' ', 'r'), S('a', 'n'), S('g', 'e'), S(' ', '*'), S(' ', '2'), S(')', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('p', 't'), S('r', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('s', 't'), S('a', 'r'), S('t', 's'), S('W', 'i'), S('t', 'h'), S('(', 't'), S('e', 'x'), S('t', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ')'), S(':', ' '), S('b', 'o'), S('o', 'l'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'v'), S('a', 'r'), S(' ', 't'), S('e', 'x'), S('t', 'L'), S('e', 'n'), S('g', 't'), S('h', ' '), S('=', ' '), S('t', 'e'), S('x', 't'), S('.', 'l'), S('e', 'n'), S('g', 't'), S('h', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'i'), S('f', ' '), S('(', 't'), S('h', 'i'), S('s', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '<'), S(' ', 't'), S('e', 'x'), S('t', 'L'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('f', 'a'), S('l', 's'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'm'), S('p', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ','), S(' ', 't'), S('e', 'x'), S('t', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '+'), S(' ', '4'), S(',', ' '), S('t', 'e'), S('x', 't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(' ', '*'), S(' ', '2'), S(')', ' '), S('=', '='), S(' ', '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', ' '), S(' ', 'e'), S('n', 'd'), S('s', 'W'), S('i', 't'), S('h', '('), S('t', 'e'), S('x', 't'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'b'), S('o', 'o'), S('l', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('t', 'h'), S('i', 's'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 't'), S('h', 'i'), S('s', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('v', 'a'), S('r', ' '), S('t', 'e'), S('x', 't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '='), S(' ', 't'), S('e', 'x'), S('t', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('i', 'f'), S(' ', '('), S('t', 'h'), S('i', 's'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', '<'), S(' ', 't'), S('e', 'x'), S('t', 'L'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('f', 'a'), S('l', 's'), S('e', ';'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'u'), S('n', 's'), S('a', 'f'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 'm'), S('e', 'm'), S('c', 'm'), S('p', '('), S('t', 'h'), S('i', 's'), S(' ', 'a'), S('s', ' '), S('*', 'b'), S('y', 't'), S('e', ' '), S('+', ' '), S('4', ' '), S('+', ' '), S('(', 't'), S('h', 'i'), S('s', 'L'), S('e', 'n'), S('g', 't'), S('h', ' '), S('-', ' '), S('t', 'e'), S('x', 't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(')', ' '), S('*', ' '), S('2', ','), S(' ', 't'), S('e', 'x'), S('t', ' '), S('a', 's'), S(' ', '*'), S('b', 'y'), S('t', 'e'), S(' ', '+'), S(' ', '4'), S(',', ' '), S('t', 'e'), S('x', 't'), S('L', 'e'), S('n', 'g'), S('t', 'h'), S(' ', 'a'), S('s', ' '), S('u', 'i'), S('n', 't'), S(' ', '*'), S(' ', '2'), S(')', ' '), S('=', '='), S(' ', '0'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S('}', '\n'), S(' ', ' '), S('}', '\n'), S('\n', '#'), S('e', 'l'), S('s', 'e'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('b', 'o'), S('o', 'l'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('s', 'b'), S('y', 't'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 'b'), S('y', 't'), S('e', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S('\n', ' '), S(' ', ' '), S(' ', 't'), S('o', 'S'), S('t', 'r'), S('i', 'n'), S('g', '('), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S(' ', ' '), S('d', 'e'), S('c', 'l'), S('a', 'r'), S('e', ' '), S('c', 'l'), S('a', 's'), S('s', ' '), S('i', 'n'), S('t', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 'u'), S('i', 'n'), S('t', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('t', 'o'), S('S', 't'), S('r', 'i'), S('n', 'g'), S('(', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(';', '\n'), S(' ', ' '), S('}', '\n'), S('\n', ' '), S(' ', 'd'), S('e', 'c'), S('l', 'a'), S('r', 'e'), S(' ', 'c'), S('l', 'a'), S('s', 's'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ' '), S('{', '\n'), S(' ', ' '), S(' ', ' '), S('c', 'h'), S('a', 'r'), S('A', 't'), S('(', 'i'), S('n', 'd'), S('e', 'x'), S(':', ' '), S('i', 'n'), S('t', ')'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('c', 'h'), S('a', 'r'), S('C', 'o'), S('d', 'e'), S('A', 't'), S('(', 'i'), S('n', 'd'), S('e', 'x'), S(':', ' '), S('i', 'n'), S('t', ')'), S(':', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('g', 'e'), S('t', ' '), S('l', 'e'), S('n', 'g'), S('t', 'h'), S('(', ')'), S(':', ' '), S('i', 'n'), S('t', ';'), S('\n', ' '), S(' ', ' '), S(' ', 'o'), S('p', 'e'), S('r', 'a'), S('t', 'o'), S('r', ' '), S('=', '='), S(' ', '('), S('o', 't'), S('h', 'e'), S('r', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ')'), S(':', ' '), S('b', 'o'), S('o', 'l'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '['), S(']', ' '), S('(', 'i'), S('n', 'd'), S('e', 'x'), S(':', ' '), S('i', 'n'), S('t', ')'), S(':', ' '), S('u', 's'), S('h', 'o'), S('r', 't'), S(' ', '{'), S(' ', 'r'), S('e', 't'), S('u', 'r'), S('n', ' '), S('t', 'h'), S('i', 's'), S('.', 'c'), S('h', 'a'), S('r', 'C'), S('o', 'd'), S('e', 'A'), S('t', '('), S('i', 'n'), S('d', 'e'), S('x', ')'), S(';', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S('s', 'l'), S('i', 'c'), S('e', '('), S('s', 't'), S('a', 'r'), S('t', ':'), S(' ', 'i'), S('n', 't'), S(',', ' '), S('e', 'n'), S('d', ':'), S(' ', 'i'), S('n', 't'), S(')', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ';'), S('\n', '\n'), S(' ', ' '), S(' ', ' '), S('#', 'i'), S('f', ' '), S('J', 'S'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 's'), S('t', 'a'), S('r', 't'), S('s', 'W'), S('i', 't'), S('h', '('), S('t', 'e'), S('x', 't'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'b'), S('o', 'o'), S('l', ' '), S('{', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('h', 'i'), S('s', '.'), S('s', 'l'), S('i', 'c'), S('e', '('), S('0', ','), S(' ', 't'), S('e', 'x'), S('t', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(')', ' '), S('=', '='), S(' ', 't'), S('e', 'x'), S('t', ';'), S(' ', '}'), S('\n', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'e'), S('n', 'd'), S('s', 'W'), S('i', 't'), S('h', '('), S('t', 'e'), S('x', 't'), S(':', ' '), S('s', 't'), S('r', 'i'), S('n', 'g'), S(')', ':'), S(' ', 'b'), S('o', 'o'), S('l', ' '), S('{', ' '), S('r', 'e'), S('t', 'u'), S('r', 'n'), S(' ', 't'), S('h', 'i'), S('s', '.'), S('s', 'l'), S('i', 'c'), S('e', '('), S('-', 't'), S('e', 'x'), S('t', '.'), S('l', 'e'), S('n', 'g'), S('t', 'h'), S(',', ' '), S('t', 'h'), S('i', 's'), S('.', 'l'), S('e', 'n'), S('g', 't'), S('h', ')'), S(' ', '='), S('=', ' '), S('t', 'e'), S('x', 't'), S(';', ' '), S('}', '\n'), S(' ', ' '), S(' ', ' '), S('#', 'e'), S('l', 's'), S('e', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('s', 't'), S('a', 'r'), S('t', 's'), S('W', 'i'), S('t', 'h'), S('(', 't'), S('e', 'x'), S('t', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ')'), S(':', ' '), S('b', 'o'), S('o', 'l'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S('e', 'n'), S('d', 's'), S('W', 'i'), S('t', 'h'), S('(', 't'), S('e', 'x'), S('t', ':'), S(' ', 's'), S('t', 'r'), S('i', 'n'), S('g', ')'), S(':', ' '), S('b', 'o'), S('o', 'l'), S(';', '\n'), S(' ', ' '), S(' ', ' '), S('#', 'e'), S('n', 'd'), S('i', 'f'), S('\n', ' '), S(' ', '}'), S('\n', '\n'), S('#', 'e'), S('n', 'd'), S('i', 'f'), S('\n', 0)};
static const uint32_t __string_516[] = {2, S(':', ' ')};
static const uint32_t __string_517_error[] = {7, S('e', 'r'), S('r', 'o'), S('r', ':'), S(' ', 0)};
static const uint32_t __string_518_warning[] = {9, S('w', 'a'), S('r', 'n'), S('i', 'n'), S('g', ':'), S(' ', 0)};
static const uint32_t __string_519_error[] = {7, S('e', 'r'), S('r', 'o'), S('r', ':'), S(' ', 0)};
static const uint32_t __string_520[] = {1, S('\n', 0)};
static const uint32_t __string_521_Usage_thinc_FLAGS_INPUTS[] = {318, S('\n', 'U'), S('s', 'a'), S('g', 'e'), S(':', ' '), S('t', 'h'), S('i', 'n'), S('c', ' '), S('[', 'F'), S('L', 'A'), S('G', 'S'), S(']', ' '), S('[', 'I'), S('N', 'P'), S('U', 'T'), S('S', ']'), S('\n', '\n'), S(' ', ' '), S('-', '-'), S('h', 'e'), S('l', 'p'), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', ' '), S(' ', 'P'), S('r', 'i'), S('n', 't'), S(' ', 't'), S('h', 'i'), S('s', ' '), S('m', 'e'), S('s', 's'), S('a', 'g'), S('e', '.'), S('\n', ' '), S(' ', '-'), S('-', 'o'), S('u', 't'), S(' ', '['), S('P', 'A'), S('T', 'H'), S(']', ' '), S(' ', ' '), S(' ', ' '), S('S', 'a'), S('v', 'e'), S(' ', 't'), S('h', 'e'), S(' ', 'g'), S('e', 'n'), S('e', 'r'), S('a', 't'), S('e', 'd'), S(' ', 'c'), S('o', 'd'), S('e', ' '), S('t', 'o'), S(' ', 'P'), S('A', 'T'), S('H', '.'), S('\n', ' '), S(' ', '-'), S('-', 'd'), S('e', 'f'), S('i', 'n'), S('e', ' '), S('[', 'N'), S('A', 'M'), S('E', ']'), S(' ', ' '), S('D', 'e'), S('f', 'i'), S('n', 'e'), S(' ', 't'), S('h', 'e'), S(' ', 'f'), S('l', 'a'), S('g', ' '), S('N', 'A'), S('M', 'E'), S(' ', 'i'), S('n', ' '), S('a', 'l'), S('l', ' '), S('i', 'n'), S('p', 'u'), S('t', ' '), S('f', 'i'), S('l', 'e'), S('s', '.'), S('\n', '\n'), S('E', 'x'), S('a', 'm'), S('p', 'l'), S('e', 's'), S(':', '\n'), S('\n', ' '), S(' ', 't'), S('h', 'i'), S('n', 'c'), S(' ', 'm'), S('a', 'i'), S('n', '.'), S('t', 'h'), S('i', 'n'), S(' ', '-'), S('-', 'o'), S('u', 't'), S(' ', 'm'), S('a', 'i'), S('n', '.'), S('j', 's'), S('\n', ' '), S(' ', 't'), S('h', 'i'), S('n', 'c'), S(' ', 's'), S('r', 'c'), S('/', '*'), S('.', 't'), S('h', 'i'), S('n', ' '), S('-', '-'), S('o', 'u'), S('t', ' '), S('m', 'a'), S('i', 'n'), S('.', 'w'), S('a', 's'), S('m', '\n'), S(' ', ' '), S('t', 'h'), S('i', 'n'), S('c', ' '), S('n', 'a'), S('t', 'i'), S('v', 'e'), S('.', 't'), S('h', 'i'), S('n', ' '), S('-', '-'), S('o', 'u'), S('t', ' '), S('m', 'a'), S('i', 'n'), S('.', 'c'), S(' ', '-'), S('-', 'd'), S('e', 'f'), S('i', 'n'), S('e', ' '), S('E', 'N'), S('A', 'B'), S('L', 'E'), S('_', 'T'), S('E', 'S'), S('T', 'S'), S('\n', '\n')};
static const uint32_t __string_522[] = {1, S('-', 0)};
static const uint32_t __string_523_h[] = {2, S('-', 'h')};
static const uint32_t __string_524_help[] = {5, S('-', 'h'), S('e', 'l'), S('p', 0)};
static const uint32_t __string_525_help[] = {6, S('-', '-'), S('h', 'e'), S('l', 'p')};
static const uint32_t __string_526[] = {2, S('/', '?')};
static const uint32_t __string_527_c[] = {3, S('-', '-'), S('c', 0)};
static const uint32_t __string_528_js[] = {4, S('-', '-'), S('j', 's')};
static const uint32_t __string_529_wasm[] = {6, S('-', '-'), S('w', 'a'), S('s', 'm')};
static const uint32_t __string_530_define[] = {8, S('-', '-'), S('d', 'e'), S('f', 'i'), S('n', 'e')};
static const uint32_t __string_531_out[] = {5, S('-', '-'), S('o', 'u'), S('t', 0)};
static const uint32_t __string_532_Invalid_flag[] = {14, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('f', 'l'), S('a', 'g'), S(':', ' ')};
static const uint32_t __string_533_No_input_files[] = {14, S('N', 'o'), S(' ', 'i'), S('n', 'p'), S('u', 't'), S(' ', 'f'), S('i', 'l'), S('e', 's')};
static const uint32_t __string_534_Missing_an_output_file_use_the[] = {43, S('M', 'i'), S('s', 's'), S('i', 'n'), S('g', ' '), S('a', 'n'), S(' ', 'o'), S('u', 't'), S('p', 'u'), S('t', ' '), S('f', 'i'), S('l', 'e'), S(' ', '('), S('u', 's'), S('e', ' '), S('t', 'h'), S('e', 160), S('-', '-'), S('o', 'u'), S('t', ' '), S('f', 'l'), S('a', 'g'), S(')', 0)};
static const uint32_t __string_535_c[] = {2, S('.', 'c')};
static const uint32_t __string_536_js[] = {3, S('.', 'j'), S('s', 0)};
static const uint32_t __string_537_wasm[] = {5, S('.', 'w'), S('a', 's'), S('m', 0)};
static const uint32_t __string_538_Missing_a_target_use_either_c[] = {50, S('M', 'i'), S('s', 's'), S('i', 'n'), S('g', ' '), S('a', ' '), S('t', 'a'), S('r', 'g'), S('e', 't'), S(' ', '('), S('u', 's'), S('e', ' '), S('e', 'i'), S('t', 'h'), S('e', 'r'), S(' ', '-'), S('-', 'c'), S(',', ' '), S('-', '-'), S('j', 's'), S(',', ' '), S('o', 'r'), S(' ', '-'), S('-', 'w'), S('a', 's'), S('m', ')')};
static const uint32_t __string_539_define[] = {8, S('-', '-'), S('d', 'e'), S('f', 'i'), S('n', 'e')};
static const uint32_t __string_540_out[] = {5, S('-', '-'), S('o', 'u'), S('t', 0)};
static const uint32_t __string_541[] = {1, S('-', 0)};
static const uint32_t __string_542_Cannot_read_from[] = {17, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'r'), S('e', 'a'), S('d', ' '), S('f', 'r'), S('o', 'm'), S(' ', 0)};
static const uint32_t __string_543_Cannot_write_to[] = {16, S('C', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'w'), S('r', 'i'), S('t', 'e'), S(' ', 't'), S('o', ' ')};
static const uint32_t __string_544[] = {1, S('%', 0)};
static const uint32_t __string_545[] = {1, S('&', 0)};
static const uint32_t __string_546[] = {1, S('*', 0)};
static const uint32_t __string_547[] = {2, S('*', '*')};
static const uint32_t __string_548[] = {1, S('/', 0)};
static const uint32_t __string_549[] = {1, S('<', 0)};
static const uint32_t __string_550[] = {2, S('<', '<')};
static const uint32_t __string_551[] = {2, S('=', '=')};
static const uint32_t __string_552[] = {1, S('>', 0)};
static const uint32_t __string_553[] = {2, S('>', '>')};
static const uint32_t __string_554[] = {2, S('[', ']')};
static const uint32_t __string_555[] = {1, S('^', 0)};
static const uint32_t __string_556[] = {1, S('|', 0)};
static const uint32_t __string_557[] = {3, S('[', ']'), S('=', 0)};
static const uint32_t __string_558_Unexpected[] = {11, S('U', 'n'), S('e', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 0)};
static const uint32_t __string_559_Expected[] = {9, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 0)};
static const uint32_t __string_560_Expected[] = {9, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 0)};
static const uint32_t __string_561_but_found[] = {11, S(' ', 'b'), S('u', 't'), S(' ', 'f'), S('o', 'u'), S('n', 'd'), S(' ', 0)};
static const uint32_t __string_562_Invalid_escape_code[] = {21, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('e', 's'), S('c', 'a'), S('p', 'e'), S(' ', 'c'), S('o', 'd'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_563_Invalid_character_literal_strin[] = {53, S('I', 'n'), S('v', 'a'), S('l', 'i'), S('d', ' '), S('c', 'h'), S('a', 'r'), S('a', 'c'), S('t', 'e'), S('r', ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', ' '), S('(', 's'), S('t', 'r'), S('i', 'n'), S('g', 's'), S(' ', 'u'), S('s', 'e'), S(' ', 'd'), S('o', 'u'), S('b', 'l'), S('e', ' '), S('q', 'u'), S('o', 't'), S('e', 's'), S(')', 0)};
static const uint32_t __string_564_operator[] = {8, S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r')};
static const uint32_t __string_565_get[] = {3, S('g', 'e'), S('t', 0)};
static const uint32_t __string_566_set[] = {3, S('s', 'e'), S('t', 0)};
static const uint32_t __string_567_Instance_functions_don_t_need_th[] = {52, S('I', 'n'), S('s', 't'), S('a', 'n'), S('c', 'e'), S(' ', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', 's'), S(' ', 'd'), S('o', 'n'), S('\'', 't'), S(' ', 'n'), S('e', 'e'), S('d', ' '), S('t', 'h'), S('e', ' '), S('\'', 'f'), S('u', 'n'), S('c', 't'), S('i', 'o'), S('n', '\''), S(' ', 'k'), S('e', 'y'), S('w', 'o'), S('r', 'd')};
static const uint32_t __string_568_Instance_variables_don_t_need_th[] = {35, S('I', 'n'), S('s', 't'), S('a', 'n'), S('c', 'e'), S(' ', 'v'), S('a', 'r'), S('i', 'a'), S('b', 'l'), S('e', 's'), S(' ', 'd'), S('o', 'n'), S('\'', 't'), S(' ', 'n'), S('e', 'e'), S('d', ' '), S('t', 'h'), S('e', ' '), S('\'', 0)};
static const uint32_t __string_569_keyword[] = {9, S('\'', ' '), S('k', 'e'), S('y', 'w'), S('o', 'r'), S('d', 0)};
static const uint32_t __string_570[] = {3, S('[', ']'), S('=', 0)};
static const uint32_t __string_571[] = {2, S('[', ']')};
static const uint32_t __string_572_The_operator[] = {14, S('T', 'h'), S('e', ' '), S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r'), S(' ', '\'')};
static const uint32_t __string_573_cannot_be_implemented[] = {23, S('\'', ' '), S('c', 'a'), S('n', 'n'), S('o', 't'), S(' ', 'b'), S('e', ' '), S('i', 'm'), S('p', 'l'), S('e', 'm'), S('e', 'n'), S('t', 'e'), S('d', 0)};
static const uint32_t __string_574_it_is_automatically_derived_fr[] = {40, S(' ', '('), S('i', 't'), S(' ', 'i'), S('s', ' '), S('a', 'u'), S('t', 'o'), S('m', 'a'), S('t', 'i'), S('c', 'a'), S('l', 'l'), S('y', ' '), S('d', 'e'), S('r', 'i'), S('v', 'e'), S('d', ' '), S('f', 'r'), S('o', 'm'), S(' ', '\''), S('=', '='), S('\'', ')')};
static const uint32_t __string_575_it_is_automatically_derived_fr[] = {39, S(' ', '('), S('i', 't'), S(' ', 'i'), S('s', ' '), S('a', 'u'), S('t', 'o'), S('m', 'a'), S('t', 'i'), S('c', 'a'), S('l', 'l'), S('y', ' '), S('d', 'e'), S('r', 'i'), S('v', 'e'), S('d', ' '), S('f', 'r'), S('o', 'm'), S(' ', '\''), S('>', '\''), S(')', 0)};
static const uint32_t __string_576_it_is_automatically_derived_fr[] = {39, S(' ', '('), S('i', 't'), S(' ', 'i'), S('s', ' '), S('a', 'u'), S('t', 'o'), S('m', 'a'), S('t', 'i'), S('c', 'a'), S('l', 'l'), S('y', ' '), S('d', 'e'), S('r', 'i'), S('v', 'e'), S('d', ' '), S('f', 'r'), S('o', 'm'), S(' ', '\''), S('<', '\''), S(')', 0)};
static const uint32_t __string_577[] = {0};
static const uint32_t __string_578_Inline_initialization_of_instanc[] = {64, S('I', 'n'), S('l', 'i'), S('n', 'e'), S(' ', 'i'), S('n', 'i'), S('t', 'i'), S('a', 'l'), S('i', 'z'), S('a', 't'), S('i', 'o'), S('n', ' '), S('o', 'f'), S(' ', 'i'), S('n', 's'), S('t', 'a'), S('n', 'c'), S('e', ' '), S('v', 'a'), S('r', 'i'), S('a', 'b'), S('l', 'e'), S('s', ' '), S('i', 's'), S(' ', 'n'), S('o', 't'), S(' ', 's'), S('u', 'p'), S('p', 'o'), S('r', 't'), S('e', 'd'), S(' ', 'y'), S('e', 't')};
static const uint32_t __string_579_Use_the_0o_prefix_for_octal_in[] = {38, S('U', 's'), S('e', ' '), S('t', 'h'), S('e', ' '), S('\'', '0'), S('o', '\''), S(' ', 'p'), S('r', 'e'), S('f', 'i'), S('x', ' '), S('f', 'o'), S('r', ' '), S('o', 'c'), S('t', 'a'), S('l', ' '), S('i', 'n'), S('t', 'e'), S('g', 'e'), S('r', 's')};
static const uint32_t __string_580_Integer_literal_is_too_big_to_fi[] = {44, S('I', 'n'), S('t', 'e'), S('g', 'e'), S('r', ' '), S('l', 'i'), S('t', 'e'), S('r', 'a'), S('l', ' '), S('i', 's'), S(' ', 't'), S('o', 'o'), S(' ', 'b'), S('i', 'g'), S(' ', 't'), S('o', ' '), S('f', 'i'), S('t', ' '), S('i', 'n'), S(' ', '3'), S('2', ' '), S('b', 'i'), S('t', 's')};
static const uint32_t __string_581_Unexpected[] = {11, S('U', 'n'), S('e', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 0)};
static const uint32_t __string_582_Expected[] = {9, S('E', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 0)};
static const uint32_t __string_583_but_found[] = {11, S(' ', 'b'), S('u', 't'), S(' ', 'f'), S('o', 'u'), S('n', 'd'), S(' ', 0)};
static const uint32_t __string_584_0[] = {1, S('0', 0)};
static const uint32_t __string_585_Use_undef_to_turn_a_preproces[] = {44, S('U', 's'), S('e', ' '), S('\'', '#'), S('u', 'n'), S('d', 'e'), S('f', '\''), S(' ', 't'), S('o', ' '), S('t', 'u'), S('r', 'n'), S(' ', 'a'), S(' ', 'p'), S('r', 'e'), S('p', 'r'), S('o', 'c'), S('e', 's'), S('s', 'o'), S('r', ' '), S('f', 'l'), S('a', 'g'), S(' ', 'o'), S('f', 'f')};
static const uint32_t __string_586_All_define_and_undef_direc[] = {68, S('A', 'l'), S('l', ' '), S('\'', '#'), S('d', 'e'), S('f', 'i'), S('n', 'e'), S('\'', ' '), S('a', 'n'), S('d', ' '), S('\'', '#'), S('u', 'n'), S('d', 'e'), S('f', '\''), S(' ', 'd'), S('i', 'r'), S('e', 'c'), S('t', 'i'), S('v', 'e'), S('s', ' '), S('m', 'u'), S('s', 't'), S(' ', 'b'), S('e', ' '), S('a', 't'), S(' ', 't'), S('h', 'e'), S(' ', 't'), S('o', 'p'), S(' ', 'o'), S('f', ' '), S('t', 'h'), S('e', ' '), S('f', 'i'), S('l', 'e')};
static const uint32_t __string_587_defined[] = {7, S('d', 'e'), S('f', 'i'), S('n', 'e'), S('d', 0)};
static const uint32_t __string_588_There_is_no_defined_operator[] = {30, S('T', 'h'), S('e', 'r'), S('e', ' '), S('i', 's'), S(' ', 'n'), S('o', ' '), S('\'', 'd'), S('e', 'f'), S('i', 'n'), S('e', 'd'), S('\'', ' '), S('o', 'p'), S('e', 'r'), S('a', 't'), S('o', 'r')};
static const uint32_t __string_589_just_use[] = {12, S(' ', '('), S('j', 'u'), S('s', 't'), S(' ', 'u'), S('s', 'e'), S(' ', '\'')};
static const uint32_t __string_590_instead[] = {10, S('\'', ' '), S('i', 'n'), S('s', 't'), S('e', 'a'), S('d', ')')};
static const uint32_t __string_591_0[] = {1, S('0', 0)};
static const uint32_t __string_592_Unexpected_integer_did_you_mean[] = {34, S('U', 'n'), S('e', 'x'), S('p', 'e'), S('c', 't'), S('e', 'd'), S(' ', 'i'), S('n', 't'), S('e', 'g'), S('e', 'r'), S(' ', '('), S('d', 'i'), S('d', ' '), S('y', 'o'), S('u', ' '), S('m', 'e'), S('a', 'n'), S(' ', '\'')};
static const uint32_t __string_593_true[] = {4, S('t', 'r'), S('u', 'e')};
static const uint32_t __string_594_false[] = {5, S('f', 'a'), S('l', 's'), S('e', 0)};
static const uint32_t __string_595[] = {3, S('\'', ')'), S('?', 0)};
static const uint32_t __string_596_Duplicate_symbol[] = {18, S('D', 'u'), S('p', 'l'), S('i', 'c'), S('a', 't'), S('e', ' '), S('s', 'y'), S('m', 'b'), S('o', 'l'), S(' ', '\'')};
static const uint32_t __string_597[] = {1, S('\'', 0)};
static const uint32_t __string_598[] = {2, S('\\', '"')};
static const uint32_t __string_599_0[] = {2, S('\\', '0')};
static const uint32_t __string_600_t[] = {2, S('\\', 't')};
static const uint32_t __string_601_r[] = {2, S('\\', 'r')};
static const uint32_t __string_602_n[] = {2, S('\\', 'n')};
static const uint32_t __string_603[] = {2, S('\\', '\\')};
static const uint32_t __string_604_signatures[] = {10, S('s', 'i'), S('g', 'n'), S('a', 't'), S('u', 'r'), S('e', 's')};
static const uint32_t __string_605_import_table[] = {12, S('i', 'm'), S('p', 'o'), S('r', 't'), S('_', 't'), S('a', 'b'), S('l', 'e')};
static const uint32_t __string_606_function_signatures[] = {19, S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S('_', 's'), S('i', 'g'), S('n', 'a'), S('t', 'u'), S('r', 'e'), S('s', 0)};
static const uint32_t __string_607_memory[] = {6, S('m', 'e'), S('m', 'o'), S('r', 'y')};
static const uint32_t __string_608_export_table[] = {12, S('e', 'x'), S('p', 'o'), S('r', 't'), S('_', 't'), S('a', 'b'), S('l', 'e')};
static const uint32_t __string_609_function_bodies[] = {15, S('f', 'u'), S('n', 'c'), S('t', 'i'), S('o', 'n'), S('_', 'b'), S('o', 'd'), S('i', 'e'), S('s', 0)};
static const uint32_t __string_610_data_segments[] = {13, S('d', 'a'), S('t', 'a'), S('_', 's'), S('e', 'g'), S('m', 'e'), S('n', 't'), S('s', 0)};
static const uint32_t __string_611_currentHeapPointer[] = {18, S('c', 'u'), S('r', 'r'), S('e', 'n'), S('t', 'H'), S('e', 'a'), S('p', 'P'), S('o', 'i'), S('n', 't'), S('e', 'r')};
static const uint32_t __string_612_originalHeapPointer[] = {19, S('o', 'r'), S('i', 'g'), S('i', 'n'), S('a', 'l'), S('H', 'e'), S('a', 'p'), S('P', 'o'), S('i', 'n'), S('t', 'e'), S('r', 0)};
static const uint32_t __string_613_global[] = {6, S('g', 'l'), S('o', 'b'), S('a', 'l')};
static const uint32_t __string_614_malloc[] = {6, S('m', 'a'), S('l', 'l'), S('o', 'c')};

#undef S

struct ByteArray;
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
  struct ByteArray *wasm;
  const uint16_t *js;
  const uint16_t *c;
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
  const uint16_t *name;
  int32_t signatureIndex;
  struct Node *body;
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
static void ByteArray_set16(struct ByteArray *array, int32_t index, int32_t value);
static void ByteArray_set32(struct ByteArray *array, int32_t index, int32_t value);
static void ByteArray_append32(struct ByteArray *array, int32_t value);
static void ByteArray_setString(struct ByteArray *array, int32_t index, const uint16_t *text);
static int32_t ByteArray_length(struct ByteArray *this);
static void ByteArray_clear(struct ByteArray *this);
static uint8_t ByteArray_get(struct ByteArray *this, int32_t index);
static void ByteArray_set(struct ByteArray *this, int32_t index, uint8_t value);
static void ByteArray_append(struct ByteArray *this, uint8_t value);
static void ByteArray_resize(struct ByteArray *this, int32_t length);
static void CResult_emitIndent(struct CResult *this);
static void CResult_emitNewlineBefore(struct CResult *this, struct Node *node);
static void CResult_emitNewlineAfter(struct CResult *this, struct Node *node);
static void CResult_emitStatements(struct CResult *this, struct Node *node);
static void CResult_emitBlock(struct CResult *this, struct Node *node);
static void CResult_emitUnary(struct CResult *this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator);
static void CResult_emitBinary(struct CResult *this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator, int32_t operatorPrecedence);
static void CResult_emitCommaSeparatedExpressions(struct CResult *this, struct Node *start, struct Node *stop);
static void CResult_emitSymbolName(struct CResult *this, struct Symbol *symbol);
static void CResult_emitCharacter(struct CResult *this, uint16_t c);
static void CResult_emitExpression(struct CResult *this, struct Node *node, int32_t parentPrecedence);
static uint8_t CResult_shouldEmitClass(struct CResult *this, struct Node *node);
static void CResult_emitType(struct CResult *this, struct Type *originalType, int32_t mode);
static void CResult_emitStatement(struct CResult *this, struct Node *node);
static void CResult_emitIncludes(struct CResult *this);
static void CResult_emitTypeDeclarations(struct CResult *this, struct Node *node);
static void CResult_emitTypeDefinitions(struct CResult *this, struct Node *node);
static uint8_t CResult_shouldEmitFunction(struct CResult *this, struct Symbol *symbol);
static void CResult_emitFunctionDeclarations(struct CResult *this, struct Node *node);
static void CResult_emitGlobalVariables(struct CResult *this, struct Node *node);
static void CResult_emitFunctionDefinitions(struct CResult *this, struct Node *node);
static void CResult_finish(struct CResult *this);
static const uint16_t *cEmit(struct Node *global, struct CheckContext *context);
static int32_t CheckContext_allocateGlobalVariableOffset(struct CheckContext *this, int32_t sizeOf, int32_t alignmentOf);
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
static void Compiler_initialize(struct Compiler *this, int32_t target);
static void Compiler_createGlobals(struct Compiler *this);
static struct Source *Compiler_addInput(struct Compiler *this, const uint16_t *name, const uint16_t *contents);
static uint8_t Compiler_finish(struct Compiler *this);
void assert(uint8_t truth);
void Profiler_begin();
void Profiler_end(const uint16_t *text);
static uint8_t isPositivePowerOf2(int32_t value);
static int32_t alignToNextMultipleOf(int32_t offset, int32_t alignment);
static void JsResult_emitIndent(struct JsResult *this);
static void JsResult_emitNewlineBefore(struct JsResult *this, struct Node *node);
static void JsResult_emitNewlineAfter(struct JsResult *this, struct Node *node);
static void JsResult_emitStatements(struct JsResult *this, struct Node *node);
static void JsResult_emitBlock(struct JsResult *this, struct Node *node);
static void JsResult_emitUnary(struct JsResult *this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator);
static void JsResult_emitBinary(struct JsResult *this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator, int32_t operatorPrecedence, int32_t mode);
static void JsResult_emitCommaSeparatedExpressions(struct JsResult *this, struct Node *start, struct Node *stop);
static void JsResult_emitExpression(struct JsResult *this, struct Node *node, int32_t parentPrecedence);
static void JsResult_emitSymbolName(struct JsResult *this, struct Symbol *symbol);
static void JsResult_emitStatement(struct JsResult *this, struct Node *node);
static uint8_t jsKindCastsOperandsToInt(int32_t kind);
static const uint16_t *jsEmit(struct Node *global, struct CheckContext *context);
static uint8_t isKeyword(int32_t kind);
static void splitToken(struct Token *first, int32_t firstKind, int32_t secondKind);
static const uint16_t *tokenToString(int32_t token);
static uint8_t isAlpha(uint16_t c);
static uint8_t isASCII(uint16_t c);
static uint8_t isNumber(uint16_t c);
static uint8_t isDigit(uint16_t c, uint8_t base);
static struct Token *tokenize(struct Source *source, struct Log *log);
static const uint16_t *library();
static struct LineColumn *Source_indexToLineColumn(struct Source *this, int32_t index);
static const uint16_t *Range_toString(struct Range *this);
static uint8_t Range_equals(struct Range *this, struct Range *other);
static struct Range *Range_enclosingLine(struct Range *this);
static struct Range *Range_rangeAtEnd(struct Range *this);
static struct Range *createRange(struct Source *source, int32_t start, int32_t end);
static struct Range *spanRanges(struct Range *left, struct Range *right);
static void Diagnostic_appendSourceName(struct Diagnostic *this, struct StringBuilder *builder, struct LineColumn *location);
static void Diagnostic_appendKind(struct Diagnostic *this, struct StringBuilder *builder);
static void Diagnostic_appendMessage(struct Diagnostic *this, struct StringBuilder *builder);
static void Diagnostic_appendLineContents(struct Diagnostic *this, struct StringBuilder *builder, struct LineColumn *location);
static void Diagnostic_appendRange(struct Diagnostic *this, struct StringBuilder *builder, struct LineColumn *location);
static void Log_error(struct Log *this, struct Range *range, const uint16_t *message);
static void Log_warning(struct Log *this, struct Range *range, const uint16_t *message);
static void Log_append(struct Log *this, struct Range *range, const uint16_t *message, int32_t kind);
static const uint16_t *Log_toString(struct Log *this);
static uint8_t Log_hasErrors(struct Log *this);
void Terminal_setColor(int32_t color);
void Terminal_write(const uint16_t *text);
const uint16_t *IO_readTextFile(const uint16_t *path);
uint8_t IO_writeTextFile(const uint16_t *path, const uint16_t *contents);
uint8_t IO_writeBinaryFile(const uint16_t *path, struct ByteArray *contents);
static void writeLogToTerminal(struct Log *log);
static void printError(const uint16_t *text);
void main_addArgument(const uint16_t *text);
const uint16_t *main_newString(uint32_t length);
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
static void Node_become(struct Node *this, struct Node *node);
static void Node_becomeSymbolReference(struct Node *this, struct Symbol *symbol);
static void Node_becomeIntegerConstant(struct Node *this, int32_t value);
static void Node_becomeBooleanConstant(struct Node *this, uint8_t value);
static uint8_t Node_isNegativeInteger(struct Node *this);
static uint8_t Node_isNonNegativeInteger(struct Node *this);
static uint8_t Node_isDeclare(struct Node *this);
static uint8_t Node_isExtern(struct Node *this);
static uint8_t Node_isDeclareOrExtern(struct Node *this);
static uint8_t Node_isGet(struct Node *this);
static uint8_t Node_isSet(struct Node *this);
static uint8_t Node_isOperator(struct Node *this);
static uint8_t Node_isPositive(struct Node *this);
static uint8_t Node_isPrivate(struct Node *this);
static uint8_t Node_isUnsafe(struct Node *this);
static uint8_t Node_isUnsignedOperator(struct Node *this);
static int32_t Node_childCount(struct Node *this);
static void Node_appendChild(struct Node *this, struct Node *child);
static void Node_insertChildBefore(struct Node *this, struct Node *after, struct Node *before);
static struct Node *Node_remove(struct Node *this);
static void Node_removeChildren(struct Node *this);
static void Node_replaceWith(struct Node *this, struct Node *node);
static uint8_t Node_isType(struct Node *this);
static uint8_t Node_isCallValue(struct Node *this);
static uint8_t Node_isAssignTarget(struct Node *this);
static struct Node *Node_withRange(struct Node *this, struct Range *range);
static struct Node *Node_withInternalRange(struct Node *this, struct Range *range);
static struct Node *Node_functionFirstArgumentIgnoringThis(struct Node *this);
static struct Node *Node_functionReturnType(struct Node *this);
static struct Node *Node_functionBody(struct Node *this);
static struct Node *Node_newType(struct Node *this);
static struct Node *Node_callValue(struct Node *this);
static struct Node *Node_castValue(struct Node *this);
static struct Node *Node_castType(struct Node *this);
static struct Node *Node_alignOfType(struct Node *this);
static struct Node *Node_sizeOfType(struct Node *this);
static struct Node *Node_dotTarget(struct Node *this);
static struct Node *Node_returnValue(struct Node *this);
static struct Node *Node_variableType(struct Node *this);
static struct Node *Node_variableValue(struct Node *this);
static struct Node *Node_expressionValue(struct Node *this);
static struct Node *Node_binaryLeft(struct Node *this);
static struct Node *Node_binaryRight(struct Node *this);
static struct Node *Node_unaryValue(struct Node *this);
static struct Node *Node_whileValue(struct Node *this);
static struct Node *Node_whileBody(struct Node *this);
static struct Node *Node_hookValue(struct Node *this);
static struct Node *Node_hookTrue(struct Node *this);
static struct Node *Node_hookFalse(struct Node *this);
static struct Node *Node_indexTarget(struct Node *this);
static struct Node *Node_ifValue(struct Node *this);
static struct Node *Node_ifTrue(struct Node *this);
static struct Node *Node_ifFalse(struct Node *this);
static uint8_t Node_expandCallIntoOperatorTree(struct Node *this);
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
static uint8_t ParserContext_peek(struct ParserContext *this, int32_t kind);
static uint8_t ParserContext_eat(struct ParserContext *this, int32_t kind);
static void ParserContext_advance(struct ParserContext *this);
static void ParserContext_unexpectedToken(struct ParserContext *this);
static uint8_t ParserContext_expect(struct ParserContext *this, int32_t kind);
static struct Node *ParserContext_parseUnaryPrefix(struct ParserContext *this, int32_t kind, int32_t mode);
static struct Node *ParserContext_parseBinary(struct ParserContext *this, int32_t kind, struct Node *left, int32_t localPrecedence, int32_t operatorPrecedence);
static struct Node *ParserContext_parseUnaryPostfix(struct ParserContext *this, int32_t kind, struct Node *value, int32_t localPrecedence);
static const uint16_t *ParserContext_parseQuotedString(struct ParserContext *this, struct Range *range);
static struct Node *ParserContext_parsePrefix(struct ParserContext *this, int32_t mode);
static struct Node *ParserContext_parseInfix(struct ParserContext *this, int32_t precedence, struct Node *node, int32_t mode);
static struct Node *ParserContext_parseArgumentList(struct ParserContext *this, struct Range *start, struct Node *node);
static struct Node *ParserContext_parseExpression(struct ParserContext *this, int32_t precedence, int32_t mode);
static struct Node *ParserContext_parseType(struct ParserContext *this);
static struct Node *ParserContext_parseIf(struct ParserContext *this);
static struct Node *ParserContext_parseWhile(struct ParserContext *this);
static struct Node *ParserContext_parseBody(struct ParserContext *this);
static struct Node *ParserContext_parseBlock(struct ParserContext *this);
static struct Node *ParserContext_parseReturn(struct ParserContext *this);
static struct Node *ParserContext_parseEmpty(struct ParserContext *this);
static struct Node *ParserContext_parseEnum(struct ParserContext *this, struct NodeFlag *firstFlag);
static struct Node *ParserContext_parseClass(struct ParserContext *this, struct NodeFlag *firstFlag);
static struct Node *ParserContext_parseFunction(struct ParserContext *this, struct NodeFlag *firstFlag, struct Node *parent);
static struct Node *ParserContext_parseVariables(struct ParserContext *this, struct NodeFlag *firstFlag, struct Node *parent);
static struct Node *ParserContext_parseLoopJump(struct ParserContext *this, int32_t kind);
static struct NodeFlag *ParserContext_parseFlags(struct ParserContext *this);
static struct Node *ParserContext_parseUnsafe(struct ParserContext *this);
static struct Node *ParserContext_parseStatement(struct ParserContext *this, int32_t mode);
static uint8_t ParserContext_parseStatements(struct ParserContext *this, struct Node *parent);
static uint8_t ParserContext_parseInt(struct ParserContext *this, struct Range *range, struct Node *node);
static struct Node *parse(struct Token *firstToken, struct Log *log);
static uint8_t Preprocessor_peek(struct Preprocessor *this, int32_t kind);
static uint8_t Preprocessor_eat(struct Preprocessor *this, int32_t kind);
static void Preprocessor_advance(struct Preprocessor *this);
static void Preprocessor_unexpectedToken(struct Preprocessor *this);
static uint8_t Preprocessor_expect(struct Preprocessor *this, int32_t kind);
static void Preprocessor_removeTokensFrom(struct Preprocessor *this, struct Token *before);
static uint8_t Preprocessor_isDefined(struct Preprocessor *this, const uint16_t *name);
static void Preprocessor_define(struct Preprocessor *this, const uint16_t *name, uint8_t isDefined);
static void Preprocessor_run(struct Preprocessor *this, struct Source *source, struct Log *log);
static uint8_t Preprocessor_scan(struct Preprocessor *this, uint8_t isParentLive);
static int32_t Preprocessor_parsePrefix(struct Preprocessor *this);
static int32_t Preprocessor_parseInfix(struct Preprocessor *this, int32_t precedence, int32_t left);
static int32_t Preprocessor_parseExpression(struct Preprocessor *this, int32_t precedence);
static struct Symbol *Scope_findLocal(struct Scope *this, const uint16_t *name, int32_t hint);
static struct Symbol *Scope_findNested(struct Scope *this, const uint16_t *name, int32_t hint, int32_t mode);
static uint8_t Scope_define(struct Scope *this, struct Log *log, struct Symbol *symbol, int32_t hint);
static struct Type *Scope_defineNativeType(struct Scope *this, struct Log *log, const uint16_t *name);
static void treeShakingMarkAllUsed(struct Node *node);
static void treeShakingSearchForUsed(struct Node *node);
static void treeShakingRemoveUnused(struct Node *node);
static void treeShaking(struct Node *node);
static struct StringBuilder *StringBuilder_new();
static void StringBuilder_appendQuoted(struct StringBuilder *sb, const uint16_t *text);
static void StringBuilder_clear(struct StringBuilder *this);
static struct StringBuilder *StringBuilder_appendChar(struct StringBuilder *this, uint16_t c);
static struct StringBuilder *StringBuilder_appendSlice(struct StringBuilder *this, const uint16_t *text, int32_t start, int32_t end);
static struct StringBuilder *StringBuilder_append(struct StringBuilder *this, const uint16_t *text);
static const uint16_t *StringBuilder_finish(struct StringBuilder *this);
static uint8_t isType(int32_t kind);
static uint8_t isFunction(int32_t kind);
static uint8_t isVariable(int32_t kind);
static uint8_t Symbol_isEnumValue(struct Symbol *this);
static uint8_t Symbol_isUnsafe(struct Symbol *this);
static uint8_t Symbol_isGetter(struct Symbol *this);
static uint8_t Symbol_isSetter(struct Symbol *this);
static uint8_t Symbol_isBinaryOperator(struct Symbol *this);
static uint8_t Symbol_isUnaryOperator(struct Symbol *this);
static uint8_t Symbol_shouldConvertInstanceToGlobal(struct Symbol *this);
static uint8_t Symbol_isUsed(struct Symbol *this);
static struct Symbol *Symbol_parent(struct Symbol *this);
static struct Type *Symbol_resolvedTypeUnderlyingIfEnumValue(struct Symbol *this, struct CheckContext *context);
static void Symbol_determineClassLayout(struct Symbol *this, struct CheckContext *context);
static uint8_t Type_isClass(struct Type *this);
static uint8_t Type_isEnum(struct Type *this);
static uint8_t Type_isInteger(struct Type *this);
static uint8_t Type_isUnsigned(struct Type *this);
static uint8_t Type_isReference(struct Type *this);
static struct Type *Type_underlyingType(struct Type *this, struct CheckContext *context);
static int32_t Type_integerBitCount(struct Type *this, struct CheckContext *context);
static uint32_t Type_integerBitMask(struct Type *this, struct CheckContext *context);
static int32_t Type_allocationSizeOf(struct Type *this, struct CheckContext *context);
static int32_t Type_allocationAlignmentOf(struct Type *this, struct CheckContext *context);
static int32_t Type_variableSizeOf(struct Type *this, struct CheckContext *context);
static int32_t Type_variableAlignmentOf(struct Type *this, struct CheckContext *context);
static struct Type *Type_pointerType(struct Type *this);
static const uint16_t *Type_toString(struct Type *this);
static struct Symbol *Type_findMember(struct Type *this, const uint16_t *name, int32_t hint);
static uint8_t Type_hasInstanceMembers(struct Type *this);
static uint8_t wasmAreSignaturesEqual(struct WasmSignature *a, struct WasmSignature *b);
static void WasmModule_growMemoryInitializer(struct WasmModule *this);
static struct WasmImport *WasmModule_allocateImport(struct WasmModule *this, int32_t signatureIndex, const uint16_t *mod, const uint16_t *name);
static struct WasmFunction *WasmModule_allocateFunction(struct WasmModule *this, const uint16_t *name, int32_t signatureIndex, struct Node *body);
static int32_t WasmModule_allocateSignature(struct WasmModule *this, struct WasmWrappedType *argumentTypes, struct WasmWrappedType *returnType);
static void WasmModule_emitModule(struct WasmModule *this, struct ByteArray *array);
static void WasmModule_emitSignatures(struct WasmModule *this, struct ByteArray *array);
static void WasmModule_emitImportTable(struct WasmModule *this, struct ByteArray *array);
static void WasmModule_emitFunctionSignatures(struct WasmModule *this, struct ByteArray *array);
static void WasmModule_emitMemory(struct WasmModule *this, struct ByteArray *array);
static void WasmModule_emitExportTable(struct WasmModule *this, struct ByteArray *array);
static void WasmModule_emitFunctionBodies(struct WasmModule *this, struct ByteArray *array);
static void WasmModule_emitDataSegments(struct WasmModule *this, struct ByteArray *array);
static void WasmModule_prepareToEmit(struct WasmModule *this, struct Node *node);
static void WasmModule_emitBinaryExpression(struct WasmModule *this, struct ByteArray *array, struct Node *node, uint8_t opcode);
static void WasmModule_emitLoadFromMemory(struct WasmModule *this, struct ByteArray *array, struct Type *type, struct Node *relativeBase, int32_t offset);
static void WasmModule_emitStoreToMemory(struct WasmModule *this, struct ByteArray *array, struct Type *type, struct Node *relativeBase, int32_t offset, struct Node *value);
static int32_t WasmModule_emitNode(struct WasmModule *this, struct ByteArray *array, struct Node *node);
static int32_t WasmModule_getWasmType(struct WasmModule *this, struct Type *type);
static void wasmPatchVarUnsigned(struct ByteArray *array, int32_t offset, int32_t value, int32_t maxValue);
static void wasmWriteVarUnsigned(struct ByteArray *array, int32_t value);
static void wasmWriteVarSigned(struct ByteArray *array, int32_t value);
static void wasmWriteLengthPrefixedASCII(struct ByteArray *array, const uint16_t *value);
static int32_t wasmStartSection(struct ByteArray *array, const uint16_t *name);
static void wasmFinishSection(struct ByteArray *array, int32_t offset);
static struct WasmWrappedType *wasmWrapType(int32_t id);
static void wasmAssignLocalVariableOffsets(struct Node *node, struct WasmSharedOffset *shared);
static void wasmEmit(struct Node *global, struct CheckContext *context, struct ByteArray *array);

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

static int32_t ByteArray_length(struct ByteArray *this) {
  return (int32_t)this->_length;
}

static void ByteArray_clear(struct ByteArray *this) {
  this->_length = 0;
}

static uint8_t ByteArray_get(struct ByteArray *this, int32_t index) {
  assert((uint32_t)index < this->_length);

  return *(this->_data + index);
}

static void ByteArray_set(struct ByteArray *this, int32_t index, uint8_t value) {
  assert((uint32_t)index < this->_length);
  *(this->_data + index) = value;
}

static void ByteArray_append(struct ByteArray *this, uint8_t value) {
  uint32_t offset = this->_length;
  ByteArray_resize(this, (int32_t)offset + 1);
  *(this->_data + offset) = value;
}

static void ByteArray_resize(struct ByteArray *this, int32_t length) {
  if ((uint32_t)length > this->_capacity) {
    uint32_t capacity = (uint32_t)length << 1;
    uint8_t *data = malloc(capacity);
    memcpy(data, this->_data, this->_length);
    this->_capacity = capacity;
    this->_data = data;
  }

  this->_length = (uint32_t)length;
}

static void CResult_emitIndent(struct CResult *this) {
  int32_t i = this->indent;

  while (i > 0) {
    StringBuilder_append(this->code, (const uint16_t *)__string_4);
    i = i - 1;
  }
}

static void CResult_emitNewlineBefore(struct CResult *this, struct Node *node) {
  if (this->previousNode != NULL && (!isCompactNodeKind(this->previousNode->kind) || !isCompactNodeKind(node->kind))) {
    StringBuilder_appendChar(this->code, 10);
  }

  this->previousNode = NULL;
}

static void CResult_emitNewlineAfter(struct CResult *this, struct Node *node) {
  this->previousNode = node;
}

static void CResult_emitStatements(struct CResult *this, struct Node *node) {
  while (node != NULL) {
    CResult_emitStatement(this, node);
    node = node->nextSibling;
  }
}

static void CResult_emitBlock(struct CResult *this, struct Node *node) {
  this->previousNode = NULL;
  StringBuilder_append(this->code, (const uint16_t *)__string_5);
  this->indent = this->indent + 1;
  CResult_emitStatements(this, node->firstChild);
  this->indent = this->indent - 1;
  CResult_emitIndent(this);
  StringBuilder_appendChar(this->code, 125);
  this->previousNode = NULL;
}

static void CResult_emitUnary(struct CResult *this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator) {
  uint8_t isPostfix = isUnaryPostfix(node->kind);
  int32_t operatorPrecedence = isPostfix ? 14 : 13;
  struct StringBuilder *code = this->code;

  if (parentPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 40);
  }

  if (!isPostfix) {
    StringBuilder_append(code, operator);
  }

  CResult_emitExpression(this, Node_unaryValue(node), operatorPrecedence);

  if (isPostfix) {
    StringBuilder_append(code, operator);
  }

  if (parentPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 41);
  }
}

static void CResult_emitBinary(struct CResult *this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator, int32_t operatorPrecedence) {
  int32_t kind = node->kind;
  uint8_t isRightAssociative = kind == 45;
  uint8_t needsParentheses = parentPrecedence > operatorPrecedence;
  int32_t parentKind = node->parent->kind;
  struct StringBuilder *code = this->code;

  if ((parentKind == 57 && kind == 56) || (parentKind == 47 && kind == 46) || ((parentKind == 50 || parentKind == 59) && (kind == 50 || kind == 59)) || ((kind == 44 || kind == 63) && (parentKind == 46 || parentKind == 47 || parentKind == 48 || parentKind == 61 || parentKind == 62))) {
    needsParentheses = 1;
  }

  if (needsParentheses) {
    StringBuilder_appendChar(code, 40);
  }

  CResult_emitExpression(this, Node_binaryLeft(node), isRightAssociative ? (int32_t)((int32_t)operatorPrecedence + 1) : operatorPrecedence);
  StringBuilder_append(code, operator);
  CResult_emitExpression(this, Node_binaryRight(node), isRightAssociative ? operatorPrecedence : (int32_t)((int32_t)operatorPrecedence + 1));

  if (needsParentheses) {
    StringBuilder_appendChar(code, 41);
  }
}

static void CResult_emitCommaSeparatedExpressions(struct CResult *this, struct Node *start, struct Node *stop) {
  while (start != stop) {
    CResult_emitExpression(this, start, 0);
    start = start->nextSibling;

    if (start != stop) {
      StringBuilder_append(this->code, (const uint16_t *)__string_6);
    }
  }
}

static void CResult_emitSymbolName(struct CResult *this, struct Symbol *symbol) {
  if (symbol->kind == 4) {
    StringBuilder_appendChar(StringBuilder_append(this->code, Symbol_parent(symbol)->name), 95);
  }

  StringBuilder_append(this->code, !string_op_equals(symbol->rename, NULL) ? symbol->rename : symbol->name);
}

static void CResult_emitCharacter(struct CResult *this, uint16_t c) {
  struct StringBuilder *codePrefix = this->codePrefix;

  if (isASCII(c)) {
    StringBuilder_appendChar(codePrefix, 39);

    if (c == 92 || c == 39) {
      StringBuilder_appendChar(codePrefix, 92);
    }

    StringBuilder_appendChar(codePrefix, c);
    StringBuilder_appendChar(codePrefix, 39);
  }

  else if (c == 0) {
    StringBuilder_append(codePrefix, (const uint16_t *)__string_7_0);
  }

  else if (c == 13) {
    StringBuilder_append(codePrefix, (const uint16_t *)__string_8_r);
  }

  else if (c == 10) {
    StringBuilder_append(codePrefix, (const uint16_t *)__string_9_n);
  }

  else if (c == 9) {
    StringBuilder_append(codePrefix, (const uint16_t *)__string_10_t);
  }

  else {
    StringBuilder_append(codePrefix, ushort_toString(c));
  }
}

static void CResult_emitExpression(struct CResult *this, struct Node *node, int32_t parentPrecedence) {
  struct StringBuilder *code = this->code;
  assert(node->resolvedType != NULL);

  if (node->kind == 25) {
    CResult_emitSymbolName(this, node->symbol);
  }

  else if (node->kind == 27) {
    StringBuilder_append(code, (const uint16_t *)__string_11_NULL);
  }

  else if (node->kind == 18) {
    StringBuilder_appendChar(code, node->intValue != 0 ? 49 : 48);
  }

  else if (node->kind == 24) {
    StringBuilder_append(code, Type_isUnsigned(node->resolvedType) ? uint_toString((uint32_t)node->intValue) : int_toString(node->intValue));
  }

  else if (node->kind == 30) {
    int32_t id = this->nextStringLiteral;
    struct StringBuilder *builder = StringBuilder_new();
    StringBuilder_append(StringBuilder_append(builder, (const uint16_t *)__string_12___string_), int_toString(id));
    const uint16_t *value = node->stringValue;
    struct StringBuilder *codePrefix = this->codePrefix;
    int32_t length = string_length(value);
    int32_t i = 0;

    if (!this->hasStrings) {
      StringBuilder_append(codePrefix, (const uint16_t *)__string_13_ifdef_THINSCRIPT_BIG_ENDIAN);
      this->hasStrings = 1;
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
    StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(codePrefix, (const uint16_t *)__string_14_static_const_uint32_t), name), (const uint16_t *)__string_15), int_toString(length));
    i = 0;

    while (i < length) {
      StringBuilder_append(codePrefix, (const uint16_t *)__string_16_S);
      CResult_emitCharacter(this, string_op_get(value, i));

      if (i + 1 < length) {
        StringBuilder_append(codePrefix, (const uint16_t *)__string_17);
        CResult_emitCharacter(this, string_op_get(value, i + 1));
        StringBuilder_appendChar(codePrefix, 41);
      }

      else {
        StringBuilder_append(codePrefix, (const uint16_t *)__string_18_0);
      }

      i = i + 2;
    }

    StringBuilder_append(codePrefix, (const uint16_t *)__string_19);
    this->nextStringLiteral = this->nextStringLiteral + 1;
    StringBuilder_append(StringBuilder_append(code, (const uint16_t *)__string_20_const_uint16_t), name);
  }

  else if (node->kind == 20) {
    if (parentPrecedence > 13) {
      StringBuilder_appendChar(code, 40);
    }

    StringBuilder_appendChar(code, 40);
    CResult_emitType(this, node->resolvedType, 0);
    StringBuilder_appendChar(code, 41);
    CResult_emitExpression(this, Node_castValue(node), 13);

    if (parentPrecedence > 13) {
      StringBuilder_appendChar(code, 41);
    }
  }

  else if (node->kind == 21) {
    struct Node *target = Node_dotTarget(node);
    CResult_emitExpression(this, target, 15);
    StringBuilder_append(code, Type_isReference(target->resolvedType) ? (const uint16_t *)__string_21 : (const uint16_t *)__string_22);
    CResult_emitSymbolName(this, node->symbol);
  }

  else if (node->kind == 22) {
    if (parentPrecedence > 1) {
      StringBuilder_appendChar(code, 40);
    }

    CResult_emitExpression(this, Node_hookValue(node), 2);
    StringBuilder_append(code, (const uint16_t *)__string_23);
    CResult_emitExpression(this, Node_hookTrue(node), 1);
    StringBuilder_append(code, (const uint16_t *)__string_24);
    CResult_emitExpression(this, Node_hookFalse(node), 1);

    if (parentPrecedence > 1) {
      StringBuilder_appendChar(code, 41);
    }
  }

  else if (node->kind == 19) {
    struct Node *value = Node_callValue(node);
    CResult_emitSymbolName(this, value->symbol);
    StringBuilder_appendChar(code, 40);

    if (value->kind == 21) {
      CResult_emitExpression(this, Node_dotTarget(value), 0);

      if (value->nextSibling != NULL) {
        StringBuilder_append(code, (const uint16_t *)__string_25);
      }
    }

    CResult_emitCommaSeparatedExpressions(this, value->nextSibling, NULL);
    StringBuilder_appendChar(code, 41);
  }

  else if (node->kind == 26) {
    StringBuilder_append(code, (const uint16_t *)__string_26_calloc_1_sizeof);
    CResult_emitType(this, node->resolvedType, 2);
    StringBuilder_append(code, (const uint16_t *)__string_27);
  }

  else if (node->kind == 34) {
    CResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_28);
  }

  else if (node->kind == 35) {
    CResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_29);
  }

  else if (node->kind == 36) {
    CResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_30);
  }

  else if (node->kind == 37) {
    CResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_31);
  }

  else if (node->kind == 39) {
    CResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_32);
  }

  else if (node->kind == 40) {
    CResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_33);
  }

  else if (node->kind == 41) {
    CResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_34);
  }

  else if (node->kind == 42) {
    CResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_35);
  }

  else if (node->kind == 43) {
    CResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_36);
  }

  else if (node->kind == 44) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_37, 10);
  }

  else if (node->kind == 45) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_38, 1);
  }

  else if (node->kind == 46) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_39, 6);
  }

  else if (node->kind == 47) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_40, 4);
  }

  else if (node->kind == 48) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_41, 5);
  }

  else if (node->kind == 49) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_42, 11);
  }

  else if (node->kind == 50) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_43, 7);
  }

  else if (node->kind == 52) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_44, 8);
  }

  else if (node->kind == 53) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_45, 8);
  }

  else if (node->kind == 54) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_46, 8);
  }

  else if (node->kind == 55) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_47, 8);
  }

  else if (node->kind == 56) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_48, 3);
  }

  else if (node->kind == 57) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_49, 2);
  }

  else if (node->kind == 58) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_50, 11);
  }

  else if (node->kind == 59) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_51, 7);
  }

  else if (node->kind == 60) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_52, 11);
  }

  else if (node->kind == 61) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_53, 9);
  }

  else if (node->kind == 62) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_54, 9);
  }

  else if (node->kind == 63) {
    CResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_55, 10);
  }

  else {
    assert(0);
  }
}

static uint8_t CResult_shouldEmitClass(struct CResult *this, struct Node *node) {
  assert(node->kind == 5);

  return node->symbol->kind == 0 && node->symbol != this->context->stringType->symbol;
}

static void CResult_emitType(struct CResult *this, struct Type *originalType, int32_t mode) {
  struct CheckContext *context = this->context;
  struct StringBuilder *code = this->code;
  struct Type *type = originalType;

  if (Type_isEnum(type)) {
    type = Type_underlyingType(type, this->context);
  }

  else {
    while (type->pointerTo != NULL) {
      type = type->pointerTo;
    }
  }

  if (Type_isClass(type)) {
    StringBuilder_append(code, (const uint16_t *)__string_56_struct);
  }

  if (type == context->boolType || type == context->byteType) {
    StringBuilder_append(code, (const uint16_t *)__string_57_uint8_t);
  }

  else if (type == context->sbyteType) {
    StringBuilder_append(code, (const uint16_t *)__string_58_int8_t);
  }

  else if (type == context->intType) {
    StringBuilder_append(code, (const uint16_t *)__string_59_int32_t);
  }

  else if (type == context->shortType) {
    StringBuilder_append(code, (const uint16_t *)__string_60_int16_t);
  }

  else if (type == context->stringType) {
    StringBuilder_append(code, (const uint16_t *)__string_61_const_uint16_t);
  }

  else if (type == context->uintType) {
    StringBuilder_append(code, (const uint16_t *)__string_62_uint32_t);
  }

  else if (type == context->ushortType) {
    StringBuilder_append(code, (const uint16_t *)__string_63_uint16_t);
  }

  else {
    CResult_emitSymbolName(this, type->symbol);
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
      StringBuilder_append(code, (const uint16_t *)__string_64);
    }

    else if (mode == 1) {
      StringBuilder_appendChar(code, 32);
    }
  }
}

static void CResult_emitStatement(struct CResult *this, struct Node *node) {
  struct StringBuilder *code = this->code;

  if (node->kind == 12) {
    CResult_emitNewlineBefore(this, node);
    CResult_emitIndent(this);

    while (1) {
      StringBuilder_append(code, (const uint16_t *)__string_65_if);
      CResult_emitExpression(this, Node_ifValue(node), 0);
      StringBuilder_append(code, (const uint16_t *)__string_66);
      CResult_emitBlock(this, Node_ifTrue(node));
      struct Node *no = Node_ifFalse(node);

      if (no == NULL) {
        StringBuilder_appendChar(code, 10);

        break;
      }

      StringBuilder_append(code, (const uint16_t *)__string_67);
      CResult_emitIndent(this);
      StringBuilder_append(code, (const uint16_t *)__string_68_else);

      if (no->firstChild == NULL || no->firstChild != no->lastChild || no->firstChild->kind != 12) {
        CResult_emitBlock(this, no);
        StringBuilder_appendChar(code, 10);

        break;
      }

      node = no->firstChild;
    }

    CResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 16) {
    CResult_emitNewlineBefore(this, node);
    CResult_emitIndent(this);
    StringBuilder_append(code, (const uint16_t *)__string_69_while);
    CResult_emitExpression(this, Node_whileValue(node), 0);
    StringBuilder_append(code, (const uint16_t *)__string_70);
    CResult_emitBlock(this, Node_whileBody(node));
    StringBuilder_appendChar(code, 10);
    CResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 4) {
    CResult_emitNewlineBefore(this, node);
    CResult_emitIndent(this);
    StringBuilder_append(code, (const uint16_t *)__string_71_break);
    CResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 7) {
    CResult_emitNewlineBefore(this, node);
    CResult_emitIndent(this);
    StringBuilder_append(code, (const uint16_t *)__string_72_continue);
    CResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 10) {
    CResult_emitNewlineBefore(this, node);
    CResult_emitIndent(this);
    CResult_emitExpression(this, Node_expressionValue(node), 0);
    StringBuilder_append(code, (const uint16_t *)__string_73);
    CResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 8) {
  }

  else if (node->kind == 13) {
    struct Node *value = Node_returnValue(node);
    CResult_emitNewlineBefore(this, node);
    CResult_emitIndent(this);

    if (value != NULL) {
      StringBuilder_append(code, (const uint16_t *)__string_74_return);
      CResult_emitExpression(this, value, 0);
      StringBuilder_append(code, (const uint16_t *)__string_75);
    }

    else {
      StringBuilder_append(code, (const uint16_t *)__string_76_return);
    }

    CResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 3) {
    if (node->parent->kind == 3) {
      CResult_emitStatements(this, node->firstChild);
    }

    else {
      CResult_emitNewlineBefore(this, node);
      CResult_emitIndent(this);
      CResult_emitBlock(this, node);
      StringBuilder_appendChar(code, 10);
      CResult_emitNewlineAfter(this, node);
    }
  }

  else if (node->kind == 15) {
    CResult_emitNewlineBefore(this, node);
    struct Node *child = node->firstChild;

    while (child != NULL) {
      struct Node *value = Node_variableValue(child);
      CResult_emitIndent(this);
      CResult_emitType(this, child->symbol->resolvedType, 1);
      CResult_emitSymbolName(this, child->symbol);
      assert(value != NULL);
      StringBuilder_append(code, (const uint16_t *)__string_77);
      CResult_emitExpression(this, value, 0);
      StringBuilder_append(code, (const uint16_t *)__string_78);
      child = child->nextSibling;
    }

    CResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 6 || node->kind == 9) {
  }

  else {
    assert(0);
  }
}

static void CResult_emitIncludes(struct CResult *this) {
  struct StringBuilder *code = this->codePrefix;
  StringBuilder_append(code, (const uint16_t *)__string_79_include_stdint_h);
  StringBuilder_append(code, (const uint16_t *)__string_80_include_stdlib_h);
  StringBuilder_append(code, (const uint16_t *)__string_81_include_string_h);
}

static void CResult_emitTypeDeclarations(struct CResult *this, struct Node *node) {
  struct StringBuilder *code = this->code;

  while (node != NULL) {
    if (node->kind == 5) {
      if (CResult_shouldEmitClass(this, node)) {
        CResult_emitNewlineBefore(this, node);
        StringBuilder_append(StringBuilder_append(StringBuilder_append(code, (const uint16_t *)__string_82_struct), node->symbol->name), (const uint16_t *)__string_83);
      }
    }

    node = node->nextSibling;
  }
}

static void CResult_emitTypeDefinitions(struct CResult *this, struct Node *node) {
  struct StringBuilder *code = this->code;

  while (node != NULL) {
    if (node->kind == 5) {
      if (CResult_shouldEmitClass(this, node)) {
        CResult_emitNewlineBefore(this, node);
        StringBuilder_append(code, (const uint16_t *)__string_84_struct);
        CResult_emitSymbolName(this, node->symbol);
        StringBuilder_append(code, (const uint16_t *)__string_85);
        this->indent = this->indent + 1;
        struct Node *child = node->firstChild;

        while (child != NULL) {
          if (child->kind == 2) {
            CResult_emitIndent(this);
            CResult_emitType(this, child->symbol->resolvedType, 1);
            CResult_emitSymbolName(this, child->symbol);
            StringBuilder_append(code, (const uint16_t *)__string_86);
          }

          child = child->nextSibling;
        }

        this->indent = this->indent - 1;
        StringBuilder_append(code, (const uint16_t *)__string_87);
        CResult_emitNewlineAfter(this, node);
      }
    }

    node = node->nextSibling;
  }
}

static uint8_t CResult_shouldEmitFunction(struct CResult *this, struct Symbol *symbol) {
  return symbol->kind != 5 || (!string_op_equals(symbol->name, (const uint16_t *)__string_88_malloc) && !string_op_equals(symbol->name, (const uint16_t *)__string_89_memcpy) && !string_op_equals(symbol->name, (const uint16_t *)__string_90_memcmp));
}

static void CResult_emitFunctionDeclarations(struct CResult *this, struct Node *node) {
  struct StringBuilder *code = this->code;

  while (node != NULL) {
    if (node->kind == 11) {
      struct Symbol *symbol = node->symbol;

      if (CResult_shouldEmitFunction(this, symbol)) {
        struct Node *returnType = Node_functionReturnType(node);
        struct Node *child = node->firstChild;
        CResult_emitNewlineBefore(this, node);

        if (!Node_isDeclareOrExtern(node)) {
          StringBuilder_append(code, (const uint16_t *)__string_91_static);
        }

        CResult_emitType(this, returnType->resolvedType, 1);
        CResult_emitSymbolName(this, symbol);
        StringBuilder_appendChar(code, 40);

        while (child != returnType) {
          assert(child->kind == 2);
          CResult_emitType(this, child->symbol->resolvedType, 1);
          CResult_emitSymbolName(this, child->symbol);
          child = child->nextSibling;

          if (child != returnType) {
            StringBuilder_append(code, (const uint16_t *)__string_92);
          }
        }

        StringBuilder_append(code, (const uint16_t *)__string_93);
      }
    }

    else if (node->kind == 5) {
      CResult_emitFunctionDeclarations(this, node->firstChild);
    }

    node = node->nextSibling;
  }
}

static void CResult_emitGlobalVariables(struct CResult *this, struct Node *node) {
  struct StringBuilder *code = this->code;

  while (node != NULL) {
    if (node->kind == 2) {
      struct Node *value = Node_variableValue(node);
      CResult_emitNewlineBefore(this, node);

      if (!Node_isDeclareOrExtern(node)) {
        StringBuilder_append(code, (const uint16_t *)__string_94_static);
      }

      CResult_emitType(this, node->symbol->resolvedType, 1);
      CResult_emitSymbolName(this, node->symbol);
      StringBuilder_append(code, (const uint16_t *)__string_95);
      CResult_emitExpression(this, value, 0);
      StringBuilder_append(code, (const uint16_t *)__string_96);
    }

    else if (node->kind == 15) {
      CResult_emitGlobalVariables(this, node->firstChild);
    }

    node = node->nextSibling;
  }
}

static void CResult_emitFunctionDefinitions(struct CResult *this, struct Node *node) {
  struct StringBuilder *code = this->code;

  while (node != NULL) {
    if (node->kind == 11) {
      struct Node *body = Node_functionBody(node);
      struct Symbol *symbol = node->symbol;

      if (body != NULL && CResult_shouldEmitFunction(this, symbol)) {
        struct Node *returnType = Node_functionReturnType(node);
        struct Node *child = node->firstChild;
        CResult_emitNewlineBefore(this, node);

        if (!Node_isDeclareOrExtern(node)) {
          StringBuilder_append(code, (const uint16_t *)__string_97_static);
        }

        CResult_emitType(this, returnType->resolvedType, 1);
        CResult_emitSymbolName(this, symbol);
        StringBuilder_appendChar(code, 40);

        while (child != returnType) {
          assert(child->kind == 2);
          CResult_emitType(this, child->symbol->resolvedType, 1);
          CResult_emitSymbolName(this, child->symbol);
          child = child->nextSibling;

          if (child != returnType) {
            StringBuilder_append(code, (const uint16_t *)__string_98);
          }
        }

        StringBuilder_append(code, (const uint16_t *)__string_99);
        CResult_emitBlock(this, Node_functionBody(node));
        StringBuilder_appendChar(code, 10);
        CResult_emitNewlineAfter(this, node);
      }
    }

    else if (node->kind == 5) {
      CResult_emitFunctionDefinitions(this, node->firstChild);
    }

    node = node->nextSibling;
  }
}

static void CResult_finish(struct CResult *this) {
  if (this->hasStrings) {
    StringBuilder_append(this->codePrefix, (const uint16_t *)__string_100_undef_S);
  }
}

static const uint16_t *cEmit(struct Node *global, struct CheckContext *context) {
  struct Node *child = global->firstChild;
  struct StringBuilder *code = StringBuilder_new();
  struct StringBuilder *codePrefix = StringBuilder_new();
  struct CResult *result = calloc(1, sizeof(struct CResult));
  result->context = context;
  result->code = code;
  result->codePrefix = codePrefix;

  if (child != NULL) {
    CResult_emitIncludes(result);
    CResult_emitNewlineAfter(result, child);
    CResult_emitTypeDeclarations(result, child);
    CResult_emitNewlineAfter(result, child);
    CResult_emitTypeDefinitions(result, child);
    CResult_emitNewlineAfter(result, child);
    CResult_emitFunctionDeclarations(result, child);
    CResult_emitNewlineAfter(result, child);
    CResult_emitGlobalVariables(result, child);
    CResult_emitNewlineAfter(result, child);
    CResult_emitFunctionDefinitions(result, child);
    CResult_finish(result);
  }

  StringBuilder_append(codePrefix, StringBuilder_finish(code));

  return StringBuilder_finish(codePrefix);
}

static int32_t CheckContext_allocateGlobalVariableOffset(struct CheckContext *this, int32_t sizeOf, int32_t alignmentOf) {
  int32_t offset = alignToNextMultipleOf(this->nextGlobalVariableOffset, alignmentOf);
  this->nextGlobalVariableOffset = offset + sizeOf;

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

    if (kind != 2 && kind != 15 && (kind != 11 || parentKind != 5) && (parentKind == 0) != (kind == 5 || kind == 9 || kind == 11 || kind == 6)) {
      Log_error(context->log, node->range, (const uint16_t *)__string_101_This_statement_is_not_allowed_he);
    }
  }

  if (kind == 5 || kind == 9) {
    assert(node->symbol == NULL);
    struct Symbol *symbol = calloc(1, sizeof(struct Symbol));
    symbol->kind = kind == 5 ? 0 : 1;
    symbol->name = node->stringValue;
    symbol->resolvedType = calloc(1, sizeof(struct Type));
    symbol->resolvedType->symbol = symbol;
    symbol->flags = 4;
    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    Scope_define(parentScope, context->log, symbol, 0);
    parentScope = symbol->scope;
  }

  else if (kind == 11) {
    assert(node->symbol == NULL);
    struct Symbol *symbol = calloc(1, sizeof(struct Symbol));
    symbol->kind = node->parent->kind == 5 ? 4 : 5;
    symbol->name = node->stringValue;

    if (Node_isOperator(node)) {
      if (string_op_equals(symbol->name, (const uint16_t *)__string_102) || string_op_equals(symbol->name, (const uint16_t *)__string_103)) {
        if (node->firstChild == Node_functionReturnType(node)) {
          symbol->flags = 8;
          symbol->rename = string_op_equals(symbol->name, (const uint16_t *)__string_104) ? (const uint16_t *)__string_105_op_positive : (const uint16_t *)__string_106_op_negative;
        }

        else {
          symbol->flags = 2;
          symbol->rename = string_op_equals(symbol->name, (const uint16_t *)__string_107) ? (const uint16_t *)__string_108_op_add : (const uint16_t *)__string_109_op_subtract;
        }
      }

      else {
        symbol->rename = string_op_equals(symbol->name, (const uint16_t *)__string_110) ? (const uint16_t *)__string_111_op_remainder : string_op_equals(symbol->name, (const uint16_t *)__string_112) ? (const uint16_t *)__string_113_op_and : string_op_equals(symbol->name, (const uint16_t *)__string_114) ? (const uint16_t *)__string_115_op_multiply : string_op_equals(symbol->name, (const uint16_t *)__string_116) ? (const uint16_t *)__string_117_op_exponent : string_op_equals(symbol->name, (const uint16_t *)__string_118) ? (const uint16_t *)__string_119_op_increment : string_op_equals(symbol->name, (const uint16_t *)__string_120) ? (const uint16_t *)__string_121_op_decrement : string_op_equals(symbol->name, (const uint16_t *)__string_122) ? (const uint16_t *)__string_123_op_divide : string_op_equals(symbol->name, (const uint16_t *)__string_124) ? (const uint16_t *)__string_125_op_lessThan : string_op_equals(symbol->name, (const uint16_t *)__string_126) ? (const uint16_t *)__string_127_op_shiftLeft : string_op_equals(symbol->name, (const uint16_t *)__string_128) ? (const uint16_t *)__string_129_op_equals : string_op_equals(symbol->name, (const uint16_t *)__string_130) ? (const uint16_t *)__string_131_op_greaterThan : string_op_equals(symbol->name, (const uint16_t *)__string_132) ? (const uint16_t *)__string_133_op_shiftRight : string_op_equals(symbol->name, (const uint16_t *)__string_134) ? (const uint16_t *)__string_135_op_get : string_op_equals(symbol->name, (const uint16_t *)__string_136) ? (const uint16_t *)__string_137_op_set : string_op_equals(symbol->name, (const uint16_t *)__string_138) ? (const uint16_t *)__string_139_op_xor : string_op_equals(symbol->name, (const uint16_t *)__string_140) ? (const uint16_t *)__string_141_op_or : string_op_equals(symbol->name, (const uint16_t *)__string_142) ? (const uint16_t *)__string_143_op_complement : NULL;
      }
    }

    addScopeToSymbol(symbol, parentScope);
    linkSymbolToNode(symbol, node);
    Scope_define(parentScope, context->log, symbol, Symbol_isSetter(symbol) ? 2 : Symbol_isGetter(symbol) ? 3 : Symbol_isBinaryOperator(symbol) ? 4 : Symbol_isUnaryOperator(symbol) ? 1 : 0);
    parentScope = symbol->scope;

    if (symbol->kind == 4) {
      struct Symbol *parent = Symbol_parent(symbol);
      initializeSymbol(context, parent);
      Node_insertChildBefore(node, node->firstChild, createVariable((const uint16_t *)__string_144_this, createType(parent->resolvedType), NULL));
    }
  }

  else if (kind == 2) {
    assert(node->symbol == NULL);
    struct Symbol *symbol = calloc(1, sizeof(struct Symbol));
    symbol->kind = node->parent->kind == 5 ? 9 : node->parent->kind == 11 ? 6 : node->parent->kind == 6 || node->parent->kind == 9 ? 7 : node->parent->kind == 15 && node->parent->parent->kind == 0 ? 8 : 10;
    symbol->name = node->stringValue;
    symbol->scope = parentScope;
    linkSymbolToNode(symbol, node);
    Scope_define(parentScope, context->log, symbol, 0);
  }

  else if (kind == 3) {
    if (node->parent->kind != 11) {
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

  if (kind == 0 && mode == 1) {
    context->boolType = Scope_findLocal(parentScope, (const uint16_t *)__string_145_bool, 0)->resolvedType;
    context->byteType = Scope_findLocal(parentScope, (const uint16_t *)__string_146_byte, 0)->resolvedType;
    context->intType = Scope_findLocal(parentScope, (const uint16_t *)__string_147_int, 0)->resolvedType;
    context->sbyteType = Scope_findLocal(parentScope, (const uint16_t *)__string_148_sbyte, 0)->resolvedType;
    context->shortType = Scope_findLocal(parentScope, (const uint16_t *)__string_149_short, 0)->resolvedType;
    context->stringType = Scope_findLocal(parentScope, (const uint16_t *)__string_150_string, 0)->resolvedType;
    context->uintType = Scope_findLocal(parentScope, (const uint16_t *)__string_151_uint, 0)->resolvedType;
    context->ushortType = Scope_findLocal(parentScope, (const uint16_t *)__string_152_ushort, 0)->resolvedType;
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
  forbidFlag(context, node, 2, (const uint16_t *)__string_153_Unsupported_flag_export);
  forbidFlag(context, node, 128, (const uint16_t *)__string_154_Unsupported_flag_protected);
  forbidFlag(context, node, 1024, (const uint16_t *)__string_155_Unsupported_flag_static);

  if (symbol->kind == 0 || symbol->kind == 3) {
    forbidFlag(context, node, 8, (const uint16_t *)__string_156_Cannot_use_get_on_a_class);
    forbidFlag(context, node, 512, (const uint16_t *)__string_157_Cannot_use_set_on_a_class);
    forbidFlag(context, node, 256, (const uint16_t *)__string_158_Cannot_use_public_on_a_class);
    forbidFlag(context, node, 64, (const uint16_t *)__string_159_Cannot_use_private_on_a_class);
  }

  else if (symbol->kind == 1) {
    forbidFlag(context, node, 8, (const uint16_t *)__string_160_Cannot_use_get_on_an_enum);
    forbidFlag(context, node, 512, (const uint16_t *)__string_161_Cannot_use_set_on_an_enum);
    forbidFlag(context, node, 256, (const uint16_t *)__string_162_Cannot_use_public_on_an_enum);
    forbidFlag(context, node, 64, (const uint16_t *)__string_163_Cannot_use_private_on_an_enum);
    symbol->resolvedType = calloc(1, sizeof(struct Type));
    symbol->resolvedType->symbol = symbol;
    struct Symbol *underlyingSymbol = Type_underlyingType(symbol->resolvedType, context)->symbol;
    symbol->byteSize = underlyingSymbol->byteSize;
    symbol->maxAlignment = underlyingSymbol->maxAlignment;
  }

  else if (isFunction(symbol->kind)) {
    struct Node *body = Node_functionBody(node);
    struct Node *returnType = Node_functionReturnType(node);
    uint8_t oldUnsafeAllowed = context->isUnsafeAllowed;
    context->isUnsafeAllowed = Node_isUnsafe(node);
    resolveAsType(context, returnType, symbol->scope->parent);
    int32_t argumentCount = 0;
    struct Node *child = node->firstChild;

    while (child != returnType) {
      assert(child->kind == 2);
      assert(child->symbol->kind == 6);
      initializeSymbol(context, child->symbol);
      child->symbol->offset = argumentCount;
      argumentCount = argumentCount + 1;
      child = child->nextSibling;
    }

    if (symbol->kind != 4) {
      forbidFlag(context, node, 8, (const uint16_t *)__string_164_Cannot_use_get_here);
      forbidFlag(context, node, 512, (const uint16_t *)__string_165_Cannot_use_set_here);
      forbidFlag(context, node, 256, (const uint16_t *)__string_166_Cannot_use_public_here);
      forbidFlag(context, node, 64, (const uint16_t *)__string_167_Cannot_use_private_here);
    }

    else if (Node_isGet(node)) {
      forbidFlag(context, node, 512, (const uint16_t *)__string_168_Cannot_use_both_get_and_set);

      if (argumentCount != 1) {
        Log_error(context->log, symbol->range, (const uint16_t *)__string_169_Getters_must_not_have_any_argume);
      }
    }

    else if (Node_isSet(node)) {
      symbol->rename = StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_170_set_), symbol->name));

      if (argumentCount != 2) {
        Log_error(context->log, symbol->range, (const uint16_t *)__string_171_Setters_must_have_exactly_one_ar);
      }
    }

    else if (Node_isOperator(node)) {
      if (string_op_equals(symbol->name, (const uint16_t *)__string_172) || string_op_equals(symbol->name, (const uint16_t *)__string_173) || string_op_equals(symbol->name, (const uint16_t *)__string_174)) {
        if (argumentCount != 1) {
          Log_error(context->log, symbol->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_175_Operator), symbol->name), (const uint16_t *)__string_176_must_not_have_any_arguments)));
        }
      }

      else if (string_op_equals(symbol->name, (const uint16_t *)__string_177) || string_op_equals(symbol->name, (const uint16_t *)__string_178)) {
        if (argumentCount > 2) {
          Log_error(context->log, symbol->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_179_Operator), symbol->name), (const uint16_t *)__string_180_must_have_at_most_one_argument)));
        }
      }

      else if (string_op_equals(symbol->name, (const uint16_t *)__string_181)) {
        if (argumentCount < 2) {
          Log_error(context->log, symbol->range, (const uint16_t *)__string_182_Operator_must_have_at_leas);
        }
      }

      else if (argumentCount != 2) {
        Log_error(context->log, symbol->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_183_Operator), symbol->name), (const uint16_t *)__string_184_must_have_exactly_one_argument)));
      }
    }

    symbol->resolvedType = calloc(1, sizeof(struct Type));
    symbol->resolvedType->symbol = symbol;

    if (symbol->kind == 4) {
      struct Symbol *parent = Symbol_parent(symbol);
      uint8_t shouldConvertInstanceToGlobal = 0;
      forbidFlag(context, node, 4, (const uint16_t *)__string_185_Cannot_use_extern_on_an_instan);
      forbidFlag(context, node, 1, (const uint16_t *)__string_186_Cannot_use_declare_on_an_insta);

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
          Log_error(context->log, node->lastChild->range, (const uint16_t *)__string_187_Must_implement_this_function);
        }

        if (Node_isExtern(parent->node)) {
          node->flags = node->flags | 4;
        }
      }

      if (shouldConvertInstanceToGlobal) {
        symbol->kind = 5;
        symbol->flags = symbol->flags | 1;
        symbol->rename = StringBuilder_finish(StringBuilder_append(StringBuilder_appendChar(StringBuilder_append(StringBuilder_new(), parent->name), 95), !string_op_equals(symbol->rename, NULL) ? symbol->rename : symbol->name));
        assert(string_op_equals(node->firstChild->symbol->name, (const uint16_t *)__string_188_this));
        node->firstChild->symbol->rename = (const uint16_t *)__string_189___this;
      }
    }

    else if (body == NULL) {
      forbidFlag(context, node, 4, (const uint16_t *)__string_190_Cannot_use_extern_on_an_unimpl);
      requireFlag(context, node, 1, (const uint16_t *)__string_191_Declared_functions_must_be_prefi);
    }

    else {
      forbidFlag(context, node, 1, (const uint16_t *)__string_192_Cannot_use_declare_on_a_functi);
    }

    context->isUnsafeAllowed = oldUnsafeAllowed;
  }

  else if (isVariable(symbol->kind)) {
    forbidFlag(context, node, 8, (const uint16_t *)__string_193_Cannot_use_get_on_a_variable);
    forbidFlag(context, node, 512, (const uint16_t *)__string_194_Cannot_use_set_on_a_variable);
    struct Node *type = Node_variableType(node);
    struct Node *value = Node_variableValue(node);
    uint8_t oldUnsafeAllowed = context->isUnsafeAllowed;
    context->isUnsafeAllowed = context->isUnsafeAllowed || Node_isUnsafe(node);

    if (symbol->kind != 9) {
      forbidFlag(context, node, 256, (const uint16_t *)__string_195_Cannot_use_public_here);
      forbidFlag(context, node, 64, (const uint16_t *)__string_196_Cannot_use_private_here);
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
      Log_error(context->log, node->internalRange, (const uint16_t *)__string_197_Cannot_create_untyped_variables);
      symbol->resolvedType = context->errorType;
    }

    if (symbol->resolvedType == context->voidType || symbol->resolvedType == context->nullType) {
      Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_198_Cannot_create_a_variable_with_ty), Type_toString(symbol->resolvedType)), 39)));
      symbol->resolvedType = context->errorType;
    }

    if (symbol->kind == 7) {
      if (value != NULL) {
        resolveAsExpression(context, value, symbol->scope);
        checkConversion(context, value, Symbol_resolvedTypeUnderlyingIfEnumValue(symbol, context), 0);

        if (value->kind == 24 || value->kind == 18) {
          symbol->offset = value->intValue;
        }

        else if (value->resolvedType != context->errorType) {
          Log_error(context->log, value->range, (const uint16_t *)__string_199_Invalid_constant_initializer);
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
        Log_error(context->log, node->internalRange, (const uint16_t *)__string_200_Constants_must_be_initialized);
      }
    }

    if (symbol->scope->symbol == NULL) {
      struct Scope *scope = symbol->scope->parent;

      while (scope != NULL) {
        struct Symbol *shadowed = Scope_findLocal(scope, symbol->name, 0);

        if (shadowed != NULL) {
          Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_201_The_symbol), symbol->name), (const uint16_t *)__string_202_shadows_another_symbol_with_th)));

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

  if (node->resolvedType != context->errorType) {
    if (Node_isType(node)) {
      Log_error(context->log, node->range, (const uint16_t *)__string_203_Expected_expression_but_found_ty);
      node->resolvedType = context->errorType;
    }

    else if (node->resolvedType == context->voidType && node->parent->kind != 10) {
      Log_error(context->log, node->range, (const uint16_t *)__string_204_This_expression_does_not_return);
      node->resolvedType = context->errorType;
    }
  }
}

static void resolveAsType(struct CheckContext *context, struct Node *node, struct Scope *parentScope) {
  assert(isExpression(node));
  resolve(context, node, parentScope);

  if (node->resolvedType != context->errorType && !Node_isType(node)) {
    Log_error(context->log, node->range, (const uint16_t *)__string_205_Expected_type_but_found_expressi);
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

    if (kind == 1 || from->symbol->byteSize < to->symbol->byteSize || (node->kind == 24 && (Type_isUnsigned(to) ? node->intValue >= 0 && (uint32_t)node->intValue <= mask : node->intValue >= (int32_t)~mask >> 1 && node->intValue <= (int32_t)(mask >> 1)))) {
      return 1;
    }
  }

  return 0;
}

static void checkConversion(struct CheckContext *context, struct Node *node, struct Type *to, int32_t kind) {
  if (!canConvert(context, node, to, kind)) {
    Log_error(context->log, node->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_206_Cannot_convert_from_type), Type_toString(node->resolvedType)), (const uint16_t *)__string_207_to_type), Type_toString(to)), kind == 0 && canConvert(context, node, to, 1) ? (const uint16_t *)__string_208_without_a_cast : (const uint16_t *)__string_209)));
    node->resolvedType = context->errorType;
  }
}

static void checkStorage(struct CheckContext *context, struct Node *target) {
  assert(isExpression(target));

  if (target->resolvedType != context->errorType && target->kind != 23 && target->kind != 35 && ((target->kind != 25 && target->kind != 21) || (target->symbol != NULL && (!isVariable(target->symbol->kind) || target->symbol->kind == 7)))) {
    Log_error(context->log, target->range, (const uint16_t *)__string_210_Cannot_store_to_this_location);
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

  if ((node->kind == 44 || node->kind == 58 || node->kind == 46 || node->kind == 47 || node->kind == 48) && left->kind == 24 && right->kind != 24) {
    Node_appendChild(node, Node_remove(left));
    left = Node_binaryLeft(node);
    right = Node_binaryRight(node);
  }

  if ((node->kind == 58 || ((node->kind == 49 || node->kind == 60) && Type_isUnsigned(node->resolvedType))) && right->kind == 24 && isPositivePowerOf2(right->intValue)) {
    int32_t shift = -1;
    int32_t value = right->intValue;

    while (value != 0) {
      value = value >> 1;
      shift = shift + 1;
    }

    if (node->kind == 58) {
      node->kind = 61;
      right->intValue = shift;
    }

    else if (node->kind == 49) {
      node->kind = 62;
      right->intValue = shift;
    }

    else if (node->kind == 60) {
      node->kind = 46;
      right->intValue = right->intValue - 1;
    }

    else {
      assert(0);
    }
  }

  else if (node->kind == 44 && right->kind == 36) {
    node->kind = 63;
    Node_replaceWith(right, Node_remove(Node_unaryValue(right)));
  }

  else if (node->kind == 44 && Node_isNegativeInteger(right)) {
    node->kind = 63;
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
    Log_error(context->log, range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_211_Cannot_use_symbol), symbol->name), (const uint16_t *)__string_212_outside_an_unsafe_block)));

    return 0;
  }

  if (symbol->node != NULL && Node_isPrivate(symbol->node)) {
    struct Symbol *parent = Symbol_parent(symbol);

    if (parent != NULL && context->enclosingClass != parent) {
      Log_error(context->log, range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_213_Cannot_access_private_symbol), symbol->name), (const uint16_t *)__string_214_here)));

      return 0;
    }
  }

  if (isFunction(symbol->kind) && (Symbol_isSetter(symbol) ? !Node_isAssignTarget(node) : !Node_isCallValue(node))) {
    if (Symbol_isSetter(symbol)) {
      Log_error(context->log, range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_215_Cannot_use_setter), symbol->name), (const uint16_t *)__string_216_here)));
    }

    else {
      Log_error(context->log, range, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_217_Must_call_function), symbol->name), 39)));
    }

    return 0;
  }

  return 1;
}

static void resolve(struct CheckContext *context, struct Node *node, struct Scope *parentScope) {
  int32_t kind = node->kind;
  assert(kind == 0 || parentScope != NULL);

  if (node->resolvedType != NULL) {
    return;
  }

  node->resolvedType = context->errorType;

  if (kind == 0 || kind == 1) {
    resolveChildren(context, node, parentScope);
  }

  else if (kind == 5) {
    struct Symbol *oldEnclosingClass = context->enclosingClass;
    initializeSymbol(context, node->symbol);
    context->enclosingClass = node->symbol;
    resolveChildren(context, node, node->scope);

    if (node->symbol->kind == 0) {
      Symbol_determineClassLayout(node->symbol, context);
    }

    context->enclosingClass = oldEnclosingClass;
  }

  else if (kind == 9) {
    initializeSymbol(context, node->symbol);
    resolveChildren(context, node, node->scope);
  }

  else if (kind == 11) {
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

  else if (kind == 2) {
    struct Symbol *symbol = node->symbol;
    initializeSymbol(context, symbol);
    uint8_t oldUnsafeAllowed = context->isUnsafeAllowed;
    context->isUnsafeAllowed = context->isUnsafeAllowed || Node_isUnsafe(node);
    struct Node *value = Node_variableValue(node);

    if (value != NULL) {
      resolveAsExpression(context, value, parentScope);
      checkConversion(context, value, Symbol_resolvedTypeUnderlyingIfEnumValue(symbol, context), 0);

      if (symbol->kind == 8 && value->kind != 24 && value->kind != 18 && value->kind != 27) {
        Log_error(context->log, value->range, (const uint16_t *)__string_218_Global_initializers_must_be_comp);
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

  else if (kind == 4 || kind == 7) {
    uint8_t found = 0;
    struct Node *n = node;

    while (n != NULL) {
      if (n->kind == 16) {
        found = 1;

        break;
      }

      n = n->parent;
    }

    if (!found) {
      Log_error(context->log, node->range, (const uint16_t *)__string_219_Cannot_use_this_statement_outsid);
    }
  }

  else if (kind == 3) {
    uint8_t oldUnsafeAllowed = context->isUnsafeAllowed;

    if (Node_isUnsafe(node)) {
      context->isUnsafeAllowed = 1;
    }

    resolveChildren(context, node, node->scope);
    context->isUnsafeAllowed = oldUnsafeAllowed;
  }

  else if (kind == 6 || kind == 15) {
    resolveChildren(context, node, parentScope);
  }

  else if (kind == 24) {
    node->resolvedType = node->intValue < 0 && !Node_isPositive(node) ? context->uintType : context->intType;
  }

  else if (kind == 30) {
    node->resolvedType = context->stringType;
  }

  else if (kind == 18) {
    node->resolvedType = context->boolType;
  }

  else if (kind == 27) {
    node->resolvedType = context->nullType;
  }

  else if (kind == 23) {
    resolveChildrenAsExpressions(context, node, parentScope);
    struct Node *target = Node_indexTarget(node);
    struct Type *type = target->resolvedType;

    if (type != context->errorType) {
      struct Symbol *symbol = Type_hasInstanceMembers(type) ? Type_findMember(type, (const uint16_t *)__string_220, 0) : NULL;

      if (symbol == NULL) {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_221_Cannot_index_into_type), Type_toString(target->resolvedType)), 39)));
      }

      else {
        assert(symbol->kind == 4 || (symbol->kind == 5 && Symbol_shouldConvertInstanceToGlobal(symbol)));
        node->kind = 19;
        Node_remove(target);
        Node_insertChildBefore(node, node->firstChild, createMemberReference(target, symbol));
        node->resolvedType = NULL;
        resolveAsExpression(context, node, parentScope);
      }
    }
  }

  else if (kind == 17) {
    struct Node *type = Node_alignOfType(node);
    resolveAsType(context, type, parentScope);
    node->resolvedType = context->intType;

    if (type->resolvedType != context->errorType) {
      Node_becomeIntegerConstant(node, Type_allocationAlignmentOf(type->resolvedType, context));
    }
  }

  else if (kind == 29) {
    struct Node *type = Node_sizeOfType(node);
    resolveAsType(context, type, parentScope);
    node->resolvedType = context->intType;

    if (type->resolvedType != context->errorType) {
      Node_becomeIntegerConstant(node, Type_allocationSizeOf(type->resolvedType, context));
    }
  }

  else if (kind == 31) {
    struct Symbol *symbol = Scope_findNested(parentScope, (const uint16_t *)__string_222_this, 0, 0);

    if (symbol == NULL) {
      Log_error(context->log, node->range, (const uint16_t *)__string_223_Cannot_use_this_here);
    }

    else {
      Node_becomeSymbolReference(node, symbol);
    }
  }

  else if (kind == 28) {
    node->resolvedType = context->errorType;
  }

  else if (kind == 25) {
    const uint16_t *name = node->stringValue;
    struct Symbol *symbol = Scope_findNested(parentScope, name, 0, 0);

    if (symbol == NULL) {
      struct StringBuilder *builder = StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_224_No_symbol_named), name), (const uint16_t *)__string_225_here);
      symbol = Scope_findNested(parentScope, name, 0, 1);

      if (symbol != NULL) {
        StringBuilder_append(StringBuilder_append(StringBuilder_append(builder, (const uint16_t *)__string_226_did_you_mean_this), symbol->name), (const uint16_t *)__string_227);
      }

      else if (string_op_equals(name, (const uint16_t *)__string_228_number)) {
        StringBuilder_append(builder, (const uint16_t *)__string_229_did_you_mean_int);
      }

      else if (string_op_equals(name, (const uint16_t *)__string_230_boolean)) {
        StringBuilder_append(builder, (const uint16_t *)__string_231_did_you_mean_bool);
      }

      Log_error(context->log, node->range, StringBuilder_finish(builder));
    }

    else if (symbol->state == 1) {
      Log_error(context->log, node->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_232_Cyclic_reference_to_symbol), name), (const uint16_t *)__string_233_here)));
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

  else if (kind == 20) {
    struct Node *value = Node_castValue(node);
    struct Node *type = Node_castType(node);
    resolveAsExpression(context, value, parentScope);
    resolveAsType(context, type, parentScope);
    struct Type *castedType = type->resolvedType;
    checkConversion(context, value, castedType, 1);
    node->resolvedType = castedType;

    if (value->kind == 24 && Type_isInteger(castedType)) {
      int32_t result = value->intValue;
      int32_t shift = 32 - Type_integerBitCount(castedType, context);
      Node_becomeIntegerConstant(node, Type_isUnsigned(castedType) ? (int32_t)Type_integerBitMask(castedType, context) & result : result << shift >> shift);
    }
  }

  else if (kind == 21) {
    struct Node *target = Node_dotTarget(node);
    resolve(context, target, parentScope);

    if (target->resolvedType != context->errorType) {
      if ((Node_isType(target) && Type_isEnum(target->resolvedType)) || (!Node_isType(target) && Type_hasInstanceMembers(target->resolvedType))) {
        const uint16_t *name = node->stringValue;

        if (string_length(name) > 0) {
          struct Symbol *symbol = Type_findMember(target->resolvedType, name, Node_isAssignTarget(node) ? 6 : 5);

          if (symbol == NULL) {
            Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_234_No_member_named), name), (const uint16_t *)__string_235_on_type), Type_toString(target->resolvedType)), 39)));
          }

          else if (Symbol_isGetter(symbol)) {
            node->kind = 19;
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
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_236_The_type), Type_toString(target->resolvedType)), (const uint16_t *)__string_237_has_no_members)));
      }
    }
  }

  else if (kind == 19) {
    struct Node *value = Node_callValue(node);
    resolveAsExpression(context, value, parentScope);

    if (value->resolvedType != context->errorType) {
      struct Symbol *symbol = value->symbol;

      if (symbol == NULL || !isFunction(symbol->kind)) {
        Log_error(context->log, value->range, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_238_Cannot_call_value_of_type), Type_toString(value->resolvedType)), 39)));
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
          Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_239_Not_enough_arguments_for_functio), symbol->name), 39)));
        }

        else if (argumentValue != NULL) {
          while (argumentValue != NULL) {
            resolveAsExpression(context, argumentValue, parentScope);
            argumentValue = argumentValue->nextSibling;
          }

          Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_240_Too_many_arguments_for_function), symbol->name), 39)));
        }

        node->resolvedType = returnType->resolvedType;
      }
    }
  }

  else if (kind == 13) {
    struct Node *value = Node_returnValue(node);

    if (value != NULL) {
      resolveAsExpression(context, value, parentScope);

      if (context->currentReturnType != NULL) {
        if (context->currentReturnType != context->voidType) {
          checkConversion(context, value, context->currentReturnType, 0);
        }

        else {
          Log_error(context->log, value->range, (const uint16_t *)__string_241_Unexpected_return_value_in_funct);
        }
      }
    }

    else if (context->currentReturnType != NULL && context->currentReturnType != context->voidType) {
      Log_error(context->log, node->range, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_242_Expected_return_value_in_functio), Type_toString(context->currentReturnType)), 39)));
    }
  }

  else if (kind == 8) {
  }

  else if (kind == 10) {
    resolveAsExpression(context, Node_expressionValue(node), parentScope);
  }

  else if (kind == 16) {
    struct Node *value = Node_whileValue(node);
    struct Node *body = Node_whileBody(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context->boolType, 0);
    resolve(context, body, parentScope);
  }

  else if (kind == 12) {
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

  else if (kind == 22) {
    struct Node *value = Node_hookValue(node);
    struct Node *yes = Node_hookTrue(node);
    struct Node *no = Node_hookFalse(node);
    resolveAsExpression(context, value, parentScope);
    checkConversion(context, value, context->boolType, 0);
    resolve(context, yes, parentScope);
    resolve(context, no, parentScope);
    struct Type *commonType = (yes->resolvedType == context->nullType ? no : yes)->resolvedType;

    if (yes->resolvedType != commonType && (yes->resolvedType != context->nullType || !Type_isReference(commonType)) && no->resolvedType != commonType && (no->resolvedType != context->nullType || !Type_isReference(commonType))) {
      Log_error(context->log, spanRanges(yes->range, no->range), StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_243_Type), Type_toString(yes->resolvedType)), (const uint16_t *)__string_244_is_not_the_same_as_type), Type_toString(no->resolvedType)), 39)));
    }

    node->resolvedType = commonType;
  }

  else if (kind == 45) {
    struct Node *left = Node_binaryLeft(node);
    struct Node *right = Node_binaryRight(node);

    if (left->kind == 23) {
      resolveChildrenAsExpressions(context, left, parentScope);
      struct Node *target = Node_indexTarget(left);
      struct Type *type = target->resolvedType;

      if (type != context->errorType) {
        struct Symbol *symbol = Type_hasInstanceMembers(type) ? Type_findMember(type, (const uint16_t *)__string_245, 0) : NULL;

        if (symbol == NULL) {
          Log_error(context->log, left->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_246_Cannot_index_into_type), Type_toString(target->resolvedType)), 39)));
        }

        else {
          assert(symbol->kind == 4);
          node->kind = 19;
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
      node->kind = 19;
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

  else if (kind == 26) {
    struct Node *type = Node_newType(node);
    resolveAsType(context, type, parentScope);

    if (type->resolvedType != context->errorType) {
      if (!Type_isClass(type->resolvedType)) {
        Log_error(context->log, type->range, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_247_Cannot_construct_type), Type_toString(type->resolvedType)), 39)));
      }

      else {
        node->resolvedType = type->resolvedType;
      }
    }

    if (type->nextSibling != NULL) {
      Log_error(context->log, node->internalRange, (const uint16_t *)__string_248_Constructors_with_arguments_are);
    }
  }

  else if (kind == 38) {
    struct Node *value = Node_unaryValue(node);
    resolveAsType(context, value, parentScope);

    if (context->target == 2) {
      Log_error(context->log, node->internalRange, (const uint16_t *)__string_249_Cannot_use_pointers_when_compili);
    }

    else if (!context->isUnsafeAllowed) {
      Log_error(context->log, node->internalRange, (const uint16_t *)__string_250_Cannot_use_pointers_outside_an);
    }

    else {
      struct Type *type = value->resolvedType;

      if (type != context->errorType) {
        if (!Type_isInteger(type) && type->pointerTo == NULL) {
          Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_251_Cannot_create_a_pointer_to_non_i), Type_toString(type)), 39)));
        }

        else {
          node->resolvedType = Type_pointerType(type);
        }
      }
    }
  }

  else if (kind == 35) {
    struct Node *value = Node_unaryValue(node);
    resolveAsExpression(context, value, parentScope);
    struct Type *type = value->resolvedType;

    if (type != context->errorType) {
      if (type->pointerTo == NULL) {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_252_Cannot_dereference_type), Type_toString(type)), 39)));
      }

      else {
        node->resolvedType = type->pointerTo;
      }
    }
  }

  else if (kind == 33) {
    struct Node *value = Node_unaryValue(node);
    resolveAsExpression(context, value, parentScope);
    Log_error(context->log, node->internalRange, (const uint16_t *)__string_253_The_address_of_operator_is_not_s);
  }

  else if (isUnary(kind)) {
    struct Node *value = Node_unaryValue(node);
    resolveAsExpression(context, value, parentScope);

    if (kind == 37) {
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

      if (value->kind == 24) {
        int32_t input = value->intValue;
        int32_t output = input;

        if (kind == 34) {
          output = ~input;
        }

        else if (kind == 36) {
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
        node->kind = 19;
        node->resolvedType = NULL;
        resolveAsExpression(context, node, parentScope);
      }

      else {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_254_Cannot_use_unary_operator), name), (const uint16_t *)__string_255_with_type), Type_toString(value->resolvedType)), 39)));
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

    if (kind == 57 || kind == 56) {
      checkConversion(context, left, context->boolType, 0);
      checkConversion(context, right, context->boolType, 0);
      node->resolvedType = context->boolType;
    }

    else if (kind == 44 && leftType->pointerTo != NULL && Type_isInteger(rightType)) {
      node->resolvedType = leftType;
    }

    else if ((kind == 54 || kind == 55 || kind == 52 || kind == 53) && (leftType->pointerTo != NULL || rightType->pointerTo != NULL)) {
      node->resolvedType = context->boolType;

      if (leftType != rightType) {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_256_Cannot_compare_type), Type_toString(leftType)), (const uint16_t *)__string_257_with_type), Type_toString(rightType)), 39)));
      }
    }

    else if (Type_isInteger(leftType) && kind != 50 && kind != 59) {
      if (kind == 44 || kind == 63 || kind == 58 || kind == 49 || kind == 60 || kind == 46 || kind == 47 || kind == 48 || kind == 61 || kind == 62) {
        uint8_t isUnsigned = binaryHasUnsignedArguments(node);
        struct Type *commonType = isUnsigned ? context->uintType : context->intType;

        if (isUnsigned) {
          node->flags = node->flags | 4096;
        }

        checkConversion(context, left, commonType, 0);
        checkConversion(context, right, commonType, 0);
        node->resolvedType = commonType;

        if (left->kind == 24 && right->kind == 24) {
          int32_t inputLeft = left->intValue;
          int32_t inputRight = right->intValue;
          int32_t output = 0;

          if (kind == 44) {
            output = inputLeft + inputRight;
          }

          else if (kind == 46) {
            output = inputLeft & inputRight;
          }

          else if (kind == 47) {
            output = inputLeft | inputRight;
          }

          else if (kind == 48) {
            output = inputLeft ^ inputRight;
          }

          else if (kind == 49) {
            output = inputLeft / inputRight;
          }

          else if (kind == 58) {
            output = inputLeft * inputRight;
          }

          else if (kind == 60) {
            output = inputLeft % inputRight;
          }

          else if (kind == 61) {
            output = inputLeft << inputRight;
          }

          else if (kind == 62) {
            output = isUnsigned ? (int32_t)((uint32_t)inputLeft >> (uint32_t)inputRight) : inputLeft >> inputRight;
          }

          else if (kind == 63) {
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

      else if (kind == 54 || kind == 55 || kind == 52 || kind == 53) {
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
        Log_error(context->log, node->internalRange, (const uint16_t *)__string_258_This_operator_is_not_currently_s);
      }
    }

    else if (leftType != context->errorType) {
      const uint16_t *name = Range_toString(node->internalRange);
      struct Symbol *symbol = Type_findMember(leftType, kind == 59 ? (const uint16_t *)__string_259 : kind == 55 ? (const uint16_t *)__string_260 : kind == 53 ? (const uint16_t *)__string_261 : name, 4);

      if (symbol != NULL) {
        left = Node_withInternalRange(Node_withRange(createMemberReference(Node_remove(left), symbol), node->range), node->internalRange);
        Node_remove(right);

        if (kind == 59 || kind == 55 || kind == 53) {
          struct Node *call = createCall(left);
          Node_appendChild(call, right);
          node->kind = 37;
          Node_appendChild(node, Node_withInternalRange(Node_withRange(call, node->range), node->range));
        }

        else {
          Node_appendChild(node, left);
          Node_appendChild(node, right);
          node->kind = 19;
        }

        node->resolvedType = NULL;
        resolveAsExpression(context, node, parentScope);
      }

      else if (kind == 50 || kind == 59) {
        node->resolvedType = context->boolType;

        if (leftType != context->errorType && rightType != context->errorType && leftType != rightType && !canConvert(context, right, leftType, 0) && !canConvert(context, left, rightType, 0)) {
          Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_262_Cannot_compare_type), Type_toString(leftType)), (const uint16_t *)__string_263_with_type), Type_toString(rightType)), 39)));
        }
      }

      else {
        Log_error(context->log, node->internalRange, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_264_Cannot_use_binary_operator), name), (const uint16_t *)__string_265_with_type), Type_toString(leftType)), 39)));
      }
    }
  }

  else {
    assert(0);
  }
}

static void Compiler_initialize(struct Compiler *this, int32_t target) {
  assert(this->log == NULL);
  this->log = calloc(1, sizeof(struct Log));
  this->preprocessor = calloc(1, sizeof(struct Preprocessor));
  this->target = target;
  this->librarySource = Compiler_addInput(this, (const uint16_t *)__string_266_native, library());
  this->librarySource->isLibrary = 1;
  Compiler_createGlobals(this);

  if (target == 1) {
    Preprocessor_define(this->preprocessor, (const uint16_t *)__string_267_C, 1);
  }

  else if (target == 2) {
    Preprocessor_define(this->preprocessor, (const uint16_t *)__string_268_JS, 1);
  }

  else if (target == 3) {
    Preprocessor_define(this->preprocessor, (const uint16_t *)__string_269_WASM, 1);
  }
}

static void Compiler_createGlobals(struct Compiler *this) {
  struct CheckContext *context = calloc(1, sizeof(struct CheckContext));
  context->log = this->log;
  context->target = this->target;
  context->pointerByteSize = 4;
  struct Node *global = calloc(1, sizeof(struct Node));
  global->kind = 1;
  struct Scope *scope = calloc(1, sizeof(struct Scope));
  global->scope = scope;
  context->errorType = Scope_defineNativeType(scope, context->log, (const uint16_t *)__string_270_error);
  context->nullType = Scope_defineNativeType(scope, context->log, (const uint16_t *)__string_271_null);
  context->voidType = Scope_defineNativeType(scope, context->log, (const uint16_t *)__string_272_void);
  this->context = context;
  this->global = global;
}

static struct Source *Compiler_addInput(struct Compiler *this, const uint16_t *name, const uint16_t *contents) {
  struct Source *source = calloc(1, sizeof(struct Source));
  source->name = name;
  source->contents = contents;

  if (this->firstSource == NULL) {
    this->firstSource = source;
  }

  else {
    this->lastSource->next = source;
  }

  this->lastSource = source;

  return source;
}

static uint8_t Compiler_finish(struct Compiler *this) {
  Profiler_begin();
  struct Source *source = this->firstSource;

  while (source != NULL) {
    source->firstToken = tokenize(source, this->log);
    source = source->next;
  }

  Profiler_end((const uint16_t *)__string_273_lexing);
  Profiler_begin();
  source = this->firstSource;

  while (source != NULL) {
    Preprocessor_run(this->preprocessor, source, this->log);
    source = source->next;
  }

  Profiler_end((const uint16_t *)__string_274_preprocessing);
  Profiler_begin();
  source = this->firstSource;

  while (source != NULL) {
    if (source->firstToken != NULL) {
      source->file = parse(source->firstToken, this->log);
    }

    source = source->next;
  }

  Profiler_end((const uint16_t *)__string_275_parsing);
  Profiler_begin();
  struct Node *global = this->global;
  struct CheckContext *context = this->context;
  source = this->firstSource;

  while (source != NULL) {
    struct Node *file = source->file;

    if (file != NULL) {
      if (source == this->librarySource) {
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

    source = source->next;
  }

  resolve(context, global, global->scope);
  Profiler_end((const uint16_t *)__string_276_checking);

  if (Log_hasErrors(this->log)) {
    return 0;
  }

  Profiler_begin();
  treeShaking(global);
  Profiler_end((const uint16_t *)__string_277_shaking);
  Profiler_begin();

  if (this->target == 1) {
    this->c = cEmit(global, context);
  }

  else if (this->target == 2) {
    this->js = jsEmit(global, context);
  }

  else if (this->target == 3) {
    this->wasm = calloc(1, sizeof(struct ByteArray));
    wasmEmit(global, context, this->wasm);
  }

  Profiler_end((const uint16_t *)__string_278_emitting);

  return 1;
}

static uint8_t isPositivePowerOf2(int32_t value) {
  return value > 0 && (value & (value - 1)) == 0;
}

static int32_t alignToNextMultipleOf(int32_t offset, int32_t alignment) {
  assert(isPositivePowerOf2(alignment));

  return (offset + alignment - 1) & -alignment;
}

static void JsResult_emitIndent(struct JsResult *this) {
  int32_t i = this->indent;

  while (i > 0) {
    StringBuilder_append(this->code, (const uint16_t *)__string_279);
    i = i - 1;
  }
}

static void JsResult_emitNewlineBefore(struct JsResult *this, struct Node *node) {
  if (this->previousNode != NULL && (!isCompactNodeKind(this->previousNode->kind) || !isCompactNodeKind(node->kind))) {
    StringBuilder_appendChar(this->code, 10);
  }

  this->previousNode = NULL;
}

static void JsResult_emitNewlineAfter(struct JsResult *this, struct Node *node) {
  this->previousNode = node;
}

static void JsResult_emitStatements(struct JsResult *this, struct Node *node) {
  while (node != NULL) {
    JsResult_emitStatement(this, node);
    node = node->nextSibling;
  }
}

static void JsResult_emitBlock(struct JsResult *this, struct Node *node) {
  this->previousNode = NULL;
  StringBuilder_append(this->code, (const uint16_t *)__string_280);
  this->indent = this->indent + 1;
  JsResult_emitStatements(this, node->firstChild);
  this->indent = this->indent - 1;
  JsResult_emitIndent(this);
  StringBuilder_appendChar(this->code, 125);
  this->previousNode = NULL;
}

static void JsResult_emitUnary(struct JsResult *this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator) {
  uint8_t isPostfix = isUnaryPostfix(node->kind);
  uint8_t shouldCastToInt = node->kind == 36 && !jsKindCastsOperandsToInt(node->parent->kind);
  uint8_t isUnsigned = Node_isUnsignedOperator(node);
  int32_t operatorPrecedence = shouldCastToInt ? isUnsigned ? 9 : 4 : isPostfix ? 14 : 13;
  struct StringBuilder *code = this->code;

  if (parentPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 40);
  }

  if (!isPostfix) {
    StringBuilder_append(code, operator);
  }

  JsResult_emitExpression(this, Node_unaryValue(node), operatorPrecedence);

  if (isPostfix) {
    StringBuilder_append(code, operator);
  }

  if (shouldCastToInt) {
    StringBuilder_append(code, isUnsigned ? (const uint16_t *)__string_281_0 : (const uint16_t *)__string_282_0);
  }

  if (parentPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 41);
  }
}

static void JsResult_emitBinary(struct JsResult *this, struct Node *node, int32_t parentPrecedence, const uint16_t *operator, int32_t operatorPrecedence, int32_t mode) {
  uint8_t isRightAssociative = node->kind == 45;
  uint8_t isUnsigned = Node_isUnsignedOperator(node);
  struct StringBuilder *code = this->code;
  uint8_t shouldCastToInt = mode == 1 && (isUnsigned || !jsKindCastsOperandsToInt(node->parent->kind));
  int32_t selfPrecedence = shouldCastToInt ? isUnsigned ? 9 : 4 : parentPrecedence;

  if (parentPrecedence > selfPrecedence) {
    StringBuilder_appendChar(code, 40);
  }

  if (selfPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 40);
  }

  JsResult_emitExpression(this, Node_binaryLeft(node), isRightAssociative ? (int32_t)((int32_t)operatorPrecedence + 1) : operatorPrecedence);
  StringBuilder_append(code, operator);
  JsResult_emitExpression(this, Node_binaryRight(node), isRightAssociative ? operatorPrecedence : (int32_t)((int32_t)operatorPrecedence + 1));

  if (selfPrecedence > operatorPrecedence) {
    StringBuilder_appendChar(code, 41);
  }

  if (shouldCastToInt) {
    StringBuilder_append(code, isUnsigned ? (const uint16_t *)__string_283_0 : (const uint16_t *)__string_284_0);
  }

  if (parentPrecedence > selfPrecedence) {
    StringBuilder_appendChar(code, 41);
  }
}

static void JsResult_emitCommaSeparatedExpressions(struct JsResult *this, struct Node *start, struct Node *stop) {
  while (start != stop) {
    JsResult_emitExpression(this, start, 0);
    start = start->nextSibling;

    if (start != stop) {
      StringBuilder_append(this->code, (const uint16_t *)__string_285);
    }
  }
}

static void JsResult_emitExpression(struct JsResult *this, struct Node *node, int32_t parentPrecedence) {
  struct StringBuilder *code = this->code;

  if (node->kind == 25) {
    struct Symbol *symbol = node->symbol;

    if (symbol->kind == 5 && Node_isDeclare(symbol->node)) {
      StringBuilder_append(code, (const uint16_t *)__string_286___declare);
    }

    JsResult_emitSymbolName(this, symbol);
  }

  else if (node->kind == 27) {
    StringBuilder_append(code, (const uint16_t *)__string_287_null);
  }

  else if (node->kind == 18) {
    StringBuilder_append(code, node->intValue != 0 ? (const uint16_t *)__string_288_true : (const uint16_t *)__string_289_false);
  }

  else if (node->kind == 24) {
    if (parentPrecedence == 15) {
      StringBuilder_appendChar(code, 40);
    }

    StringBuilder_append(code, Type_isUnsigned(node->resolvedType) ? uint_toString((uint32_t)node->intValue) : int_toString(node->intValue));

    if (parentPrecedence == 15) {
      StringBuilder_appendChar(code, 41);
    }
  }

  else if (node->kind == 30) {
    StringBuilder_appendQuoted(code, node->stringValue);
  }

  else if (node->kind == 20) {
    struct CheckContext *context = this->context;
    struct Node *value = Node_castValue(node);
    struct Type *from = Type_underlyingType(value->resolvedType, context);
    struct Type *type = Type_underlyingType(node->resolvedType, context);
    int32_t fromSize = Type_variableSizeOf(from, context);
    int32_t typeSize = Type_variableSizeOf(type, context);

    if (from == type || fromSize < typeSize) {
      JsResult_emitExpression(this, value, parentPrecedence);
    }

    else if (type == context->sbyteType || type == context->shortType) {
      if (parentPrecedence > 9) {
        StringBuilder_appendChar(code, 40);
      }

      const uint16_t *shift = int_toString(32 - (typeSize << 3));
      JsResult_emitExpression(this, value, 9);
      StringBuilder_append(code, (const uint16_t *)__string_290);
      StringBuilder_append(code, shift);
      StringBuilder_append(code, (const uint16_t *)__string_291);
      StringBuilder_append(code, shift);

      if (parentPrecedence > 9) {
        StringBuilder_appendChar(code, 41);
      }
    }

    else if (type == context->byteType || type == context->ushortType) {
      if (parentPrecedence > 6) {
        StringBuilder_appendChar(code, 40);
      }

      JsResult_emitExpression(this, value, 6);
      StringBuilder_append(code, (const uint16_t *)__string_292);
      StringBuilder_append(code, uint_toString(Type_integerBitMask(type, context)));

      if (parentPrecedence > 6) {
        StringBuilder_appendChar(code, 41);
      }
    }

    else if (type == context->intType) {
      if (parentPrecedence > 4) {
        StringBuilder_appendChar(code, 40);
      }

      JsResult_emitExpression(this, value, 4);
      StringBuilder_append(code, (const uint16_t *)__string_293_0);

      if (parentPrecedence > 4) {
        StringBuilder_appendChar(code, 41);
      }
    }

    else if (type == context->uintType) {
      if (parentPrecedence > 9) {
        StringBuilder_appendChar(code, 40);
      }

      JsResult_emitExpression(this, value, 9);
      StringBuilder_append(code, (const uint16_t *)__string_294_0);

      if (parentPrecedence > 9) {
        StringBuilder_appendChar(code, 41);
      }
    }

    else {
      JsResult_emitExpression(this, value, parentPrecedence);
    }
  }

  else if (node->kind == 21) {
    JsResult_emitExpression(this, Node_dotTarget(node), 15);
    StringBuilder_appendChar(code, 46);
    JsResult_emitSymbolName(this, node->symbol);
  }

  else if (node->kind == 22) {
    if (parentPrecedence > 1) {
      StringBuilder_appendChar(code, 40);
    }

    JsResult_emitExpression(this, Node_hookValue(node), 2);
    StringBuilder_append(code, (const uint16_t *)__string_295);
    JsResult_emitExpression(this, Node_hookTrue(node), 1);
    StringBuilder_append(code, (const uint16_t *)__string_296);
    JsResult_emitExpression(this, Node_hookFalse(node), 1);

    if (parentPrecedence > 1) {
      StringBuilder_appendChar(code, 41);
    }
  }

  else if (node->kind == 23) {
    struct Node *value = Node_indexTarget(node);
    JsResult_emitExpression(this, value, 14);
    StringBuilder_appendChar(code, 91);
    JsResult_emitCommaSeparatedExpressions(this, value->nextSibling, NULL);
    StringBuilder_appendChar(code, 93);
  }

  else if (node->kind == 19) {
    if (Node_expandCallIntoOperatorTree(node)) {
      JsResult_emitExpression(this, node, parentPrecedence);
    }

    else {
      struct Node *value = Node_callValue(node);
      JsResult_emitExpression(this, value, 14);

      if (value->symbol == NULL || !Symbol_isGetter(value->symbol)) {
        StringBuilder_appendChar(code, 40);
        JsResult_emitCommaSeparatedExpressions(this, value->nextSibling, NULL);
        StringBuilder_appendChar(code, 41);
      }
    }
  }

  else if (node->kind == 26) {
    StringBuilder_append(code, (const uint16_t *)__string_297_new);
    JsResult_emitExpression(this, Node_newType(node), 14);
    StringBuilder_append(code, (const uint16_t *)__string_298);
  }

  else if (node->kind == 37) {
    struct Node *value = Node_unaryValue(node);
    Node_expandCallIntoOperatorTree(value);
    int32_t invertedKind = invertedBinaryKind(value->kind);

    if (invertedKind != value->kind) {
      value->kind = invertedKind;
      JsResult_emitExpression(this, value, parentPrecedence);
    }

    else {
      JsResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_299);
    }
  }

  else if (node->kind == 34) {
    JsResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_300);
  }

  else if (node->kind == 36) {
    JsResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_301);
  }

  else if (node->kind == 39) {
    JsResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_302);
  }

  else if (node->kind == 43) {
    JsResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_303);
  }

  else if (node->kind == 42) {
    JsResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_304);
  }

  else if (node->kind == 41) {
    JsResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_305);
  }

  else if (node->kind == 40) {
    JsResult_emitUnary(this, node, parentPrecedence, (const uint16_t *)__string_306);
  }

  else if (node->kind == 44) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_307, 10, 1);
  }

  else if (node->kind == 45) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_308, 1, 0);
  }

  else if (node->kind == 46) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_309, 6, 0);
  }

  else if (node->kind == 47) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_310, 4, 0);
  }

  else if (node->kind == 48) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_311, 5, 0);
  }

  else if (node->kind == 49) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_312, 11, 1);
  }

  else if (node->kind == 50) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_313, 7, 0);
  }

  else if (node->kind == 52) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_314, 8, 0);
  }

  else if (node->kind == 53) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_315, 8, 0);
  }

  else if (node->kind == 54) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_316, 8, 0);
  }

  else if (node->kind == 55) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_317, 8, 0);
  }

  else if (node->kind == 56) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_318, 3, 0);
  }

  else if (node->kind == 57) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_319, 2, 0);
  }

  else if (node->kind == 59) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_320, 7, 0);
  }

  else if (node->kind == 60) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_321, 11, 1);
  }

  else if (node->kind == 61) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_322, 9, 0);
  }

  else if (node->kind == 62) {
    JsResult_emitBinary(this, node, parentPrecedence, Node_isUnsignedOperator(node) ? (const uint16_t *)__string_323 : (const uint16_t *)__string_324, 9, 0);
  }

  else if (node->kind == 63) {
    JsResult_emitBinary(this, node, parentPrecedence, (const uint16_t *)__string_325, 10, 1);
  }

  else if (node->kind == 58) {
    struct Node *left = Node_binaryLeft(node);
    struct Node *right = Node_binaryRight(node);
    uint8_t isUnsigned = Node_isUnsignedOperator(node);

    if (isUnsigned && parentPrecedence > 9) {
      StringBuilder_appendChar(code, 40);
    }

    StringBuilder_append(code, (const uint16_t *)__string_326___imul);
    JsResult_emitExpression(this, left, 0);
    StringBuilder_append(code, (const uint16_t *)__string_327);
    JsResult_emitExpression(this, right, 0);
    StringBuilder_appendChar(code, 41);
    this->foundMultiply = 1;

    if (isUnsigned) {
      StringBuilder_append(code, (const uint16_t *)__string_328_0);

      if (parentPrecedence > 9) {
        StringBuilder_appendChar(code, 41);
      }
    }
  }

  else {
    assert(0);
  }
}

static void JsResult_emitSymbolName(struct JsResult *this, struct Symbol *symbol) {
  StringBuilder_append(this->code, !string_op_equals(symbol->rename, NULL) ? symbol->rename : symbol->name);
}

static void JsResult_emitStatement(struct JsResult *this, struct Node *node) {
  struct StringBuilder *code = this->code;

  if (node->kind == 11) {
    struct Node *body = Node_functionBody(node);

    if (body == NULL) {
      return;
    }

    struct Symbol *symbol = node->symbol;
    uint8_t needsSemicolon = 0;
    JsResult_emitNewlineBefore(this, node);
    JsResult_emitIndent(this);

    if (symbol->kind == 4) {
      JsResult_emitSymbolName(this, Symbol_parent(symbol));
      StringBuilder_append(code, (const uint16_t *)__string_329_prototype);
      JsResult_emitSymbolName(this, symbol);
      StringBuilder_append(code, (const uint16_t *)__string_330_function);
      needsSemicolon = 1;
    }

    else if (Node_isExtern(node)) {
      StringBuilder_append(code, (const uint16_t *)__string_331_var);
      JsResult_emitSymbolName(this, symbol);
      StringBuilder_append(code, (const uint16_t *)__string_332___extern);
      JsResult_emitSymbolName(this, symbol);
      StringBuilder_append(code, (const uint16_t *)__string_333_function);
      needsSemicolon = 1;
    }

    else {
      StringBuilder_append(code, (const uint16_t *)__string_334_function);
      JsResult_emitSymbolName(this, symbol);
    }

    StringBuilder_appendChar(code, 40);
    struct Node *returnType = Node_functionReturnType(node);
    struct Node *child = Node_functionFirstArgumentIgnoringThis(node);

    while (child != returnType) {
      assert(child->kind == 2);
      JsResult_emitSymbolName(this, child->symbol);
      child = child->nextSibling;

      if (child != returnType) {
        StringBuilder_append(code, (const uint16_t *)__string_335);
      }
    }

    StringBuilder_append(code, (const uint16_t *)__string_336);
    JsResult_emitBlock(this, Node_functionBody(node));
    StringBuilder_append(code, needsSemicolon ? (const uint16_t *)__string_337 : (const uint16_t *)__string_338);
    JsResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 12) {
    JsResult_emitNewlineBefore(this, node);
    JsResult_emitIndent(this);

    while (1) {
      StringBuilder_append(code, (const uint16_t *)__string_339_if);
      JsResult_emitExpression(this, Node_ifValue(node), 0);
      StringBuilder_append(code, (const uint16_t *)__string_340);
      JsResult_emitBlock(this, Node_ifTrue(node));
      struct Node *no = Node_ifFalse(node);

      if (no == NULL) {
        StringBuilder_appendChar(code, 10);

        break;
      }

      StringBuilder_append(code, (const uint16_t *)__string_341);
      JsResult_emitIndent(this);
      StringBuilder_append(code, (const uint16_t *)__string_342_else);

      if (no->firstChild == NULL || no->firstChild != no->lastChild || no->firstChild->kind != 12) {
        JsResult_emitBlock(this, no);
        StringBuilder_appendChar(code, 10);

        break;
      }

      node = no->firstChild;
    }

    JsResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 16) {
    JsResult_emitNewlineBefore(this, node);
    JsResult_emitIndent(this);
    StringBuilder_append(code, (const uint16_t *)__string_343_while);
    JsResult_emitExpression(this, Node_whileValue(node), 0);
    StringBuilder_append(code, (const uint16_t *)__string_344);
    JsResult_emitBlock(this, Node_whileBody(node));
    StringBuilder_appendChar(code, 10);
    JsResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 4) {
    JsResult_emitNewlineBefore(this, node);
    JsResult_emitIndent(this);
    StringBuilder_append(code, (const uint16_t *)__string_345_break);
    JsResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 7) {
    JsResult_emitNewlineBefore(this, node);
    JsResult_emitIndent(this);
    StringBuilder_append(code, (const uint16_t *)__string_346_continue);
    JsResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 10) {
    JsResult_emitNewlineBefore(this, node);
    JsResult_emitIndent(this);
    JsResult_emitExpression(this, Node_expressionValue(node), 0);
    StringBuilder_append(code, (const uint16_t *)__string_347);
    JsResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 8) {
  }

  else if (node->kind == 13) {
    struct Node *value = Node_returnValue(node);
    JsResult_emitNewlineBefore(this, node);
    JsResult_emitIndent(this);

    if (value != NULL) {
      StringBuilder_append(code, (const uint16_t *)__string_348_return);
      JsResult_emitExpression(this, value, 0);
      StringBuilder_append(code, (const uint16_t *)__string_349);
    }

    else {
      StringBuilder_append(code, (const uint16_t *)__string_350_return);
    }

    JsResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 3) {
    if (node->parent->kind == 3) {
      JsResult_emitStatements(this, node->firstChild);
    }

    else {
      JsResult_emitNewlineBefore(this, node);
      JsResult_emitIndent(this);
      JsResult_emitBlock(this, node);
      StringBuilder_appendChar(code, 10);
      JsResult_emitNewlineAfter(this, node);
    }
  }

  else if (node->kind == 15) {
    JsResult_emitNewlineBefore(this, node);
    JsResult_emitIndent(this);
    StringBuilder_append(code, (const uint16_t *)__string_351_var);
    struct Node *child = node->firstChild;

    while (child != NULL) {
      struct Node *value = Node_variableValue(child);
      JsResult_emitSymbolName(this, child->symbol);
      child = child->nextSibling;

      if (child != NULL) {
        StringBuilder_append(code, (const uint16_t *)__string_352);
      }

      assert(value != NULL);
      StringBuilder_append(code, (const uint16_t *)__string_353);
      JsResult_emitExpression(this, value, 0);
    }

    StringBuilder_append(code, (const uint16_t *)__string_354);
    JsResult_emitNewlineAfter(this, node);
  }

  else if (node->kind == 5) {
    if (!Node_isDeclare(node)) {
      JsResult_emitNewlineBefore(this, node);
      JsResult_emitIndent(this);
      StringBuilder_append(code, (const uint16_t *)__string_355_function);
      JsResult_emitSymbolName(this, node->symbol);
      StringBuilder_append(code, (const uint16_t *)__string_356);
      this->indent = this->indent + 1;
      struct Node *argument = node->firstChild;

      while (argument != NULL) {
        if (argument->kind == 2) {
          JsResult_emitIndent(this);
          StringBuilder_append(code, (const uint16_t *)__string_357_this);
          JsResult_emitSymbolName(this, argument->symbol);
          StringBuilder_append(code, (const uint16_t *)__string_358);
          JsResult_emitExpression(this, Node_variableValue(argument), 0);
          StringBuilder_append(code, (const uint16_t *)__string_359);
        }

        argument = argument->nextSibling;
      }

      this->indent = this->indent - 1;
      JsResult_emitIndent(this);
      StringBuilder_append(code, (const uint16_t *)__string_360);
      JsResult_emitNewlineAfter(this, node);
    }

    struct Node *child = node->firstChild;

    while (child != NULL) {
      if (child->kind == 11) {
        JsResult_emitStatement(this, child);
      }

      child = child->nextSibling;
    }
  }

  else if (node->kind == 9) {
    if (Node_isExtern(node)) {
      JsResult_emitNewlineBefore(this, node);
      JsResult_emitIndent(this);
      StringBuilder_append(code, (const uint16_t *)__string_361___extern);
      JsResult_emitSymbolName(this, node->symbol);
      StringBuilder_append(code, (const uint16_t *)__string_362);
      this->indent = this->indent + 1;
      struct Node *child = node->firstChild;

      while (child != NULL) {
        assert(child->kind == 2);
        JsResult_emitIndent(this);
        JsResult_emitSymbolName(this, child->symbol);
        StringBuilder_append(code, (const uint16_t *)__string_363);
        StringBuilder_append(code, int_toString(child->symbol->offset));
        child = child->nextSibling;
        StringBuilder_append(code, child != NULL ? (const uint16_t *)__string_364 : (const uint16_t *)__string_365);
      }

      this->indent = this->indent - 1;
      JsResult_emitIndent(this);
      StringBuilder_append(code, (const uint16_t *)__string_366);
      JsResult_emitNewlineAfter(this, node);
    }
  }

  else if (node->kind == 6) {
  }

  else {
    assert(0);
  }
}

static uint8_t jsKindCastsOperandsToInt(int32_t kind) {
  return kind == 61 || kind == 62 || kind == 47 || kind == 46 || kind == 48;
}

static const uint16_t *jsEmit(struct Node *global, struct CheckContext *context) {
  struct StringBuilder *code = StringBuilder_new();
  struct JsResult *result = calloc(1, sizeof(struct JsResult));
  result->context = context;
  result->code = code;
  StringBuilder_append(code, (const uint16_t *)__string_367_function___declare___extern);
  result->indent = 1;
  JsResult_emitStatements(result, global->firstChild);

  if (result->foundMultiply) {
    StringBuilder_appendChar(code, 10);
    JsResult_emitIndent(result);
    StringBuilder_append(code, (const uint16_t *)__string_368_var___imul_Math_imul_functi);
    result->indent = 2;
    JsResult_emitIndent(result);
    StringBuilder_append(code, (const uint16_t *)__string_369_return_a_b_16_16);
    result->indent = 1;
    JsResult_emitIndent(result);
    StringBuilder_append(code, (const uint16_t *)__string_370);
  }

  StringBuilder_append(code, (const uint16_t *)__string_371);
  JsResult_emitIndent(result);
  StringBuilder_append(code, (const uint16_t *)__string_372_typeof_global_undefined);
  JsResult_emitIndent(result);
  StringBuilder_append(code, (const uint16_t *)__string_373_typeof_exports_undefined);
  StringBuilder_append(code, (const uint16_t *)__string_374);

  return StringBuilder_finish(code);
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
    return (const uint16_t *)__string_375_end_of_file;
  }

  if (token == 1) {
    return (const uint16_t *)__string_376_character_literal;
  }

  if (token == 2) {
    return (const uint16_t *)__string_377_identifier;
  }

  if (token == 3) {
    return (const uint16_t *)__string_378_integer_literal;
  }

  if (token == 4) {
    return (const uint16_t *)__string_379_string_literal;
  }

  if (token == 5) {
    return (const uint16_t *)__string_380;
  }

  if (token == 6) {
    return (const uint16_t *)__string_381;
  }

  if (token == 7) {
    return (const uint16_t *)__string_382;
  }

  if (token == 8) {
    return (const uint16_t *)__string_383;
  }

  if (token == 9) {
    return (const uint16_t *)__string_384;
  }

  if (token == 10) {
    return (const uint16_t *)__string_385;
  }

  if (token == 11) {
    return (const uint16_t *)__string_386;
  }

  if (token == 12) {
    return (const uint16_t *)__string_387;
  }

  if (token == 13) {
    return (const uint16_t *)__string_388;
  }

  if (token == 14) {
    return (const uint16_t *)__string_389;
  }

  if (token == 15) {
    return (const uint16_t *)__string_390;
  }

  if (token == 16) {
    return (const uint16_t *)__string_391;
  }

  if (token == 17) {
    return (const uint16_t *)__string_392;
  }

  if (token == 18) {
    return (const uint16_t *)__string_393;
  }

  if (token == 19) {
    return (const uint16_t *)__string_394;
  }

  if (token == 20) {
    return (const uint16_t *)__string_395;
  }

  if (token == 21) {
    return (const uint16_t *)__string_396;
  }

  if (token == 22) {
    return (const uint16_t *)__string_397;
  }

  if (token == 23) {
    return (const uint16_t *)__string_398;
  }

  if (token == 24) {
    return (const uint16_t *)__string_399;
  }

  if (token == 25) {
    return (const uint16_t *)__string_400;
  }

  if (token == 26) {
    return (const uint16_t *)__string_401;
  }

  if (token == 27) {
    return (const uint16_t *)__string_402;
  }

  if (token == 28) {
    return (const uint16_t *)__string_403;
  }

  if (token == 29) {
    return (const uint16_t *)__string_404;
  }

  if (token == 30) {
    return (const uint16_t *)__string_405;
  }

  if (token == 31) {
    return (const uint16_t *)__string_406;
  }

  if (token == 32) {
    return (const uint16_t *)__string_407;
  }

  if (token == 33) {
    return (const uint16_t *)__string_408;
  }

  if (token == 34) {
    return (const uint16_t *)__string_409;
  }

  if (token == 35) {
    return (const uint16_t *)__string_410;
  }

  if (token == 36) {
    return (const uint16_t *)__string_411;
  }

  if (token == 37) {
    return (const uint16_t *)__string_412;
  }

  if (token == 38) {
    return (const uint16_t *)__string_413;
  }

  if (token == 39) {
    return (const uint16_t *)__string_414;
  }

  if (token == 40) {
    return (const uint16_t *)__string_415_alignof;
  }

  if (token == 41) {
    return (const uint16_t *)__string_416_as;
  }

  if (token == 42) {
    return (const uint16_t *)__string_417_break;
  }

  if (token == 43) {
    return (const uint16_t *)__string_418_class;
  }

  if (token == 44) {
    return (const uint16_t *)__string_419_const;
  }

  if (token == 45) {
    return (const uint16_t *)__string_420_continue;
  }

  if (token == 46) {
    return (const uint16_t *)__string_421_declare;
  }

  if (token == 47) {
    return (const uint16_t *)__string_422_else;
  }

  if (token == 48) {
    return (const uint16_t *)__string_423_enum;
  }

  if (token == 49) {
    return (const uint16_t *)__string_424_export;
  }

  if (token == 50) {
    return (const uint16_t *)__string_425_extends;
  }

  if (token == 51) {
    return (const uint16_t *)__string_426_extern;
  }

  if (token == 52) {
    return (const uint16_t *)__string_427_false;
  }

  if (token == 53) {
    return (const uint16_t *)__string_428_function;
  }

  if (token == 54) {
    return (const uint16_t *)__string_429_if;
  }

  if (token == 55) {
    return (const uint16_t *)__string_430_implements;
  }

  if (token == 56) {
    return (const uint16_t *)__string_431_import;
  }

  if (token == 57) {
    return (const uint16_t *)__string_432_interface;
  }

  if (token == 58) {
    return (const uint16_t *)__string_433_let;
  }

  if (token == 59) {
    return (const uint16_t *)__string_434_new;
  }

  if (token == 60) {
    return (const uint16_t *)__string_435_null;
  }

  if (token == 61) {
    return (const uint16_t *)__string_436_operator;
  }

  if (token == 62) {
    return (const uint16_t *)__string_437_private;
  }

  if (token == 63) {
    return (const uint16_t *)__string_438_protected;
  }

  if (token == 64) {
    return (const uint16_t *)__string_439_public;
  }

  if (token == 65) {
    return (const uint16_t *)__string_440_return;
  }

  if (token == 66) {
    return (const uint16_t *)__string_441_sizeof;
  }

  if (token == 67) {
    return (const uint16_t *)__string_442_static;
  }

  if (token == 68) {
    return (const uint16_t *)__string_443_this;
  }

  if (token == 69) {
    return (const uint16_t *)__string_444_true;
  }

  if (token == 70) {
    return (const uint16_t *)__string_445_unsafe;
  }

  if (token == 71) {
    return (const uint16_t *)__string_446_var;
  }

  if (token == 72) {
    return (const uint16_t *)__string_447_while;
  }

  if (token == 73) {
    return (const uint16_t *)__string_448_define;
  }

  if (token == 74) {
    return (const uint16_t *)__string_449_elif;
  }

  if (token == 75) {
    return (const uint16_t *)__string_450_else;
  }

  if (token == 76) {
    return (const uint16_t *)__string_451_endif;
  }

  if (token == 77) {
    return (const uint16_t *)__string_452_error;
  }

  if (token == 78) {
    return (const uint16_t *)__string_453_if;
  }

  if (token == 80) {
    return (const uint16_t *)__string_454_newline;
  }

  if (token == 81) {
    return (const uint16_t *)__string_455_undef;
  }

  if (token == 82) {
    return (const uint16_t *)__string_456_warning;
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
          if (string_op_equals(text, (const uint16_t *)__string_457_as)) {
            kind = 41;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_458_if)) {
            kind = 54;
          }
        }

        else if (length == 3) {
          if (string_op_equals(text, (const uint16_t *)__string_459_let)) {
            kind = 58;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_460_new)) {
            kind = 59;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_461_var)) {
            kind = 71;
          }
        }

        else if (length == 4) {
          if (string_op_equals(text, (const uint16_t *)__string_462_else)) {
            kind = 47;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_463_enum)) {
            kind = 48;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_464_null)) {
            kind = 60;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_465_this)) {
            kind = 68;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_466_true)) {
            kind = 69;
          }
        }

        else if (length == 5) {
          if (string_op_equals(text, (const uint16_t *)__string_467_break)) {
            kind = 42;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_468_class)) {
            kind = 43;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_469_const)) {
            kind = 44;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_470_false)) {
            kind = 52;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_471_while)) {
            kind = 72;
          }
        }

        else if (length == 6) {
          if (string_op_equals(text, (const uint16_t *)__string_472_export)) {
            kind = 49;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_473_extern)) {
            kind = 51;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_474_import)) {
            kind = 56;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_475_public)) {
            kind = 64;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_476_return)) {
            kind = 65;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_477_sizeof)) {
            kind = 66;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_478_static)) {
            kind = 67;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_479_unsafe)) {
            kind = 70;
          }
        }

        else if (length == 7) {
          if (string_op_equals(text, (const uint16_t *)__string_480_alignof)) {
            kind = 40;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_481_declare)) {
            kind = 46;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_482_extends)) {
            kind = 50;
          }

          else if (string_op_equals(text, (const uint16_t *)__string_483_private)) {
            kind = 62;
          }
        }

        else if (string_op_equals(text, (const uint16_t *)__string_484_continue)) {
          kind = 45;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_485_function)) {
          kind = 53;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_486_implements)) {
          kind = 55;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_487_interface)) {
          kind = 57;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_488_protected)) {
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

          Log_error(log, createRange(source, start, i), StringBuilder_finish(StringBuilder_appendChar(StringBuilder_appendSlice(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_489_Invalid_integer_literal), contents, start, i), 39)));

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
        Log_error(log, createRange(source, start, i), c == 39 ? (const uint16_t *)__string_490_Unterminated_character_literal : c == 96 ? (const uint16_t *)__string_491_Unterminated_template_literal : (const uint16_t *)__string_492_Unterminated_string_literal);

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
          Log_error(log, createRange(source, start, start + 2), (const uint16_t *)__string_493_Unterminated_multi_line_comment);

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
          Log_error(log, createRange(source, start, i), (const uint16_t *)__string_494_Use_instead_of);
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
          Log_error(log, createRange(source, start, i), (const uint16_t *)__string_495_Use_instead_of);
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

      if (string_op_equals(text, (const uint16_t *)__string_496_define)) {
        kind = 73;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_497_elif)) {
        kind = 74;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_498_else)) {
        kind = 75;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_499_endif)) {
        kind = 76;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_500_error)) {
        kind = 77;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_501_if)) {
        kind = 78;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_502_undef)) {
        kind = 81;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_503_warning)) {
        kind = 82;
      }

      else if (start == 0 && string_op_equals(text, (const uint16_t *)__string_504) && i < limit && string_op_get(contents, i) == 33) {
        while (i < limit && string_op_get(contents, i) != 10) {
          i = i + 1;
        }

        continue;
      }

      else {
        struct StringBuilder *builder = StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_505_Invalid_preprocessor_token), text), 39);

        if (string_op_equals(text, (const uint16_t *)__string_506_ifdef)) {
          StringBuilder_append(builder, (const uint16_t *)__string_507_did_you_mean_if);
          kind = 78;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_508_elsif) || string_op_equals(text, (const uint16_t *)__string_509_elseif)) {
          StringBuilder_append(builder, (const uint16_t *)__string_510_did_you_mean_elif);
          kind = 74;
        }

        else if (string_op_equals(text, (const uint16_t *)__string_511_end)) {
          StringBuilder_append(builder, (const uint16_t *)__string_512_did_you_mean_endif);
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
          Log_error(log, createRange(source, start, i), StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_513_Expected_newline_before), tokenToString(kind))));
        }
      }

      needsPreprocessor = 1;
      wantNewline = 1;
    }

    struct Range *range = createRange(source, start, i);

    if (kind == 0) {
      Log_error(log, range, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_appendSlice(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_514_Syntax_error), contents, start, start + 1), 39)));

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
  return (const uint16_t *)__string_515_if_WASM_These_will_be_fi;
}

static struct LineColumn *Source_indexToLineColumn(struct Source *this, int32_t index) {
  const uint16_t *contents = this->contents;
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

static const uint16_t *Range_toString(struct Range *this) {
  return string_slice(this->source->contents, this->start, this->end);
}

static uint8_t Range_equals(struct Range *this, struct Range *other) {
  return this->source == other->source && this->start == other->start && this->end == other->end;
}

static struct Range *Range_enclosingLine(struct Range *this) {
  const uint16_t *contents = this->source->contents;
  int32_t start = this->start;
  int32_t end = this->start;

  while (start > 0 && string_op_get(contents, start - 1) != 10) {
    start = start - 1;
  }

  int32_t length = string_length(contents);

  while (end < length && string_op_get(contents, end) != 10) {
    end = end + 1;
  }

  return createRange(this->source, start, end);
}

static struct Range *Range_rangeAtEnd(struct Range *this) {
  return createRange(this->source, this->end, this->end);
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

static void Diagnostic_appendSourceName(struct Diagnostic *this, struct StringBuilder *builder, struct LineColumn *location) {
  StringBuilder_append(StringBuilder_append(StringBuilder_appendChar(StringBuilder_append(StringBuilder_appendChar(StringBuilder_append(builder, this->range->source->name), 58), int_toString(location->line + 1)), 58), int_toString(location->column + 1)), (const uint16_t *)__string_516);
}

static void Diagnostic_appendKind(struct Diagnostic *this, struct StringBuilder *builder) {
  StringBuilder_append(builder, this->kind == 0 ? (const uint16_t *)__string_517_error : (const uint16_t *)__string_518_warning);
}

static void Diagnostic_appendMessage(struct Diagnostic *this, struct StringBuilder *builder) {
  StringBuilder_appendChar(StringBuilder_append(builder, this->message), 10);
}

static void Diagnostic_appendLineContents(struct Diagnostic *this, struct StringBuilder *builder, struct LineColumn *location) {
  struct Range *range = Range_enclosingLine(this->range);
  StringBuilder_appendChar(StringBuilder_appendSlice(builder, range->source->contents, range->start, range->end), 10);
}

static void Diagnostic_appendRange(struct Diagnostic *this, struct StringBuilder *builder, struct LineColumn *location) {
  struct Range *range = this->range;
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

static void Log_error(struct Log *this, struct Range *range, const uint16_t *message) {
  Log_append(this, range, message, 0);
}

static void Log_warning(struct Log *this, struct Range *range, const uint16_t *message) {
  Log_append(this, range, message, 1);
}

static void Log_append(struct Log *this, struct Range *range, const uint16_t *message, int32_t kind) {
  struct Diagnostic *diagnostic = calloc(1, sizeof(struct Diagnostic));
  diagnostic->range = range;
  diagnostic->message = message;
  diagnostic->kind = kind;

  if (this->first == NULL) {
    this->first = diagnostic;
  }

  else {
    this->last->next = diagnostic;
  }

  this->last = diagnostic;
}

static const uint16_t *Log_toString(struct Log *this) {
  struct StringBuilder *builder = StringBuilder_new();
  struct Diagnostic *diagnostic = this->first;

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

static uint8_t Log_hasErrors(struct Log *this) {
  struct Diagnostic *diagnostic = this->first;

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
  Terminal_write((const uint16_t *)__string_519_error);
  Terminal_setColor(1);
  Terminal_write(text);
  Terminal_write((const uint16_t *)__string_520);
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

const uint16_t *main_newString(uint32_t length) {
  return string_new(length);
}

void main_reset() {
  firstArgument = NULL;
  lastArgument = NULL;
}

static void printUsage() {
  Terminal_write((const uint16_t *)__string_521_Usage_thinc_FLAGS_INPUTS);
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

    if (string_startsWith(text, (const uint16_t *)__string_522)) {
      if (string_op_equals(text, (const uint16_t *)__string_523_h) || string_op_equals(text, (const uint16_t *)__string_524_help) || string_op_equals(text, (const uint16_t *)__string_525_help) || string_op_equals(text, (const uint16_t *)__string_526)) {
        printUsage();

        return 0;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_527_c)) {
        target = 1;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_528_js)) {
        target = 2;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_529_wasm)) {
        target = 3;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_530_define) && argument->next != NULL) {
        argument = argument->next;
      }

      else if (string_op_equals(text, (const uint16_t *)__string_531_out) && argument->next != NULL) {
        argument = argument->next;
        output = argument->text;
      }

      else {
        printError(StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_532_Invalid_flag), text)));

        return 1;
      }
    }

    else {
      inputCount = inputCount + 1;
    }

    argument = argument->next;
  }

  if (inputCount == 0) {
    printError((const uint16_t *)__string_533_No_input_files);

    return 1;
  }

  if (string_op_equals(output, NULL)) {
    printError((const uint16_t *)__string_534_Missing_an_output_file_use_the);

    return 1;
  }

  if (target == 0) {
    if (string_endsWith(output, (const uint16_t *)__string_535_c)) {
      target = 1;
    }

    else if (string_endsWith(output, (const uint16_t *)__string_536_js)) {
      target = 2;
    }

    else if (string_endsWith(output, (const uint16_t *)__string_537_wasm)) {
      target = 3;
    }

    else {
      printError((const uint16_t *)__string_538_Missing_a_target_use_either_c);

      return 1;
    }
  }

  struct Compiler *compiler = calloc(1, sizeof(struct Compiler));
  Compiler_initialize(compiler, target);
  argument = firstArgument;

  while (argument != NULL) {
    const uint16_t *text = argument->text;

    if (string_op_equals(text, (const uint16_t *)__string_539_define)) {
      argument = argument->next;
      Preprocessor_define(compiler->preprocessor, argument->text, 1);
    }

    else if (string_op_equals(text, (const uint16_t *)__string_540_out)) {
      argument = argument->next;
    }

    else if (!string_startsWith(text, (const uint16_t *)__string_541)) {
      const uint16_t *contents = IO_readTextFile(text);

      if (string_op_equals(contents, NULL)) {
        printError(StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_542_Cannot_read_from), text)));

        return 1;
      }

      Compiler_addInput(compiler, text, contents);
    }

    argument = argument->next;
  }

  Compiler_finish(compiler);
  writeLogToTerminal(compiler->log);

  if (!Log_hasErrors(compiler->log)) {
    uint8_t success = target == 1 ? IO_writeTextFile(output, compiler->c) : target == 2 ? IO_writeTextFile(output, compiler->js) : target == 3 ? IO_writeBinaryFile(output, compiler->wasm) : 0;

    if (!success) {
      printError(StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_543_Cannot_write_to), output)));

      return 1;
    }
  }

  return 0;
}

static uint8_t isUnary(int32_t kind) {
  return kind >= 33 && kind <= 43;
}

static uint8_t isUnaryPostfix(int32_t kind) {
  return kind >= 40 && kind <= 41;
}

static uint8_t isBinary(int32_t kind) {
  return kind >= 44 && kind <= 63;
}

static int32_t invertedBinaryKind(int32_t kind) {
  if (kind == 50) {
    return 59;
  }

  if (kind == 59) {
    return 50;
  }

  if (kind == 52) {
    return 55;
  }

  if (kind == 53) {
    return 54;
  }

  if (kind == 54) {
    return 53;
  }

  if (kind == 55) {
    return 52;
  }

  return kind;
}

static uint8_t isExpression(struct Node *node) {
  return node->kind >= 17 && node->kind <= 63;
}

static uint8_t isCompactNodeKind(int32_t kind) {
  return kind == 6 || kind == 10 || kind == 15;
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

static void Node_become(struct Node *this, struct Node *node) {
  assert(node != this);
  assert(node->parent == NULL);
  this->kind = node->kind;
  this->flags = node->flags;
  this->firstFlag = node->firstFlag;
  this->range = node->range;
  this->internalRange = node->internalRange;
  this->intValue = node->intValue;
  this->stringValue = node->stringValue;
  this->resolvedType = node->resolvedType;
  this->symbol = node->symbol;
  this->scope = node->scope;
}

static void Node_becomeSymbolReference(struct Node *this, struct Symbol *symbol) {
  this->kind = 25;
  this->symbol = symbol;
  this->stringValue = symbol->name;
  this->resolvedType = symbol->resolvedType;
  Node_removeChildren(this);
}

static void Node_becomeIntegerConstant(struct Node *this, int32_t value) {
  this->kind = 24;
  this->symbol = NULL;
  this->intValue = value;
  Node_removeChildren(this);
}

static void Node_becomeBooleanConstant(struct Node *this, uint8_t value) {
  this->kind = 18;
  this->symbol = NULL;
  this->intValue = value ? 1 : 0;
  Node_removeChildren(this);
}

static uint8_t Node_isNegativeInteger(struct Node *this) {
  return this->kind == 24 && this->intValue < 0;
}

static uint8_t Node_isNonNegativeInteger(struct Node *this) {
  return this->kind == 24 && this->intValue >= 0;
}

static uint8_t Node_isDeclare(struct Node *this) {
  return (this->flags & 1) != 0;
}

static uint8_t Node_isExtern(struct Node *this) {
  return (this->flags & 4) != 0;
}

static uint8_t Node_isDeclareOrExtern(struct Node *this) {
  return (this->flags & 5) != 0;
}

static uint8_t Node_isGet(struct Node *this) {
  return (this->flags & 8) != 0;
}

static uint8_t Node_isSet(struct Node *this) {
  return (this->flags & 512) != 0;
}

static uint8_t Node_isOperator(struct Node *this) {
  return (this->flags & 16) != 0;
}

static uint8_t Node_isPositive(struct Node *this) {
  return (this->flags & 32) != 0;
}

static uint8_t Node_isPrivate(struct Node *this) {
  return (this->flags & 64) != 0;
}

static uint8_t Node_isUnsafe(struct Node *this) {
  return (this->flags & 2048) != 0;
}

static uint8_t Node_isUnsignedOperator(struct Node *this) {
  return (this->flags & 4096) != 0;
}

static int32_t Node_childCount(struct Node *this) {
  int32_t count = 0;
  struct Node *child = this->firstChild;

  while (child != NULL) {
    count = count + 1;
    child = child->nextSibling;
  }

  return count;
}

static void Node_appendChild(struct Node *this, struct Node *child) {
  child->parent = this;

  if (this->firstChild == NULL) {
    this->firstChild = child;
  }

  else {
    child->previousSibling = this->lastChild;
    this->lastChild->nextSibling = child;
  }

  this->lastChild = child;
}

static void Node_insertChildBefore(struct Node *this, struct Node *after, struct Node *before) {
  if (before == NULL) {
    return;
  }

  assert(before != after);
  assert(before->parent == NULL);
  assert(before->previousSibling == NULL);
  assert(before->nextSibling == NULL);
  assert(after == NULL || after->parent == this);

  if (after == NULL) {
    Node_appendChild(this, before);

    return;
  }

  before->parent = this;
  before->previousSibling = after->previousSibling;
  before->nextSibling = after;

  if (after->previousSibling != NULL) {
    assert(after == after->previousSibling->nextSibling);
    after->previousSibling->nextSibling = before;
  }

  else {
    assert(after == this->firstChild);
    this->firstChild = before;
  }

  after->previousSibling = before;
}

static struct Node *Node_remove(struct Node *this) {
  assert(this->parent != NULL);

  if (this->previousSibling != NULL) {
    assert(this->previousSibling->nextSibling == this);
    this->previousSibling->nextSibling = this->nextSibling;
  }

  else {
    assert(this->parent->firstChild == this);
    this->parent->firstChild = this->nextSibling;
  }

  if (this->nextSibling != NULL) {
    assert(this->nextSibling->previousSibling == this);
    this->nextSibling->previousSibling = this->previousSibling;
  }

  else {
    assert(this->parent->lastChild == this);
    this->parent->lastChild = this->previousSibling;
  }

  this->parent = NULL;
  this->previousSibling = NULL;
  this->nextSibling = NULL;

  return this;
}

static void Node_removeChildren(struct Node *this) {
  while (this->lastChild != NULL) {
    Node_remove(this->lastChild);
  }
}

static void Node_replaceWith(struct Node *this, struct Node *node) {
  assert(node != this);
  assert(this->parent != NULL);
  assert(node->parent == NULL);
  assert(node->previousSibling == NULL);
  assert(node->nextSibling == NULL);
  node->parent = this->parent;
  node->previousSibling = this->previousSibling;
  node->nextSibling = this->nextSibling;

  if (this->previousSibling != NULL) {
    assert(this->previousSibling->nextSibling == this);
    this->previousSibling->nextSibling = node;
  }

  else {
    assert(this->parent->firstChild == this);
    this->parent->firstChild = node;
  }

  if (this->nextSibling != NULL) {
    assert(this->nextSibling->previousSibling == this);
    this->nextSibling->previousSibling = node;
  }

  else {
    assert(this->parent->lastChild == this);
    this->parent->lastChild = node;
  }

  this->parent = NULL;
  this->previousSibling = NULL;
  this->nextSibling = NULL;
}

static uint8_t Node_isType(struct Node *this) {
  return this->kind == 32 || this->kind == 38 || (this->symbol != NULL && isType(this->symbol->kind));
}

static uint8_t Node_isCallValue(struct Node *this) {
  return this->parent->kind == 19 && this == Node_callValue(this->parent);
}

static uint8_t Node_isAssignTarget(struct Node *this) {
  return this->parent->kind == 45 && this == Node_binaryLeft(this->parent);
}

static struct Node *Node_withRange(struct Node *this, struct Range *range) {
  this->range = range;

  return this;
}

static struct Node *Node_withInternalRange(struct Node *this, struct Range *range) {
  this->internalRange = range;

  return this;
}

static struct Node *Node_functionFirstArgumentIgnoringThis(struct Node *this) {
  assert(this->kind == 11);
  assert(Node_childCount(this) >= 2);
  assert(this->symbol != NULL);

  return this->symbol->kind == 4 ? this->firstChild->nextSibling : this->firstChild;
}

static struct Node *Node_functionReturnType(struct Node *this) {
  assert(this->kind == 11);
  assert(Node_childCount(this) >= 2);
  assert(isExpression(this->lastChild->previousSibling));

  return this->lastChild->previousSibling;
}

static struct Node *Node_functionBody(struct Node *this) {
  assert(this->kind == 11);
  assert(Node_childCount(this) >= 2);
  assert(this->lastChild->kind == 3 || this->lastChild->kind == 8);
  struct Node *body = this->lastChild;

  return body->kind == 3 ? body : NULL;
}

static struct Node *Node_newType(struct Node *this) {
  assert(this->kind == 26);
  assert(Node_childCount(this) >= 1);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_callValue(struct Node *this) {
  assert(this->kind == 19);
  assert(Node_childCount(this) >= 1);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_castValue(struct Node *this) {
  assert(this->kind == 20);
  assert(Node_childCount(this) == 2);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_castType(struct Node *this) {
  assert(this->kind == 20);
  assert(Node_childCount(this) == 2);
  assert(isExpression(this->lastChild));

  return this->lastChild;
}

static struct Node *Node_alignOfType(struct Node *this) {
  assert(this->kind == 17);
  assert(Node_childCount(this) == 1);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_sizeOfType(struct Node *this) {
  assert(this->kind == 29);
  assert(Node_childCount(this) == 1);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_dotTarget(struct Node *this) {
  assert(this->kind == 21);
  assert(Node_childCount(this) == 1);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_returnValue(struct Node *this) {
  assert(this->kind == 13);
  assert(Node_childCount(this) <= 1);
  assert(this->firstChild == NULL || isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_variableType(struct Node *this) {
  assert(this->kind == 2);
  assert(Node_childCount(this) <= 2);
  assert(isExpression(this->firstChild) || this->firstChild->kind == 8);
  struct Node *type = this->firstChild;

  return type->kind != 8 ? type : NULL;
}

static struct Node *Node_variableValue(struct Node *this) {
  assert(this->kind == 2);
  assert(Node_childCount(this) <= 2);
  assert(this->firstChild->nextSibling == NULL || isExpression(this->firstChild->nextSibling));

  return this->firstChild->nextSibling;
}

static struct Node *Node_expressionValue(struct Node *this) {
  assert(this->kind == 10);
  assert(Node_childCount(this) == 1);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_binaryLeft(struct Node *this) {
  assert(isBinary(this->kind));
  assert(Node_childCount(this) == 2);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_binaryRight(struct Node *this) {
  assert(isBinary(this->kind));
  assert(Node_childCount(this) == 2);
  assert(isExpression(this->lastChild));

  return this->lastChild;
}

static struct Node *Node_unaryValue(struct Node *this) {
  assert(isUnary(this->kind));
  assert(Node_childCount(this) == 1);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_whileValue(struct Node *this) {
  assert(this->kind == 16);
  assert(Node_childCount(this) == 2);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_whileBody(struct Node *this) {
  assert(this->kind == 16);
  assert(Node_childCount(this) == 2);
  assert(this->lastChild->kind == 3);

  return this->lastChild;
}

static struct Node *Node_hookValue(struct Node *this) {
  assert(this->kind == 22);
  assert(Node_childCount(this) == 3);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_hookTrue(struct Node *this) {
  assert(this->kind == 22);
  assert(Node_childCount(this) == 3);
  assert(isExpression(this->firstChild->nextSibling));

  return this->firstChild->nextSibling;
}

static struct Node *Node_hookFalse(struct Node *this) {
  assert(this->kind == 22);
  assert(Node_childCount(this) == 3);
  assert(isExpression(this->lastChild));

  return this->lastChild;
}

static struct Node *Node_indexTarget(struct Node *this) {
  assert(this->kind == 23);
  assert(Node_childCount(this) >= 1);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_ifValue(struct Node *this) {
  assert(this->kind == 12);
  assert(Node_childCount(this) == 2 || Node_childCount(this) == 3);
  assert(isExpression(this->firstChild));

  return this->firstChild;
}

static struct Node *Node_ifTrue(struct Node *this) {
  assert(this->kind == 12);
  assert(Node_childCount(this) == 2 || Node_childCount(this) == 3);
  assert(this->firstChild->nextSibling->kind == 3);

  return this->firstChild->nextSibling;
}

static struct Node *Node_ifFalse(struct Node *this) {
  assert(this->kind == 12);
  assert(Node_childCount(this) == 2 || Node_childCount(this) == 3);
  assert(this->firstChild->nextSibling->nextSibling == NULL || this->firstChild->nextSibling->nextSibling->kind == 3);

  return this->firstChild->nextSibling->nextSibling;
}

static uint8_t Node_expandCallIntoOperatorTree(struct Node *this) {
  if (this->kind != 19) {
    return 0;
  }

  struct Node *value = Node_callValue(this);
  struct Symbol *symbol = value->symbol;

  if (value->kind == 21 && Node_isOperator(symbol->node) && Node_isDeclare(symbol->node)) {
    int32_t binaryKind = 27;

    if (string_op_equals(symbol->name, (const uint16_t *)__string_544)) {
      binaryKind = 60;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_545)) {
      binaryKind = 46;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_546)) {
      binaryKind = 58;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_547)) {
      binaryKind = 51;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_548)) {
      binaryKind = 49;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_549)) {
      binaryKind = 54;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_550)) {
      binaryKind = 61;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_551)) {
      binaryKind = 50;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_552)) {
      binaryKind = 52;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_553)) {
      binaryKind = 62;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_554)) {
      binaryKind = 23;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_555)) {
      binaryKind = 48;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_556)) {
      binaryKind = 47;
    }

    if (binaryKind != 27) {
      this->kind = binaryKind;
      Node_remove(value);
      Node_insertChildBefore(this, this->firstChild, Node_remove(Node_dotTarget(value)));

      return 1;
    }

    else if (string_op_equals(symbol->name, (const uint16_t *)__string_557)) {
      this->kind = 45;
      struct Node *target = createIndex(Node_remove(Node_dotTarget(Node_remove(value))));
      Node_appendChild(target, Node_remove(this->firstChild));
      Node_insertChildBefore(this, this->firstChild, target);

      return 1;
    }
  }

  return 0;
}

static struct Node *createNew(struct Node *type) {
  assert(isExpression(type));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 26;
  Node_appendChild(node, type);

  return node;
}

static struct Node *createHook(struct Node *test, struct Node *primary, struct Node *secondary) {
  assert(isExpression(test));
  assert(isExpression(primary));
  assert(isExpression(secondary));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 22;
  Node_appendChild(node, test);
  Node_appendChild(node, primary);
  Node_appendChild(node, secondary);

  return node;
}

static struct Node *createIndex(struct Node *target) {
  assert(isExpression(target));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 23;
  Node_appendChild(node, target);

  return node;
}

static struct Node *createNull() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 27;

  return node;
}

static struct Node *createThis() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 31;

  return node;
}

static struct Node *createAddressOf(struct Node *value) {
  assert(isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 33;
  Node_appendChild(node, value);

  return node;
}

static struct Node *createDereference(struct Node *value) {
  assert(isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 35;
  Node_appendChild(node, value);

  return node;
}

static struct Node *createAlignOf(struct Node *type) {
  assert(isExpression(type));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 17;
  Node_appendChild(node, type);

  return node;
}

static struct Node *createSizeOf(struct Node *type) {
  assert(isExpression(type));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 29;
  Node_appendChild(node, type);

  return node;
}

static struct Node *createBool(uint8_t value) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 18;
  node->intValue = value ? 1 : 0;

  return node;
}

static struct Node *createInt(int32_t value) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 24;
  node->intValue = value;

  return node;
}

static struct Node *createString(const uint16_t *value) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 30;
  node->stringValue = value;

  return node;
}

static struct Node *createName(const uint16_t *value) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 25;
  node->stringValue = value;

  return node;
}

static struct Node *createType(struct Type *type) {
  assert(type != NULL);
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 32;
  node->resolvedType = type;

  return node;
}

static struct Node *createEmpty() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 8;

  return node;
}

static struct Node *createExpression(struct Node *value) {
  assert(isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 10;
  Node_appendChild(node, value);

  return node;
}

static struct Node *createBlock() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 3;

  return node;
}

static struct Node *createClass(const uint16_t *name) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 5;
  node->stringValue = name;

  return node;
}

static struct Node *createEnum(const uint16_t *name) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 9;
  node->stringValue = name;

  return node;
}

static struct Node *createIf(struct Node *value, struct Node *trueBranch, struct Node *falseBranch) {
  assert(isExpression(value));
  assert(trueBranch->kind == 3);
  assert(falseBranch == NULL || falseBranch->kind == 3);
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 12;
  Node_appendChild(node, value);
  Node_appendChild(node, trueBranch);

  if (falseBranch != NULL) {
    Node_appendChild(node, falseBranch);
  }

  return node;
}

static struct Node *createWhile(struct Node *value, struct Node *body) {
  assert(isExpression(value));
  assert(body->kind == 3);
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 16;
  Node_appendChild(node, value);
  Node_appendChild(node, body);

  return node;
}

static struct Node *createReturn(struct Node *value) {
  assert(value == NULL || isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 13;

  if (value != NULL) {
    Node_appendChild(node, value);
  }

  return node;
}

static struct Node *createVariables() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 15;

  return node;
}

static struct Node *createConstants() {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 6;

  return node;
}

static struct Node *createVariable(const uint16_t *name, struct Node *type, struct Node *value) {
  assert(type == NULL || isExpression(type));
  assert(value == NULL || isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 2;
  node->stringValue = name;
  Node_appendChild(node, type != NULL ? type : createEmpty());

  if (value != NULL) {
    Node_appendChild(node, value);
  }

  return node;
}

static struct Node *createFunction(const uint16_t *name) {
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 11;
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
  node->kind = 19;
  Node_appendChild(node, value);

  return node;
}

static struct Node *createCast(struct Node *value, struct Node *type) {
  assert(isExpression(value));
  assert(isExpression(type));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 20;
  Node_appendChild(node, value);
  Node_appendChild(node, type);

  return node;
}

static struct Node *createDot(struct Node *value, const uint16_t *name) {
  assert(isExpression(value));
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = 21;
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
  node->kind = 28;

  return node;
}

static uint8_t isRightAssociative(int32_t precedence) {
  return precedence == 1 || precedence == 12;
}

static uint8_t ParserContext_peek(struct ParserContext *this, int32_t kind) {
  return this->current->kind == kind;
}

static uint8_t ParserContext_eat(struct ParserContext *this, int32_t kind) {
  if (ParserContext_peek(this, kind)) {
    ParserContext_advance(this);

    return 1;
  }

  return 0;
}

static void ParserContext_advance(struct ParserContext *this) {
  if (!ParserContext_peek(this, 0)) {
    this->previous = this->current;
    this->current = this->current->next;
  }
}

static void ParserContext_unexpectedToken(struct ParserContext *this) {
  if (this->lastError != this->current) {
    this->lastError = this->current;
    Log_error(this->log, this->current->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_558_Unexpected), tokenToString(this->current->kind))));
  }
}

static uint8_t ParserContext_expect(struct ParserContext *this, int32_t kind) {
  if (!ParserContext_peek(this, kind)) {
    if (this->lastError != this->current) {
      this->lastError = this->current;
      struct Range *previousLine = Range_enclosingLine(this->previous->range);
      struct Range *currentLine = Range_enclosingLine(this->current->range);

      if (kind != 2 && !Range_equals(previousLine, currentLine)) {
        Log_error(this->log, Range_rangeAtEnd(previousLine), StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_559_Expected), tokenToString(kind))));
      }

      else {
        Log_error(this->log, this->current->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_560_Expected), tokenToString(kind)), (const uint16_t *)__string_561_but_found), tokenToString(this->current->kind))));
      }
    }

    return 0;
  }

  ParserContext_advance(this);

  return 1;
}

static struct Node *ParserContext_parseUnaryPrefix(struct ParserContext *this, int32_t kind, int32_t mode) {
  assert(isUnary(kind));
  struct Token *token = this->current;
  ParserContext_advance(this);
  struct Node *value = ParserContext_parseExpression(this, 13, mode);

  if (value == NULL) {
    return NULL;
  }

  return Node_withInternalRange(Node_withRange(createUnary(kind, value), spanRanges(token->range, value->range)), token->range);
}

static struct Node *ParserContext_parseBinary(struct ParserContext *this, int32_t kind, struct Node *left, int32_t localPrecedence, int32_t operatorPrecedence) {
  if (localPrecedence >= operatorPrecedence) {
    return left;
  }

  struct Token *token = this->current;
  ParserContext_advance(this);
  int32_t precedence = isRightAssociative(operatorPrecedence) ? (int32_t)((int32_t)operatorPrecedence - 1) : operatorPrecedence;
  struct Node *right = ParserContext_parseExpression(this, precedence, 0);

  if (right == NULL) {
    return NULL;
  }

  return Node_withInternalRange(Node_withRange(createBinary(kind, left, right), spanRanges(left->range, right->range)), token->range);
}

static struct Node *ParserContext_parseUnaryPostfix(struct ParserContext *this, int32_t kind, struct Node *value, int32_t localPrecedence) {
  if (localPrecedence >= 14) {
    return value;
  }

  struct Token *token = this->current;
  ParserContext_advance(this);

  return Node_withInternalRange(Node_withRange(createUnary(kind, value), spanRanges(value->range, token->range)), token->range);
}

static const uint16_t *ParserContext_parseQuotedString(struct ParserContext *this, struct Range *range) {
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
        Log_error(this->log, escape, StringBuilder_finish(StringBuilder_appendChar(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_562_Invalid_escape_code), Range_toString(escape)), 39)));

        return NULL;
      }
    }

    end = end + 1;
  }

  return StringBuilder_finish(StringBuilder_appendSlice(builder, text, start, end));
}

static struct Node *ParserContext_parsePrefix(struct ParserContext *this, int32_t mode) {
  struct Token *token = this->current;

  if (ParserContext_peek(this, 2)) {
    ParserContext_advance(this);

    return Node_withRange(createName(Range_toString(token->range)), token->range);
  }

  if (ParserContext_peek(this, 15)) {
    splitToken(this->current, 27, 27);
  }

  if (ParserContext_peek(this, 27)) {
    return ParserContext_parseUnaryPrefix(this, mode == 1 ? 38 : 35, mode);
  }

  if (mode == 0) {
    if (ParserContext_eat(this, 60)) {
      return Node_withRange(createNull(), token->range);
    }

    if (ParserContext_eat(this, 68)) {
      return Node_withRange(createThis(), token->range);
    }

    if (ParserContext_peek(this, 1)) {
      const uint16_t *text = ParserContext_parseQuotedString(this, token->range);

      if (string_op_equals(text, NULL)) {
        return NULL;
      }

      ParserContext_advance(this);

      if (string_length(text) != 1) {
        Log_error(this->log, token->range, (const uint16_t *)__string_563_Invalid_character_literal_strin);

        return Node_withRange(createParseError(), token->range);
      }

      return Node_withRange(createInt(string_op_get(text, 0)), token->range);
    }

    if (ParserContext_peek(this, 4)) {
      const uint16_t *text = ParserContext_parseQuotedString(this, token->range);

      if (string_op_equals(text, NULL)) {
        return NULL;
      }

      ParserContext_advance(this);

      return Node_withRange(createString(text), token->range);
    }

    if (ParserContext_peek(this, 3)) {
      struct Node *value = createInt(0);

      if (!ParserContext_parseInt(this, token->range, value)) {
        value = createParseError();
      }

      ParserContext_advance(this);

      return Node_withRange(value, token->range);
    }

    if (ParserContext_eat(this, 69)) {
      return Node_withRange(createBool(1), token->range);
    }

    if (ParserContext_eat(this, 52)) {
      return Node_withRange(createBool(0), token->range);
    }

    if (ParserContext_eat(this, 59)) {
      struct Node *type = ParserContext_parseType(this);

      if (type == NULL) {
        return NULL;
      }

      return ParserContext_parseArgumentList(this, token->range, createNew(type));
    }

    if (ParserContext_eat(this, 40)) {
      if (!ParserContext_expect(this, 20)) {
        return NULL;
      }

      struct Node *type = ParserContext_parseType(this);

      if (type == NULL) {
        return NULL;
      }

      struct Token *close = this->current;

      if (!ParserContext_expect(this, 36)) {
        return NULL;
      }

      return Node_withRange(createAlignOf(type), spanRanges(token->range, close->range));
    }

    if (ParserContext_eat(this, 66)) {
      if (!ParserContext_expect(this, 20)) {
        return NULL;
      }

      struct Node *type = ParserContext_parseType(this);

      if (type == NULL) {
        return NULL;
      }

      struct Token *close = this->current;

      if (!ParserContext_expect(this, 36)) {
        return NULL;
      }

      return Node_withRange(createSizeOf(type), spanRanges(token->range, close->range));
    }

    if (ParserContext_eat(this, 20)) {
      struct Node *value = ParserContext_parseExpression(this, 0, 0);

      if (value == NULL || !ParserContext_expect(this, 36)) {
        return NULL;
      }

      return value;
    }

    if (ParserContext_peek(this, 6)) {
      return ParserContext_parseUnaryPrefix(this, 33, 0);
    }

    if (ParserContext_peek(this, 11)) {
      return ParserContext_parseUnaryPrefix(this, 34, 0);
    }

    if (ParserContext_peek(this, 25)) {
      return ParserContext_parseUnaryPrefix(this, 36, 0);
    }

    if (ParserContext_peek(this, 26)) {
      return ParserContext_parseUnaryPrefix(this, 42, 0);
    }

    if (ParserContext_peek(this, 28)) {
      return ParserContext_parseUnaryPrefix(this, 37, 0);
    }

    if (ParserContext_peek(this, 30)) {
      return ParserContext_parseUnaryPrefix(this, 39, 0);
    }

    if (ParserContext_peek(this, 31)) {
      return ParserContext_parseUnaryPrefix(this, 43, 0);
    }
  }

  ParserContext_unexpectedToken(this);

  return NULL;
}

static struct Node *ParserContext_parseInfix(struct ParserContext *this, int32_t precedence, struct Node *node, int32_t mode) {
  struct Range *token = this->current->range;

  if (ParserContext_peek(this, 13) && precedence < 15) {
    ParserContext_advance(this);
    struct Token *name = this->current;
    struct Range *range = name->range;

    if (isKeyword(name->kind)) {
      ParserContext_advance(this);
    }

    else if (!ParserContext_expect(this, 2)) {
      range = createRange(range->source, token->end, token->end);
    }

    return Node_withInternalRange(Node_withRange(createDot(node, Range_toString(range)), spanRanges(node->range, range)), range);
  }

  if (mode == 0) {
    if (ParserContext_peek(this, 5)) {
      return ParserContext_parseBinary(this, 45, node, precedence, 1);
    }

    if (ParserContext_peek(this, 6)) {
      return ParserContext_parseBinary(this, 46, node, precedence, 6);
    }

    if (ParserContext_peek(this, 7)) {
      return ParserContext_parseBinary(this, 47, node, precedence, 4);
    }

    if (ParserContext_peek(this, 8)) {
      return ParserContext_parseBinary(this, 48, node, precedence, 5);
    }

    if (ParserContext_peek(this, 12)) {
      return ParserContext_parseBinary(this, 49, node, precedence, 11);
    }

    if (ParserContext_peek(this, 14)) {
      return ParserContext_parseBinary(this, 50, node, precedence, 7);
    }

    if (ParserContext_peek(this, 15)) {
      return ParserContext_parseBinary(this, 51, node, precedence, 12);
    }

    if (ParserContext_peek(this, 16)) {
      return ParserContext_parseBinary(this, 52, node, precedence, 8);
    }

    if (ParserContext_peek(this, 17)) {
      return ParserContext_parseBinary(this, 53, node, precedence, 8);
    }

    if (ParserContext_peek(this, 21)) {
      return ParserContext_parseBinary(this, 54, node, precedence, 8);
    }

    if (ParserContext_peek(this, 22)) {
      return ParserContext_parseBinary(this, 55, node, precedence, 8);
    }

    if (ParserContext_peek(this, 23)) {
      return ParserContext_parseBinary(this, 56, node, precedence, 3);
    }

    if (ParserContext_peek(this, 24)) {
      return ParserContext_parseBinary(this, 57, node, precedence, 2);
    }

    if (ParserContext_peek(this, 25)) {
      return ParserContext_parseBinary(this, 63, node, precedence, 10);
    }

    if (ParserContext_peek(this, 27)) {
      return ParserContext_parseBinary(this, 58, node, precedence, 11);
    }

    if (ParserContext_peek(this, 29)) {
      return ParserContext_parseBinary(this, 59, node, precedence, 7);
    }

    if (ParserContext_peek(this, 30)) {
      return ParserContext_parseBinary(this, 44, node, precedence, 10);
    }

    if (ParserContext_peek(this, 33)) {
      return ParserContext_parseBinary(this, 60, node, precedence, 11);
    }

    if (ParserContext_peek(this, 38)) {
      return ParserContext_parseBinary(this, 61, node, precedence, 9);
    }

    if (ParserContext_peek(this, 39)) {
      return ParserContext_parseBinary(this, 62, node, precedence, 9);
    }

    if (ParserContext_peek(this, 31)) {
      return ParserContext_parseUnaryPostfix(this, 41, node, precedence);
    }

    if (ParserContext_peek(this, 26)) {
      return ParserContext_parseUnaryPostfix(this, 40, node, precedence);
    }

    if (ParserContext_peek(this, 41) && precedence < 13) {
      ParserContext_advance(this);
      struct Node *type = ParserContext_parseType(this);

      if (type == NULL) {
        return NULL;
      }

      return Node_withInternalRange(Node_withRange(createCast(node, type), spanRanges(node->range, type->range)), token);
    }

    uint8_t isIndex = ParserContext_peek(this, 19);

    if ((isIndex || ParserContext_peek(this, 20)) && precedence < 14) {
      return ParserContext_parseArgumentList(this, node->range, isIndex ? createIndex(node) : createCall(node));
    }

    if (ParserContext_peek(this, 32) && precedence < 1) {
      ParserContext_advance(this);
      struct Node *middle = ParserContext_parseExpression(this, 0, 0);

      if (middle == NULL || !ParserContext_expect(this, 9)) {
        return NULL;
      }

      struct Node *right = ParserContext_parseExpression(this, 0, 0);

      if (right == NULL) {
        return NULL;
      }

      return Node_withRange(createHook(node, middle, right), spanRanges(node->range, right->range));
    }
  }

  return node;
}

static struct Node *ParserContext_parseArgumentList(struct ParserContext *this, struct Range *start, struct Node *node) {
  struct Range *open = this->current->range;
  uint8_t isIndex = node->kind == 23;
  int32_t left = isIndex ? 19 : 20;
  int32_t right = isIndex ? 35 : 36;

  if (!ParserContext_expect(this, left)) {
    return NULL;
  }

  if (!ParserContext_peek(this, right)) {
    while (1) {
      struct Node *value = ParserContext_parseExpression(this, 0, 0);

      if (value == NULL) {
        return NULL;
      }

      Node_appendChild(node, value);

      if (!ParserContext_eat(this, 10)) {
        break;
      }
    }
  }

  struct Range *close = this->current->range;

  if (!ParserContext_expect(this, right)) {
    return NULL;
  }

  return Node_withInternalRange(Node_withRange(node, spanRanges(start, close)), spanRanges(open, close));
}

static struct Node *ParserContext_parseExpression(struct ParserContext *this, int32_t precedence, int32_t mode) {
  struct Node *node = ParserContext_parsePrefix(this, mode);

  if (node == NULL) {
    return NULL;
  }

  assert(node->range != NULL);

  while (1) {
    struct Node *result = ParserContext_parseInfix(this, precedence, node, mode);

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

static struct Node *ParserContext_parseType(struct ParserContext *this) {
  return ParserContext_parseExpression(this, 14, 1);
}

static struct Node *ParserContext_parseIf(struct ParserContext *this) {
  struct Token *token = this->current;
  assert(token->kind == 54);
  ParserContext_advance(this);

  if (!ParserContext_expect(this, 20)) {
    return NULL;
  }

  struct Node *value = NULL;

  if (ParserContext_peek(this, 36)) {
    ParserContext_unexpectedToken(this);
    ParserContext_advance(this);
    value = createParseError();
  }

  else {
    value = ParserContext_parseExpression(this, 0, 0);

    if (value == NULL || !ParserContext_expect(this, 36)) {
      return NULL;
    }
  }

  struct Node *trueBranch = ParserContext_parseBody(this);

  if (trueBranch == NULL) {
    return NULL;
  }

  struct Node *falseBranch = NULL;

  if (ParserContext_eat(this, 47)) {
    falseBranch = ParserContext_parseBody(this);

    if (falseBranch == NULL) {
      return NULL;
    }
  }

  return Node_withRange(createIf(value, trueBranch, falseBranch), spanRanges(token->range, (falseBranch != NULL ? falseBranch : trueBranch)->range));
}

static struct Node *ParserContext_parseWhile(struct ParserContext *this) {
  struct Token *token = this->current;
  assert(token->kind == 72);
  ParserContext_advance(this);

  if (!ParserContext_expect(this, 20)) {
    return NULL;
  }

  struct Node *value = NULL;

  if (ParserContext_peek(this, 36)) {
    ParserContext_unexpectedToken(this);
    ParserContext_advance(this);
    value = createParseError();
  }

  else {
    value = ParserContext_parseExpression(this, 0, 0);

    if (value == NULL || !ParserContext_expect(this, 36)) {
      return NULL;
    }
  }

  struct Node *body = ParserContext_parseBody(this);

  if (body == NULL) {
    return NULL;
  }

  return Node_withRange(createWhile(value, body), spanRanges(token->range, body->range));
}

static struct Node *ParserContext_parseBody(struct ParserContext *this) {
  struct Node *node = ParserContext_parseStatement(this, 0);

  if (node == NULL) {
    return NULL;
  }

  if (node->kind == 3) {
    return node;
  }

  struct Node *block = createBlock();
  Node_appendChild(block, node);

  return Node_withRange(block, node->range);
}

static struct Node *ParserContext_parseBlock(struct ParserContext *this) {
  struct Token *open = this->current;

  if (!ParserContext_expect(this, 18)) {
    return NULL;
  }

  struct Node *block = createBlock();

  if (!ParserContext_parseStatements(this, block)) {
    return NULL;
  }

  struct Token *close = this->current;

  if (!ParserContext_expect(this, 34)) {
    return NULL;
  }

  return Node_withRange(block, spanRanges(open->range, close->range));
}

static struct Node *ParserContext_parseReturn(struct ParserContext *this) {
  struct Token *token = this->current;
  assert(token->kind == 65);
  ParserContext_advance(this);
  struct Node *value = NULL;

  if (!ParserContext_peek(this, 37)) {
    value = ParserContext_parseExpression(this, 0, 0);

    if (value == NULL) {
      return NULL;
    }
  }

  struct Token *semicolon = this->current;
  ParserContext_expect(this, 37);

  return Node_withRange(createReturn(value), spanRanges(token->range, semicolon->range));
}

static struct Node *ParserContext_parseEmpty(struct ParserContext *this) {
  struct Token *token = this->current;
  ParserContext_advance(this);

  return Node_withRange(createEmpty(), token->range);
}

static struct Node *ParserContext_parseEnum(struct ParserContext *this, struct NodeFlag *firstFlag) {
  struct Token *token = this->current;
  assert(token->kind == 48);
  ParserContext_advance(this);
  struct Token *name = this->current;

  if (!ParserContext_expect(this, 2) || !ParserContext_expect(this, 18)) {
    return NULL;
  }

  const uint16_t *text = Range_toString(name->range);
  struct Node *node = createEnum(text);
  node->firstFlag = firstFlag;
  node->flags = allFlags(firstFlag);

  while (!ParserContext_peek(this, 0) && !ParserContext_peek(this, 34)) {
    struct Range *member = this->current->range;
    struct Node *value = NULL;

    if (!ParserContext_expect(this, 2)) {
      return NULL;
    }

    if (ParserContext_eat(this, 5)) {
      value = ParserContext_parseExpression(this, 0, 0);

      if (value == NULL) {
        return NULL;
      }
    }

    struct Node *variable = createVariable(Range_toString(member), createName(text), value);
    Node_appendChild(node, Node_withInternalRange(Node_withRange(variable, value != NULL ? spanRanges(member, value->range) : member), member));

    if (ParserContext_peek(this, 37)) {
      ParserContext_expect(this, 10);
      ParserContext_advance(this);
    }

    else if (ParserContext_peek(this, 2)) {
      ParserContext_expect(this, 10);
    }

    else if (!ParserContext_eat(this, 10)) {
      break;
    }
  }

  struct Token *close = this->current;

  if (!ParserContext_expect(this, 34)) {
    return NULL;
  }

  return Node_withInternalRange(Node_withRange(node, spanRanges(token->range, close->range)), name->range);
}

static struct Node *ParserContext_parseClass(struct ParserContext *this, struct NodeFlag *firstFlag) {
  struct Token *token = this->current;
  assert(token->kind == 43);
  ParserContext_advance(this);
  struct Token *name = this->current;

  if (!ParserContext_expect(this, 2) || !ParserContext_expect(this, 18)) {
    return NULL;
  }

  struct Node *node = createClass(Range_toString(name->range));
  node->firstFlag = firstFlag;
  node->flags = allFlags(firstFlag);

  while (!ParserContext_peek(this, 0) && !ParserContext_peek(this, 34)) {
    struct NodeFlag *childFlags = ParserContext_parseFlags(this);
    struct Token *childName = this->current;
    int32_t oldKind = childName->kind;

    if (isKeyword(childName->kind)) {
      childName->kind = 2;
      ParserContext_advance(this);
    }

    if (!ParserContext_expect(this, 2)) {
      return NULL;
    }

    const uint16_t *text = Range_toString(childName->range);

    if (string_op_equals(text, (const uint16_t *)__string_564_operator) && !ParserContext_peek(this, 20) && !ParserContext_peek(this, 2)) {
      childName->kind = 61;
      this->current = childName;

      if (ParserContext_parseFunction(this, childFlags, node) == NULL) {
        return NULL;
      }

      continue;
    }

    else if (ParserContext_peek(this, 2)) {
      uint8_t isGet = string_op_equals(text, (const uint16_t *)__string_565_get);
      uint8_t isSet = string_op_equals(text, (const uint16_t *)__string_566_set);

      if (isGet || isSet) {
        childFlags = appendFlag(childFlags, isGet ? 8 : 512, childName->range);
        childName = this->current;
        ParserContext_advance(this);
      }

      else if (oldKind == 53) {
        Log_error(this->log, childName->range, (const uint16_t *)__string_567_Instance_functions_don_t_need_th);
        childName = this->current;
        ParserContext_advance(this);
      }

      else if (oldKind == 44 || oldKind == 58 || oldKind == 71) {
        Log_error(this->log, childName->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_568_Instance_variables_don_t_need_th), Range_toString(childName->range)), (const uint16_t *)__string_569_keyword)));
        childName = this->current;
        ParserContext_advance(this);
      }
    }

    if (ParserContext_peek(this, 20)) {
      this->current = childName;

      if (ParserContext_parseFunction(this, childFlags, node) == NULL) {
        return NULL;
      }
    }

    else {
      this->current = childName;

      if (ParserContext_parseVariables(this, childFlags, node) == NULL) {
        return NULL;
      }
    }
  }

  struct Token *close = this->current;

  if (!ParserContext_expect(this, 34)) {
    return NULL;
  }

  return Node_withInternalRange(Node_withRange(node, spanRanges(token->range, close->range)), name->range);
}

static struct Node *ParserContext_parseFunction(struct ParserContext *this, struct NodeFlag *firstFlag, struct Node *parent) {
  uint8_t isOperator = 0;
  struct Token *token = this->current;
  struct Range *nameRange = NULL;
  const uint16_t *name = NULL;

  if (parent != NULL && ParserContext_eat(this, 61)) {
    struct Token *end = this->current;

    if (ParserContext_eat(this, 19)) {
      if (!ParserContext_expect(this, 35)) {
        return NULL;
      }

      if (ParserContext_peek(this, 5)) {
        nameRange = spanRanges(token->range, this->current->range);
        name = (const uint16_t *)__string_570;
        ParserContext_advance(this);
      }

      else {
        nameRange = spanRanges(token->range, end->range);
        name = (const uint16_t *)__string_571;
      }

      isOperator = 1;
    }

    else if (ParserContext_eat(this, 6) || ParserContext_eat(this, 7) || ParserContext_eat(this, 8) || ParserContext_eat(this, 11) || ParserContext_eat(this, 12) || ParserContext_eat(this, 14) || ParserContext_eat(this, 15) || ParserContext_eat(this, 21) || ParserContext_eat(this, 16) || ParserContext_eat(this, 25) || ParserContext_eat(this, 26) || ParserContext_eat(this, 27) || ParserContext_eat(this, 30) || ParserContext_eat(this, 31) || ParserContext_eat(this, 33) || ParserContext_eat(this, 38) || ParserContext_eat(this, 39)) {
      nameRange = end->range;
      name = Range_toString(nameRange);
      isOperator = 1;
    }

    else if (ParserContext_eat(this, 5) || ParserContext_eat(this, 17) || ParserContext_eat(this, 22) || ParserContext_eat(this, 23) || ParserContext_eat(this, 24) || ParserContext_eat(this, 28) || ParserContext_eat(this, 29)) {
      nameRange = end->range;
      name = Range_toString(nameRange);
      Log_error(this->log, nameRange, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_572_The_operator), name), (const uint16_t *)__string_573_cannot_be_implemented), end->kind == 29 ? (const uint16_t *)__string_574_it_is_automatically_derived_fr : end->kind == 22 ? (const uint16_t *)__string_575_it_is_automatically_derived_fr : end->kind == 17 ? (const uint16_t *)__string_576_it_is_automatically_derived_fr : (const uint16_t *)__string_577)));
    }

    else {
      ParserContext_unexpectedToken(this);
    }
  }

  else {
    if (parent == NULL) {
      assert(token->kind == 53);
      ParserContext_advance(this);
    }

    nameRange = this->current->range;

    if (!ParserContext_expect(this, 2)) {
      return NULL;
    }

    name = Range_toString(nameRange);
  }

  if (!ParserContext_expect(this, 20)) {
    return NULL;
  }

  struct Node *node = createFunction(name);
  node->firstFlag = firstFlag;
  node->flags = allFlags(firstFlag);

  if (isOperator) {
    node->flags = node->flags | 16;
  }

  if (!ParserContext_peek(this, 36)) {
    while (1) {
      struct NodeFlag *firstArgumentFlag = ParserContext_parseFlags(this);
      struct Token *argument = this->current;

      if (!ParserContext_expect(this, 2)) {
        return NULL;
      }

      struct Node *type = NULL;
      struct Range *range = argument->range;

      if (ParserContext_expect(this, 9)) {
        type = ParserContext_parseType(this);

        if (type != NULL) {
          range = spanRanges(range, type->range);
        }

        else if (ParserContext_peek(this, 10) || ParserContext_peek(this, 36)) {
          type = createParseError();
        }

        else {
          return NULL;
        }
      }

      else if (ParserContext_peek(this, 10) || ParserContext_peek(this, 36)) {
        type = createParseError();
      }

      struct Node *variable = createVariable(Range_toString(argument->range), type, NULL);
      variable->firstFlag = firstArgumentFlag;
      variable->flags = allFlags(firstArgumentFlag);
      Node_appendChild(node, Node_withInternalRange(Node_withRange(variable, range), argument->range));

      if (!ParserContext_eat(this, 10)) {
        break;
      }
    }
  }

  if (!ParserContext_expect(this, 36)) {
    return NULL;
  }

  struct Node *returnType = NULL;

  if (ParserContext_expect(this, 9)) {
    returnType = ParserContext_parseType(this);

    if (returnType == NULL) {
      if (ParserContext_peek(this, 37) || ParserContext_peek(this, 18)) {
        returnType = createParseError();
      }

      else {
        return NULL;
      }
    }
  }

  else if (ParserContext_peek(this, 37) || ParserContext_peek(this, 18)) {
    returnType = createParseError();
  }

  else {
    return NULL;
  }

  Node_appendChild(node, returnType);
  struct Node *block = NULL;
  struct Token *semicolon = this->current;

  if (ParserContext_eat(this, 37)) {
    block = Node_withRange(createEmpty(), semicolon->range);
  }

  else {
    block = ParserContext_parseBlock(this);

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

static struct Node *ParserContext_parseVariables(struct ParserContext *this, struct NodeFlag *firstFlag, struct Node *parent) {
  struct Token *token = this->current;

  if (parent == NULL) {
    assert(token->kind == 44 || token->kind == 58 || token->kind == 71);
    ParserContext_advance(this);
  }

  struct Node *node = token->kind == 44 ? createConstants() : createVariables();
  node->firstFlag = firstFlag;

  while (1) {
    struct Token *name = this->current;

    if (!ParserContext_expect(this, 2)) {
      return NULL;
    }

    struct Node *type = NULL;

    if (ParserContext_eat(this, 9)) {
      type = ParserContext_parseType(this);

      if (type == NULL) {
        return NULL;
      }
    }

    struct Node *value = NULL;

    if (ParserContext_eat(this, 5)) {
      value = ParserContext_parseExpression(this, 0, 0);

      if (value == NULL) {
        return NULL;
      }

      if (parent != NULL) {
        Log_error(this->log, value->range, (const uint16_t *)__string_578_Inline_initialization_of_instanc);
      }
    }

    struct Range *range = value != NULL ? spanRanges(name->range, value->range) : type != NULL ? spanRanges(name->range, type->range) : name->range;
    struct Node *variable = createVariable(Range_toString(name->range), type, value);
    variable->firstFlag = firstFlag;
    variable->flags = allFlags(firstFlag);
    Node_appendChild(parent != NULL ? parent : node, Node_withInternalRange(Node_withRange(variable, range), name->range));

    if (!ParserContext_eat(this, 10)) {
      break;
    }
  }

  struct Token *semicolon = this->current;
  ParserContext_expect(this, 37);

  return Node_withRange(node, spanRanges(token->range, semicolon->range));
}

static struct Node *ParserContext_parseLoopJump(struct ParserContext *this, int32_t kind) {
  struct Token *token = this->current;
  ParserContext_advance(this);
  ParserContext_expect(this, 37);
  struct Node *node = calloc(1, sizeof(struct Node));
  node->kind = kind;

  return Node_withRange(node, token->range);
}

static struct NodeFlag *ParserContext_parseFlags(struct ParserContext *this) {
  struct NodeFlag *firstFlag = NULL;
  struct NodeFlag *lastFlag = NULL;

  while (1) {
    struct Token *token = this->current;
    int32_t flag = 0;

    if (ParserContext_eat(this, 46)) {
      flag = 1;
    }

    else if (ParserContext_eat(this, 49)) {
      flag = 2;
    }

    else if (ParserContext_eat(this, 51)) {
      flag = 4;
    }

    else if (ParserContext_eat(this, 62)) {
      flag = 64;
    }

    else if (ParserContext_eat(this, 63)) {
      flag = 128;
    }

    else if (ParserContext_eat(this, 64)) {
      flag = 256;
    }

    else if (ParserContext_eat(this, 67)) {
      flag = 1024;
    }

    else if (ParserContext_eat(this, 70)) {
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

static struct Node *ParserContext_parseUnsafe(struct ParserContext *this) {
  struct Token *token = this->current;
  ParserContext_advance(this);
  struct Node *node = ParserContext_parseBlock(this);

  if (node == NULL) {
    return NULL;
  }

  node->flags = node->flags | 2048;

  return Node_withRange(node, spanRanges(token->range, node->range));
}

static struct Node *ParserContext_parseStatement(struct ParserContext *this, int32_t mode) {
  struct NodeFlag *firstFlag = mode == 1 ? ParserContext_parseFlags(this) : NULL;

  if (ParserContext_peek(this, 70) && firstFlag == NULL) {
    return ParserContext_parseUnsafe(this);
  }

  if (ParserContext_peek(this, 44) || ParserContext_peek(this, 58) || ParserContext_peek(this, 71)) {
    return ParserContext_parseVariables(this, firstFlag, NULL);
  }

  if (ParserContext_peek(this, 53)) {
    return ParserContext_parseFunction(this, firstFlag, NULL);
  }

  if (ParserContext_peek(this, 43)) {
    return ParserContext_parseClass(this, firstFlag);
  }

  if (ParserContext_peek(this, 48)) {
    return ParserContext_parseEnum(this, firstFlag);
  }

  if (firstFlag != NULL) {
    ParserContext_unexpectedToken(this);

    return NULL;
  }

  if (ParserContext_peek(this, 18)) {
    return ParserContext_parseBlock(this);
  }

  if (ParserContext_peek(this, 42)) {
    return ParserContext_parseLoopJump(this, 4);
  }

  if (ParserContext_peek(this, 45)) {
    return ParserContext_parseLoopJump(this, 7);
  }

  if (ParserContext_peek(this, 54)) {
    return ParserContext_parseIf(this);
  }

  if (ParserContext_peek(this, 72)) {
    return ParserContext_parseWhile(this);
  }

  if (ParserContext_peek(this, 65)) {
    return ParserContext_parseReturn(this);
  }

  if (ParserContext_peek(this, 37)) {
    return ParserContext_parseEmpty(this);
  }

  struct Node *value = ParserContext_parseExpression(this, 0, 0);

  if (value == NULL) {
    return NULL;
  }

  struct Token *semicolon = this->current;
  ParserContext_expect(this, 37);

  return Node_withRange(createExpression(value), spanRanges(value->range, semicolon->range));
}

static uint8_t ParserContext_parseStatements(struct ParserContext *this, struct Node *parent) {
  while (!ParserContext_peek(this, 0) && !ParserContext_peek(this, 34)) {
    struct Node *child = ParserContext_parseStatement(this, parent->kind == 0 ? 1 : 0);

    if (child == NULL) {
      return 0;
    }

    Node_appendChild(parent, child);
  }

  return 1;
}

static uint8_t ParserContext_parseInt(struct ParserContext *this, struct Range *range, struct Node *node) {
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
      Log_error(this->log, range, (const uint16_t *)__string_579_Use_the_0o_prefix_for_octal_in);

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
      Log_error(this->log, range, (const uint16_t *)__string_580_Integer_literal_is_too_big_to_fi);

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
  file->kind = 0;

  if (!ParserContext_parseStatements(context, file)) {
    return NULL;
  }

  return file;
}

static uint8_t Preprocessor_peek(struct Preprocessor *this, int32_t kind) {
  return this->current->kind == kind;
}

static uint8_t Preprocessor_eat(struct Preprocessor *this, int32_t kind) {
  if (Preprocessor_peek(this, kind)) {
    Preprocessor_advance(this);

    return 1;
  }

  return 0;
}

static void Preprocessor_advance(struct Preprocessor *this) {
  if (!Preprocessor_peek(this, 0)) {
    this->previous = this->current;
    this->current = this->current->next;
  }
}

static void Preprocessor_unexpectedToken(struct Preprocessor *this) {
  Log_error(this->log, this->current->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_581_Unexpected), tokenToString(this->current->kind))));
}

static uint8_t Preprocessor_expect(struct Preprocessor *this, int32_t kind) {
  if (!Preprocessor_peek(this, kind)) {
    Log_error(this->log, this->current->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_582_Expected), tokenToString(kind)), (const uint16_t *)__string_583_but_found), tokenToString(this->current->kind))));

    return 0;
  }

  Preprocessor_advance(this);

  return 1;
}

static void Preprocessor_removeTokensFrom(struct Preprocessor *this, struct Token *before) {
  before->next = this->current;
  this->previous = before;
}

static uint8_t Preprocessor_isDefined(struct Preprocessor *this, const uint16_t *name) {
  struct PreprocessorFlag *flag = this->firstFlag;

  while (flag != NULL) {
    if (string_op_equals(flag->name, name)) {
      return flag->isDefined;
    }

    flag = flag->next;
  }

  return 0;
}

static void Preprocessor_define(struct Preprocessor *this, const uint16_t *name, uint8_t isDefined) {
  struct PreprocessorFlag *flag = calloc(1, sizeof(struct PreprocessorFlag));
  flag->isDefined = isDefined;
  flag->name = name;
  flag->next = this->firstFlag;
  this->firstFlag = flag;
}

static void Preprocessor_run(struct Preprocessor *this, struct Source *source, struct Log *log) {
  struct Token *firstToken = source->firstToken;

  if (firstToken != NULL && firstToken->kind == 79) {
    struct PreprocessorFlag *firstFlag = this->firstFlag;
    this->isDefineAndUndefAllowed = 1;
    this->previous = firstToken;
    this->current = firstToken->next;
    this->log = log;

    if (!Preprocessor_scan(this, 1)) {
      source->firstToken = NULL;

      return;
    }

    if (!Preprocessor_peek(this, 0)) {
      Preprocessor_unexpectedToken(this);
    }

    this->firstFlag = firstFlag;
    source->firstToken = source->firstToken->next;
  }
}

static uint8_t Preprocessor_scan(struct Preprocessor *this, uint8_t isParentLive) {
  while (!Preprocessor_peek(this, 0) && !Preprocessor_peek(this, 74) && !Preprocessor_peek(this, 75) && !Preprocessor_peek(this, 76)) {
    struct Token *previous = this->previous;
    struct Token *current = this->current;

    if (Preprocessor_eat(this, 73) || Preprocessor_eat(this, 81)) {
      if (Preprocessor_expect(this, 2) && isParentLive) {
        Preprocessor_define(this, Range_toString(this->previous->range), current->kind == 73);
      }

      if (Preprocessor_eat(this, 52) || (Preprocessor_eat(this, 3) && string_op_equals(Range_toString(this->previous->range), (const uint16_t *)__string_584_0))) {
        Log_error(this->log, this->previous->range, (const uint16_t *)__string_585_Use_undef_to_turn_a_preproces);
      }

      if (!Preprocessor_peek(this, 0) && !Preprocessor_expect(this, 80)) {
        while (!Preprocessor_eat(this, 80) && !Preprocessor_eat(this, 0)) {
          Preprocessor_advance(this);
        }
      }

      if (!this->isDefineAndUndefAllowed) {
        Log_error(this->log, spanRanges(current->range, this->previous->range), (const uint16_t *)__string_586_All_define_and_undef_direc);
      }

      Preprocessor_removeTokensFrom(this, previous);
    }

    else if (Preprocessor_eat(this, 82) || Preprocessor_eat(this, 77)) {
      struct Token *next = this->current;

      while (!Preprocessor_peek(this, 80) && !Preprocessor_peek(this, 0)) {
        Preprocessor_advance(this);
      }

      if (isParentLive) {
        struct Range *range = this->current == next ? current->range : spanRanges(next->range, this->previous->range);
        Log_append(this->log, range, Range_toString(range), current->kind == 82 ? 1 : 0);
      }

      Preprocessor_eat(this, 80);
      Preprocessor_removeTokensFrom(this, previous);
    }

    else if (Preprocessor_eat(this, 78)) {
      uint8_t isLive = isParentLive;

      while (1) {
        int32_t condition = Preprocessor_parseExpression(this, 0);

        if (condition == 2 || !Preprocessor_expect(this, 80)) {
          return 0;
        }

        Preprocessor_removeTokensFrom(this, previous);

        if (!Preprocessor_scan(this, isLive && condition == 1)) {
          return 0;
        }

        if (!isLive || condition == 0) {
          Preprocessor_removeTokensFrom(this, previous);
        }

        else {
          isLive = 0;
        }

        previous = this->previous;

        if (Preprocessor_eat(this, 74)) {
          continue;
        }

        if (Preprocessor_eat(this, 75)) {
          if (!Preprocessor_expect(this, 80)) {
            return 0;
          }

          Preprocessor_removeTokensFrom(this, previous);

          if (!Preprocessor_scan(this, isLive)) {
            return 0;
          }

          if (!isLive) {
            Preprocessor_removeTokensFrom(this, previous);
          }
        }

        break;
      }

      previous = this->previous;

      if (!Preprocessor_expect(this, 76) || (!Preprocessor_peek(this, 0) && !Preprocessor_expect(this, 80))) {
        return 0;
      }

      Preprocessor_removeTokensFrom(this, previous);
    }

    else {
      this->isDefineAndUndefAllowed = 0;
      Preprocessor_advance(this);
    }
  }

  return 1;
}

static int32_t Preprocessor_parsePrefix(struct Preprocessor *this) {
  uint8_t isDefinedOperator = 0;
  struct Token *start = this->current;

  if (Preprocessor_eat(this, 69)) {
    return 1;
  }

  if (Preprocessor_eat(this, 52)) {
    return 0;
  }

  if (Preprocessor_eat(this, 2)) {
    const uint16_t *name = Range_toString(this->previous->range);

    if (Preprocessor_peek(this, 20) && string_op_equals(name, (const uint16_t *)__string_587_defined)) {
      isDefinedOperator = 1;
    }

    else {
      uint8_t isTrue = Preprocessor_isDefined(this, name);

      return isTrue ? 1 : 0;
    }
  }

  if (Preprocessor_eat(this, 28)) {
    int32_t value = Preprocessor_parseExpression(this, 13);

    if (value == 2) {
      return 2;
    }

    return value == 1 ? 0 : 1;
  }

  if (Preprocessor_eat(this, 20)) {
    struct Token *first = this->current;
    int32_t value = Preprocessor_parseExpression(this, 0);

    if (value == 2 || !Preprocessor_expect(this, 36)) {
      return 2;
    }

    if (isDefinedOperator) {
      struct StringBuilder *builder = StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_588_There_is_no_defined_operator);

      if (first->kind == 2 && this->previous == first->next) {
        StringBuilder_append(StringBuilder_append(StringBuilder_append(builder, (const uint16_t *)__string_589_just_use), Range_toString(first->range)), (const uint16_t *)__string_590_instead);
      }

      Log_error(this->log, spanRanges(start->range, this->previous->range), StringBuilder_finish(builder));
    }

    return value;
  }

  if (Preprocessor_eat(this, 3)) {
    uint8_t isTrue = !string_op_equals(Range_toString(this->previous->range), (const uint16_t *)__string_591_0);
    Log_error(this->log, this->previous->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_592_Unexpected_integer_did_you_mean), isTrue ? (const uint16_t *)__string_593_true : (const uint16_t *)__string_594_false), (const uint16_t *)__string_595)));

    return isTrue ? 1 : 0;
  }

  Preprocessor_unexpectedToken(this);

  return 2;
}

static int32_t Preprocessor_parseInfix(struct Preprocessor *this, int32_t precedence, int32_t left) {
  int32_t operator = this->current->kind;

  if (precedence < 7 && (Preprocessor_eat(this, 14) || Preprocessor_eat(this, 29))) {
    int32_t right = Preprocessor_parseExpression(this, 7);

    if (right == 2) {
      return 2;
    }

    return (operator == 14) == (left == right) ? 1 : 0;
  }

  if (precedence < 3 && Preprocessor_eat(this, 23)) {
    int32_t right = Preprocessor_parseExpression(this, 3);

    if (right == 2) {
      return 2;
    }

    return left == 1 && right == 1 ? 1 : 0;
  }

  if (precedence < 2 && Preprocessor_eat(this, 24)) {
    int32_t right = Preprocessor_parseExpression(this, 2);

    if (right == 2) {
      return 2;
    }

    return left == 1 || right == 1 ? 1 : 0;
  }

  if (precedence == 0 && Preprocessor_eat(this, 32)) {
    int32_t middle = Preprocessor_parseExpression(this, 0);

    if (middle == 2 || !Preprocessor_expect(this, 9)) {
      return 2;
    }

    int32_t right = Preprocessor_parseExpression(this, 0);

    if (right == 2) {
      return 2;
    }

    return left == 1 ? middle : right;
  }

  return left;
}

static int32_t Preprocessor_parseExpression(struct Preprocessor *this, int32_t precedence) {
  int32_t value = Preprocessor_parsePrefix(this);

  if (value == 2) {
    return 2;
  }

  while (1) {
    struct Token *current = this->current;
    value = Preprocessor_parseInfix(this, precedence, value);

    if (value == 2) {
      return 2;
    }

    if (this->current == current) {
      break;
    }
  }

  return value;
}

static struct Symbol *Scope_findLocal(struct Scope *this, const uint16_t *name, int32_t hint) {
  struct Symbol *symbol = this->firstSymbol;
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

static struct Symbol *Scope_findNested(struct Scope *this, const uint16_t *name, int32_t hint, int32_t mode) {
  struct Scope *scope = this;

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

static uint8_t Scope_define(struct Scope *this, struct Log *log, struct Symbol *symbol, int32_t hint) {
  struct Symbol *existing = Scope_findLocal(this, symbol->name, hint);

  if (existing != NULL) {
    Log_error(log, symbol->range, StringBuilder_finish(StringBuilder_append(StringBuilder_append(StringBuilder_append(StringBuilder_new(), (const uint16_t *)__string_596_Duplicate_symbol), symbol->name), (const uint16_t *)__string_597)));

    return 0;
  }

  if (this->firstSymbol == NULL) {
    this->firstSymbol = symbol;
  }

  else {
    this->lastSymbol->next = symbol;
  }

  this->lastSymbol = symbol;

  return 1;
}

static struct Type *Scope_defineNativeType(struct Scope *this, struct Log *log, const uint16_t *name) {
  struct Symbol *symbol = calloc(1, sizeof(struct Symbol));
  symbol->kind = 3;
  symbol->name = name;
  symbol->resolvedType = calloc(1, sizeof(struct Type));
  symbol->resolvedType->symbol = symbol;
  symbol->state = 2;
  Scope_define(this, log, symbol, 0);

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

  if (node->kind == 26) {
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
  if (node->kind == 11 && Node_isExtern(node)) {
    treeShakingMarkAllUsed(node);
  }

  else if (node->kind == 1 || node->kind == 5) {
    struct Node *child = node->firstChild;

    while (child != NULL) {
      treeShakingSearchForUsed(child);
      child = child->nextSibling;
    }

    if (node->kind == 5 && Node_isExtern(node)) {
      node->symbol->flags = node->symbol->flags | 64;
    }
  }
}

static void treeShakingRemoveUnused(struct Node *node) {
  if (node->kind == 11 && !Symbol_isUsed(node->symbol) && node->range->source->isLibrary) {
    Node_remove(node);
  }

  else if (node->kind == 1 || node->kind == 5) {
    struct Node *child = node->firstChild;

    while (child != NULL) {
      struct Node *next = child->nextSibling;
      treeShakingRemoveUnused(child);
      child = next;
    }

    if (node->kind == 5 && !Symbol_isUsed(node->symbol) && !Node_isDeclare(node) && node->range->source->isLibrary) {
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
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_598);
    }

    else if (c == 0) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_599_0);
    }

    else if (c == 9) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_600_t);
    }

    else if (c == 13) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_601_r);
    }

    else if (c == 10) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_602_n);
    }

    else if (c == 92) {
      StringBuilder_append(StringBuilder_appendSlice(sb, text, start, end), (const uint16_t *)__string_603);
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

static void StringBuilder_clear(struct StringBuilder *this) {
  struct ByteArray *bytes = this->_bytes;

  if (bytes == NULL) {
    bytes = calloc(1, sizeof(struct ByteArray));
    this->_bytes = bytes;
  }

  else {
    ByteArray_clear(bytes);
  }
}

static struct StringBuilder *StringBuilder_appendChar(struct StringBuilder *this, uint16_t c) {
  ByteArray_append(this->_bytes, (uint8_t)c);
  ByteArray_append(this->_bytes, (uint8_t)(c >> 8));

  return this;
}

static struct StringBuilder *StringBuilder_appendSlice(struct StringBuilder *this, const uint16_t *text, int32_t start, int32_t end) {
  return StringBuilder_append(this, string_slice(text, start, end));
}

static struct StringBuilder *StringBuilder_append(struct StringBuilder *this, const uint16_t *text) {
  struct ByteArray *bytes = this->_bytes;
  uint32_t index = bytes->_length;
  int32_t length = string_length(text);
  ByteArray_resize(bytes, (int32_t)index + (length << 1));
  memcpy(bytes->_data + index, (uint8_t *)text + 4, (uint32_t)length << 1);

  return this;
}

static const uint16_t *StringBuilder_finish(struct StringBuilder *this) {
  this->next = stringBuilderPool;
  stringBuilderPool = this;
  struct ByteArray *bytes = this->_bytes;
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

static uint8_t Symbol_isEnumValue(struct Symbol *this) {
  return this->node->parent->kind == 9;
}

static uint8_t Symbol_isUnsafe(struct Symbol *this) {
  return this->node != NULL && Node_isUnsafe(this->node);
}

static uint8_t Symbol_isGetter(struct Symbol *this) {
  return Node_isGet(this->node);
}

static uint8_t Symbol_isSetter(struct Symbol *this) {
  return Node_isSet(this->node);
}

static uint8_t Symbol_isBinaryOperator(struct Symbol *this) {
  return (this->flags & 2) != 0;
}

static uint8_t Symbol_isUnaryOperator(struct Symbol *this) {
  return (this->flags & 8) != 0;
}

static uint8_t Symbol_shouldConvertInstanceToGlobal(struct Symbol *this) {
  return (this->flags & 1) != 0;
}

static uint8_t Symbol_isUsed(struct Symbol *this) {
  return (this->flags & 64) != 0;
}

static struct Symbol *Symbol_parent(struct Symbol *this) {
  struct Node *parent = this->node->parent;

  return parent->kind == 5 ? parent->symbol : NULL;
}

static struct Type *Symbol_resolvedTypeUnderlyingIfEnumValue(struct Symbol *this, struct CheckContext *context) {
  return Symbol_isEnumValue(this) ? Type_underlyingType(this->resolvedType, context) : this->resolvedType;
}

static void Symbol_determineClassLayout(struct Symbol *this, struct CheckContext *context) {
  assert(this->kind == 0);

  if (this->byteSize != 0) {
    return;
  }

  int32_t offset = 0;
  struct Node *child = this->node->firstChild;
  int32_t maxAlignment = 1;

  while (child != NULL) {
    if (child->kind == 2) {
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
  this->byteSize = offset;
  this->maxAlignment = maxAlignment;
}

static uint8_t Type_isClass(struct Type *this) {
  return this->symbol != NULL && this->symbol->kind == 0;
}

static uint8_t Type_isEnum(struct Type *this) {
  return this->symbol != NULL && this->symbol->kind == 1;
}

static uint8_t Type_isInteger(struct Type *this) {
  return (this->symbol != NULL && (this->symbol->flags & 32) != 0) || Type_isEnum(this);
}

static uint8_t Type_isUnsigned(struct Type *this) {
  return this->symbol != NULL && (this->symbol->flags & 16) != 0;
}

static uint8_t Type_isReference(struct Type *this) {
  return this->pointerTo != NULL || (this->symbol != NULL && (this->symbol->flags & 4) != 0);
}

static struct Type *Type_underlyingType(struct Type *this, struct CheckContext *context) {
  return Type_isEnum(this) ? context->intType : this->pointerTo != NULL ? context->uintType : this;
}

static int32_t Type_integerBitCount(struct Type *this, struct CheckContext *context) {
  return this->symbol != NULL ? this->symbol->byteSize << 3 : 0;
}

static uint32_t Type_integerBitMask(struct Type *this, struct CheckContext *context) {
  return 4294967295 >> (uint32_t)(32 - Type_integerBitCount(this, context));
}

static int32_t Type_allocationSizeOf(struct Type *this, struct CheckContext *context) {
  return this->symbol == NULL ? context->pointerByteSize : this->symbol->byteSize;
}

static int32_t Type_allocationAlignmentOf(struct Type *this, struct CheckContext *context) {
  return Type_allocationSizeOf(this, context);
}

static int32_t Type_variableSizeOf(struct Type *this, struct CheckContext *context) {
  return Type_isReference(this) ? context->pointerByteSize : this->symbol->byteSize;
}

static int32_t Type_variableAlignmentOf(struct Type *this, struct CheckContext *context) {
  return Type_variableSizeOf(this, context);
}

static struct Type *Type_pointerType(struct Type *this) {
  struct Type *type = this->cachedPointerType;

  if (type == NULL) {
    type = calloc(1, sizeof(struct Type));
    type->pointerTo = this;
    this->cachedPointerType = type;
  }

  return type;
}

static const uint16_t *Type_toString(struct Type *this) {
  if (string_op_equals(this->cachedToString, NULL)) {
    this->cachedToString = this->pointerTo != NULL ? StringBuilder_finish(StringBuilder_append(StringBuilder_appendChar(StringBuilder_new(), 42), Type_toString(this->pointerTo))) : this->symbol->name;
  }

  return this->cachedToString;
}

static struct Symbol *Type_findMember(struct Type *this, const uint16_t *name, int32_t hint) {
  struct Symbol *symbol = this->symbol;

  return symbol != NULL && symbol->scope != NULL ? Scope_findLocal(symbol->scope, name, hint) : NULL;
}

static uint8_t Type_hasInstanceMembers(struct Type *this) {
  struct Symbol *symbol = this->symbol;

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

static void WasmModule_growMemoryInitializer(struct WasmModule *this) {
  struct ByteArray *array = this->memoryInitializer;
  int32_t current = ByteArray_length(array);
  int32_t length = this->context->nextGlobalVariableOffset;

  while (current < length) {
    ByteArray_append(array, 0);
    current = current + 1;
  }
}

static struct WasmImport *WasmModule_allocateImport(struct WasmModule *this, int32_t signatureIndex, const uint16_t *mod, const uint16_t *name) {
  struct WasmImport *result = calloc(1, sizeof(struct WasmImport));
  result->signatureIndex = signatureIndex;
  result->module = mod;
  result->name = name;

  if (this->firstImport == NULL) {
    this->firstImport = result;
  }

  else {
    this->lastImport->next = result;
  }

  this->lastImport = result;
  this->importCount = this->importCount + 1;

  return result;
}

static struct WasmFunction *WasmModule_allocateFunction(struct WasmModule *this, const uint16_t *name, int32_t signatureIndex, struct Node *body) {
  struct WasmFunction *fn = calloc(1, sizeof(struct WasmFunction));
  fn->name = name;
  fn->signatureIndex = signatureIndex;
  fn->body = body;

  if (this->firstFunction == NULL) {
    this->firstFunction = fn;
  }

  else {
    this->lastFunction->next = fn;
  }

  this->lastFunction = fn;
  this->functionCount = this->functionCount + 1;

  return fn;
}

static int32_t WasmModule_allocateSignature(struct WasmModule *this, struct WasmWrappedType *argumentTypes, struct WasmWrappedType *returnType) {
  assert(returnType != NULL);
  assert(returnType->next == NULL);
  struct WasmSignature *signature = calloc(1, sizeof(struct WasmSignature));
  signature->argumentTypes = argumentTypes;
  signature->returnType = returnType;
  struct WasmSignature *check = this->firstSignature;
  int32_t i = 0;

  while (check != NULL) {
    if (wasmAreSignaturesEqual(signature, check)) {
      return i;
    }

    check = check->next;
    i = i + 1;
  }

  if (this->firstSignature == NULL) {
    this->firstSignature = signature;
  }

  else {
    this->lastSignature->next = signature;
  }

  this->lastSignature = signature;
  this->signatureCount = this->signatureCount + 1;

  return i;
}

static void WasmModule_emitModule(struct WasmModule *this, struct ByteArray *array) {
  ByteArray_append32(array, 1836278016);
  ByteArray_append32(array, 10);
  WasmModule_emitSignatures(this, array);
  WasmModule_emitImportTable(this, array);
  WasmModule_emitFunctionSignatures(this, array);
  WasmModule_emitMemory(this, array);
  WasmModule_emitExportTable(this, array);
  WasmModule_emitFunctionBodies(this, array);
  WasmModule_emitDataSegments(this, array);
}

static void WasmModule_emitSignatures(struct WasmModule *this, struct ByteArray *array) {
  int32_t section = wasmStartSection(array, (const uint16_t *)__string_604_signatures);
  wasmWriteVarUnsigned(array, this->signatureCount);
  struct WasmSignature *signature = this->firstSignature;

  while (signature != NULL) {
    int32_t count = 0;
    struct WasmWrappedType *type = signature->argumentTypes;

    while (type != NULL) {
      count = count + 1;
      type = type->next;
    }

    wasmWriteVarUnsigned(array, count);
    wasmWriteVarUnsigned(array, (int32_t)signature->returnType->id);
    type = signature->argumentTypes;

    while (type != NULL) {
      wasmWriteVarUnsigned(array, (int32_t)type->id);
      type = type->next;
    }

    signature = signature->next;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitImportTable(struct WasmModule *this, struct ByteArray *array) {
  if (this->firstImport == NULL) {
    return;
  }

  int32_t section = wasmStartSection(array, (const uint16_t *)__string_605_import_table);
  wasmWriteVarUnsigned(array, this->importCount);
  struct WasmImport *current = this->firstImport;

  while (current != NULL) {
    wasmWriteVarUnsigned(array, current->signatureIndex);
    wasmWriteLengthPrefixedASCII(array, current->module);
    wasmWriteLengthPrefixedASCII(array, current->name);
    current = current->next;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitFunctionSignatures(struct WasmModule *this, struct ByteArray *array) {
  if (this->firstFunction == NULL) {
    return;
  }

  int32_t section = wasmStartSection(array, (const uint16_t *)__string_606_function_signatures);
  wasmWriteVarUnsigned(array, this->functionCount);
  struct WasmFunction *fn = this->firstFunction;

  while (fn != NULL) {
    wasmWriteVarUnsigned(array, fn->signatureIndex);
    fn = fn->next;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitMemory(struct WasmModule *this, struct ByteArray *array) {
  int32_t section = wasmStartSection(array, (const uint16_t *)__string_607_memory);
  wasmWriteVarUnsigned(array, 256);
  wasmWriteVarUnsigned(array, 256);
  wasmWriteVarUnsigned(array, 1);
  wasmFinishSection(array, section);
}

static void WasmModule_emitExportTable(struct WasmModule *this, struct ByteArray *array) {
  int32_t exportedCount = 0;
  struct WasmFunction *fn = this->firstFunction;

  while (fn != NULL) {
    if (fn->isExported) {
      exportedCount = exportedCount + 1;
    }

    fn = fn->next;
  }

  if (exportedCount == 0) {
    return;
  }

  int32_t section = wasmStartSection(array, (const uint16_t *)__string_608_export_table);
  wasmWriteVarUnsigned(array, exportedCount);
  int32_t i = 0;
  fn = this->firstFunction;

  while (fn != NULL) {
    if (fn->isExported) {
      wasmWriteVarUnsigned(array, i);
      wasmWriteLengthPrefixedASCII(array, fn->name);
    }

    fn = fn->next;
    i = i + 1;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitFunctionBodies(struct WasmModule *this, struct ByteArray *array) {
  if (this->firstFunction == NULL) {
    return;
  }

  int32_t section = wasmStartSection(array, (const uint16_t *)__string_609_function_bodies);
  wasmWriteVarUnsigned(array, this->functionCount);
  struct WasmFunction *fn = this->firstFunction;

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

    struct Node *child = fn->body->firstChild;

    while (child != NULL) {
      WasmModule_emitNode(this, array, child);
      child = child->nextSibling;
    }

    wasmPatchVarUnsigned(array, bodyLength, ByteArray_length(array) - bodyLength - 5, -1);
    fn = fn->next;
  }

  wasmFinishSection(array, section);
}

static void WasmModule_emitDataSegments(struct WasmModule *this, struct ByteArray *array) {
  WasmModule_growMemoryInitializer(this);
  struct ByteArray *memoryInitializer = this->memoryInitializer;
  int32_t initializerLength = ByteArray_length(memoryInitializer);
  int32_t initialHeapPointer = alignToNextMultipleOf(initializerLength + 8, 8);
  ByteArray_set32(memoryInitializer, this->currentHeapPointer, initialHeapPointer);
  ByteArray_set32(memoryInitializer, this->originalHeapPointer, initialHeapPointer);
  int32_t section = wasmStartSection(array, (const uint16_t *)__string_610_data_segments);
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

static void WasmModule_prepareToEmit(struct WasmModule *this, struct Node *node) {
  if (node->kind == 30) {
    const uint16_t *text = node->stringValue;
    int32_t length = string_length(text);
    int32_t offset = CheckContext_allocateGlobalVariableOffset(this->context, (length << 1) + 4, 4);
    node->intValue = offset;
    WasmModule_growMemoryInitializer(this);
    struct ByteArray *memoryInitializer = this->memoryInitializer;
    ByteArray_set32(memoryInitializer, offset, length);
    ByteArray_setString(memoryInitializer, offset + 4, text);
  }

  else if (node->kind == 2) {
    struct Symbol *symbol = node->symbol;

    if (symbol->kind == 8) {
      int32_t sizeOf = Type_variableSizeOf(symbol->resolvedType, this->context);
      int32_t value = Node_variableValue(symbol->node)->intValue;
      struct ByteArray *memoryInitializer = this->memoryInitializer;
      WasmModule_growMemoryInitializer(this);

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

      if (string_op_equals(symbol->name, (const uint16_t *)__string_611_currentHeapPointer)) {
        assert(this->currentHeapPointer == -1);
        this->currentHeapPointer = symbol->offset;
      }

      else if (string_op_equals(symbol->name, (const uint16_t *)__string_612_originalHeapPointer)) {
        assert(this->originalHeapPointer == -1);
        this->originalHeapPointer = symbol->offset;
      }
    }
  }

  else if (node->kind == 11) {
    struct Node *returnType = Node_functionReturnType(node);
    struct WasmSharedOffset *shared = calloc(1, sizeof(struct WasmSharedOffset));
    struct WasmWrappedType *argumentTypesFirst = NULL;
    struct WasmWrappedType *argumentTypesLast = NULL;
    struct Node *argument = node->firstChild;

    while (argument != returnType) {
      struct WasmWrappedType *type = wasmWrapType(WasmModule_getWasmType(this, Node_variableType(argument)->resolvedType));

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

    int32_t signatureIndex = WasmModule_allocateSignature(this, argumentTypesFirst, wasmWrapType(WasmModule_getWasmType(this, returnType->resolvedType)));
    struct Node *body = Node_functionBody(node);
    struct Symbol *symbol = node->symbol;

    if (body == NULL) {
      const uint16_t *moduleName = symbol->kind == 4 ? Symbol_parent(symbol)->name : (const uint16_t *)__string_613_global;
      symbol->offset = this->importCount;
      WasmModule_allocateImport(this, signatureIndex, moduleName, symbol->name);
      node = node->nextSibling;

      return;
    }

    symbol->offset = this->functionCount;
    struct WasmFunction *fn = WasmModule_allocateFunction(this, symbol->name, signatureIndex, body);

    if (symbol->kind == 5 && string_op_equals(symbol->name, (const uint16_t *)__string_614_malloc)) {
      assert(this->mallocFunctionIndex == -1);
      this->mallocFunctionIndex = symbol->offset;
    }

    if (Node_isExtern(node)) {
      fn->isExported = 1;
    }

    wasmAssignLocalVariableOffsets(body, shared);
    fn->intLocalCount = shared->intLocalCount;
  }

  struct Node *child = node->firstChild;

  while (child != NULL) {
    WasmModule_prepareToEmit(this, child);
    child = child->nextSibling;
  }
}

static void WasmModule_emitBinaryExpression(struct WasmModule *this, struct ByteArray *array, struct Node *node, uint8_t opcode) {
  ByteArray_append(array, opcode);
  WasmModule_emitNode(this, array, Node_binaryLeft(node));
  WasmModule_emitNode(this, array, Node_binaryRight(node));
}

static void WasmModule_emitLoadFromMemory(struct WasmModule *this, struct ByteArray *array, struct Type *type, struct Node *relativeBase, int32_t offset) {
  int32_t sizeOf = Type_variableSizeOf(type, this->context);

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

  if (relativeBase != NULL) {
    WasmModule_emitNode(this, array, relativeBase);
  }

  else {
    ByteArray_append(array, 10);
    wasmWriteVarUnsigned(array, 0);
  }
}

static void WasmModule_emitStoreToMemory(struct WasmModule *this, struct ByteArray *array, struct Type *type, struct Node *relativeBase, int32_t offset, struct Node *value) {
  int32_t sizeOf = Type_variableSizeOf(type, this->context);

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

  if (relativeBase != NULL) {
    WasmModule_emitNode(this, array, relativeBase);
  }

  else {
    ByteArray_append(array, 10);
    wasmWriteVarUnsigned(array, 0);
  }

  WasmModule_emitNode(this, array, value);
}

static int32_t WasmModule_emitNode(struct WasmModule *this, struct ByteArray *array, struct Node *node) {
  assert(!isExpression(node) || node->resolvedType != NULL);

  if (node->kind == 3) {
    ByteArray_append(array, 1);
    int32_t offset = ByteArray_length(array);
    wasmWriteVarUnsigned(array, -1);
    int32_t count = 0;
    struct Node *child = node->firstChild;

    while (child != NULL) {
      count = count + WasmModule_emitNode(this, array, child);
      child = child->nextSibling;
    }

    wasmPatchVarUnsigned(array, offset, count, -1);
  }

  else if (node->kind == 16) {
    struct Node *value = Node_whileValue(node);
    struct Node *body = Node_whileBody(node);

    if (value->kind == 18 && value->intValue == 0) {
      return 0;
    }

    ByteArray_append(array, 2);
    int32_t offset = ByteArray_length(array);
    wasmWriteVarUnsigned(array, -1);
    int32_t count = 0;

    if (value->kind != 18) {
      ByteArray_append(array, 7);
      wasmWriteVarUnsigned(array, 1);
      ByteArray_append(array, 0);
      ByteArray_append(array, 90);
      WasmModule_emitNode(this, array, value);
      count = count + 1;
    }

    struct Node *child = body->firstChild;

    while (child != NULL) {
      count = count + WasmModule_emitNode(this, array, child);
      child = child->nextSibling;
    }

    ByteArray_append(array, 6);
    wasmWriteVarUnsigned(array, 0);
    ByteArray_append(array, 0);
    count = count + 1;
    wasmPatchVarUnsigned(array, offset, count, -1);
  }

  else if (node->kind == 4 || node->kind == 7) {
    int32_t label = 0;
    struct Node *parent = node->parent;

    while (parent != NULL && parent->kind != 16) {
      if (parent->kind == 3) {
        label = label + 1;
      }

      parent = parent->parent;
    }

    assert(label > 0);
    ByteArray_append(array, 6);
    wasmWriteVarUnsigned(array, label - (node->kind == 4 ? 0 : 1));
    ByteArray_append(array, 0);
  }

  else if (node->kind == 8) {
    return 0;
  }

  else if (node->kind == 10) {
    WasmModule_emitNode(this, array, Node_expressionValue(node));
  }

  else if (node->kind == 13) {
    struct Node *value = Node_returnValue(node);
    ByteArray_append(array, 20);

    if (value != NULL) {
      WasmModule_emitNode(this, array, value);
    }
  }

  else if (node->kind == 15) {
    int32_t count = 0;
    struct Node *child = node->firstChild;

    while (child != NULL) {
      assert(child->kind == 2);
      count = count + WasmModule_emitNode(this, array, child);
      child = child->nextSibling;
    }

    return count;
  }

  else if (node->kind == 12) {
    struct Node *branch = Node_ifFalse(node);
    ByteArray_append(array, branch == NULL ? 3 : 4);
    WasmModule_emitNode(this, array, Node_ifValue(node));
    WasmModule_emitNode(this, array, Node_ifTrue(node));

    if (branch != NULL) {
      WasmModule_emitNode(this, array, branch);
    }
  }

  else if (node->kind == 22) {
    ByteArray_append(array, 4);
    WasmModule_emitNode(this, array, Node_hookValue(node));
    WasmModule_emitNode(this, array, Node_hookTrue(node));
    WasmModule_emitNode(this, array, Node_hookFalse(node));
  }

  else if (node->kind == 2) {
    struct Node *value = Node_variableValue(node);

    if (node->symbol->kind == 10) {
      ByteArray_append(array, 15);
      wasmWriteVarUnsigned(array, node->symbol->offset);

      if (value != NULL) {
        WasmModule_emitNode(this, array, value);
      }

      else {
        ByteArray_append(array, 10);
        wasmWriteVarSigned(array, 0);
      }
    }

    else {
      assert(0);
    }
  }

  else if (node->kind == 25) {
    struct Symbol *symbol = node->symbol;

    if (symbol->kind == 6 || symbol->kind == 10) {
      ByteArray_append(array, 14);
      wasmWriteVarUnsigned(array, symbol->offset);
    }

    else if (symbol->kind == 8) {
      WasmModule_emitLoadFromMemory(this, array, symbol->resolvedType, NULL, symbol->offset + 8);
    }

    else {
      assert(0);
    }
  }

  else if (node->kind == 35) {
    WasmModule_emitLoadFromMemory(this, array, Type_underlyingType(node->resolvedType, this->context), Node_unaryValue(node), 0);
  }

  else if (node->kind == 27) {
    ByteArray_append(array, 10);
    wasmWriteVarSigned(array, 0);
  }

  else if (node->kind == 24 || node->kind == 18) {
    ByteArray_append(array, 10);
    wasmWriteVarSigned(array, node->intValue);
  }

  else if (node->kind == 30) {
    ByteArray_append(array, 10);
    wasmWriteVarSigned(array, node->intValue + 8);
  }

  else if (node->kind == 19) {
    struct Node *value = Node_callValue(node);
    struct Symbol *symbol = value->symbol;
    assert(isFunction(symbol->kind));
    ByteArray_append(array, Node_functionBody(symbol->node) == NULL ? 31 : 18);
    wasmWriteVarUnsigned(array, symbol->offset);

    if (symbol->kind == 4) {
      WasmModule_emitNode(this, array, Node_dotTarget(value));
    }

    struct Node *child = value->nextSibling;

    while (child != NULL) {
      WasmModule_emitNode(this, array, child);
      child = child->nextSibling;
    }
  }

  else if (node->kind == 26) {
    struct Node *type = Node_newType(node);
    int32_t size = Type_allocationSizeOf(type->resolvedType, this->context);
    ByteArray_append(array, 18);
    wasmWriteVarUnsigned(array, this->mallocFunctionIndex);
    assert(size > 0);
    ByteArray_append(array, 10);
    wasmWriteVarSigned(array, size);
  }

  else if (node->kind == 39) {
    WasmModule_emitNode(this, array, Node_unaryValue(node));
  }

  else if (node->kind == 36) {
    ByteArray_append(array, 65);
    ByteArray_append(array, 10);
    wasmWriteVarSigned(array, 0);
    WasmModule_emitNode(this, array, Node_unaryValue(node));
  }

  else if (node->kind == 34) {
    ByteArray_append(array, 73);
    ByteArray_append(array, 10);
    wasmWriteVarSigned(array, -1);
    WasmModule_emitNode(this, array, Node_unaryValue(node));
  }

  else if (node->kind == 37) {
    ByteArray_append(array, 90);
    WasmModule_emitNode(this, array, Node_unaryValue(node));
  }

  else if (node->kind == 20) {
    struct Node *value = Node_castValue(node);
    struct CheckContext *context = this->context;
    struct Type *from = Type_underlyingType(value->resolvedType, context);
    struct Type *type = Type_underlyingType(node->resolvedType, context);
    int32_t fromSize = Type_variableSizeOf(from, context);
    int32_t typeSize = Type_variableSizeOf(type, context);

    if (from == type || fromSize < typeSize) {
      WasmModule_emitNode(this, array, value);
    }

    else if (type == context->sbyteType || type == context->shortType) {
      int32_t shift = 32 - (typeSize << 3);
      ByteArray_append(array, 76);
      ByteArray_append(array, 74);
      WasmModule_emitNode(this, array, value);
      ByteArray_append(array, 10);
      wasmWriteVarSigned(array, shift);
      ByteArray_append(array, 10);
      wasmWriteVarSigned(array, shift);
    }

    else if (type == context->byteType || type == context->ushortType) {
      ByteArray_append(array, 71);
      WasmModule_emitNode(this, array, value);
      ByteArray_append(array, 10);
      wasmWriteVarSigned(array, (int32_t)Type_integerBitMask(type, this->context));
    }

    else {
      WasmModule_emitNode(this, array, value);
    }
  }

  else if (node->kind == 21) {
    struct Symbol *symbol = node->symbol;

    if (symbol->kind == 9) {
      WasmModule_emitLoadFromMemory(this, array, symbol->resolvedType, Node_dotTarget(node), symbol->offset);
    }

    else {
      assert(0);
    }
  }

  else if (node->kind == 45) {
    struct Node *left = Node_binaryLeft(node);
    struct Node *right = Node_binaryRight(node);
    struct Symbol *symbol = left->symbol;

    if (left->kind == 35) {
      WasmModule_emitStoreToMemory(this, array, Type_underlyingType(left->resolvedType, this->context), Node_unaryValue(left), 0, right);
    }

    else if (symbol->kind == 9) {
      WasmModule_emitStoreToMemory(this, array, symbol->resolvedType, Node_dotTarget(left), symbol->offset, right);
    }

    else if (symbol->kind == 8) {
      WasmModule_emitStoreToMemory(this, array, symbol->resolvedType, NULL, symbol->offset + 8, right);
    }

    else if (symbol->kind == 6 || symbol->kind == 10) {
      ByteArray_append(array, 15);
      wasmWriteVarUnsigned(array, symbol->offset);
      WasmModule_emitNode(this, array, right);
    }

    else {
      assert(0);
    }
  }

  else if (node->kind == 56) {
    ByteArray_append(array, 4);
    WasmModule_emitNode(this, array, Node_binaryLeft(node));
    WasmModule_emitNode(this, array, Node_binaryRight(node));
    ByteArray_append(array, 10);
    wasmWriteVarSigned(array, 0);
  }

  else if (node->kind == 57) {
    ByteArray_append(array, 4);
    WasmModule_emitNode(this, array, Node_binaryLeft(node));
    ByteArray_append(array, 10);
    wasmWriteVarSigned(array, 1);
    WasmModule_emitNode(this, array, Node_binaryRight(node));
  }

  else {
    uint8_t isUnsigned = Node_isUnsignedOperator(node);

    if (node->kind == 44) {
      struct Node *left = Node_binaryLeft(node);
      struct Node *right = Node_binaryRight(node);
      ByteArray_append(array, 64);
      WasmModule_emitNode(this, array, left);

      if (left->resolvedType->pointerTo == NULL) {
        WasmModule_emitNode(this, array, right);
      }

      else {
        assert(Type_isInteger(right->resolvedType));
        int32_t size = Type_allocationSizeOf(left->resolvedType->pointerTo, this->context);

        if (size == 2) {
          if (right->kind == 24) {
            ByteArray_append(array, 10);
            wasmWriteVarSigned(array, right->intValue << 1);
          }

          else {
            ByteArray_append(array, 74);
            WasmModule_emitNode(this, array, right);
            ByteArray_append(array, 10);
            wasmWriteVarSigned(array, 1);
          }
        }

        else if (size == 4) {
          if (right->kind == 24) {
            ByteArray_append(array, 10);
            wasmWriteVarSigned(array, right->intValue << 2);
          }

          else {
            ByteArray_append(array, 74);
            WasmModule_emitNode(this, array, right);
            ByteArray_append(array, 10);
            wasmWriteVarSigned(array, 2);
          }
        }

        else {
          WasmModule_emitNode(this, array, right);
        }
      }
    }

    else if (node->kind == 46) {
      WasmModule_emitBinaryExpression(this, array, node, 71);
    }

    else if (node->kind == 47) {
      WasmModule_emitBinaryExpression(this, array, node, 72);
    }

    else if (node->kind == 48) {
      WasmModule_emitBinaryExpression(this, array, node, 73);
    }

    else if (node->kind == 50) {
      WasmModule_emitBinaryExpression(this, array, node, 77);
    }

    else if (node->kind == 58) {
      WasmModule_emitBinaryExpression(this, array, node, 66);
    }

    else if (node->kind == 59) {
      WasmModule_emitBinaryExpression(this, array, node, 78);
    }

    else if (node->kind == 61) {
      WasmModule_emitBinaryExpression(this, array, node, 74);
    }

    else if (node->kind == 63) {
      WasmModule_emitBinaryExpression(this, array, node, 65);
    }

    else if (node->kind == 49) {
      WasmModule_emitBinaryExpression(this, array, node, isUnsigned ? 68 : 67);
    }

    else if (node->kind == 52) {
      WasmModule_emitBinaryExpression(this, array, node, isUnsigned ? 85 : 83);
    }

    else if (node->kind == 53) {
      WasmModule_emitBinaryExpression(this, array, node, isUnsigned ? 86 : 84);
    }

    else if (node->kind == 54) {
      WasmModule_emitBinaryExpression(this, array, node, isUnsigned ? 81 : 79);
    }

    else if (node->kind == 55) {
      WasmModule_emitBinaryExpression(this, array, node, isUnsigned ? 82 : 80);
    }

    else if (node->kind == 60) {
      WasmModule_emitBinaryExpression(this, array, node, isUnsigned ? 70 : 69);
    }

    else if (node->kind == 62) {
      WasmModule_emitBinaryExpression(this, array, node, isUnsigned ? 75 : 76);
    }

    else {
      assert(0);
    }
  }

  return 1;
}

static int32_t WasmModule_getWasmType(struct WasmModule *this, struct Type *type) {
  struct CheckContext *context = this->context;

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
  int32_t offset = ByteArray_length(array);
  wasmWriteVarUnsigned(array, -1);
  wasmWriteLengthPrefixedASCII(array, name);

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
  if (node->kind == 2) {
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

static void wasmEmit(struct Node *global, struct CheckContext *context, struct ByteArray *array) {
  struct WasmModule *module = calloc(1, sizeof(struct WasmModule));
  module->context = context;
  module->memoryInitializer = calloc(1, sizeof(struct ByteArray));
  module->mallocFunctionIndex = -1;
  module->currentHeapPointer = -1;
  module->originalHeapPointer = -1;
  WasmModule_prepareToEmit(module, global);
  assert(module->mallocFunctionIndex != -1);
  assert(module->currentHeapPointer != -1);
  assert(module->originalHeapPointer != -1);
  WasmModule_emitModule(module, array);
}
