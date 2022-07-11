//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: July 10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <sstream>
#include <iomanip>
#include "Car.h"

char tag = '\0';
namespace sdds {
	Car::Car(std::istream& in) {
		
		getline(in, m_maker, ',');
		m_maker.erase(m_maker.find_last_not_of(' ') + 1);

		
		char condition;
		in >> condition;
		if (condition == ',')
		{
			condition = 'n';
		}
		else if (condition == ' ')
		{
			condition = 'n';
			in.ignore(1000, ',');
		}
		else
		{
			in.ignore(1000, ',');
		}

		if (condition != 'n' && condition != 'u' && condition != 'b')
		{
			in.ignore(1000, '\n');
			throw "Invalid record!";
		}


		if (in >> m_topSpeed)
		{
			if (tag == 'c')
			{
				in.ignore(1000, '\n');
			}
			else if (tag == 'r')
			{
				in.ignore(1000, ',');
			}
		}
		else
		{
			in.clear();
			in.ignore(1000, '\n');
			throw "Invalid record!";
		}

		
		switch (condition) {
		case 'n':
			m_condition = Condition::newCar;
			break;
		case 'u':
			m_condition = Condition::used;
			break;
		case 'b':
			m_condition = Condition::broken;
			break;
		default:
			break;
		}
	}

	std::string Car::condition()const {
		std::string condition;
		switch (m_condition) {
		case Condition::newCar:
			condition = "new";
			break;
		case Condition::used:
			condition = "used";
			break;
		case Condition::broken:
			condition = "broken";
			break;
		default:
			break;
		}
		return condition;
	}

	double Car::topSpeed()const {
		return m_topSpeed;
	}
	void Car::display(std::ostream& out) const {
		out << "| " << std::setw(10) << std::right << m_maker;
		out << " | " << std::setw(6) << std::left << condition();
		out << " | " << std::fixed << std::setw(6) << std::setprecision(2) << topSpeed() << " |";
	}
}