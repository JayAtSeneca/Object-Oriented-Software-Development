#include <deque>
#include <iostream>
using namespace std;
int main() {
	std::deque<double> prices(3, 10.50), costs;
	prices.back() = 32.43;
	prices.pop_front();
	for (int i = 0; i < prices.size(); i++) {
		std::cout << prices[i] << " ";
	}
	std::cout << std::endl;
	costs = prices;
	costs.push_front(5.64);
	costs.push_front(20.31);
	costs.at(1) += 10.0;
	for (int i = 0; i < costs.size(); i++) {
		std::cout << costs[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}