#include<Navigation.h>
#include<Motor.h>
#include<Arduino.h>
#include<I2C.h>
#include<accel.h>

Navigation::Navigation(){
    I2c.begin();
    _accel.init(9);
}

Navigation::~Navigation(){

}

void Navigation::onLoop(){
    _accel.clock();
    //Serial.println("Navigation Loop");
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

void Navigation::process(char* str){        //Format:  cmd:val

    int val = 0;
    char* cmd = strtok(str,SEPARATOR);
    val = atoi(strtok(NULL,SEPARATOR));
    //Compare Strings
    if(strcmp(cmd,ACCELERATE)==0){
        _speed = val;
        if(val > 254){
            _speed = 254;
        }else if(val < -254){
            _speed = -254;
        }
        control(_angle,_speed);
    }else if(strcmp(cmd,STOP)==0){
        stop();
    }else if(strcmp(cmd,ANGLE)==0){
        if(val > MAX_ANGLE){
            _angle = MAX_ANGLE;
        }else if(val < -MAX_ANGLE){
            _angle = -MAX_ANGLE;
        }
        control(_angle, _speed);
    }
    val = atoi(strtok(NULL, SEPARATOR));

    

}