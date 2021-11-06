#include<Navigation.h>
#include<Motor.h>
#include<Arduino.h>
#include<I2C.h>
#include<accel.h>
#include<parameters.h>
#include<protoCom.h>

Navigation::Navigation(){
    I2c.begin();
    pinMode(_debugPin,OUTPUT);
    digitalWrite(_debugPin,_debugPinStat);
}

Navigation::~Navigation(){
    
}

void Navigation::initAccel(){
    _accel.init(2);
}

void Navigation::setU1(int val){
    _motors[0].setSpeed(val);
}

void Navigation::setU2(int val){
    _motors[1].setSpeed(val);
}

void Navigation::onLoop(){
    long actMill = millis();
    if(_accel.connected()){_accel.clock();}
    _iface.listen();
    /*u1+=2;
    u2+=2;
    _motors[0].setSpeed(u1);
    _motors[1].setSpeed(u2);*/




    //////////////////////////////////////////
    //This code is for the Algorithm execution
    if(actMill - _lastMs >= T){
        _debugPinStat = !_debugPinStat;
        digitalWrite(_debugPin,_debugPinStat);
        //Algorithm goes here
        _accel.log();
        _lastMs = actMill;
    }
    //////////////////////////////////////////
    if(actMill - _stepInit > _duration + _stepDelay && !_stepLatch){    //These functions are used for Unit Step response Function
        setU1(0);
        setU2(0);
        _stepLatch = 1;
    }
    if(actMill >= _stepInit + _stepDelay && _delaysteplatch){
        setU1(255);
        setU2(-255);
        _delaysteplatch = 0;
    }
}

void Navigation::updatePosition(){
    int accel = _accel.getAccelX()/ACCEL_SCALAR_2G;
    //integrate this using last position data with x axis
    _position._speed[0] += accel*1000/SAMPLE_PERIOD_MS;
    _position._xPos += _position._speed[0]*1000/SAMPLE_PERIOD_MS;
    Serial.println(accel);
    Serial.println(_position._speed[0]);
    Serial.println(_position._xPos);
    Serial.println("");
    _position._accel[0] = accel;
}

void Navigation::setupMotor(int motor, int u, int en){
    ////////////////////////////
    _motors[motor].setup(u,en);
}

void Navigation::setupMotor(int motor, int u1, int u2, int en){
    ////////////////////////////
    _motors[motor].setup(u1,u2,en);
}

void Navigation::control(int speed, int angle){ 
    //Make some complex calculous for finding each motor's speed and apply it
    for(int i = 0;i<MOTORS;i++){
        if(i == 0){
            _motors[i].setSpeed(-speed);
        }else{
            _motors[i].setSpeed(speed);
        }
    }
}

void Navigation::setDirection(bool dir){
    for(int i = 0;i<MOTORS;i++){
        if(_motors[i].isAttached()){
            _motors[i].setDirection(dir);
        }
        
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

void Navigation::step(int del, int duration){
    if(_stepLatch){
        _stepInit = millis();
        _stepLatch = 0;
        _delaysteplatch = 1;
        _stepDelay = del;
        _duration = duration;
    }
}





void Navigation::process(char* str){        //Format:  cmd:val
    
    int val = 0;
    //Serial.println(str);
    char* cmd = strtok(str,SEPARATOR);
    val = atoi(strtok(NULL,SEPARATOR));
    Serial.print("C_STR:  ");
    Serial.println(str);
    
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

void Navigation::setMode(int mode){

}

void Navigation::setSpeed(int speed){   //Open Loop; -255 - 255 values
    for(int i = 0;i<2;i++){
        _motors[i].setSpeed(speed);
    }
}

void Navigation::setSpeed(float speed){
    if(speed <= MOTORS_MAX_SPEED){

    }
}

void Navigation::setAngle(int angle){

}

void Navigation::setAngle(float angle){

}

void Navigation::displayData(){
    Serial.println("Accel Raw data:");
    Serial.print("X: ");
    Serial.println(_accel.getGyroX());
    Serial.print("  Y: ");
    Serial.print(_accel.getGyroY());
    Serial.print("  Z: ");
    Serial.println(_accel.getGyroZ());
}
