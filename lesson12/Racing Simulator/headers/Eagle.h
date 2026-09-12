#ifndef EAGLE_H
#define EAGLE_H

#include "Air.h"

class RACING_API Eagle : public Air {
public:
	Eagle();
	double getReductionFactor(double distance) const override;

};
#endif
