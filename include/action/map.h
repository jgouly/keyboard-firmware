#include "action/action.h"
#include "common/USBBuffer.h"

class KeyBase {
public:
  virtual void operator()(USBBuffer &, unsigned char &, KeyState) = 0;
};

class KeyFn : public KeyBase {
public:
  KeyFn(char k) : KeyBase(), k(k) {}
  virtual void operator()(USBBuffer &buf, unsigned char &, KeyState) {
    buf.push_back(k);
  }
  char k;
};
class LayerKey : public KeyBase {
public:
  LayerKey(unsigned n) : KeyBase(), n(n) {}
  virtual void operator()(USBBuffer &, unsigned char &activeLayers,
                          KeyState state) {
    if (state == KeyState::PRESSED)
      activeLayers |= (1 << (n - 1));
    else if (state == KeyState::RELEASED)
      activeLayers &= ~(1 << (n - 1));
  }
  unsigned n;
};

