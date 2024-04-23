#ifndef Button_h
#define Button_h

#include "Arduino.h"

#define BUTTON_PRESSED 1
#define BUTTON_NOT_PRESSED 0

class Button
{
    int buttonPin;

    public:
    Button(int pin);
    Button();
    int getState();
};
#endif
