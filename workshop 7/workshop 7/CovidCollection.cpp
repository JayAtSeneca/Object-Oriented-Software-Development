#include "CovidCollection.h"
#include <iomanip>
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

	void CovidCollection::cleanList()
	{
		//TODO: try using & in lambda
		std::transform(m_collection.begin(), m_collection.end(), m_collection.begin(), [=](Covid covid) {
			if (covid.m_variant == "[None]")
				covid.m_variant = "";
			return covid;
		});
	}

	bool CovidCollection::inCollection(const char* variantName) const
	{
		return std::any_of(m_collection.begin(), m_collection.end(), [variantName](Covid covid) {
			return covid.m_variant.c_str() == variantName;
		});
	}

	std::list<Covid> CovidCollection::getListForCountry(const char* countryName) const
	{
		std::list<Covid> val{};
		std::copy_if(m_collection.begin(), m_collection.end(), std::inserter(val, val.begin()), [=](const Covid& covid) {return covid.m_country.c_str() == countryName; });
		return val;
	}

	std::list<Covid> CovidCollection::getListForVariant(const char* variantName) const
	{
		std::vector<Covid> copy(m_collection.begin(), m_collection.end());
		std::list<Covid> collection{};
		std::remove_if(copy.begin(), copy.end(), [=](const Covid& covid) {
			return covid.m_variant.c_str() != variantName;
		});
		std::copy(copy.begin(), copy.end(), std::back_inserter(collection));
		return collection;
	}

	void CovidCollection::display(std::ostream& out)const {
		std::for_each(m_collection.begin(), m_collection.end(), [&](const Covid& covid) { out << covid << std::endl; });
		size_t totalCases = 0u, totalDeaths = 0u;
		std::for_each(m_collection.begin(), m_collection.end(), [&](const Covid& covid) {totalCases += covid.m_numOfCases; });
		std::for_each(m_collection.begin(), m_collection.end(), [&](const Covid& covid) {totalDeaths += covid.m_numOfDeaths; });
		out.fill('-');
		out << std::setw(88) << "" << std::endl;
		out.fill(' ');
		out << "|" << std::setw(49) << " " << "Total Cases Around the World:  " << totalCases << " |" << std::endl;
		out << "|" << std::setw(48) << " " << "Total Deaths Around the World:  " << totalDeaths << " |" << std::endl;

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

	void CovidCollection::sort(const char* fieldName) {
		if (fieldName == "country") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {return a.m_country < b.m_country; });
		}
		else if (fieldName == "variant") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {return a.m_variant < b.m_variant; });
		}
		else if (fieldName == "cases") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {return a.m_numOfCases < b.m_numOfCases; });
		}
		else if (fieldName == "deaths") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {return a.m_numOfDeaths < b.m_numOfDeaths; });
		}
		else {
			throw "Error: no field exists";
		}
	}

}