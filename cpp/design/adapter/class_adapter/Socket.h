#ifndef _SOCKET_H_
#define _SOCKET_H_

class Socket
{
    public:
        virtual ~Socket(){};

    public:
        virtual void CreateSocket() = 0;
        virtual void BindSocket() = 0;
        virtual void ListenSocket() = 0;
        virtual void ConnectSocket() = 0;
};

#endif //_SOCKET_H_
