#pragma once
#include <iostream>
template <typename T = int, typename V = int>
class Calculator {
	static int uses;
public:
	auto add(const T v1, const V v2)->decltype(v1 + v2) {
		uses++;
		return v1 + v2;
	}
	auto minus(const T v1, const V v2)->decltype(v1 - v2) {
		uses++;
		return v1 - v2;
	}
	auto multiply(const T v1, const T v2)->decltype(v1* v2) {
		uses++;
		return v1 * v2;
	}
	static int used() { return uses; }
};
template <typename T, typename V>
int Calculator<T, V>::uses = 0;
int main() {
	Calculator<int, double> c;
	auto x = c.minus(1, 1.1);
	std::cout << "x: " << x << std::endl;
	x = c.multiply(3, 3.3);
	std::cout << "x: " << x << std::endl;
	std::cout << "uses: " << c.used() << std::endl;
	Calculator<int, double> c2;
	std::cout << "c2 uses: " << c2.used() << std::endl;
}
