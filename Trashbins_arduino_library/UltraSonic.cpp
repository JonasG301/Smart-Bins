#include "UltraSonic.hpp"

//initialize UltraSonicSensor 
UltraSonic::UltraSonic(int ultraSonicTriggerPin, int ultraSonicEchoPin) 
  : ultraSonicTriggerPin(ultraSonicTriggerPin), ultraSonicEchoPin(ultraSonicEchoPin) {
  pinMode(ultraSonicTriggerPin, OUTPUT);
  pinMode(ultraSonicEchoPin, INPUT);
}

// funktion to return the messured distance
float UltraSonic::getDistance() {
  float distance = 0;
  float duration = 0;
  digitalWrite(ultraSonicTriggerPin, LOW);
  delay(5);
  digitalWrite(ultraSonicTriggerPin, HIGH);
  delay(10);
  digitalWrite(ultraSonicTriggerPin, LOW);
  duration = pulseIn(this->ultraSonicEchoPin, HIGH);
  distance = ((duration/2) * 0.03432);
  if (checkDistance(distance) != errorValue)
  {
    return distance;
  } else {
    return errorValue;
    }
}

//funktion to check whether the distance value is valid
int UltraSonic::checkDistance(int distance) {
  if (distance < 0) {
    return errorValue;
  } else {
    return 1;
  }
}



