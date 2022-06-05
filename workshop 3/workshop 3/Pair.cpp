#include "Pair.h"
using namespace std;
namespace sdds
{

	const std::string& Pair::getKey() const
	{
		return m_key;
	}

	const std::string& Pair::getValue() const
	{
		return m_value;
	}

	std::ostream& Pair::display(std::ostream& ostr) const
	{
		if (ostr) {
			ostr.width(20);
			ostr << m_key << ": " << m_value;
		}
		return ostr;
	}

	bool Pair::operator==(const Pair& item)
	{
		return (m_key == item.m_key) ? true : false;
	}

	std::ostream& operator<<(std::ostream& ostr, const Pair& p)
	{
		return p.display(ostr);
	}

}