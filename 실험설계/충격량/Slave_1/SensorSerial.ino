// 하드웨어 시리얼 통신을 위한 함수 정의
// github.com/chanwoochan

#include "slave_1.h"

extern volatile unsigned long timer0_millis;                // 아두이노 작동시간을 조작하기 위한 변수

void printSerial(sensors_event_t a){
  double mstime = millis()/1000.0;                          //s  보드 동작시간
  double force = (a.acceleration.x - acc_cor) * CAR_MASS;   //N  가속도*질량
  Serial.print("[Slave1]:");
  Serial.print(mstime);
  Serial.print(",");
  Serial.println(force);                                    // 보드동작시간, 힘 프린트
}

void writeSerialUser(sensors_event_t a){
  if(Serial.available()){
    String inputStr = Serial.readStringUntil('\n');
    if(inputStr=="[Master]:timer_init") timer0_millis = 0;          // 마스터에서 동작시간 초기화 요청 및 초기화
    if(inputStr=="[Master]:acc_init") acc_cor = a.acceleration.x;   // 마스터에서 가속도 초기화(영점보정) 요청 및 초기화
  }
}
