#include "Invoker.h"
#include "Reveiver.h"
#include "Command.h"
#include "PayCommand.h"
#include "TakeCommand.h"

int main()
{
    Reveiver *reveiver = new Reveiver();

    Command *takeCommand = new TakeCommand(reveiver);
    Command *payCommand = new PayCommand(reveiver);

    Invoker *invoker = new Invoker();
    invoker->AddCmd(takeCommand);
    invoker->AddCmd(payCommand);

    invoker->Notify();

    return 0;
}



