#include "Socket.h"
#include "SocketAdapter.h"
#include "SocketPackage.h"

int main()
{
    Socket *adapt = new SocketAdapter();

    adapt->CreateSocket();
    adapt->BindSocket();
    adapt->ListenSocket();
    adapt->ConnectSocket();

    delete adapt;
    adapt = NULL;

    return 0;
}

