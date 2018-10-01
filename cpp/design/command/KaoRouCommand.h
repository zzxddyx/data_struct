#ifndef _KAOROUCOMMAND_H_
#define _KAOROUCOMMAND_H_

#include "Command.h"
#include "Barbecuer.h"

class KaoRouCommand : public Command
{
    public:
        KaoRouCommand(Barbecuer *receiver)
            :p_mReceiver(receiver)
        {}

    public:
        void ExecuteCommand()
        {
            p_mReceiver->KaoRou();
        }
};

#endif //_KAOROUCOMMAND_H_
