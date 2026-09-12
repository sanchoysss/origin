#include "MagicCarpet.h"

MagicCarpet::MagicCarpet() : Air("Ковер-самолет", 10) {}

double MagicCarpet::getReductionFactor(double distance) const {
	if (distance < 1000) { return 0; }
	if (distance < 5000) { return 3; }
	if (distance < 10000) { return 10; }
	return 5;
}