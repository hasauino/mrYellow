#include <Servo.h>
#include <Encoder.h>
#include <Wire.h>
#include <MrYellow.h>

#define FACE_SERVO_ZERO 95
#define RIGHT_SERVO_MIN 30
#define RIGHT_SERVO_MAX 70
#define LEFT_SERVO_MIN 30
#define LEFT_SERVO_MAX 70
#define HEAD_SERVO_MID 100


//buttons array, it stores the state of each button, true means pressed, false means released. the "check_buttons()"
//function should be called to update the status of each button
//                fwd_button  bwd_button  left_button right_button  rightArm_button leftArm_button  headCW    headCCW   face
boolean buttons[]={0,            0,              0,       0,              0,            0,           0,       0,       0};

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


void setup()
{
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
}

void loop()
{
headServo.write(100);



/*
check_buttons(buttons);

if(buttons[fwd_button] && !buttons[left_button] && !buttons[right_button]){fwd(20);} 
if(buttons[bwd_button] && !buttons[left_button] && !buttons[right_button]){ bwd(20);} 
if(buttons[left_button]){left(20);}
if(buttons[right_button]){right(20);}
if (!buttons[0] && !buttons[1] && !buttons[2] && !buttons[3]){stop();  analogWrite(RIGHT_MOTOR1_PWM,0); analogWrite(LEFT_MOTOR1_PWM,0); analogWrite(RIGHT_MOTOR2_PWM,0); analogWrite(LEFT_MOTOR2_PWM,0); }

if(buttons[rightArm_button] && buttons[headCW]){
  analogWrite(RIGHT_MOTOR1_PWM,100);
digitalWrite(RIGHT_MOTOR1_BLACK,HIGH);
digitalWrite(RIGHT_MOTOR1_WHITE,LOW);
}

if(buttons[rightArm_button] && buttons[headCCW]){
  analogWrite(RIGHT_MOTOR1_PWM,100);
digitalWrite(RIGHT_MOTOR1_BLACK,LOW);
digitalWrite(RIGHT_MOTOR1_WHITE,HIGH);
}


if(buttons[leftArm_button] && buttons[headCW]){
  analogWrite(LEFT_MOTOR1_PWM,100);
digitalWrite(LEFT_MOTOR1_BLACK,HIGH);
digitalWrite(LEFT_MOTOR1_WHITE,LOW);
}

if(buttons[leftArm_button] && buttons[headCCW]){
  analogWrite(LEFT_MOTOR1_PWM,100);
digitalWrite(LEFT_MOTOR1_BLACK,LOW);
digitalWrite(LEFT_MOTOR1_WHITE,HIGH);
}

*/




}

