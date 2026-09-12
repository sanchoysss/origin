#ifndef AIR_H
#define AIR_H

#include "Transport.h"

class RACING_API Air : public Transport {
public:
	Air(const std::string& name, double speed);
	virtual ~Air() = default;

	virtual double getReductionFactor(double distance) const = 0;
	double calcTime(double distance) const override;
};
#endif
