// SysTick Current Value Register
#define SYST_CVR p_addr32(0xE000E018)
// SysTick Reload Value Register
#define SYST_RVR p_addr32(0xE000E014)
// SysTick Control and Status
#define SYST_CSR p_addr32(0xE000E010)
#define SYST_CSR_CLKSOURCE ((uint32_t)0x00000004)
#define SYST_CSR_TICKINT ((uint32_t)0x00000002)
#define SYST_CSR_ENABLE ((uint32_t)0x00000001)
