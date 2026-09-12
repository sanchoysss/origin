#include "Eagle.h"

Eagle::Eagle() : Air("Орёл", 8) {}

double Eagle::getReductionFactor(double distance) const {
	return 6;
}