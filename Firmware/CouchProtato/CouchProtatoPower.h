/*
 * DESCRIPTION
 * CouchProtato Power file .h version
 */

#ifndef CouchProtatoPower_h
#define CouchProtatoPower_h
#include <Arduino.h>

class CouchProtatoPower
{
private:

public:

  CouchProtatoPower();
  void begin();

  bool isCharging(); //bool
  uint16_t getBatteryVoltage();
 
  void enableGPS();
  void disableGPS();

  void enableMP3();
  void disableMP3();
};

#endif
