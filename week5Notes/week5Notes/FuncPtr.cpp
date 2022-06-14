#include <iostream>
using namespace std;
void funcA() {
	cout << "I am function A" << endl;
}
void funcB() {
	cout << "I am function B" << endl;
}
void funcC() {
	cout << "I am Function C" << endl;
}
void display(const char* prompt, void(*funcX)()) {
	cout << prompt;
	funcX();
}
template <typename T>
bool maximum(T& v1, T& v2) {
	return (v1 > v2);
}
template<typename T>
bool minimum(T& v1, T& v2) {
	return (v1 < v2);
}

template <typename T>
bool compareTwoArrays(T arr1[], T arr2[], int len, bool (*compare)(T&, T&)) {

	int a1results = 0;
	int a2results = 0;

	for (int i = 0; i < len; ++i) {
		a1results += compare(arr1[i], arr2[i]);
		a2results += compare(arr2[i], arr1[i]);
	}

	return a1results > a2results;
}

void switchCase(int a) {
	switch (a) {
	case 0:
		funcA();
		break;
	case 1:
		funcB();
		break;
	case 2: 
		funcC();
		break;
	}
}
int main() {
#ifdef  ex1
	void (*ptrtoFuncA)() = funcA;
	void (*ptrtoFuncB)() = funcB;
	ptrtoFuncA();
	ptrtoFuncB();
	display("Hello!", ptrtoFuncA);
	display("Hello!", ptrtoFuncB);

#endif //  ex1

#ifdef ex2
	int arr1[]{ 1,2,3 };
	int arr2[]{ 1,3,3 };
	if (compareTwoArrays(arr1, arr2, maximum<int>)) {
		cout << "Arr1 is bigger than arr2" << endl;
	}
	else {
		cout << "Arr2 is bigger than Arr1" << endl;
	}
#endif // ex2

#ifdef ex3
	void (*arrofFunc[3])() { funcA, funcB, funcC };
	int choice = 0;
	do {
		cout << "Enter a value: ";
		cin >> choice;
		if (choice >= 0 && choice < 3) {
			arrOfFunc[choice]();
		}
		else {
			cout << "value of range! " << endl;
		}
	}
#endif // ex3

}