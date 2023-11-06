#include "slave_1.h"

Adafruit_MPU6050 mpu;

double acc_cor = 0.0;

sensors_event_t mpuGetAcc(){
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  return a;
}

void mpu6050Setup(){
  if (!mpu.begin()) {
    while(1) delay(10);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
}
