#ifndef ACTION_KEYCODE_H
#define ACTION_KEYCODE_H

#define KEY_BIT (1 << 9)
#define KEY(K) (K | KEY_BIT)
#define IS_KEY(K) (K & KEY_BIT)
#define GET_KEY(K) (K & ~KEY_BIT)

#define MOD_BIT (1 << 10)
#define MOD(M) (M | MOD_BIT)
#define IS_MOD(M) (M & MOD_BIT)
#define GET_MOD(M) (M & ~MOD_BIT)

#define LAYER_BIT (1 << 11)
#define TOGGLE_LAYER(L) (L | LAYER_BIT)
#define IS_LAYER(L) (L & LAYER_BIT)
#define GET_LAYER(L) (L & ~LAYER_BIT)

enum USBKeyCode {
  KEY_NONE = 0,

  KEY_A = KEY(4),
  KEY_B = KEY(5),
  KEY_C = KEY(6),
  KEY_D = KEY(7),
  KEY_E = KEY(8),
  KEY_F = KEY(9),
  KEY_G = KEY(10),
  KEY_H = KEY(11),
  KEY_I = KEY(12),
  KEY_J = KEY(13),
  KEY_K = KEY(14),
  KEY_L = KEY(15),
  KEY_M = KEY(16),
  KEY_N = KEY(17),
  KEY_O = KEY(18),
  KEY_P = KEY(19),
  KEY_Q = KEY(20),
  KEY_R = KEY(21),
  KEY_S = KEY(22),
  KEY_T = KEY(23),
  KEY_U = KEY(24),
  KEY_V = KEY(25),
  KEY_W = KEY(26),
  KEY_X = KEY(27),
  KEY_Y = KEY(28),
  KEY_Z = KEY(29),

  KEY_1 = KEY(30),
  KEY_2 = KEY(31),
  KEY_3 = KEY(32),
  KEY_4 = KEY(33),
  KEY_5 = KEY(34),
  KEY_6 = KEY(35),
  KEY_7 = KEY(36),
  KEY_8 = KEY(37),
  KEY_9 = KEY(38),
  KEY_0 = KEY(39),

  KEY_ENTER = KEY(40),
  KEY_ESC = KEY(41),
  KEY_BACKSPACE = KEY(42),
  KEY_TAB = KEY(43),
  KEY_SPACE = KEY(44),
  KEY_MINUS = KEY(45),
  KEY_EQUALS = KEY(46),
  KEY_LBRACE = KEY(47),
  KEY_RBRACE = KEY(48),
  KEY_BACKSLASH = KEY(49),
  KEY_SEMICOLON = KEY(51),
  KEY_QUOTE = KEY(52),
  KEY_TILDE = KEY(53),
  KEY_COMMA = KEY(54),
  KEY_PERIOD = KEY(55),
  KEY_SLASH = KEY(56),
  KEY_CAPS_LOCK = KEY(57),

  KEY_RIGHT = KEY(79),
  KEY_LEFT = KEY(80),
  KEY_DOWN = KEY(81),
  KEY_UP = KEY(82),
};

#endif
