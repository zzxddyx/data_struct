#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Reveiver.h"
//class Reveiver;

class Command
{
    public:
        Command(Reveiver *receiver)
            :m_pReceiver(receiver)
        {}
        virtual void Execute() = 0;

    protected:
        Reveiver *m_pReceiver;
};

#endif //_COMMAND_H_
