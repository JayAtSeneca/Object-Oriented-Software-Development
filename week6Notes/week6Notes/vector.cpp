#include <iostream>
#include <vector>
#include <exception>
using namespace std;
int main() {
	std::vector<double> prices;
	if (prices.empty()) {
		std::cout << "prices is empty" << endl;
	}
	prices.push_back(10.43);
	prices.push_back(20.54);
	prices.push_back(32.43);
	for (int i = 0; i < prices.size(); i++) {
		std::cout << prices[i] << " ";
	}
	std::cout << std::endl;
	prices.front() = 54.11;
	prices.pop_back();
	for (int i = 0; i < prices.size(); i++) {
		std::cout << prices[i] << " ";
	}
	std::cout << std::endl;
	try {
		prices.at(1) += 15;
	}
	catch (std::out_of_range e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << prices[1] << std::endl;
	return 0;
}