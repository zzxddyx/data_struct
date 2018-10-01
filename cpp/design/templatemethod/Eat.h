#ifndef _EAT_H_
#define _EAT_H_

class Eat
{
    public:
        Eat();
        virtual ~Eat();
    public:
        void feed();

        virtual void prepare() = 0;
        virtual void cooking() = 0;
        virtual void eating();
        virtual void cleaning();

        virtual bool by_self();
};

#endif //_EAT_H_
