#include <TrashSystem.hpp>
const int yellowTrashbinBlueLEDPin = 2;
const int yellowTrashbinYellowLEDPin = 3;
const int yellowTrashbinRedLEDPin = 4; 
const int brownTrashbinBlueLEDPin = 5;
const int brownTrashbinYellowLEDPin = 6;
const int brownTrashbinRedLEDPin = 7; 
const int blackTrashbinBlueLEDPin = 8;
const int blackTrashbinYellowLEDPin = 9;
const int blackTrashbinRedLEDPin = 10; 
const int yellowTrashbinUltraSonicTriggerPin = A0;
const int yellowTrashbinUltraSonicEchoPin = A1; 
const int brownTrashbinUltraSonicTriggerPin = A2;
const int brownTrashbinUltraSonicEchoPin = A3; 
const int blackTrashbinUltraSonicTriggerPin = A4; 
const int blackTrashbinUltraSonicEchoPin = A5; 
const int pushButtonPin = 11;

TrashSystem sys(yellowTrashbinYellowLEDPin, yellowTrashbinBlueLEDPin, yellowTrashbinRedLEDPin, 
    brownTrashbinYellowLEDPin, brownTrashbinBlueLEDPin, brownTrashbinRedLEDPin, 
    blackTrashbinYellowLEDPin, blackTrashbinBlueLEDPin, blackTrashbinRedLEDPin, 
    yellowTrashbinUltraSonicTriggerPin, yellowTrashbinUltraSonicEchoPin, 
    brownTrashbinUltraSonicTriggerPin, brownTrashbinUltraSonicEchoPin, 
    blackTrashbinUltraSonicTriggerPin, blackTrashbinUltraSonicEchoPin, 
    pushButtonPin);


void setup() {
  pinMode(yellowTrashbinYellowLEDPin, OUTPUT);
  pinMode(yellowTrashbinBlueLEDPin, OUTPUT);
  pinMode(yellowTrashbinRedLEDPin, OUTPUT); 
  pinMode(brownTrashbinYellowLEDPin, OUTPUT);
  pinMode(brownTrashbinBlueLEDPin, OUTPUT);
  pinMode(brownTrashbinRedLEDPin, OUTPUT); 
  pinMode(blackTrashbinYellowLEDPin, OUTPUT);
  pinMode(blackTrashbinBlueLEDPin, OUTPUT);
  pinMode(blackTrashbinRedLEDPin, OUTPUT);
  pinMode(yellowTrashbinUltraSonicTriggerPin, OUTPUT);
  pinMode(yellowTrashbinUltraSonicEchoPin, INPUT);
  pinMode(brownTrashbinUltraSonicTriggerPin, OUTPUT);
  pinMode(brownTrashbinUltraSonicEchoPin, INPUT);
  pinMode(blackTrashbinUltraSonicTriggerPin, OUTPUT);
  pinMode(blackTrashbinUltraSonicEchoPin, INPUT);
  pinMode(pushButtonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  sys.mainRoutine();
}

