#include <iostream>
template <typename K, typename V>
class Keyvalue{
    K key{};
    V val{};
public:
    std::istream& input(std::istream& is){
        std::cout<<"Enter a Key: ";
        is>>key;
        std::cout<<"Enter a value: "<<endl;
        is>>val;
        return is;
    }
    std::ostream& display(std::ostream& os)const{
        os<<key<<" : "<<val<<std::endl;
        return os;
    }
};

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, Keyvalue<K,V>& keyval){
    return keyval.display(os);
}

template <typename K, typename V>
std::istream& operator>>(std::istream& is,Keyvalue<K,V>& keyval){
    return keyval.input(os);
}