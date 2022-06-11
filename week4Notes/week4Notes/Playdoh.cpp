#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Playdoh.h"
Playdoh::Playdoh(){}
Playdoh::Playdoh(const char* col, int wei) {
	setColour(col);
	setWeight(wei);
}

Playdoh::Playdoh(const Playdog& src) {
	*this = src;
}

Playdoh& Playdoh::operator=(const Playdoh& src) {
	if (this != &src) {
		weight = src.weight;
		setColour(src.colour);
	}
	return *this;
}
std::ostream& Playdoh::display(std::ostream& os)const {
	if (colour)
		os << "Playdoh colour: " << colour << "weight: " << weight << std::endl;
	else
		os << "Empty Playdoh" << std::endl;
	return os;
}

void Playdoh::setWeight(int wei) {
	weight = wei > 0 ? wei : 0;
}
Playdoh::~Playdoh() {
	std::cout << "In playdoh dest" << std::endl;
	delete[] colour;
}

bool operator==(const Playdoh& p1, const Playdoh& p2) {
	return strcmp(p1.colour, p2.colour) == 0;
}
std::ostream& operator<<(std::ostream& os, const Playdoh& p) {
	return p.display(os);
}