#include <iostream>
#include "template.h"
using namespace std;


int main()
{
	std::string s[]{ "yes", "no", "who", "when", "why" },
		t[]{ "yes", "no", "who", "when", "why" },
		u[5]{};
	int a[]{ 1, 2, 3, 4, 5 },
		b[]{ 5, 4, 3, 2, 1 },
		c[5];
	double d[]{ 1.1, 2.2, 3.3, 4.4, 2.2 },
		e[]{ 1.1, 2.2, 3.3, 4.4, 2.2 },
		f[5];

	add(s, t, u, 5);
	for (auto& e : u)
		std::cout << e << '|';
	std::cout << std::endl;

	add(a, b, c, sizeof a / sizeof(int));
	for (auto& e : c)
		std::cout << e << ' ';
	std::cout << std::endl;

	add(d, e, f, sizeof d / sizeof(double));
	for (auto& e : f)
		std::cout << e << ' ';
	std::cout << std::endl;
}