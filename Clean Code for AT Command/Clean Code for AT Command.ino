#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 4); // Pin A will become RX. insert HC-05 TX there, Pin B will become TX insert HC-05 RX there.

void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT); 
  digitalWrite(9,HIGH);
  Serial.println("Enter AT commands:");
  mySerial.begin(38400);
}

void loop(){
  if (mySerial.available()){
    Serial.write(mySerial.read());
  }
  if (Serial.available()){
    mySerial.write(Serial.read());
  }
}