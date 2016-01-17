#ifndef BOARD_MPAD6_CONFIG_H
#define BOARD_MPAD6_CONFIG_H

#include "common/MatrixConfig.h"
#include "mkl27z/InputPin.h"
#include "mkl27z/OutputPin.h"

#define COLUMNS 15
#define ROWS 5

using LayoutT = MatrixConfig<ROWS, COLUMNS, MKL27ZInputPin, MKL27ZOutputPin>;
using ResultT = Matrix<unsigned, ROWS, COLUMNS>;
using MapT = Matrix<unsigned, ROWS, COLUMNS>;

extern const MKL27ZInputPin mkl27zRowPins[ROWS];
extern const MKL27ZOutputPin mkl27zColumnPins[COLUMNS];

extern const MapT mkl27zMap;

#endif
