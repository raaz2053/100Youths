#define motor1IN1 8
#define motor1IN2 9
#define motor1IN3 12
#define motor1IN4 13

const int en1 = 5;
const int en2 = 6;
#include<SoftwareSerial.h>
SoftwareSerial BT(10, 11); // 10 rx and 11 tx
char c;
void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  while (BT.available())
  {
    delay(10);
    c = BT.read();

    Serial.println(c);
    switch (c)
    {
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'L':
        right();
        break;
      case 'R':
        left();
        break;
      case 'I':
        hardleft();
        break;
      case 'G':
        hardright();
        break;
      default: brake();
    }
  }
}


void backward()
{

  digitalWrite(motor1IN1, LOW);
  digitalWrite(motor1IN2, HIGH);
  digitalWrite(motor1IN3, LOW);
  digitalWrite(motor1IN4, HIGH);
  analogWrite(en1, 200);
  analogWrite(en2, 200);
  BT.println("/n backward");
}

void forward()
{

  digitalWrite(motor1IN1, HIGH);
  digitalWrite(motor1IN2, LOW);
  digitalWrite(motor1IN3, HIGH);
  digitalWrite(motor1IN4, LOW);
  analogWrite(en1, 255);
  analogWrite(en2, 255);
  BT.println("/n forward");
}

void right()//forward right
{

  digitalWrite(motor1IN1, HIGH);
  digitalWrite(motor1IN2, LOW);
  digitalWrite(motor1IN3, LOW);
  digitalWrite(motor1IN4, HIGH);
  analogWrite(en1, 200);
  analogWrite(en2, 200);
  BT.println("/n hardright");
}


void left()//forward left
{
  digitalWrite(motor1IN1, LOW);
  digitalWrite(motor1IN2, HIGH);
  digitalWrite(motor1IN3, HIGH);
  digitalWrite(motor1IN4, LOW);
  analogWrite(en1, 200);
  analogWrite(en2, 200);
  BT.println("/n hardleft");
}


void hardleft()
{
  digitalWrite(motor1IN1, 1);
  digitalWrite(motor1IN2, 0);
  digitalWrite(motor1IN3, HIGH);
  digitalWrite(motor1IN4, LOW);
  analogWrite(en1, 100);
  analogWrite(en2, 255);
  BT.println("/n left");
}


void hardright()
{

  digitalWrite(motor1IN1, HIGH);
  digitalWrite(motor1IN2, LOW);
  digitalWrite(motor1IN3, 1);
  digitalWrite(motor1IN4, 0);
  analogWrite(en1, 255);
  analogWrite(en2, 100);
  BT.println("/n right");
}

void brake()
{

  digitalWrite(motor1IN1, 1);
  digitalWrite(motor1IN2, 1);
  digitalWrite(motor1IN3, 1);
  digitalWrite(motor1IN4, 1);
  BT.println("/n Brake");

}

