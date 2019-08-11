#include <iostream>
#include <cstring>

#include <sys/types.h>          /*  See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
/*  According to POSIX.1-2001, POSIX.1-2008 */
#include <sys/select.h>
/*  According to earlier standards */
#include <sys/time.h>
#include <unistd.h>

const int FD_SETSIZE = 1024;
const int PORT = 7890;
const int BACKLOG = 10;

int createSocket()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0)
    {
        std::cout << "socket error" << std::endl;
        return -1;
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int on = 1;
    socklen_t len = sizeof(on);
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &on, len);

    if(bind(fd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr_in)) < 0)
    {
        std::cout << "bind error" << std::endl;
        return -1;
    }

    if(listen(fd, BACKLOG) < 0)
    {
        std::cout << "listen error" << std::endl;
        return -1;
    }

    return fd;
}

int main(void)
{
    int listenfd = createSocket();
    if(listenfd < 0)
    {
        std::cout << "create socket error" << std::endl;
        exit(-1);
    }
    int maxfd = listenfd;
    int client[FD_SETSIZE] = {0};
    for(int i = 0; i < FD_SETSIZE; ++i)
        client[i] = -1;

    fd_set allsets;
    FD_ZERO(&allsets);
    FD_SET(listenfd, &allsets);

    fd_set resetset;
    while(1)
    {
        resetset = allsets;
        int nready = select(maxfd+1, &resetset, NULL, NULL, NULL);
        if(nready < 0)
        {
            std::cout << "select error" << std::endl;
            continue;
        }

        if(FD_ISSET(listenfd, &resetset))
        {

        }

    }

    return 0;
}
