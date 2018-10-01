#ifndef _BUILDINT_STATE_H_
#define _BUILDINT_STATE_H_

#include "State.h"

class BuildingState : public State
{
    public:
        void show()
        {
            std::cout << "建造特效" << std::endl;
        }
};

#endif //_BUILDINT_STATE_H_
