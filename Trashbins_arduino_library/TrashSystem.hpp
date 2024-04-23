#ifndef TRASHSYSTEM_HPP
#define TRASHSYSTEM_HPP

#include "LED.hpp"
#include "Button.hpp"
#include "UltraSonic.hpp"
#include "Trashbin.hpp"

#define errorMessage "No wright bin"
#define YELLOW_TRASHBIN 1
#define BROWN_TRASHBIN 2
#define BLACK_TRASHBIN 3	
#define TRASHBIN_ERROR 4

class TrashSystem {
LED yellowTrashbinYellowLED;
LED yellowTrashbinBlueLED;
LED yellowTrashbinRedLED;
LED brownTrashbinYellowLED;
LED brownTrashbinBlueLED;
LED brownTrashbinRedLED; 
LED blackTrashbinYellowLED;
LED blackTrashbinBlueLED;
LED blackTrashbinRedLED;
Trashbin yellowTrashbin; 
Trashbin brownTrashbin;
Trashbin blackTrashbin; 
Button pushButton;


public:
    TrashSystem();
    TrashSystem(int yellowTrashbinYellowLEDPin, int yellowTrashbinBlueLEDPin, int yellowTrashbinRedLEDPin, 
    int brownTrashbinYellowLEDPin, int brownTrashbinBlueLEDPin, int brownTrashbinRedLEDPin, 
    int blackTrashbinYellowLEDPin, int blackTrashbinBlueLEDPin, int blackTrashbinRedLEDPin, 
    int yellowTrashbinUltraSonicTriggerPin, int yellowTrashbinUltraSonicEchoPin, 
    int brownTrashbinUltraSonicTriggerPin, int brownTrashbinUltraSonicEchoPin, 
    int blackTrashbinUltraSonicTriggerPin, int blackTrashbinUltraSonicEchoPin, 
    int pushButtonPin);
    
    void mainRoutine();

    
private: 
    String message;
    int button_state;
    String getTrashbin();
    void wait();
    int chooseTrashbin(String trashbin);
    void allLightsBlink();
};
#endif