// String Class
 // string.cpp

 #include <iostream>
 #include <string>

 int main() {
     std::string str("Hello");
     str += '\0'; // adds a null byte
     str += " World"; // adds a string
     int i = 0;
     for (const auto& c : str)
         if (str[i++] == '\0')
             std::cout << "Null byte at str["
              << i-1 << "]\n"; 
     std::cout << str << std::endl;
 }