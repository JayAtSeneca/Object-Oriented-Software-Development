// main.cpp
#include <utility>
#include "postal1.h"
#include "postal1.h"
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
	po2 = std::move(po1);  // error 4

	for (int i = 0; i < num; ++i) {
		po2.receiveMail(people[i]);

	}
	po2.listMail();
}

////Error #1 - In postal.h related to array declaration
//Error #2 - In main.cpp related to special operations
//Error #3 - In main.cpp related to variable redefinition
//Error #4 - In postal.cpp related to the use of dynamic memory
//Error #5 - In postal.cpp related to the use of invalid operators with user defined types