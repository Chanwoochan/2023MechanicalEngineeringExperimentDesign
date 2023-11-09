// Slave_1 함수 선언 헤더파일
// github.com/chanwoochan

#ifndef SLAVE1_H
#define SLAVE1_H

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <SoftwareSerial.h>
#include <Wire.h>

// MPU6050setup.ino
void mpu6050Setup();
sensors_event_t mpuGetAcc();

// SensorSerial.ino
void printSerial(sensors_event_t a);
void writeSerialUser(sensors_event_t a);

// HC_05.ino
void BTbegin();
void BTtoSerial();

#endif
