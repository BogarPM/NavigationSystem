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
    int _maxSpeed;
    int _speed;
    HBridge _bridge;
    bool _attached;
public:
    Motor();
    Motor(int u1, int u2, int en);
    ~Motor();
    void setup(int u,int en);
    int getSpeed();
    void stop();
    void setSpeed(int speed);
    void setDirection(bool dir);
    
    HBridge getBridge();
};




#endif