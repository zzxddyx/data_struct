#include "ConcreteIterator.h"

ConcreteIterator::ConcreteIterator(Aggregate *pAggregate)
    :m_pAggregate(pAggregate), m_iCurrent(0)
{}

ConcreteIterator::~ConcreteIterator()
{}

string ConcreteIterator::First()
{
    return m_pAggregate->Pop(0);
}

string ConcreteIterator::Next()
{
    string strRet;
    m_iCurrent++;

    if (m_iCurrent < m_pAggregate->Count())
    {
        strRet = m_pAggregate->Pop(m_iCurrent);
    }

    return strRet;
}

string ConcreteIterator::getCur()
{
    return m_pAggregate->Pop(m_iCurrent);
}

bool ConcreteIterator::isEnd()
{
    return ((m_iCurrent >= m_pAggregate->Count()) ? true : false);
}
