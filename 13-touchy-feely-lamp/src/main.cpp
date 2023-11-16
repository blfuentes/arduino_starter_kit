#include <Arduino.h>
#include <CapacitiveSensor.h>

// declare the capacit
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

const int ledPin = 12;

int threshold = 1000;
long sensorValue;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);

  if (sensorValue > threshold)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}