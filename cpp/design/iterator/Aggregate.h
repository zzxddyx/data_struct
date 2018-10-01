#ifndef _AGGREGATE_H_
#define _AGGREGATE_H_

#include "Iterator.h"

class Aggregate
{
    public:
        virtual int Count() = 0;
        virtual void Push(const string &) = 0;
        virtual string Pop(const int) = 0;
        virtual Iterator* CreateIterator() = 0;
};

#endif //_AGGREGATE_H_
