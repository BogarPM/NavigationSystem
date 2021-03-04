#ifndef Navigation_h
#define Navigation_h

#include<Arduino.h>
#include<Motor.h>
#include<I2C.h>
#include<accel.h>
#include<position.h>

#define MOTORS 2
#define MAX_ANGLE 45
#define COM Serial

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
    Motor _motors[2];
    accel _accel;
    position _position;

    int _angle = 0;
    int _speed = 0;

    int _mode = MOTORS_X2;  //2 H bridges as default

public:
    Navigation();
    ~Navigation();
    void onLoop();
    void updatePosition();
    void setupMotor(int motor, int u, int en);
    void setupMotor(int motor, int u1, int u2, int en);
    void control(int angle, int speed);
    void setDirection(bool dir);
    void stop();
    Motor getMotor(int motor);
    
    //Serial Control interface
    void process(char* str);

    //Navigation Position interface

    //Construction mode (Concept yet)
    void setMode(int mode);

};



#endif