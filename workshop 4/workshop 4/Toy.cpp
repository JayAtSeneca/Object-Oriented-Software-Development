#include <iostream>
#include "Toy.h"
using namespace std;
namespace sdds {
	const double Toy::m_tax = 0.13;
	Toy::Toy() :m_orderId{ 0 }, m_name{ "" }, m_numItems{ 0 }, m_price{ 0.0 }{

	}
	std::string& Toy::trim(std::string& str)const {
		while (str[0] == ' ') {
			str.erase(0, str.find_first_not_of(' '));
		}
		while (str[str.size() - 1] == ' ') {
			str.erase(str.find_last_not_of(' ') + 1);
		}
		return str;
	}
	Toy::Toy(const std::string& str) {
		string data = str;
		string id, num, name, price;
		id = data.substr(0, data.find(":"));
		data = data.erase(0, data.find(":") + 1);

		name = data.substr(0, data.find(":"));
		data = data.erase(0, data.find(":") + 1);

		num = data.substr(0, data.find(":"));
		data = data.erase(0, data.find(":") + 1);

		price = data.substr(0, data.find(":"));

		m_orderId = std::stoul(trim(id));
		m_name = trim(name);
		m_numItems = std::stoi(trim(num));
		m_price = std::stod(trim(price));
	}
	void Toy::update(int numItems) {
		m_numItems = numItems;
	}
	Toy::~Toy() {}

	std::ostream& Toy::display(std::ostream& os)const {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "Toy";
		os.width(8);
		os << m_orderId << ":";
		os.width(18);
		os << m_name;
		os.width(3);
		os << m_numItems << " items";
		os.width(8);
		os << m_price << "/item  subtotal:";
		os.width(7);
		os << m_price * m_numItems << " tax:";
		os.width(6);
		os << m_price * m_numItems * m_tax << " total:";
		os.width(7);
		os << m_price * m_numItems * (1 + m_tax) << std::endl;
		os.precision(6);
		return os;
	}

	std::ostream& operator<<(std::ostream& ostr, const Toy& src) {
		return src.display(ostr);
	}
}