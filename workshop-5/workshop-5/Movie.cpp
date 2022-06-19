#include "Movie.h"
#include <iomanip>
using namespace std;
namespace sdds {
	std::string& Movie::trim(std::string& str) const
	{
		while (str[0] == ' ') {
			str.erase(0, str.find_first_not_of(' '));
		}
		while (str[str.size() - 1] == ' ') {
			str.erase(str.find_last_not_of(' ') + 1);
		}
		return str;
	}
	Movie::Movie(const std::string& strMovie)
	{
		string data = strMovie;
		string title, year, description;

		title = data.substr(0, data.find(','));
		data = data.erase(0, data.find(',') + 1);

		year = data.substr(0, data.find(','));
		data = data.erase(0, data.find(',') + 1);

		description = data;

		m_year = stoi(trim(year));
		m_title = trim(title);
		m_description = trim(description);
	}
	const std::string& Movie::title() const
	{
		return m_title;
	}
	std::ostream& operator<<(std::ostream& os, const Movie& m)
	{
		os << std::setw(40) << std::right << m.m_title << " | "
			<< std::setw(4) << std::right << m.m_year << " | "
			<< std::left << m.m_description << std::endl;

		return os;
	}
}