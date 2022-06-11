#include <iostream>
#include <typeinfo>
using namespace std;

#define order 
#define prepost
#define szof
#define dtype
#define confusing
#define ternary

#ifdef szof
struct temp {
	int thing;
	char stuff;
};
void foosize(int arr[]) {
	cout << "sizeof arr in function: " << sizeof arr << endl;
}
#endif

#ifdef order
struct Box {
	int weight{};
	int items[5]{ 1,2,3,4,5 };
	void display()const {
		cout << "Box weight: " << weight << endl;
		for (int i = 0; i < 5; i++) {
			int temp = *this.item[i]; // *(this.items[i])
			cout << i + 1 << ": " << temp << endl;
		}
	}
};
#endif // order

int main() {
#ifdef order
	Box b;
	b.display();
#endif // order

#ifdef prepost
	int i = 0;
	++(++i);

	unsigned y = 0u;
	--y;
	cout << "value if underflowed unsigned y: " << y << endl;
	++y;
	cout << "value of the overflowed unsigned y: " << y << endl;
	int z = INT_MAX;
	cout << "value of the max int z: " << z << endl;
	++z;
	cout << "value of the max int z overflowed: " << z << endl;
	--z;
	cout << "value of the max int z underflowed: " << z << endl;
#endif // prepost
#ifdef szof
	int x = 4, y = 2;
	cout << "size of int: " << sizeof(int) << endl;
	cout << "size of double: " << sizeof(double) << endl;
	cout << "size of char: " << sizeof(char) << endl;
	cout << "size of x: " << sizeof(x) << endl;
	cout << "size of expression1: " << sizeof x + y << endl;
	cout << "size of expression2: " << sizeof(x + y) << endl;
	cout << "size of temp struct: " << sizeof(temp) << endl;
	int iarr[5]{ 1,2,3,4,5 };
	cout << "size of arr: " << sizeof(iarr) << endl;
	foosize(iarr);
	char carr[5]{ 'a','b','c','d','e' };
	for (int i = 0; i < sizeof(carr); i++) {
		cout << carr[i] << endl;
	}
#endif // 
#ifdef dtype
	int x = 10;
	double y = 5.5;
	double& z = y;
	decltype(x) var1 = 1;
	decltype(y) var2 = 2.2;
#endif // dtype

#ifdef confusing
	int x = 3;
	x = x + ++x;
	cout << "val of x: " << x << endl;
#endif // confusinh

#ifdef ternary
	int x = 1;
	int y = 0;
	cout << (x == 0 ? "Zero" : "Two") << endl;
#endif // ternary


}
