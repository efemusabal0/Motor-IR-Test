#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define CH1 0xFFA25D
#define CH 0xFF629D
#define CH2 0xFFE21D
#define PREV 0xFF22DD
#define NEXT 0xFF02FD
#define PLAYPAUSE 0xFFC23D
#define VOL1 0xFFE01F
#define VOL2 0xFFA857
#define EQ 0xFF906F
#define BUTON0 0xFF6897
#define BUTON100 0xFF9867
#define BUTON200 0xFFB04F
#define BUTON1 0xFF30CF
#define BUTON2 0xFF18E7
#define BUTON3 0xFF7A85
#define BUTON4 0xFF10EF
#define BUTON5 0xFF38C7
#define BUTON6 0xFF5AA5
#define BUTON7 0xFF42BD
#define BUTON8 0xFF4AB5
#define BUTON9 0xFF52AD

int motor1A = 3;
int motor1B = 4;
int motor2A = 5;
int motor2B = 6;
int motor3A = 7;
int motor3B = 8;
int motor4A = 9;
int motor4B = 10;

void setup()
{
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor3A, OUTPUT);
  pinMode(motor3B, OUTPUT);
  pinMode(motor4A, OUTPUT);
  pinMode(motor4B, OUTPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
  {
    if (results.value == BUTON1)
    {
      moveForward();
      Serial.println("Motors moving forward");
    }
    if (results.value == BUTON2)
    {
      moveBackward();
      Serial.println("Motors moving backward");
    }
    if (results.value == BUTON3)
    {
      turnRight();
      Serial.println("Motors turning right");
    }
    if (results.value == BUTON4)
    {
      turnLeft();
      Serial.println("Motors turning left");
    }
    if (results.value == BUTON0)
    {
      stopMotors();
      Serial.println("Motors stopped");
    }
    irrecv.resume();
  }
}

void moveForward() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  digitalWrite(motor3A, HIGH);
  digitalWrite(motor3B, LOW);
  digitalWrite(motor4A, HIGH);
  digitalWrite(motor4B, LOW);
}

void moveBackward() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  digitalWrite(motor3A, LOW);
  digitalWrite(motor3B, HIGH);
  digitalWrite(motor4A, LOW);
  digitalWrite(motor4B, HIGH);
}

void turnRight() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  digitalWrite(motor3A, LOW);
  digitalWrite(motor3B, HIGH);
  digitalWrite(motor4A, HIGH);
  digitalWrite(motor4B, LOW);
}

void turnLeft() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  digitalWrite(motor3A, HIGH);
  digitalWrite(motor3B, LOW);
  digitalWrite(motor4A, LOW);
  digitalWrite(motor4B, HIGH);
}

void stopMotors() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
  digitalWrite(motor3A, LOW);
  digitalWrite(motor3B, LOW);
  digitalWrite(motor4A, LOW);
  digitalWrite(motor4B, LOW);
}
