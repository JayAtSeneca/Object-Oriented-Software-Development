#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include "Vehicle.h"
#include "Utilities.h"

namespace sdds {
	class Car :public Vehicle{
		std::string m_make{};
		char m_condition{};
		double m_topSpeed{};
	public:
		Car() {};
		virtual ~Car() {};
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif