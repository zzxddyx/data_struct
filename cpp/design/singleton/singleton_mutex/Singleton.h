#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>
#include <pthread.h>

class Singleton
{
    public:
        static Singleton* getInstance();
        void show();

    public:
        static pthread_mutex_t mutex;

    private:
        static Singleton *m_pInstance;

    private:
        Singleton()
        {
            pthread_mutex_init(&mutex, NULL);
        };
};

#endif //_SINGLETON_H_
