#ifndef MKL27Z_OUTPUT_PIN
#define MKL27Z_OUTPUT_PIN

#include "port.h"

class MKL27ZOutputPin {
public:
  MKL27ZOutputPin(unsigned N) : Num(N) {}
  unsigned pinToPortNum() const {
    switch (Num) {
    case 36:
      return 1;
    case 57:
      return 0;
    case 64:
      return 7;
    }
  }

  void init() const {
    switch (Num) {
    case 36:
      // PTB1 is used by the ROM bootloader, so need to clear the MUX bits.
      PORTB_PCR1 = ((PORTB_PCR1 & ~0x700) | PORT_PCR_MUX(1));
      GPIOB_PDDR |= (1 << 1);

    case 57:
      PORTD_PCR0 |= PORT_PCR_MUX(1);
      GPIOD_PDDR |= (1 << 0);

    case 64:
      PORTD_PCR7 |= PORT_PCR_MUX(1);
      GPIOD_PDDR |= (1 << 7);
      break;
    }
  }

  void outputLow() const {
    switch (Num) {
    case 36:
      GPIOB_PCOR |= (1 << pinToPortNum());
      break;
    case 57:
    case 64:
      GPIOD_PCOR |= (1 << pinToPortNum());
      break;
    }
  }

  void outputHigh() const {
    switch (Num) {
    case 36:
      GPIOB_PSOR |= (1 << pinToPortNum());
      break;
    case 57:
    case 64:
      GPIOD_PSOR |= (1 << pinToPortNum());
      break;
    }
  }

private:
  unsigned Num;
};

#endif
