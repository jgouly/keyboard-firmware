#include "scan/scan.h"

int app_main(const LayoutT &l) {
  while (1) {
    ResultT res = scan(l);
    res.dump();
  }
  __builtin_unreachable();
}
