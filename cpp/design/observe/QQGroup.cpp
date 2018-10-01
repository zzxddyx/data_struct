#include "QQGroup.h"

void QQGroup::registerObserver(Observer *obser)
{
    _observers->push_back(obser);
}

void QQGroup::removeObserver(Observer *obser)
{
    if ( _observers->size() > 0 )
    {
        _observers->remove(obser);
    }
}

void QQGroup::notifyObservers(const std::string &msg)
{
    std::cout << "msg : " << msg << std::endl;

    std::list<Observer *>::iterator iter;
    for (iter = _observers->begin(); iter != _observers->end(); ++iter)
    {
        (*iter)->Update(msg);
    }
}
