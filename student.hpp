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
    Student(string _name, string _lastName, int _exam, int _final, vector <int> _hw)
    {
        name = _name;
        lastName = _lastName;
        exam = _exam;
        final = _final;
        hw = _hw;
    }
    string getName() const {return name;}
    string getLastName() const {return lastName;}
    int getExam() const {return exam;}
    int getFinal() const {return final;}
    vector <int> getHw() const {return hw;} 
    ~Student() {};
};

#endif
