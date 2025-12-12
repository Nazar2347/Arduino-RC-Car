#include "Car.h"
#include "Arduino.h"

Car::Car(short MotorRF_, short MotorRB_, short MotorLF_, short MotorLB_)
:  MotorRF(MotorRF_),MotorRB(MotorRB_), MotorLF(MotorLF_), MotorLB(MotorLB_)
{

  Serial.begin(9600);
  pinMode(MotorRF, OUTPUT); //
  pinMode(MotorRB, OUTPUT); //
  pinMode(MotorLF, OUTPUT); //
  pinMode(MotorLB, OUTPUT); //
}

char Car::GetCommand()
{
   return command;
}
void Car::Run()
{
  if (Serial.available() > 0) 
  {
     command = Serial.read();
    
    switch (command) {
      case 'F': //Forward
         analogWrite(MotorLF, SpeedFull);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, SpeedFull);
         analogWrite(MotorRB, 0);
         digitalWrite(LEDBack, LOW); // Turn off Back lights
        break;
      case 'B': //Backward
         analogWrite(MotorLF, 0);
         analogWrite(MotorLB, SpeedFull);
         analogWrite(MotorRF, 0);
         analogWrite(MotorRB, SpeedFull);
         digitalWrite(LEDBack, HIGH); // Turn on Back lights
        break;
      case 'R': //Right
         analogWrite(MotorLF, SpeedFull);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, 0);
         analogWrite(MotorRB, 0);
        break;
      case 'L': //Left
         analogWrite(MotorLF, 0);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, SpeedFull);
         analogWrite(MotorRB, 0);
        break;
        case 'H': //Forward -Right
         analogWrite(MotorLF, SpeedFull);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, SpeedOnTurn);
         analogWrite(MotorRB, 0);
        break;
      case 'G': //Forward -left
         analogWrite(MotorLF, SpeedOnTurn);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, SpeedFull);
         analogWrite(MotorRB, 0);
        break;
      case 'J': //Backward -Right
         analogWrite(MotorLF, 0);
         analogWrite(MotorLB, SpeedFull);
         analogWrite(MotorRF, 0);
         analogWrite(MotorRB, SpeedOnTurn);
         digitalWrite(LEDBack, HIGH);
        break;
      case 'I': //Backward -Left
          analogWrite(MotorLF, 0);
         analogWrite(MotorLB, SpeedOnTurn);
         analogWrite(MotorRF, 0);
         analogWrite(MotorRB, SpeedFull);
         digitalWrite(LEDBack, HIGH);
        break;
      case 'S':
         analogWrite(MotorLF, 0);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, 0);
         analogWrite(MotorRB, 0);
        break;
    
      case'U': digitalWrite(LEDFront, HIGH); break; 
      case'u': digitalWrite(LEDFront,LOW); break;

    }
  }
   
  
}
