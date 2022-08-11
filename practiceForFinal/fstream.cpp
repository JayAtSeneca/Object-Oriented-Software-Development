// Smart Pointers - Unsafe Exception
 // unsafe_exception.cpp

 #include <iostream>
 #include "Title.h"

 void display(const char* s) {
     Title* t = new Title(s);
     t->display(); // may throw an exception!
     delete t;
 }

 int main() {
     const char* s[] = {"Mr.", "Ms.", "", "Dr."}; 

     for (auto x : s) {
         try {
             display(x);
         } catch(const char* msg) {
             std::cerr << msg << std::endl; 
         }
     }
 }