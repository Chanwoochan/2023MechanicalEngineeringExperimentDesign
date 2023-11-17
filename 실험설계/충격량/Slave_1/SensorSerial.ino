// 하드웨어 시리얼 통신을 위한 함수 정의
// github.com/chanwoochan

#include "slave_1.h"

void printSerial(sensors_event_t a){
  double mstime = millis()/1000.0;                         // s  보드 동작시간
  double acc = (a.acceleration.x - acc_cor);               // m/s^2  가속도
  Slave_1.print("[Slave1]:");
  Slave_1.print(mstime,3);
  Slave_1.print(",");
  Slave_1.print(acc,3);                                    // 보드동작시간, 힘 프린트 
  Slave_1.println("F");                                    // 오류난 통신 구문 구분 및 구문 끝 기호로 이용
  
  //Serial.print("[Slave1]:");
  //Serial.print(mstime,3);
  //Serial.print(",");
  //Serial.print(acc,3);
  //Serial.println("F");                                     // 시리얼 모니터 확인용
}
