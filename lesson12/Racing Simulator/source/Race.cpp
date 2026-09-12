#include "Race.h"
#include <algorithm>

Race::Race(double distance, RaceType type) : distance(distance), type(type) {}

double Race::getDistance() const {
    return distance;
}

RaceType Race::getRaceType() const {
    return type;
}

bool Race::addTransport(Transport* transport) {
    if (transport == nullptr) {
        return false;
    }
    if (type == RaceType::Ground && transport->getType() != TransportType::Ground) { 
        return false; 
    }
    if (type == RaceType::Air && transport->getType() != TransportType::Air) {
        return false;
    }

    bool IsDublicate = std::any_of(registeredTransports.begin(), registeredTransports.end(),
        [transport](const Transport* t) {return t->getName() == transport->getName();});

    if (IsDublicate) {
            return false;
    }


     registeredTransports.push_back(transport);
     return true;
}


std::vector<RaceResult> Race::run() {
    std::vector<RaceResult> results;
 
    for (const Transport* transport : registeredTransports) {
        results.push_back({ transport->getName(), transport->calcTime(distance) });
    }


    std::sort(results.begin(), results.end(),
        [](const RaceResult& a, const RaceResult& b) {
            return a.time < b.time;
        });

    return results;
}

void Race::clean() {
    registeredTransports.clear();

}


