//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: July 10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"

extern char tag;

namespace sdds {
	enum class Condition {
		newCar,
		used,
		broken
	};
	class Car : public Vehicle {
		std::string m_maker{};
		Condition m_condition{ Condition::newCar };
		double m_topSpeed{ 0.0 };
	public:
		Car(std::istream& in);
		std::string condition()const;
		double topSpeed()const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_CAR_H
