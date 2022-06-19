
#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds {
	std::string& Book::trim(std::string& str)const {
		while (str[0] == ' ') {
			str.erase(0, str.find_first_not_of(' '));
		}
		while (str[str.size() - 1] == ' ') {
			str.erase(str.find_last_not_of(' ') + 1);
		}
		return str;
	}

	const std::string& Book::title() const {
		return m_title;
	}

	const std::string& Book::country() const {
		return m_country;
	}

	const size_t& Book::year() const {
		return m_year;
	}
	double& Book::price() {
		return m_price;
	}

	Book::Book(const std::string& str) {
		string data = str;
		string author, title, country, year, price, description;
		author = data.substr(0, data.find(','));
		data = data.erase(0, data.find(',') + 1);

		title = data.substr(0, data.find(','));
		data = data.erase(0, data.find(',') + 1);

		country = data.substr(0, data.find(','));
		data = data.erase(0, data.find(',') + 1);

		price = data.substr(0, data.find(','));
		data = data.erase(0, data.find(',') + 1);

		year = data.substr(0, data.find(','));
		data = data.erase(0, data.find(',') + 1);

		description = data;

		m_year = stoi(trim(year));
		m_price = stod(trim(price));
		m_author = trim(author);
		m_title = trim(title);
		m_country = trim(country);
		m_description = trim(description);
	}

	std::ostream& operator<<(std::ostream& os, const Book b) {
		os << std::setw(20) << std::right << b.m_author << " | "
			<< std::setw(22) << std::right << b.m_title << " | "
			<< std::setw(5) << std::right << b.m_country << " | "
			<< std::setw(4) << std::right << b.m_year << " | "
			<< std::setw(6) << std::setiosflags(std::ios::fixed) << std::setprecision(2) << std::right << b.m_price << " | "
			<< std::left << b.m_description << std::endl;

		return os;
	}
}