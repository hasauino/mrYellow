#include <Servo.h>
#include <Encoder.h>
#include <Wire.h>
#include <MrYellow.h>

unsigned long t0=0;
unsigned long t_buttons=0;
#define robotSpeed 20

//buttons array, it stores the state of each button, true means pressed, false means released. the "check_buttons()"
//function should be called to update the status of each button
//                fwd_button  bwd_button  left_button right_button  rightArm_button leftArm_button  headCW    headCCW   face	select_button	  start_button
boolean buttons[]={0,            0,              0,       0,              0,            0,           0,       0,       0,	0,	0};

//Encoder instances
Encoder right_arm_enc1(RIGHT_MOTOR1_YELLOW,RIGHT_MOTOR1_BLUE);
Encoder right_arm_enc2(RIGHT_MOTOR2_YELLOW,RIGHT_MOTOR2_BLUE);
Encoder left_arm_enc1(LEFT_MOTOR1_YELLOW,LEFT_MOTOR1_BLUE);
Encoder left_arm_enc2(LEFT_MOTOR2_YELLOW,LEFT_MOTOR2_BLUE);

//Servo instances
Servo headServo;
Servo faceServo;
Servo rightServo;
Servo leftServo;

int headAngle=HEAD_SERVO_MID;
unsigned long timeHead=0;

int rightAngle=RIGHT_SERVO_MAX;
unsigned long timeRight=0;

int leftAngle=LEFT_SERVO_MAX;
unsigned long timeLeft=0;
void setup()
{
Wire.begin();
Serial.begin(115200);//should be called here, the "check_buttons" uses the serial port to read serial message from RPi and update buttons' status
setModes();  //needed to control the base motors (initialization)
arm_motors_init();  //needed to control arms nxt motors (initialization)
headServo.attach(31);
faceServo.attach(33);
rightServo.attach(35);
leftServo.attach(37);

faceServo.write(FACE_SERVO_ZERO);
rightServo.write(RIGHT_SERVO_MAX);
leftServo.write(LEFT_SERVO_MAX);
headServo.write(HEAD_SERVO_MID);

t_buttons=millis();
}

