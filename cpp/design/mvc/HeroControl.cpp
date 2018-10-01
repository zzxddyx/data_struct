#include "HeroControl.h"

HeroControl::HeroControl(int no, string name)
{
    m_pHero = new Hero();
    m_pHeroView = new HeroView();

    m_pHero->setNo(no);
    m_pHero->setName(name);
}

HeroControl::~HeroControl()
{
    if (m_pHero != NULL)
    {
        delete m_pHero;
        m_pHero = NULL;
    }

    if (m_pHeroView != NULL)
    {
        delete m_pHeroView;
        m_pHeroView = NULL;
    }
}

void HeroControl::setHeroHp(int hp)
{
    m_pHero->setHp(hp);
}

void HeroControl::setHeroAtk(int atk)
{
    m_pHero->setAtk(atk);
}

void HeroControl::show()
{
    m_pHeroView->show(m_pHero->getNo(), m_pHero->getName(), m_pHero->getHp(), m_pHero->getAtk());
}

void HeroControl::beAttack(int atk)
{
    m_pHero->beAttack(atk);
}

void HeroControl::dead()
{
    m_pHeroView->dead(m_pHero->getNo(), m_pHero->getName());
}

void HeroControl::win()
{
    m_pHeroView->win(m_pHero->getNo(), m_pHero->getName());
}
