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
    Temperature m_degree{.};
    char* m_message{};
   static int numOfObjects;
   public: