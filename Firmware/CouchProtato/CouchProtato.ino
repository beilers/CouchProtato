#include "CouchProtatoPower.h"

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
