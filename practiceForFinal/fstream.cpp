#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int* a = *((int) 3);
    int* b = *((int) 5);
    return 0;
}