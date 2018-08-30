#include "badge.h"
matrix::matrix(){
    a=0b1111111111000000;
    DDRB|=(1<<PB7)|(1<<PB6)|(1<<PB5);
    PORTB&=~(1<<PB6)|(1<<PB5);
    PORTB|=(1<<PB7);//clock line to high
}
void matrix::showim(bool inp[6][6],int rep){
    for(cycles=0; cycles<=(rep*25); cycles++) {
        for(row=0; row<=5; row++) {
            for(colum=0; colum<=5; colum++) {
                a=0b1111111111000000;
                if((bool*)pgm_read_byte(&(inp[row][colum]))==1) {
                    a|=(1<<row);
                    a&=~(1<<colum+6);
                    disp(a);
                }
                else{
                    disp(a);
                }
            }
        }
    }
}
void matrix::disp(int patt){
        for(int b=0; b<=15; b++) {
                PORTB&=~(1<<PB7);//clock line from high to low
                //falling edge
                if((patt&0x8000)==0x8000) {
                        PORTB|=(1<<PB6);//data line
                }
                else{
                        PORTB&=(0<<PB6);//data line
                }
                PORTB|=(1<<PB7);//clock line from low to high
                //rising edge, update the data
                patt=(patt<<1);//shift to left the input pattern
        }
        PORTB|=(1<<PB5);//latchline
        PORTB&=~(1<<PB5);//latchline
}
