#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);
  // Serial.println("Value: " + String(value));
  Serial.write(value/4);
  delay(100);
}