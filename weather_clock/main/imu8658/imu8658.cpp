#include "imu8658.h"

float IMU8658::invSqrt(float number)
{
    long i;
    float x, y;
    const float f = 1.5F;

    x = number * 0.5F;
    y = number;
    i = * (( long * ) &y);
    i = 0x5f375a86 - ( i >> 1 );
    y = * (( float * ) &i);
    y = y * ( f - ( x * y * y ) );
    return y;
}

bool IMU8658::getEulerAngles(float gx_, float gy_, float gz_, float ax_, float ay_, float az_)
{
    float recipNorm;
    float vx, vy, vz;
    float ex, ey, ez;
    float gx, gy, gz;
    float ax, ay, az;
    gx = gx_;
    gy = gy_;
    gz = gz_;
    ax = ax_;
    ay = ay_;
    az = az_;

    float q0q0 = q0*q0;
    float q0q1 = q0*q1;
    float q0q2 = q0*q2;

    float q1q1 = q1*q1;
    float q1q3 = q1*q3;

    float q2q2 = q2*q2;
    float q2q3 = q2*q3;

    float q3q3 = q3*q3;


    if( ax*ay*az==0)
        return false;
    /* 对加速度数据进行归一化处理 */
    recipNorm = invSqrt( ax* ax +ay*ay + az*az);
    ax = ax *recipNorm;
    ay = ay *recipNorm;
    az = az *recipNorm;
    /* DCM矩阵旋转 */
    vx = 2*(q1q3 - q0q2);
    vy = 2*(q0q1 + q2q3);
    vz = q0q0 - q1q1 - q2q2 + q3q3 ;
    /* 在机体坐标系下做向量叉积得到补偿数据 */
    ex = ay*vz - az*vy ;
    ey = az*vx - ax*vz ;
    ez = ax*vy - ay*vx ;
    /* 对误差进行PI计算，补偿角速度 */
    exInt = exInt + ex * Ki;
    eyInt = eyInt + ey * Ki;
    ezInt = ezInt + ez * Ki;

    gx = gx + Kp*ex + exInt;
    gy = gy + Kp*ey + eyInt;
    gz = gz + Kp*ez + ezInt;
    /* 按照四元素微分公式进行四元素更新 */
    q0 = q0 + (-q1*gx - q2*gy - q3*gz)*halfT;
    q1 = q1 + (q0*gx + q2*gz - q3*gy)*halfT;
    q2 = q2 + (q0*gy - q1*gz + q3*gx)*halfT;
    q3 = q3 + (q0*gz + q1*gy - q2*gx)*halfT;

    recipNorm = invSqrt(q0*q0 + q1*q1 + q2*q2 + q3*q3);

    q0 = q0*recipNorm;
    q1 = q1*recipNorm;
    q2 = q2*recipNorm;
    q3 = q3*recipNorm;

    roll =  atan2(2*q2*q3 + 2*q0*q1, -2*q1*q1 - 2*q2*q2 + 1)*57.3f;
    pitch =  asin(2*q1*q3 - 2*q0*q2)*57.3f;
    yaw  =  -atan2(2*q1*q2 + 2*q0*q3, -2*q2*q2 -2*q3*q3 + 1)*57.3f;
    //usart1_report_imu(roll,pitch,yaw);
    // printf("pitch:%.2f roll:%.2f yaw:%.2f\r\n",pitch,roll,yaw);
    return true;
}

IMU8658::IMU8658(i2c_master_bus_handle_t *i2c_bus_handle){
    //构造函数
    this->qmi = new SensorQMI8658();
    this->i2c_bus_handle_=i2c_bus_handle;
    this->is_init_success = this->InitIMU8658(this->i2c_bus_handle_);
    
}

IMU8658::~IMU8658(){
    //析构函数
    if(this->qmi != nullptr){
        delete this->qmi;
        this->qmi = nullptr;
    }
}

void IMU8658::updateIMUData(){
    if (qmi->getDataReady())
    {
        if (qmi->getAccelerometer(acc.x, acc.y, acc.z))
        {
            // ESP_LOGI(TAG, "ACCEL: %f, %f, %f", acc.x, acc.y, acc.z);
            // sprintf(imu_buff, "x:%.3f;y:%.3f;z:%.3f", acc.x, acc.y, acc.z);
            // lv_label_set_text(label_imu, imu_buff);
        }
        else
        {
            ESP_LOGE(TAG, "Failed to read accelerometer data");
        }

        if (qmi->getGyroscope(gyr.x, gyr.y, gyr.z)) {
            // ESP_LOGI(TAG, "GYRO: %f, %f, %f", gyr.x, gyr.y, gyr.z);
        } 
        else {
            ESP_LOGE(TAG, "Failed to read gyroscope data");
        }

        getEulerAngles(gyr.x, gyr.y, gyr.z, acc.x, acc.y, acc.z);
        // get_euler_angles(gyr.x, gyr.y, gyr.z, acc.x, acc.y, acc.z);
        // ESP_LOGI(TAG, "Timestamp: %u, Temperature: %.2f *C", (unsigned int)qmi->getTimestamp(), qmi->getTemperature_C()); // Casting to unsigned int
    }
}

bool IMU8658::InitIMU8658(i2c_master_bus_handle_t *i2c_bus_handle){
    // Initialize QMI8658 sensor with 4 parameters (port number, address, SDA, SCL)
    if (!qmi->begin(*i2c_bus_handle, 0x6a))
    {
        ESP_LOGE(TAG, "Failed to find QMI8658 - check your wiring!");
        return false;
    }

    // Get chip ID
    ESP_LOGI(TAG, "Device ID: %x", qmi->getChipID());

    // Configure accelerometer
    this->qmi->configAccelerometer(
        SensorQMI8658::ACC_RANGE_4G,
        SensorQMI8658::ACC_ODR_1000Hz,
        SensorQMI8658::LPF_MODE_0,
        true);

    // Configure gyroscope
    qmi->configGyroscope(
        SensorQMI8658::GYR_RANGE_64DPS,
        SensorQMI8658::GYR_ODR_896_8Hz,
        SensorQMI8658::LPF_MODE_3,
        true);

    // Enable gyroscope and accelerometer
    qmi->enableGyroscope();
    qmi->enableAccelerometer();

    ESP_LOGI(TAG, "QMI8658A ok...#\n");
    return true;
}
