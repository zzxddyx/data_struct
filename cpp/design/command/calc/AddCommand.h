#ifndef _ADDCOMMAND_H_
#define _ADDCOMMAND_H_

#include "Command.h"

class AddCommand : public Command
{
    public:
        AddCommand(Receiver *recv)
            :Command(recv)
        {};

    public:
        void Execute()
        {
            p_mReceiver->ExecAdd();
        };
};

#endif //_ADDCOMMAND_H_
