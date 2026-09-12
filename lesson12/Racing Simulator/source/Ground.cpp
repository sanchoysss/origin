#include "Ground.h"
#include <cmath>

Ground::Ground(const std::string& name, double speed, double TimeBeforeRest) :
	Transport(name, speed, TransportType::Ground), TimeBeforeRest(TimeBeforeRest) {
}

double Ground::calcTime(double distance) const {
	double AllTime = distance / speed;
	int RestCount = static_cast<int>(AllTime / TimeBeforeRest);

	if (std::fmod(AllTime, TimeBeforeRest) == 0) {
		RestCount--;
	}

	double TotalRestTime = 0;
	for (int i = 1; i <= RestCount; i++) {
		TotalRestTime += getRestTime(i);
	}

	return AllTime + TotalRestTime;
}
