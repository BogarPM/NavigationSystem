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

void Navigation::setupMotor(int motor, int u1, int u2, int en){
    if(motor==1){
        _m1.setup(u1, u2, en);
    }else if(motor == 2){
        _m2.setup(u1, u2, en);
    }else if(motor == 2){
        _m3.setup(u1, u2, en);
    }else{
        _m4.setup(u1, u2, en);
    }
}

void Navigation::control(int angle, int speed){
    _m1.setSpeed(speed);
}