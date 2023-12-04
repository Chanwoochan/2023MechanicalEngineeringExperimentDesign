// 솔레노이드 컨트롤을 위한 클래스 함수 정의
// github.com/chanwoochan

#include "master.h"


ExpState::ExpState(){           // 생성자
  sol_time = 0;                 // 솔레노이드 상태
}

void ExpState::expInnturupt (){    // 솔레노이드 상태 변경
  if(sol_time > millis()) {
    servo.write(90); 
  } else servo.write(0); 
}   

void ExpState::startExp(int Time){   // 솔레노이드 작동 Time = ms
  sol_time = Time * 1.0 + millis();
}
