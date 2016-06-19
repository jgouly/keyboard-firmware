#ifndef MKL27Z_INPUT_PIN
#define MKL27Z_INPUT_PIN

#include "port.h"
typedef unsigned int uint32_t;

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
  { 23, PORTE_PCR23, GPIOE_PDDR, GPIOE_PDIR }

#define PI33                                                                   \
  { 19, PORTA_PCR19, GPIOA_PDDR, GPIOA_PDIR }

#define PI35                                                                   \
  { 0, PORTB_PCR0, GPIOB_PDDR, GPIOB_PDIR }
#define PI36                                                                   \
  { 1, PORTB_PCR1, GPIOB_PDDR, GPIOB_PDIR }
#define PI37                                                                   \
  { 2, PORTB_PCR2, GPIOB_PDDR, GPIOB_PDIR }

#define PI49                                                                   \
  { 4, PORTC_PCR4, GPIOC_PDDR, GPIOC_PDIR }
#define PI54                                                                   \
  { 9, PORTC_PCR9, GPIOC_PDDR, GPIOC_PDIR }

#endif
