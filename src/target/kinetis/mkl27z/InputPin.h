#ifndef MKL27Z_INPUT_PIN
#define MKL27Z_INPUT_PIN

#include "port.h"
typedef unsigned int uint32_t;
#define p_addr32(addr) (*(volatile uint32_t *)addr)

class MKL27ZInputPin {
public:
  MKL27ZInputPin(unsigned PortNum, volatile uint32_t *const PORT,
                 volatile uint32_t *const PDDR, volatile uint32_t *const PDIR)
      : PortNum(PortNum), PORT(PORT), PDDR(PDDR), PDIR(PDIR) {}

  void init() const {
    *PORT |= PORT_PCR_MUX(1) | PORT_PCR_PE;
    *PORT &= ~PORT_PCR_PS;
    *PDDR &= ~(1 << PortNum);
  }

  unsigned readInput() const { return ((*PDIR & (1 << PortNum)) ? 1 : 0); }

private:
  unsigned PortNum;
  volatile uint32_t *const PORT;
  volatile uint32_t *const PDDR;
  volatile uint32_t *const PDIR;
};

#define PI12                                                                   \
  {                                                                            \
    23, (volatile uint32_t *)0x4004D05C, (volatile uint32_t *)0x400FF114,      \
        (volatile uint32_t *)0x400FF110                                        \
  }

#define PI33                                                                   \
  {                                                                            \
    19, (volatile uint32_t *)0x4004904C, (volatile uint32_t *)0x400FF014,      \
        (volatile uint32_t *)0x400FF010                                        \
  }

#define PI35                                                                   \
  {                                                                            \
    0, (volatile uint32_t *)0x4004A000, (volatile uint32_t *)0x400FF054,       \
        (volatile uint32_t *)0x400FF050                                        \
  }
#define PI36                                                                   \
  {                                                                            \
    1, (volatile uint32_t *)0x4004A004, (volatile uint32_t *)0x400FF054,       \
        (volatile uint32_t *)0x400FF050                                        \
  }
#define PI37                                                                   \
  {                                                                            \
    2, (volatile uint32_t *)0x4004A008, (volatile uint32_t *)0x400FF054,       \
        (volatile uint32_t *)0x400FF050                                        \
  }

#define PI49                                                                   \
  {                                                                            \
    4, (volatile uint32_t *)0x4004B010, (volatile uint32_t *)0x400FF094,       \
        (volatile uint32_t *)0x400FF090                                        \
  }
#define PI54                                                                   \
  {                                                                            \
    9, (volatile uint32_t *)0x4004B024, (volatile uint32_t *)0x400FF094,       \
        (volatile uint32_t *)0x400FF090                                        \
  }

#endif
