#define LOOP_TICK 50    //ms
#define CAR_MASS 1      //kg

#include "slave_1.h"

void setup(void) {
  Serial.begin(115200);
  while(!Serial) delay(10);
  mpu6050Setup();

  pinMode(9,INPUT_PULLUP);
  delay(100);
  
  //excelDataSetup();
}

void loop() {
  sensors_event_t a = mpuGetAcc();
  printSerial(a);
  writeSerialUser(a);
  
  delay(LOOP_TICK);
}
