#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using std::string;
using std::vector;

#include "person.hpp"

class Student : public Person{
private:
    int exam, final;
    vector <int> hw;
public:
    Student() {exam = 0, final = 0, Person::name = "", Person::lastName = "";}

    int getExam() const {return exam;}
    int getFinal() const {return final;}
    vector <int> getHw() const {return hw;} 

    void setExam(int _exam) {exam = _exam;}
    void setFinal(int _final) {final = _final;}
    void setHw(vector <int> _hw) {hw = _hw;}
    
    /*Student(const Student& that) :
        {
            name = that.getName(); lastName = that.getLastName();
            exam = that.getExam(); final = that.getFinal();
            hw = that.getHw();
        }*/

    Student (const Student& that) :
    exam(that.exam), final(that.final),
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
        final = that.final;
        hw = that.hw;
        return *this;
    }

	 ~Student() {};
};



#endif
