// Pin Mux Control
#define PORT_PCR_MUX(n) ((uint32_t)(((n)&7) << 8))
// Drive Strength Enable
#define PORT_PCR_DSE ((uint32_t)0x00000040)
// Slew Rate Enable
#define PORT_PCR_SRE ((uint32_t)0x00000004)
// Pull Enable
#define PORT_PCR_PE ((uint32_t)0x00000002)
// Pull Select
#define PORT_PCR_PS ((uint32_t)0x00000001)
// Passive Filter Enable
#define PORT_PCR_PFE ((uint32_t)0x00000010)

#define PORTA_PCR1 p_addr32(0x40049004)
#define PORTA_PCR2 p_addr32(0x40049008)

#define PORTB_PCR1 p_addr32(0x4004A004)
#define PORTB_PCR19 p_addr32(0x4004A04C)

#define PORTC_PCR0 p_addr32(0x4004B000)
#define PORTC_PCR9 p_addr32(0x4004B024)

#define PORTD_PCR0 p_addr32(0x4004C000)
#define PORTD_PCR7 p_addr32(0x4004C01C)

#define PORTE_PCR20 p_addr32(0x4004D050)
#define PORTE_PCR21 p_addr32(0x4004D054)
#define PORTE_PCR23 p_addr32(0x4004D05C)

#define GPIOB_PDDR p_addr32(0x400FF054)
#define GPIOC_PDDR p_addr32(0x400FF094)
#define GPIOD_PDDR p_addr32(0x400FF0D4)
#define GPIOE_PDDR p_addr32(0x400FF114)

#define GPIOE_PDIR p_addr32(0x400FF110)
#define GPIOC_PDIR p_addr32(0x400FF090)

#define GPIOB_PSOR p_addr32(0x400FF044)
#define GPIOC_PSOR p_addr32(0x400FF084)
#define GPIOD_PSOR p_addr32(0x400FF0C4)

#define GPIOB_PCOR p_addr32(0x400FF048)
#define GPIOC_PCOR p_addr32(0x400FF088)
#define GPIOD_PCOR p_addr32(0x400FF0C8)
