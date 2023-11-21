#include <Arduino.h>

const int ledPin = 13;
const int pushButton = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(pushButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, digitalRead(pushButton));
}