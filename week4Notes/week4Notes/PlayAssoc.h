#pragma once
#include <iostream>
using namespace std;
class ToyBox;
class PlaydohAssoc {
	char* colour{ nullptr };
	int weight{ 0 };
	ToyBox* box{ nullptr };
public:
	PlaydohAssoc();
	PlaydohAssoc(const char* col, int wei);
	void associate(ToyBox& src);
	void disassociate();
	std::ostream& display(std::ostream& ostr)const;
	void setColour(const char* col);
	void setWeight(int wei);
	const char* getColour()const;
	int getWeight()const;
	~PlaydohAssoc();
};
std::ostream& operator<<(std::ostream& os, const PlaydohAssoc& p);