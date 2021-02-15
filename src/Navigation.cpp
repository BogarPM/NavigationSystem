#include<Navigation.h>
#include<Motor.h>
#include<Arduino.h>

Navigation::Navigation(){

    Serial.println("Navigation init");
}

Navigation::~Navigation(){

}

void Navigation::onLoop(){
    Serial.println("Navigation Loop");
}

void Navigation::setMotor(int u1, int u2, int en){
    

}

void Navigation::setupMotor(int motor, int u, int en){
    ////////////////////////////
    _motors[motor].setup(u,en);
}

void Navigation::control(int angle, int speed){ 
    //Make some complex calculous for finding each motor's speed and apply it
    for(int i = 0;i<MOTORS;i++){
        _motors[i].setSpeed(speed);
    }
}

void Navigation::setDirection(bool dir){
    for(int i = 0;i<MOTORS;i++){
        _motors[i].setDirection(dir);
    }
}

void Navigation::stop(){
    for(int i = 0;i<MOTORS;i++){
        _motors[i].stop();
    }
}

Motor Navigation::getMotor(int motor){
    if(motor <=3 && motor >=0){
        return _motors[motor];
    }else{
        
    }
}