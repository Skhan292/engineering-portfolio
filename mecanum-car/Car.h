#pragma once
#include <pigpio.h>

class Car {
public:
    Car();              // sets up GPIO & pins
    ~Car();             // optional: stop + terminate

    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void stop();
    //void cameraOn();
    //void cameraOff();
    //void takePicture();
    //void printStatus();

private:
    // Example GPIO pins (BCM numbers)
    int FL_IN1, FL_IN2; // Front-left motor
    int FR_IN1, FR_IN2; // Front-right motor
    int RL_IN1, RL_IN2; // Rear-left motor
    int RR_IN1, RR_IN2; // Rear-right motor

    bool camOn = false;
};
//car.cpp, and car.h
