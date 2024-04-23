// DistanceSensor.h
#ifndef UltraSonic_H
#define UltraSonic_H

#include <Arduino.h>

#define errorValue -1

class UltraSonic {
  int ultraSonicTriggerPin;
  int ultraSonicEchoPin;
public:
  UltraSonic(int triggerPin, int echoPin);
  float getDistance();
  int checkDistance(int distance);
private:
 
};

#endif
