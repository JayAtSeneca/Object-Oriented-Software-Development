
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		virtual ~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles);
	};
	template <typename T>
	void Autoshop::select(T test, std::list<const Vehicle*>& vehicles) {
		for (auto i = m_vehicles.begin(); i < m_vehicles.end(); i++) {
			if (test(*i)) {
				vehicles.push_back(*i);
			}
		}
	}
}

#endif