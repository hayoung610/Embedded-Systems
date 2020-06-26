// Change brightness of the LED using fast PWM
// OC1A pin are used for LED

#include <avr/io.h>
#define F_CPU 16000000UL    //Define CPU clock as 16Mhz
#include <avr/interrupt.h>
#include <util/delay.h>

int n = 0;
int main(void)
{
    cli();
    DDRB = 0x02;            //Set PORTB pin1 as output
    OCR1A = 0;
    TCCR1A = 0b10000001;    //OC1A compare match toggle,
                            //and enable fast PWM
    TCCR1B = 0b00001001;    //Enable fast PWM, clt/1
                            //TOP value set as 0x00FF(255)
    sei();
    while(1){
         n +=1;             //Change brightness
         n %= 255;
         OCR1A = n;
         _delay_ms(10);     //delay
    }
    return 0;
}
