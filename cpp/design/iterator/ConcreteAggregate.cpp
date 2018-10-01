#include "ConcreteAggregate.h"
#include "ConcreteIterator.h"

ConcreteAggregate::ConcreteAggregate()
    :m_pIterator(NULL)
{
    m_vecItems.clear();
}

ConcreteAggregate::~ConcreteAggregate()
{
    if (NULL != m_pIterator)
    {
        delete m_pIterator;
        m_pIterator = NULL;
    }
}

int ConcreteAggregate::Count()
{
    return m_vecItems.size();
}

void ConcreteAggregate::Push(const string &str)
{
    m_vecItems.push_back(str);
}

string ConcreteAggregate::Pop(const int index)
{
    string strRet;
    if (index < this->Count())
    {
        strRet = m_vecItems[index];
    }

    return strRet;
}

Iterator* ConcreteAggregate::CreateIterator()
{
    if (NULL == m_pIterator)
    {
        m_pIterator = new ConcreteIterator(this);
    }

    return this->m_pIterator;
}
