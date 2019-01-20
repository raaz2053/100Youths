#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int val;    // variable to read the value from the analog pin

SoftwareSerial BT(10, 11);
const int m1a = 8;
const int m1b = 9;
const int m2a = 12;
const int m2b = 13;

const int a=20;

const int en1 = 5;
const int en2 = 6;
const int servo = 3 ;
int s;

char Bdata;
void setup()
{
  myservo.attach(servo);  // attaches the servo on pin 9 to the servo object
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(servo, OUTPUT);
  BT.begin(9600);
  Serial.begin(9600);
  s = 100;
}
void loop() {
  if (BT.available()) {
    if (BT.available() > 0) {
      delay(3);
      Bdata = BT.read();
    }
  }
  Serial.println(Bdata);



  switch (Bdata)
  { case 'F': forward();
      break;
    case 'R': right();
      break;
    case 'L': left();
      break;
    case 'B': backward();
      break;
    case '0': s = 100;
      break;
    case '9': s = 200;
      break;
    case '8': s = 200;
      break;
    case '7': s = 200;
      break;
    case '6': s = 200;
      break;
    default: halt();
      break;

  }


}


void forward()
{ myservo.write(a+15);
  digitalWrite(m1a, 1);
  digitalWrite(m1b, 0);
  digitalWrite(m2a, 1);
  digitalWrite(m2b, 0);
  analogWrite(en1, s);
  analogWrite(en2, s);
}
void left()
{ myservo.write(a);
  digitalWrite(m1a, 1);
  digitalWrite(m1b, 0);
  digitalWrite(m2a, 1);
  digitalWrite(m2b, 0);
  analogWrite(en1, s);
  analogWrite(en2, s);
}

void right()
{ myservo.write(a+31);
  digitalWrite(m1a, 1);
  digitalWrite(m1b, 0);
  digitalWrite(m2a, 1);
  digitalWrite(m2b, 0);
  analogWrite(en1, s);
  analogWrite(en2, s);
}

void backward()
{ digitalWrite(m1a, 0);
  digitalWrite(m1b, 1);
  digitalWrite(m2a, 0);
  digitalWrite(m2b, 1);
  analogWrite(en1, s);
  analogWrite(en2, s);
}

void halt()
{ digitalWrite(m1a, 1);
  digitalWrite(m1b, 1);
  digitalWrite(m2a, 1);
  digitalWrite(m2b, 1);
  analogWrite(en1, s);
  analogWrite(en2, s);
}


