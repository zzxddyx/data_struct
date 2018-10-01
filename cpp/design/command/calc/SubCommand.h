#ifndef _SUBCOMMAND_H_
#define _SUBCOMMAND_H_

#include "Command.h"

class SubCommand : public Command
{
    public:
        SubCommand(Receiver *recv)
            :Command(recv)
        {};

    public:
        void Execute()
        {
            p_mReceiver->ExecSub();
        };
};

#endif //_SUBCOMMAND_H_


