#ifndef __AVR_ATmega32__
    #define __AVR_ATmega32__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "hal_led.h"

static uint8_t setLedPinAsOutput(uint8_t ledNo);

static uint8_t setLedPinAsOutput(uint8_t ledNo){
    if(ledNo > LED_MAX) return 0;
    else DDRD |= (1<<(ledNo + LED_OFFSET));
    return 1;
}

uint8_t setLedOn(uint8_t ledNo){
    if(!setLedPinAsOutput(ledNo)) return 0;
    else PORTD &= ~(1<<(ledNo + LED_OFFSET)); 
    return 1;
}

uint8_t setLedOff(uint8_t ledNo){
    if(!setLedPinAsOutput(ledNo)) return 0;
    else PORTD |= (1<<(ledNo + LED_OFFSET)); 
    return 1;
}