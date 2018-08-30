#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
void setup() {
  DDRB|=(1<<PB3);//IR LED Output declaration
  //default all I/O are inputs
}
void loop() {
  if((PINB&0X01)==0X01){
  PORTB|=(1<< PB3);
  }
  else{
  PORTB&=(0<< PB3);
  }
}
