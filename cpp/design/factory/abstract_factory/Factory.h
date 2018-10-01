#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Product2.h"
#include "Product1.h"

class Factory
{
    public:
        virtual Product1* create1() = 0;
        virtual Product2* create2() = 0;
};

#endif //_FACTORY_H_
