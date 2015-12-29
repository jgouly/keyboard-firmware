#ifndef COMMON_MATRIX_H
#define COMMON_MATRIX_H

int putchar(int c);

template <typename T, int Rows, int Columns> class Matrix {
public:
  void put(unsigned C, unsigned R, T val) {
    data[C + (R * Columns)] = val;
  }

  T get(unsigned C, unsigned R) const { return data[C + (R * Columns)]; }

  void dump() const {
    for (unsigned c = 0; c < Columns; ++c) {
      for (unsigned r = 0; r < Rows; ++r) {
        putchar('0' + data[c + (r * Columns)]);
        putchar(' ');
      }
      putchar('\r');
      putchar('\n');
    }
  }

  unsigned getNumRows() const { return Rows; }
  unsigned getNumColumns() const { return Columns; }

  T data[Rows * Columns];
};

#endif
