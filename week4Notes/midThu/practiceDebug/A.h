#ifndef A_H
#define A_H
struct A
{
    public: // Error 1
    double m_val;
    public:
    A operator+=(const A& other){
        this->m_val += other.m_val;
        return *this;
    }
    double getValue()const {return m_val;};
};

decltype(A().getValue()) operator+=(double& val, const A& other);

template <typename T, int N> // error 3 solved
T process(const T data[]){
    T sum{};
    for(const auto& elem:data){ // error 2
        sum += elem;
    }
    return sum;
}

#endif  // A_H