#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/in.h>

#define PORT 8888

void deal_client_info(int fd);

int main(void)
{
    int sock_server, sock_cli;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int err;
    pid_t pid;

    //socket
    sock_server = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_server < 0)
    {
        printf("socket error : %d\n", sock_server);
        return -1;
    }

    //set server ip and port
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind
    err = bind(sock_server, (struct sockaddr *)(&server_addr), sizeof(server_addr));
    if (err < 0)
    {
        printf("bind error : %d\n", err);
        return -1;
    }

    //listen
    err = listen(sock_server, 5);
    if (err < 0)
    {
        printf("listen error : %d\n", err);
        return -1;
    }

    //accept
    //循环监听client的连接
    while(1)
    {
        int add_len = sizeof(struct sockaddr);
        sock_cli = accept(sock_server, (struct sockaddr*)&client_addr, &add_len);
        if (sock_cli < 0)
        {
            syslog(LOG_ERR, "%s:%d, accept failed\n", __FILE__, __LINE__);
            printf("accept error : %d\n", sock_cli);
            continue;
        }

        pid = fork();
        if (pid == 0)
        {
            close(sock_server);
            deal_client_info(sock_cli);
        }
        else
        {
            close(sock_cli);
        }

    }

    return 0;
}

void deal_client_info(int fd)
{
    ssize_t size = 0;
    char buf[10324] = {};

    while(1)
    {
        size = read(fd, buf, sizeof(buf));

        if (size == 0)
        {
            printf("recv 0 b");
            return;
        }

        sprintf(buf, "read %d bytes\n", size);
        write(fd, buf, strlen(buf)+1);
    }
}
