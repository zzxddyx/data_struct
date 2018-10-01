#ifndef _BLEND_H_
#define _BLEND_H_

#include "Beverage.h"

class Blend : public Beverage
{
    public:
        double cost()
        {
            return 1;
        }
        std::string getDescription()
        {
            return "Blend";
        }
};

#endif //_BLEND_H_
