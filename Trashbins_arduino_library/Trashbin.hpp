#ifndef TRASHBIN_HPP
#define TRASHBIN_HPP

#include "LED.hpp"
#include "Button.hpp"
#include "UltraSonic.hpp"


#define halfEmptyBin 3
#define emptyBin 6

class Trashbin{
LED trashbinYellowLED;
LED trashbinBlueLED;
LED trashbinRedLED;
UltraSonic trashbinUltraSonic; 


public:
    Trashbin();
    Trashbin(int trashbinYellowLEDPin, int trashbinBlueLEDPin, int trashbinRedLEDPin, 
    int trashbinUltraSonicTriggerPin, int trashbinUltraSonicEchoPin);
    void getVolume();
    void blink();
    void turnOFF();
    void turnON();
    
private:
    int trashbinDistance;
};

#endif