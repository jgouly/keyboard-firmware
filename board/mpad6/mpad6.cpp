#include "config.h"
#include "action/keycode.h"

const MKL27ZOutputPin mkl27zColumnPins[3] = {64, 57, 36};
const MKL27ZInputPin mkl27zRowPins[2] = {12, 54};

KEYMAP({
  KEY_A, KEY_B, KEY_C,
  KEY_D, KEY_E, KEY_F
})
