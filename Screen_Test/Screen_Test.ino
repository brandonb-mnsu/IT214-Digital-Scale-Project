#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

void setup() 
{
  // put your setup code here, to run once:
lcd.begin(16,3);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  lcd.print("IT214");
  delay(900);

  lcd.setCursor(2,1);
  lcd.print("Scale");
  delay(900);

  lcd.print(" Project");
  delay(900);
  
  lcd.clear();
  lcd.print("Using Java &");
  delay(900);

  lcd.setCursor(2,1);
  lcd.print(" Arduino Code");
  delay(2000);
  lcd.clear();
  delay(2000);
  
}
