#include <sstream>

#include "Utilities.h"
#include "Racecar.h"


namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* ptr = nullptr;
		std::string temp;
		std::getline(in, temp, '\n');

		std::string val1 = trim(temp);

		std::stringstream str;
		str << temp;


		if (str && !temp.empty()) {

			if (val1 == "c" || val1 == "C") {

				ptr =  new Car(str);

			}
			else if (val1 == "r" || val1 == "R") {
				ptr = new Racecar(str);
			}
			else {
				if (val1 != "u" && val1 != "n" && val1 != "b") {
					std::string err(val1);
					throw err;
				}
				
			}
		}
		return ptr;
	}

	std::string trim(std::string& str) {
		const char* spaces = " \f\n\r\t\v";
		std::string temp;
		temp = str.substr(0, str.find(","));
		temp.erase(0, temp.find_first_not_of(spaces));
		temp.erase(temp.find_last_not_of(spaces) + 1);
		str.erase(0, str.find(",") + 1);

		return temp;
	}
	bool isInteger(const std::string& str) {
		bool val = true;
		for (size_t i = 0u; i < str.size(); i++) {
			if (!isdigit(str[i])) {
				val = false;
			}
		}
		return val;
	}
}