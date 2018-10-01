#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Product.h"
#include "Product_A.h"
#include "Product_B.h"

class Factory
{
    public:
        Product *create(int i);
};

#endif //_FACTORY_H_
