#ifndef _REPAIR_STATE_H_
#define _REPAIR_STATE_H_

#include "State.h"

class RepairState : public State
{
    public:
        void show()
        {
            std::cout << "产生绿光" << std::endl;
        }
};

#endif //_REPAIR_STATE_H_
