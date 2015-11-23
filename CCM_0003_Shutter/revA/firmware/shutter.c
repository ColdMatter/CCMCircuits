#import <avr/io.h>
#import <util/delay.h>

#define SERVO_OUT_PORT PORTA
#define SERVO_OUT_LINE PA6
#define SERVO_OUT_DDR DDRA

#define TTL_IN_PORT PORTB
#define TTL_IN_LINE PB0
#define TTL_IN_DDR DDRB
#define TTL_IN_DATA PINB

// these numbers are the length of the servo control
// pulses (in clock periods). Changing these will
// change the two positions that the servo flips
// between.
#define SERVO_NEUTRAL 8000
#define SERVO_MOVED 8400

int main()
{
	// set up the digital input and output
	SERVO_OUT_DDR |= _BV(SERVO_OUT_LINE);
	TTL_IN_DDR &= ~_BV(TTL_IN_LINE);
	// activate the input pull-up
	TTL_IN_PORT |= _BV(TTL_IN_LINE);

	// set up the timer to generate the servo output
	// we use 16-bit counter timer 1 in phase and frequency
	// correct PWM mode. The TOP value of the counter is defined
	// by ICR1, and the PWM duty cycle by OCR1A
	// The clock runs at the system clock rate (8MHz).
	TCCR1A = _BV(COM1A1);
	TCCR1B = _BV(WGM13) | _BV(CS10);
	// this sets the pulse repetition rate sent to the servo, in units of system clocks.
	// 0xffff is equivalent to 8.2ms (this is pretty fast for a servo - they usually run
	// at 40Hz ish, but the fast digital ones can usually take faster.)
	ICR1 = 0x8fff;
	// start with an initial pulse period of 1.5ms (servo centered)
	OCR1A = SERVO_NEUTRAL;

	// start the main loop
	for (;;)
	{
		// check every ms or so for a change in the TTL line
//		_delay_us(1000);

		//
//		if ( bit_is_set(TTL_IN_DATA, TTL_IN_LINE) ) OCR1A = SERVO_MOVED;
//		else OCR1A = SERVO_NEUTRAL;
//		if ( bit_is_set(TTL_IN_DATA, TTL_IN_LINE) ) SERVO_OUT_PORT &= ~_BV(SERVO_OUT_LINE);
//		else SERVO_OUT_PORT |= _BV(SERVO_OUT_LINE);

		if ( bit_is_set(TTL_IN_DATA, TTL_IN_LINE) )
		{
			_delay_ms(100);
			OCR1A = SERVO_NEUTRAL;
			_delay_ms(100);
			OCR1A = SERVO_MOVED;
		}
	}
	
}
