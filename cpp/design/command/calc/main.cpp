#include "Command.h"
#include "Invoker.h"
#include "Receiver.h"

#include "AddCommand.h"
#include "SubCommand.h"
#include "MulCommand.h"
#include "DivCommand.h"

int main()
{
    Invoker *invk = new Invoker(); // fa qi zhe
    Receiver *recv = new Receiver(10,20); // zhi xing zhe

    Command *add = new AddCommand(recv);
    Command *sub = new SubCommand(recv);
    Command *mul = new MulCommand(recv);
    Command *div = new DivCommand(recv);

    invk->AddCmd(add);
    invk->AddCmd(sub);
    invk->AddCmd(mul);
    invk->AddCmd(div);
    invk->Notify();



    return 0;
}
