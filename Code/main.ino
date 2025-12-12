#include "Car.h"
#include "ServoRadar.h"
#include "Sensor.h"
#include <Arduino.h>




const short SensorTriggerDistance=10; //cm
//===Front Sensor
const int TriggerPinFront = A4;
const int EchoPinFront = A5;
const short ServoPinFront =A1;
Sensor* FrontSensor = new Sensor (TriggerPinFront,EchoPinFront, SensorTriggerDistance);
ServoRadar FrontRadar(ServoPinFront,FrontSensor);

//===Back Sensor
const short TriggerPinBack = A2;
const short EchoPinBack =A3;
Sensor* BackSensor = new Sensor(TriggerPinBack, EchoPinBack, SensorTriggerDistance);


//===Car 
short MotorRF =  5;  //Right -Bacward
short MotorRB = 6;  // Right-Forward
short MotorLF = 10; // Left-Forward
short MotorLB = 11; // Left-Backward //good
Car RCCar(MotorRB,MotorRF,MotorLF,MotorLB);


//===Light
const int BuzzerPin = 3;
const short LEDFront =13;
const short LEDBack =12;




void setup()
{
  Serial.begin(9600);
  pinMode(BuzzerPin,OUTPUT);
  
  pinMode(LEDFront,OUTPUT);
  pinMode(LEDBack,OUTPUT);

  digitalWrite(LEDFront,HIGH);
  digitalWrite(LEDBack,LOW);
  digitalWrite (BuzzerPin,HIGH);
}

void loop()
{
  
  RCCar.Run();
  
  if (FrontRadar.Run())
  {
    tone(BuzzerPin,0,3);
    noTone(BuzzerPin);
    
  }
  else if (BackSensor->DoScan())
  {
    tone(BuzzerPin,10000,3);
    noTone(BuzzerPin);
  }
  else
  {
     digitalWrite(BuzzerPin,HIGH); // Turn off Buzzer
  }
 



}
