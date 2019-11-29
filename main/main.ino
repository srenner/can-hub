#include <ASTCanLib.h>

//pins used on board
byte const MPH_PIN = 9;                                     //pin 9 on the board corresponds to interrupt 7 on the chip

//helper variables
unsigned long currentMillis = 0;                            //
unsigned long lastMillis = 0;                               //

//constants/variables for mph
unsigned const int MPH_PULSES_PER_MILE = 8000;              //typical early Ford speed sensor
byte const MPH_CALC_INTERVAL = 125;                         //read number of pulses approx every 1/8 second
byte const MPH_BUFFER_LENGTH = 4;                           //
volatile unsigned long mphCounter = 0;                      //increment pulses in the interrupt function
unsigned long mphCounterPrevious = 0;                       //used to calculate speed

//interrupt routine for interrupt 7 (pin 9)
ISR(INT7_vect) {
  mphCounter++;
}

void setup() {
  pinMode(MPH_PIN, INPUT_PULLUP);

  //set trigger for interrupt 7 (pin 9) to be falling edge (see datasheet)
  EICRB |= ( 1 << ISC71);
  EICRB |= ( 0 << ISC70);

  //enable interrupt 7 (pin 9) (see datasheet)
  EIMSK |= ( 1 << INT7);

}

void loop() {

}
