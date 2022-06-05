#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>
#include <string>

namespace sdds {
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		// added default constructor
		Pair() :m_key{}, m_value{}{};
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};
		const std::string& getKey()const;
		const std::string& getValue()const;
		std::ostream& display(std::ostream& ostr = std::cout)const;
		bool operator==(const Pair& item);

	};
	std::ostream& operator<<(std::ostream& ostr, const Pair& p);
}
#endif // !SDDS_PAIR_H
