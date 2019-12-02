

#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];


UTFT myGLCD(ILI9341_16,38,39,40,41);

void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);
}

void loop()
{
    myGLCD.print("Weight Conversion", 0, 0);
    myGLCD.setColor(0, 0, 255);
    myGLCD.print("", 0, 16, 0);
    myGLCD.print("", 0, 50, 0);
    myGLCD.print("Pounds: ", 0, 100, 0);
    myGLCD.print("Kg: ", 0, 150, 0);
    

    myGLCD.setFont(SevenSegNumFont);

  while (true) {};
}
