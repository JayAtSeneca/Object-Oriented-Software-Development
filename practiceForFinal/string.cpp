// Iterators - Insertion and Removal
 // iterator_deque.cpp

 #include <deque>
 #include <iostream>

 int main() {
     std::deque<double> p(3, 10.50);

     p.back() = 32.43;   // reset last 
     p.erase(p.begin()); // remove first
     for(auto i = p.begin(); i != p.end(); i++) 
         std::cout << *i << "  ";
     std::cout << std::endl;
     p.insert(++p.begin(), 15.64);
     p.insert(p.end(), 20.31);
     for(auto i = p.begin(); i != p.end(); i++)
         std::cout << *i << "  ";
     std::cout << std::endl;
 }