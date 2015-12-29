#include "action/action.h"
#include "scan/scan.h"

int app_main(const LayoutT &l) {
  while (1) {
    ResultT result = scan(l);
    processKeys(result);
  }
  __builtin_unreachable();
}
