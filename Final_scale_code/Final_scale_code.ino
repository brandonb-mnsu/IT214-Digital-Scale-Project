#include "HX711.h"
#define DOUT  3
#define CLK  2
#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 8, 4, 5, 6, 7);



HX711 scale;

void setup(){
  lcd.begin(16,2);
  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare();
}

void loop() {
  float current_weight = scale.get_units();
  float scale_reading = (current_weight/6.85);
  float metric_conversion = (scale_reading / 2.205);
  lcd.setCursor(0,0);
  lcd.print("   Pounds:");
  lcd.print(scale_reading);

  
  
  lcd.setCursor(0,1);
  lcd.print("Kilograms:");
  lcd.print(metric_conversion);
  delay(200);

  lcd.clear();
}
  
  






// just the calibration code
