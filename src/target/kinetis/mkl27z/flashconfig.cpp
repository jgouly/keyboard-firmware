typedef unsigned char uint8_t;
__attribute__((section(".flashconfig"), used))
const uint8_t flashconfigbytes[16] = {
    // 8-byte Backdoor Key.
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    // 4-byte FPROT.
    0xFF, 0xFF, 0xFF, 0xFF,
    // 2-bytes reserved.
    0xFE, 0xFF,
    // 1-byte FOPT.
    0xFF,
    // 1-byte FSEC.
    0xFF};
