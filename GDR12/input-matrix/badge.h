#ifndef badge_h
#define badge_h
#include <avr/io.h>
#include <avr/pgmspace.h>
class matrix {
public:
int a,row,colum,cycles;
matrix();
void disp(int pattern);
void showim(bool inp[6][6]);
private:
};
#endif
