// ship.cpp
#include <string>
#include "ship.h"

using namespace std;

namespace sdds_midterm
{
    std::ostream &Ship::operator<<(std::ostream &os) const
    {
        if (xposition >= 0 || yposition >= 0)
            os << "Ship size: " << getSizeStr() << std::endl
               << "Ship position (x,y) : ("
               << xposition << "," << yposition << ")"
               << std::endl;
        else
            os << "Ship is not launched." << std::endl;

        return os;
    }

    std::string Ship::getSizeStr() const
    {
        std::string str{};
        switch (ss)
        {
        case ShipSizes::none:
            str = "None";
            break;
        case ShipSizes::handymax:
            str = "Handymax";
            break;
        case ShipSizes::arfamax:
            str = "Arfamax";
            break;
        }
        return str;
    }

    std::string Ship::getInfo() const
    {
        char *s{};
        if (xposition >= 0 || yposition >= 0)
        {
            s = "Ship size: ";
            s += getSizeStr();
            s += "\nShip position (x,y) : (";
            s += std::to_string(xposition);
            s += ",";
            s += std::to_string(yposition);
            s += ")\n";
        }
        else
        {
            s = "Ship is not launched\n";
        }
        return s;
    }

    std::ostream &operator<<(std::ostream &os, const Ship &s)
    {
        return s << os;
    }

    Ship &operator+(Ship &s, std::string str)
    {
        return s;
    }
    std::string operator+(std::string s, Ship &sh)
    {
        return s;
    }
}