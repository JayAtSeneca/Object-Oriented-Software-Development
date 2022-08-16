#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <future>
#include <thread>
struct CarInfo {
	int id;
	char make[22];
	unsigned char status_pattern;
};
class CarCollection {
	CarInfo* m_car{ nullptr };
	size_t n_cars{ 0 };
public:
    CarCollection(): m_car{ nullptr }, n_cars{ 0 } {}
    CarCollection& load(const std::string& filename){
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Error opening file " << filename << std::endl;
            return *this;
        }
        file.seekg(0, std::ios::end);
        size_t size = file.tellg();
        file.seekg(0, std::ios::beg);
        n_cars = size / sizeof(CarInfo);
        m_car = new CarInfo[n_cars];
        file.read((char*)m_car, size);
        file.close();
        return *this;
    }
    size_t size()const{
        return n_cars;
    }
    CarInfo at(unsigned int index){
        if(index < 0){
            return m_car[0];
        }
        else if(index>n_cars){
            return m_car[n_cars-1];
        }
        else{
            return m_car[index];
        }
    }
    CarCollection(const CarCollection& other) = delete;
    CarCollection& operator=(const CarCollection& other) = delete;
    CarCollection(CarCollection&& other) = delete;
    CarCollection& operator=(CarCollection&& other) = delete;
};
void countInsuredHybrid(std::promise<int>& p, const CarCollection& cars, std::vector<CarCollection>::iterator begin, std::vector<CarCollection>::iterator end){
    int count = 0;
    for(auto it = begin; it != end; ++it){
        for(size_t i = 0; i < it->size(); ++i){
            CarInfo car = it->at(i);
            if(car.status_pattern & 0x01 && car.status_pattern & 0x02){
                count++;
            }
        }
    }
    p.set_value(count);
}
int main()
{

    CarCollection cc,cc1;
    cc.load("car_info.dat");
    size_t size = cc.size();

    // construct promise and future objects, initialize future objects to be able to access the 
    //  data set by the promise objects while a task is being executed.  
    std::promise<int> p[5];
    std::future<int> f[5];
    for(int i = 0; i < 5; ++i){
        f[i] = p[i].get_future();
    }

    // set five threads into execution to run countValidHybrid function with five 
    // non-overlapping segments of the dynamic array carried by the cc object. 
    std::thread t[5];
    std::vector<CarCollection> v;
    v.push_back(cc);
    for(int i = 0; i<5;i++){
        t[i] = std::thread(countInsuredHybrid, std::ref(p[i]), std::ref(cc), v.begin(), v.end());
    }

    // use future objects to access the counts computed by different threads and add them together. 
    int count = 0;
    for(int i = 0; i < 5; ++i){
        count += f[i].get();
    }

    // synchronize the threads
    for(int i = 0; i < 5; ++i){
        t[i].join();
    }

    std::cout << "Number of elements: " << count << std::endl;

}