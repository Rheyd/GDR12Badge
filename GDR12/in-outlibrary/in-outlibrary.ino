#include "badge.h"
readin inputs;
void setup() {
  DDRB|=(1<<PB3);
}

void loop() {
  if(inputs.hall()==false){
    PORTB|=(1<<PB3);
  }
  else
    PORTB&=(0<<PB3);
}
