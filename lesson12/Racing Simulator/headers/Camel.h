#ifndef CAMEL_H
#define CAMEL_H

#include "Ground.h"

class RACING_API Camel : public Ground {
public:
	Camel();
	double getRestTime(int RestNumber) const override;

};
#endif