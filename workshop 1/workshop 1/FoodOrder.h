#ifndef SDDS_FOOD_ORDER_H
#define SDDS_FOOD_ORDER_H

#include <iostream>

namespace sdds
{
	extern double g_taxrate;
	extern double g_dailydiscount;
	class FoodOrder {
		char m_name[10]{];
		char m_description[25]{};
		double m_price{};
		bool m_special{];
	public:
		FoodOrder() {};
		std::istream& read(std::istream& istr);
		std::ostream& display(std::ostream& ostr = std::cout);
	};
}
#endif // !SDDS_FOOD_ORDER_H
