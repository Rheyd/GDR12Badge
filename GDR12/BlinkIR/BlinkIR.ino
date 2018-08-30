#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
void setup() {
  DDRB|=(1<<PB4);
}

void loop() {
  PORTB|=(1<< PB4);
  _delay_ms(1000);
  PORTB&=(0<< PB4);
  _delay_ms(1000);
}
