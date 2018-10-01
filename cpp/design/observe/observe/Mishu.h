#ifndef _MISHU_H_
#define _MISHU_H_

#include <list>
#include "Subject.h"
#include "Observer.h"

class Mishu
{
    public:
        Mishu()
        {
            obsers = new std::list<Observer *>();
        }
        virtual ~Mishu(){};

    public:
        void registerObserver(Observer *);
        void removeObserver(Observer *);
        void notifyObserver(const std::string &);
    private:
        std::list<Observer *> *obsers;
};

#endif //_MISHU_H_
