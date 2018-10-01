#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>
#include <pthread.h>

class Singleton
{
    public:
        static Singleton* getInstance();
        void show();

    private:
        static Singleton *m_pInstance;
        static pthread_mutex_t mutex;

    private:
        Singleton()
        {
            pthread_mutex_init(&mutex, NULL);
        };
        Singleton(const Singleton&)
        {
            pthread_mutex_init(&mutex, NULL);
        };
        Singleton& operator=(const Singleton&)
        {
            pthread_mutex_init(&mutex, NULL);
        };
};

#endif //_SINGLETON_H_
