#include<HBridge.h>
#include<Arduino.h>
#include<math.h>

HBridge::HBridge(){
    _u1Pin = -1;
    _u2Pin = -1;
    _enPin = -1;
}

HBridge::HBridge(int u1, int u2, int en){  //En be a PWM Pin
    _u1Pin = u1;
    _u2Pin = u2;
    _enPin = en;
}

HBridge::~HBridge(){
    _u1Pin = -1;
    _u2Pin = -1;
    _enPin = -1;
}


void HBridge::setU1Pin(int u1){
    pinMode(_u1Pin, INPUT);
    _u1Pin = u1;
    pinMode(_u1Pin, OUTPUT);
}

void HBridge::setU2Pin(int u2){
    pinMode(_u2Pin, INPUT);
    _u2Pin = u2;
    pinMode(_u2Pin, OUTPUT);
}

void HBridge::setEnPin(int en){
    pinMode(_enPin, INPUT);
    _enPin = en;
    pinMode(_enPin, OUTPUT);
}

void HBridge::setEnabled(bool en){
    _enabled = en;
    digitalWrite(_enPin, _enabled);
}

void HBridge::setDirection(bool dir){
    _direction = dir;
}

void HBridge::setDir(bool dir){
    
}

void HBridge::setUValue(int val){
    if(_direction){
        setU2(val);
    }else{
        setU1(val);
    }
}


void HBridge::setPWM(int val){
    if(val > 0){
        _direction = 1;
        analogWrite(_u2Pin,0);
        analogWrite(_u1Pin,abs(val));
    }else{
        _direction = 0;
        analogWrite(_u1Pin,0);
        analogWrite(_u2Pin,abs(val));
    }
}

void HBridge::stop(){
    setPWM(0);
}