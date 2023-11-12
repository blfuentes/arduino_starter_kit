#include <Arduino.h>

// RGB LED pins
const int greenLedPin = 9;
const int blueLedPin = 10;
const int redLedPin = 11;

// RGB sensor pins
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

// init values
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
    Serial.begin(9600);

    pinMode(redLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(blueLedPin, OUTPUT);
}

void loop() {
    // red sensor values
    redSensorValue = analogRead(redSensorPin);
    delay(5);
    greenSensorValue = analogRead(greenSensorPin);
    delay(5);
    blueSensorValue = analogRead(blueSensorPin);
    delay(5);

    // display red sensor values
    Serial.print("Raw Sensor Values \t Red: ");
    Serial.print(redSensorValue);
    Serial.print("\t Green: ");
    Serial.print(greenSensorValue);
    Serial.print("\t Blue: ");
    Serial.println(blueSensorValue);

    // normalize sensor values
    redValue = map(redSensorValue, 0, 1023, 0, 255);
    greenValue = map(greenSensorValue, 0, 1023, 0, 255);
    blueValue = map(blueSensorValue, 0, 1023, 0, 255);

    // display normalized values
    Serial.print("Mapped Sensor Values \t Red: ");
    Serial.print(redValue);
    Serial.print("\t Green: ");
    Serial.print(greenValue);
    Serial.print("\t Blue: ");
    Serial.println(blueValue);

    // write values to RGB LED
    analogWrite(redLedPin, redValue);
    analogWrite(greenLedPin, greenValue);
    analogWrite(blueLedPin, blueValue);

    delay(1000);
}