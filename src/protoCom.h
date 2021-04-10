#ifndef protoCom_h
#define protoCom_h

#include<Arduino.h>

#define END_CHAR ';'

#define BAUD_RATE 38400

typedef enum{   //Order to execute
    MOTOR1 = 0,
    MOTOR2 = 1,

    //Get the gyroscope actual reading
    GYROX = 2,
    GYROY = 3,
    GYROZ = 4,
    //Get the accelerometer actual reading
    ACCELX = 5,
    ACCELY = 6,
    ACCELZ = 7
} Order;

/*Format:


*/

class protoCom
{
private:
    uint8_t _buf[32];
    void func1Callback();

public:
    protoCom();
    ~protoCom();
    void listen();  //This function must be called once in loop


};





#endif