#ifndef _PRODUCTION_STATE_H_
#define _PRODUCTION_STATE_H_

#include "State.h"

class ProductionState : public State
{
    public:
        void show()
        {
            std::cout << "产生白光" << std::endl;
        }
};

#endif //_PRODUCTION_STATE_H_
