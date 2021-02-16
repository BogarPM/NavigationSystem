#ifndef accel_h
#define accel_h

#include<Arduino.h>
#include<I2C.h>
#include<Arduino.h>

#define ADDRESS 0x68

//Register definitions (Datasheet)
#define PWR_MGMT_1 107
#define PWR_MGMT_2 108
#define ACCEL_XOUT_H 59
#define ACCEL_XOUT_L 60
#define ACCEL_YOUT_H 61
#define ACCEL_YOUT_L 62
#define ACCEL_ZOUT_H 63
#define ACCEL_ZOUT_L 64
#define TEMP_OUT_H 65
#define TEMP_OUT_L 66
#define GYRO_XOUT_H 67
#define GYRO_XOUT_L 68
#define GYRO_YOUT_H 69
#define GYRO_YOUT_L 70
#define GYRO_ZOUT_H 71
#define GYRO_ZOUT_L 72

#define INT_PIN_CFG 55
#define CONFIG 26
#define GYRO_CONFIG 27
#define ACCEL_CONFIG 28
#define INT_ENABLE 55

#define GYRO_250 0
#define GYRO_500 1
#define GYRO_1000 2
#define GYRO_2000 3

#define ACCEL_2G 0
#define ACCEL_4G 1
#define ACCEL_8G 2
#define ACCEL_16G 3


class accel{
private:
    int _intPin;
    //uint8_t _data[14];  //axh-axl, ayh-ayl, azh-azl, temph-templ, gxh-gxl, gyh-gyl, gzh-gzl
    int _vals[7];
public:
    accel();
    ~accel();
    void init(int intPin);
    int getIntPin();
    
    void setGyroSensitivity(int sens);
    void setAccelSensitivity(int sens);

    int getAccelX();
    int getAccelY();
    int getAccelZ();

    int getGyroX();
    int getGyroY();
    int getGyroZ();

    int getTemp();

    void clock();
    void setInterruptEnable(bool en);


};

#endif