#ifndef _COOK_H_
#define _COOK_H_

#include "Eat.h"

class Cook : public Eat
{
    public:
        Cook();
        ~Cook();

    public:
        void prepare();
        void cooking();
        void eating();
        void cleaning();
};

#endif //_COOK_H_
