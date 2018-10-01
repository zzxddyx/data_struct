#ifndef _MULCOMMAND_H_
#define _MULCOMMAND_H_

#include "Command.h"

class MulCommand : public Command
{
    public:
        MulCommand(Receiver *recv)
            :Command(recv)
        {};

    public:
        void Execute()
        {
            p_mReceiver->ExecMul();
        }

};

#endif //_MULCOMMAND_H_
