#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <vector>
using std::string;

class Person{
protected:
    string name, lastName;

public:
    virtual ~Person() {};
    string getName() const {return name;}
    string getLastName() const {return lastName;}
    void setName(string _name) {name = _name;}
    void setLastName(string _lastName) {lastName = _lastName;}
};
#endif
