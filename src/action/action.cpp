#include "action/action.h"
#include "action/keycode.h"

static unsigned msb(unsigned int v) {
  return v == 0 ? 0 : 32 - __builtin_clz(v);
}

void processKeys(const ResultT &result, const MapT &map, USBBuffer &buf,
                 const ResultT &prevResult, unsigned char &activeLayers) {
  for (unsigned C = 0; C < result.getNumColumns(); ++C) {
    for (unsigned R = 0; R < result.getNumRows(); ++R) {
      KeyState state = KeyState::NONE;
      if (result.get(C, R)) {
        if (prevResult.get(C, R)) {
          state = KeyState::HELD;
        } else {
          state = KeyState::PRESSED;
        }
      } else {
        if (prevResult.get(C, R)) {
          state = KeyState::RELEASED;
        }
      }
      if (state != KeyState::NONE) {
        unsigned action = map[msb(activeLayers)].get(C, R);
        if (IS_KEY(action)) {
          buf.push_back(GET_KEY(action));
        } else if (IS_MOD(action)) {
          buf.push_mod(GET_MOD(action));
        } else if (IS_LAYER(action)) {
          if (state == KeyState::PRESSED)
            activeLayers |= (1 << (GET_LAYER(action) - 1));
          else if (state == KeyState::RELEASED)
            activeLayers &= ~(1 << (GET_LAYER(action) - 1));
        }
      }
    }
  }
}
