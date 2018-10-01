#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Barbecuer.h"

class Command
{
    public:
        Command(){};
        Command(Barbecuer *receiver)
            :p_mReceiver(receiver)
        {}

    public:
        virtual void ExecuteCommand() = 0;

    protected:
        Barbecuer *p_mReceiver;
};



#endif //_COMMAND_H_
