// main.cpp
#include <utility>
#include "postal.h"
#include "postal.h"
using namespace sdds;

const int num = 5;

int main()
{
	Person people[num]{ "Aqua", "Marine", "Noel", "Subaru", "Towa" };
	PostalOffice po1("Toronto"), po2("Brampton");

	for (int i = 0; i < num; ++i) {
		po1.sendMail(people[i], people[num - 1 - i], mailType::letter);
		po1.sendMail(people[num - 1 - i], people[i], mailType::parcel);

	}
	po1.listMail();

	PostalOffice po3 = std::move(po2);
	po2 = std::move(po1); //error 1 

	for (int i = 0; i < num; ++i) {
		po2.receiveMail(people[i]);

	}
	po2.listMail();
}