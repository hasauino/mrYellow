#define TWI_FREQ 37390L
#include <Wire.h>

#define DEVICE_ADDRESS 0x05
#define M1_MODE 0x44
#define M1_POWER 0x45
#define M2_MODE 0x47
#define M2_POWER 0x46
#define MODE 0x00//0x10


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

  
void setup()
{
setModes();
}

void loop()
{
motor1(-100); motor2(-15);


}


