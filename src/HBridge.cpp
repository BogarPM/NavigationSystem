#include<HBridge.h>
#include<Arduino.h>

HBridge::HBridge(){
    
}

HBridge::HBridge(int u1, int u2, int en){  //En be a PWM Pin
    _u1Pin = u1;
    _u2Pin = u2;
    _enPin = en;
    pinMode(_u1Pin, OUTPUT);
    pinMode(_u2Pin, OUTPUT);
    pinMode(_enPin, OUTPUT);
    Serial.println("init bridge");
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
    if(_direction){
        setU1(LOW);
        setU2(HIGH);
    }else{
        setU1(HIGH);
        setU2(LOW);
    }
}

void HBridge::setUValue(int val){
    if(_direction){
        setU2(val);
    }else{
        setU1(val);
    }
}

void HBridge::setU1(int val){
    digitalWrite(_u1Pin, val);
}

void HBridge::setU2(int val){
    digitalWrite(_u2Pin, val);
}

void HBridge::setPWM(int val){
    analogWrite(_enPin,val);
}