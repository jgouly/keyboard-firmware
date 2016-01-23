#include "config.h"
#include "action/keycode.h"

const MKL27ZOutputPin mkl27zColumnPins[3] = {64, 57, 36};
const MKL27ZInputPin mkl27zRowPins[2] = {12, 54};

const MapT mkl27zMap{KEY('a'), KEY('b'), KEY('c'),
                     KEY('d'), KEY('e'), KEY('f')};
