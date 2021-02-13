#include<HBridge.h>
#include<Arduino.h>

HBridge::HBridge(int u1, int u2, bool en){  //u1 and u2 must be PWM Pins
    _u1Pin = u1;
    _u2Pin = u2;
    _enPin = en;
    pinMode(_u1Pin, OUTPUT);
    pinMode(_u2Pin, OUTPUT);
    pinMode(_enPin, OUTPUT);
}
HBridge::~HBridge(){
    _u1Pin = 0;
    _u2Pin = 0;
    _enPin = 0;
}

HBridge::void setU1Pin(int u1){
    pinMode(_u1Pin, INPUT);
    _u1Pin = u1;
    pinMode(_u1Pin, OUTPUT);
}

HBridge::void setU2Pin(int u2){
    pinMode(_u2Pin, INPUT);
    _u2Pin = u2;
    pinMode(_u2Pin, OUTPUT);
}

HBridge::void setEnPin(int en){
    pinMode(_enPin, INPUT);
    _enPin = en;
    pinMode(_enPin, OUTPUT);
}

HBridge::void setEnabled(bool en){
    _enabled = en;
    digitalWrite(_enPin, _enabled);

}

HBridge::void setDirection(bool dir){
    _direction = dir;
    if(_direction){
        setU1(0);
    }else{
        setU2(0);
    }
}

HBridge::void setUValue(int val){
    if(_direction){
        setU2(val);
    }else{
        setU1(val);
    }
}

HBridge::setU1(int val){
    analogWrite(_u1Pin, val);
}

HBridge::setU2(int val){
    analogWrite(_u2Pin, val);
}