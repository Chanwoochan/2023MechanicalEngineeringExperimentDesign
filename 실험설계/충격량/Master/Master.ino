/*---------------------------------------------------------------------
             Bumper beam collision experiment Master Board
                          Board : Arduino Mega 2560
                          Coded by Chanwoochan

                          
                            kcwjoma@naver.com
                         github.com/chanwoochan
-----------------------------------------------------------------------*/
#define EXP_SRART_PIN 6
#define EXP_STOP_PIN 7
#define SOLENOID_PIN 2
#define BUZZER_PIN 3

#include "master.h"

ExpState solenoid;                                        // 솔레노이드 클래스 객체 생성
BeepInnturupt BEEP;                                                   // 부저 인터럽트 클래스 객체 생성
ButtonAction expStop; ButtonAction sol;                               // 버튼액션 클래스 객체 생성
Servo servo;

void setup(void) {
  servo.attach(SOLENOID_PIN);
  pinMode(EXP_SRART_PIN,INPUT_PULLUP); pinMode(EXP_STOP_PIN,INPUT_PULLUP);                   // 버튼 핀 설정
  pinMode(SOLENOID_PIN,OUTPUT); pinMode(BUZZER_PIN,OUTPUT);                               // 릴레이, 부저 제어 핀
  digitalWrite(SOLENOID_PIN,LOW); digitalWrite(BUZZER_PIN,LOW);
  Serial.begin(57600);
  Serial1.begin(57600);
  digitalWrite(BUZZER_PIN,HIGH); delay(100); digitalWrite(BUZZER_PIN,LOW); delay(100); 
  digitalWrite(BUZZER_PIN,HIGH); delay(100); digitalWrite(BUZZER_PIN,LOW);              // SerialBegin 후 알림 비프
  delay(1000); 
}

void loop(void) {
  expStop.buttonAction(EXP_STOP_PIN, "[Master]:1004\n");                         // 측정종료 버튼 인터럽트
  sol.buttonAction(EXP_SRART_PIN);                                                // 솔레노이드 버튼 인터럽트
  solenoid.expInnturupt();
  BEEP.beepInnturupt();                                               // 부저 상태 인터럽트
  if(Serial1.available()) {                                           // Slave_1에서 받아온 데이터 값 serial(MATLAB)로 전송
    String inputStr = Serial1.readStringUntil('\n');
    Serial.println(inputStr);
  }
}
