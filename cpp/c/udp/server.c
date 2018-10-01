#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/in.h>

void udpserver(int fd, struct sockaddr *client)
{
    ssize_t size = 0;
    char buf[1024] = "";
    int sock_len = 0;
    int len = strlen(buf);

    while(1)
    {
        sock_len = sizeof(*client);
        
        size = recvfrom(fd, buf, len, 0, client, &sock_len);

        sendto(fd, buf, size, 0, client, sock_len);
    }
}

int main(void)
{
    struct sockaddr_in addr_server, addr_client;
    int ser_fd;

    ser_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (ser_fd < 0)
    {
        printf("socket error : %d\n", ser_fd);
        return -1;
    }

    bzero(&addr_server, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = 8888;
    addr_server.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(ser_fd, (struct sockaddr*)&addr_server, sizeof(addr_server));

    udpserver(ser_fd, (struct sockaddr *)&addr_client);

    return 0;
}
