#include "CovidCollection.h"
#include <algorithm>
#include <fstream>
using namespace std;
namespace sdds {
	std::string CovidCollection::trim(std::string str) const
	{
		while (str[0] == ' ') {
			str.erase(0, str.find_first_not_of(' '));
		}
		while (str[str.size() - 1] == ' ') {
			str.erase(str.find_last_not_of(' ') + 1);
		}
		return str;
	}
	CovidCollection::CovidCollection(const char* fileName) {
		std::ifstream file(fileName);
		if (file.is_open()) {
			Covid temp; // TODO: Take it inside the loop
			std::string str{};
			while (file) {
				getline(file, str);
				if (str != "") {
					temp.m_country = trim(str.substr(0, 25));
					temp.m_city = trim(str.substr(25, 25));
					temp.m_variant = trim(str.substr(50, 25));
					temp.m_year = std::stoi(trim(str.substr(75, 5)));
					temp.m_numOfCases = std::stoul(trim(str.substr(80, 5)));
					temp.m_numOfDeaths = std::stoul(trim(str.substr(85, 5)));
					m_collection.push_back(temp);
				}
			}
			file.close();
		}
		else {
			throw "Cannot open file";
		}
	}

	void CovidCollection::display(std::ostream& out)const {
		std::for_each(m_collection.begin(), m_collection.end(), [&](const Covid& covid) { out << covid << std::endl; });
	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		out << "| ";
		out.unsetf(ios::right);
		out.setf(ios::left);
		out.width(21);
		out << theCovid.m_country;
		out << " | ";
		out.width(15);
		out << theCovid.m_city;
		out << " | ";
		out.width(20);
		out << theCovid.m_variant;
		out << " | ";
		out.unsetf(ios::left);
		out.setf(ios::right);
		out.width(6);
		(theCovid.m_year < 0 || theCovid.m_year>9999) ? out << ' ' : out << theCovid.m_year;
		out << " | ";
		out.width(4);
		out << theCovid.m_numOfCases;
		out << " | ";
		out.width(3);
		out << theCovid.m_numOfDeaths;
		out << " | ";
		out.unsetf(ios::right);
		return out;
	}

}