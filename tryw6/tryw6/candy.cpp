#include <string> 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <thread>
#include <memory>

using namespace std;

const double TAX = 0.13;
const double MIN_SUGAR = 120.50;

struct Candy {
	std::string name{};
	double sugarContent{};
	double weight{};
	double pricePerWeight{};
	double price{};
};

void totalPrice(Candy& candy) {
	candy.price = candy.pricePerWeight * candy.weight * TAX;
}

class CandyShop {
	std::vector<Candy> candies;
	void (*fn)(const std::vector<Candy>&) { nullptr };
	bool priceWithTax{};
public:
	CandyShop& operator+=(const Candy& candy) {
		if (candy.sugarContent >= MIN_SUGAR) {
			candies.push_back(candy);
			priceWithTax = false;
		}
		else {
			std::string errMessage("Not sweet enough: ");
			throw errMessage + candy.name;
		}
		return *this;
	}
	void processCandy() {
		if (std::any_of(candies.begin(), candies.end(), [](const Candy& c) {
			if (c.price == 0) {
				return true;
			}
			return false;
			})) {
			for (size_t i = 0; i < candies.size() / 2; i++) {
				std::thread t1(totalPrice, std::ref(candies[i]));
				std::thread t2(totalPrice, std::ref(candies[i + candies.size() / 2]));
				t1.join();
				t2.join();
			}
		}
		if (fn != nullptr) {
			fn(candies);
		}
		else {
			std::exit(2);
		}
	}
	void setDisplay(void (*fn)(const std::vector<Candy>&)) {
		this->fn = fn;
	}
};

void byPrice(const std::vector<Candy>& candies) {
	std::cout << "\nName Price\n";
	for (auto& c : candies)
		std::cout << c.name << ": " << std::fixed << std::setprecision(2) << c.price << std::endl;
}

void bySugarContent(const std::vector<Candy>& candies) {
	std::cout << "\nName SugarContent\n";
	for (auto& c : candies)
		std::cout << c.name << ": " << std::fixed << std::setprecision(2) << c.sugarContent << std::endl;
}

int main() {
	Candy candies[]{
	{ "Twix", 155.33, 50.4, 0.2 },
	{ "Candy Crisp", 140.22, 60.5, 0.25 },
	{ "KitKat", 130.22, 48.4, 0.29 },
	{ "Celery Sticks", 20, 45.2, 0.1 },
	{ "Toblerone", 180.44, 70.3, 0.30 },
	};

	std::unique_ptr<CandyShop> candyshop(new CandyShop());

	for (const auto& c : candies) {
		try
		{
			*candyshop += c;
			candyshop->setDisplay(byPrice);
			candyshop->processCandy();
			candyshop->setDisplay(bySugarContent);
			candyshop->processCandy();
		}
		catch (const std::string& err)
		{
			cout << err << std::endl;
		}

	}
	return 0;
}