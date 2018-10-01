#include "Singleton.h"

Singleton* Singleton::m_pInstance = NULL;
pthread_mutex_t Singleton::mutex;

Singleton* Singleton::getInstance()
{
    if (NULL == m_pInstance)
    {
        pthread_mutex_lock(&mutex);
        if (NULL == m_pInstance)
        {
            m_pInstance = new Singleton();
        }
        pthread_mutex_unlock(&mutex);
    }

    return m_pInstance;
}

void Singleton::show()
{
    std::cout << "info : " << std::endl; 
}
