#include <avr/io.h>         //Contains the neccessary definitions for the MCU
#define F_CPU 16000000UL    //Define CPU clock as 16Mhz
#include <util/delay.h>     //Helper functions for delay implementation

int main(void)
{
    int i;
    DDRD = 0xF0;    //Setting the last four ports as output
                    //Only three of them are used
    while(1)
    {
        PORTD = 0x80;   //Start of the cycle 10000000
                        //The first LED is on
        for (i = 0; i < 2; i++)
        {
            _delay_ms(500);     //Delay of 500 ms
            PORTD = PORTD >> 1; //Right shift the ON port
                                //The second LED turns on
                                //Cycle continues ...
        }
		
        _delay_ms(500);
    }
    return 0;
}
