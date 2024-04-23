#include "LED.hpp"

LED :: LED() {};

//initialize LED
LED :: LED(int pin) {
  this->LedPin = pin;
}

//turn on LED
void LED :: turnOFF(){
    digitalWrite(LedPin, LOW);
}

//turn off LED
void LED::turnON() {
    digitalWrite(LedPin, HIGH);
}

//let LED blink
void LED :: blink() {
    for(byte i = 0; i <= 5; i++){
        turnOFF();
        delay(500);
        turnON();
        delay(500);
    }
}
