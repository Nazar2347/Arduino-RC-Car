#pragma once
#include "IEngine.h"
class Engine_4Motors: public IEngine
{
  private:
    short MotorRB;
    short MotorRF;
    short MotorLF;
    short MotorLB;

    short SpeedFull =200;
    short SpeedOnTurn = SpeedFull/4;
  public:

  Engine_4Motors(short MotorRF_, short MotorRB_, short MotorLF_, short MotorLB_);
  virtual void RunForward() override;
  virtual void RunBackward() override;
  virtual void RunLeft() override;
  virtual void RunRight() override;
  virtual void RunForwardRight() override;
  virtual void RunForwardLeft() override;
  virtual void RunBackwardRight() override ;
  virtual void RunBackwardLeft() override ;
  virtual void Stop();
};