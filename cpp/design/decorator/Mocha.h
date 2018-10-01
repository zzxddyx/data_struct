#ifndef _MOCHA_H_
#define _MOCHA_H_

#include "Decorator.h"

class Mocha : public Decorator
{
    public:
        double cost()
        {
            return this->getObserver()->cost() + 100;
        }
};

#endif //_MOCHA_H_
