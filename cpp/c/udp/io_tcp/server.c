#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define PORT        8888
#define CLIENTNUM   1024
#define BLOCK       5
int connect_host[CLIENTNUM];
int connect_num = 0;

void deal_request(void *arg)
{
    size_t size;
    time_t now;
    char buf[1024] = "";
    int len = sizeof(buf);

    int maxfd = -1;
    fd_set scanfd;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    int i = 1;
    int err = -1;

    while(1)
    {
        maxfd = -1;
        FD_ZERO(&scanfd);
        for (i = 0; i < CLIENTNUM; ++i)
        {
            if (connect_host[i] != -1)
            {
                FD_SET(connect_host[1], $scanfd);
                if (maxfd < connect_host[i])
                {
                    maxfd = connect_host[1];
                }
            }
        }

        err = select(maxfd + 1, &scanfd, NULL, NULL, &timeout);
        switch(err)
        {
            case 0:
                break;
            case -1:
                break;
            default:
                if (connect_num <= 0)
                {
                    break;
                }
                for (i = 0; i < CLIENTNUM; ++i)
                {
                    if (connect_host[i] != -1)
                    {
                        if
                    }
                }
                break;
        }
    }


}


void deal_connect(void *arg)
{

}

int main(void)
{
    int fd_server;
    struct sockaddr_in addr_server;

    fd_server = socker(AF_INET, SOCK_STREAM, 0);
    if (fd_server < 0)
    {
        printf("socket failed : %d\n", fd_server);
        return -1;
    }

    bzero(&addr_server, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(PORT);
    addr_server.sin_addr.s_addr = htonl(INADDR_ANY);

    int err = bind(fd_server, (struct sockaddr*)&addr_server, sizeof(addr_server));
    if (err < 0)
    {
        printf("bind failed : %d\n", err);
        return -1;
    }

    err = listen(fd_server, BLOCK);
    if (err < 0)
    {
        printf("listen failed : %d\n", err);
        return -1;
    }

    pthread_t pt[2];
    pthread_create(&pt[0], NULL, deal_connect, (void*)&fd_server);//create pthread deal client connect
    pthread_create(&pt[1], NULL, deal_request, NULL);//create pthread deal client request

    int i = 0;
    for (; i < 2; ++i)
    {
        pthread_join(pt[i], NULL);
    }

    close(fd_server);

    return 0;
}
