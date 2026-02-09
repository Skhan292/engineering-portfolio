#include "Motor.h"
#include <iostream>

Motor::Motor() {
    speed = 0;
    enabled = false;
}

void Motor::setSpeed(int s) {
    speed = s;
}

int Motor::getSpeed() const {
    return speed;
}

void Motor::enable() {
    enabled = true;
}

void Motor::disable() {
    enabled = false;
}

bool Motor::isEnabled() const {
    return enabled;
}

void Motor::print() const {
    std::cout << "  Speed: " << speed
              << " | Enabled: " << (enabled ? "Yes" : "No") 
              << std::endl;
}
