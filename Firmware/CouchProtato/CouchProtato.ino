#include "CouchProtatoPower.h" //power circuit
//#include "AD524X.h" //digital potentiometer
//#include "Adafruit_SSD1306.h" //for OLED
#include "RTClib.h" //real time clock
//#include "Adafruit_nRF52_Arduino.h"//microcontroller !!!arduino couldnt find library!!!
#include "OneButton.h" //for buttons
//#include "SparkFun_LSM6DS3_Arduino_Library.h" //accelerometer and gyroscope
//#include "SparkFun_Ublox_Arduino_Library.h" //gps (might add in later)
//#include "RN_52.h" //bluetooth audio (might add in later) !!!arduino couldnt find library!!!
#import <LiquidCrystal.h> //LCD library for testing, will delete once rplaced with oled

CouchProtatoPower pwr;

#define PIN_INPUT A1
#define contra 9 //Define the pin that controls the contrast of the screen
#define bri 10 //Define the pin the controls the brightness of the screen

OneButton button(PIN_INPUT, true);
int Contrast=100;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

void setup() 
{
  Serial.begin(9600);
  pwr.begin();

  // link the doubleclick function to be called on a doubleclick event.
  button.attachClick(singleclick);

  //LCD SCREEN
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
}

void loop() 
{
  pwr.isCharging();
  pwr.getBatteryVoltage();
  //print this information to my watch screen
  button.tick();
  delay(10);

  //LCD SCREEN
}

void singleclick()
{
  static int m = 1;
  m = !m;
  if (m == 1)
  {
  lcd.setCursor(0, 0);
  lcd.print("Time (EST):"); //Output on the first line of the LCD
  lcd.setCursor(0, 1); /*Set the (invisible) cursor on the first place second row of the LCD.
                        Cursor values are 0-indexed, 0 would the be the first place.
                        The cursor coordinates are X,Y coordinates.*/
  lcd.print("12:00");
  delay(1000);
  }
  else
  {
    lcd.clear();
  }
} // singleclick
