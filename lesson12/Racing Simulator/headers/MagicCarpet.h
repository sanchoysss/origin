#ifndef MAGIC_CARPET_H
#define MAGIC_CARPET_H

#include "Air.h"

class RACING_API MagicCarpet : public Air {
public:
	MagicCarpet();
	double getReductionFactor(double distance) const override;

};
#endif
