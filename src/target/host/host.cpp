#include "config.h"

extern int app_main(const LayoutT &);

int main(void) {
  LayoutT m;
  m.reconfigure(2, 3);
  app_main(m);
  return 0;
}
