#ifndef BROOM_H
#define BROOM_H

#include "Air.h"

class RACING_API Broom : public Air {
public:
	Broom();
	double getReductionFactor(double distance) const override;

};
#endif
