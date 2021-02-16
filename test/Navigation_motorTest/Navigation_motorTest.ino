#include<Navigation.h>

Navigation nav;

int i = 0;
bool dir = 0;
int n = 3;

void setup() {
  
  nav.setupMotor(0,2,11);
  nav.setupMotor(1,4,3);
  nav.setupMotor(2,7,5);
  nav.setupMotor(3,8,6);
  nav.setDirection(dir);
  Serial.begin(9600);
}

void loop() {
  nav.control(0,i);
  nav.getMotor(0).setSpeed(-i);
  delay(50);
  i+=n;
  if(i>=255 || i<=0){
    //nav.stop();
    delay(1000);
    dir = !dir;
    nav.setDirection(dir);
    n*=-1;
  }
}
