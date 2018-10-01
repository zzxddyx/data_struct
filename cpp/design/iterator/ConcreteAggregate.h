#ifndef _CONCRETE_AGGREGATE_H_
#define _CONCRETE_AGGREGATE_H_

#include <vector>
#include <string>
#include "Aggregate.h"

using std::vector;
using std::string;

class ConcreteAggregate : public Aggregate
{
    public:
        ConcreteAggregate();
        virtual ~ConcreteAggregate();
    public:
        int Count();
        void Push(const string &);
        string Pop(const int);
        Iterator *CreateIterator();
    private:
        vector<string> m_vecItems;
        Iterator *m_pIterator;
};

#endif //_CONCRETE_AGGREGATE_H_
