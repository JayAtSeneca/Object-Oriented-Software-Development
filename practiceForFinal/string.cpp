// Container Adapters - Queues
 // ca_queue.cpp

 #include <queue>
 #include <iostream>

 int main() {
     std::queue<int> tickets; // initially empty 

     tickets.push(10); // add 10
     tickets.push(20); // add 20
     tickets.push(32); // add 32
     tickets.back() = 30;
     while(!tickets.empty()) {
         std::cout << tickets.front() << "  ";
         tickets.pop();
     }
     std::cout << std::endl;
 }