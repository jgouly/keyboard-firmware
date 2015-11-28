typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#include "lpuart.h"
#include "mcg.h"
#include "port.h"
#include "sim.h"
#define p_addr32(addr) (*(volatile uint32_t *)addr)

template <LPUART_CLOCK CLK> static constexpr unsigned calculateBaud();

template <> constexpr unsigned calculateBaud<LPUART_CLOCK_LIRC>() {
  return (3 << 24) | 52;
}

template <> constexpr unsigned calculateBaud<LPUART_CLOCK_USB>() { return 313; }

template <LPUART_CLOCK CLK, LPUART_PIN_PAIR PAIR> void lpuart_init() {
  if (CLK == LPUART_CLOCK_LIRC) {
    MCG_C1 |= IRCLKEN;
  }
  SIM_SCGC5 |= SIM_SCGC5_LPUART0;

  if (PAIR == LPUART0_PTA1_PTA2) {
    // UART0_TX
    PORTA_PCR2 = PORT_PCR_PE | PORT_PCR_PS | PORT_PCR_PFE | PORT_PCR_MUX(2);
    // UART0_RX
    PORTA_PCR1 = PORT_PCR_DSE | PORT_PCR_SRE | PORT_PCR_MUX(2);
  }

  if (CLK == LPUART_CLOCK_LIRC) {
    SIM_SOPT2 |= SIM_SOPT2_LPUART0SRC_MCGIRCLK;
  } else {
    SIM_SOPT2 |= SIM_SOPT2_LPUART0SRC_IRC48M;
  }

  LPUART0_BAUD |= calculateBaud<CLK>();

  LPUART0_CTRL |= LPUART0_CTRL_TE;
}

template void lpuart_init<LPUART_CLOCK_LIRC, LPUART0_PTA1_PTA2>();
template void lpuart_init<LPUART_CLOCK_USB, LPUART0_PTA1_PTA2>();

void lpuart0_putc(uint8_t c) {
  while ((LPUART0_STAT & LPUART0_STAT_TC) == 0)
    ;
  while ((LPUART0_STAT & LPUART0_STAT_TDRE) == 0)
    ;
  LPUART0_DATA |= c;
}

void lpuart0_putch(uint8_t c) {
  lpuart0_putc('0');
  lpuart0_putc('b');
  lpuart0_putc(c & (1 << 7) ? '1' : '0');
  lpuart0_putc(c & (1 << 6) ? '1' : '0');
  lpuart0_putc(c & (1 << 5) ? '1' : '0');
  lpuart0_putc(c & (1 << 4) ? '1' : '0');
  lpuart0_putc(c & (1 << 3) ? '1' : '0');
  lpuart0_putc(c & (1 << 2) ? '1' : '0');
  lpuart0_putc(c & (1 << 1) ? '1' : '0');
  lpuart0_putc(c & (1 << 0) ? '1' : '0');
}
