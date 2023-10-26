#include <LiquidCrystal.h>
#include <GyverButton.h>
#include "Dice.h"

LiquidCrystal lcd(12, 11, 9, 8, 7, 6);
GButton butt1(13);
boolean isPress = false;
Dice cube (6);

void setup() {
  button1Setup();
  lcd.begin(16, 2);
  lcd.clear();

  lcd.print("Press the button");
  lcd.setCursor(0, 1);
  lcd.print("for roll");
  lcd.setCursor(1, 0);
}

void button1Setup() {
  butt1.setTickMode(AUTO);
  butt1.setDebounce(50);
  butt1.setTimeout(300);
  butt1.setClickTimeout(600);
  butt1.setType(HIGH_PULL);
  butt1.setDirection(NORM_OPEN);
}

void loop() {
  if (butt1.isHold() && isPress == false) {
    lcd.clear();
    lcd.print("Rolling...");
    isPress = true;
  }
  if (butt1.isRelease()) {
    isPress = false;
    lcd.clear();
    cube.doThrow();
    lcd.print("Score: ");
    lcd.print(cube.getValue());
  }
}
