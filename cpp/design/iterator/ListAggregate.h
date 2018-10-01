#ifndef _LIST_AGGREGATE_H_
#define _LIST_AGGREGATE_H_

#include "Aggregate.h"
#include <deque>

using std::deque;
using std::string;

class ListAggregate : public Aggregate
{
    public:
        ListAggregate();
        virtual ~ListAggregate();
    public:
        int Count();
        void Push(const string &);
        string Pop(const int);
        Iterator *CreateIterator();

    private:
        deque<string> m_listItems;
        Iterator *m_pIterator;
};

#endif //_LIST_AGGREGATE_H_
