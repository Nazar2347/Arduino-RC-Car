#include "Sensor.h"
#include "Arduino.h"

  Sensor::Sensor(short TriggerPin_, short EchoPin_, float TriggerDistance_)
    :TriggerPin(TriggerPin_), EchoPin(EchoPin_), TriggerDistance(TriggerDistance_)
  {
      pinMode(TriggerPin,OUTPUT);
      pinMode(EchoPin, INPUT);
  }
  bool Sensor::DoScan()
  {
    int Distance = 0;
    float Duration =0;
    digitalWrite(TriggerPin, LOW);
   

    digitalWrite(TriggerPin, HIGH);
   
    digitalWrite(TriggerPin, LOW);

    Duration = pulseIn(EchoPin, HIGH,3000);
    if (Duration == 0) {
        return false;  // No object detected
    }

    Distance = Duration * 0.034 / 2;
     
    
    return Distance <TriggerDistance;

  }
  
