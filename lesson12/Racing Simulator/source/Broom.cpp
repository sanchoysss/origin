#include "Broom.h"

Broom::Broom() : Air("Орёл", 8) {}

double Broom::getReductionFactor(double distance) const {
	int thousands = static_cast<int>(distance / 1000);
	return thousands;
}