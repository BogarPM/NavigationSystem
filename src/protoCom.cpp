#include<Arduino.h>
#include<protocom.h>

protoCom::protoCom(){
    Serial.begin(38400);
}

protoCom::~protoCom(){

}

void protoCom::listen(){
    //Serial.println("asds");
    if(Serial.available()>0){
        delay(4);
        //String str = "";
        char cmd[16] = {};
        uint8_t i = 0;
        char c = Serial.read();
        while(Serial.available()>0){
            if(c == ';'){
                break;
            }
            cmd[i] = c;
            i++;
            c = Serial.read();
        }
        //Serial.println(cmd);
        //Serial.flush();
    }
}