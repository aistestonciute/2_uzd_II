#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using std::string;
using std::vector;

#include "person.hpp"

class Student : public Person{
private:
    int exam, finalGrade;
    vector <int> hw;
public:
    Student() {exam = 0, finalGrade = 0, Person::name = "", Person::lastName = "";}
    
    int getExam() const {return exam;}
    int getFinalGrade() const {return finalGrade;}
    vector <int> getHw() const {return hw;} 

    void setExam(int _exam) {exam = _exam;}
    void setFinalGrade(int _finalGrade) {finalGrade = _finalGrade;}
    void setHw(vector <int> _hw) {hw = _hw;}

    Student (const Student& that) :
    exam(that.exam), finalGrade(that.finalGrade),
    hw(that.hw) 
    {
        name = that.getName();
        lastName = that.getLastName();
    }

    Student& operator=(const Student& that)
    {
        name = that.name;
        lastName = that.lastName;
        exam = that.exam;
        finalGrade = that.finalGrade;
        hw = that.hw;
        return *this;
    }

	 ~Student() {};
};



#endif
