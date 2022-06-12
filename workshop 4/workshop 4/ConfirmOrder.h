#ifndef SDDS_CONFIRM_ORDER_H
#define SDDS_CONFIRM_ORDER_H
#include <iostream>
namespace sdds {
	class Toy;

	class ConfirmOrder {
		const sdds::Toy** m_toys{};
		size_t m_size;
		void deallocate();
	public:
		ConfirmOrder();
		ConfirmOrder& operator+=(const Toy& t);
		ConfirmOrder& operator-=(const Toy& t);
		std::ostream& display(std::ostream& ostr = std::cout)const;

		
		virtual ~ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& c);
		ConfirmOrder& operator=(const ConfirmOrder& c);
		ConfirmOrder(ConfirmOrder&& c) noexcept;
		ConfirmOrder& operator=(ConfirmOrder&& c)noexcept;
	};

	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& src);
}
#endif // !SDDS_CONFIRM_ORDER_H
