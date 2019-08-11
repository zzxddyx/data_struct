#include <iostream>
#include <cstdio>
#include <cstring>

#include <sys/types.h>          /*  See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

const int PORT = 8080;
const char *IP = "127.0.0.1";
const int BUFSIZE = 1024;

int main(void)
{
    int fd = 0;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        std::cout << __LINE__ << " socket error" << std::endl;
        exit(-1);
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    if(connect(fd, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr_in)) < 0)
    {
        std::cout << __LINE__ << " connect error" << std::endl;
        exit(-1);
    }

    char buff[BUFSIZE] = "";
    strcpy(buff, "haha I'm connect");
    if(send(fd, buff, strlen(buff)+1, 0) < 0)
    {
        std::cout << __LINE__ << " send error" << std::endl;
        exit(-1);
    }

    memset(buff, 0, sizeof(buff));
    int n = recv(fd, buff, BUFSIZE, 0);
    buff[n] = '\0';
    std::cout << "recv size is :" << n << "\trecv info is : " << buff << std::endl;
    close(fd);

    return 0;
}
