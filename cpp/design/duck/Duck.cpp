#include "Duck.h"

void Duck::performFly()
{
    flyBehavior->fly();
}

void Duck::performQuack()
{
    quackBehavior->quack();
}

void Duck::swim()
{
    std::cout << "All Duck float, even decoys !" << std::endl;
}

void Duck::display()
{
    std::cout << "Is Duck" << std::endl;
}

void Duck::setFlyBehavior(FlyBehavior *fb)
{
    flyBehavior = fb;
}

void Duck::setQuackBehavior(QuackBehavior *qb)
{
    quackBehavior = qb;
}
