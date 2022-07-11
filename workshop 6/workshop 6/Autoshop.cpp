//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: July 10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Autoshop.h"

namespace sdds {
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out)const
	{
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (auto v : m_vehicles)
		{
			v->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop() {
		for (auto v : m_vehicles)
		{
			delete v;
			v = nullptr;
		}
	}

}