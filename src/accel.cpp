#include<accel.h>
#include<I2C.h>
#include<Arduino.h>

accel::accel(){
    _intPin = -1;
}

accel::~accel(){

}

bool accel::init(int intPin){
    _intPin = intPin;
    uint8_t sta = I2c.write(ADDRESS,PWR_MGMT_1,0);
    if(sta != 56){
        I2c.write(ADDRESS,CONFIG,0x00);
        I2c.write(ADDRESS,ACCEL_CONFIG,0x00);
        //I2c.write(ADDRESS,PWR_MGMT_1,0x30);
        I2c.write(ADDRESS, INT_ENABLE, 84);
        _connected = 1;
        return 1;
    }
    return 0;
}

int accel::getIntPin(){
    return _intPin;
    
}

bool accel::connected(){
    return _connected;
}
    
void accel::setGyroSensitivity(int sens){
    I2c.write(ADDRESS,ACCEL_CONFIG,sens<<4);
}

void accel::setAccelSensitivity(int sens){

}

float accel::getAccelX(){
    return _vals[0]/ACCEL_SCALAR_2G;
}

int accel::getRawAccelX(){
    return _vals[0];
}

int accel::getRawAccelY(){
    return _vals[1];
}

float accel::getAccelY(){
    return _vals[1]/ACCEL_SCALAR_2G;
}

int accel::getRawAccelZ(){
    return _vals[2];
}

float accel::getAccelZ(){
    return _vals[2]/ACCEL_SCALAR_2G;
}

int accel::getRawGyroX(){
    return _vals[4];
}

float accel::getGyroX(){
    return _vals[4];
}

int accel::getRawGyroY(){
    return _vals[5];
}

float accel::getGyroY(){
    return _vals[5];
}

int accel::getRawGyroZ(){
    return _vals[6];
}

float accel::getGyroZ(){
    return _vals[6];
}

int accel::getTemp(){
    return _vals[3];
}

void accel::clock(){
    uint8_t res = I2c.read(ADDRESS,ACCEL_XOUT_H,14); //read 14 bytes (x,y,z) from the device
    if(res==0){
        _vals[0] = I2c.receive() << 8;
        _vals[0] |= I2c.receive();
        _vals[1] = I2c.receive() << 8;
        _vals[1] |= I2c.receive();
        _vals[2] = I2c.receive() << 8;
        _vals[2] |= I2c.receive();
        _vals[3] = I2c.receive() << 8;
        _vals[3] |= I2c.receive();
        _vals[4] = I2c.receive() << 8;
        _vals[4] |= I2c.receive();
        _vals[5] = I2c.receive() << 8;
        _vals[5] |= I2c.receive();
        _vals[6] = I2c.receive() << 8;
        _vals[6] |= I2c.receive();
        /*_vals[0] /= 50;
        _vals[1] /= 50;
        _vals[2] /= 50;*/
        
    }else{
        
    }
    

}

void accel::setInterruptEnable(bool en){

}

void accel::log(){
    Serial.write(_vals[0]);
    Serial.write(_vals[0]>>8);
    //Serial.println(_vals[1]);
    //Serial.println(_vals[2]);
    //Serial.println(_vals[3]);
    //Serial.println(_vals[4]);
    //Serial.println(_vals[5]);
    //Serial.println(_vals[6]);
    //Serial.println(" ");
}