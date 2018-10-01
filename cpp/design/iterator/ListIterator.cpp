#include "ListIterator.h"

ListIterator::ListIterator(Aggregate *pAggregate)
    :m_pAggregate(pAggregate), m_iCurrent(0)
{
}

ListIterator::~ListIterator()
{
}

string ListIterator::First()
{
    return m_pAggregate->Pop(0);
}

string ListIterator::Next()
{
    string strRes;
    m_iCurrent++;

    if (m_iCurrent < m_pAggregate->Count())
    {
        strRes = m_pAggregate->Pop(m_iCurrent);
    }

    return strRes;
}

string ListIterator::getCur()
{
    return m_pAggregate->Pop(m_iCurrent);
}

bool ListIterator::isEnd()
{
    return ((m_iCurrent >= m_pAggregate->Count()) ? true : false);
}
