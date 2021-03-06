typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#include "config.h"
#include "lpuart.h"
#include "mcg.h"
#include "scb.h"
#include "sim.h"
#include "systick.h"
#include "usb.h"
#define p_addr32(addr) (*(volatile uint32_t *)addr)

#include "common/USBBuffer.h"
#include "third_party/usb_keyboard.h"

extern int app_main(const LayoutT &l, const MapT &map);

void disable_watchdog() { SIM_COPC = 0; }

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

typedef void (*boot_fn)(void *);
void bootloader_start() {
  uint32_t const kbootloader_start_address = **(uint32_t **)(0x1C00001CUL);
  boot_fn kbootloader_start = (boot_fn)kbootloader_start_address;
  kbootloader_start(nullptr);
  __builtin_unreachable();
}

extern "C" void nmi_isr() { bootloader_start(); }

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

void sendBuffer(const USBBuffer &buff) {
  const unsigned *buf = buff.getData();
  unsigned count = buff.size();
  for (unsigned i = 0; i < count; ++i) {
    keyboard_keys[i] = buf[i];
  }
  for (unsigned i = count; i < 6; ++i) {
    keyboard_keys[i] = 0;
  }
  keyboard_modifier_keys = buff.getMods();
  usb_keyboard_send();
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

static void init_clocks() {
  MCG_MC |= MCG_MC_HIRCEN;
  MCG_C1 &= ~MCG_C1_CLKS_HIRC;
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
