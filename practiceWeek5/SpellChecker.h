#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>
namespace sdds
{
    class SpellChecker
    {
        std::string m_badWords[6]{};
        std::string m_goodWord[6]{};

    public:
        SpellChecker(const char *filename);
        void operator()(std::string &text);
        void showStatistics(std::ostream &os) const;
    };
}
#endif // !SDDS_SPELLCHECKER_H