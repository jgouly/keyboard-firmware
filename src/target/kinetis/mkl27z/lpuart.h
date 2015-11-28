#define LPUART0_BAUD (*(volatile uint32_t *)0x40054000)
#define LPUART0_CTRL (*(volatile uint32_t *)0x40054008)
#define LPUART0_CTRL_TE (1 << 19)
#define LPUART0_DATA (*(volatile uint32_t *)0x4005400C)
#define LPUART0_STAT (*(volatile uint32_t *)0x40054004)
#define LPUART0_STAT_TDRE (1 << 23)
#define LPUART0_STAT_TC (1 << 22)

#define SELECTED_LPUART_CLK LPUART_CLOCK_LIRC
#define SELECTED_LPUART_PAIR LPUART0_PTA1_PTA2

enum LPUART_CLOCK { LPUART_CLOCK_LIRC, LPUART_CLOCK_USB };

enum LPUART_PIN_PAIR { LPUART0_PTA1_PTA2 };

template <LPUART_CLOCK CLK, LPUART_PIN_PAIR PAIR> void lpuart_init();

void lpuart0_putc(uint8_t c);
void lpuart0_putch(uint8_t c);
