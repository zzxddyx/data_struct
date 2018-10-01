#ifndef _LIST_ITERATOR_H_
#define _LIST_ITERATOR_H_

#include "Iterator.h"
#include "Aggregate.h"

class ListIterator : public Iterator
{
    public:
        ListIterator(Aggregate *pAggregate);
        virtual ~ListIterator();

    public:
        string First();
        string Next();
        string getCur();
        bool isEnd();

    private:
        Aggregate *m_pAggregate;
        int m_iCurrent;

};


#endif //_LIST_ITERATOR_H_
