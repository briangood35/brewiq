#include <Arduino.h>
#include "pins.h"

void setup() {
  // put your setup code here, to run once:
  init_pins();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void heat_water() {
  digitalWrite(HEAT_RELAY, 1);
  int delay_mins = 3;
  delay(delay_mins * 60 * 1000); // minutes to milliseconds
  digitalWrite(HEAT_RELAY, 0);
}

void drip_water() {

}


// what happens when button is pressed
void brew() {
  noInterrupts(); // disable interrupts so that extra button pushes don't screw with the brew
  heat_water();

  drip_water();

  interrupts(); // reenable interrupts for the next brew
}
