#include <iostream>
#include "A.h"
using namespace std;
int main(){
    int arrI[6]{0,1,2,3,4,5}; // error 4
    //error 5
    cout<<process<int,6>(arrI)<<endl;

    // error 6
    double arrA[5]{{1.2},{2.3},{3.4},{4.5}};
    cout<<process<double,5>(arrA)<<endl;
}