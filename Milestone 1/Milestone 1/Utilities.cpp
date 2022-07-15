#include <iostream>
#include "Utilities.h"
using namespace std;
namespace sdds {
	char Utilities::m_delimiter{};

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return size_t();
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		return std::string();
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
	}
	char Utilities::getDelimiter()
	{
		return 0;
	}
}