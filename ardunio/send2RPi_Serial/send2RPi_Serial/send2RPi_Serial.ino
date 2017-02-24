void setup() {
Serial.begin(9600);
Serial3.begin(9600);
pinMode(16,OUTPUT);
pinMode(17,OUTPUT);
delay(1000);
digitalWrite(16,LOW);digitalWrite(17,HIGH);
}

void loop() {
if(Serial3.available()>0){
 Serial.write(Serial3.read()); 
  }
}
