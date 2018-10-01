#include "Factory.h"
#include "Product.h"
#include "Factory_A.h"
#include "Factory_B.h"

int main()
{
    Factory *factory_a = new Factory_A();
    Factory *factory_b = new Factory_B();

    factory_a->create()->show();
    factory_b->create()->show();
    return 0;
}
