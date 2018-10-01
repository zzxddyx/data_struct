#ifndef _CONCRETE_ITERATOR_H_
#define _CONCRETE_ITERATOR_H_

#include "Iterator.h"
#include "Aggregate.h"

class ConcreteIterator : public Iterator
{
    public:
        ConcreteIterator(Aggregate *pAggregate);
        virtual ~ConcreteIterator();

    public:
        string First();
        string Next();
        string getCur();
        bool isEnd();

    private:
        Aggregate *m_pAggregate;
        int m_iCurrent;
};

#endif //_CONCRETE_ITERATOR_H_
