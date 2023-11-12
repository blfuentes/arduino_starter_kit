#include <Arduino.h>

// define pins for the theremin and pins
const int thereminPin = 8;
const int sensorPin = A0;
const int ledPin = 13;

int sensorValue;
int pitchValue;

// variables to calibrate the sensor
int sensorLow = 1023;
int sensorHigh = 0;

void setup() {
  // configure the pins
  pinMode(thereminPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);

  // calibrate the sensor
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }

    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  pitchValue = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(thereminPin, pitchValue, 20);

  delay(10);
}