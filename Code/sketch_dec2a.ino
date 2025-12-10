#include <Servo.h> 
/*
const int TriggerPinFront = A2;
const int EchoPinFront = A3;
const int Buzzer = 4;

const short TriggerPinBack = A4;
const short EchoPinback =A5;

const short LEDFront =A0;
const short LEDBack=A1;


Servo myServo;

void setup() {
  //Front Sensor
  pinMode(TriggerPinFront, OUTPUT);
  pinMode(EchoPinFront, INPUT);

  pinMode(TriggerPinBack, OUTPUT);
  pinMode(EchoPinFront,INPUT);

  pinMode(Buzzer, OUTPUT);


  Serial.begin(9600);
  myServo.attach(10);
}

void loop() {

short Distance =0;
  // Servo 0 → 180 stopni
  for (int i = 0; i <= 180; i++) {
    myServo.write(i);
    delay(30);

    Distance = calculateDistance(TriggerPinFront,EchoPinFront,Buzzer);

    Serial.print(i);
    Serial.print(",");
    Serial.println(Distance);   // <-- NOWA LINIA
  }

  // Servo 180 → 0 stopni
  for (int i = 180; i >= 0; i--) {
    myServo.write(i);
    delay(30);

    Distance = calculateDistance(TriggerPinFront,EchoPinFront,Buzzer);

    Serial.print(i);
    Serial.print(",");
    Serial.println(Distance);   // <-- NOWA LINIA
  }
}




int calculateDistance(short TriggerPin, short EchoPin, short Buzzer)
 {
  float distance = 0;
  float duration =0;
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  duration = pulseIn(EchoPin, HIGH);

  distance = duration * 0.034 / 2;

  if (distance < 40) {
    digitalWrite(Buzzer, LOW);
  } else {
    digitalWrite(Buzzer, HIGH);
  }

  return distance;
}
*/