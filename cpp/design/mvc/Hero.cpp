#include "Hero.h"
#include <iostream>

Hero::Hero()
{

}

Hero::~Hero()
{

}

void Hero::beAttack(int atk)
{
    if (atk < 0)
    {
        std::cout << " attack error must > 0" << std::endl;
    }

    this->m_Hp -= atk;
    this->m_Hp = (this->m_Hp < 0) ? 0 : this->m_Hp;

}
