#include <Arduino.h>
#include "Motor.h"

int pwmPin;
int logicF;
int logicB;

Motor::Motor(int pwm, int forward, int backward){
  pwmPin = pwm;
  logicF = forward;
  logicB = backward;
}

//stub
Motor::Motor(){
  
}

void Motor::start(){
  pinMode(pwmPin, OUTPUT);
  pinMode(logicF, OUTPUT);
  pinMode(logicB, OUTPUT);
}

void Motor::rotate(int rotspeed){
  if(rotspeed > 0){
    digitalWrite(logicF, HIGH);
    digitalWrite(logicB, LOW);
    analogWrite(pwmPin, rotspeed);
  }
  if(rotspeed < 0){
    digitalWrite(logicF, LOW);
    digitalWrite(logicB, HIGH);
    analogWrite(pwmPin, abs(rotspeed));
  }
  else{
    digitalWrite(logicF, LOW);
    digitalWrite(logicB, LOW);
  }
}

void Motor::zero(){
  digitalWrite(logicF, LOW);
  digitalWrite(logicB, LOW);
}
