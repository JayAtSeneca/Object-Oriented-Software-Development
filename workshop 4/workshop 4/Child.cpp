#include "Child.h"
#include "Toy.h"
using namespace std;
namespace sdds {
	Child::Child() :m_name{ 0 }, m_age{ 0 }, m_size{ 0 }{

	}
	Child::Child(std::string name, int age, const Toy* toys[], size_t count) : m_name{ name }, m_age{ age } {
		m_size = count;
		m_toyPtrs = new const sdds::Toy * [m_size];
		for (size_t i = 0; i < m_size; i++) {
			m_toyPtrs[i] = new Toy(*toys[i]);
		}
	}
	size_t Child::size()const {
		return m_size;
	}
	std::ostream& Child::display(std::ostream& ostr)const {
		static int count = 0;
		ostr << "--------------------------" << std::endl;
		ostr << "Child " << ++count << ": " << m_name << " " << m_age << " years old:" << std::endl;
		ostr << "--------------------------" << std::endl;
		if (m_size == 0) {
			ostr << "This child has no toys!" << std::endl;
		}
		else {
			for (size_t i = 0; i < m_size; i++) {
				ostr << *m_toyPtrs[i];
			}
		}
		ostr << "--------------------------" << std::endl;
		return ostr;
	}

	Child::~Child() {
		for (size_t i = 0; i < m_size; i++) {
			delete m_toyPtrs[i];
			m_toyPtrs[i] = nullptr;
		}
		delete[] m_toyPtrs;
	}

	Child::Child(const Child& c) {
		*this = c;
	}

	Child& Child::operator=(const Child& c) {
		if (this != &c) {
			deallocate();
			if (c.m_name.c_str()) {
				m_name = c.m_name;
				m_age = c.m_age;
				m_size = c.m_size;
				m_toyPtrs = new const sdds::Toy * [m_size];
				for (size_t i = 0; i < m_size; i++) {
					m_toyPtrs[i] = new Toy(*c.m_toyPtrs[i]);
				}
			}
		}
		return *this;
	}

	Child::Child(Child&& c) noexcept{
		*this = std::move(c);
	}

	Child& Child::operator=(Child&& c)noexcept {
		if (this != &c) {
			deallocate();
			if (c.m_name.c_str()) {
				m_name = c.m_name;
				m_age = c.m_age;
				m_size = c.m_size;
				m_toyPtrs = c.m_toyPtrs;
				c.m_size = 0;
				c.m_name = "";
				c.m_age = 0;
				c.m_toyPtrs = nullptr;
			}
		}
		return *this;
	}

	void Child::deallocate() {
		if (m_toyPtrs != nullptr) {
			for (size_t i = 0; i < m_size; i++) {
				delete m_toyPtrs[i];
				m_toyPtrs[i] = nullptr;
			}
			delete[] m_toyPtrs;
			m_toyPtrs = nullptr;
			m_size = 0;
		}
	}
	std::ostream& operator<<(std::ostream& ostr, const Child& c) {
		return c.display(ostr);
	}
}