#ifndef BOARD_HOST_TEST_CONFIG_H
#define BOARD_HOST_TEST_CONFIG_H

#include "TestMatrix.h"
#include "TestPin.h"
#include <string>
using LayoutT = TestMatrixConfig;
using ResultT = TestMatrix<unsigned>;
class KeyBase;
using MapT = TestMatrix<KeyBase*>;

#endif
