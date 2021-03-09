/*Compass default configuration

    ASPM = 8    //Averaged Samples Per Measurement. Set to maximum value
    DOR = 75    //Data Output Rate. Set to maximum value








*/

#ifndef compass_h
#define compass_h

#include<Arduino.h>
#include<I2C.h>

#define COMPASS_ADDRESS 60      //0x3C  Direction to Read    Write: 61 : 0x3D

#define COMPASS_CONFIG_REG_A 0
#define COMPASS_CONFIG_REG_B 1
#define COMPASS_MODE_REG 2
#define COMPASS_X_MSB_OUT_REG 3
#define COMPASS_X__LSB_OUT_REG 4
#define COMPASS_Y_OUT_REG 5
#define COMPASS_Y_OUT_REG 6
#define COMPASS_Z_OUT_REG 7
#define COMPASS_Z_OUT_REG 8
#define COMPASS_STATUS_REG 9
#define COMPASS_IDENTIFICATION_A_REG 10
#define COMPASS_IDENTIFICATION_B_REG 11
#define COMPASS_IDENTIFICATION_C_REG 12

//Definitions for ASPM, DOR, etc. Functions.
#define ASPM_REGION 159  //The two bits on 1 at their position, this is a A1 complement of the area to and
#define ASPM_1 0
#define ASPM_2 32
#define ASPM_4 64
#define ASPM_8 96

#define DOR_REGION 227
#define DOR_0_75_HZ 0
#define DOR_1_5_HZ 4
#define DOR_3_HZ 8
#define DOR_7_5_HZ 12
#define DOR_15_HZ 16    //DEFAULT
#define DOR_30_HZ 20
#define DOR_75_HZ 4

#define MCONFIF_AREA 252
#define MCONFIF_NORMAL 0
#define MCONFIF_POSITIVE 1
#define MCONFIF_NEGATIVE 2

#define GAIN_AREA 31
#define GAIN_1370 0
#define GAIN_1090 32
#define GAIN_820 64
#define GAIN_660 96
#define GAIN_440 128
#define GAIN_390 160
#define GAIN_330 192
#define GAIN_230 224

#define HS_AREA 127

#define MODE_AREA 252
#define MODE_CONTINUOUS 0
#define MODE_SINGLE 1   //DEFAULT
#define MODE_IDLE 2


class compass
{
private:
    int _d[3];  // 0: x, 1: y, 2: z
    
public:
    compass();
    ~compass();
    void init();
    //check for different register configuration values
    void setAveragedSamplesPerMeasurement(int val);     //ASPM
    void setDataOutputRate(int val);        //DOR
    void setMeasurementConfiguration(int val);      //MConfig
    void setGain(int val);
    void setHighSpeedI2cEnabled(bool en);
    void setOperationMode(int val);

    int getDX();
    int getDY();
    int getDZ();
    
    void clock();




};


#endif