#include <Arduino.h>
#include <Wire.h>
#include <Encoder.h>

#define TWI_FREQ 37390L
#define DEVICE_ADDRESS 0x05
#define M1_MODE 0x44
#define M1_POWER 0x45
#define M2_MODE 0x47
#define M2_POWER 0x46
#define MODE 0x00//0x10
#define NONE 48
#define FWD 55
#define BWD 57
#define LEFT 51
#define RIGHT 52
#define RIGHT_ARM 65
#define LEFT_ARM 56
#define HEAD_CW 49
#define HEAD_CCW 50
#define FACE 102

//Buttons
//                fwd_button  bwd_button  left_button right_button  rightArm_button leftArm_button  headCW    headCCW   face
//boolean buttons[]={0,            0,              0,       0,              0,            0,           0,       0,       0};

#define fwd_button 0
#define bwd_button 1
#define left_button 2
#define right_button 3
#define rightArm_button 4
#define leftArm_button 5
#define headCW 6
#define headCCW 7
#define face 8



//right arm constants
#define RIGHT_MOTOR2_BLACK 26
#define RIGHT_MOTOR2_WHITE 28
#define RIGHT_MOTOR2_PWM 13
#define RIGHT_MOTOR2_YELLOW 19
#define RIGHT_MOTOR2_BLUE 22
#define RIGHT_MOTOR1_BLACK 32
#define RIGHT_MOTOR1_WHITE 34
#define RIGHT_MOTOR1_PWM 12
#define RIGHT_MOTOR1_YELLOW 18
#define RIGHT_MOTOR1_BLUE 30
#define RIGHT_MOTOR1_MAX 600

//left arm constants
#define LEFT_MOTOR2_BLACK 44
#define LEFT_MOTOR2_WHITE 46
#define LEFT_MOTOR2_PWM 10
#define LEFT_MOTOR2_YELLOW 2
#define LEFT_MOTOR2_BLUE 42
#define LEFT_MOTOR1_BLACK 38
#define LEFT_MOTOR1_WHITE 40
#define LEFT_MOTOR1_PWM 11
#define LEFT_MOTOR1_YELLOW 3
#define LEFT_MOTOR1_BLUE 36
#define LEFT_MOTOR1_MAX 1300



//Tetrix Motor controller
//right motor is motor 1 (base motors)
//left motor is motor 2 (base motors) 


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

 

void check_buttons(boolean * buttons){
	
if(Serial.read()==123){
while(Serial.available()<1);
if(Serial.read()==55){
for (int i=0;i<9;i++) {*(buttons+i)=0;}
while(Serial.available()<1);
int len=Serial.read();
byte b[len];
while(Serial.available()<len);
for (int i=0;i<len;i++){
b[i]=Serial.read();
switch (b[i]) {
    case NONE:
    for (int i=0;i<9;i++) {*(buttons+i)=0;}
    break;
    case FWD:
    *buttons=1;
      break;
    case BWD:
    *(buttons+1)=1;
      break;
    case LEFT:
    *(buttons+2)=1;
      break;
    case RIGHT:
    *(buttons+3)=1;
      break;
    case RIGHT_ARM:
    *(buttons+4)=1;
      break;        
    case LEFT_ARM:
    *(buttons+5)=1;
      break;  
    case HEAD_CW:
    *(buttons+6)=1;
      break;
    case HEAD_CCW:
   *(buttons+7)=1;
      break; 
    case FACE:
  *(buttons+8)=1;
      break; 
  // default: 
 // for (int i=0;i<9;i++) {*(buttons+i)=0;};
  }}}}

}



void right_up_2(int power,Encoder & enc){
analogWrite(RIGHT_MOTOR2_PWM,power);
digitalWrite(RIGHT_MOTOR2_BLACK,LOW);
digitalWrite(RIGHT_MOTOR2_WHITE,HIGH);
boolean cond=true;
long t0=millis();
while((enc.read()*-0.5)<90 && cond){  cond=(millis()-t0)<3000;  }
analogWrite(RIGHT_MOTOR2_PWM,0);
enc.write(90*-2);
}


void right_down_2(int power,Encoder & enc){
analogWrite(RIGHT_MOTOR2_PWM,power);
digitalWrite(RIGHT_MOTOR2_BLACK,HIGH);
digitalWrite(RIGHT_MOTOR2_WHITE,LOW);
boolean cond=true;
long t0=millis();
while((enc.read()*-0.5)>0 && cond){  cond=(millis()-t0)<3000;  }
analogWrite(RIGHT_MOTOR2_PWM,0);
enc.write(0);
}


