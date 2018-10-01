#ifndef _PRODUCT_A_H_
#define _PRODUCT_A_H_

#include "Product.h"
class Product_A : public Product
{
    public:
        virtual void show()
        {
            std::cout << "Product_A" << std::endl;
        }
};

#endif //_PRODUCT_A_H_
