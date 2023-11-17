// 버튼액션을 위한 클래스 함수 정의
// github.com/chanwoochan

#include "slave_1.h"

ButtonAction::ButtonAction(){                                   // 생성자
  button_state = 0;                                             // 버튼입력상태
}

void ButtonAction::buttonAction (int pin,sensors_event_t a){    // 버튼이 입력되면 명령어 전송
  if(digitalRead(pin)==HIGH) {
    if(button_state == 0) {
      //timer0_millis = 0;
      acc_cor = a.acceleration.x;
      button_state = 1;
    }
  }else button_state = 0;
}   
