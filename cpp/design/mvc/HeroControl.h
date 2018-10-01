#ifndef _HERO_CONTROL_H_
#define _HERO_CONTROL_H_

#include "Hero.h"
#include "HeroView.h"
#include <string>
using std::string;

class HeroControl
{
    public:
        HeroControl(int no, string name);
        virtual ~HeroControl();

    public:
        void setHeroHp(int hp);
        void setHeroAtk(int atk);
        void show();
        void beAttack(int atk);
        void dead();
        void win();

    public:
        Hero *getHero()
        {
            return this->m_pHero;
        }

    private:
        Hero *m_pHero;
        HeroView *m_pHeroView;
};

#endif //_HERO_CONTROL_H_
