#include "SpellChecker.h";
#include <iomanip>
#include <fstream>
using namespace std;
namespace sdds {
	int SpellChecker::wordCount[ARR_SIZE]{ 0 };

	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (file.is_open()) {
			int i = 0;
			while (file&& i < ARR_SIZE) {
				file >> m_badWords[i];
				file >> m_goodWords[i];
				i++;
			}
		}
		else {
			throw "Bad file name!";
		}
	}

	void SpellChecker::operator()(std::string& text)
	{
		for (int i = 0; i < ARR_SIZE; i++) {
			string::size_type n = text.find(m_badWords[i]);
			if (n != std::string::npos) {
				text.replace(n, m_badWords[i].length(), m_goodWords[i]);
				wordCount[i] += 1;
				string::size_type m = text.find(m_badWords[i]);
				if (m != std::string::npos) {
					text.replace(m, m_badWords[i].length(), m_goodWords[i]);
					wordCount[i] += 1;
				}
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << endl;
		for (int i = 0; i < ARR_SIZE; i++) {
			out << setw(15) << right << m_badWords[i];
			out << ": " << wordCount[i] << " replacements" << endl;
		}
		
	}

}