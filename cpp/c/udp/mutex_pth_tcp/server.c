#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT        8888
#define CLIENTNUM   2
#define LISTENBLOK  5

pthread_mutex_t LOCK = PTHREAD_MUTEX_INITIALIZER; 

void deal_data(void *arg)
{
    int fd_client;
    int fd_server = *((int*)arg);
    struct sockaddr_in addr_client;
    int len = sizeof(addr_client);

    while(1)
    {
        ssize_t size = 0;
        time_t now;
        char buf[1024] = "";
        int len = sizeof(buf);

        pthread_mutex_lock(&LOCK);
        fd_client = accept(fd_server, (struct sockaddr *)&addr_client, &len);
        if (fd_client < 0)
        {
            printf("accept failed : %d\n", fd_client);
            return;
        }
        pthread_mutex_unlock(&LOCK);

        size = recv(fd_client, buf, len, 0);
        if (size > 0 && !strncmp(buf, "TIME", 4))
        {
            memset(buf, len, 0);
            now = time(NULL);
            sprintf(buf, "%24s\r\n", ctime(&now));
            send(fd_client, buf, strlen(buf), 0);
        }
        close(fd_client);
    }
}



void deal_client(int fd_server)
{
    int i = 0;
    pthread_t pt[CLIENTNUM];

    for (i = 0; i < CLIENTNUM; ++i)
    {
        int err = pthread_create(&pt[i], NULL, (void*)deal_data, (void*)&fd_server);
        if (err != 0)
        {
            printf("pthread_create failed : %d\n", err);
            return;
        }
    }

    for (i = 0; i < CLIENTNUM; ++i)
    {
        pthread_join(pt[i], NULL);
    }
}

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

    err = bind(fd_server, (struct sockaddr *)&addr_server, sizeof(addr_server));
    if (err < 0)
    {
        printf("bind failed : %d\n", err);
        return -1;
    }

    err = listen(fd_server, LISTENBLOK);
    if (err < 0)
    {
        printf("listen failed : %d\n", err);
        return -1;
    }

    deal_client(fd_server);

    close(fd_server);

    return 0;
}


