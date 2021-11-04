#ifndef Navigation_h
#define Navigation_h

#include<Arduino.h>
#include<Motor.h>
#include<I2C.h>
#include<accel.h>
#include<position.h>
#include<protoCom.h>

#define MOTORS 2
#define MAX_ANGLE 45
#define COM Serial

#define T 50    //Sample Period in milliseconds
#define MIN_DELAY 5
#define RCV_DELAY 5

#define SEPARATOR ":\0"

//Commands for operating from Serial
#define ACCELERATE "a"
#define ANGLE "an\0"
#define STOP "s\0"
#define CONTROL "c\0"

//modes
#define MOTORS_X2 2     //This for 2 H bridges
                        //When this is selected; each two side motors are treaten as one
                        //Because it's just one H bridge

#define MOTORS_X4 4     //This for 4 H bridges

#define SAMPLE_PERIOD_MS 50
#define SAMPLE_PERIOD_US 50000




class Navigation
{
private:

    float _angPos = 0;
    protoCom _iface;
    //Variables used for step/impulse response
    long _stepInit = 0;         //Initial ms 
    bool _stepLatch = 1;
    bool _delaysteplatch = 0;   
    int _stepDelay = 0;         //Delay to execute fcn from time where called
    int _duration = 0;

    //Variables used for control algorithm execution
    long _lastMs = 0;

    uint8_t _debugPin = 13;
    bool _debugPinStat = 0;

    Motor _motors[2];

    accel _accel;
    position _position;

    int _angle = 0;
    int _speed = 0;

    int u1 = 0;
    int u2 = 0;

    void setU1(int val);
    void setU2(int val);

    int _mode = MOTORS_X2;  //2 H bridges as default

public:
    Navigation();
    ~Navigation();
    void initAccel();
    void onLoop();
    void updatePosition();
    void setupMotor(int motor, int u, int en);
    void setupMotor(int motor, int u1, int u2, int en);
    void control(int speed, int angle);
    void setDirection(bool dir);
    void stop();
    Motor getMotor(int motor);

    void step(int del,int duration);    //Duration in ms
    
    //Serial Control interface
    void process(char* str);

    //Navigation Position interface

    //Construction mode (Concept yet)
    void setMode(int mode);

    void setSpeed(int speed);
    void setSpeed(float speed);

    void setAngle(int angle);
    void setAngle(float angle);

    void displayData();

};



#endif