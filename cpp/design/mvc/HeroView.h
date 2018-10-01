#ifndef _HERO_VIEW_H_
#define _HERO_VIEW_H_

#include <string>
using std::string;

class HeroView
{
    public:
        HeroView();
        virtual ~HeroView();

    public:
        void show(int no, string name, int hp, int atk);
        void dead(int no, string name);
        void win(int no, string name);
};

#endif //_HERO_VIEW_H_
