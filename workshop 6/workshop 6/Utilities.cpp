//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: July 10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include"Utilities.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* vehicle = nullptr;

		char type = '\0';
		in >> type;
		in.ignore(1000, ',');
		if (type == 'c' || type == 'C')
		{
			tag = 'c';
			vehicle = new Car(in);
		}
		else if (type == 'r' || type == 'R')
		{
			tag = 'r';
			vehicle = new Racecar(in);
		}
		else
		{
			in.ignore(1000, '\n');
			std::string msg = "Unrecognized record type: [";
			msg += type;
			msg += "]";
			throw msg;
		}
		return vehicle;
	}
}