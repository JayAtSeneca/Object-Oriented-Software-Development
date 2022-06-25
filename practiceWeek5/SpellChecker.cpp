#include "SpellChecker.h"
#include <fstream>
using namespace std;
namespace sdds
{
    SpellChecker::SpellChecker(const char *filename){
        std::ifstream file(filename);
        if(!file.is_open()){
            cout<<"Error: File not found"<<endl;
        }
        else{
            for(int i = 0; i < 6; i++){
                file>>m_badWords[i];
                file>>m_goodWord[i];
            }
        }

    }
    void SpellChecker::operator()(std::string &text){
        for(int i = 0; i < 6; i++){
            if(text.find(m_badWords[i]) != std::string::npos){
                text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWord[i]);
            }
        }
    }
}
    