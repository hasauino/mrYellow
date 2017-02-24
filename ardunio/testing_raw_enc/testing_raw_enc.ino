#include <Encoder.h>

#define DIRA 12
#define DIRB 13
#define PWMA 3
#define PWMB 11
#define currentA A0
#define currentB A1

Encoder enc(18,22);

void setup() {
Serial.begin(9600);
pinMode(DIRA,OUTPUT);
pinMode(DIRB,OUTPUT);
pinMode(PWMA,OUTPUT);
pinMode(PWMB,OUTPUT);
}

void loop() {
digitalWrite(DIRA,LOW);  
analogWrite(PWMA,0);
}
