#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 8888
#define SIZE 1024

int main(void)
{
    int fd;
    struct sockaddr_in server, client;
    time_t now;
    char buf[SIZE] = "";
    size_t size = 0;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0){
        printf("socket failed : %d\n", fd);
        return -1;
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    int err = bind(fd, (struct sockaddr*)&server, sizeof(server));
    if (fd < 0){
        printf("bind faile %d\n", err);
        return -1;
    }

    while(1){
        memset(buf, 0, SIZE);
        int len = sizeof(client);
        size = recvfrom(fd, buf, SIZE, 0, (struct sockaddr*)&client, &len);
        if (size > 0 && !strncmp(buf, "TIME", 4)){
            memset(buf, 0, SIZE);
            now = time(NULL);
            sprintf(buf, "%24s\r\n", ctime(&now));
            sendto(fd, buf, strlen(buf), 0, (struct sockaddr*)&client, len);
        }
    }

    close(fd);
    return 0;
}

