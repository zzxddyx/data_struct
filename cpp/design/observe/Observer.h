#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <iostream>
#include <string>

class Observer
{
    public:
        virtual ~Observer(){};
    public:
        virtual void Update(const std::string &msg) = 0;
        virtual std::string getName() = 0;
};

#endif //_OBSERVER_H_
