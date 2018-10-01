#ifndef _SOY_H_
#define _SOY_H_

#include "Decorator.h"

class Soy : public Decorator
{
    public:
        double cost()
        {
            return this->getObserver()->cost() + 1000;
        }
};

#endif //_SOY_H_
