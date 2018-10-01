#ifndef _FACTORY_B_H_
#define _FACTORY_B_H_

#include "Factory.h"
#include "Product_B.h"

class Factory_B : public Factory
{
    public:
        Product* create()
        {
            return new Product_B;
        }
};

#endif //_FACTORY_B_H_
