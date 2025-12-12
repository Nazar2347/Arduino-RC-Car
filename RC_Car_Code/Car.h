class Car
{
  private:
  short MotorRB;
  short MotorRF;
  short MotorLF;
  short MotorLB;

  short SpeedFull =200;
  short SpeedOnTurn = SpeedFull/4;
  
  char command = 'S';
  public:
  Car (short MotorRF_, short MotorRB_, short MotorLF_, short MotorLB_);
  void Run();
  char GetCommand();
};
