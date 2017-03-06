#include <Arduino.h>
#include <Wire.h>
#define TWI_FREQ 37390L
#define DEVICE_ADDRESS 0x05
#define M1_MODE 0x44
#define M1_POWER 0x45
#define M2_MODE 0x47
#define M2_POWER 0x46
#define MODE 0x00//0x10
    #define POWER 7 
    #define FWD 7
    #define BWD 9
    #define LEFT 3
    #define RIGHT 4
    #define LEFT 3
    #define RIGHT_ARM 10
    #define LEFT_ARM 8
    #define HEAD_CW 1
    #define HEAD_CCW 2

//right motor is motor 1
//left motor is motor 2


void setModes(){
Wire.begin(); 
Wire.beginTransmission(DEVICE_ADDRESS);
Wire.write(M1_MODE); 
Wire.write(MODE); 
Wire.endTransmission(0);
delay(10);
Wire.begin(); 
Wire.beginTransmission(DEVICE_ADDRESS);
Wire.write(M2_MODE); 
Wire.write(MODE); 
Wire.endTransmission(0);
delay(10);
}

void motor1(int power){
if (power>100){power=100;}
if (power<-100){power=-100;}
Wire.beginTransmission(DEVICE_ADDRESS);
Wire.write(M1_POWER); 
Wire.write(power); 
Wire.endTransmission(0);}

void motor2(int power){
if (power>100){power=100;}
if (power<-100){power=-100;}
Wire.beginTransmission(DEVICE_ADDRESS);
Wire.write(M2_POWER); 
Wire.write(power); 
Wire.endTransmission(0);}


void fwd(int power){
if (abs(power)>100){power=100;}
motor1(abs(power));
motor2(abs(power));
}

void bwd(int power){
if (abs(power)>100){power=100;}
motor1(-abs(power));
motor2(-abs(power));
}

void left(int power){
if (abs(power)>100){power=100;}
motor1(abs(power));
motor2(-abs(power));
}

void right(int power){
if (abs(power)>100){power=100;}
motor1(-abs(power));
motor2(abs(power));
}

void stop(){
motor1(0);
motor2(0);
}
/*
boolean check_buttons(boolean buttons){
if(Serial.read()==123){
while(Serial.available()<1);
if(Serial.read()==55){
buttons[8]={0,0,0,0,0,0,0,0};
while(Serial.available()<1);
len=Serial.read();
while(Serial.available()<len);
for (int i=0;i<len;i++){
b[i]=Serial.read();
switch (b[i]) {
    case 0:
    fwd_button=0,bwd_button=0,left_button=0,right_button=0,rightArm_button=0,leftArm_button=0,headCW=0;headCCW=0;
    case FWD:
    fwd_button=1;
      break;
    case BWD:
    bwd_button=1;
      break;
    case LEFT:
    left_button=1;
      break;
    case RIGHT:
    right_button=1;
      break;
    case RIGHT_ARM:
    rightArm_button=1;
      break;        
    case LEFT_ARM:
    leftArm_button=1;
      break;  
    case HEAD_CW:
    headCW=1;
      break;
    case HEAD_CCW:
    headCCW=1;
      break;      
    default: 
    fwd_button=0,bwd_button=0,left_button=0,right_button=0,rightArm_button=0,leftArm_button=0,headCW=0;headCCW=0;
  }
}
}}

}

*/






