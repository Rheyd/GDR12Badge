#include "badge.h"
matrix md;
const bool g[6][6] PROGMEM={
        {0,0,1,1,1,1},
        {0,1,0,0,0,1},
        {1,0,0,0,0,0},
        {1,0,0,1,1,1},
        {1,0,0,0,0,1},
        {0,1,1,1,1,0}
};
const bool u[6][6] PROGMEM={
        {1,1,0,0,0,1},
        {1,1,0,0,0,1},
        {1,1,0,0,0,1},
        {1,1,0,0,0,1},
        {1,1,0,0,0,1},
        {0,1,1,1,1,0}
};
const bool e[6][6] PROGMEM={
        {1,1,1,1,1,1},
        {1,1,0,0,0,0},
        {1,1,0,0,0,0},
        {1,1,1,1,1,1},
        {1,1,0,0,0,0},
        {1,1,1,1,1,1}
};
const bool r[6][6] PROGMEM={
        {1,1,1,1,1,0},
        {1,1,0,0,0,1},
        {1,1,0,0,0,1},
        {1,1,1,1,1,0},
        {1,1,0,0,1,0},
        {1,1,0,0,0,1}
};
const bool a[6][6] PROGMEM={
        {0,1,1,1,0,0},
        {1,1,0,0,1,0},
        {1,1,0,0,0,1},
        {1,1,1,1,1,1},
        {1,1,0,0,0,1},
        {1,1,0,0,0,1}
};
const bool d[6][6] PROGMEM={
        {1,1,1,1,0,0},
        {1,1,0,0,1,0},
        {1,1,0,0,0,1},
        {1,1,0,0,0,1},
        {1,1,0,0,1,0},
        {1,1,1,1,0,0}
};
const bool o[6][6] PROGMEM={
        {0,1,1,1,1,0},
        {1,1,0,0,1,1},
        {1,1,0,0,1,1},
        {1,1,0,0,1,1},
        {1,1,0,0,1,1},
        {0,1,1,1,1,0}
};
const bool b[6][6] PROGMEM={
        {1,1,1,1,1,0},
        {1,1,0,0,0,1},
        {1,1,0,0,0,1},
        {1,1,1,1,1,0},
        {1,1,0,0,0,1},
        {1,1,1,1,1,0}
};
const bool t[6][6] PROGMEM={
        {1,1,1,1,1,1},
        {1,0,1,1,0,1},
        {0,0,1,1,0,0},
        {0,0,1,1,0,0},
        {0,0,1,1,0,0},
        {0,1,1,1,1,0}
};
const bool s[6][6] PROGMEM={
        {0,1,1,1,1,1},
        {1,0,0,0,0,0},
        {0,1,1,1,1,0},
        {0,0,0,0,0,1},
        {1,0,0,0,0,1},
        {1,1,1,1,1,0}
};
const bool ws[6][6] PROGMEM={
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
};
void setup() {
}
void loop() {
        md.showim(g,10);
        md.showim(ws,1);
        md.showim(u,10);
        md.showim(ws,1);
        md.showim(e,10);
        md.showim(ws,1);
        md.showim(r,10);
        md.showim(ws,1);
        md.showim(r,10);
        md.showim(ws,1);
        md.showim(a,10);
        md.showim(ws,1);
        md.showim(d,10);
        md.showim(ws,1);
        md.showim(e,10);
        md.showim(ws,1);
        md.showim(r,10);
        md.showim(ws,1);
        md.showim(o,10);
        md.showim(ws,1);
        md.showim(b,10);
        md.showim(ws,1);
        md.showim(o,10);
        md.showim(ws,1);
        md.showim(t,10);
        md.showim(ws,1);
        md.showim(s,10);
        md.showim(ws,1);
}

//this is an example for the shifthing
/*
 #include "badge.h"
   matrix md;
   int a=0b1111111111000000;
   void setup() {
   }
   void loop() {
   for (int bcc=0;bcc<=5;bcc++){
    a=0b1111111111000000;
    a&=~(1<<6+bcc);
    for (int bc=0;bc<=5;bc++){
      a=(a&0xffc0);
      a|=(1<<bc);
      md.disp(a);
      _delay_ms(50);
    }
   }
   }*/
