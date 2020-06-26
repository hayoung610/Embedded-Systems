// Blink LED continuously with period of 1s using the internal Timer

#include <avr/io.h>
#define F_CPU 16000000UL           //Define CPU clock as 16Mhz
#include <avr/interrupt.h>

int main(void)
{
     cli();
     DDRD = 0xF0;			     //Set PORTD PIN 4 - 7 of to output and PIN 0 – 3 to input
     PORTD = 0x00;			     //set PORTD as 0
     TCNT1 = 3036;			     //Set timer/counter initial value
     TIMSK1 = 0x01;		          //enable overflow interrupt
     TCCR1B = 0b00000100;	     //set prescale as clk/256
     sei();
     while(1){
     }
     return 0;
}

ISR(TIMER1_OVF_vect)               //When overflow interrupt
{
     TCNT1 = 3036;                 //Set timer/counter initial value
     PORTD ^= 1<<7;		          //Set PORTD PIN7 to toggle  Turn on and off LED
}
