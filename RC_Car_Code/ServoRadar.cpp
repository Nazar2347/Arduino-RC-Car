#include "ServoRadar.h"
#include "Sensor.h"
#include <Servo.h> 

ServoRadar::ServoRadar(short ServoPin_,  Sensor* AttachedSensor): ServoPin(ServoPin),MySensor(AttachedSensor)
{
   MyServo = new Servo;
   MyServo->attach(ServoPin);
   Itterator =0;
}
//TODO: 
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

bool ServoRadar::CheckForObstacle()
{
  
  return MySensor->DoScan();
  
}

void ServoRadar::TurnServo(short Degrees_)
{

  MyServo->write(Degrees_);
}

ServoRadar::~ServoRadar()
{
  delete MySensor;
  delete MyServo;
}