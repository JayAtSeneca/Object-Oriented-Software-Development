#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Playdoh {
	char* colour;
	int weight;
public:
	Playdoh(const char* col, int wei) :weight(wei) {
		colour = nullptr;
		if (col != nullptr) {
			colour = new char[strlen(col) + 1];
			strcpy(colour, col);
		}
	}
	~Playdoh() { delete[] colour; }
	void display(ostream& os)const {
		if (colour[0] == '\0') {
			throw "Empty String colour";
			os << "Playdoh colour: " << colour << "weight: " << weight << endl;
		}
	}
};
ostream& operator<<(ostream& os, const Playdoh& p) {
	p.display(os);
	return os;
}

void asPlaydoh(const char* col) {
	Playdoh* p = new Playdoh(col, 50);
	p->display(cout);
	delete p;
}

int main() {
#ifdef ex1
	Playdoh* playptr = new Playdoh("Red", 10);
	cout << *playptr;
	delete playptr;
	playptr = new Playdoh("", 20);
	cout << *playptr;
	delete playptr;
#endif // ex1

#ifdef ex2
	try {
		cout << *playptr;
	}
	catch (const char* e) {
		cout << "Caught: " << e << endl;
		delete playptr;
	}
#endif // ex2

#ifdef ex3
	try {
		asPlaydoh("Blue");
		asPlaydoh("Green");
		asPlaydoh("");
	}
	catch (const char* e) {
		cout << "Caught: " << e << endl;
	}

#endif // ex3

}