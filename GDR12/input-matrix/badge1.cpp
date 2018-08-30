#include "badge1.h" 
readin::readin(){
  PORTA|=((1<<PA0)|(1<<PA1));
}
bool readin::sw2(){
  if((PINA&0x01)==0x01){
    return true;
  }
  else{
    return false;
  }
}
bool readin::sw1(){
  if((PINA&0x02)==0x02){
    return true;
  }
  else{
    return false;
  }
}
bool readin::hall(){
  if((PINB&0x01)==0x01){
    return true;
  }
  else{
    return false;
  }
}
