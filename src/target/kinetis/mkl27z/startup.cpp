typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#include "config.h"
#include "port.h"
#include "sim.h"
#include "lpuart.h"
#define p_addr32(addr) (*(volatile uint32_t *)addr)

extern int app_main(const LayoutT &l);

void disable_watchdog() { SIM_COPC = 0; }

int putchar(int c) {
  lpuart0_putc(c);
}

extern "C" __attribute__((used)) void memset(void *buf, int value, int num);
extern "C" void memset(void *buf, int value, int num) {
  char *buf_c = (char *)buf;
  for (unsigned i = 0; i < num; ++i) {
    buf_c[i] = value;
  }
}

extern "C" void (*__init_array_start)(void);
extern "C" void (*__init_array_end)(void);
void call_static_constructors() {
  for (void (**p)() = &__init_array_start; p < &__init_array_end; ++p) {
    (*p)();
  }
}

void copy_rom_to_ram() {
  extern uint32_t _etext;
  extern uint32_t _sdata;
  extern uint32_t _edata;
  extern uint32_t _sbss;
  extern uint32_t _ebss;

  uint32_t *src = &_etext;
  uint32_t *dest = &_sdata;
  while (dest < &_edata)
    *dest++ = *src++;
  dest = &_sbss;
  while (dest < &_ebss)
    *dest++ = 0;
}

extern "C" __attribute__((section(".startup"))) void reset_handler_isr() {
  disable_watchdog();
  // Enable the clock gating to all GPIO ports.
  SIM_SCGC5 = SIM_SCGC5_PORTA | SIM_SCGC5_PORTB | SIM_SCGC5_PORTC |
              SIM_SCGC5_PORTD | SIM_SCGC5_PORTE;

  copy_rom_to_ram();
  call_static_constructors();

  lpuart_init<SELECTED_LPUART_CLK, SELECTED_LPUART_PAIR>();

  const LayoutT l { mkl27zRowPins, mkl27zColumnPins };
  app_main(l);

  __builtin_unreachable();
}
