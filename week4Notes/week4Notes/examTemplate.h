#include <iostream>
#include <string>
//template.h
template <typename T>
int ispartitioned(const T* arr, size_t length, size_t index, const T value){
    int count = 0;
    int retVal = 0;
    for(size_t i  = 0u; i<=index;i++){
        if(arr[i] < value){
            count++;
        }
    }
    if(count == index+1){
        retVal = 1;
    }
    return retVal;
}

template <>
int ispartitioned<std::string>(const std::string* str, size_t length, size_t index, const std::string value){
    int count = 0;
    int retVal = 0;
    for(size_t i  = 0u; i<=index;i++){
        if(int(str[i].c_str()) < int(value[i])){
            count++;
        }
    }
    if(count == index+1){
        retVal = 1;
    }
    return retVal;
} 