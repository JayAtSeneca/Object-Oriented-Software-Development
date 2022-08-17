#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

enum class State
{
   OH, // Ohio
   PA, // Pennsylvania
   WA, // Washington
   FL  // Florida
};

struct EndangeredFish
{
   std::string m_spices;   // name of spieces
   State m_state;          // state fish found in 
   std::string m_name;     // common name of fish
   int m_year;             // year surveyed on
   int m_month;            // month surveyed on
   std::string m_genus;    // fish genus
   int m_length;           // avg. length of fish in inches
   int m_weight;           // avg. weight of fish in lbs
   int m_count;            // total number of fishes
};

std::vector<EndangeredFish> fishDataProcessor(std::list<EndangeredFish> &);

int main()
{
   std::list<EndangeredFish> endangeredFishList = {
       {"Walleye", State::PA, "Yellowbelly", 2010, 5, "Sander vitreus", 24, 3, 1000},
       {"Muskellunge", State::WA, "Muskie", 2009, 5, "Esox masquinongy", 42, 8, 200},
       {"Brook Trout", State::FL, "Speckled Trout", 2008, 6, "Salvelinus fontinalis", 18, 2, 1500},
       {"Cutthroat Trout", State::OH, "Cutthroat", 2007, 7, "Oncorhynchus clarkii", 16, 1, 2000},
       {"Lake Trout", State::FL, "Mackinaw", 2006, 8, "Salvelinus namaycush", 36, 6, 400},
       {"Brook Trout", State::PA, "Speckled Trout", 2005, 9, "Salvelinus fontinalis", 18, 2, 600},
       {"Cutthroat Trout", State::WA, "Cutthroat", 2004, 10, "Oncorhynchus clarkii", 16, 1, 700},
       {"Lake Trout", State::OH, "Mackinaw", 2003, 11, "Salvelinus namaycush", 36, 6, 800},
       {"Brook Trout", State::FL, "Speckled Trout", 2002, 12, "Salvelinus fontinalis", 18, 2, 900},
       {"Cutthroat Trout", State::PA, "Cutthroat", 2001, 1, "Oncorhynchus clarkii", 16, 1, 950},
       {"Lake Trout", State::WA, "Mackinaw", 2000, 2, "Salvelinus namaycush", 36, 6, 1000},
       {"Brook Trout", State::OH, "Speckled Trout", 1999, 3, "Salvelinus fontinalis", 18, 2, 1100},
       {"Cutthroat Trout", State::FL, "Cutthroat", 1998, 4, "Oncorhynchus clarkii", 16, 1, 1200},
       {"Lake Trout", State::PA, "Mackinaw", 1997, 5, "Salvelinus namaycush", 36, 6, 1300},
       {"Brook Trout", State::WA, "Speckled Trout", 1996, 6, "Salvelinus fontinalis", 18, 2, 1400},
       {"Cutthroat Trout", State::OH, "Cutthroat", 1995, 7, "Oncorhynchus clarkii", 16, 1, 1500},
       {"Lake Trout", State::FL, "Mackinaw", 1994, 8, "Salvelinus namaycush", 36, 6, 1600},
       {"Brook Trout", State::PA, "Speckled Trout", 1993, 9, "Salvelinus fontinalis", 18, 2, 1700},
       {"Cutthroat Trout", State::WA, "Cutthroat", 1992, 10, "Oncorhynchus clarkii", 16, 1, 1800},
       {"Lake Trout", State::OH, "Mackinaw", 1991, 11, "Salvelinus namaycush", 36, 6, 1900},
       {"Brook Trout", State::FL, "Speckled Trout", 1990, 12, "Salvelinus fontinalis", 18, 2, 2000}};

   std::vector<EndangeredFish> endangeredFishVector = fishDataProcessor(endangeredFishList);

   return 0;
}

std::vector<EndangeredFish> fishDataProcessor(std::list<EndangeredFish> &endangeredFishList)
{
   // Task-1
   std::cout << "\nTask-1\n";
   std::for_each(endangeredFishList.begin(), endangeredFishList.end(), [](EndangeredFish endangeredFish) {
      if ((endangeredFish.m_count / endangeredFish.m_weight) > 30.0)
      {
         std::cout << "Species: " << endangeredFish.m_spices << ", count: " << endangeredFish.m_count
                   << ", weight: " << endangeredFish.m_weight << "\n";
      }
   });

   // Task-2
   std::cout << "\n\nTask-2\n";
   int totalEndangeredFishObjects = std::count_if(endangeredFishList.begin(), endangeredFishList.end(), [](EndangeredFish endangeredFish) {
      int year = endangeredFish.m_year;
      int month = endangeredFish.m_month;
      return ((year % 2 == 0 && month == 6) || (year % 2 == 1 && month == 7));
   });

   std::cout << "Total number of endangered fish objects: " << totalEndangeredFishObjects << "\n";

   // Task-3
   std::cout << "\n\nTask-3\n";
   std::vector<EndangeredFish> endangeredFishVector;
   std::copy_if(endangeredFishList.begin(), endangeredFishList.end(), std::back_inserter(endangeredFishVector), [](EndangeredFish endangeredFish) {
      return (endangeredFish.m_year >= 2005 && endangeredFish.m_count <= 500);
   });

   // Task-4
   std::cout << "\n\nTask-4\n";
   bool anyEndangeredFishhasLengthLessThan10InchesWeightLessThan5Lbs = std::any_of(endangeredFishVector.begin(), endangeredFishVector.end(), [](EndangeredFish endangeredFish) {
      return (endangeredFish.m_length < 10 && endangeredFish.m_weight < 5);
   });

   if (anyEndangeredFishhasLengthLessThan10InchesWeightLessThan5Lbs)
   {
      std::cout << "There is at least one endangered fish with length less than 10 inches and weight less than 5 lbs\n";
   }
   else
   {
      std::cout << "There is no endangered fish with length less than 10 inches and weight less than 5 lbs\n";
   }

   // Task-5
   std::cout << "\n\nTask-5\n";
   std::sort(endangeredFishVector.begin(), endangeredFishVector.end(), [](EndangeredFish endangeredFish1, EndangeredFish endangeredFish2) {
      return (endangeredFish1.m_length / endangeredFish1.m_weight) < (endangeredFish2.m_length / endangeredFish2.m_weight);
   });

   std::for_each(endangeredFishVector.begin(), endangeredFishVector.end(), [](EndangeredFish endangeredFish) {
      std::cout << "Species: " << endangeredFish.m_spices << ", length: " << endangeredFish.m_length << ", weight: " << endangeredFish.m_weight << ", length to weight ratio: " << (endangeredFish.m_length / endangeredFish.m_weight) << "\n";
   });

   return endangeredFishVector;
}