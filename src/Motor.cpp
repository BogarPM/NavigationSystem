#include<Motor.h>
#include<HBridge.h>
#include<globals.h>

Motor::Motor(){
    _attached = false;
    _type = 0;
    _speed = 0;
    _maxSpeed = 0;
}

Motor::Motor(int u1, int en){
    _type = 0;
    _speed = 0;
    _maxSpeed = 0;
    setup(u1, en);
}

Motor::Motor(int u1, int u2, int en){
    _type = 1;
    _speed = 0;
    _maxSpeed = 0;
    setup(u1, u2, en);
}

Motor::~Motor(){

}

//This for single direction
void Motor::setup(int u, int en){
    _type = 0;
    _bridge.setU1Pin(u);
    //_bridge.setU2Pin(u2);
    _bridge.setEnPin(en);
    _attached = true;
}
//Setup for dual direction motor
void Motor::setup(int u1, int u2,int en){
    _type = 1;
    _bridge.setU1Pin(u1);
    _bridge.setU2Pin(u2);
    _bridge.setEnPin(en);
    setEnabled(1);
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

bool Motor::isAttached(){
    return _attached;
}

HBridge Motor::getBridge(){
    return _bridge;
}

void Motor::setEnabled(bool en){
    _bridge.setEnabled(en);
}