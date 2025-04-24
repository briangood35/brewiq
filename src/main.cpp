#include <Arduino.h>
#include "pins.h"

void trigger() {
  static int state = 0;
  static bool flow = false;
  if (state == 0) {
    Serial.println("heat on");
    digitalWrite(HEAT_RELAY, 1);
  } 
  
  else if (state == 1) {
    Serial.println("heat off");
    digitalWrite(HEAT_RELAY, 0);
    Serial.println("flow on");
    digitalWrite(VALVE_RELAY, 1);
  } 
  
  else if (state == 2) {
    Serial.println("flow off");
    digitalWrite(VALVE_RELAY, 0);
  }

  state++;

  if (state == 3) {
    state = 0;
    Serial.println("cup complete, resetting to state=0");
  }
}

void setup() {
  // put your setup code here, to run once:
  init_pins();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  static int this_reading = 0, last_reading = 0;

  if (!this_reading && last_reading) { // falling edge trigger
    trigger();
  }

  last_reading = this_reading;
  this_reading = digitalRead(START_BUTTON);
}
