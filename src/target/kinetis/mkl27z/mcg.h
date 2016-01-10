#define MCG_C1 (*(volatile uint8_t *)0x40064000)
#define MCG_C1_CLKS_HIRC (3 << 6)
#define IRCLKEN (1 << 1)

#define MCG_S (*(volatile uint8_t *)0x40064006)
#define MCG_S_CLKST (3 << 2)
#define MCG_MC (*(volatile uint8_t *)0x40064018)
#define MCG_MC_HIRCEN (1 << 7)
