//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: July 10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in) :Car(in) {
		in >> m_booster;
		in.ignore(1000, '\n');
	}
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}
