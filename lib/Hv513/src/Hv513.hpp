#pragma once

#include <Arduino.h>

class Hv513
{
public:
    Hv513(uint8_t clk, uint8_t le, uint8_t din);

    /**.enable the latch */
    void latchEnable();

    /** load one bit into the latch */
    void loadBit(bool data);

private:
    /** CLK */
    uint8_t clk_;
    /** not LE */
    uint8_t le_;
    /** Data in */
    uint8_t din_;
};
