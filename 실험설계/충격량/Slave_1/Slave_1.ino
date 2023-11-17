/*---------------------------------------------------------------------
             Bumper beam collision experiment Slave_1 Board
                          Board : Arduino UNO
                          Coded by Chanwoochan

                          
                            kcwjoma@naver.com
                         github.com/chanwoochan
-----------------------------------------------------------------------*/

#define LOOP_TICK 0                           // us
#define Tx 11
#define Rx 10                                 // BT모듈 기준

#include "slave_1.h"

SoftwareSerial Slave_1(Tx,Rx);                // 소프트웨어 시리얼 선언

ButtonAction Init;                            // 버튼 클래스 객체 생성

extern volatile unsigned long timer0_millis;  // 아두이노 작동시간을 조작하기 위한 변수
double acc_cor = 0.0;                         // 가속도 보정 상수

void setup(void) {
  Serial.begin(57600);                        // Baudrate 57600bps
  Slave_1.begin(57600);                       // 블루투스 초기 설정
  pinMode(12,INPUT_PULLUP);                   // 가속도 보정버튼 핀 초기화 (풀업버튼)
  mpu6050Setup();                             // 가속도센서 초기 설정 (라이브러리 by Adafruit)
  delay(100);                                 // 0.1초 대기
}

void loop() {
  sensors_event_t a = mpuGetAcc();             // a에 가속도센서 정보 저장
  printSerial(a);                              // UNO의 하드웨어 시리얼에 센서정보 출력
  Init.buttonAction(12, a);                    // 가속도 보정 버튼 입력 함수
  //delayMicroseconds(LOOP_TICK);                // 통신 오류 방지 틱 (안줌)
}
