#ifndef _SOCKET_PACKAGE_H_
#define _SOCKET_PACKAGE_H_

#include <iostream>

class SocketPackage
{
    public:
        void CreatePackageSocket()
        {
            std::cout << "Package : Create" << std::endl;
        }
        void BindPackageSocket()
        {
            std::cout << "Package : Bind" << std::endl;
        }
        void ListenPackageSocket()
        {
            std::cout << "Package : Listen" << std::endl;
        }
        void ConnectPackageSocket()
        {
            std::cout << "Package : Connect" << std::endl;
        }
};

#endif //_SOCKET_PACKAGE_H_
