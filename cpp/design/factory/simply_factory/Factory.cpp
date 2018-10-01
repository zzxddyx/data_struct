#include "Factory.h"

Product* Factory::create(int i)
{
    switch(i)
    {
        case 1:
            return new Product_A;
            break;
        case 2:
            return new Product_B;
            break;
        default:
            break;
    }
}
