typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef void(isr_fn)();

extern "C" void default_isr() {}

#define INT(name)                                                              \
  extern "C" void name##_isr() __attribute__((weak, alias("default_isr")));
#include "interrupts.def"
#undef INT

// Provided by the linker.
extern uint32_t _estack;

__attribute__((section(".vectors"), used)) isr_fn *VectorFlash[] = {
    (isr_fn *)((unsigned long)&_estack), //  0 ARM: Initial Stack Pointer
#define INT(name) name##_isr,
#include "interrupts.def"
#undef INT
};
