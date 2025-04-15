#include "pins.h"

extern void brew();

void test_func() {
    Serial.println("test_func");
}

void init_pins() {

    pinMode(HEAT_RELAY, OUTPUT);
    digitalWrite(HEAT_RELAY, 0);

    pinMode(VALVE_RELAY, OUTPUT);
    digitalWrite(VALVE_RELAY, 0); // ??

    pinMode(START_BUTTON, INPUT_PULLUP);
    // attachInterrupt(digitalPinToInterrupt(START_BUTTON), test_func, FALLING);

}


