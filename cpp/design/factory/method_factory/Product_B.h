#ifndef _PRODUCT_B_H_
#define _PRODUCT_B_H_

#include "Product.h"

class Product_B : public Product
{
    public:
        void show()
        {
            std::cout << "Product_B" << std::endl;
        }
};

#endif //_PRODUCT_B_H_
