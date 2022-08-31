#include <SoftwareSerial.h>
#include <Wire.h>
              
SoftwareSerial HC12(10, 11);

int backword_forward;
int left_clutch;
int right_clutch;
int potensiometer_speedcontrol;
int signal_sensor;
int metering_mechanism;
String input;
int boundLow;
int boundHigh;


//for two clutches
    int linL1=1;
    int linL2=2;
    int linR1=3;
    int linR2=4;

//for dc motor

    int dir1 = 5;
    int dir2 = 6;
    int speedpin=7;

void setup() {
    
Serial.begin(9600);
HC12.begin(9600);

//for left clutch
    pinMode(linL1,OUTPUT);
    pinMode(linL2,OUTPUT);

//for right clutch
    pinMode(linR1,OUTPUT);
    pinMode(linR2,OUTPUT);

// for dc motor
    pinMode(speedpin,OUTPUT);
    pinMode(dir1,OUTPUT);
    pinMode(dir2,OUTPUT);

// for metering mechanism
   pinMode(signal_sensor,INPUT);
   pinMode(metering_mechanism,OUTPUT);

}


void loop() {

  if(HC12.available())
  {
  input = HC12.readStringUntil('\n');
  if (input.length() > 0)
      {
        Serial.println(input);
       
       boundLow = input.indexOf(delimiter);
        backword_forward = input.substring(0, boundLow).toInt();
    
        boundHigh = input.indexOf(delimiter, boundLow+1);
        left_clutch = input.substring(boundLow+1, boundHigh).toInt();
    
        boundLow = input.indexOf(delimiter, boundHigh+1);
        right_clutch = input.substring(boundHigh+1, boundLow).toInt();

    
        potensiometer_speedcontrol = input.substring(boundLow+1).toInt();
      }
  }
  Serial.print("backword_forward=");
  Serial.print(backword_forward);
  Serial.print(",left_clutch=");
  Serial.print(left_clutch);
  Serial.print(",right_clutch=");
  Serial.print(right_clutch);
  Serial.print(",potensiometer_speedcontrol=");
  Serial.print(potensiometer_speedcontrol);


   //for clockwise and anticlockwise rotation of motor 
  
  
      if(backword_forward<500){
          digitalWrite(dir1,LOW);
          digitalWrite(dir2,HIGH);
          analogWrite(speedpin,pot)
      }
      else if(backword_forward>=530){
          digitalWrite(dir1,HIGH);
          digitalWrite(dir2,LOW);
          analogWrite(speedpin,pot);
      }
      else{
          digitalWrite(dir1,LOW);
          digitalWrite(dir2,LOW);
      }
// for engagement and disengagement of left clutch
    if(left_clutch<500){
      digitalWrite(linL1,LOW);
      digitalWrite(linL2,HIGH);
    }
    else if(left_clutch>=530){
      digitalWrite(linL1,HIGH);
      digitalWrite(linL2,LOW);
    }
    else{
      digitalWrite(linL1,LOW);
      digitalWrite(linL2,LOW);
      }

// for engagement and disengagement of right clutch    
    if(right_clutch>500){
      digitalWrite(linR1,LOW);
      digitalWrite(linR2,HIGH);
    }
    else if(right_clutch<=530){
      digitalWrite(linR1,HIGH);
      digitalWrite(linR2,LOW);
    }else{
      digitalWrite(linL1,LOW);
      digitalWrite(linL2,LOW);
    }

//for operating the metering mechanism of solonoiblade 
    if(digitalRead(inductive)==HIGH){
      digitalwrite(signal_sensor,HIGH);
      delay(10);
      digitalwrite(metering_mechanism,LOW);
    }
    


}
