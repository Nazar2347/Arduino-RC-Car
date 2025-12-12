#pragma once
class IEngine ;

class Car
{
  private:
  short LEDFront;
  short LEDBack;
  IEngine* CarEngine;

  short SpeedFull =200;
  short SpeedOnTurn = SpeedFull/4;
  
  char command = 'S';
  public:
  Car (IEngine* CarEngine_, short LEDFront_, short LEDBack_);
  void Run();
  char GetCommand();
  ~Car();
};
