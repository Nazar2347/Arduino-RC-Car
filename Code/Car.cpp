#include "Car.h"
#include "Arduino.h"

Car::Car(short MotorRB_, short MotorRF_, short MotorLF_, short MotorLB_)
: MotorRB(MotorRB_), MotorRF(MotorRF_), MotorLF(MotorLF_), MotorLB(MotorLB_)
{

  Serial.begin(9600);
  pinMode(MotorRF, OUTPUT); //
  pinMode(MotorRB, OUTPUT); //
  pinMode(MotorLF, OUTPUT); //
  pinMode(MotorLB, OUTPUT); //
}
void Car::Run()
{
  short MotorRB = 6;//Right-Forward
  short MotorRF = 5; //Right -Bacward
  short MotorLF = 9; // Left-Forward
  short MotorLB = 10; // Left-Backward //good

  if (Serial.available() > 0) {
    char command = Serial.read();

    Serial.println(command);

    switch (command) {
      case 'F': //Forward
         analogWrite(MotorLF, 150);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, 150);
         analogWrite(MotorRB, 0);
        break;
      case 'B': //Backward
         analogWrite(MotorLF, 0);
         analogWrite(MotorLB, 150);
         analogWrite(MotorRF, 0);
         analogWrite(MotorRB, 150);
        break;
      case 'R': //Right
         analogWrite(MotorLF, 150);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, 0);
         analogWrite(MotorRB, 0);
        break;
      case 'L': //Left
         analogWrite(MotorLF, 0);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, 150);
         analogWrite(MotorRB, 0);
        break;
        case 'H': //Forward -Right
         analogWrite(MotorLF, 150);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, 75);
         analogWrite(MotorRB, 0);
        break;
      case 'G': //Forward -left
         analogWrite(MotorLF, 75);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, 150);
         analogWrite(MotorRB, 0);
        break;
      case 'J': //Backward -Right
         analogWrite(MotorLF, 0);
         analogWrite(MotorLB, 150);
         analogWrite(MotorRF, 0);
         analogWrite(MotorRB, 75);
        break;
      case 'I': //Backward -Left
          analogWrite(MotorLF, 0);
         analogWrite(MotorLB, 75);
         analogWrite(MotorRF, 0);
         analogWrite(MotorRB, 150);
        break;
      case 'S':
         analogWrite(MotorLF, 0);
         analogWrite(MotorLB, 0);
         analogWrite(MotorRF, 0);
         analogWrite(MotorRB, 0);
        break;
    }
  }
}
