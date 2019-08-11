#include <iostream>
#include <cstring>
#include <cstdio>

#include <sys/types.h>          /*  See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

const int PORT = 8080;
const int BACKLOG = 5;
const int BUFSIZE = 1024;

int main(void)
{
    // socket
    int sFd = socket(AF_INET, SOCK_STREAM, 0);
    if (sFd < 0)
    {
        std::cout << "create socket error" << std::endl;
        return -1;
    }

    // bind
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sFd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr_in)) < 0)
    {
        std::cout << "bind error" << std::endl;
        close(sFd);
        return -2;
    }

    // listen
    if(listen(sFd, BACKLOG) < 0)
    {
        std::cout << __LINE__ << " listen error" << std::endl;
        close(sFd);
        exit(0);
    }

    // accept
    // read
    // write
    int cFd = 0;
    int n = 0;
    while(true)
    {
        char buff[BUFSIZE] = "";
        cFd = accept(sFd, (struct sockaddr*)NULL, NULL);
        if(cFd < 0)
        {
            std::cout << __LINE__ << " accept error" << std::endl;
            continue;
        }
        else 
        {
            n = recv(cFd, buff, BUFSIZE, 0);
            buff[n] = '\0';
            std::cout << "recv size is " << n << "\trecv client info is " << buff << std::endl;
            if(strncmp(buff, "quit", 4) == 0)
                break;

            memset(&buff, 0, sizeof(buff));
            sprintf(buff, "%s", "Welcome connect Server");
            send(cFd, buff, strlen(buff)+1, 0);
        }
    }
    // close
    close(sFd);

    return 0;
}
