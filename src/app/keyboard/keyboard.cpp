#include "action/action.h"
#include "scan/scan.h"

static void initMatrixPins(const LayoutT &l) {
  for (unsigned R = 0; R < l.getNumRows(); ++R) {
    auto &rowPin = l.getRowPin(R);
    rowPin.init();
  }
  for (unsigned C = 0; C < l.getNumColumns(); ++C) {
    auto &colPin = l.getColumnPin(C);
    colPin.init();
  }
}

void sendBuffer(const USBBuffer &buf);

int app_main(const LayoutT &l, const MapT &map) {
  initMatrixPins(l);
  ResultT prevResult = l.createResultMatrix();
  unsigned char activeLayers = 0;
  while (1) {
    USBBuffer buffer;
    ResultT result = scan(l);
    processKeys(result, map, buffer, prevResult, activeLayers);
    sendBuffer(buffer);
    prevResult = result;
  }
  __builtin_unreachable();
}
