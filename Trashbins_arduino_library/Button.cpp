#include "Button.hpp"

Button::Button(){};

//initialize button
Button::Button(int pin) {
  this->buttonPin = pin;
}

//return state of button
int Button::getState() {
  if (digitalRead(buttonPin) == HIGH) {
    return BUTTON_PRESSED;
  } else {
    return BUTTON_NOT_PRESSED;
  }
}