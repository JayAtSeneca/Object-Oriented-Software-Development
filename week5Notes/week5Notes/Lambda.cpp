#include <iostream>
using namespace std;
int value(const char* c) {
	int ret = 0;
	int temp = 0;
	int temp2 = 0;
	auto check_constant = [](char c) {
		c = toupper(c);
		return c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U';
	};
	for (int i = 0; c[i]; i++) {
		ret += check_constant(c[i]);
	}
	return ret;
}
void display(const char* prompt, void (*funcX)()) {
	cout << prompt << " ";
	funcX();
}
int main() {
	const char* str{ "Apples" };
	int v = value(str);
	cout << "V: " << v << endl;
	display("Prompt", []() {cout << "Hello from lamdba1" << endl; });
	display("Prompt", []() {cout << "Hello from lamdba2" << endl; });
	display("Prompt", []() {cout << "Hello from lamdba3" << endl; });
}