#include "Trashbin.hpp"


//initialize Trashbin
Trashbin::Trashbin(int trashbinBlueLEDPin,int trashbinYellowLEDPin,int trashbinRedLEDPin,
   int trashbinUltraSonicTriggerPin,int trashbinUltraSonicEchoPin) :
  trashbinYellowLED(trashbinYellowLEDPin),
  trashbinBlueLED(trashbinBlueLEDPin),
  trashbinRedLED(trashbinRedLEDPin),
  trashbinUltraSonic(trashbinUltraSonicTriggerPin, trashbinUltraSonicEchoPin)
  {}

//Turns all lights off
void Trashbin::turnOFF(){
    trashbinBlueLED.turnOFF();
    trashbinRedLED.turnOFF();
    trashbinYellowLED.turnOFF();
}

//Turns all lights on
void Trashbin::turnON(){
    trashbinBlueLED.turnON();
    trashbinRedLED.turnON();
    trashbinYellowLED.turnON();
}

//Function to indicate Volume 
void Trashbin::getVolume()
{   
    long trashbinDistance = trashbinUltraSonic.getDistance();
    if (trashbinDistance > emptyBin)
    {
        trashbinRedLED.turnOFF();
        trashbinYellowLED.turnOFF();
        trashbinBlueLED.turnON();
        return;
    }
    else if (trashbinDistance > halfEmptyBin)
    {
        trashbinYellowLED.turnON();
        trashbinBlueLED.turnON();
        return;
    }
    else 
    {
        trashbinYellowLED.turnON();
        trashbinBlueLED.turnON();
        trashbinRedLED.turnON();
        return;
    }
}

// function to indicate wright bin
void Trashbin::blink()
{
    for(int i = 0; i<3; i++){
        trashbinYellowLED.turnON();
        trashbinBlueLED.turnON();
        trashbinRedLED.turnON();
        delay(1000);
        trashbinYellowLED.turnOFF();
        trashbinBlueLED.turnOFF();
        trashbinRedLED.turnOFF();
        delay(500);
    }
    return;
}
