
#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H
#include <iostream>
namespace sdds{

double calcAverage(std::vector<Learner>::iterator begin, std::vector<Learner>::iterator end){
    double sum = 0;
    int count = 0;
    for (auto it = begin; it != end; it++) {
        sum += Learner[it].mark;
        count++;
    }
    return sum / count;
}
class Subject{
    std::vector<sdds::Learner> m_learners;
    bool isAvgcalculated;
    size_t avgMark;
    public:
    Subject();
    Learner& operator+=(const Learner&);
    void display(std::ostream&) const;
    Learner* operator[](const char* name);
};
}
#endif // SDDS_SUBJECT_H

// subject.cpp
#include "Subject.h"
using namespace std;
using namespace sdds;
Subject::Subject(){
    isAvgcalculated = false;
}
Learner& Subject::operator+=(const Learner& learner){
    m_learners.push_back(learner);
    isAvgcalculated = false;
    return m_learners.back();
}
void Subject::display(ostream& os) const{
    if(!isAvgcalculated){
        avgMark = 0;
        for(auto& learner : m_learners){
            avgMark += learner.getMark();
        }
        avgMark /= m_learners.size();
        isAvgcalculated = true;
    }
    os << "Subject Name: " << m_learners.front().getSubjectName() << endl;
    os << "Subject Average: " << avgMark << endl;
    os << "----------------------------------------" << endl;
    for(auto& learner : m_learners){
        learner.display(os);
    }
}
Learner* Subject::operator[](const char* name){
    for(auto& learner : m_learners){
        if(learner.getName() == name){
            return &learner;
        }
    }
    return nullptr;
}