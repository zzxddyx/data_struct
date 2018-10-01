#ifndef _PAYCOMMAND_H_
#define _PAYCOMMAND_H_

#include "Command.h"
#include <iostream>

class PayCommand : public Command
{
    public:
        PayCommand(Reveiver *receiver)
            :Command(receiver)
        {}

    public:
        void Execute()
        {
            std::cout << "Pay Command" << std::endl;
            m_pReceiver->ReceIpt();
        }
};

#endif //_PAYCOMMAND_H_
