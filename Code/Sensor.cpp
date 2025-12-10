#include "Sensor.h"
#include "Arduino.h"

  Sensor::Sensor(short TriggerPin_, short EchoPin_, float TriggerDistance_)
    :TriggerPin(TriggerPin_), EchoPin(EchoPin_), TriggerDistance(TriggerDistance_)
  {
    
  }
  bool Sensor::DoScan()
  {
    float Distance = 0;
    float Duration =0;
    digitalWrite(TriggerPin, LOW);
    delayMicroseconds(2);

    digitalWrite(TriggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);

    Duration = pulseIn(EchoPin, HIGH);

    Distance = Duration * 0.034 / 2;

    Serial.print(180);
    Serial.print(", ");
    Serial.print(Distance);
    Serial.print(". ");
    return Distance <TriggerDistance;

  }
  
