#include "Car.h"
#include "IEngine.h"
#include "Arduino.h"

Car::Car(IEngine* CarEngine_, short LEDFront_, short LEDBack_)
: CarEngine(CarEngine_), LEDFront(LEDFront_),LEDBack(LEDBack_)
{
  
  Serial.begin(9600);
  pinMode(LEDFront, OUTPUT);//
  pinMode(LEDBack, OUTPUT); //
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
    
    switch (command) 
    {
      case 'F': //Forward
        CarEngine->RunForward();
         digitalWrite(LEDBack, LOW); // Turn off Back lights
        break;
      case 'B': //Backward
         CarEngine->RunBackward();
         digitalWrite(LEDBack, HIGH); // Turn on Back lights
        break;
      case 'R': //Right
         CarEngine->RunRight();
        break;
      case 'L': //Left
         CarEngine->RunLeft();
        break;
      case 'H': //Forward -Right
         CarEngine->RunForwardRight();
        break;
      case 'G': //Forward -left
         CarEngine->RunForwardLeft();
        break;
      case 'J': //Backward -Right
         CarEngine->RunBackwardRight();
        break;
      case 'I': //Backward -Left
         CarEngine->RunBackwardLeft();
         digitalWrite(LEDBack, HIGH);
        break;
      case 'S':
        CarEngine->Stop();
        break;
    
      case'U': digitalWrite(LEDFront, HIGH); break; 
      case'u': digitalWrite(LEDFront,LOW); break;

    }
  }
   
  
}
Car::~Car()
{
  delete CarEngine;
}
