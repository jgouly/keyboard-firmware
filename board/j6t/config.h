#ifndef BOARD_MPAD6_CONFIG_H
#define BOARD_MPAD6_CONFIG_H

#include "common/MatrixConfig.h"
#include "mkl27z/InputPin.h"
#include "mkl27z/OutputPin.h"

constexpr unsigned COLUMNS = 15;
constexpr unsigned ROWS = 5;

constexpr unsigned DEBUG_LED = 17;

using LayoutT = MatrixConfig<ROWS, COLUMNS, MKL27ZInputPin, MKL27ZOutputPin>;
using ResultT = Matrix<unsigned, ROWS, COLUMNS>;
using LayerT = Matrix<unsigned, ROWS, COLUMNS>;
using MapT = const LayerT *;

extern const MKL27ZInputPin mkl27zRowPins[ROWS];
extern const MKL27ZOutputPin mkl27zColumnPins[COLUMNS];

#define KEYMAP(...)                                                            \
  static const LayerT layers[] = __VA_ARGS__;                                  \
  const MapT mkl27zMap{layers};

extern const MapT mkl27zMap;

#endif
