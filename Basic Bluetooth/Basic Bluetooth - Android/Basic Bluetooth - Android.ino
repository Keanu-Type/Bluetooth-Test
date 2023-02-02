//Devices: Android Phone, Arduino UNO R3, HC-05, Sg90 Servo, 2.2K Resistor, 4.7K Resistor. 

//NOTE: IF YOU ARE GOING TO USE SOFTWARESERIAL, USE DIFFERENT RX AND TX.
//NOTE: HC-05 TX -> ARDUINO RX & HC-05 RX ->ARDUINO TX. COMMON MISTAKE TO CONNECT TX -> TX etc.
//NOTE: USE VOLTAGE DIVIDER WITH 2.2K RESISTOR AND 4.7K RESISTOR(SEE DIAGRAM) FOR SOFTWARESERIAL SETUP
//      PROCEDURE WHEN USING:
//           1. Construct the circuit first(see diagram). Then power your Arduino(by battery or usb/laptop). Your HC-05 will blink intense
//           2. Open and use your phone. download Bluetooth Serial Terminal(or other alternative) from Playstore and install.
//           3. Turn on your Bluetooth from your phone, scan for HC-05, then connect with it. password is 1234(if asked)
//              NOTE: do note that if it is successful, it will only "PAIRED" with the device. Not "CONNECTED" yet. so being PAIRED is enough.
//           4.Open your Bluetooth Terminal App. Find the Option where you will select Paired Device to connect with. Connect to HC-05
//           5. It should Connect if it is successful. your HC-05 should stop blinking.
//           NOW YOUR HC-05 IS CONNECTED

//KEANU P. BERCHES
//PSWD: ARDUINO
#include <SoftwareSerial.h>       
#include <Servo.h>
Servo BTServo;
SoftwareSerial BTSerial(10, 11);  // For Software Serial, the Pin 10 will become RX and Pin 11 will become TX
#define ledpin 13              //built-in LED in UNO

void setup() {
  BTServo.attach(A0);         //SERVO
  pinMode(ledpin, OUTPUT);    //LED
  digitalWrite(ledpin, LOW);  //L is OFF  
  Serial.begin(9600);         //SOFTWARE SERIALNAME.BEGIN(FREQUENCY)
  BTSerial.begin(9600);
  BTServo.write(0);           //SET YOUR SERVO TO 0 ANGLE
}

void loop() {
  if (BTSerial.available()) { //IF BLUETOOTH IS CONNECTED TO A DEVICE/ RUN THE CODE. ELSE NONE.
    char x = BTSerial.read(); //READ THE DATA THAT COULD BE RECEIVED FROM THE DEVICE. ONLY CHAR. ONLY 1 CHAR WILL BE RECEIVED PER LOOP IF YOU SENT A STRING
    if (x =='S') {           //S = SERVO. IF THE USER SENT S THE SERVO WILL SPIN
      //SERVO LEFT TO RIGHT, RIGHT TO LEFT
      for (int i=0; i<180; i++){
        BTServo.write(i);
        delay(10);
      }
      for (int i=180; i>0; i--){
        BTServo.write(i);
        delay(10);
      }
    //FOR ON/OFF of BUILTIN LED
    }else if(x=='1'){
      digitalWrite(ledpin, HIGH);
    }else if(x=='0'){
      digitalWrite(ledpin, LOW);
    }
  }
  if (Serial.available()) { //IF SERIAL IS AVAILABLE(WHICH IS ON)
    char c = Serial.read(); //THIS WILL READ WHAT WAS THE DATA THAT WAS SENT FROM DEVICE
    BTSerial.write(c); //THIS WILL OUTPUT CHAR
  }
  //NOTE: SERIAL.AVAILABLE AND BTSERIAL.AVAILABLE RUNS AT THE SAME TIME.
}