// MPU6050 모듈을 위한 함수 정의
// github.com/chanwoochan

#include "slave_1.h"

Adafruit_MPU6050 mpu;                             // Adafruit_MPU6050 라이브러리를 이용한 보정된 가속도값 객체(mpu) 생성

sensors_event_t mpuGetAcc(){                      // 가속도센서의 가속도 자이로 온도 중 가속도만 반환
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  return a;
}

void mpu6050Setup(){                              // 가속도센서 초기 설정 (라이브러리 by Adafruit)
  if (!mpu.begin()) {
    while(1) delay(10);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);  // 가속도 측정범위 최대 16G, 2048 Level
}
