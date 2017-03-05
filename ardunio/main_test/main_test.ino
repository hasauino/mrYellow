#include <MrYellow.h>
#include <Wire.h>
#define POWER 7  
void setup()
{
Serial.begin(9600);
//setModes();
}

void loop()
{
if(Serial.read()==123){
while(Serial.read()!=55); 

while(Serial.){}  
}
//Serial.println(Serial.read()); delay(100);
//fwd(POWER); delay(1000);
//stop(); delay(1000);
//bwd(POWER); delay(1000);
//stop(); delay(1000);
//left(POWER); delay(1000);
//stop(); delay(1000);
//right(POWER); delay(1000);
//stop(); delay(1000);

}


