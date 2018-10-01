#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <iostream>
#include <string>

class Observer
{
    public:
        Observer(std::string _name, std::string _type)
            :name(_name), type(_type)
        {}
        virtual ~Observer(){};

    public:
        virtual std::string getName() = 0;
        virtual std::string getType() = 0;
        virtual void Update(const std::string &) = 0;
    protected:
        std::string name;
        std::string type;
};

#endif //_OBSERVER_H_
