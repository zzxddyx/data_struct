#ifndef _FACTORY_A_H_
#define _FACTORY_A_H_

#include "Factory.h"
#include "Product_A.h"

class Factory_A : public Factory
{
    public:
        Product* create()
        {
            return new Product_A;
        }
};

#endif //_FACTORY_A_H_
