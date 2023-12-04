// Master 함수 선언 헤더파일
// github.com/chanwoochan

#ifndef MASTER_H
#define MASTER_H

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//ButtonAction.ino
class ButtonAction {
    bool button_state;
  public:
    ButtonAction();
    void buttonAction (int pin);
    void buttonAction (int pin, String str);
};

//Solenoid.ino
class ExpState {
    double sol_time;
  public:
    ExpState();
    void expInnturupt();
    void startExp(int Time);
};

//Buzzer.ino
class BeepInnturupt {
    double Beep_time;
  public:
    BeepInnturupt();
    void beepInnturupt();
    void beep(int Time);
};

#endif
