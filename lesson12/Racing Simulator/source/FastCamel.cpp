#include "FastCamel.h"

FastCamel::FastCamel() : Ground("Верблюд-быстроход", 40, 10) {};

double FastCamel::getRestTime(int RestNumber) const {
	if (RestNumber == 1) {
		return 5;
	}
	if (RestNumber == 2) {
		return 6.5;
	}
	return 8;
	
}