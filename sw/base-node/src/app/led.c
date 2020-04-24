#ifndef __AVR_ATmega32__
    #define __AVR_ATmega32__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

// Set PortD as output. 
void outputPortD(){
    DDRD = 0xff;
}

// Toggle all the leds on PORTD (-ve) logic.
void toggleLed(){
    PORTD = 0x00;    // Turn ON all the Leds connected to PORTD.
    _delay_ms(2000); // Wait for some time.
    PORTD = 0xff;    // Turn OFF all the Leds connected to PORTD.
    _delay_ms(4000); // Wait for some time.  
}