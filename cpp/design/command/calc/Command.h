#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Receiver.h"

class Command
{
    public:
        Command(Receiver *receiver)
            :p_mReceiver(receiver)
        {};

    public:
        virtual void Execute() = 0;

    protected:
        Receiver *p_mReceiver;
};

#endif //_COMMAND_H_
