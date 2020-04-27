#ifndef __AVR_ATmega32__
    #define __AVR_ATmega32__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

static void _delay_s(uint8_t secs);

static void _delay_s(uint8_t secs){
    while (secs--) _delay_ms(MS_TO_SECS);
}

void toggleLed(uint8_t ledNo, uint8_t delay){
    if(!setLedOn(ledNo)){
        // print error message when UART is ready.
    } else {
        _delay_s(delay);
        setLedOff(ledNo);
    }
}