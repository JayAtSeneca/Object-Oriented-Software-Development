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
}
#endif // !CALCULATOR_H