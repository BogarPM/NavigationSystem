#ifndef Motor_h
#define Motor_h

#include<HBridge.h>
#include<globals.h>

//Define physical caracteristics of the motor and wheel
#define maxSpeed 260    //RPM
#define WheelDiameter 65    //mm



class Motor
{
private:
    uint16_t _maxSpeed;
    int _speed;
    HBridge _bridge;
    bool _attached = 0;
    bool _type = 0;      //0 for single, 1 for compound
public:
    Motor();
    Motor(int u1, int en);
    Motor(int u1, int u2, int en);
    ~Motor();
    void setup(int u,int en);   //this function is used when pwm is input at En pin:  Single motor
    void setup(int u1, int u2,int en);   //And this is used when pwm in input into the u pins
    int getSpeed();
    void stop();
    void setSpeed(int speed);
    void setDirection(bool dir);

    void setMaxSpeed(int max);
    bool isAttached();
    void setEnabled(bool en);
    
    HBridge getBridge();
};




#endif