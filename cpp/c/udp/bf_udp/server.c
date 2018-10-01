#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#define PORT 8888

void sig_int(int num)
{
    exit(1);
}

void deal_client(int fd)
{
    ssize_t size;
    struct sockaddr_in addr_client;
    time_t now;
    int addr_len = sizeof(addr_client);
    char buf[1024] = "";
    int buf_len = sizeof(buf);

    while(1)
    {
        memset(buf, 0, buf_len);
        size = recvfrom(fd, buf, buf_len, 0, (struct sockaddr*)&addr_client, &addr_len);
        if (size > 0 && !strncmp(buf, "TIME", 4))
        {
            memset(buf, 0, buf_len);
            now = time(NULL);
            sprintf(buf, "%24s\r\n", ctime(&now));
            sendto(fd, buf, strlen(buf), 0, (struct sockaddr*)&addr_client, addr_len);
        }
        
    }
}

int main(void)
{
    int fd_server;
    struct sockaddr_in addr_server;

    signal(SIGINT, sig_int);

    fd_server = socket(AF_INET, SOCK_STREAM, 0);
    if (fd_server < 0)
    {
        printf("socket failed : %d\n", fd_server);
        return -1;
    }

    bzero(&addr_server, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(PORT);
    addr_server.sin_addr.s_addr = htonl(INADDR_ANY);

    int fd = bind(fd_server, (struct sockaddr *)&addr_server, sizeof(addr_server));
    if (fd < 0)
    {
        printf("bind failed : %d\n", fd);
        return -1;
    }

    pid_t pid[2];
    int i = 0;
    for(i = 0; i < 2; ++i)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            //处理客户端
            deal_client(fd_server);
        }
    }

    while(1);
    return 0;
}
