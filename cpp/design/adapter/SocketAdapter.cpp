#include "SocketAdapter.h"

SocketAdapter::SocketAdapter()
{
    adapterr = new SocketPackage();
}

SocketAdapter::~SocketAdapter()
{
    if (NULL != adapterr)
    {
        delete adapterr;
        adapterr = NULL;
    }
}

void SocketAdapter::CreateSocket()
{
    adapterr->CreatePackageSocket();
}

void SocketAdapter::BindSocket()
{
    adapterr->BindPackageSocket();
}

void SocketAdapter::ListenSocket()
{
    adapterr->ListenPackageSocket();
}

void SocketAdapter::ConnectSocket()
{
    adapterr->ConnectPackageSocket();
}
