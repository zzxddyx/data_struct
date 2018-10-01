#include "Factory.h"

int main(void)
{
    Factory *factory = new Factory();

    factory->create(1)->show();
    factory->create(2)->show();

    delete factory;

    return 0;
}
