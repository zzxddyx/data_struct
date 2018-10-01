#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <iostream>
#include <string>
#include <list>
#include "Observer.h"
class Subject
{
    public:
        virtual ~Subject(){};

    public:
        virtual void registerObserver(Observer *obser) = 0;
        virtual void removeObserver(Observer *obser) = 0;
        virtual void notifyObservers(const std::string &msg) = 0;
};

#endif //_SUBJECT_H_
