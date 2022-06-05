#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>
#include "Pair.h"
namespace sdds {
	template <typename T, size_t CAPACITY>
	class Collection {
		T m_array[CAPACITY]{};
		size_t m_size;
		static T m_dummy;
	public:
		Collection();
		size_t size()const;
		std::ostream& display(std::ostream& ostr = std::cout)const;
		virtual bool add(const T& item);
		T& operator[](int index);
		virtual ~Collection();
	};
	template<typename T, size_t CAPACITY>
	Collection<T, CAPACITY>::~Collection() {

	}

	template<typename T, size_t CAPACITY>
	Collection<T, CAPACITY>::Collection() : m_size{ 0 } {

	}

	template <typename T, size_t CAPACITY>
	size_t Collection<T, CAPACITY>::size()const {
		return m_size;
	}

	template <typename T, size_t CAPACITY>
	std::ostream& Collection<T, CAPACITY>::display(std::ostream& ostr)const {
		if (ostr) {
			ostr << "----------------------" << std::endl;
			ostr << "| Collection Content |" << std::endl;
			ostr << "----------------------" << std::endl;

			for (size_t i = 0; i < m_size; i++) {
				ostr << m_array[i] << std::endl;
			}
			ostr << "----------------------" << std::endl;
		}
		return ostr;
	}

	template <typename T, size_t CAPACITY>
	bool Collection<T, CAPACITY>::add(const T& item) {
		bool done = false;
		if (m_size < CAPACITY) {
			m_array[m_size++] = item;
			done = true;
		}
		return done;
	}

	template <typename T, size_t CAPACITY>
	T& Collection<T, CAPACITY>::operator[](int index) {
		return (index >= 0 && index < m_size) ? m_array[index] : m_dummy;
	}

	template <typename T, size_t CAPACITY>
	T Collection<T, CAPACITY>::m_dummy{};

	template <>
	sdds::Pair Collection<sdds::Pair, 100>::m_dummy{ "No Key","No Value" };
}
#endif // !SDDS_COLLECTION_H
