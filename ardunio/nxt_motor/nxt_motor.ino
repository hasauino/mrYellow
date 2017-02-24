#include <Encoder.h>


//White +   black -  (counter clockwise rotation)
#define DIRA 12
#define DIRB 13
#define PWMA 3
#define PWMB 11
#define currentA A0
#define currentB A1
#define Yellow 2
#define Blue 4


Encoder enc(Yellow,Blue);

float i=0;
void setup() {
Serial.begin(9600);
pinMode(DIRA,OUTPUT);
pinMode(DIRB,OUTPUT);
pinMode(PWMA,OUTPUT);
pinMode(PWMB,OUTPUT);

}


void loop()
{

motorA(0.0,enc);
delay(2000);
motorA(90.0,enc);
delay(2000);
}

void motorA(float pos,Encoder enc){
analogWrite(PWMA,0);
if((pos-enc.read()*0.5)>0.0){ digitalWrite(DIRA,LOW);}
else{ digitalWrite(DIRA,HIGH);}

  while(abs(pos-enc.read()*.5)>5){analogWrite(PWMA,100);}
 analogWrite(PWMA,0); 
}




