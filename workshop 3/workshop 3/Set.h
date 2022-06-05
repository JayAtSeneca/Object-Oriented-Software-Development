#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>
#include <string>
#include "Collection.h"

namespace sdds {
	template<typename T>
	class Set :public Collection<T, 100> {
	public:
		Set();
		virtual ~Set() {};
		bool add(const T& item);
	};

	template <typename T>
	Set<T>::Set() {

	}

	template<typename T>
	bool Set<T>::add(const T& item) {
		bool done = false;
		if (Collection<T, 100>::size() < 100) {
			bool flag = false;
			for (size_t i = 0; i < Collection<T, 100>::size() && !flag; i++) {
				if (Collection<T, 100>::operator[](i) == item) {
					flag = true;
				}
			}
			if (!flag) {
				done = Collection<T, 100>::add(item);
			}
		}
		return done;
	}

	template<>
	bool Set<double>::add(const double& item) {
		bool done = false;
		if (Collection<double, 100>::size() < 100) {
			bool flag = false;
			for (size_t i = 0; i < Collection<double, 100>::size(); i++) {
				if (std::fabs(Collection<double, 100>::operator[](i) - item) <= 0.01)
				{
					flag = true;
				}
			}
			if (!flag) {
				done = Collection<double, 100>::add(item);
			}
		}
		return done;
	}
}
#endif // !SDDS_SET_H
