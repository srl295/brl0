#include <Arduino.h>
#include <Hv513.hpp>

const int inPin = 1;

Hv513 hv(3,5,6);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  pinMode(inPin, INPUT);
}

void loop() {
  delay(50);

  // read inPin and write to latch
  if(digitalRead(inPin) == HIGH) {
    hv.loadBit(true);
  } else {
    hv.loadBit(false);
  }
  delay(50);
  hv.latchEnable();
  delay(50);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

