#ifndef FAST_CAMEL_H
#define FAST_CAMEL_H

#include "Ground.h"

class RACING_API FastCamel : public Ground {
public:
	FastCamel();
	double getRestTime(int RestNumber) const override;

};
#endif