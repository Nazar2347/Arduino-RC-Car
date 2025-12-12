#pragma once
class Engine ;

class Car
{
  private:
  short LEDFront;
  short LEDBack;
  Engine* CarEngine;

  short SpeedFull =200;
  short SpeedOnTurn = SpeedFull/4;
  
  char command = 'S';
  public:
  Car (Engine* CarEngine, short LEDFront_, short LEDBack_);
  void Run();
  char GetCommand();
};
