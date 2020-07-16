#include "CouchProtatoPower.h"
#include "AD524X.h"
#include "Adafruit_SSD1306.h"
#include "RTClib.h"
#include "Adafruit_nRF52_Arduino.h"
#include "OneButton.h"
#include "SparkFun_LSM6DS3_Arduino_Library.h"
#include "SparkFun_Ublox_Arduino_Library.h"
#include "RN_52.h"

CouchProtatoPower pwr;

void setup() 
{
  pwr.begin();
}

void loop() 
{
  pwr.isCharging();
  pwr.getBatteryVoltage();
  //pring this information to my watch screen
}
