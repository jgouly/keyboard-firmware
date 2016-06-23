#include "action/action.h"
//#include <iostream>
#include "action/keycode.h"
#include "action/map.h"

static unsigned msb(unsigned int v) {
  return v == 0 ? 0 : 32 - __builtin_clz(v);
}

template< class T > struct remove_reference      {typedef T type;};
template< class T > struct remove_reference<T&>  {typedef T type;};
template< class T > struct remove_reference<T&&> {typedef T type;}; 

KeyFn KEY_A1(GET_KEY(KEY_A));
KeyFn KEY_B1('b');
KeyFn KEY_C1('c');
KeyFn KEY_D1('d');
KeyFn KEY_E1('e');
KeyFn KEY_F1('f');
LayerKey L1(1);

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
        //remove_reference<decltype(map[0])>::type::value_type action = map[msb(activeLayers)].get(C, R);
        auto action = map[msb(activeLayers)].get(C, R);
        (*action)(buf, activeLayers, state);
#if 0
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
#endif
      }
    }
  }
}
