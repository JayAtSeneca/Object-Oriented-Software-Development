#include <iostream>
#include <vector>
#include <functional>
using namespace std;

#define ex1
#define ex2
long multiply(long x, long y) { return x * y; }
struct Multiply {
	long operator()(long x, long y) { return x * y; }
};
int main() {
#ifdef ex1
	function<long(long, long)> f1 = multiply;
	function<long(long, long)> f2 = Multiply();
	function<long(long, long)> f3 = [](long x, long y) {return x * y; };
	cout << "f1(10, 2) = " << f1(10, 2) << endl;
	cout << "f2(10, 2) = " << f2(10, 2) << endl;
	cout << "f3(10, 2) = " << f3(10, 2) << endl;
#endif // ex1

#ifdef ex2
	vector<int> v(6, 20);
#define reff
#ifdef reff
	vector<reference_wrapper<int>> r(v.begin(), v.end());
	for (auto& i : v) {
		i *= 3;
	}
	for (auto i : r) {
		cout << i << " ";
	}
	cout << endl;
#else
	vector<int*> p;
	for (auto& i : v) {
		p.push_back(&i);
	}
	for (auto& i : p) {
		*i *= 4;
	}
	for (auto& x : p) {
		cout << x << " ";
	}
	cout << endl;
#endif // reff

#endif // ex2

}