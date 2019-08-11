#include <iostream>
#include <cstring>

#include <sys/types.h>          /*  See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

const int PORT = 9090;
const char *IP = "127.0.0.1";
const int BUFSIZE = 1024;

int main(void)
{
    int fd = 0;
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0)
    {
        std::cout << __FILE__ << ":" << __LINE__ << " : socket error" << std::endl;
        exit(-1);
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    //serverAddr.sin_addr.s_addr = inet_addr(IP);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(fd, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr_in)) < 0)
    {
        std::cout << "bind error" << std::endl;
        close(fd);
        exit(-1);
    }

    char recvbuf[BUFSIZE] = "";
    ssize_t size = 0;
    struct sockaddr_in clientAddr;
    socklen_t len = sizeof(struct sockaddr_in);
    

    while(1)
    {
        size = recvfrom(fd, recvbuf, BUFSIZE, 0, (struct sockaddr *)&clientAddr, &len);
        if (size < 0)
        {
            std::cout << "recv from error" << std::endl;
            exit(-1);
        }
        else
            std::cout << "recv is : " << recvbuf << std::endl;

        if(sendto(fd, recvbuf, size, 0, (struct sockaddr *)&clientAddr, len) != size)
        {
            std::cout << "sendto error" << std::endl;
            exit(-1);
        }
    }

    return 0;
}
