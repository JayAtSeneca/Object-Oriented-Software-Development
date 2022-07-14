#ifndef SDDS_COVID_COLLECTION_H
#define SDDS_COVID_COLLECTION_H

#include <iostream>
#include <vector>
#include <string>

namespace sdds {
	struct Covid {
		std::string m_country{};
		std::string m_city{};
		std::string m_variant{};
		size_t m_numOfCases{};
		size_t m_year{};
		size_t m_numOfDeaths{};
	};

	class CovidCollection {
		std::vector<Covid> m_collection;
		std::string trim(std::string str)const;
	public:
		CovidCollection(const char* fileName);
		void display(std::ostream& out)const;
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif // !SDDS_COVID_COLLECTION_H
