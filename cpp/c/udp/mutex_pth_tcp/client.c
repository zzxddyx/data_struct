#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888

int main(void)
{
    int fd_addr;
    struct sockaddr_in addr_client;
    char buf[1024] = "";
    time_t now;
    int err;

    fd_addr = socket(AF_INET, SOCK_STREAM, 0);
    if (fd_addr < 0)
    {
        printf("socket failed : %d\n", fd_addr);
        return -1;
    }

    bzero(&addr_client, sizeof(addr_client));
    addr_client.sin_family = AF_INET;
    addr_client.sin_port = htons(PORT);
    addr_client.sin_addr.s_addr = htonl(INADDR_ANY);

    err = connect(fd_addr, (struct sockaddr*)&addr_client, sizeof(addr_client));
    if (err < 0)
    {
        printf("connect faild : %d\n", err);
        return -1;
    }

    memset(buf, 0, sizeof(buf));
    strcpy(buf, "TIME");
    send(fd_addr, buf, strlen(buf), 0);
    memset(buf, 0, sizeof(buf));
    ssize_t size = recv(fd_addr, buf, sizeof(buf), 0);
    if (size > 0)
    {
        printf("recv : %s\n", buf);
    }

    close(fd_addr);

    return 0;
}
