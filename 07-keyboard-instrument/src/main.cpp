#include <Arduino.h>

const int keyPin = A0;
const int buzzPin = 8;

int keyVal;
int notes[] = { 262, 294, 330, 349 };

void setup() {
  // configure pin modes and serial communication
  pinMode(keyPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the key value
  keyVal = analogRead(keyPin);
  Serial.println(keyVal);

  // play the note
  if (keyVal == 1023) {
    tone(buzzPin, notes[0]);
  } else if (keyVal >= 990 && keyVal <= 1010) {
    tone(buzzPin, notes[1]);
  } else if (keyVal >= 505 && keyVal <= 515) {
    tone(buzzPin, notes[2]);
  } else if (keyVal >= 5 && keyVal <= 10) {
    tone(buzzPin, notes[3]);
  } else {
    noTone(buzzPin);
  }

  delay(10);
}