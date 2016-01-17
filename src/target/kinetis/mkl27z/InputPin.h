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

    case 33:
      PORTA_PCR19 |= PORT_PCR_MUX(1) | (1 << 1);
      PORTA_PCR19 &= ~(1 << 0);
      GPIOA_PDDR &= ~(1 << 19);
      break;
    case 35:
      PORTB_PCR0 |= PORT_PCR_MUX(1) | (1 << 1);
      PORTB_PCR0 &= ~(1 << 0);
      GPIOB_PDDR &= ~(1 << 0);
      break;
    case 36:
      PORTB_PCR1 |= PORT_PCR_MUX(1) | (1 << 1);
      PORTB_PCR1 &= ~(1 << 0);
      GPIOB_PDDR &= ~(1 << 1);
      break;
    case 37:
      PORTB_PCR2 |= PORT_PCR_MUX(1) | (1 << 1);
      PORTB_PCR2 &= ~(1 << 0);
      GPIOB_PDDR &= ~(1 << 2);
      break;
    case 49:
      PORTC_PCR4 |= PORT_PCR_MUX(1) | (1 << 1);
      PORTC_PCR4 &= ~(1 << 0);
      GPIOC_PDDR &= ~(1 << 4);
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
    case 33:
      return 19;
    case 35:
      return 0;
    case 36:
      return 1;
    case 37:
      return 2;
    case 49:
      return 4;
    case 54:
      return 9;
    }
  }

  unsigned readInput() const {
    switch (Num) {
    case 12:
      return (GPIOE_PDIR & (1 << pinToPortNum()) ? 1 : 0);
      break;
    case 33:
      return (GPIOA_PDIR & (1 << pinToPortNum()) ? 1 : 0);
      break;
    case 35:
    case 36:
    case 37:
      return (GPIOB_PDIR & (1 << pinToPortNum()) ? 1 : 0);
      break;
    case 49:
    case 54:
      return (GPIOC_PDIR & (1 << pinToPortNum()) ? 1 : 0);
      break;
    }
  }

private:
  unsigned Num;
};

#endif
