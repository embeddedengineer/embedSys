#ifndef _HAL_LED_H_
#define _HAL_LED_H_

#include <stdint.h>

#define LED_OFFSET (4)
#define LED_MAX    (3)

uint8_t setLedOn(uint8_t);
uint8_t setLedOff(uint8_t);

#endif