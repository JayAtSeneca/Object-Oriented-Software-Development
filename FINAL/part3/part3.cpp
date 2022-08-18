#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
using namespace std;
struct Kitchenware
{
    std::string description;
    std::string brand;
    double price;
    bool electric;
};
std::vector<Kitchenware> updateWares(std::list<Kitchenware> &collection)
{
    // 1. Sum up the total price of electric Kitchenware in the collection and print it to the screen.
    auto totalPrice = std::accumulate(collection.begin(), collection.end(), (double)0.0, [](const Kitchenware &k1, const Kitchenware &k2)
                                      {
        if(k1.electric && k2.electric){
            return k1.price + k2.price;
        } });
    std::cout << "Total price of electric kitchenware: " << totalPrice << endl;

    // 2. Count the number of non electric Kitchenware in the collection and print it to the screen.
    auto count = std::count_if(collection.begin(), collection.end(), [](const Kitchenware &k)
                               {
        if(k.electric == false){
            return true;
        }
        return false; });
    std::cout << "Number of non electric kitchenware: " << count << endl;

    // 3. Change all the non electric Kitchenware in the collection into electric wares by increasing the price by 50 and changing the electric status
    std::for_each(collection.begin(), collection.end(), [](Kitchenware &k)
                  {
        if(!k.electric){
            k.price += 50;
            k.electric = true;
        }
        return k; });
    // 4. Copy all the Kitchenware in the collection into a vector (the return value)
    std::vector<Kitchenware> retCollection;
    std::copy(collection.begin(), collection.end(), std::back_inserter(retCollection));

    // 5. Remove all the Kitchenware from the vector where the brand is “Unknown”.
    std::remove_if(retCollection.begin(), retCollection.end(), [](const Kitchenware &k)
                   {
        if(k.brand == "Unknown"){
            return true;
        }
        return false; });
    return retCollection;
}