#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
void setup() {
  DDRB|=(1<<PB4);//IR LED Output declaration
  //default all I/O are inputs
  PORTA|=((1<<PA1)|(1<<PA0));//Input pullup declaration
}
void loop() {
  if((PINA&0X03)==0X03){
  PORTB|=(1<< PB4);
  }
  else{
  PORTB&=(0<< PB4);
  }
}
