#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX
int flag=0;
String input="";
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
 if(Serial.available() > 0){//Read from serial monitor and send over HC-12
   while(flag==0)
    {  
      input = Serial.readString();
      flag=1;
    }
    mySerial.flush();
    mySerial.println(input);
    delay(1000);
    flag=0;
    
    if(input == "Pit+Check")
    {
      long start = millis();
      delay(100);
      String temp = mySerial.readString();
      Serial.print("Check :");
      Serial.println(temp);
      if(temp == "hw")
      {
        Serial.print("GOT IN:"); 
        Serial.println(millis() - start);
      }
      else
      {
        Serial.println("Data Corrupted!!: ");
        Serial.println(temp);
        Serial.print("GOT IN:"); 
        Serial.println(millis() - start);
      }
    }       
  }
}
 
 
