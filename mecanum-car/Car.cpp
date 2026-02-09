#include "Car.h"
#include <iostream>


Car::Car() {
    if (gpioInitialise() < 0) {
        std::cerr << "pigpio init failed\n";
        // You might want to throw or set an error flag
    }

    // Example pin mapping – change to match YOUR wiring
    
    
    
     FL_IN1 =19; FL_IN2 = 26;
    FR_IN1 = 17; FR_IN2 = 27;
    RL_IN1 = 23;  RL_IN2 = 24;
    RR_IN1 = 20; RR_IN2 = 21;
    

    gpioSetMode(FL_IN1, PI_OUTPUT);
    gpioSetMode(FL_IN2, PI_OUTPUT);
    gpioSetMode(FR_IN1, PI_OUTPUT);
    gpioSetMode(FR_IN2, PI_OUTPUT);
    gpioSetMode(RL_IN1, PI_OUTPUT);
    gpioSetMode(RL_IN2, PI_OUTPUT);
    gpioSetMode(RR_IN1, PI_OUTPUT);
    gpioSetMode(RR_IN2, PI_OUTPUT);

    // Optionally stop everything at start
    gpioWrite(FL_IN1, 0); gpioWrite(FL_IN2, 0);
    gpioWrite(FR_IN1, 0); gpioWrite(FR_IN2, 0);
    gpioWrite(RL_IN1, 0); gpioWrite(RL_IN2, 0);
    gpioWrite(RR_IN1, 0); gpioWrite(RR_IN2, 0);
}

Car::~Car() {
    // Stop motors before shutting down
    gpioWrite(FL_IN1, 0); gpioWrite(FL_IN2, 0);
    gpioWrite(FR_IN1, 0); gpioWrite(FR_IN2, 0);
    gpioWrite(RL_IN1, 0); gpioWrite(RL_IN2, 0);
    gpioWrite(RR_IN1, 0); gpioWrite(RR_IN2, 0);

    gpioTerminate();
}

void Car::moveForward() {
    std::cout << "Moving forward\n";

    // For mecanum, this is “simple forward”:
    // FL & RL forward, FR & RR forward
    gpioWrite(FL_IN1, 1); gpioWrite(FL_IN2, 0);
    gpioWrite(FR_IN1, 1); gpioWrite(FR_IN2, 0);
    gpioWrite(RL_IN1, 1); gpioWrite(RL_IN2, 0);
    gpioWrite(RR_IN1, 1); gpioWrite(RR_IN2, 0);
}

void Car::moveBackward() {
    std::cout << "Moving backward\n";

    gpioWrite(FL_IN1, 0); gpioWrite(FL_IN2, 1);
    gpioWrite(FR_IN1, 0); gpioWrite(FR_IN2, 1);
    gpioWrite(RL_IN1, 0); gpioWrite(RL_IN2, 1);
    gpioWrite(RR_IN1, 0); gpioWrite(RR_IN2, 1);
}

void Car::turnLeft() {
    std::cout << "Turning left (spin)\n";

    // Left wheels backward, right wheels forward
    gpioWrite(FL_IN1, 0); gpioWrite(FL_IN2, 1);
    gpioWrite(FR_IN1, 1); gpioWrite(FR_IN2, 0);
    gpioWrite(RL_IN1, 0); gpioWrite(RL_IN2, 1);
    gpioWrite(RR_IN1, 1); gpioWrite(RR_IN2, 0);
}

void Car::turnRight() {
    std::cout << "Turning right (spin)\n";

    gpioWrite(FL_IN1, 1); gpioWrite(FL_IN2, 0);
    gpioWrite(FR_IN1, 0); gpioWrite(FR_IN2, 1);
    gpioWrite(RL_IN1, 1); gpioWrite(RL_IN2, 0);
    gpioWrite(RR_IN1, 0); gpioWrite(RR_IN2, 1);
}
void Car::stop() {
    std::cout << "Stopping car\n";

    gpioWrite(FL_IN1, 0); gpioWrite(FL_IN2, 0);
    gpioWrite(FR_IN1, 0); gpioWrite(FR_IN2, 0);
    gpioWrite(RL_IN1, 0); gpioWrite(RL_IN2, 0);
    gpioWrite(RR_IN1, 0); gpioWrite(RR_IN2, 0);
}

// The rest can just be placeholders for now:
//void Car::cameraOn()  { camOn = true;  std::cout << "Camera ON (stub)\n"; }
//void Car::cameraOff() { camOn = false; std::cout << "Camera OFF (stub)\n"; }
//void Car::takePicture(){ std::cout << "Take picture (stub)\n"; }
//void Car::printStatus(){
    //std::cout << "Camera: " << (camOn ? "ON" : "OFF") << "\n";
//}
