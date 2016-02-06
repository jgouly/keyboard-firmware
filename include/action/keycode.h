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

enum USBKeyCode {
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
  KEY_Z = KEY(29)
};

#endif
