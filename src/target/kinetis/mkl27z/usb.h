#define USB0_OTGISTAT (*(volatile uint8_t *)0x40072010)
#define USB0_ISTAT (*(volatile uint8_t *)0x40072080)
#define USB_ISTAT_STALL ((uint8_t)0x80)
#define USB_ISTAT_SLEEP ((uint8_t)0x10)
#define USB_ISTAT_TOKDNE ((uint8_t)0x08)
#define USB_ISTAT_SOFTOK ((uint8_t)0x04)
#define USB_ISTAT_ERROR ((uint8_t)0x02)
#define USB_ISTAT_USBRST ((uint8_t)0x01)
#define USB0_INTEN (*(volatile uint8_t *)0x40072084)
#define USB_INTEN_STALLEN ((uint8_t)0x80)
#define USB_INTEN_SLEEPEN ((uint8_t)0x10)
#define USB_INTEN_TOKDNEEN ((uint8_t)0x08)
#define USB_INTEN_SOFTOKEN ((uint8_t)0x04)
#define USB_INTEN_ERROREN ((uint8_t)0x02)
#define USB_INTEN_USBRSTEN ((uint8_t)0x01)
#define USB0_ERRSTAT (*(volatile uint8_t *)0x40072088)
#define USB0_ERREN (*(volatile uint8_t *)0x4007208C)
#define USB0_STAT (*(volatile uint8_t *)0x40072090)
#define USB0_CTL (*(volatile uint8_t *)0x40072094)
#define USB_CTL_ODDRST ((uint8_t)0x02)
#define USB_CTL_USBENSOFEN ((uint8_t)0x01)
#define USB0_ADDR (*(volatile uint8_t *)0x40072098)
#define USB0_BDTPAGE1 (*(volatile uint8_t *)0x4007209C)
#define USB0_BDTPAGE2 (*(volatile uint8_t *)0x400720B0)
#define USB0_BDTPAGE3 (*(volatile uint8_t *)0x400720B4)
#define USB0_ENDPT0 (*(volatile uint8_t *)0x400720C0)
#define USB_ENDPT_EPRXEN ((uint8_t)0x08)
#define USB_ENDPT_EPTXEN ((uint8_t)0x04)
#define USB_ENDPT_EPSTALL ((uint8_t)0x02)
#define USB_ENDPT_EPHSHK ((uint8_t)0x01)
#define USB0_ENDPT1 (*(volatile uint8_t *)0x400720C4)
#define USB0_USBCTRL (*(volatile uint8_t *)0x40072100)
#define USB0_CONTROL (*(volatile uint8_t *)0x40072108)
#define USB_CONTROL_DPPULLUPNONOTG ((uint8_t)0x10)
#define USB0_CLK_RECOVER_IRC_EN p_addr32(0x40072144)
#define USB0_CLK_RECOVER_IRC_EN_IRC_EN (1 << 1)
#define USB0_CLK_RECOVER_CTRL p_addr32(0x40072140)
#define USB0_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN (1 << 7)
