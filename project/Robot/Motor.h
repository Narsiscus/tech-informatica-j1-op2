#ifndef MOTOR_H
#define MOTOR_H

class Motor {
    int pwmPin;
    int logicF;
    int logicB;

  public:
    Motor(int pwm, int logicF, int logicB);
    Motor();
    void start();
    void rotate(int rotspeed);
    void zero();
};
#endif
