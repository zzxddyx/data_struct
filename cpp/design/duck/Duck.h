#ifndef _DUCK_H_
#define _DUCK_H_

#include <iostream>
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class Duck
{
    public:
        Duck(){}
        Duck(FlyBehavior *_flyBehavior, QuackBehavior *_quackBehavior)
            :flyBehavior(_flyBehavior), quackBehavior(_quackBehavior)
        {}
        virtual void performFly();
        virtual void performQuack();
        virtual void swim();
        virtual void display();
        virtual void setFlyBehavior(FlyBehavior *fb);
        virtual void setQuackBehavior(QuackBehavior *qb);

    private:
        FlyBehavior *flyBehavior;
        QuackBehavior *quackBehavior;
};

#endif // _DUCK_H_
