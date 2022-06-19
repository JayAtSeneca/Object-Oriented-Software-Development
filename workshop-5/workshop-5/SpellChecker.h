#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>
namespace sdds {
	const int ARR_SIZE = 6;
	class SpellChecker {
		std::string m_badWords[ARR_SIZE];
		std::string m_goodWords[ARR_SIZE];
		static int wordCount[ARR_SIZE];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SDDS_SPELLCHECKER_H
