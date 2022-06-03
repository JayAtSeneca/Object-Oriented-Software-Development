#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <cstring>
#include <iostream>
using namespace std;
template <typename T>
void temp_swap(T& a, T& b){
    T c;
    c = a;
    a = b;
    b = c;
}
template <class T>
T maximum(T a, T b){
    cout<<"Generic max"<<endl;
    return a>b?a:b;
}
//specialization for const char*
template <>
const char* maximum<const char*>(const char* a, const char* b){
    return std::strcmp(a,b)>0?a:b;
}
#endif