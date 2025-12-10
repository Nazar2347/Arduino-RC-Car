#include "Car.h"
#include "ServoRadar.h"
#include "Sensor.h"
#include <Arduino.h>



const short SensorTriggerDistance;
//===Front Sensor
const int TriggerPinFront = A2;
const int EchoPinFront = A3;
const short ServoPinFront =3;
Sensor* FrontSensor = new Sensor (TriggerPinFront,EchoPinFront, SensorTriggerDistance);

//===Back Sensor
const short TriggerPinBack = A4;
const short EchoPinBack =A5;
Sensor* BackSensor = new Sensor(TriggerPinBack, EchoPinBack, SensorTriggerDistance);



short MotorRB = 6;//Right-Forward
short MotorRF = 5; //Right -Bacward
short MotorLF = 9; // Left-Forward
short MotorLB = 10; // Left-Backward //good

Car RCCar(MotorRB,MotorRF,MotorLF,MotorLB);

const int Buzzer = A0;
const short LEDFront =13;
const short LEDBack =12;


ServoRadar FrontRadar(ServoPinFront,FrontSensor);


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (BackSensor->DoScan()||FrontRadar.Run())
  {
     digitalWrite(Buzzer, LOW);
  }
  else
  {
     digitalWrite(Buzzer, HIGH);
  }
  RCCar.Run();


}
