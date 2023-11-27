#include <IRremote.h>
#include <Unistep2.h>
#define DELAY 1
//cellphone﹕
#define RF 86057202
#define RB 3728385585
#define RL 2270411356
#define RR 1770599057
#define RS 1990685718

//controler  
#define CF 489680886
#define CB 2737486129
#define CL 970202566
#define CR 3768077238
#define CS 924466310

IRrecv IrReceiver(4);
decode_results results;
int F = 0, B = 0, L = 0, R = 0;
void backward();
void forward();
void left();
void right();
void stopp();
void blinkk();

void setup()
{
  Serial.begin(9600);
  IrReceiver.enableIRIn();
  pinMode(4, INPUT);  //LED
  pinMode(5, OUTPUT); //LED
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  if (IrReceiver.decode(&results)) {
    switch (results.value) {
      case RF:
        blinkk();   F = 1;  B = L = R = 0;  forward();    break;
      case RB:
        blinkk();   B = 1;  F = L = R = 0;  backward();   break;
      case RL:
        blinkk();   L = 1;  F = B = R = 0;  left();       break;
      case RR:
        blinkk();   R = 1;  F = B = L = 0;  right();      break;
      case RS:
        blinkk();   F = B = L = R = 0;      stopp();      break;
      case CF:
        blinkk();   F = 1;  B = L = R = 0;  forward();    break;
      case CB:
        blinkk();   B = 1;  F = L = R = 0;  backward();   break;
      case CL:
        blinkk();   L = 1;  F = B = R = 0;  left();       break;
      case CR:
        blinkk();   R = 1;  F = B = L = 0;  right();      break;
      case CS:
        blinkk();   F = B = L = R = 0;      stopp();      break;
    }
    Serial.println(results.value);
    IrReceiver.resume();
  }
}

void blinkk()
{
  digitalWrite(5, 1);
  delay(100);
  digitalWrite(5, 0);
}

