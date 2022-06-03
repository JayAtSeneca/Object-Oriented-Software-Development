#include <iostream>
#include "calculator.h"
using namespace std;
int main(){
    int iarr1[]{1,2,3};
    int iarr2[]{3,4,5};

    Calculator<int,3> c1;
    c1.add(iarr1,iarr2);
    cout<<"Adding iarr1 and iarr2:"<<endl;
    cout<<c1<<endl;

    double darr1[]{1.1,2.2,3.3};
    double darr2[]{1.1,2.2,3.3};
    Calculator<double,3> d1;
    d1.add(darr1,darr2);
    cout<<"Adding darr1 and darr2:"<<endl;
    cout<<d1<<endl;
}