#include <Arduino.h>

const int switchPin = 2;
const int motorPin = 9;
const int ledPin = 13;

int switchState = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
} 

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    digitalWrite(motorPin, HIGH);
    Serial.println("Motor is on");
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
    Serial.println("Motor is off");
    digitalWrite(ledPin, LOW);
  }

  // delay(500);
}