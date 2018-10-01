#ifndef _MILK_H_
#define _MILK_H_

#include "Decorator.h"

class Milk : public Decorator
{
    public:
        double cost()
        {
            return this->getObserver()->cost() + 1;
        }
};

#endif //_MILK_H_
