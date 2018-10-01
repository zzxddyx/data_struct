#ifndef _FACTORYA_H_
#define _FACTORYA_H_

#include "Factory.h"
#include "Product1.h"
#include "Product2.h"
#include "ProductA1.h"
#include "ProductA2.h"

class FactoryA : public Factory
{
    public:
        Product1* create1()
        {
            return new ProductA1();
        };
        Product2* create2()
        {
            return new ProductA2();
        };
};

#endif //_FACTORYA_H_
