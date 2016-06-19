#ifndef MKL27Z_OUTPUT_PIN
#define MKL27Z_OUTPUT_PIN

#include "port.h"

class MKL27ZOutputPin {
public:
  MKL27ZOutputPin(unsigned PortNum, volatile uint32_t *const PSOR,
                  volatile uint32_t *const PCOR, volatile uint32_t *const PDDR,
                  volatile uint32_t *const PORT)
      : PortNum(PortNum), PSOR(PSOR), PCOR(PCOR), PDDR(PDDR), PORT(PORT) {}

  void init() const {
    *PORT = ((*PORT & ~0x700)) | PORT_PCR_MUX(1);
    *PDDR |= (1 << PortNum);
  }

  void outputLow() const { *PCOR |= (1 << PortNum); }

  void outputHigh() const { *PSOR |= (1 << PortNum); }

private:
  unsigned PortNum;
  volatile uint32_t *const PSOR;
  volatile uint32_t *const PCOR;
  volatile uint32_t *const PDDR;
  volatile uint32_t *const PORT;
};

#define P17                                                                    \
  {                                                                            \
    29, (volatile uint32_t *)0x400FF104, (volatile uint32_t *)0x400FF108,      \
        (volatile uint32_t *)0x400FF114, (volatile uint32_t *)0x4004D074       \
  }
#define P18                                                                    \
  {                                                                            \
    30, (volatile uint32_t *)0x400FF104, (volatile uint32_t *)0x400FF108,      \
        (volatile uint32_t *)0x400FF114, (volatile uint32_t *)0x4004D078       \
  }
#define P19                                                                    \
  {                                                                            \
    31, (volatile uint32_t *)0x400FF104, (volatile uint32_t *)0x400FF108,      \
        (volatile uint32_t *)0x400FF114, (volatile uint32_t *)0x4004D07C       \
  }
#define P20                                                                    \
  {                                                                            \
    24, (volatile uint32_t *)0x400FF104, (volatile uint32_t *)0x400FF108,      \
        (volatile uint32_t *)0x400FF114, (volatile uint32_t *)0x4004D060       \
  }
#define P21                                                                    \
  {                                                                            \
    25, (volatile uint32_t *)0x400FF104, (volatile uint32_t *)0x400FF108,      \
        (volatile uint32_t *)0x400FF114, (volatile uint32_t *)0x4004D064       \
  }

#define P36                                                                    \
  {                                                                            \
    1, (volatile uint32_t *)0x400FF044, (volatile uint32_t *)0x400FF048,       \
        (volatile uint32_t *)0x400FF054, (volatile uint32_t *)0x4004A004       \
  }
#define P38                                                                    \
  {                                                                            \
    3, (volatile uint32_t *)0x400FF044, (volatile uint32_t *)0x400FF048,       \
        (volatile uint32_t *)0x400FF054, (volatile uint32_t *)0x4004A00C       \
  }
#define P39                                                                    \
  {                                                                            \
    16, (volatile uint32_t *)0x400FF044, (volatile uint32_t *)0x400FF048,      \
        (volatile uint32_t *)0x400FF054, (volatile uint32_t *)0x4004A040       \
  }
#define P40                                                                    \
  {                                                                            \
    17, (volatile uint32_t *)0x400FF044, (volatile uint32_t *)0x400FF048,      \
        (volatile uint32_t *)0x400FF054, (volatile uint32_t *)0x4004A044       \
  }
#define P41                                                                    \
  {                                                                            \
    18, (volatile uint32_t *)0x400FF044, (volatile uint32_t *)0x400FF048,      \
        (volatile uint32_t *)0x400FF054, (volatile uint32_t *)0x4004A048       \
  }
#define P42                                                                    \
  {                                                                            \
    19, (volatile uint32_t *)0x400FF044, (volatile uint32_t *)0x400FF048,      \
        (volatile uint32_t *)0x400FF054, (volatile uint32_t *)0x4004A04C       \
  }

#define P43                                                                    \
  {                                                                            \
    0, (volatile uint32_t *)0x400FF084, (volatile uint32_t *)0x400FF088,       \
        (volatile uint32_t *)0x400FF094, (volatile uint32_t *)0x4004B000       \
  }
#define P44                                                                    \
  {                                                                            \
    1, (volatile uint32_t *)0x400FF084, (volatile uint32_t *)0x400FF088,       \
        (volatile uint32_t *)0x400FF094, (volatile uint32_t *)0x4004B004       \
  }
#define P45                                                                    \
  {                                                                            \
    2, (volatile uint32_t *)0x400FF084, (volatile uint32_t *)0x400FF088,       \
        (volatile uint32_t *)0x400FF094, (volatile uint32_t *)0x4004B008       \
  }

#define P57                                                                    \
  {                                                                            \
    0, (volatile uint32_t *)0x400FF0C4, (volatile uint32_t *)0x400FF0C8,       \
        (volatile uint32_t *)0x400FF0D4, (volatile uint32_t *)0x4004C000       \
  }
#define P62                                                                    \
  {                                                                            \
    5, (volatile uint32_t *)0x400FF0C4, (volatile uint32_t *)0x400FF0C8,       \
        (volatile uint32_t *)0x400FF0D4, (volatile uint32_t *)0x4004C014       \
  }
#define P63                                                                    \
  {                                                                            \
    6, (volatile uint32_t *)0x400FF0C4, (volatile uint32_t *)0x400FF0C8,       \
        (volatile uint32_t *)0x400FF0D4, (volatile uint32_t *)0x4004C018       \
  }
#define P64                                                                    \
  {                                                                            \
    7, (volatile uint32_t *)0x400FF0C4, (volatile uint32_t *)0x400FF0C8,       \
        (volatile uint32_t *)0x400FF0D4, (volatile uint32_t *)0x4004C01C       \
  }

#endif
