#include "CouchProtatoPower.h" //power circuit
//#include "AD524X.h" //digital potentiometer
//#include "Adafruit_SSD1306.h" //for OLED
//#include "RTClib.h" //real time clock
//#include "Adafruit_nRF52_Arduino.h"//microcontroller !!!arduino couldnt find library!!!
#include "OneButton.h" //for buttons
//#include "SparkFun_LSM6DS3_Arduino_Library.h" //accelerometer and gyroscope
//#include "SparkFun_Ublox_Arduino_Library.h" //gps (might add in later)
//#include "RN_52.h" //bluetooth audio (might add in later) !!!arduino couldnt find library!!!

CouchProtatoPower pwr;

#define PIN_INPUT A1
#define PIN_LED 13

OneButton button(PIN_INPUT, true);

void setup() 
{
  Serial.begin(9600);
  pwr.begin();
  pinMode(PIN_LED, OUTPUT); // sets the digital pin as output

  // link the doubleclick function to be called on a doubleclick event.
  button.attachClick(singleclick);
}

void loop() 
{
  pwr.isCharging();
  pwr.getBatteryVoltage();
  //print this information to my watch screen

  button.tick();
  delay(10);
}

void singleclick()
{
  static int m = LOW;
  m = !m;
  digitalWrite(PIN_LED, m);
} // singleclick
