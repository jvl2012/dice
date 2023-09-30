#include <LiquidCrystal.h>
#include <GyverButton.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 9, 8, 7, 6);
GButton butt1(13);
boolean isPress = false;

int cube = 0;

void setup() {
  buttonSetup();
  lcd.begin(16, 2);
  lcd.clear();

  lcd.print("Press the button");
  lcd.setCursor(0, 1);
  lcd.print("for roll");
  lcd.setCursor(1, 0);
}

void buttonSetup() {
  Serial.begin(9600);
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
    cube = random(1, 7);
    lcd.print("Score:");
    lcd.print(cube);
  }
}
