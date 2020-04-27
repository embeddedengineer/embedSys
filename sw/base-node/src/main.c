#ifndef __AVR_ATmega32__
    #define __AVR_ATmega32__
#endif

#include <stdint.h>
#include "app/led.h"
#include <avr/io.h>
#include <util/delay.h>


int main()
{   
    uint8_t i;
    while(1)
    {
        for(i = 0; i < 4; i++) toggleLed(i, 2);
    }
    return 0;
}