#ifndef BOARD_MPAD6_CONFIG_H
#define BOARD_MPAD6_CONFIG_H

#include "common/MatrixConfig.h"
#include "mkl27z/InputPin.h"
#include "mkl27z/OutputPin.h"

#define COLUMNS 3
#define ROWS 2

using LayoutT = MatrixConfig<ROWS, COLUMNS, MKL27ZInputPin, MKL27ZOutputPin>;
using ResultT = Matrix<unsigned, ROWS, COLUMNS>;

extern const MKL27ZInputPin mkl27zRowPins[ROWS];
extern const MKL27ZOutputPin mkl27zColumnPins[COLUMNS];

#endif
