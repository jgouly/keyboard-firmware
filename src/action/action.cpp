#include "action/action.h"

void processKeys(const ResultT &result, const MapT &map) {
  for (unsigned C = 0; C < result.getNumColumns(); ++C) {
    for (unsigned R = 0; R < result.getNumRows(); ++R) {
      if (result.get(C, R)) {
        putchar(map.get(C, R));
      }
    }
  }
}
