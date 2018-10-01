#include "ListAggregate.h"
#include "ListIterator.h"

ListAggregate::ListAggregate()
    :m_pIterator(NULL)
{
    m_listItems.clear();
}

ListAggregate::~ListAggregate()
{
    if (NULL != m_pIterator)
    {
        delete m_pIterator;
        m_pIterator = NULL;
    }
}

int ListAggregate::Count()
{
    return m_listItems.size();
}

void ListAggregate::Push(const string &str)
{
    m_listItems.push_back(str);
}

string ListAggregate::Pop(const int index)
{
    string strRet;
    if (index < this->Count())
    {
        strRet = m_listItems[index];
    }
    return strRet;
}

Iterator* ListAggregate::CreateIterator()
{
    if (NULL == m_pIterator)
    {
        m_pIterator = new ListIterator(this);
    }

    return this->m_pIterator;
}
