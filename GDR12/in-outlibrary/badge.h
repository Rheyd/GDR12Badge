#ifndef badge_h
#define badge_h
#include <avr/io.h>
#define F_CPU 8000000UL

class readin{
  public:
    readin();
    bool sw1();
    bool sw2();
    bool hall();
  private:
};
#endif

