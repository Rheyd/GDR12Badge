#include <avr/interrupt.h>
int temir=0,a=0,rep=0;
uint8_t bits=0,state=4;
ISR(TIMER1_CAPT_vect){
  a++;
  switch (state){
  case 0://startuptime
  if(a>=97){
    TCCR1A&=~(1<<COM1B1);
    state=1;
    a=0;
  }
  else{
    TCCR1A|=(1<<COM1B1);
    state=0;
  }
  break;
  case 1://off time of the startuptime
  if(a>=25){
    TCCR1A|=(1<<COM1B1);
    state=2;
    a=0;
  }
  break; 
  case 2://cero and one evaluation time
  TCCR1A|=(1<<COM1B1);//enable the output PWM
  if((0x800&temir)==0x800){
    if(a>=49){
      temir=temir<<1;
      state=3;
      a=0;
      bits++;
    }    
  }
  else{
    if(a>=25){
      temir=temir<<1;
      state=3;
      a=0;
      bits++;
    }    
  }

  break;
  case 3://off time
  if(bits<=11){
    TCCR1A&=~(1<<COM1B1);
    if(a>=25){
      state=2;
      a=0;
    }
  }
  else
    state=4;
  break;
  case 4://off time
    TCCR1A&=~(1<<COM1B1);
    a=0;
  /*  if(a>=1801 & rep<=3){
      state=0;
      a=0;
      rep++;
    } 
    else{
    state=4;
    }*/
  break;
  }
}
void setup() {
  //40Khz PWM for the IR sony rptocol, library in progress
  TCCR1A=0;//clear registers just in case
  TCCR1B=0;//clear registers just in case
  //TCCR1A|=(1<<COM1B1);
  /*
  Clear OC1A/OC1B on Compare Match when upcounting.
  Set OC1A/OC1B on Compare Match
  when downcounting
  */
  TCCR1B|=(1<<WGM13)|(1<<CS10);//clock selection and output mode
  ICR1=100;//new top definition
  DDRB|=(1<<PB4);//output definition
  OCR1B=33;//compare value, where 100 is 100 dutycyle, 1/3 for the sony IR protocol
  TIMSK|=(1<<ICIE1);//enable the interrupt when top value (ICR1) is reached
        sei();
  /*
  the Timer/Counter1 Input Capture interrupt is enabled. The corresponding Interrupt
  Vector
  */
  PORTA|=((1<<PA1)|(1<<PA0));//Input pullup declaration
  PORTB&=~((1<<PB5)|(1<<PB5)|(1<<PB6));//Input pullup declaration  
  DDRB|=((1<<PB5)|(1<<PB5)|(1<<PB6));
  TCCR1A&=~(1<<COM1B1);
  
}
void loop() {
    if((PINA&0X02)!=0X02){//run PA1
      temir=0b001101101111;
      state=0;
      a=0;
      TCCR1A|=(1<<COM1B1);
    }
    else if((PINA&0X01)!=0X01){//stop PA0
      temir=0b111100001111;
      state=0;
      a=0;
      TCCR1A|=(1<<COM1B1);      
    }
}
