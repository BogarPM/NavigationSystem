#include<Motor.h>
#include<HBridge.h>
#include<globals.h>

Motor::Motor(){

}

Motor::Motor(int u1, int u2, int en){
    setup(u1, u2, en);
}

Motor::~Motor(){

}

void Motor::setup(int u1, int u2, int en){
    _bridge.setU1Pin(u1);
    _bridge.setU2Pin(u2);
    _bridge.setEnPin(en);
}

int Motor::getSpeed(){

}

void Motor::stop(){
    _bridge.stop();
}

void Motor::setSpeed(int speed){
    if(speed>0){

    }
    _bridge.setPWM(speed);
}

void Motor::setDirection(bool dir){
    _bridge.setDirection(dir);
}

HBridge Motor::getBridge(){

}