// postal.h
#ifndef SDDS_POSTAL_H
#define SDDS_POSTAL_H
#include <iostream>
#include <string>

const int capacity = 5 * 2; // error 2
extern const int num;

namespace sdds {

	enum class mailType { letter, parcel, none };

	class PostalOffice;

	class Person {
		std::string name{};
	public:
		Person(const char* nm = "Someone") : name(nm) {};
		bool operator==(const Person& per) const;
		operator std::string() const { return name; };

	};

	class PostalOffice
	{
		struct Mail {
			Person sender{ "Noone" };
			Person receiver{ "Noone" };
			mailType mtype{ mailType::none };

		};

		char* location{};
		int amountOfMail{};
		Mail mail[capacity]{};

	public:
		PostalOffice() {};
		PostalOffice(const char* lo);
		~PostalOffice();
		PostalOffice(const PostalOffice& src) = delete;
		PostalOffice& operator=(const PostalOffice& src) = delete;
		PostalOffice(PostalOffice&& src);
		PostalOffice& operator=(PostalOffice&& src);
		void sendMail(const Person& sender, const Person& receiver, mailType mt);
		void receiveMail(const Person& receiver);
		void listMail(std::ostream& os = std::cout) const;
	};

}
#endif