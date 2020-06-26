// A to D converter
// Change LED brightness according to the rotation of the pontentiometer

#include <avr/io.h>
#define F_CPU 16000000UL    //Define CPU clock as 16Mhz
#include <avr/interrupt.h>

int main(void)

{
	cli();
	DDRD = 0xFF; // setting to ouput mode
	PORTD = 0x00; // all pins are low

	// clearing bit 7, setting REFS0 for reference voltage and ADLAR
	ADMUX &= ~(1<<REFS1);
	ADMUX |= (1<<REFS0)|(1<<ADLAR);

	// Enable ADC
	// Start single conversion
	// Enable ADC complete interrupt
	// Input clock prescaler, 125 kHz
	ADCSRA |= (1<<ADEN)|(1<<ADSC)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

	sei(); //Activate the interrupt
	while(1){}
	return 0;
}

// ADC complete interrupt
ISR(ADC_vect){
    PORTD = ADCH; // Setting port D as the digital value
    ADCSRA |= (1<<ADSC); // Starting the conversion again
}
