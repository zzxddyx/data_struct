#include "Kfc.h"
#include <iostream>

Kfc::Kfc()
{
}

Kfc::~Kfc()
{
}

bool Kfc::by_self()
{
    return false;
}

void Kfc::prepare()
{
    std::cout << "sit and order" << std::endl;
}

void Kfc::cooking()
{
    std::cout << "By Cooker not me" << std::endl;
}
