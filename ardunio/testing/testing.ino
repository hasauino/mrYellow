#include <Encoder.h>
#include <PID_v1.h>

//White +   black -  (counter clockwise rotation)
#define DIRA 12
#define DIRB 13
#define PWMA 3
#define PWMB 11
#define currentA A0
#define currentB A1
#define Yellow 2
#define Blue 4
double Setpoint, Input, Output;
double Kp=0.10, Ki=0.050, Kd=.010;

Encoder enc(Yellow,Blue);
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, REVERSE);

void setup() {
Serial.begin(9600);
pinMode(DIRA,OUTPUT);
pinMode(DIRB,OUTPUT);
pinMode(PWMA,OUTPUT);
pinMode(PWMB,OUTPUT);

  //initialize the variables we're linked to
  Input = 0.0;
  Setpoint = 300.0;
    //turn the PID on
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-9.0, 9.0);
}


void loop()
{
  Input = enc.read()*0.5;
  myPID.Compute();
  motor(Output);
 // Serial.print(Output); Serial.print("     ");Serial.println(Input/2.0);

}

void motor(double voltage){
float  power=voltage*255.0/9.0;
if (power>0){digitalWrite(DIRA,HIGH);}
else{digitalWrite(DIRA,LOW);}
analogWrite(PWMA,abs(power));
}



