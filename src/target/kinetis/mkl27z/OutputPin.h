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
  { 29, GPIOE_PSOR, GPIOE_PCOR, GPIOE_PDDR, PORTE_PCR29 }
#define P18                                                                    \
  { 30, GPIOE_PSOR, GPIOE_PCOR, GPIOE_PDDR, PORTE_PCR30 }
#define P19                                                                    \
  { 31, GPIOE_PSOR, GPIOE_PCOR, GPIOE_PDDR, PORTE_PCR31 }
#define P20                                                                    \
  { 24, GPIOE_PSOR, GPIOE_PCOR, GPIOE_PDDR, PORTE_PCR24 }
#define P21                                                                    \
  { 25, GPIOE_PSOR, GPIOE_PCOR, GPIOE_PDDR, PORTE_PCR25 }

#define P36                                                                    \
  { 1, GPIOB_PSOR, GPIOB_PCOR, GPIOB_PDDR, PORTB_PCR1 }
#define P38                                                                    \
  { 3, GPIOB_PSOR, GPIOB_PCOR, GPIOB_PDDR, PORTB_PCR3 }
#define P39                                                                    \
  { 16, GPIOB_PSOR, GPIOB_PCOR, GPIOB_PDDR, PORTB_PCR16 }
#define P40                                                                    \
  { 17, GPIOB_PSOR, GPIOB_PCOR, GPIOB_PDDR, PORTB_PCR17 }
#define P41                                                                    \
  { 18, GPIOB_PSOR, GPIOB_PCOR, GPIOB_PDDR, PORTB_PCR18 }
#define P42                                                                    \
  { 19, GPIOB_PSOR, GPIOB_PCOR, GPIOB_PDDR, PORTB_PCR19 }

#define P43                                                                    \
  { 0, GPIOC_PSOR, GPIOC_PCOR, GPIOC_PDDR, PORTC_PCR0 }
#define P44                                                                    \
  { 1, GPIOC_PSOR, GPIOC_PCOR, GPIOC_PDDR, PORTC_PCR1 }
#define P45                                                                    \
  { 2, GPIOC_PSOR, GPIOC_PCOR, GPIOC_PDDR, PORTC_PCR2 }

#define P57                                                                    \
  { 0, GPIOD_PSOR, GPIOD_PCOR, GPIOD_PDDR, PORTD_PCR0 }
#define P62                                                                    \
  { 5, GPIOD_PSOR, GPIOD_PCOR, GPIOD_PDDR, PORTD_PCR5 }
#define P63                                                                    \
  { 6, GPIOD_PSOR, GPIOD_PCOR, GPIOD_PDDR, PORTD_PCR6 }
#define P64                                                                    \
  { 7, GPIOD_PSOR, GPIOD_PCOR, GPIOD_PDDR, PORTD_PCR7 }

#endif
