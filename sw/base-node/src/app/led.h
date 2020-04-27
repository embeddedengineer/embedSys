#ifndef _LED_H_
#define _LED_H_

#include "../hal/hal_led.h"
#include <stdint.h>

#define MS_TO_SECS (1000)

void toggleLed(uint8_t, uint8_t);

#endif