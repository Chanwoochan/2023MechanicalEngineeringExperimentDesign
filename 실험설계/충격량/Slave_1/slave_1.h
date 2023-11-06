#ifndef SLAVE1_H
#define SLAVE1_H

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

void mpu6050Setup();
sensors_event_t mpuGetAcc();

void excelDataSetup();
void printSerial(sensors_event_t a);
void writeSerialUser(sensors_event_t a);

void btSetup();
void btLoop();

#endif
