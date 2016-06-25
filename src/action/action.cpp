#include "action/action.h"
#include "action/keycode.h"

static unsigned msb(unsigned int v) {
  return v == 0 ? 0 : 32 - __builtin_clz(v);
}

static void handleKey(USBBuffer &buf, unsigned action) {
  buf.push_back(GET_KEY(action));
}

static void handleMod(USBBuffer &buf, unsigned action) {
  buf.push_mod(GET_MOD(action));
}

static void handleLayer(unsigned action, const KeyState state,
                        unsigned char &activeLayers) {
  if (state == KeyState::PRESSED)
    activeLayers |= (1 << (GET_LAYER(action) - 1));
  else if (state == KeyState::RELEASED)
    activeLayers &= ~(1 << (GET_LAYER(action) - 1));
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
        unsigned actionBit = ACTION_BITS & action;
        switch (actionBit) {
        case KEY_BIT:
          handleKey(buf, action);
          break;
        case MOD_BIT:
          handleMod(buf, action);
          break;
        case LAYER_BIT:
          handleLayer(action, state, activeLayers);
          break;
        }
      }
    }
  }
}
