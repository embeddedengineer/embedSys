#ifndef __AVR_ATmega32__
    #define __AVR_ATmega32__
#endif

#include "app/led.h"
#include <avr/io.h>
#include <util/delay.h>


int main()
{
    outputPortD();
    while(1)
    {
        toggleLed();
    }
    return 0;
}