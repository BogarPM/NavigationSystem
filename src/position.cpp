#include<position.h>
#include <string.h>

position::position(){

}

position::~position(){

}

int position::getXPos(){
    return _xPos;
}

int position::getYPos(){
    return _yPos;
}

int position::getZPos(){
    return _zPos;
}

void position::setXPos(int x){
    _xPos = x;
}

void position::setYPos(int y){
    _yPos = y;
}

void position::setZPos(int z){
    _zPos = z;
}

int position::getXAngle(){
    return _xAngle;
}

int position::getYAngle(){
    return _yAngle;
}

int position::getZAngle(){
    return _zAngle;
}

void position::setXAngle(int x){
    _xAngle = x;
}

void position::setYAngle(int y){
    _yAngle = y;
}

void position::setZAngle(int z){
    _zAngle = z;
}

void position::toC_str(char* str){
    
}