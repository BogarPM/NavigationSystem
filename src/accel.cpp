#include<accel.h>
#include<I2C.h>
#include<Arduino.h>

accel::accel(){
    _intPin = -1;
}

accel::~accel(){

}

void accel::init(int intPin){
    _intPin = intPin;
    I2c.write(ADDRESS,PWR_MGMT_1,0);
    I2c.write(ADDRESS,CONFIG,0x00);
    I2c.write(ADDRESS,ACCEL_CONFIG,0x00);
    //I2c.write(ADDRESS,PWR_MGMT_1,0x30);
    I2c.write(ADDRESS, INT_ENABLE, 84);

}

int accel::getIntPin(){
    return _intPin;
    
}
    
void accel::setGyroSensitivity(int sens){

}

void accel::setAccelSensitivity(int sens){

}

int accel::getAccelX(){

}

int accel::getAccelY(){

}

int accel::getAccelZ(){

}

int accel::getGyroX(){

}

int accel::getGyroY(){

}

int accel::getGyroZ(){

}

int accel::getTemp(){

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
        _vals[0] /= 50;
        _vals[1] /= 50;
        _vals[2] /= 50;
        Serial.println(_vals[0]);
        Serial.println(_vals[1]);
        Serial.println(_vals[2]);
        Serial.println(_vals[3]);
        Serial.println(_vals[4]);
        Serial.println(_vals[5]);
        Serial.println(_vals[6]);
        Serial.println(" ");
    }else{
        Serial.println(res);
    }
    

}

void accel::setInterruptEnable(bool en){

}