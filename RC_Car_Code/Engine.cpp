#include "Engine.h"
#include "Arduino.h"

Engine::Engine(short MotorRF_, short MotorRB_, short MotorLF_, short MotorLB_):
 MotorRF(MotorRF_),MotorRB(MotorRB_), MotorLF(MotorLF_), MotorLB(MotorLB_)
{
  pinMode(MotorRF, OUTPUT); //
  pinMode(MotorRB, OUTPUT); //
  pinMode(MotorLF, OUTPUT); //
  pinMode(MotorLB, OUTPUT);
}
void Engine::RunForward()
{
  analogWrite(MotorLF, SpeedFull);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, SpeedFull);
  analogWrite(MotorRB, 0);
}
void Engine::RunBackward()
{
  analogWrite(MotorLF, 0);
  analogWrite(MotorLB, SpeedFull);
  analogWrite(MotorRF, 0);
  analogWrite(MotorRB, SpeedFull);
}
void Engine::RunLeft()
{
  analogWrite(MotorLF, 0);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, SpeedFull);
  analogWrite(MotorRB, 0);
}
void Engine::RunRight()
{
  analogWrite(MotorLF, SpeedFull);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, 0);
  analogWrite(MotorRB, 0);
}
void Engine::RunForwardRight()
{
  analogWrite(MotorLF, SpeedFull);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, SpeedOnTurn);
  analogWrite(MotorRB, 0);
}
void Engine::RunForwardLeft()
{
  analogWrite(MotorLF, SpeedOnTurn);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, SpeedFull);
  analogWrite(MotorRB, 0);
}
void Engine::RunBackwardRight()
{
  analogWrite(MotorLF, 0);
  analogWrite(MotorLB, SpeedFull);
  analogWrite(MotorRF, 0);
  analogWrite(MotorRB, SpeedOnTurn);
}
void Engine::RunBackwardLeft()
{
  analogWrite(MotorLF, 0);
  analogWrite(MotorLB, SpeedOnTurn);
  analogWrite(MotorRF, 0);
  analogWrite(MotorRB, SpeedFull);
}
void Engine::Stop()
{
  analogWrite(MotorLF, 0);
  analogWrite(MotorLB, 0);
  analogWrite(MotorRF, 0);
  analogWrite(MotorRB, 0);
}