#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
enum class State
{
    OH, // Ohio
    PA, // Pennsylvania
    WA, // Washington
    FL  // Florida
};
struct EndangeredFish
{
    std::string m_spices; // name of spieces
    State m_state;        // state fish found in
    std::string m_name;   // common name of fish
    int m_year;           // year surveyed on
    int m_month;          // month surveyed on
    std::string m_genus;  // fish genus
    int m_length;         // avg. length of fish in inches
    int m_weight;         // avg. weight of fish in lbs
    int m_count;          // total number of fishes
};
std::vector<EndangeredFish> fishDataProcessor(std::list<EndangeredFish> &ef)
{
    std::for_each(ef.begin(), ef.end(), [](EndangeredFish &ef)
                  {
        if(ef.m_count/ef.m_weight > 30){
            cout<<"Species: "<<ef.m_spices<<", count: "<<ef.m_count<<", weight: "<<ef.m_weight<<endl;
        } });
    int count = std::count_if(ef.begin(), ef.end(), [](EndangeredFish &ef)
                              {
        if((ef.m_month == 6 || ef.m_month == 7)&& (ef.m_year % 2 ==0)){
            return true;
        }
        else{
            return false;
        } });
    cout << "Number of fish surveyed in June or July in even years: " << count << endl;
    std::vector<EndangeredFish> cpy;
    std::copy_if(ef.begin(), ef.end(), std::back_inserter(cpy), [](EndangeredFish &ef)
                 {
        if(ef.m_year >= 2005 && ef.m_count < 500){
            return true;
        }
        else{
            return false;
        } });
    std::vector<EndangeredFish> v;
    std::copy(cpy.begin(), cpy.end(), std::back_inserter(v));
    remove_if(v.begin(), v.end(), [](EndangeredFish &ef)
              {
        if(ef.m_length <10 && ef.m_weight < 5 ){
            return true;
        }
        else{
            return false;
        } });
    std::sort(v.begin(), v.end(), [](EndangeredFish &ef1, EndangeredFish &ef2)
              {
        if((ef1.m_length/ef1.m_weight)< (ef2.m_length/ef2.m_weight)){
            return true;
        }
        else{
            return false;
        } });

    return cpy;
}