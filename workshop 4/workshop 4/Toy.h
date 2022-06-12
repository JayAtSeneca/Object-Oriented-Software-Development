#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include <iostream>
#include <string>

namespace sdds {
	class Toy {
		size_t m_orderId{};
		std::string m_name{};
		int m_numItems{};
		double m_price{};
		static const double m_tax;
		std::string& trim(std::string& str)const;
	public:
		Toy();
		Toy(const std::string& str);
		void update(int numItems);
		virtual ~Toy();
		std::ostream& display(std::ostream& ostr = std::cout)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Toy& src);
}

#endif // !SDDS_TOY_H
