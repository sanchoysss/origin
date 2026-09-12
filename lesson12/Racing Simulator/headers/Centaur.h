#ifndef CENTAUR_H
#define CENTAUR_H

#include "Ground.h"

class RACING_API Centaur : public Ground {
public:
	Centaur();
	double getRestTime(int RestNumber) const override;

};
#endif