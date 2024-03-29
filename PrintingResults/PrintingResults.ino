#include "HX711.h"
#include <LiquidCrystal.h>
#define DOUT  3 //output pin
#define CLK  2  //CLK pin

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

HX711 scale;

float calibration_factor = -7050; //-7050 worked for my 440lb max scale setup

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("HX711 calibration sketch");
  lcd.print("HX711");
  delay(800);
  lcd.setCursor(2,1);
  lcd.print(" calibration sketch");
  delay(900);
  lcd.clear();
  delay(1000);
  
  Serial.println("Remove all weight from scale");
  lcd.print("Remove all weight");
  lcd.setCursor(2,1);
  lcd.print(" from scale");
  delay(900);
  lcd.clear();
  delay(1000);
  
  Serial.println("After readings begin, place known weight on scale");
  lcd.print("After readings begin,");
  delay(900);
  lcd.setCursor(2,1);
  lcd.print(" place known");
  delay(900);
  lcd.clear();
  delay(900);
  lcd.print("weight on scale");
  delay(900);
  
  Serial.println("Press + or a to increase calibration factor");
  lcd.print("Press + or a");
  delay(900);
  lcd.setCursor(2,1);
  lcd.print(" to increase");
  delay(900);
  lcd.clear();
  delay(900);
  lcd.print("calibration");
  delay(900);
  lcd.setCursor(2,1);
  lcd.print("factor");
  delay(900);
  lcd.clear();
  delay(900);
  
  Serial.println("Press - or z to decrease calibration factor");
  lcd.print("Press - or z");
  delay(900);
  lcd.setCursor(2,1);
  lcd.print(" to decrease");
  delay(900);
  lcd.clear();
  delay(900);
  lcd.print("calibration");
  delay(900);
  lcd.setCursor(2,1);
  lcd.print("factor");
  delay(900);
  lcd.clear();
  delay(900);

  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.println("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  lcd.print("Zero factor: ");
  delay(900);
  
  Serial.println(zero_factor);
  lcd.setCursor(2,1);
  lcd.print(zero_factor);
  delay(900);
  lcd.clear();
  delay(900);
  
}

void loop() {

  scale.set_scale(calibration_factor); //Adjust to this calibration factor

  Serial.print("Reading: ");
  lcd.print("Reading: ");
  delay(900);
  
  Serial.print(scale.get_units(), 1);
  lcd.setCursor(2,1);
  lcd.print(scale.get_units(), 1);
  delay(900);
  lcd.clear();
  delay(900);
  
  Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  lcd.print("lbs");
  delay(900);
  
  Serial.print(" calibration_factor: ");
  lcd.setCursor(2,1);
  lcd.print("calibration_factor: ");
  delay(900);
  lcd.clear();
  delay(900);
  
  Serial.print(calibration_factor);
  lcd.print(calibration_factor);
  delay(900);
  lcd.clear();
  delay(900);
  
  Serial.println();

  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if (temp == '-' || temp == 'z')
      calibration_factor -= 10;
  }
} // just the calibration code
