#include "Mishu.h"

void Mishu::registerObserver(Observer *_obsers)
{
    this->obsers->push_back(_obsers);
}

void Mishu::removeObserver(Observer *_obsers)
{
    if (this->obsers->size() > 0)
    {
        std::list<Observer *>::iterator iter = obsers->begin();
        while ( iter != obsers->end() )
        {
            if ( (*iter) == _obsers )
            {
                this->obsers->erase(iter);
            }
            ++iter;
        }
    }
}

void Mishu::notifyObserver(const std::string &msg)
{
    std::cout << "msg : " << msg << std::endl;
    std::list<Observer *>::iterator iter = this->obsers->begin();
    for (iter; iter != obsers->end(); ++iter )
    {
        (*iter)->Update(msg);
    }
}
