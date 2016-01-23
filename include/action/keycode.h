#ifndef ACTION_KEYCODE_H
#define ACTION_KEYCODE_H

#define KEY_BIT (1 << 9)
#define KEY(K) (K | KEY_BIT)
#define IS_KEY(K) (K & KEY_BIT)
#define GET_KEY(K) (K & ~KEY_BIT)

#endif
