#include "master.h"

ButtonAction accInit;

void setup(void) {
  Serial.begin(115200);
  while(!Serial) delay(10);
  Serial.println("Master connect OK");
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  Serial.println("Pullup button set OK");
  LCDSetup();
}

void loop(void) {
  if(Serial.available()) {
    String inputStr = Serial.readStringUntil('\n');
    Serial.println(inputStr);
    accInit.buttonAction(9, "[Master]:acc_init\n[Master]:acc_init\n");
    timeParsing(inputStr);
    accParsing(inputStr);
  }
}
