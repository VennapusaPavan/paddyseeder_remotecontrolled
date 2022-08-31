#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial HC12(10, 11);

int backword_forward;
int left_clutch;
int right_clutch;
int potensiometer_speedcontrol;
int lowering_mechanism=2;
int low_mechanism;
void setup()
{ 
HC12.begin(9600);
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(lowering_mechanism,INPUT);

}
void loop()
{
  delay(1000);

       backword_forward = analogRead(A0);

       left_clutch= analogRead(A1);
       
       right_clutch = analogRead(A3);
       
       int potval = analogRead(A2);
       potensiometer_speedcontrol=map(potval,0,1023,0,255);

       int val = digitalRead (lowering_mechanism) ;
       
            if (val == HIGH)
              {
                low_mechanism=1; 
              }
            else
              {
                low_mechanism=0
              }
       

HC12.print(backword_forward);
HC12.print("A");
HC12.print(left_clutch);
HC12.print("B");
HC12.print(right_clutch);
HC12.print("C");
HC12.print(potensiometer_speedcontrol);
HC12.print("D");
HC12.print(low_mechanism);


Serial.print(backword_forward);
Serial.print("A");
Serial.print(left_clutch);
Serial.print("B");
Serial.print(right_clutch);
Serial.print("C");
Serial.println(potensiometer_speedcontrol);
Serial.print("D");
Serial.println(low_mechanism);

}
