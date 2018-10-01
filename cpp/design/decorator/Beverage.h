#ifndef _BEVARAGE_H_
#define _BEVARAGE_H_

#include <iostream>
#include <string>

class Beverage
{
    public:
        virtual ~Beverage(){};

    public:
        virtual double cost() = 0;
        virtual std::string getDescription() = 0;
};


#endif //_BEVARAGE_H_
