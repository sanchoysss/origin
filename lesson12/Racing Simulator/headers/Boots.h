#ifndef BOOTS_H
#define BOOTS_H

#include "Ground.h"

class RACING_API Boots : public Ground {
public:
	Boots();
	double getRestTime(int RestNumber) const override;

};
#endif
