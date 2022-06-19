#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>
#include "SpellChecker.h"
namespace sdds {
	class Movie {
		std::string m_title{};
		size_t m_year{};
		std::string m_description{};
		std::string& trim(std::string& str)const;
	public:
		Movie() {};
		Movie(const std::string& strMovie);
		const std::string& title() const;
		template <typename T>
		void fixSpelling(T& spellChecker);
		friend std::ostream& operator<<(std::ostream& os, const Movie& m);
	};
	template<typename T>
	void Movie::fixSpelling(T& spellChecker)
	{
		spellChecker(m_title);
		spellChecker(m_description);
	}
}
#endif // !SDDS_MOVIE_H
