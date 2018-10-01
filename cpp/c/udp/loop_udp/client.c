#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <string.h>

#define PORT 8888
#define SIZE 1024

int main(void)
{
    int fd;
    struct sockaddr_in server;
    char buf[SIZE] = "";
    time_t now;


    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0)
    {
        printf("socket faile %d\n", fd);
        return -1;
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htons(INADDR_ANY);

    strcpy(buf, "TIME");
    sendto(fd, buf, strlen(buf), 0, (struct sockaddr*)&server, sizeof(server));
    memset(buf, 0, strlen(buf));

    int len = sizeof(server);
    ssize_t size = recvfrom(fd, buf, SIZE, 0, (struct sockaddr*)&server, &len);

    if (size > 0)
    {
        printf("recv is : %s\n", buf);
    }

    close(fd);

    return 0;
}
