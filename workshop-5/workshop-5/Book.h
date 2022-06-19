#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>
#include <string>
#include "SpellChecker.h"
namespace sdds {
	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_description{};
		std::string& trim(std::string& str)const;
	public:
		Book() {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& str);
		template <typename T>
		void fixSpelling(T& spellChecker);
		friend std::ostream& operator<<(std::ostream& os, const Book b);
	};
	template <typename T>
	void Book::fixSpelling(T& spellChecker) {
		spellChecker(m_description);
	}

}
#endif