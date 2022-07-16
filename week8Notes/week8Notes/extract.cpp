#include <iostream>
#include <string>
using namespace std;


std::string trim(std::string& str) {
	while (str[0] == ' ') {
		str.erase(0, str.find_first_not_of(' '));
	}
	while (str[str.size() - 1] == ' ') {
		str.erase(str.find_last_not_of(' ') + 1);
	}
	return str;
}

std::string extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string token{};
	if (more) {
		char m_delimiter = ',';
		size_t position = str.find(m_delimiter, next_pos);
		if (position != next_pos) {

			token = str.substr(next_pos, position - next_pos);
			trim(token);
			int m_widthField = 1;
			if (m_widthField < token.size())
				m_widthField = token.size();

			if (position != std::string::npos) {

				next_pos = str.find(m_delimiter, next_pos + 1) + 1;
				more = true;
			}
			else {

				next_pos = 0;
				more = false;
			}
		}
		else {
			more = false;
			throw std::string("Delimiter is found at next_pos");
		}
	}
	return token;
}



int main() {
	string raw = "Armchair,    654321,  10,  Upholstered Wing Chair";
	size_t next_pos = 0;
	bool more = true;
	string str = extractToken(raw, next_pos, more);
	string num = extractToken(raw, next_pos, more);
	string num2 = extractToken(raw, next_pos, more);
	string des = extractToken(raw, next_pos, more);
	return 0;
}