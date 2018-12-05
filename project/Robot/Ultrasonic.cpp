#include <Arduino.h>
#include "Ultrasonic.h"

int triggerPin;
int echoPin;

Ultrasonic::Ultrasonic(int trig, int echo) {
  triggerPin = trig;
  echoPin = echo;
}

void Ultrasonic::start() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void Ultrasonic::pulse() {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
}
