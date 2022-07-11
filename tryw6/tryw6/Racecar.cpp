#include <string>
#include "Racecar.h"
using namespace std;
namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in){
		string temp;
		getline(in,temp,',');
		m_booster = stod(trim(temp));
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return (Car::topSpeed() + (Car::topSpeed() * m_booster));
	}
}