#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
template <typename T = int, int N = 3> // with default values defined
class Calculator{
    T result[N]{};
    static int uses;
public:
    Calculator(){
        for(int i =0; i<N; i++){
            result[i] = 0;
        }
    }
    std::ostream& display(std::ostream& os)const{
        for(int i =0; i<N;i++){
            os<<result[i];
            if(N-i>1){
                os<<",";
            }
        }
        os<<std::endl;
        return os;
    }
    void add(const T* arr1, const T* arr2){
        for(int i = 0; i<N;i++){
            result[i] = arr1[i] + arr2[i];
        }
        uses++;
    }
    static int used(){return uses;}
};
template <typename T, int N>
int Calculator<T,N>::uses = 0;

template <typename T, int N>
std::ostream& operator<<(std::ostream& os, Calculator<T,N>& calc){
    return calc.display(os);
}
#endif // !CALCULATOR_H