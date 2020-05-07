Library for a simply activation and deactivation of a predetermined output based on sunrise and sunset times

include the library and simply enter the longitude, latitude, time zone and output pin like this:

dusker(45.6993  ,  8.4622 , 2 , 9 , false);//latitude,longitude,time zone,output,true for opto relay//

dusker is based on Dusk2Dawn library

dependencies:math,RTClib,Dusk2Dawn
