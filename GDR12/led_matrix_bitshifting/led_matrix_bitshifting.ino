#include <util/delay.h>
#define   F_CPU   8000000UL
int latchPin = 14;  //Pin connected to ST_CP of 1st 74595
int clockPin = 16;  //Pin connected to SH_CP of 1st 74595
int dataPin = 15;   //Pin connected to DS of 1st 74595
/*const PROGMEM bool R[6][6]={
  {1,1,1,1,1,1},
  {1,0,0,0,1,0},
  {1,1,1,1,0,0},
  {1,0,0,1,0,0},
  {1,0,0,0,1,0},
  {1,0,0,0,0,1}
};*/
int a=0b11000000;
void setup() {
  //set pins to output so you can control the shift register   
  DDRB|=(1<<PB7)|(1<<PB6)|(1<<PB5);
}

void loop() {
    a=0b11000000;
    a|=(1<<5);
    a&=~(1<<6);  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b11111111);   
    shiftOut(dataPin, clockPin, MSBFIRST, a);    
    digitalWrite(latchPin, HIGH);
    _delay_ms(2);
    a=0b11000000;
    a|=(1<<4);
    a&=~(1<<7);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b11111111);   
    shiftOut(dataPin, clockPin, MSBFIRST, a);    
    digitalWrite(latchPin, HIGH);    
    _delay_ms(2);
    a=0b11000000;
    a|=(1<<3);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b11111110);   
    shiftOut(dataPin, clockPin, MSBFIRST, a);    
    digitalWrite(latchPin, HIGH);
    _delay_ms(2);    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b11111101);   
    shiftOut(dataPin, clockPin, MSBFIRST, 0b11001000);    
    digitalWrite(latchPin, HIGH);
    _delay_ms(2);    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b11111011);   
    shiftOut(dataPin, clockPin, MSBFIRST, 0b11010000);    
    digitalWrite(latchPin, HIGH);
    _delay_ms(2);    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b11110111);   
    shiftOut(dataPin, clockPin, MSBFIRST, 0b11100000);    
    digitalWrite(latchPin, HIGH);
    _delay_ms(2);    
}
