#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include "Beverage.h"
#include <memory>

class Decorator : public Beverage
{
    public:
        double cost()
        {
            return this->observed->cost() + 0;
        }

        void setObserver(std::shared_ptr<Beverage> _obs)
        {
            this->observed = _obs;
        }

    protected:
        shared_ptr<Beverage> getObserver()
        {
            return observed;
        }

    private:
        std::shared_ptr<Beverage> observed; 
};

#endif //_DECORATOR_H_
