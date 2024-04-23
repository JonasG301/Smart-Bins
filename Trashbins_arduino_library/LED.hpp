#ifndef LED_HPP
#define LED_HPP

//defines for returns
#define OFF 0
#define ON 1

#include <Arduino.h>

class LED {

  int LedPin;
  int mode;

public:
  LED(int pin);
  LED();
  void blink();
  void turnON();
  void turnOFF();
};
#endif