#include "action/action.h"
#include "scan/scan.h"

static void init_matrix(const LayoutT &l) {
  for (unsigned R = 0; R < l.getNumRows(); ++R) {
    auto &rowPin = l.getRowPin(R);
    rowPin.init();
  }
  for (unsigned C = 0; C < l.getNumColumns(); ++C) {
    auto &colPin = l.getColumnPin(C);
    colPin.init();
  }
}

int app_main(const LayoutT &l, const MapT &map) {
  init_matrix(l);
  while (1) {
    ResultT result = scan(l);
    processKeys(result, map);
  }
  __builtin_unreachable();
}
