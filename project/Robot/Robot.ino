#define TRIG 2
#define ECHO 3
#define SENSOR_CAP_CM 400
#include "Ultrasonic.h"
#include "Motor.h"
#define MAX_SPEED 255
#define SLOW_SPEED 110
#define US_DANGER 15

Motor motor1; //add pin numbers
Motor motor2; //add pin numbers

//add ultrasonic sensors

double temporary;
double ultrasonic;
long int startTime;
long int endTime;
Ultrasonic us(TRIG, ECHO);

void setup() {
  Serial.begin(9600);
  us.start();
  attachInterrupt(digitalPinToInterrupt(ECHO), usISR, CHANGE);
  pinMode(9, OUTPUT);
}

void loop() {
  us.pulse();
  analogWrite(9, 250);
  delay(2000);
  analogWrite(9, 110);
  delay(2000);
}

void usISR() {
  if (digitalRead(ECHO) == HIGH) {
    startTime = micros();
  } else {
    endTime = micros();
    temporary = (endTime - startTime) * 0.017;
    if (temporary < 200) {
      ultrasonic = temporary;
      Serial.println(ultrasonic);
    }
  }
}

void drive() {
  //US is < 10 cm
  if (ultrasonic < US_DANGER) {
    motor1.zero();
    motor2.zero();
    return;
  }

  // sensoren IR2 en IR3 zien lijn
  // Motor1 en Motor2 draaien vooruit
  if (IR1 == false && IR2 == true && IR3 == true && IR4 == false) {
    motor1.rotate(MAX_SPEED);
    motor2.rotate(MAX_SPEED);
  }

  // Sensor IR3 ziet geen lijn
  // Motor1 moet minder snel draaien
  if (IR1 == false && IR2 == true && IR3 == false && IR4 == false) {
    motor1.rotate(SLOW_SPEED);
    motor2.rotate(MAX_SPEED);
  }

  // Sensor IR2 ziet geen lijn
  // Motor2 moet minder snel draaien
  if (IR1 == false && IR2 == false && IR3 == true && IR4 == false) {
    motor1.rotate(MAX_SPEED);
    motor2.rotate(SLOW_SPEED);
  }
