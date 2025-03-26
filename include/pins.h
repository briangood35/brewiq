#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

#define HEAT_RELAY 4
#define VALVE_RELAY 5
#define START_BUTTON 6

extern void brew();

void init_pins() {

    pinMode(HEAT_RELAY, OUTPUT);
    digitalWrite(HEAT_RELAY, 0);

    pinMode(VALVE_RELAY, OUTPUT);
    digitalWrite(VALVE_RELAY, 0); // ??

    pinMode(START_BUTTON, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(START_BUTTON), brew, RISING);

}

#endif
