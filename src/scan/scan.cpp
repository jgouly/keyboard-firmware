#include "scan/scan.h"
void msdelay(unsigned int ms);

constexpr unsigned PIN_CLEAR_DELAY_MS = 1;
static ResultT singleScan(LayoutT l) {
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
    msdelay(PIN_CLEAR_DELAY_MS);
  }
  return result;
}

constexpr unsigned DEBOUNCE_MS = 4;

ResultT scan(LayoutT l) {
  ResultT r0 = singleScan(l);
  msdelay(DEBOUNCE_MS);
  ResultT r1 = singleScan(l);
  ResultT result = l.createResultMatrix();
  for (unsigned C = 0; C < l.getNumColumns(); ++C) {
    for (unsigned R = 0; R < l.getNumRows(); ++R) {
      result.put(C, R, r0.get(C, R) & r1.get(C, R));
    }
  }
  return result;
}
