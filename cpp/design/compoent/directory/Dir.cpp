#include "Dir.h"
#include <iostream>

Dir::Dir(string name)
    :m_name(name)
{
    m_list = new list<IFile *>();
}

Dir::~Dir()
{
    if( NULL != m_list )
    {
        delete m_list;
        m_list = NULL;
    }
}

void Dir::display()
{
    std::cout << this->m_name << std::endl;
}

int Dir::add(IFile *file)
{
    m_list->push_back(file);
    return 0;
}

int Dir::remove(IFile *file)
{
    m_list->remove(file);
    return 0;
}

list<IFile*>* Dir::getChild()
{
    return this->m_list;
}
