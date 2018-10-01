#ifndef _DIVCOMMAND_H_
#define _DIVCOMMAND_H_

#include "Command.h"

class DivCommand : public Command
{
    public:
        DivCommand(Receiver *recv)
            :Command(recv)
        {};

    public:
        void Execute()
        {
            p_mReceiver->ExecDiv();
        }
};

#endif //_DIVCOMMAND_H_
