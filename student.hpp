#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class Student{
private:
    string name, lastName;
    int exam, final;
    vector <int> hw;
public:
    Student() {exam = 0, final = 0, name = "", lastName = "";}

    string getName() const {return name;}
    string getLastName() const {return lastName;}
    int getExam() const {return exam;}
    int getFinal() const {return final;}
    vector <int> getHw() const {return hw;} 

    void setName(string _name) {name = _name;}
    void setLastName(string _lastName) {name = _lastName;}
    void setExam(int _exam) {exam = _exam;}
    void setFinal(int _final) {final = _final;}
    void setHw(vector <int> _hw) {hw = _hw;}
    
    Student(const Student& that) :
        name(that.name), lastName(that.lastName),
        exam(that.exam), final(that.final),
        hw(that.hw) {}

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
