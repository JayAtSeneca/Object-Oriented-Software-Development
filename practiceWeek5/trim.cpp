#include <iostream>
#include <string>
using namespace std;

class Book{
    string title{};
    string author{};
   
    public:
    Book(){}
    string getTitle(){return title;}
    string trim(string& str){
        string::size_type pos = str.find_first_not_of(' ');
        string::size_type lasPos = str.find_last_not_of(' ');
        return str.substr(pos,lasPos);
    }
    Book(const std::string& str){
        string data = str;
        string c_title, c_author;
        c_title = data.substr(0, data.find(","));
        data = data.erase(0,data.find(",")+1);
        c_author = data.substr(0, data.find(","));
        title = trim(c_title);
        author = trim(c_author);
        cout<<"Title:"<<"start"<<title<<endl;
        cout<<"Author:"<<author;
        cout<<"End"<<endl;
    }
};
int main(){
    Book b("    The c++ book, by John Doe   ");
    return 0;
}