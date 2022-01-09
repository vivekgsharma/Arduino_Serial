#include<SoftwareSerial.h>

int horn=3,led=4;

char rd;
 SoftwareSerial mySerial(10,11); // Rx, Tx
void setup() {
  Serial.begin(9600);
  mySerial.begin(57600); // data rate for software serial port
  pinMode(horn ,OUTPUT);
  pinMode(led ,OUTPUT);

  while(!mySerial)
   { ; // do nothing 
    }
  }

void loop() {
 // if(Serial.available())
  // {
   // rd= Serial.read();
   // myserial.print(rd);
   //}
   
  if (mySerial.available()==1)
  
    {
      // int flag=0;
      String val= mySerial.readString();
      
      String temp="";
     // int n=val.size();
      for(int i=0;i<4;i++)
         temp+=val[i];
        int vehicle_speed =(temp[1]-'0') *100 + (temp[2]-'0')*10 +(temp[3]-'0') ;
        
        if(temp[0]=='+' &&  vehicle_speed>=4)
         { //flag=1;
           Serial.print("Alert Sent\n");
          digitalWrite(horn,HIGH);
          digitalWrite(led,HIGH);
          delay(10000);
          digitalWrite(led,LOW);
          digitalWrite(horn,LOW);
          delay(10000);
         }
         
          
      Serial.println(temp);
     // if(flag)
      //Serial.print("Alert Sent\n");
      ///Serial.print("\n");
    }

    }



/* 
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(38400);
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
} 

*/
