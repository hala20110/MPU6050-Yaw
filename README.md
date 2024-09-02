# MPU6050 Yaw Reader

This project contains Arduino code to read the yaw value from an MPU6050 IMU using the I2C protocol without relying on any external libraries other than `Wire.h`.

## Project Structure

- `MPU6050_Yaw.ino`: The main Arduino file that contains the code for reading yaw from the MPU6050.

## How It Works

- The code initializes the MPU6050 and reads the yaw (Gyro Z-axis) data from the sensor.
- The yaw value is then printed to the Serial Monitor.
