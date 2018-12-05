#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic {
    int triggerPin;
    int echoPin;


  public:
    Ultrasonic(int trig, int echo);
    void start();
    void pulse();
};
#endif
