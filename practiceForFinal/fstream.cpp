// Thread Class - Function Object
 // thread_id_fo.cpp

 #include <iostream>
 #include <thread>
 #include <vector>

 const int NT = 10;

 class Task {
   public:
     Task(){}
     void operator()(int i) {
     std::cout << i << " Thread id = " <<
      std::this_thread::get_id() << std::endl; 
     }
 };

 int main() {
     // create a vector of not-joinable threads
     std::vector<std::thread> threads;

     // launch execution of each thread
     for (int i = 0; i < NT; i++)
         threads.push_back(std::thread(Task(), i)); 

     // synchronize their execution here
     for (auto& thread : threads)
         thread.join();
 }