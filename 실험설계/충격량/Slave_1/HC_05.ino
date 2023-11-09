// 블루투스 모듈과 소프트웨어 시리얼 통신을 위한 함수 정의
// github.com/chanwoochan

#define Tx 7
#define Rx 8

#include "slave_1.h"

SoftwareSerial Slave_1(Tx,Rx);  //슬레이브1 소프트웨어 시리얼 객체 생성 및 핀 설정

void BTbegin(){
  Slave_1.begin(38400);         //HC-05의 보드레이트 38400
}

void BTtoSerial(){              //소프트웨어시리얼 -> 하드웨어시리얼소프트웨어시리얼 -> 하드웨어시리얼
  if(Slave_1.available()){
    byte data = Slave_1.read();
    Serial.write(data);
  }
} 

void SerialtoBT(){              // 하드웨어시리얼 -> 소프트웨어시리얼
  if(Serial.available()){ 
    byte data = Serial.read();
    Slave_1.write(data);
  }
}
