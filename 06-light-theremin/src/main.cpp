#include <Arduino.h>

// define pins for the theremin and pins
const int sensorPin = A0;
const int potPin = A1;
const int thereminPin = 8;
const int ledPin = 13;

int sensorValue;
int pitchValue;

int potValue;
int maxFrecuency;

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
  // read the potentiometer
  potValue = analogRead(potPin);
  maxFrecuency = map(potValue, 0, 1023, 1000, 10000);

  // read the light sensor
  sensorValue = analogRead(sensorPin);
  pitchValue = map(sensorValue, sensorLow, sensorHigh, 50, maxFrecuency);

  // play the tone
  tone(thereminPin, pitchValue, 20);

  delay(10);
}