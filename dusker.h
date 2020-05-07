#ifndef dusker_h
#define dusker_h

#include "Arduino.h"
#include "RTClib.h"
#include "Dusk2Dawn.h"
#include "time.h"

class dusker
{
private:
  int home_sunrise;
  int home_sunset;
  int _out;
  float _latitude;
  float _longitude;
  int _time_zone;
  long msmNow;
  RTC_DS3231 rtc;
  DateTime now = rtc.now();

public:
  dusker(float, float, int, int);
};

#endif
