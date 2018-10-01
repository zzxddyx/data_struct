#include <iostream>
#include "Eat.h"

Eat::Eat()
{

}

Eat::~Eat()
{

}

void Eat::feed()
{
    if (true == this->by_self())
    {
        this->prepare();
        this->cooking();
    }

    this->eating();

    if (true == this->by_self())
    {
        this->cleaning();
    }
}

void Eat::eating()
{
    std::cout << "Food is delicious !" << std::endl;
}

void Eat::cleaning()
{
    std::cout << "I'm clean pleats and cups !" << std::endl;
}

bool Eat::by_self()
{
    return true;
}
