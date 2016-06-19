#include "config.h"
#include "action/keycode.h"

#define p_addr32(x) (volatile uint32_t *const)x

const MKL27ZOutputPin mkl27zColumnPins[] = {P62, P63, P64, P19, P18, P21, P20, P44, P43, P42, P41, P40, P39, P38, P45};
const MKL27ZInputPin mkl27zRowPins[] = {PI33, PI35, PI36, PI37, PI49};

KEYMAP({
{ 
  KEY_ESC, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_MINUS, KEY_EQUALS, KEY_BACKSLASH, KEY_TILDE,
  KEY_TAB, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_LBRACE, KEY_RBRACE, KEY_BACKSPACE, KEY_NONE,
  KEY_CAPS_LOCK, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, KEY_QUOTE, KEY_ENTER, KEY_ENTER, KEY_NONE,
  MOD(0x2), MOD(0x2), KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, MOD(0x20), TOGGLE_LAYER(1), KEY_NONE,
  MOD(0x1), MOD(0x8), MOD(0x4), KEY_NONE, KEY_NONE, KEY_NONE, KEY_SPACE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, MOD(0x40), MOD(0x80), MOD(0x10), KEY_NONE,
},
{ 
  KEY_ESC, KEY_2, KEY_3, KEY_4, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_MINUS, KEY_EQUALS, KEY_BACKSLASH, KEY_TILDE,
  KEY_TAB, KEY_Q, KEY_W, KEY_UP, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_LBRACE, KEY_RBRACE, KEY_BACKSPACE, KEY_NONE,
  KEY_CAPS_LOCK, KEY_A, KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, KEY_QUOTE, KEY_ENTER, KEY_ENTER, KEY_NONE,
  MOD(0x2), MOD(0x2), KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, MOD(0x20), TOGGLE_LAYER(1), KEY_NONE,
  MOD(0x1), MOD(0x8), MOD(0x4), KEY_NONE, KEY_NONE, KEY_NONE, KEY_SPACE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, MOD(0x40), MOD(0x80), MOD(0x10), KEY_NONE,
}
});
