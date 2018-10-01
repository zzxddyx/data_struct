#ifndef _DARKROAST_H_
#define _DARKROAST_H_

#include "Beverage.h"

class DarkRoast : public Beverage
{
    public:
        double cost()
        {
            return 10;
        }
        std::string getDescription()
        {
            return "DarkRoast";
        }
};

#endif //_DARKROAST_H_
