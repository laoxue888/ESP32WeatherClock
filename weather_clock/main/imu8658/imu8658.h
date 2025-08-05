#ifndef IMU8658_H
#define IMU8658_H

#include "SensorLib.h"
#include "SensorQMI8658.hpp" // Ensure this path is correct
#include <esp_err.h>
#include <driver/i2c_master.h>
#include <cmath>
#define halfT 0.002127f        /*half the sample period*/
#define Kp 10.0f               
#define Ki 0.008f      

// #define TAG "IMU8658"
// static const char *TAG = "IMU8658";

class IMU8658 {
public:
    IMU8658(i2c_master_bus_handle_t *i2c_bus_handle);
    ~IMU8658();
    SensorQMI8658 *qmi;
    IMUdata acc;
    IMUdata gyr;
    float roll, pitch, yaw;
    // i2c_master_bus_handle_t *i2c_bus_handle;
    void updateIMUData();

    
private:
    bool is_init_success = false;
    i2c_master_bus_handle_t *i2c_bus_handle_=nullptr;
    bool InitIMU8658(i2c_master_bus_handle_t *i2c_bus_handle); //注意返回值不能是esp32的结构体，否则会报错

    float invSqrt(float number);
    bool getEulerAngles(float gx_, float gy_, float gz_, float ax_, float ay_, float az_);
    const char *TAG = "IMU8658";

    /* 参与计算的加速度单位g 陀螺仪单位是弧度/s()【度*pi/180=弧度】*/
    float exInt=0.0, eyInt=0.0, ezInt=0.0;
    float q0 = 1.0f, q1 = 0.0f, q2 = 0.0f, q3 = 0.0f;	/** quaternion of sensor frame relative to auxiliary frane*/
    
};

#endif