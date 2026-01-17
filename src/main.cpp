#include <Arduino.h>
#include "Joysticks/joysticks.h"
#include "Motors/motors.h"



void setup() {
  Serial.begin(115200);
  Joystick_Setup();
  Motors_Setup();
  
}



void loop() {

  Joysticks_Update();
  Joysticks_Print();

}
