#ifndef HBridge_h
#define HBridge_h

#include<Arduino.h>

class HBridge
{
private:
    int _enPin;
    int _u1Pin;
    int _u2Pin;
    bool _enabled;
    bool _direction;

    void setU1(int val);
    void setU2(int val);

public:
    HBridge();
    HBridge(int u1, int u2, int en);   //u1 and u2 must be PWM Pins
    ~HBridge();

    void setU1Pin(int u1);
    void setU2Pin(int u1);
    void setEnPin(int en);

    void setEnabled(bool);
    void setDirection(bool dir);
    void setUValue(int val);

    void setU1(bool val);
    void setU2(bool val);
    void setPWM(int val);
    void stop();        //Or brack

};





#endif