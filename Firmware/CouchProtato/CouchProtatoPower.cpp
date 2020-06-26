#include "CouchProtatoPower.h"

const uint8_t chrgPin=27;
const uint8_t battPin=A4;
const uint16_t VDD = 3300;
const uint16_t adcResolution = 1023;
//const uint8_t gpsPwrPin=2;

CouchProtatoPower::CouchProtatoPower()
{
}

void CouchProtatoPower::begin()
{
  pinMode(chrgPin,INPUT);
  //pinMode(gpsPwrPin, OUTPUT);
}

//returns whether or not the battery is charging
bool CouchProtatoPower::isCharging()
{
  return !digitalRead(chrgPin); //return 1 if charging, 0 if not charging
}

uint16_t CouchProtatoPower::getBatteryVoltage()
{
  uint16_t val = analogRead(battPin); //10-bit ADC, will return a number between 0(0V)-1023(3.3V)
  uint16_t voltage = VDD*(val/(float)adcResolution);

  return 2*voltage;
}

/*void CouchProtatoPower::enableGPS()
{
  digitalWrite(gpsPwrPin,HIGH); //enables regulator, turning ON GPS Circuit
}

void CouchProtatoPower::disableGPS()
{
  digitalWrite(gpsPwrPin,LOW); //disables regulator, turning OFF GPS
}

void CouchProtatoPower::enableMP3()
{
  
}

void CouchProtatoPower::disableMP3()
{
  
}*/
