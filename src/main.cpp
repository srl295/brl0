#include <Arduino.h>
#include <Hv513.hpp>

// const int inPin = 1;

Hv513 hv(3,5,6);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // pinMode(inPin, INPUT);
}

bool z = false;

void loop() {
  delay(50);

#if 0
  // read inPin and write to latch
  if(digitalRead(inPin) == HIGH) {
    hv.loadBit(true);
  } else {
    hv.loadBit(false);
  }
#endif
  hv.loadBit(z);
  z = !z;

  delay(50);
  hv.latchEnable();
  delay(50);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