void right_up_1(int power,Encoder & enc){
analogWrite(RIGHT_MOTOR1_PWM,power);
digitalWrite(RIGHT_MOTOR1_BLACK,HIGH);
digitalWrite(RIGHT_MOTOR1_WHITE,LOW);
boolean cond=true;
int prev=enc.read();

long t0=millis();
    while((enc.read())<RIGHT_MOTOR1_MAX && cond){  
    if ((millis()-t0)>100){
    if ((enc.read()-prev)>10 ){  cond=true; prev=enc.read(); t0=millis(); }
    else{cond = false; enc.write(RIGHT_MOTOR1_MAX+500);}   }
    }  
analogWrite(RIGHT_MOTOR1_PWM,0);
}


void right_down_1(int power,Encoder & enc){
analogWrite(RIGHT_MOTOR1_PWM,power);
digitalWrite(RIGHT_MOTOR1_BLACK,LOW);
digitalWrite(RIGHT_MOTOR1_WHITE,HIGH);
boolean cond=true;
int prev=enc.read();

long t0=millis();
    while((enc.read())>0 && cond){  
    if ((millis()-t0)>100){
    if (abs(enc.read()-prev)>10 ){  cond=true; prev=enc.read(); t0=millis(); }
    else{cond = false; enc.write(-1500);}   }
    }  
analogWrite(RIGHT_MOTOR1_PWM,0);
}


void left_up_2(int power,Encoder & enc){
analogWrite(LEFT_MOTOR2_PWM,power);
digitalWrite(LEFT_MOTOR2_BLACK,LOW);
digitalWrite(LEFT_MOTOR2_WHITE,HIGH);
boolean cond=true;
long t0=millis();
while((enc.read()*-0.5)<120 && cond){  cond=(millis()-t0)<3000;  }
analogWrite(LEFT_MOTOR2_PWM,0);
enc.write(120*-2);
}

void left_down_2(int power,Encoder & enc){
analogWrite(LEFT_MOTOR2_PWM,power);
digitalWrite(LEFT_MOTOR2_BLACK,HIGH);
digitalWrite(LEFT_MOTOR2_WHITE,LOW);
boolean cond=true;
long t0=millis();
while((enc.read()*-0.5)>0 && cond){  cond=(millis()-t0)<3000;  }
analogWrite(LEFT_MOTOR2_PWM,0);
enc.write(0);
}


void left_up_1(int power,Encoder & enc){
analogWrite(LEFT_MOTOR1_PWM,power);
digitalWrite(LEFT_MOTOR1_BLACK,HIGH);
digitalWrite(LEFT_MOTOR1_WHITE,LOW);
boolean cond=true;
int prev=enc.read();

long t0=millis();
    while((enc.read())<LEFT_MOTOR1_MAX && cond){  
    if ((millis()-t0)>100){
    if ((enc.read()-prev)>10 ){  cond=true; prev=enc.read(); t0=millis(); }
    else{cond = false; enc.write(LEFT_MOTOR1_MAX+500);}   }
    }  
analogWrite(LEFT_MOTOR1_PWM,0);
}


void left_down_1(int power,Encoder & enc){
analogWrite(LEFT_MOTOR1_PWM,power);
digitalWrite(LEFT_MOTOR1_BLACK,LOW);
digitalWrite(LEFT_MOTOR1_WHITE,HIGH);
boolean cond=true;
int prev=enc.read();

long t0=millis();
    while((enc.read())>0 && cond){  
    if ((millis()-t0)>100){
    if (abs(enc.read()-prev)>10 ){  cond=true; prev=enc.read(); t0=millis(); }
    else{cond = false; enc.write(-1500);}   }
    }  
analogWrite(LEFT_MOTOR1_PWM,0);
}

void arm_motors_init(){
pinMode(RIGHT_MOTOR1_BLACK,OUTPUT);
pinMode(RIGHT_MOTOR1_WHITE,OUTPUT);
pinMode(RIGHT_MOTOR1_PWM,OUTPUT);

pinMode(RIGHT_MOTOR2_BLACK,OUTPUT);
pinMode(RIGHT_MOTOR2_WHITE,OUTPUT);
pinMode(RIGHT_MOTOR2_PWM,OUTPUT);

pinMode(LEFT_MOTOR1_BLACK,OUTPUT);
pinMode(LEFT_MOTOR1_WHITE,OUTPUT);
pinMode(LEFT_MOTOR1_PWM,OUTPUT);

pinMode(LEFT_MOTOR2_BLACK,OUTPUT);
pinMode(LEFT_MOTOR2_WHITE,OUTPUT);
pinMode(LEFT_MOTOR2_PWM,OUTPUT);
	}


