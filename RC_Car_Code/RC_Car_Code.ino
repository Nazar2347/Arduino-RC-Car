#include "Car.h"
#include "ServoRadar.h"
#include "Sensor.h"
#include "Engine_4Motors.h"
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
short MotorRF = 6;  // Right-Forward
short MotorRB =  5;  //Right -Bacward
short MotorLF = 10; // Left-Forward
short MotorLB = 11; // Left-Backward //good
short LEDFront = 13;
short LEDBack= 12;
IEngine* CarEngine = new Engine_4Motors(MotorRF,MotorRB,MotorLF,MotorLB);
Car RCCar(CarEngine,LEDFront,LEDBack);

const int BuzzerPin = A0;





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
  
  if (FrontRadar.CheckForObstacle())
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
