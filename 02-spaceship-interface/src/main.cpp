#include <Arduino.h>

int switchState = 0;

int switchButton = 2;
int greenLed = 3;
int redFirstLed = 4;
int redSecondLed = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLed, OUTPUT);
  pinMode(redFirstLed, OUTPUT);
  pinMode(redSecondLed, OUTPUT);
  pinMode(switchButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchButton);

  if (switchState == LOW) {
    // the button is not pressed

    digitalWrite(greenLed, HIGH);
    digitalWrite(redFirstLed, LOW);
    digitalWrite(redSecondLed, LOW);
  } else {
    // the button is pressed
    digitalWrite(greenLed, LOW);

    digitalWrite(redFirstLed, HIGH);
    digitalWrite(redSecondLed, LOW);
    delay(250);

    digitalWrite(redFirstLed, LOW);
    digitalWrite(redSecondLed, HIGH);
    delay(250);
  }
}