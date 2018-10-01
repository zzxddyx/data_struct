#include "Reveiver.h"
#include <iostream>

Reveiver::Reveiver()
{
    std::cout << "I'm Command Execute" << std::endl;
}

void Reveiver::TakeOrder()
{
    std::cout << "Take Order !..." << std::endl;
}

void Reveiver::ReceIpt()
{
    std::cout << "Rece Ipe !..." << std::endl;
}
