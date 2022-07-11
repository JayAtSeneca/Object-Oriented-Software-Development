#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <string>
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
	std::string trim(std::string& str);
	bool isInteger(const std::string& str);
}
#endif