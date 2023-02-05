//Note: Master and Slave must have same password
//Note: Master HC-05 won't get paired to other device for some reason
//      to unpair, enter to AT Mode by wiring EN pin to 5V along with HC-05's VCC pin.
//      enter to Serial Monitor 9600 or 38400. use this code instead: 
//      upload that then enter this following commands: AT+ORGL
//      AT+ORGL will reset everything. including HC-05 Name, Password, Status, and paired device. use only when in trouble
//      See more AT Commands here: https://s3-sa-east-1.amazonaws.com/robocore-lojavirtual/709/HC-05_ATCommandSet.pdf
#include <SoftwareSerial.h>
                      //ARDUINO UNO
SoftwareSerial BTSerial(2, 4);  // For Software Serial, the Pin 10 will become RX and Pin 11 will become TX
#define ledpin 13               //built-in LED in UNO
#define Key 9
int timer = 200;
void setup()
{
  pinMode(Key, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(Key, HIGH);
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);  // HC-05 default speed in AT command more

}

void loop() {
  // put your main code here, to run repeatedly:
//We will need this BTSerial.write('G') so we can activate/run the ACTIVATER line. so we can receive some kind of signal
  BTSerial.write('G'); //RESPONDER
  if(BTSerial.available()){ //time to receive COMMANDS. since the other code sent "Y" or "N" in BTSerial line, we will access BTSerial line and see what char/variable is in that server/line
    char receive = BTSerial.read();
    if(receive=='Y'){
      digitalWrite(ledpin, HIGH);
    }else if(receive=='N'){
      digitalWrite(ledpin, LOW);
    }
  } 
//IF YOU WANT TO OUTPUT SOMETHING IN SERIAL OF YOUR BLUETOOTH APP
 // if(Serial.available()){
 //   char Y = BTSerial.read();
 //   BTSerial.write(Y);
 // }
}