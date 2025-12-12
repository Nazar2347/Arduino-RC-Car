#pragma once
class Engine
{
  private:
    short MotorRB;
    short MotorRF;
    short MotorLF;
    short MotorLB;

    short SpeedFull =200;
    short SpeedOnTurn = SpeedFull/4;
  public:

  Engine(short MotorRF_, short MotorRB_, short MotorLF_, short MotorLB_);
  void RunForward();
  void RunBackward();
  void RunLeft();
  void RunRight();
  void RunForwardRight();
  void RunForwardLeft();
  void RunBackwardRight();
  void RunBackwardLeft();
  void Stop();
};