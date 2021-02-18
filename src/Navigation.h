#ifndef Navigation_h
#define Navigation_h

#include<Arduino.h>
#include<Motor.h>
#include<I2C.h>
#include<accel.h>

#define MOTORS 4
#define MAX_ANGLE 45
#define COM Serial

#define SEPARATOR ":\0"


#define ACCELERATE "a"
#define ANGLE "an\0"
#define STOP "s\0"
#define CONTROL "c\0"



class Navigation
{
private:
    /*Motor _m1;
    Motor _m2;
    Motor _m3;
    Motor _m4;*/
    Motor _motors[4];
    accel _accel;

    int _angle = 0;
    int _speed = 0;

public:
    Navigation();
    ~Navigation();
    void onLoop();
    void setMotor(int u1, int u2, int en);
    void setupMotor(int motor, int u, int en);
    void control(int angle, int speed);
    void setDirection(bool dir);
    void stop();
    Motor getMotor(int motor);

    void process(char* str);

};



#endif