#include "Singleton.h"

Singleton* Singleton::m_pInstance = NULL;

Singleton* Singleton::getInstance()
{
    if(NULL == m_pInstance)
    {
        m_pInstance = new Singleton();
    }

    return m_pInstance;
}

void Singleton::show()
{
    std::cout << "Singleton is OK" << std::endl;
}
