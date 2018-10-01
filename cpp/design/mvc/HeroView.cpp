#include "HeroView.h"
#include <iostream>

HeroView::HeroView()
{
}

HeroView::~HeroView()
{
}

void HeroView::show(int no, string name, int hp, int atk)
{
    std::cout << name << " in game: " << no << " attack is: " <<  atk << " now hp is:" << hp << std::endl;
}

void HeroView::dead(int no, string name)
{
    std::cout << "Hero " << name << " in game " << no << " is dead" << std::endl;
}

void HeroView::win(int no, string name)
{
    std::cout << "Hero " << name << " in game " << no << " is win" << std::endl;
}
