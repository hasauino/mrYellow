#include <MrYellow.h>
#include <Wire.h>
//                fwd_button  bwd_button  left_button right_button  rightArm_button leftArm_button  headCW    headCCW   face
#define fwd_button 0
#define bwd_button 1
#define left_button 2
#define right_button 3
#define rightArm_button 4
#define leftArm_button 5
#define headCW 6
#define headCCW 7
#define face 8

boolean buttons[]={0,            0,              0,       0,              0,            0,           0,       0,       0};



void setup()
{
Serial.begin(115200);
Serial3.begin(115200);
setModes();

}

void loop()
{

check_buttons(buttons);
//Serial3.print(buttons[0]); delay(100);
if(buttons[fwd_button] && !buttons[left_button] && !buttons[right_button]){fwd(20);} 
if(buttons[bwd_button] && !buttons[left_button] && !buttons[right_button]){bwd(20);} 
if(buttons[left_button]){left(20);}
if(buttons[right_button]){right(20);}
if (!buttons[0] && !buttons[1] && !buttons[2] && !buttons[3]){stop();}

}

