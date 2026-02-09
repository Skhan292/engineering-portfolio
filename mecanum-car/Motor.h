#ifndef MOTOR_H
#define MOTOR_H

#include <string>

class Motor {
private:
    int speed;      // -100 to 100
    bool enabled;   // motor on/off

public:
    Motor();

    void setSpeed(int s);
    int getSpeed() const;

    void enable();
    void disable();
    bool isEnabled() const;

    void print() const;
};

#endif
