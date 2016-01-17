// Interrupt Control and State
#define SCB_ICSR p_addr32(0xE000ED04)
#define SCB_ICSR_PENDSTSET ((uint32_t)0x04000000)
// System Handler Priority Register 3
#define SCB_SHPR3 (*(volatile uint32_t *)0xE000ED20)
