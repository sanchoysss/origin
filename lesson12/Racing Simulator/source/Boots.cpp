#include "Boots.h"

Boots::Boots() : Ground("Ботинки-вездеходы", 6, 60) {}

double Boots::getRestTime(int RestNumber) const {
	if (RestNumber == 1) {
		return 10;
	}
	return 5;
}