#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include "Exports.h"

enum class TransportType {
	Ground = 1,
	Air = 2
};

class RACING_API Transport {
protected:
	std::string name;
	double speed;
	TransportType type;

public:
	Transport(const std::string& name, double speed, TransportType type);
	virtual ~Transport() = default;

	std::string getName() const;
	double getSpeed() const;
	TransportType getType() const;

	virtual double calcTime(double distance) const = 0;
};
#endif