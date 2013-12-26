#include "ProximitySensor.h"
#include <Arduino.h>



int SharpIRProximitySensor::read() {
  float volts = analogRead(_pin)*0.0048828125;   // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  int distance = 12*pow(volts, -1);          // worked out from graph 65 = theretical distance / (1/Volts)S
  if(distance<40&&distance!=0)
  {
    if(_last == distance && _last2 == distance) {

      _last = distance;
      _last2 = _last;

      return distance;
    }
    _last = distance;
      _last2 = _last;
  }

  return -1;
}


