#include "HeroControl.h"

int main(void)
{
    HeroControl *ctrl1 = new HeroControl(1, "GaiLun");
    ctrl1->setHeroHp(100);
    ctrl1->setHeroAtk(10);
    ctrl1->show();

    HeroControl *ctrl2 = new HeroControl(1, "JianShen");
    ctrl2->setHeroHp(100);
    ctrl2->setHeroAtk(40);
    ctrl2->show();

    ctrl1->beAttack(ctrl2->getHero()->getAtk());
    ctrl1->show();
    ctrl2->show();

    while (!ctrl2->getHero()->isDead())
    {
        ctrl2->beAttack(ctrl1->getHero()->getAtk());
        ctrl2->show();
    }

    return 0;
}
