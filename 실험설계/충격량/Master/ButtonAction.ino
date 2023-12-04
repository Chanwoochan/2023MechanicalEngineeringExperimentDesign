// 버튼액션을 위한 클래스 함수 정의
// github.com/chanwoochan

#include "master.h"

ButtonAction::ButtonAction(){                             // 생성자
  button_state = 0;                                       // 버튼입력상태
}

void ButtonAction::buttonAction (int pin){                // 솔래노이드 버튼 액션
  if(digitalRead(pin)==LOW) {
    if(button_state == 0) {
      solenoid.startExp(1000);                            // 솔레노이드의 상태 변경
      button_state = 1;
      BEEP.beep(10);                                      // BEEP
      delayMicroseconds(50);                              // 채터링 방지
    }
  }else button_state = 0;
}   

void ButtonAction::buttonAction (int pin, String str){    // 시리얼 문자열 입력 버튼 액션
  if(digitalRead(pin)==LOW) {
    if(button_state == 0) {
      Serial.print(str);                                  // Serial에 문자열 전송
      button_state = 1;
      BEEP.beep(10);                                     // BEEP
      delayMicroseconds(50);                              // 채터링 방지
    }
  }else button_state = 0;
}   
