#include <iostream>
#include <string>
using namespace std;
class Arr{
    string word[6]{"a","b","c","d","e","f"};
    static int arrWord[6];
    public:
    Arr(const string& text){
        for(int i = 0; i<text.length();i++){
            char wordCh= text[i];
            for(int j = 0; j<6;j++){
                string temp{wordCh};
                if(temp == word[j]){
                    arrWord[j]++;
                }
            }
        }
    }
    friend ostream& operator<<(ostream& os,const Arr& arr){
        os<<arrWord[0]<<endl;
        os<<arrWord[1]<<endl;
    }
};
int Arr::arrWord[6]{0};
int main(){
    Arr a("aaaaaabb");
    cout<<a;
    return 0;
}