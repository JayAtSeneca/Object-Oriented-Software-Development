#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>

namespace sdds {
	class Book {
		std::string m_author = "";
		std::string m_title = "";
		std::string m_country = "";
		size_t m_year = 0u;
		double m_price = 0.0f;
		std::string m_description = "";

		void trim(std::string& str) const;
	public:
		Book() { }
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book b);
	};
 }
#endif