typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#include "config.h"
#include "lpuart.h"
#include "mcg.h"
#include "port.h"
#include "scb.h"
#include "sim.h"
#include "systick.h"
#include "usb.h"
#define p_addr32(addr) (*(volatile uint32_t *)addr)

extern int app_main(const LayoutT &l, const MapT &map);

void disable_watchdog() { SIM_COPC = 0; }

int putchar(int c) {
  lpuart0_putc(c);
}

extern "C" void __enable_irq();
extern "C" void __disable_irq();
volatile uint32_t systick_millis_count = 0;

extern "C" void systick_isr(void) { systick_millis_count++; }

uint32_t micros(void) {
  __disable_irq();
  uint32_t current = SYST_CVR;
  uint32_t count = systick_millis_count;
  uint32_t istatus = SCB_ICSR; // bit 26 indicates if systick exception pending
  __enable_irq();
  if ((istatus & SCB_ICSR_PENDSTSET) && current > 50)
    count++;
  current = ((F_CPU / 1000) - 1) - current;
  return count * 1000 + ((current * (uint32_t)87381) >> 22);
}

void msdelay(uint32_t ms) {
  uint32_t start = micros();

  if (ms > 0) {
    while (1) {
      while ((micros() - start) >= 1000) {
        ms--;
        if (ms == 0)
          return;
        start += 1000;
      }
    }
  }
}

void delay() __attribute__((noinline));
void delay() {
  for (int i = 0; i < 10000; ++i) {
    __asm("mov r0,r0");
  }
}
extern "C" void cdelay() { delay(); }

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

static void init_clocks() {
  MCG_MC |= MCG_MC_HIRCEN;
  while ((MCG_S & MCG_S_CLKST) != 0)
    ;
}

static void init_systick() {
  SYST_RVR = (F_CPU / 1000) - 1;
  SYST_CVR = 0;
  SYST_CSR = SYST_CSR_CLKSOURCE | SYST_CSR_TICKINT | SYST_CSR_ENABLE;
  SCB_SHPR3 = 0x20200000; // Systick = priority 32
}

extern "C" void usb_init();

extern "C" __attribute__((section(".startup"))) void reset_handler_isr() {
  disable_watchdog();
  // Enable the clock gating to all GPIO ports.
  SIM_SCGC5 = SIM_SCGC5_PORTA | SIM_SCGC5_PORTB | SIM_SCGC5_PORTC |
              SIM_SCGC5_PORTD | SIM_SCGC5_PORTE;

  copy_rom_to_ram();
  init_clocks();
  init_systick();

  call_static_constructors();

  lpuart_init<SELECTED_LPUART_CLK, SELECTED_LPUART_PAIR>();

  usb_init();

  const LayoutT l{mkl27zRowPins, mkl27zColumnPins};
  app_main(l, mkl27zMap);

  __builtin_unreachable();
}
