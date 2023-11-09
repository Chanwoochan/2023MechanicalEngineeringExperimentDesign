/*---------------------------------------------------------------------
             Bumper beam collision experiment Slave_1 Board
                          Board : Arduino UNO
                          Coded by Chanwoochan

                          
                            kcwjoma@naver.com
                         github.com/chanwoochan
-----------------------------------------------------------------------*/

#define LOOP_TICK 10    // ms
#define CAR_MASS 1      // kg

#include "slave_1.h"

void setup(void) {
  Serial.begin(115200);
  BTbegin();            // 블루투스 초기 설정
  mpu6050Setup();       // 가속도센서 초기 설정 (라이브러리 by Adafruit)

  delay(100);           // 0.1초 대기
}

void loop() {
  sensors_event_t a = mpuGetAcc();  // a에 가속도센서 정보 저장
  printSerial(a);                   // UNO의 하드웨어 시리얼에 센서정보 출력
  writeSerialUser(a);               // 유저(Master) 입력 대응
  
  delay(LOOP_TICK);                 // LOOP_TICK 만큼 딜레이 (ms) [매트랩 지연 방지]
}
