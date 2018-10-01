#ifndef _KFC_H_
#define _KFC_H_

#include "Eat.h"

class Kfc : public Eat
{
    public:
        Kfc();
        virtual ~Kfc();

    public:
        void prepare();
        void cooking();
        bool by_self();
};

#endif //_KFC_H_
