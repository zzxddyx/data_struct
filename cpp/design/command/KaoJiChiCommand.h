#ifndef _KAOJICHICOMMAND_H_
#define _KAOJICHICOMMAND_H_

#include "Command.h"
#include "Barbecuer.h"

class KaoJiChiCommand : public Command
{
    public:
        KaoJiChiCommand(Barbecuer *receiver)
            :p_mReceiver(receiver)
        {}

    public:
        void ExecuteCommand()
        {
            p_mReceiver->KaoJiChi();
        }
};

#endif //_KAOJICHICOMMAND_H_
