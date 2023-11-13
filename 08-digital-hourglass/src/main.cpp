#include <Arduino.h>

const int switchPin = 8;

unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int ledPin = 2;
long interval = 50;

bool backwards = false;

void updatePin(bool isBackwards, int ledPin);

void setup() {
  // set pin modes to output
  for (int pin = 2; pin < 8; pin++) {
    pinMode(pin, OUTPUT);
  }
  // set tilt pin mode for input
  pinMode(switchPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // get current time
  unsigned long currentTime = millis();

  // check if the interval has elapsed
  if (currentTime - previousTime > interval) {
    previousTime = currentTime;

    // turn on next LED
    // digitalWrite(ledPin, HIGH);
    updatePin(backwards, ledPin);
    ledPin = backwards ? ledPin - 1 : ledPin + 1;

    if ((ledPin == 8 && !backwards) || (ledPin == 1 && backwards)) {
      // change orientation of turn on/off
      backwards = !backwards;
      ledPin = backwards ? ledPin - 1 : ledPin + 1;
    }
  } 

  // read the switch
  switchState = digitalRead(switchPin);

  // check if the switch has changed and reset pins
  if (switchState != prevSwitchState) {
    for (int pin = 2; pin < 8; pin++) {
      digitalWrite(pin, LOW);
    }

    ledPin = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}

void updatePin(bool isBackwards, int ledPin) {
  if (isBackwards) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}