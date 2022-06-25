// postal.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
#include <utility>
#include "postal.h"

using namespace std; // error 3
namespace sdds { // error 4
	const int num = 5;

	bool Person::operator==(const Person& per) const {
		return name == per.name;

	}

	PostalOffice::PostalOffice(const char* loc) {
		if (loc) {
			location = new char[std::strlen(loc) + 1];
			std::strcpy(location, loc);

		}

	}

	PostalOffice::~PostalOffice() {
		delete[] location;

	}

	PostalOffice::PostalOffice(PostalOffice&& src) {
		*this = std::move(src);

	}

	PostalOffice& PostalOffice::operator=(PostalOffice&& src) {
		if (this != &src) {
			location = src.location;
			amountOfMail = src.amountOfMail;
			for (int i = 0; i < capacity; ++i)
				mail[i] = src.mail[i];
			src.location = nullptr;

		}
		return *this;

	}

	void PostalOffice::sendMail(const Person& sender, const Person& receiver, mailType mt) {
		if (amountOfMail < capacity) {
			mail[amountOfMail].sender = sender;
			mail[amountOfMail].receiver = receiver;
			mail[amountOfMail].mtype = mt;
			amountOfMail++;

		}

	}

	void PostalOffice::receiveMail(const Person& receiver) {
		for (auto& m : mail) {
			if (m.receiver == receiver) {
				m = Mail();
				amountOfMail--;

			}

		}

	}

	void PostalOffice::listMail(std::ostream& os) const {
		os << "Postaloffice - " << location << "\n";
		os << "Total mail: " << amountOfMail << "\n";
		for (int i = 0; i < amountOfMail; ++i) {
			os << "#" << (i + 1) << " ";
			if (mail[i].mtype == mailType::letter)
				os << "Letter ";
			else if (mail[i].mtype == mailType::parcel)
				os << "Parcel ";
			else
				os << "Nothing";
			os << " To: " << std::string(mail[i].receiver) << "\n"; // error 5

		}

	}
}