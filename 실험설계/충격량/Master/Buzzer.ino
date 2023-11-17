// 부저 컨트롤을 위한 클래스 함수 정의
// github.com/chanwoochan

#include "master.h"

BeepInnturupt::BeepInnturupt(){       // 생성자
  Beep_time = 0;                     // 부저 작동상태
}

void BeepInnturupt::beepInnturupt(){  // 부저 작동 인터럽트
  if(Beep_time > millis()) {
    digitalWrite(BUZZER_PIN,HIGH);
  } else digitalWrite(BUZZER_PIN,LOW);
}

void BeepInnturupt::beep(int Time){   // 부저 작동 Time = ms
  Beep_time = Time * 1.0 + millis();
}
