#include "Engine_4Motors.h"
#include "Arduino.h"

Engine_4Motors::Engine_4Motors(short MotorRF_, short MotorRB_, short MotorLF_, short MotorLB_):
 MotorRF(MotorRF_),MotorRB(MotorRB_), MotorLF(MotorLF_), MotorLB(MotorLB_)
{
  pinMode(MotorRF, OUTPUT); //
  pinMode(MotorRB, OUTPUT); //
  pinMode(MotorLF, OUTPUT); //
  pinMode(MotorLB, OUTPUT);
}
void Engine_4Motors::RunForward() 
{
  analogWrite(MotorLF, SpeedFull);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, SpeedFull);
  analogWrite(MotorRB, 0);
}
void Engine_4Motors::RunBackward() 
{
  analogWrite(MotorLF, 0);
  analogWrite(MotorLB, SpeedFull);
  analogWrite(MotorRF, 0);
  analogWrite(MotorRB, SpeedFull);
}
void Engine_4Motors::RunLeft() 
{
  analogWrite(MotorLF, 0);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, SpeedFull);
  analogWrite(MotorRB, 0);
}
void Engine_4Motors::RunRight()
{
  analogWrite(MotorLF, SpeedFull);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, 0);
  analogWrite(MotorRB, 0);
}
void Engine_4Motors::RunForwardRight()
{
  analogWrite(MotorLF, SpeedFull);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, SpeedOnTurn);
  analogWrite(MotorRB, 0);
}
void Engine_4Motors::RunForwardLeft()
{
  analogWrite(MotorLF, SpeedOnTurn);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, SpeedFull);
  analogWrite(MotorRB, 0);
}
void Engine_4Motors::RunBackwardRight()
{
  analogWrite(MotorLF, 0);
  analogWrite(MotorLB, SpeedFull);
  analogWrite(MotorRF, 0);
  analogWrite(MotorRB, SpeedOnTurn);
}
void Engine_4Motors::RunBackwardLeft()
{
  analogWrite(MotorLF, 0);
  analogWrite(MotorLB, SpeedOnTurn);
  analogWrite(MotorRF, 0);
  analogWrite(MotorRB, SpeedFull);
}
void Engine_4Motors::Stop()
{
  analogWrite(MotorLF, 0);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, 0);
  analogWrite(MotorRB, 0);
}