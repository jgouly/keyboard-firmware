#ifndef COMMON_MATRIX_CONFIG_H
#define COMMON_MATRIX_CONFIG_H

#include "common/matrix.h"

template <unsigned Rows, unsigned Columns, class PinIT, class PinOT>
class MatrixConfig {
public:
  MatrixConfig(const PinIT (&ip)[Rows], const PinOT (&pp)[Columns])
      : inputPins{ip}, outputPins{pp} {}
  Matrix<unsigned, Rows, Columns> createResultMatrix() const {
    return Matrix<unsigned, Rows, Columns>();
  }
  PinIT getRowPin(unsigned R) { return inputPins[R]; }

  PinOT getColumnPin(unsigned C) { return outputPins[C]; }

  unsigned getNumRows() const { return Rows; }
  unsigned getNumColumns() const { return Columns; }

private:
  const PinIT (&inputPins)[Rows];
  const PinOT (&outputPins)[Columns];
};

#endif
