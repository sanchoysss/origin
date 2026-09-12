#include "Air.h"

Air::Air(const std::string& name, double speed) :
	Transport(name, speed, TransportType::Air) {}

double Air::calcTime(double distance) const {
	double factor = getReductionFactor(distance);
	double ReducedDistance = distance * (1.0 - factor / 100.0);
	return ReducedDistance / speed;
};