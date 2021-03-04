#include<Motor.h>
#include<HBridge.h>
#include<globals.h>

Motor::Motor(){
    _attached = false;
    _speed = 0;
    _maxSpeed = 0;
}

Motor::Motor(int u1, int u2, int en){
    setup(u1, en);
}

Motor::~Motor(){

}

void Motor::setup(int u, int en){
    _bridge.setU1Pin(u);
    //_bridge.setU2Pin(u2);
    _bridge.setEnPin(en);
    _attached = true;
}

void Motor::setup(int u1, int u2,int en){
    _bridge.setU1Pin(u1);
    _bridge.setU2Pin(u2);
    _bridge.setEnPin(en);
    _attached = true;
}

int Motor::getSpeed(){
    return _speed;
}

void Motor::stop(){
    _bridge.stop();
}

void Motor::setSpeed(int speed){    //here must be the value in rpm or something like that
    //Code for converting "stuff"
    _bridge.setPWM(speed);
}

void Motor::setDirection(bool dir){
    
}

void Motor::setMaxSpeed(int max){
    _maxSpeed = max;
}

HBridge Motor::getBridge(){
    return _bridge;
}