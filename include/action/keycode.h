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

#endif
