#ifndef SDDS_FOOD_ORDER_H
#define SDDS_FOOD_ORDER_H

#include <iostream>
 extern double g_taxrate;
 extern double g_dailydiscount;
namespace sdds
{
	
	class FoodOrder {
		char m_name[10]{};
		char* m_description{};
		double m_price{};
		bool m_special{};
	public:
		FoodOrder() {};
		FoodOrder(const FoodOrder& F);
		FoodOrder& operator=(const FoodOrder& F);
		~FoodOrder();
		std::istream& read(std::istream& istr);
		std::ostream& display(std::ostream& ostr = std::cout)const;
	};
	char* alcpy(const char* cstr);
}
#endif // !SDDS_FOOD_ORDER_H
