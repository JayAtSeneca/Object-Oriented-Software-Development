#ifndef SDDS_CITYTEMPERATURE_H
#define SDDS_CITYTEMPERATURE_H
#include <iostream>
#include <string>

namespace sdds{

enum class TempType{Degree, Range};
enum class Range {None, Low, High};

union Temperature {
    double degree;
    Range range;
} temperature;

class CityTemperature{
    TempType m_temperature{TempType::Degree};
    Temperature m_degree{0.0};
    char* m_message{};
    static int numOfObjects;
    public:
    CityTemperature();
    CityTemperature(double degree, const char* message);
    int getNumOfObjects() const;
    //special member functions
    CityTemperature(const CityTemperature& other);
    CityTemperature& operator=(const CityTemperature& other);
    ~CityTemperature();
    CityTemperature(CityTemperature&& other);
    CityTemperature& operator=(CityTemperature&& other);
    void setRange(Range r);
    void setDegree(double d);
    std::string rangeStr(Range r) const;
    std::ostream& display(std::ostream& os) const;
};
bool updateTemperature(CityTemperature& city, std::string message);
}
#endif  // SDDS_CITYTEMPERATURE_H