#ifndef position_h
#define position_h

#include <string.h>

class position
{
private:
    //Positions obtained from Accelerometer
        //Todo: Define units
    

    

    //Positions obtained from gyroscope and magnetometer
    int _xAngle = 0;
    int _yAngle = 0;
    int _zAngle = 0;    //Angle measured with magnetometer

public:

    int _xPos = 0;
    int _yPos = 0;
    int _zPos = 0;
    
    int _speed[3];
    int _accel[3];

    position();
    ~position();

    int getXPos();
    int getYPos();
    int getZPos();

    void setXPos(int x);
    void setYPos(int y);
    void setZPos(int z);

    int getXAngle();
    int getYAngle();
    int getZAngle();

    void setXAngle(int x);
    void setYAngle(int y);
    void setZAngle(int z);

    void toC_str(char* str);
};

#endif