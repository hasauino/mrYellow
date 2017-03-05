#include <MrYellow.h>
#include <Wire.h>
  
void setup()
{
setModes();
}

void loop()
{
fwd(50); delay(1000);
stop(); delay(1000);
bwd(50); delay(1000);
stop(); delay(1000);
left(50); delay(1000);
stop(); delay(1000);
right(50); delay(1000);
stop(); delay(1000);

}


