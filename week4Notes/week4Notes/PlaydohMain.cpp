#include <iostream>
#include "Playdoh.h"
#include "PlaydohPack.h"
#include "PlaydohAssoc.h"
#include "ToyBox.h"
using namespace std;

#define ex1
#define ex2
#define ex3
#ifdef ex3
void giveandtake(ToyBox& t, PlaydohAssoc& p) {
	t.put(p);
	p.associate(t);
}
#endif // ex3

int main() {
#ifdef ex1
	const char* reds[]{ "Red","Redder","Reddest" };
	PlaydohPack p("Red Pack", 3, reds);
	cout << p << endl;
	const char* blues[]{ "Blue","Bluer","Bluest" };
	PlaydohPack p2{ "Blue Pack",3,blues };
	cout << p2 << endl;
	const char* greens[]{ "Green", "Greener", "Greenest", "Verdant Green" };
	Playdoh p3("Green Pack", 4, greens);
	cout << p3 << endl;
	p = p3;
	cout << p << endl;
	cout << "End of Ex1" << endl;
#endif // ex1
#ifdef ex2
	Playdoh r("Red", 10);
	Playdoh g("Green", 30);
	Playdoh b("Blue", 20);
	{
		PlaydohPackAgg p("RGB Pack");
		p += r;
		p += g;
		p += b;
		cout << p << endl;
		p -= g;
		cout << p << endl;
	}
	cout << "Our Playdohs" << endl;
	cout << r << g << b << endl;
	cout << "End of Ex2" << endl;
#endif // ex2

#ifdef ex3
	ToyBox t1("Big Box", "Wood", 50);
	ToyBox t2("Fun Box", "Plastic", 10);
	{
		PlaydohAssoc r("Red", 10);
		PlaydohAssoc g("Green", 30);
		PlaydogAssoc b("Blue", 20);

		giveandtake(t1, r);
		giveandtake(t2, b);
		cout << t1 << endl;
		cout << t2 << endl;
		giveandtake(t1, b);
		giveandtake(t2, g);
		cout << t1 << endl;
		cout << t2 << endl;
	}
	cout << "********" << endl;
	cout << t1 << endl;
	cout << t2 << endl;
#endif // ex3

}