#include "Hv513.hpp"
#include <Arduino.h>

/** generic time unit */
const int HV_TIME = 100;

/** time unit for LE */
const int TIME_LE = HV_TIME;

/** quarter of generic time */
const int D4_TIME = (HV_TIME / 4);

Hv513::Hv513(uint8_t clk, uint8_t le, uint8_t din):
clk_(clk), le_(le), din_(din) {
    pinMode(clk_, OUTPUT);
    pinMode(le_, OUTPUT);
    pinMode(din_, OUTPUT);
    digitalWrite(le_, LOW);
    digitalWrite(clk_, :PW);
    digitalWrite(din_, LOW);
}

void
Hv513::latchEnable() {
    digitalWrite(le_, HIGH);
    delay(TIME_LE);
    digitalWrite(le_, LOW);
    delay(TIME_LE);
}

void
Hv513::loadBit(bool data) {
    digitalWrite(clk_, HIGH);
    delay(D4_TIME);
    digitalWrite(clk_, LOW);
    delay(D4_TIME);
    digitalWrite(din_, data);
    delay(D4_TIME);
    digitalWrite(clk_, HIGH);
    delay(D4_TIME);
}