void stopp()
{
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void forward()
{
  stopp();
  while (F != 0) {
    digitalWrite(6, 1);   digitalWrite(13, 1);
    delay(DELAY);
    digitalWrite(9, 0);   digitalWrite(10, 0);
    delay(DELAY);
    digitalWrite(7, 1);   digitalWrite(12, 1);
    delay(DELAY);
    digitalWrite(6, 0);   digitalWrite(13, 0);
    delay(DELAY);
    digitalWrite(8, 1);   digitalWrite(11, 1);
    delay(DELAY);
    digitalWrite(7, 0);   digitalWrite(12, 0);
    delay(DELAY);
    digitalWrite(9, 1);   digitalWrite(10, 1);
    delay(DELAY);
    digitalWrite(8, 0);   digitalWrite(11, 0);
    delay(DELAY);
    if (IrReceiver.decode(&results)) {
      switch (results.value) {
        case RF:
          blinkk();   F = 1;   B = L = R = 0;                  break;
        case RB:
          blinkk();   B = 1;   F = L = R = 0;    backward();   break;
        case RL:
          blinkk();   L = 1;   F = B = R = 0;    left();       break;
        case RR:
          blinkk();   R = 1;   F = B = L = 0;    right();      break;
        case RS:
          blinkk();   F = B = L = R = 0;         stopp();      break;
        case CF:
          blinkk();   F = 1;  B = L = R = 0;                   break;
        case CB:
          blinkk();   B = 1;  F = L = R = 0;     backward();   break;
        case CL:
          blinkk();   L = 1;  F = B = R = 0;     left();       break;
        case CR:
          blinkk();   R = 1;  F = B = L = 0;     right();      break;
        case CS:
          blinkk();   F = B = L = R = 0;         stopp();      break;
      }
      Serial.println(results.value);
      IrReceiver.resume();
    }
  }
}

void backward()
{
  stopp();
  while (B != 0) {
    digitalWrite(9, 1);   digitalWrite(10, 1);
    delay(DELAY);
    digitalWrite(6, 0);   digitalWrite(13, 0);
    delay(DELAY);
    digitalWrite(8, 1);   digitalWrite(11, 1);
    delay(DELAY);
    digitalWrite(9, 0);   digitalWrite(10, 0);
    delay(DELAY);
    digitalWrite(7, 1);   digitalWrite(12, 1);
    delay(DELAY);
    digitalWrite(8, 0);   digitalWrite(11, 0);
    delay(DELAY);
    digitalWrite(6, 1);   digitalWrite(13, 1);
    delay(DELAY);
    digitalWrite(7, 0);   digitalWrite(12, 0);
    delay(DELAY);
    if (IrReceiver.decode(&results)) {
      switch (results.value) {
        case RF:
          blinkk();   F = 1;   B = L = R = 0;   forward();    break;
        case RB:
          blinkk();   B = 1;   F = L = R = 0;                 break;
        case RL:
          blinkk();   L = 1;   F = B = R = 0;   left();       break;
        case RR:
          blinkk();   R = 1;   F = B = L = 0;   right();      break;
        case RS:
          blinkk();   F = B = L = R = 0;        stopp();      break;
        case CF:
          blinkk();   F = 1;  B = L = R = 0;    forward();    break;
        case CB:
          blinkk();   B = 1;  F = L = R = 0;                  break;
        case CL:
          blinkk();   L = 1;  F = B = R = 0;    left();       break;
        case CR:
          blinkk();   R = 1;  F = B = L = 0;    right();      break;
        case CS:
          blinkk();   F = B = L = R = 0;        stopp();      break;
      }
      Serial.println(results.value);
      IrReceiver.resume();
    }
  }
}

void left()
{
  stopp();
  while (L != 0) {
    digitalWrite(9, 1);   digitalWrite(13, 1);
    delay(DELAY);
    digitalWrite(6, 0);   digitalWrite(10, 0);
    delay(DELAY);
    digitalWrite(8, 1);   digitalWrite(12, 1);
    delay(DELAY);
    digitalWrite(9, 0);   digitalWrite(13, 0);
    delay(DELAY);
    digitalWrite(7, 1);   digitalWrite(11, 1);
    delay(DELAY);
    digitalWrite(8, 0);   digitalWrite(12, 0);
    delay(DELAY);
    digitalWrite(6, 1);   digitalWrite(10, 1);
    delay(DELAY);
    digitalWrite(7, 0);   digitalWrite(11, 0);
    delay(DELAY);
    if (IrReceiver.decode(&results)) {
      switch (results.value) {
        case RF:
          blinkk();   F = 1;   B = L = R = 0;   forward();    break;
        case RB:
          blinkk();   B = 1;   F = L = R = 0;   backward();   break;
        case RL:
          blinkk();   L = 1;   F = B = R = 0;                 break;
        case RR:
          blinkk();   R = 1;   F = B = L = 0;   right();      break;
        case RS:
          blinkk();   F = B = L = R = 0;        stopp();      break;
        case CF:
          blinkk();   F = 1;  B = L = R = 0;    forward();    break;
        case CB:
          blinkk();   B = 1;  F = L = R = 0;    backward();   break;
        case CL:
          blinkk();   L = 1;  F = B = R = 0;                  break;
        case CR:
          blinkk();   R = 1;  F = B = L = 0;    right();      break;
        case CS:
          blinkk();   F = B = L = R = 0;        stopp();      break;
      }
      Serial.println(results.value);
      IrReceiver.resume();
    }
  }
}

void right()
{
  stopp();
  while (R != 0) {
    digitalWrite(6, 1);   digitalWrite(10, 1);
    delay(DELAY);
    digitalWrite(9, 0);   digitalWrite(13, 0);
    delay(DELAY);
    digitalWrite(7, 1);   digitalWrite(11, 1);
    delay(DELAY);
    digitalWrite(6, 0);   digitalWrite(10, 0);
    delay(DELAY);
    digitalWrite(8, 1);   digitalWrite(12, 1);
    delay(DELAY);
    digitalWrite(7, 0);   digitalWrite(11, 0);
    delay(DELAY);
    digitalWrite(9, 1);   digitalWrite(13, 1);
    delay(DELAY);
    digitalWrite(8, 0);   digitalWrite(12, 0);
    delay(DELAY);
    if (IrReceiver.decode(&results)) {
      switch (results.value) {
        case RF:
          blinkk();   F = 1;   B = L = R = 0;   forward();    break;
        case RB:
          blinkk();   B = 1;   F = L = R = 0;   backward();   break;
        case RL:
          blinkk();   L = 1;   F = B = R = 0;   left();       break;
        case RR:
          blinkk();   R = 1;   F = B = L = 0;                 break;
        case RS:
          blinkk();   F = B = L = R = 0;        stopp();      break;
        case CF:
          blinkk();   F = 1;  B = L = R = 0;    forward();    break;
        case CB:
          blinkk();   B = 1;  F = L = R = 0;    backward();   break;
        case CL:
          blinkk();   L = 1;  F = B = R = 0;    left();       break;
        case CR:
          blinkk();   R = 1;  F = B = L = 0;                  break;
        case CS:
          blinkk();   F = B = L = R = 0;        stopp();      break;
      }
      Serial.println(results.value);
      IrReceiver.resume();
    }
  }
}
