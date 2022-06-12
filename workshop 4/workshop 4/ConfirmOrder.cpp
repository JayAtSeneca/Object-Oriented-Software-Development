#include <iostream>
#include "ConfirmOrder.h"
#include "Toy.h"
using namespace std;

namespace sdds {
	ConfirmOrder::ConfirmOrder() : m_size{ 0 } {
		//default
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
		bool add = true;
		for (size_t i = 0; i < m_size && add; i++) {
			if (m_toys[i] == &toy) add = false;
		}
		if (add) {
			const sdds::Toy** temp = new const sdds::Toy * [m_size + 1];
			for (size_t i = 0; i < m_size; i++) {
				temp[i] = m_toys[i];
			}
			temp[m_size] = &toy;
			delete[] m_toys;
			m_toys = temp;
			m_size++;
		}
		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
		if (m_size > 0) {
			bool found = false;
			size_t index = 0;
			for (size_t i = 0; i < m_size && !found; i++) {
				if (m_toys[i] == &toy) {
					m_toys[i] = nullptr;
					found = true;
					index = i;
				}
			}
			if (found) {
				for (size_t j = index; j < m_size - 1; j++) {
					m_toys[j] = m_toys[j + 1];
				}
				m_toys[m_size - 1] = nullptr;
				m_size--;
			}
		}
		return *this;
	}

	std::ostream& ConfirmOrder::display(std::ostream& ostr)const {
		ostr << "--------------------------" << std::endl;
		ostr << "Confirmations to Send" << std::endl;
		ostr << "--------------------------" << std::endl;
		if (m_size == 0) {
			ostr << "There are no confirmations to send!" << std::endl;
		}
		else {
			for (size_t i = 0; i < m_size; i++) {
				ostr << *m_toys[i];
			}
		}
		ostr << "--------------------------" << std::endl;
		return ostr;
	}

	

	ConfirmOrder:: ~ConfirmOrder() {
		delete[] m_toys;
	}
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& c) {
		*this = c;
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& c) {
		if (this != &c) {
			deallocate();
			m_size = c.m_size;
			if (c.m_toys) {
				m_toys = new const sdds::Toy * [m_size];
				for (size_t i = 0; i < m_size; i++) {
					m_toys[i] = c.m_toys[i];
				}
			}
		}
		return *this;
	}

	ConfirmOrder::ConfirmOrder(ConfirmOrder&& c) noexcept{
		*this = std::move(c);
	}

	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& c) noexcept{
		if (this != &c) {
			deallocate();
			if (c.m_toys) {
				m_size = c.m_size;
				m_toys = c.m_toys;
				c.m_size = 0;
				c.m_toys = nullptr;
			}
		}
		return *this;
	}

	void ConfirmOrder::deallocate() {
		delete[] m_toys;
		m_toys = nullptr;
		m_size = 0;
	}

	std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& src) {
		return src.display(ostr);
	}

	
}