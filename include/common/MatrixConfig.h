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
  const PinIT &getRowPin(unsigned R) const { return inputPins[R]; }

  const PinOT &getColumnPin(unsigned C) const { return outputPins[C]; }

  unsigned getNumRows() const { return Rows; }
  unsigned getNumColumns() const { return Columns; }

private:
  const PinIT (&inputPins)[Rows];
  const PinOT (&outputPins)[Columns];
};

#endif
