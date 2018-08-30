void setup() {
  //40Khz PWM for the IR sony rptocol, library in progress
  TCCR1A=0;
  TCCR1B=0;
  TCCR1A|=(1<<COM1B1)|(1<<WGM10);
  TCCR1B|=(1<<WGM12)|(1<<CS10);
  OCR1A=99;
  DDRB|=(1<<PB4);
}

void loop() {
  // put your main code here, to run repeatedly:

}
