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
    int fd_client;
    struct sockaddr_in addr_client;
    char buf[1024] = "";
    time_t now;
    int len = sizeof(addr_client);

    fd_client = socket(AF_INET, SOCK_SGRAM, 0);
    if (fd_client < 0)
    {
        printf("socket failed : %d\n", fd_client);
        return -1;
    }

    bzero(&addr_client, sizeof(addr_client));
    addr_client.sin_family = AF_INET;
    addr_client.sin_port = htons(PORT);
    addr_client.sin_addr.s_addr = htonl(INADDR_ANY);

    memset(buf, 0, sizeof(buf));
    strcpy(buf, "TIME");
    sendto(fd_client, buf, strlen(buf), 0, (struct sockaddr*)&addr_client, len);

    memset(buf, 0, sizeof(buf));
    ssize_t size = recvfrom(fd_client, buf, sizeof(buf), 0, (struct sockaddr*)&addr_client, &len);
    if (size > 0)
    {
        printf("recv is : %s\n", buf);
    }

    close(fd_client);

    return 0;
}
