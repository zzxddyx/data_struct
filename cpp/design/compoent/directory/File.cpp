#include "File.h"
#include <iostream>

File::File(string name)
    :m_name(name)
{
}

File::~File()
{
}

void File::display()
{
    std::cout << this->m_name << std::endl;
}

int File::add(IFile *)
{
    return -1;
}

int File::remove(IFile *)
{
    return -1;
}

list<IFile*>* File::getChild()
{
    return NULL;
}
