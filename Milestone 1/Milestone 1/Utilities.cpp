#include <iostream>
#include "Utilities.h"
using namespace std;
namespace sdds {
	char Utilities::m_delimiter{};

	std::string Utilities::trim(std::string& str)const {
		while (str[0] == ' ') {
			str.erase(0, str.find_first_not_of(' '));
		}
		while (str[str.size() - 1] == ' ') {
			str.erase(str.find_last_not_of(' ') + 1);
		}
		return str;
	}

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string token{};
		if (more) {
			size_t position = str.find(getDelimiter(), next_pos);
			if (position != next_pos) {

				token = str.substr(next_pos, position - next_pos);
				trim(token);

				if (m_widthField < token.size())
					m_widthField = token.size();

				if (position != std::string::npos) {

					next_pos = str.find(m_delimiter, next_pos + 1) + 1;
					more = true;
				}
				else {

					next_pos = 0;
					more = false;
				}
			}
			else {
				more = false;
				throw std::string("Delimiter is found at next_pos");
			}
		}
		return token;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}


