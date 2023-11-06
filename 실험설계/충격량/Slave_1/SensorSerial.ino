#include "slave_1.h"

extern volatile unsigned long timer0_millis;

void excelDataSetup(){
  //Serial.println("CLEARDATA");
  //Serial.println("LABEL,ms_time, acc");
  timer0_millis=0;
}

void printSerial(sensors_event_t a){
  double mstime = millis()/1000.0;                          //s
  double force = (a.acceleration.x - acc_cor) * CAR_MASS;   //N
  Serial.print("[Slave1]:");
  Serial.print(mstime);
  Serial.print(",");
  Serial.println(force);
}

void writeSerialUser(sensors_event_t a){
  if(Serial.available()){
    String inputStr = Serial.readStringUntil('\n');
    if(inputStr=="[Master]:timer_init") timer0_millis = 0;
    if(inputStr=="[Master]:acc_init") acc_cor = a.acceleration.x;
  }
}
