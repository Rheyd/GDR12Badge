#include "badge.h" 
readin::readin(){
	PORTA|=((1<<PA0)|(1<<PA1));
}
bool input::sw1(void){
  if((PINA&0x01)==0x01){
    return true;
  }
  else{
    return false;
  }
}
bool input::sw2(void){
  if((PINA&0x02)==0x02){
    return true;
  }
  else{
    return false;
  }
}
