void setup() {
  //40Khz PWM for the IR sony protocol, library in progress
  //the IR led pin is on PB4 with 0C1B timer1 output
  //for testing the pin is changed to the PB3 OC1A timer1 output
  TCCR1A=0;
  TCCR1B=0;
  TCCR1A|=(1<<COM1A1)|(1<<WGM11);
  TCCR1B|=(1<<WGM13)|(1<<CS10);
  //New top of the counter
  ICR1=100;
  //duty cicle of 50% of the top of 99
  OCR1A=50;
  //output declaration
  DDRB|=(1<<PB3);
}

void loop() {
}
