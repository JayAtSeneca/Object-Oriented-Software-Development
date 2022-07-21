#include <iostream>

 template <typename T>
 void print(const T& t) {
     //std::cout << t << std::endl;
     std::cout<<"In print 1 function"<<std::endl;
 }

 template <typename T, typename... etc>
 void print(const T& t,const etc&... pp) { 
    // std::cout << t << " | ";
     std::cout<<"In print 2 function"<<std::endl;
     print(pp...);
 }

 int main() {
     print(100);
     print("abcd", 100, 34.56);
 }