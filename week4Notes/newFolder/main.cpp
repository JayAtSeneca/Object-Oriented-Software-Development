// main.cpp
#include <iostream>
#include "ship.h"

using namespace std;
using namespace sdds_midterm;

Ship s;

decltype(s + "") getData(const Ship &s)
{
    return s;
}

decltype("" + s) getData(const Ship *s)
{
    return s->getInfo();
}

int main()
{
    Ship *s[3]{
        new Ship(ShipSizes::arfamax, 5, 10),
        new Ship(ShipSizes::handymax, 100, 200)};

    s[2] = new Ship(ShipSizes::none, 50, 100);
    s[3] = new Ship(s[2]);
    std::cout << getData(s[0]) << std::endl;
    std::cout << getData(*s[1]) << std::endl;
    std::cout << getData(s[2]) << std::endl;

    for (auto &item : s)
        delete item;
    delete[] s;
}