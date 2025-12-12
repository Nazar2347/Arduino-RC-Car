
class Sensor
{
  private:
    const short TriggerPin;
    const short EchoPin;
    const float TriggerDistance; //cm
  public:
    Sensor(short TriggerPin_, short EchoPin_, float TriggerDistance_);
    bool DoScan();

};