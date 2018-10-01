#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>

class Singleton
{
    public:
        void show();


    public:
        static Singleton* getInstance();

    private:
        static Singleton *m_pInstance;

    private:
        Singleton(){};
};

#endif //_SINGLETON_H_
