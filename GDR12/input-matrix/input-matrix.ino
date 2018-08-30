#include "badge.h"
#include "badge1.h"
matrix md;
readin inputs;
const bool carita[6][6] PROGMEM={
        {0,0,0,1,1,0},
        {1,1,0,0,0,1},
        {0,0,0,0,1,0},
        {0,0,0,0,1,0},
        {1,1,0,0,0,1},
        {0,0,0,1,1,0}
};
const bool pacman[6][6] PROGMEM={
        {0,0,0,0,0,0},
        {1,1,0,1,0,1},
        {0,0,0,1,0,1},
        {1,1,0,0,1,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
};
void setup(){}
void loop(){
  if(inputs.sw1()==false){
    md.showim(carita);
  }
  else{
    md.showim(pacman);
  }
}
