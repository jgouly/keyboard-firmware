MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
  RAM  (rwx) : ORIGIN = 0x1FFFF800, LENGTH = 8K
}

ENTRY(reset_handler_isr)

SECTIONS
{
  .text : {
    . = 0;
    KEEP(*(.vectors))
    *(.startup*)
    . = 0x400;
    KEEP(*(.flashconfig*))
    *(.text*)
    *(.rodata*)
    . = ALIGN(4);
    __init_array_start = .;
    KEEP (*(.init_array*))
    __init_array_end = .;
  } > FLASH = 0xFF

  _etext = .;

  .data : AT (_etext) {
    . = ALIGN(4);
    _sdata = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } > RAM

  .bss : {
    . = ALIGN(4);
    _sbss = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
    __bss_end = .;
  } > RAM

  _estack = ORIGIN(RAM) + LENGTH(RAM);
}
