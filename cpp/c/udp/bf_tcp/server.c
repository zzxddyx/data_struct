#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888

void deal_connect (int fd_server);
void deal_recv(int fd_client);

int main(void)
{
    int fd_server;
    struct sockaddr_in addr_server;
    
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
    
    int err = bind(fd_server, (struct sockaddr *)&addr_server, sizeof(addr_server));
    if (err < 0)
    {
        printf("bind failed : %d\n", err);
        return -1;
    }

    err = listen(fd_server, 5);
    if (err < 0)
    {
        printf("listen failed : %d\n", err);
        return -1;
    }

    deal_connect(fd_server);
    close(fd_server);

    return 0;
}

void deal_connect(int fd_server)
{
    int fd_client;
    struct sockaddr_in addr_client;
    int len = sizeof(addr_client);

    while(1)
    {
        fd_client = accept(fd_server, (struct sockaddr *)&addr_client, &len);
        if (fd_client < 0)
        {
            printf("accept failed : %d\n", fd_client);
            return;
        }

        pid_t pid = fork();
        if (pid > 0)
        {
            close(fd_client);
        }
        else if(pid < 0)
        {
            printf("fork error\n");
            return;
        }
        else
        {
            deal_recv(fd_client);
            return;
        }
    }

}

void deal_recv(int fd_client)
{
    time_t now;
    char buf[1024] = "";
    int len = sizeof(buf);
    ssize_t size;

    size = recv(fd_client, buf, len, 0);
    if (size > 0 && !strncmp(buf, "TIME", 4))
    {
        memset(buf, 0, len);
        now = time(NULL);
        sprintf(buf, "%24s\r\n", ctime(&now));
        send(fd_client, buf, strlen(buf), 0);
    }

    close(fd_client);
}
