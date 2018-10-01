#ifndef _SOCKET_ADAPTER_H_
#define _SOCKET_ADAPTER_H_

#include "Socket.h"
#include "SocketPackage.h"

class SocketAdapter : public Socket
{
    public:
        SocketAdapter();
        virtual ~SocketAdapter();

    public:
        void CreateSocket();
        void BindSocket();
        void ListenSocket();
        void ConnectSocket();

    private:
        SocketPackage *adapterr;
};

#endif //_SOCKET_ADAPTER_H_
