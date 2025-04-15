#include <Arduino.h>
#include "pins.h"

void setup() {
  // put your setup code here, to run once:
  init_pins();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  static int this_reading = 0, last_reading = 0;

  static bool heater_on = false;
  if (!this_reading && last_reading) { // falling edge trigger
    if (heater_on) {
      Serial.println("Just turned heater on");
    } else {
      Serial.println("Just turned heater off");
    }
    digitalWrite(HEAT_RELAY, heater_on);
    heater_on = !heater_on;
  }

  last_reading = this_reading;
  this_reading = digitalRead(START_BUTTON);
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
