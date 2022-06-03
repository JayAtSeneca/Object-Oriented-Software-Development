#include <iostream>
#include "clay.h"
using namespace std;
Clay::Clay(){}

Clay::Clay(int wei, double har):hardness(har){
    setWeight(wei);
}
std::ostream& Clay::display(std::ostream& os)const{
    return os<<"Clay hardness: "<<hardness<<" weight: "<<getWeight()<<endl;
}

std::istream& Clay::write(std::istream& is){
    cout<<"enter a value for the clay hardness: ";
    is>>hardness;
    cout<<"Enter a value for clay weight: ";
    int wei;
    is>>wei;
    setWeight(wei);
    return is;
}
Compound* Clay::clone()const{
    return new Clay(*this);
}
bool Clay::operator==(Compound& c)const{
    const Clay* clay = dynamic_cast<Clay*>(&c);
    return clay?clay->hardness == hardness:false;
}