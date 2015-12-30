#ifndef TEST_MATRIX_CONFIG_H
#define TEST_MATRIX_CONFIG_H

#include "TestPin.h"
#include <cstdlib>
#include <vector>

class TestMatrix {
public:
  TestMatrix(unsigned C, unsigned R) : Columns(C), Rows(R), data() {
    data.resize(C * R);
  }
  void put(unsigned C, unsigned R, unsigned val) {
    data[C + (R * Columns)] = val;
  }
  unsigned get(unsigned C, unsigned R) const { return data[C + (R * Columns)]; }

  unsigned getNumRows() const { return Rows; }
  unsigned getNumColumns() const { return Columns; }

  void dump() const {
    for (unsigned R = 0; R < Rows; ++R) {
      for (unsigned C = 0; C < Columns; ++C) {
        printf("%d ", get(C, R));
      }
      printf("\n");
    }
  }

private:
  unsigned Columns;
  unsigned Rows;
  std::vector<unsigned> data;
};

class TestMatrixConfig {
public:
  TestMatrix createResultMatrix() const { return TestMatrix(Columns, Rows); }
  void reconfigure(unsigned R, unsigned C) {
    Rows = R;
    rowPins.clear();
    rowPins.reserve(Rows);
    srand(time(NULL));
    for (unsigned i = 0; i < Rows; ++i) {
      rowPins.push_back(TestInputPin{static_cast<unsigned>(rand()) % 2});
    }
    Columns = C;
    columnPins.clear();
    columnPins.reserve(Columns);
    for (unsigned i = 0; i < Columns; ++i) {
      columnPins.push_back(TestOutputPin{});
    }
  }

  const TestInputPin &getRowPin(unsigned R) const { return rowPins[R]; }

  const TestOutputPin &getColumnPin(unsigned C) const { return columnPins[C]; }

  unsigned getNumRows() const { return Rows; }
  unsigned getNumColumns() const { return Columns; }

private:
  unsigned Rows;
  unsigned Columns;
  std::vector<TestInputPin> rowPins;
  std::vector<TestOutputPin> columnPins;
};

#endif
