#include "SocketAdapter.h"
#include "Socket.h"
#include "SocketPackage.h"

int main()
{
    Socket *adapterr = new SocketAdapter();

    adapterr->CreateSocket();
    adapterr->BindSocket();
    adapterr->ListenSocket();
    adapterr->ConnectSocket();

    delete adapterr;
    adapterr = NULL;

    return 0;
}
