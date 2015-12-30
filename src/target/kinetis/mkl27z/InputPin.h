#ifndef MKL27Z_INPUT_PIN
#define MKL27Z_INPUT_PIN

#include "port.h"
typedef unsigned int uint32_t;
#define p_addr32(addr) (*(volatile uint32_t *)addr)

class MKL27ZInputPin {
public:
  MKL27ZInputPin(unsigned N) : Num(N) {}

  void init() const {
    switch (Num) {
    case 12:
      PORTE_PCR23 |= PORT_PCR_MUX(1) | PORT_PCR_PE;
      PORTE_PCR23 &= ~PORT_PCR_PS;
      GPIOE_PDDR &= ~(1 << 23);
      break;
    case 54:
      PORTC_PCR9 |= PORT_PCR_MUX(1) | PORT_PCR_PE;
      PORTC_PCR9 &= ~PORT_PCR_PS;
      GPIOC_PDDR &= ~(1 << 9);
      break;
    }
  }

  unsigned pinToPortNum() const {
    switch (Num) {
    case 12:
      return 23;
    case 54:
      return 9;
    }
  }

  unsigned readInput() const {
    switch (Num) {
    case 12:
      return (GPIOE_PDIR & (1 << pinToPortNum()) ? 1 : 0);
      break;
    case 54:
      return (GPIOC_PDIR & (1 << pinToPortNum()) ? 1 : 0);
      break;
    }
  }

private:
  unsigned Num;
};

#endif
