#include "config.h"
#include "action/keycode.h"

const MKL27ZOutputPin mkl27zColumnPins[3] = {P64, P57, P36};
const MKL27ZInputPin mkl27zRowPins[2] = {12, 54};

KEYMAP({
  KEY_A, KEY_B, KEY_C,
  KEY_D, KEY_E, KEY_F
})
