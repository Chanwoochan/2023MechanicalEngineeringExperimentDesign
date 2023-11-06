#include "master.h"

ButtonAction::ButtonAction(){
  button_state = 0;
}

void ButtonAction::buttonAction (int pin, String str){
  if(digitalRead(pin)==LOW) {
    if(button_state == 0) Serial.print(str);
    button_state = 1;
  } else button_state = 0;
}   
