#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Product.h"

class Factory
{
    public:
        virtual Product* create() = 0;
};

#endif //_FACTORY_H_
