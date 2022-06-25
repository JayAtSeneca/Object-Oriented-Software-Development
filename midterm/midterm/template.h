#include <string>
/*
	for this template to run it should support:
	operator+
	operator= (assignment operator)
*/
template <typename T>
void add(const T arr1[], const T arr2[],T arr3[], size_t length) {

	for (size_t i = 0u; i < length; i++) {
		arr3[i] = arr1[i] + arr2[i];
	}
}

template<>
void add<std::string>(const std::string arr1[], const std::string arr2[],std::string arr3[], size_t length) {
	for (size_t i = 0u; i < length; i++) {
		arr3[i] = arr1[i] + ' ' + arr2[i];
	}
}