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

int Motor::getSpeed(){

}

void Motor::stop(){
    _bridge.stop();
}

void Motor::setSpeed(int speed){
    if(speed>0){
        setDirection(FORWARD);
    }else{
        setDirection(BACKWARD);
    }
    _bridge.setPWM(speed);
}

void Motor::setDirection(bool dir){
    //_bridge.setDirection(dir);
    if(dir == FORWARD){
        _bridge.setU1((bool)FORWARD);
    }else{
        _bridge.setU1((bool)BACKWARD);
    }
    _bridge.setDir(dir);
}

HBridge Motor::getBridge(){
    return _bridge;
}