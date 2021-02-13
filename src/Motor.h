#ifndef Motor_h
#define Motor_h

#include<HBridge.h>

class Motor
{
private:
    int _maxSpeed;
    int _speed;
    HBridge _bridge;
    bool _attached;
public:
    Motor(int en, int u1, int u2);
    ~Motor();
    int getSpeed();
    void stop();
    void setSpeed(int speed);
    
    HBridge getBridge();
};




#endif