#include <Encoder.h>
#include <Wire.h>
#include <MrYellow.h>


#define fwd_button 0
#define bwd_button 1
#define left_button 2
#define right_button 3
#define rightArm_button 4
#define leftArm_button 5
#define headCW 6
#define headCCW 7
#define face 8

//                fwd_button  bwd_button  left_button right_button  rightArm_button leftArm_button  headCW    headCCW   face
boolean buttons[]={0,            0,              0,       0,              0,            0,           0,       0,       0};
int temp=0;
int power=0;
boolean rightarm_status=false;
Encoder right_arm_enc1(RIGHT_MOTOR1_YELLOW,RIGHT_MOTOR1_BLUE);
Encoder right_arm_enc2(RIGHT_MOTOR2_YELLOW,RIGHT_MOTOR2_BLUE);
void setup()
{
Serial.begin(115200);
pinMode(RIGHT_MOTOR1_BLACK,OUTPUT);
pinMode(RIGHT_MOTOR1_WHITE,OUTPUT);
pinMode(RIGHT_MOTOR1_PWM,OUTPUT);
digitalWrite(RIGHT_MOTOR1_BLACK,LOW);
digitalWrite(RIGHT_MOTOR1_WHITE,LOW);
analogWrite(RIGHT_MOTOR1_PWM,100);

setModes();


}

void loop()
{


check_buttons(buttons);
/*
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
if(buttons[fwd_button]){
fwd(20);
delay(1000);

}

if(!buttons[fwd_button]){stop();}








}

