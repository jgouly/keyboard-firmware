#include "config.h"
#include "common/USBBuffer.h"

extern int app_main(const LayoutT &l, const MapT &map);

void msdelay(uint32_t ms) {}

void sendBuffer(const USBBuffer &buf) {
  const unsigned *data = buf.getData();
  for (unsigned i = 0; i < buf.size(); ++i) {
    printf("%c\n", data[i]);
  }
}

int main(void) {
  LayoutT l;
  l.reconfigure(2, 3);
  MapT m(3, 2);
  m.put(0, 0, 'a');
  m.put(0, 1, 'b');
  m.put(0, 2, 'c');
  m.put(1, 0, 'd');
  m.put(1, 1, 'e');
  m.put(1, 2, 'f');
  app_main(l, m);
  return 0;
}
