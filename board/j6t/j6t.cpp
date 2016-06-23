#include "config.h"
#include "action/keycode.h"
#include "action/map.h"

#define p_addr32(x) (volatile uint32_t *const)x

const MKL27ZOutputPin mkl27zColumnPins[] = {P62, P63, P64, P19, P18, P21, P20, P44, P43, P42, P41, P40, P39, P38, P45};
const MKL27ZInputPin mkl27zRowPins[] = {PI33, PI35, PI36, PI37, PI49};

//int KEY = 10;
extern KeyFn KEY_A1;

KEYMAP({
&KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1,
&KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1,
&KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1,
&KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1,
&KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1, &KEY_A1,
});
