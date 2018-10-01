#ifndef _FIRE_STATE_H_
#define _FIRE_STATE_H_

#include "State.h"

class FireState : public State
{
    public:
        void show()
        {
            std::cout << "受伤着火" << std::endl;
        }
};

#endif //_FIRE_STATE_H_

