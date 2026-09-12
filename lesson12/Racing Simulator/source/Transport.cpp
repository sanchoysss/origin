#include "Transport.h"

Transport::Transport(const std::string& name, double speed, TransportType type)
    : name(name), speed(speed), type(type) {
}

std::string Transport::getName() const {
    return name;
}

double Transport::getSpeed() const {
    return speed;
}

TransportType Transport::getType() const {
    return type;
}