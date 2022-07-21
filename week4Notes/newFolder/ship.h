// ship.h
#ifndef SDDS_MIDTERM_SHIP_H
#define SDDS_MIDTERM_SHIP_H
#include <iostream>

namespace sdds_midterm
{
    enum class ShipSizes
    {
        none,
        handymax,
        arfamax
    };

    class Ship
    {
        ShipSizes ss;
        int xposition;
        int yposition;

        std::string getSizeStr() const;
        Ship sh(){
            return new Ship(*this);
        }
        std::string getInfo() const;

    public:
        
        Ship() : ss{ShipSizes::none},
                 xposition{-1},
                 yposition{-1} {}

        Ship(ShipSizes ss_, int xpos, int ypos) : ss{ss_},
                                                  xposition{xpos},
                                                  yposition{ypos} {}

        Ship(const Ship *s) : ss{s->ss},
                              xposition{s->xposition},
                              yposition{s->yposition} {}

        std::ostream &operator<<(std::ostream &) const;
    };

    std::ostream &operator<<(std::ostream &, const Ship &);

    // enables addition of Ship object and a string
    const Ship &operator+(const Ship &, std::string);
    // enables addition of string and Ship object
    std::string operator+(std::string, const Ship &);
}
#endif