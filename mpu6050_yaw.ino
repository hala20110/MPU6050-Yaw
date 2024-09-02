#include <Wire.h>

const int MPU6050_ADDR = 0x68;
const int PWR_MGMT_1 = 0x6B;
const int GYRO_XOUT_H = 0x43;

int16_t GyroX, GyroY, GyroZ;
float yaw, elapsedTime, currentTime, previousTime;
float gyroAngleX, gyroAngleY, gyroAngleZ;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission(true);
  
  previousTime = millis();
}

void loop() {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(GYRO_XOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true);

  GyroX = Wire.read() << 8 | Wire.read();
  GyroY = Wire.read() << 8 | Wire.read();
  GyroZ = Wire.read() << 8 | Wire.read();

  currentTime = millis();
  elapsedTime = (currentTime - previousTime) / 1000;
  previousTime = currentTime;

  // Convert to angles (yaw)
  yaw += (GyroZ / 131.0) * elapsedTime;

  Serial.print("Yaw: ");
  Serial.println(yaw);
  
  delay(100);
}
