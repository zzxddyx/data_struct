#ifndef _PRODUCTB_H_
#define _PRODUCTB_H_

#include "Factory.h"
#include "Product1.h"
#include "Product2.h"
#include "ProductB1.h"
#include "ProductB2.h"

class FactoryB : public Factory
{
    public:
        Product1* create1()
        {
            return new ProductB1();
        }
        Product2* create2()
        {
            return new ProductB2();
        }
};

#endif //_PRODUCTB_H_
