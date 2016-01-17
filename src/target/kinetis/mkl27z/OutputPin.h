#ifndef MKL27Z_OUTPUT_PIN
#define MKL27Z_OUTPUT_PIN

#include "port.h"

class MKL27ZOutputPin {
public:
  MKL27ZOutputPin(unsigned N) : Num(N) {}
  unsigned pinToPortNum() const {
    switch (Num) {
    case 18:
      return 30;
    case 19:
      return 31;
    case 20:
      return 24;
    case 21:
      return 25;
    case 36:
      return 1;

    case 38:
      return 3;
    case 39:
      return 16;
    case 40:
      return 17;
    case 41:
      return 18;
    case 42:
      return 19;
    case 43:
      return 0;
    case 44:
      return 1;


    case 45:
      return 2;
    case 57:
      return 0;
    case 62:
      return 5;
    case 63:
      return 6;
    case 64:
      return 7;
    }
  }

  void init() const {
    switch (Num) {
    case 18:
      PORTE_PCR30 |= PORT_PCR_MUX(1);
      GPIOE_PDDR |= (1 << 30);
      break;
    case 19:
      PORTE_PCR31 |= PORT_PCR_MUX(1);
      GPIOE_PDDR |= (1 << 31);
      break;
    case 20:
      PORTE_PCR24 |= PORT_PCR_MUX(1);
      GPIOE_PDDR |= (1 << 24);
      break;
    case 21:
      PORTE_PCR25 |= PORT_PCR_MUX(1);
      GPIOE_PDDR |= (1 << 25);
      break;
    case 36:
      // PTB1 is used by the ROM bootloader, so need to clear the MUX bits.
      PORTB_PCR1 = ((PORTB_PCR1 & ~0x700) | PORT_PCR_MUX(1));
      GPIOB_PDDR |= (1 << 1);
      break;

    case 38:
      PORTB_PCR3 |= PORT_PCR_MUX(1);
      GPIOB_PDDR |= (1 << 3);
      break;
    case 39:
      PORTB_PCR16 |= PORT_PCR_MUX(1);
      GPIOB_PDDR |= (1 << 16);
      break;
    case 40:
      PORTB_PCR17 |= PORT_PCR_MUX(1);
      GPIOB_PDDR |= (1 << 17);
      break;
    case 41:
      PORTB_PCR18 |= PORT_PCR_MUX(1);
      GPIOB_PDDR |= (1 << 18);
      break;
    case 42:
      PORTB_PCR19 |= PORT_PCR_MUX(1);
      GPIOB_PDDR |= (1 << 19);
      break;
    case 43:
      PORTC_PCR0 |= PORT_PCR_MUX(1);
      GPIOC_PDDR |= (1 << 0);
      break;
    case 44:
      PORTC_PCR1 |= PORT_PCR_MUX(1);
      GPIOC_PDDR |= (1 << 1);
      break;

    case 45:
      PORTC_PCR2 |= PORT_PCR_MUX(1);
      GPIOC_PDDR |= (1 << 2);
      break;

    case 57:
      PORTD_PCR0 |= PORT_PCR_MUX(1);
      GPIOD_PDDR |= (1 << 0);
      break;

    case 62:
      PORTD_PCR5 |= PORT_PCR_MUX(1);
      GPIOD_PDDR |= (1 << 5);
      break;
    case 63:
      PORTD_PCR6 |= PORT_PCR_MUX(1);
      GPIOD_PDDR |= (1 << 6);
      break;

    case 64:
      PORTD_PCR7 |= PORT_PCR_MUX(1);
      GPIOD_PDDR |= (1 << 7);
      break;
    }
  }

  void outputLow() const {
    switch (Num) {
    case 18:
    case 19:
    case 20:
    case 21:
      GPIOE_PCOR |= (1 << pinToPortNum());
      break;

    case 36:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
      GPIOB_PCOR |= (1 << pinToPortNum());
      break;
    case 43:
    case 44:
    case 45:
      GPIOC_PCOR |= (1 << pinToPortNum());
      break;
    case 57:
    case 62:
    case 63:
    case 64:
      GPIOD_PCOR |= (1 << pinToPortNum());
      break;
    }
  }

  void outputHigh() const {
    switch (Num) {
    case 18:
    case 19:
    case 20:
    case 21:
      GPIOE_PSOR |= (1 << pinToPortNum());
      break;
    case 36:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
      GPIOB_PSOR |= (1 << pinToPortNum());
      break;

    case 43:
    case 44:
    case 45:
      GPIOC_PSOR |= (1 << pinToPortNum());
      break;
    case 57:
    case 62:
    case 63:
    case 64:
      GPIOD_PSOR |= (1 << pinToPortNum());
      break;
    }
  }

private:
  unsigned Num;
};

#endif
