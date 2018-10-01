#include "Cook.h"
#include <iostream>

Cook::Cook()
{
}

Cook::~Cook()
{
}

void Cook::prepare()
{
    std::cout << "vegetables, noodles and fruit" << std::endl;
}

void Cook::cooking()
{
    std::cout << "start" << std::endl;
}

void Cook::eating()
{
    std::cout << "delicious" << std::endl;
}

void Cook::cleaning()
{
    std::cout << "It's good" << std::endl;
}
