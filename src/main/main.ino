#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 9, 8, 7, 6);

int cube = 0;

void setup() {
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Print a message to the LCD.
    lcd.print("Press the button");
    lcd.setCursor(0,1);
    lcd.print("for roll");
    lcd.setCursor(1,0);

 pinMode(13, OUTPUT);
}
void loop() {
  if(digitalRead(13) == HIGH){
    cube = random(1,7);
    lcd.clear();
    lcd.print("Score:");
    lcd.print(     cube);
    delay(750);
  }
}