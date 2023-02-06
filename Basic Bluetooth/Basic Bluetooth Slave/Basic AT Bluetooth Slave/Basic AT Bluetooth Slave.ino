#include <SoftwareSerial.h>
                      //ARDUINO NANO
SoftwareSerial BTSerial(10, 11);  // For Software Serial, the Pin 10 will become RX and Pin 11 will become TX
#define ledpin 13              //built-in LED in UNO
#define Key 9
bool switchs=true;
void setup()
{
  pinMode(Key, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(Key, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
}

void loop() {
//if(BTSerial.available()) == it means that if your other partner/slave bluetooth send something in 
//BTSerial(thats BTSerial.write('G')) or RESPONDER line, this code will respond. thats (BTSerial.write(Z)) in other code.(around line 18-21)
  if(BTSerial.available()){ //ACTIVATER = to send signal
    //char x = BTSerial.read();
    if(switchs){
      BTSerial.write('Y'); //COMMANDS (we will write it on BTSerial communication. so basically, there is now "Y" within BTSerial line)
      switchs=false;
    }else{
      BTSerial.write('N');//COMANDS (we will write it on BTSerial communication. so basically, there is now "N" within BTSerial line)
      switchs=true;
    }
    delay(200);
  } 

//IF YOU WANT TO OUTPUT SOMETHING IN SERIAL OF YOUR BLUETOOTH APP
 // if(Serial.available()){
 //   char Y = BTSerial.read();
 //   BTSerial.write(Y);
//}
}
