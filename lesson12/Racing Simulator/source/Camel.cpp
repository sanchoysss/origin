#include "Camel.h"

Camel::Camel() : Ground("Верблюд", 10, 30) {};

double Camel::getRestTime(int RestNumber) const {
	if (RestNumber == 1) {
		return 5;
	}
	else {
		return 8;
	}
}