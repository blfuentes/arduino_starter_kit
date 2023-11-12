#include <Servo.h>
#include <Arduino.h>

// define servo
Servo myServo;

// define pins
const int servoPin = 9;
const int potPin = A0;

// define variables
int potVal;
int angle;


void setup() {
  // consigure servo
  myServo.attach(servoPin);

  // configure serial
  Serial.begin(9600);
}

void loop() {
  // read potentiometer
  potVal = analogRead(potPin);
  Serial.println("potVal: " + String(potVal));

  // map potentiometer value to servo angle
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.println("angle: " + String(angle));

  // move servo
  myServo.write(angle);

  // wait
  delay(100);
}