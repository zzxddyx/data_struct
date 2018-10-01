#define _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
        Person(const string _name, const string _address)
            :name(_name), address(_address)
        {}

        Person(const Person &ref)
            :name(ref.name), address(ref.address)
        {}

        string getName() const
        {
            return this->name;
        }
        string getAddr() const
        {
            return this->address;
        }
    private:
        string name;
        string address;
};

#endif //_PERSON_H_
