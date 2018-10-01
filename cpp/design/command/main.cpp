#include "Barbecuer.h"
#include "Command.h"
#include "KaoJiChiCommand.h"
#include "KaoRouCommand.h"
#include "Waiter.h"

#define SAFE_DELETE(p) if(p){delete p; p=NULL;}

int main(void)
{
    Barbecuer *cooker = new Barbecuer();

    Command *kaorou = new KaoRouCommand(cooker);
    Command *kaojichi = new KaoJiChiCommand(cooker);

    Waiter *waiter = new Waiter();
    waiter->SetOrder(kaorou);
    waiter->SetOrder(kaojichi);

    waiter->Notify();

    SAFE_DELETE(cooker);
    SAFE_DELETE(kaorou);
    SAFE_DELETE(kaojichi);
    SAFE_DELETE(waiter);

    return 0;
}

