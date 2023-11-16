#include <Arduino.h>
#include <LiquidCrystal.h>

// define the LCD object with pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;

int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup()
{
  // configure the LCD
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball");
}

void loop()
{
  // read the switch
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState && switchState == LOW)
  {
    // generate a random number
    randomSeed(analogRead(0));
    reply = random(8);

    // print the reply
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("The ball says:");
    lcd.setCursor(0, 1);
    switch (reply)
    {
    case 0:
      lcd.print("Yes");
      break;
    case 1:
      lcd.print("No");
      break;
    case 2:
      lcd.print("Ask again");
      break;
    case 3:
      lcd.print("Maybe");
      break;
    case 4:
      lcd.print("Not sure");
      break;
    case 5:
      lcd.print("Doubtful");
      break;
    case 6:
      lcd.print("No way");
      break;
    case 7:
      lcd.print("Go for it");
      break;
    }
  }

  // save the switch state
  prevSwitchState = switchState;
}