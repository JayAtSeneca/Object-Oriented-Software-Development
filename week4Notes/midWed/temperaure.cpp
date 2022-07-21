#include <iostream>
#include "temperature.h"
using namespace std;
namespace sdds{
    int CityTemperature::numOfObjects = 0;
    CityTemperature::CityTemperature(){}
    CityTemperature::CityTemperature(double degree, const char* message){
        m_degree = degree;
        if(message != nullptr){
            m_message = new char[strlen(message) + 1];
            strcpy(m_message, message);
        }
        else{
            throw 300;
        }
        strcpy(m_message, message);
    }
    int CityTemperature::getNumOfObjects() const{
        return numOfObjects;
    }

    bool CityTemperature::updateTemperature(CityTemperature& city, std::string message){
        bool isUpdated = false;
        if(message == "None"|| message == "Low" || message == "High"){
            isUpdated = true;
            if(message =="Low"){
                setRange(Range::Low);
            }
            else if(message == "High"){
                setRange(Range::High);
            }
            else{
                setRange(Range::None);
            }
        }
        else if(isdigit(atod(message))){
            isUpdated = true;
            setDegree(atod(message));
        }
        return isUpdated;
    }
    CityTemperature::CityTemperature(const CityTemperature& other){
        m_degree = other.m_degree;
        m_message = new char[strlen(other.m_message) + 1];
        strcpy(m_message, other.m_message);
        numOfObjects++;
    }
    CityTemperature& CityTemperature::operator=(const CityTemperature& other){
        if(this != &other){
            delete[] m_message;
            m_degree = other.m_degree;
            m_message = new char[strlen(other.m_message) + 1];
            strcpy(m_message, other.m_message);
        }
        return *this;
    }
    CityTemperature::~CityTemperature(){
        delete[] m_message;
        numOfObjects--;
    }
    CityTemperature::CityTemperature(CityTemperature&& other){
        m_degree = other.m_degree;
        m_message = other.m_message;
        other.m_message = nullptr;
        numOfObjects++;
    }
    CityTemperature& CityTemperature::operator=(CityTemperature&& other){
        if(this != &other){
            delete[] m_message;
            m_degree = other.m_degree;
            m_message = other.m_message;
            other.m_message = nullptr;
        }
        return *this;
    }
    void CityTemperature::setRange(Range r) { // available to students
    {temperature-type member} = TempType::Range;
    {temperature member}.range = r;
}
    void CityTemperature::setDegree(double d) { // available to students
    {temperature-type member} = TempType::Degree;
    {temperature member}.degree = d;
}
 std::string CityTemperature::rangeStr(Range r) const {
        std::string s = "";
        switch (r) {
        case Range::Low:
            s += "Low";
            break; 
        case Range::High:
            s += "High";
            break;
        default:
                s += "None";
        }
        return s;
    }
    std::ostream& CityTemperature::display(std::ostream& os) const{
        os << "Temperature: ";
        os << (m_temperature == TempType::Degree ? std::to_string(temperature.degree)
            : rangeStr(temperature.range));
        os << (tt == TempType::Degree ? " Deg. Celcius" : " Level");
        os << std::endl;
        os << "Advisory: ";
        if (m_message) {
            os << m_message << std::endl;
        }
        else {
            os << "not available" << std::endl;
        }
        return os;
    }
}