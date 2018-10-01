#ifndef _TAKECOMMAND_H_
#define _TAKECOMMAND_H_

#include "Command.h"

class TakeCommand : public Command
{
    public:
        TakeCommand(Reveiver *receiver)
            :Command(receiver)
        {}

    public:
        void Execute()
        {
            std::cout << "Take Command" << std::endl;
            m_pReceiver->TakeOrder();
        }
};

#endif // _TAKECOMMAND_H_
