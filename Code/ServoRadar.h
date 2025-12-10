class Servo;
class Sensor;

class ServoRadar
{
  private:
  const Sensor* MySensor;

  const short ServoPin;
  Servo* MyServo;
  short Itterator;
  bool GoRight;
  

  public:
  ServoRadar(short ServoPin_,  Sensor* AttachedSensor);
  ~ServoRadar();
  bool Run();
  void Itterate();
  void TurnServo(short Degrees_);
};
