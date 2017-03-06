//    #include <MrYellow.h>
//    #include <Wire.h>

    
    
    void setup()
    {
    Serial.begin(115200);
    Serial3.begin(115200);
    //setModes();
    }
    
    void loop()
    {
   // if(Serial.available()>0){
   // Serial3.write(Serial.read());}
    //Serial.println(Serial.read()); delay(100);
    //fwd(POWER); delay(1000);
    //stop(); delay(1000);
    //bwd(POWER); delay(1000);
    //stop(); delay(1000);
    //left(POWER); delay(1000);
    //stop(); delay(1000);
    //right(POWER); delay(1000);
    //stop(); delay(1000);
    if(Serial.available()>0){Serial3.write(Serial.read());}
    //Serial3.write(97); delay(1000);
    
    }
    

