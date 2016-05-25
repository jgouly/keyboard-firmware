#include "action/action.h"
#include "action/keycode.h"

void processKeys(const ResultT &result, const MapT &map, USBBuffer &buf,
                 const ResultT &prevResult) {
  for (unsigned C = 0; C < result.getNumColumns(); ++C) {
    for (unsigned R = 0; R < result.getNumRows(); ++R) {
      if (result.get(C, R)) {
        unsigned action = map[0].get(C, R);
        if (IS_KEY(action)) {
          buf.push_back(GET_KEY(action));
        } else if (IS_MOD(action)) {
          buf.push_mod(GET_MOD(action));
        }
      }
    }
  }
}
