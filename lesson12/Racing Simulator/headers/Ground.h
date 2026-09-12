#ifndef GROUND_H
#define GROUND_H

#include "Transport.h"

class RACING_API Ground : public Transport {
protected:
	double TimeBeforeRest;
public:
	Ground(const std::string& name, double speed, double TimeBeforeRest);
	virtual ~Ground() = default;

	virtual double getRestTime(int RestNumber) const = 0;
	double calcTime(double distance) const override;
};
#endif
