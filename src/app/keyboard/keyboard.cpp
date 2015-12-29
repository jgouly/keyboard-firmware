#include "action/action.h"
#include "scan/scan.h"

int app_main(const LayoutT &l, const MapT &map) {
  while (1) {
    ResultT result = scan(l);
    processKeys(result, map);
  }
  __builtin_unreachable();
}
