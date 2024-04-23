#include "TrashSystem.hpp"

//initialize TrashSystem
TrashSystem::TrashSystem(int yellowTrashbinYellowLEDPin, int yellowTrashbinBlueLEDPin, int yellowTrashbinRedLEDPin, 
                    int brownTrashbinYellowLEDPin, int brownTrashbinBlueLEDPin, int brownTrashbinRedLEDPin, 
                    int blackTrashbinYellowLEDPin, int blackTrashbinBlueLEDPin, int blackTrashbinRedLEDPin, 
                    int yellowTrashbinUltraSonicTriggerPin, int yellowTrashbinUltraSonicEchoPin, 
                    int brownTrashbinUltraSonicTriggerPin, int brownTrashbinUltraSonicEchoPin, 
                    int blackTrashbinUltraSonicTriggerPin, int blackTrashbinUltraSonicEchoPin, 
                    int pushButtonPin) :
  yellowTrashbin(yellowTrashbinBlueLEDPin, yellowTrashbinYellowLEDPin, yellowTrashbinRedLEDPin,
    yellowTrashbinUltraSonicTriggerPin, yellowTrashbinUltraSonicEchoPin), // initialize Trasbins
  brownTrashbin(brownTrashbinBlueLEDPin, brownTrashbinYellowLEDPin, brownTrashbinRedLEDPin,
    brownTrashbinUltraSonicTriggerPin, brownTrashbinUltraSonicEchoPin),
  blackTrashbin(blackTrashbinBlueLEDPin, blackTrashbinYellowLEDPin, blackTrashbinRedLEDPin,
    blackTrashbinUltraSonicTriggerPin, blackTrashbinUltraSonicEchoPin),
  pushButton(pushButtonPin) {}                                            // initialize Button

void TrashSystem::mainRoutine()
{
    button_state = pushButton.getState();  //is asistants needed? 
    if(button_state == BUTTON_NOT_PRESSED){
        yellowTrashbin.getVolume();
        blackTrashbin.getVolume();
        brownTrashbin.getVolume();
        wait();
    } else {
        yellowTrashbin.turnOFF();
        blackTrashbin.turnOFF();
        brownTrashbin.turnOFF();
        if (Serial.available()) {
            message = getTrashbin();
            Serial.println(message);
            int trashbin = chooseTrashbin(message);
            switch (trashbin)
            {
            case YELLOW_TRASHBIN:
                yellowTrashbin.blink();
                break;
            case BROWN_TRASHBIN:
                brownTrashbin.blink();
                break;
            case BLACK_TRASHBIN:
                brownTrashbin.blink();
                break;
            case TRASHBIN_ERROR:
                allLightsBlink();
                break;
            default:
                break;
            }
            message = "";
        }
    }
}
// function for error case
void TrashSystem::allLightsBlink(){
    for(int i = 0; i<3; i++){
        yellowTrashbin.turnON();
        brownTrashbin.turnON();
        blackTrashbin.turnON();
        delay(1000);
        yellowTrashbin.turnOFF();
        brownTrashbin.turnOFF();
        blackTrashbin.turnOFF();
        delay(500);
    }
}

void TrashSystem::wait(){
    delay(50);
}

int TrashSystem::chooseTrashbin(String trashbin)
{
    if (trashbin == "Plastik")
    {
        return YELLOW_TRASHBIN;
    }
    else if (trashbin == "Bio")
    {
        return BROWN_TRASHBIN;
    }
    else if (trashbin == "Restabfalleimer")
    {
        return BLACK_TRASHBIN;
    }
    else
    {
        return TRASHBIN_ERROR;
    }
}

String TrashSystem::getTrashbin(){ 
    message = Serial.readString();
    return message;
}