#include <iostream>
#include <typeinfo>//typeid
#include "Playdoh.h"
#include "clay.h"
using namespace std;
Compound* produce(){
    Compound* c = nullptr;
    cout<<"Do you want a playdoh or a clay(p or c): ";
    char selection = 'x';
    cin >>selection;
    if(selection == 'P'){
        c = new Playdoh();
    }
    else{
        c = new Clay();
    }
    if(c){
        cin >> *c;
    }
    return c;
}

int main(){
    Compound* mycomp = produce();
    cout<<"***************"<<endl;
    cout<<"Printing the details of the compound: "<<endl;
    cout<<mycomp<<endl;
    Compound* mycopy = mycomp->clone();
    cout<<"*********"<<endl;
    cout<<"Printing the details of the copy: "<<endl;
    cout<<*mycopy<<endl;
    delete mycopy;
    // compare
    Compound* mycomp2 = produce();
    cout<<"*************"<<endl;
    if(*mycomp2 == *mycomp){
        cout<<"They're are the same"<<endl;
    }
    else{
        cout<<"They are different"<<endl;
    }
    delete mycomp2;

    //typeinf
    int i;
    int* ptr;
    cout<<"i is : "<<typeid.name()<<endl;
    cout<<"ptr is: "<<typeid(ptr).name()<<endl;

    Playdoh play;
    Clay clay;
    cout<<"Play is: "<<typeid(play).name()<<endl;
    cout<<"clay is: "<<typeid(clay).name()<<endl;
    cout<<"mycomp is: "<<typeid(*mycomp).name()<<endl;
    delete mycomp;
}