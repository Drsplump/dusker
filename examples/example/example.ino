     //activation and deactivation of a predetermined output based on sunrise and sunset times//

#include "Arduino.h"
#include "RTClib.h"
#include "Dusk2Dawn.h"
#include "time.h"
#include "dusker.h"

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
long msmNow;
void setup()
{
  Serial.begin(9600);
  delay(3000);
  if (!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    while (1)
      ;
  }
  
  //rtc.adjust(DateTime(2020, 5, 6, 20, 45, 45));
}

void loop()
{

  dusker(45.6993,8.4622,2,9);           /////latitude,longitude,time zone from UTC,output pin/////////

  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  msmNow = (now.hour() * 60) + now.minute();
  Serial.println(msmNow);


  delay(1000);
}
