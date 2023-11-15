#include <Arduino.h>

// motor + goes to pin 6 on the L293D (output 2)
// motor - goes to pin 3 on the L293D (output 1)

const int controlPin1 = 2; // pin 2 connects to pin 7 on the L293D (input 2)
const int controlPin2 = 3; // pin 3 connects to pin 2 on the L293D (input 1)
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStatePin = 5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  // configure pin modes
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);

  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStatePin, INPUT);
  
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);

  Serial.begin(9600);
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchStatePin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin) / 4;
  Serial.println("Motor speed:" + String(motorSpeed));

  if (onOffSwitchState != previousOnOffSwitchState && onOffSwitchState == HIGH) {
    motorEnabled = !motorEnabled;
  }

  if (directionSwitchState != previousDirectionSwitchState && directionSwitchState == HIGH) {
    motorDirection = !motorDirection;
  }

  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  } else {
    analogWrite(enablePin, 0);
  }

  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}