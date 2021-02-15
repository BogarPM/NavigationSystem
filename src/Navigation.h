#ifndef Navigation_h
#define Navigation_h

#include<Arduino.h>
#include<Motor.h>

#define MOTORS 4


class Navigation
{
private:
    Motor _m1;
    Motor _m2;
    Motor _m3;
    Motor _m4;
    Motor _motors[4];

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

};



#endif