#include <Arduino.h>
#include <Servo.h>

// define the servo object
Servo myServo;

// define pins
const int piezoPin = A0;
const int switchPin = 2;
const int yellowLedPin = 3;
const int greenLedPin = 4;
const int redLedPin = 5;
const int servoPin = 9;

// constants
const int quietKnock = 10;
const int loudKnock = 100;

// define variables
int knockVal;
int switchVal;
boolean locked = false;
int numberOfKnocks = 0;

void setup()
{
  // attach the servo
  myServo.attach(servoPin);

  // configure the pins
  pinMode(switchPin, INPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  // initialize serial communication
  Serial.begin(9600);

  // move the servo to the unlocked position
  digitalWrite(greenLedPin, HIGH);
  myServo.write(0);
  Serial.println("the box is unlocked");
}

void loop()
{
  if (locked == false)
  {
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH)
    {
      locked = true;
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
      myServo.write(90);
      Serial.println("the box is locked");
      delay(1000);
    }
  }

  if (locked == true)
  {
    knockVal = analogRead(piezoPin);
    if (numberOfKnocks < 3 && knockVal > 0)
    {
      if (checkForKnock(knockVal) == true)
      {
        numberOfKnocks++;
      }
      Serial.print(3-numberOfKnocks);
      Serial.println(" more knocks to go");
    }

    if (numberOfKnocks >= 3)
    {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLedPin, HIGH);
      digitalWrite(redLedPin, LOW);

      Serial.println("the box is unlocked");
    }
  }
}

boolean checkForKnock(int value)
{
  if (value > quietKnock && value < loudKnock)
  {
    digitalWrite(yellowLedPin, HIGH);
    delay(50);
    digitalWrite(yellowLedPin, LOW);

    Serial.println("Validad knock of value " + String(value));

    return true;
  }
  else
  {
    Serial.println("Bad knock value " + String(value));

    return false;
  }
}