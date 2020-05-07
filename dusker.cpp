#include "dusker.h"
#include "Dusk2Dawn.h"
#include "Arduino.h"
#include "RTClib.h"
#include "time.h"

dusker::dusker(float latitude, float longitude, int time_zone, int out, bool opto)
{
    pinMode(out, OUTPUT);

    _out = out;
    _latitude = latitude;
    _longitude = longitude;
    _time_zone = time_zone;
    mode = opto;

    if (mode == true)
    {
        x = LOW;
        y = HIGH;
    }
    else
    {
        x = HIGH;
        y = LOW;
    }

    Dusk2Dawn home(_latitude, _longitude, _time_zone);

    home_sunrise = home.sunrise(now.year(), now.month(), now.day(), false);
    home_sunset = home.sunset(now.year(), now.month(), now.day(), false);
    msmNow = (now.hour() * 60) + now.minute();

    if (msmNow < home_sunrise)
    {
        digitalWrite(_out, x);
    }
    if (msmNow >= home_sunrise)
    {
        digitalWrite(_out, y);
    }
    if (msmNow >= home_sunset)
    {
        digitalWrite(_out, x);
    }
}
