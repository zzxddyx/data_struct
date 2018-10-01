#ifndef _QQGROUP_H_
#define _QQGROUP_H_

#include "Subject.h"
#include "Observer.h"

class QQGroup : public Subject
{
    public:
        QQGroup()
        {
            _observers = new std::list<Observer *>();
        };
        virtual ~QQGroup(){};

    public:
        void registerObserver(Observer *obser);
        void removeObserver(Observer *obser);
        void notifyObservers(const std::string &msg);

    private:
        std::list<Observer *> *_observers;
};

#endif //_QQGROUP_H_
