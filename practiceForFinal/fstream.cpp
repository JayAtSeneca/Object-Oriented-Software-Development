// Thread Class
 // thread.cpp

 #include <iostream>
 #include <string>
 #include <thread>

 void task(const std::string& str) {
     std::cout << str + " says Hi\n";
 }

 int main() {
     // spawn child thread t1
     std::thread t1(task, "t1");
     // spawn child thread t2
     std::thread t2(task, "t2");
     // continue executing main thread
     task("main");

     // synchronize - IMPORTANT!
     t2.join();
     t1.join();
 }