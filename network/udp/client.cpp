#include <iostream>
#include <cstdio>
#include <cstring>

#include <sys/types.h>          /*  See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

const int PORT = 9090;
const char *IP = "127.0.0.1";
const int BUFSIZE = 1024;

int main(void)
{
    int fd = 0;
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd < 0)
    {
        std::cout << "socket error" << std::endl;
        exit(-1);
    }

    struct sockaddr_in clientAddr;
    memset(&clientAddr, 0, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(PORT);
    clientAddr.sin_addr.s_addr = inet_addr(IP);
    socklen_t len = sizeof(struct sockaddr_in);

    while(1)
    {
        char sendbuff[BUFSIZE] = "";
        char recvbuff[BUFSIZE] = "";
        ssize_t size = 0;

        std::cin >> sendbuff;
        size = sendto(fd, sendbuff, BUFSIZE, 0, (struct sockaddr*)&clientAddr, len);
        if(size < 0)
        {
            std::cout << "send to error" << std::endl;
            exit(-1);
        }

        size = recvfrom(fd, recvbuff, BUFSIZE, 0, (struct sockaddr*)&clientAddr, &len);
        if(size < 0)
        {
            std::cout << "recv from error " << std::endl;
            exit(-1);
        }
        else
        {
            std::cout << "recv size is : " << size << " recv info : " << recvbuff << std::endl;
        }
    }

    return 0;
}