void loop()
{
if(Serial.available()>0){t_buttons=millis();}
check_buttons(buttons);  //update buttons status

//Forward
if(buttons[fwd_button] && !buttons[left_button] && !buttons[right_button] && !buttons[select_button] && !buttons[start_button]) 
{fwd(robotSpeed); } 

//Backward  
if(buttons[bwd_button] && !buttons[left_button] && !buttons[right_button] && !buttons[select_button] && !buttons[start_button])
{ 
  if ((millis()-t0)>1000){bwd(robotSpeed); t0=millis();}
  
} 


//reset (turn motors off if no button is pressed)
if (!buttons[fwd_button] && !buttons[bwd_button] && !buttons[left_button] && !buttons[right_button]){
stop();  analogWrite(RIGHT_MOTOR1_PWM,0);
analogWrite(LEFT_MOTOR1_PWM,0); 
analogWrite(RIGHT_MOTOR2_PWM,0); analogWrite(LEFT_MOTOR2_PWM,0);
faceServo.write(FACE_SERVO_ZERO);
}



//left
if(buttons[left_button] && !buttons[leftArm_button] && !buttons[rightArm_button] && !buttons[select_button] && !buttons[start_button]){
if ((millis()-t0)>1000){left(robotSpeed); t0=millis();} }

//right
if(buttons[right_button] && !buttons[leftArm_button] && !buttons[rightArm_button] && !buttons[select_button] && !buttons[start_button]){right(robotSpeed); }


//rightArm motor1 up
if(buttons[rightArm_button] && buttons[headCW] && !buttons[select_button] && !buttons[start_button]) {
  analogWrite(RIGHT_MOTOR1_PWM,150);
digitalWrite(RIGHT_MOTOR1_BLACK,HIGH);
digitalWrite(RIGHT_MOTOR1_WHITE,LOW);
}


//rightArm motor1 down
if(buttons[rightArm_button] && buttons[headCCW] && !buttons[select_button] && !buttons[start_button]){
  analogWrite(RIGHT_MOTOR1_PWM,150);
digitalWrite(RIGHT_MOTOR1_BLACK,LOW);
digitalWrite(RIGHT_MOTOR1_WHITE,HIGH);
}


//leftArm motor1 up
if(buttons[leftArm_button] && buttons[headCW] && !buttons[select_button] && !buttons[start_button]){
  analogWrite(LEFT_MOTOR1_PWM,100);
digitalWrite(LEFT_MOTOR1_BLACK,HIGH);
digitalWrite(LEFT_MOTOR1_WHITE,LOW);
}

//leftArm motor1 down
if(buttons[leftArm_button] && buttons[headCCW] && !buttons[select_button] && !buttons[start_button]){
  analogWrite(LEFT_MOTOR1_PWM,100);
digitalWrite(LEFT_MOTOR1_BLACK,LOW);
digitalWrite(LEFT_MOTOR1_WHITE,HIGH);
}


//rightArm motor2 up
if(buttons[rightArm_button] && buttons[right_button] && !buttons[select_button] && !buttons[start_button]){
  analogWrite(RIGHT_MOTOR2_PWM,50);
digitalWrite(RIGHT_MOTOR2_BLACK,HIGH);
digitalWrite(RIGHT_MOTOR2_WHITE,LOW);
}

//rightArm motor2 down
if(buttons[rightArm_button] && buttons[left_button] && !buttons[select_button] && !buttons[start_button]){
  analogWrite(RIGHT_MOTOR2_PWM,50);
digitalWrite(RIGHT_MOTOR2_BLACK,LOW);
digitalWrite(RIGHT_MOTOR2_WHITE,HIGH);
}

//leftArm motor2 up
if(buttons[leftArm_button] && buttons[right_button] && !buttons[select_button] && !buttons[start_button]){
  analogWrite(LEFT_MOTOR2_PWM,50);
digitalWrite(LEFT_MOTOR2_BLACK,HIGH);
digitalWrite(LEFT_MOTOR2_WHITE,LOW);
}

//leftArm motor2 down
if(buttons[leftArm_button] && buttons[left_button] && !buttons[select_button] && !buttons[start_button]){
  analogWrite(LEFT_MOTOR2_PWM,50);
digitalWrite(LEFT_MOTOR2_BLACK,LOW);
digitalWrite(LEFT_MOTOR2_WHITE,HIGH);
}



//head CW
if(!buttons[rightArm_button] && !buttons[select_button] && !buttons[start_button] && !buttons[leftArm_button] && buttons[headCW] && !buttons[select_button] && !buttons[start_button]){
headServo.write(headAngle);
if (millis()-timeHead>50){headAngle++; timeHead=millis();}
if(headAngle>150){headAngle=150;}
}

//head CW
if(!buttons[rightArm_button] && !buttons[select_button] && !buttons[start_button] && !buttons[leftArm_button] && buttons[headCCW] && !buttons[select_button] && !buttons[start_button]){
headServo.write(headAngle);
if (millis()-timeHead>50){headAngle--; timeHead=millis();}
if(headAngle<50){headAngle=50;}
}

//right servo down
if(buttons[start_button] && buttons[bwd_button]){
rightServo.write(rightAngle);
if (millis()-timeRight>20){rightAngle--; timeRight=millis();}
if(rightAngle<RIGHT_SERVO_MIN){rightAngle=RIGHT_SERVO_MIN;}
}

//right servo up
if(buttons[start_button] && buttons[fwd_button]){
rightServo.write(rightAngle);
if (millis()-timeRight>20){rightAngle++; timeRight=millis();}
if(rightAngle>RIGHT_SERVO_MAX){rightAngle=RIGHT_SERVO_MAX;}
}


//left servo down
if(buttons[start_button] && buttons[headCCW]){
leftServo.write(leftAngle);
if (millis()-timeLeft>20){leftAngle--; timeLeft=millis();}
if(leftAngle<LEFT_SERVO_MIN){leftAngle=LEFT_SERVO_MIN;}
}

//left servo up
if(buttons[start_button] && buttons[headCW]){
leftServo.write(leftAngle);
if (millis()-timeLeft>20){leftAngle++; timeLeft=millis();}
if(leftAngle>LEFT_SERVO_MAX){leftAngle=LEFT_SERVO_MAX;}
}

//face ccw
if(buttons[start_button] && buttons[left_button]){
faceServo.write(80);}

//face cw
if(buttons[start_button] && buttons[right_button]){
faceServo.write(110);}



if ((millis()-t_buttons)>1000){
  for (int i=0;i<9;i++) {buttons[i]=0;}
  }
}
