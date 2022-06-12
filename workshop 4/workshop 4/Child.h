#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include <iostream>
#include <string>
namespace sdds {
	class Toy;

	class Child {
		const sdds::Toy** m_toyPtrs{};
		size_t m_size{};
		int m_age{};
		std::string m_name{};
		void deallocate();
	public:
		Child();
		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size()const;
		std::ostream& display(std::ostream& ostr)const;

		Child(const Child& c);
		Child(Child&& c)noexcept;
		Child& operator=(const Child& c);
		Child& operator=(Child&& c)noexcept;
		virtual ~Child();
	};
	std::ostream& operator<<(std::ostream& ostr, const Child& c);
}
#endif // !SDDS_CHILD_H
