#ifndef MASTER_H
#define MASTER_H

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

class ButtonAction {
    bool button_state;
  public:
    ButtonAction();
    void buttonAction (int pin, String str);
};

void LCDSetup();
void timeParsing(String inputStr);
void accParsing(String inputStr);

#endif
