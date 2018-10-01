#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <iostream>
#include <string>
#include "Observer.h"

class Subject
{
    public:
        virtual ~Subject(){};

    public:
        virtual void registerObserver(Observer *) = 0;
        virtual void removeObserver(Observer *) = 0;
        virtual void notifyObserver(const std::string &) = 0;
};

#endif //_SUBJECT_H_
