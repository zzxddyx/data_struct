#ifndef _SOCKET_ADAPTER_H_
#define _SOCKET_ADAPTER_H_

#include "Socket.h"
#include "SocketPackage.h"

class SocketAdapter : public Socket, public SocketPackage
{
    void CreateSocket()
    {
        CreatePackageSocket();
    }
    void BindSocket()
    {
        BindPackageSocket();
    }
    void ListenSocket()
    {
        ListenPackageSocket();
    }
    void ConnectSocket()
    {
        ConnectPackageSocket();
    }
};

#endif //_SOCKET_ADAPTER_H_


