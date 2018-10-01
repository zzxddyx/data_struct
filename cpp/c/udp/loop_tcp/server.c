#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888
#define BLOK 2

int main(void)
{
    int fd_server, fd_client;
    struct sockaddr_in addr_server, addr_client;
    char buf[1024] = "";
    int len_buf = sizeof(buf);
    time_t now;
    int err;
    int addr_len = sizeof(addr_client);

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
        printf("bind failed : %d\n", err);
        return -1;
    }

    err = listen(fd_server, BLOK);
    if (err < 0)
    {
        printf("listen failed : %d\n", err);
        return -1;
    }

    while(1)
    {
        fd_client = accept(fd_server, (struct sockaddr*)&addr_client, &addr_len);
        if (fd_client < 0)
        {
            printf("accept failed : %d\n", fd_client);
            return -1;
        }

        memset(buf, 0, sizeof(buf));
        ssize_t size = recv(fd_client, buf, sizeof(buf), 0);
        if (size > 0 && !strncmp(buf, "TIME", 4))
        {
            memset(buf, 0, sizeof(buf));
            now = time(NULL);
            sprintf(buf, "%24s\r\n", ctime(&now));
            send(fd_client, buf, strlen(buf), 0);
        }
        close(fd_client);
    }

    close(fd_server);

    return 0;
}
