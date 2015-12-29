#include "scan/scan.h"

ResultT scan(LayoutT l) {
  ResultT result = l.createResultMatrix();
  for (unsigned C = 0; C < l.getNumColumns(); ++C) {
    const auto &columnPin = l.getColumnPin(C);
    columnPin.outputHigh();
    for (unsigned R = 0; R < l.getNumRows(); ++R) {
      const auto &rowPin = l.getRowPin(R);
      unsigned val = rowPin.readInput();
      result.put(C, R, val);
    }
    columnPin.outputLow();
  }
  return result;
}
