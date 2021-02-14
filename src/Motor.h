#ifndef Motor_h
#define Motor_h

#include<HBridge.h>
#include<globals.h>

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
    void setup(int u1,int u2,int en);
    int getSpeed();
    void stop();
    void setSpeed(int speed);
    void setDirection(bool dir);
    
    HBridge getBridge();
};




#endif