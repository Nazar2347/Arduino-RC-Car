#include "ServoRadar.h"
#include "Sensor.h"
#include <Servo.h> 

ServoRadar::ServoRadar(short ServoPin_,  Sensor* AttachedSensor): ServoPin(ServoPin),MySensor(AttachedSensor)
{
   MyServo = new Servo;
   MyServo->attach(ServoPin);
   Itterator =0;
}

void ServoRadar::Itterate()
{
  if (Itterator < 180&& GoRight)
  {
    Itterator++;
  }
  if (Itterator >= 180)
  {
    Itterator--;
    GoRight =false;
  }
  if (Itterator <= 0)
  {
    Itterator++;
    GoRight = true;
  }
}

bool ServoRadar::Run()
{
  

  //MyServo->write(Itterator);
  return MySensor->DoScan();

  
}
void ServoRadar::TurnServo(short Degrees_)
{
  if (Degrees_ >180 ||Degrees_ <0)
  {
    return;
  }
  MyServo->write(Degrees_);
}

ServoRadar::~ServoRadar()
{
  delete MySensor;
  delete MyServo;
}