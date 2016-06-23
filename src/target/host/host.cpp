#include "config.h"
#include "action/keycode.h"
#include "action/map.h"
#include "common/USBBuffer.h"

extern int app_main(const LayoutT &l, const MapT &map);

void msdelay(uint32_t ms) {}

void sendBuffer(const USBBuffer &buf) {
  const unsigned *data = buf.getData();
  for (unsigned i = 0; i < buf.size(); ++i) {
    printf("%c\n", data[i]);
  }
}

extern KeyFn KEY_A1;
extern KeyFn KEY_B1;
extern KeyFn KEY_C1;
extern KeyFn KEY_D1;
extern KeyFn KEY_E1;
extern KeyFn KEY_F1;
extern LayerKey L1;

int main(void) {
  LayoutT l;
  l.reconfigure(2, 3);
  MapT m(2, 3);
  m.put(0, 0, static_cast<KeyBase*>(&L1));
  m.put(0, 1, &KEY_B1);
  m.put(0, 2, &KEY_C1);
  m.put(1, 0, &KEY_D1);
  m.put(1, 1, &KEY_E1);
  m.put(1, 2, &KEY_F1);
  app_main(l, m);
  return 0;
}
