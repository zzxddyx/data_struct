#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <linux/in.h>

void udpclient(int fd, struct sockaddr *client)
{
    char buf[1024] = "HELLO UDP";
    int len = strlen(buf);
    struct sockaddr_in from;
    int sock_len = sizeof(*client);
    connect(fd, client, sock_len);

    sendto(fd, buf, len, 0, client, sock_len);
    recvfrom(fd, buf, len, 0, (struct sockaddr *)&from, &len);

    printf("recv data : %s\n", buf);
}

int main(void)
{
    struct sockaddr_in addr_client, addr_server;
    int sock_cliet = 0;

    sock_cliet = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_cliet < 0)
    {
        printf("socket failed : %d\n", sock_cliet);
        return -1;
    }

    bzero(&addr_server, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = 8888;
    addr_server.sin_addr.s_addr = htonl(INADDR_ANY);

    udpclient(sock_cliet, (struct sockaddr*)&addr_server);

    close(sock_cliet);

    return 0;
}

