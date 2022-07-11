
#include "Autoshop.h"

namespace sdds {
	Autoshop::~Autoshop(){
		for (auto i = m_vehicles.begin(); i < m_vehicles.end(); i++) {
			delete* i;
		}
	}
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle){
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (size_t i = 0; i < m_vehicles.size(); i++) {
			m_vehicles[i]->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}
}