#ifndef HBridge_h
#define HBridge_h

#include<Arduino.h>
#include<math.h>

class HBridge
{
private:
    int _enPin = -1;
    int _u1Pin = -1;
    int _u2Pin = -1;
    bool _enabled;
    bool _direction;

public:
    HBridge();
    HBridge(int u1, int u2, int en);   //u1 and u2 must be PWM Pins
    ~HBridge();

    void setU1Pin(int u1);
    void setU2Pin(int u1);
    void setEnPin(int en);


    void setEnabled(bool);
    void setDirection(bool dir);
    void setDir(bool dir);
    void setUValue(int val);

    void setU1(bool val);
    void setU2(bool val);
    void setPWM(int val);   //Max value: 254, min: -254
    void stop();        //Or brack
    

};





#endif