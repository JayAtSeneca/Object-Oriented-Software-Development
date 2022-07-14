#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
class Playdoh {
	string color{};
	int weight{ 0 };
public:
	Playdoh(){}
	Playdoh(int wei):color("Pink"),weight(wei){}
	Playdoh(const char* col, int wei):color(col), weight(wei){}
	std::ostream& display(std::ostream& os)const {
		os << "Playdoh Colour: " << color << "Weight: " << weight << endl;
		return os;
	}
	void setColour(const char* col) { color = col; }
	void setWeight(int wei) { weight = wei; }
	string getColour()const { return color; }
	int getWeight()const { return weight; }
	bool operator==(string col)const { return color == col; }
	operator int()const { return weight; }
};

std::ostream& operator<<(std::ostream& os, const Playdoh& p) {
	p.display(os);
	return os;
}

int main() {
	vector<Playdoh> ps = {
		{"Red", 22},
		{"Red", 24},
		{"Blue", 29},
		{"Blue", 23},
		{"Blue", 25},
		{"Red", 21},
		{"White", 90},
		{"Yellow", 40},
		{"Green", 50},

	};
#define que
#define mod
#define mani
#define numeric
	cout << "Print out the original Playdoh vector" << endl;
	for (auto& x : ps) {
		cout << x;
	}
#ifdef que
	cout << "\n***********Queries************" << endl;
	if (!all_of(ps.begin(), ps.end(), [](Playdoh p) {return p.getColour() == "Red"; }))
	{
		cout << "Not All of the Playdohs are Red" << endl;
	}
	if (any_of(ps.begin(), ps.end(), [](Playdoh p) {return p.getColour() == "Pink"; })) {
		cout << "At least one of them Playdoh is Red" << endl;
	}
	if (none_of(ps.begin(), ps.end(), [](Playdoh p) {return p.getColour() == "Pink"; })) {
		cout << "None of Playdohs are Pink" << endl;
	}

	int ints[]{ 1,2,3,4,5,6,7,8 };
	for_each(ints, ints + 5, [](auto p) {cout << p << ", "; });
	vector<Playdoh>::iterator itr;
	itr = find(ps.begin(), ps.end(), "White");
	if (itr != ps.end()) {
		cout << endl << *itr;
		cout << "Found at postion: " << itr - ps.begin() << endl;
	}

	int counter = count_if(ps.begin(), ps.end(), [](Playdoh& p) {return p.getColour() == "Red"; });
	cout << "We have " << counter << "Red Playdoh in the vector" << endl;
#endif // que

#ifdef mod
	cout << "\n***********Modifiers************" << endl;
	vector<int> dohweights(ps.size(), 1);
	vector<Playdoh> ps2(ps.size(), Playdoh());
	transform(ps.begin(), ps.end(), dohweights.begin(), [](Playdoh& p) {return int(p); });
	cout << "Print out the dohweight Vector" << endl;
	for (auto& x : dohweights) {
		cout << x << endl;
	}

	transform(ps.begin(), ps.end(), dohweights.begin(), ps2.begin(), plus<int>());
	cout << "Print out the transformed Playdoh Vector" << endl;
	for (auto& x : ps2) {
		cout << x;
	}
	replace_if(ps2.begin(), ps2.end(), [](const Playdoh& p) {return p.getColour() == "Pink"; }, Playdoh("Red", 99));
	for (auto& x : ps2) {
		cout << x;
	}
#endif // mod

#ifdef mani
	cout << "\n***********Manipulators************" << endl;
	cout << "sorted" << endl;
	sort(ps.begin(), ps.end());
	for (auto& x : ps) {
		cout << x;
	}
	cout << "merged" << endl;
	int first[] = { 10,15,5,20,25 };
	int second[] = { 50,40,30,20,10 };
	std::vector<int> v(10);
	sort(first, first + 5);
	sort(second, second + 5);
	merge(first, first + 5, second, second + 5, v.begin());
	for (auto& x : v) {
		cout << x << ", ";
	}
	cout << endl;
#endif // mani

#ifdef numeric
	cout << "\n***********Numeric************" << endl;
	int weightSum = accumulate(ps.begin(), ps.end(), 0);
	cout << "The sum of the playdoh vector's weight is: " << weightSum << endl;
	int arr1[]{ 1,2,3,4 };
	int arr2[]{ 1,2,3,4 };
	int innerprod = inner_product(arr1, arr1 + 4, arr2, 0);
	cout << "The inner_product of arr1 and arr2 is: " << innerprod << endl;
	vector<int> partialsum(4, 0);
	partial_sum(arr1, arr1 + 4, partialsum.begin());
	for (auto& x : partialsum) {
		cout << x << ", ";
	}
#endif // numeric

}