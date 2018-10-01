#include "FactoryA.h"
#include "FactoryB.h"

int main()
{
    FactoryA *factorya = new FactoryA();
    factorya->create1()->show();
    factorya->create2()->show();

    FactoryB *factoryb = new FactoryB();
    factoryb->create1()->show();
    factoryb->create2()->show();

    return 0;
}


