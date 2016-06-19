#ifndef ACTION_ACTION_H
#define ACTION_ACTION_H

#include "common/USBBuffer.h"
#include "config.h"

void processKeys(const ResultT &result, const MapT &map, USBBuffer &buffer,
                 const ResultT &prevResult, unsigned char &layeridx);

enum class KeyState { NONE, PRESSED, HELD, RELEASED };

#endif
