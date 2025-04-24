#include "pins.h"

void init_pins() {

    pinMode(HEAT_RELAY, OUTPUT);
    digitalWrite(HEAT_RELAY, 0);

    pinMode(VALVE_RELAY, OUTPUT);
    digitalWrite(VALVE_RELAY, 0); // ??

    pinMode(START_BUTTON, INPUT_PULLUP);

}


