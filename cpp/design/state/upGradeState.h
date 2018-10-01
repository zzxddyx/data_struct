#ifndef _UPGRADE_STATE_H_
#define _UPGRADE_STATE_H_

#include "State.h"

class upGradeState : public State
{
    public:
        void show()
        {
            std::cout << "产生蓝光" << std::endl;
        }
};

#endif //_UPGRADE_STATE_H_

