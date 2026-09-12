#ifndef RACE_H
#define RACE_H

#include <vector>
#include <string>
#include "Transport.h"

enum class RaceType {
	Ground = 1,
	Air = 2,
	Both = 3
};

struct RaceResult {
	std::string name;
	double time;
};

class RACING_API Race {
private:
	double distance;
	RaceType type;
	std::vector <Transport*> registeredTransports;
public:
	Race(double distance, RaceType type);

	double getDistance() const;
	RaceType getRaceType() const;

	bool addTransport(Transport* transport);

	std::vector<RaceResult> run();

	void clean();


};

#endif
