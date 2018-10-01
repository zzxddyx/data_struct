#ifndef _HERO_H_
#define _HERO_H_

#include <string>
using std::string;

class Hero
{
    public:
        Hero();
        virtual ~Hero();

    public:
        void beAttack(int atk);

    public:
        bool isDead()
        {
            return (0==m_Hp);
        }

    public:
        void setNo(int no)
        {
            this->m_No = no;
        }
        int getNo()
        {
            return this->m_No;
        }
        void setName(string name)
        {
            this->m_Name = name;
        }
        string getName()
        {
            return this->m_Name;
        }
        void setHp(int hp)
        {
            this->m_Hp = hp;
        }
        int getHp()
        {
            return this->m_Hp;
        }
        void setAtk(int atk)
        {
            this->m_Attack = atk;
        }
        int getAtk()
        {
            return this->m_Attack;
        }

    private:
        int m_No;
        string m_Name;
        int m_Hp;
        int m_Attack;
};

#endif //_HERO_H_
