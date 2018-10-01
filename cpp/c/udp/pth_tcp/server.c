#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888
#define BLOK 5

void deal_data(void *arg)
{
    int fd_client = *((int*)arg);
    time_t now;
    char buf[1024] = "";
    int len = sizeof(buf);
    size_t size = 0;

    size = recv(fd_client, buf, sizeof(buf), 0);
    if (size > 0 && !strncmp(buf, "TIME", 4))
    {
        memset(buf, sizeof(buf), 0);
        now = time(NULL);
        sprintf(buf, "%24s\r\n", ctime(&now));
        send(fd_client, buf, strlen(buf), 0);
    }

    close(fd_client);
}

void deal_client(int fd_server)
{
    int fd_client;
    struct sockaddr_in addr_client;
    int len = sizeof(addr_client);
    pthread_t pt;
    
    while(1)
    {
        fd_client = accept(fd_server, (struct sockaddr*)&addr_client, &len);
        if (fd_client > 0)
        {
            int err = pthread_create(&pt, NULL, (void*)deal_data, (void*)&fd_client);
            if (err != 0)
            {
                printf("pthread_create failed : %d\n", err);
                return;
            }
        }
    }

}

/*
 * 单客户端单线程，统一accept
 */
int main(void)
{
    int fd_server;
    struct sockaddr_in addr_server;
    int err;

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

    err = bind(fd_server, (struct sockaddr*)&addr_server, sizeof(addr_server));
    if (err < 0)
    {
        printf("bind faile : %d\n", err);
        return -1;
    }

    err = listen(fd_server, BLOK);
    if (err < 0)
    {
        printf("listen failed : %d\n", err);
        return -1;
    }

    deal_client(fd_server);
    
    return 0;
}

