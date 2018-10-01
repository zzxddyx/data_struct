#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/in.h>
#include <syslog.h>

void deal_connect_server(int fd);

int main(void)
{
    int fd = 0;
    struct sockaddr_in sock_addr;
    int err = 0;

    //socket
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        printf("socket failed : %d\n", fd);
        return -1;
    }

    bzero(&sock_addr, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = 8888;
    inet_aton("127.0.0.1", (struct in_addr *)&sock_addr.sin_addr);

    //connect
    err = connect(fd, (struct sockaddr*)&sock_addr, sizeof(struct sockaddr));
    if (err < 0)
    {
        syslog(LOG_ERR, "%s:%d, connect failed\n", __FILE__, __LINE__); 
        return -1;
    }

    deal_connect_server(fd);

    close(fd);

    return 0;
}

void deal_connect_server(int fd)
{
    ssize_t size = 0;
    char buf[1024] = {};
    
    while(1)
    {
        size = read(0, buf, sizeof(buf));

        if (size > 0)
        {
            write(fd, buf, size);
            size = read(fd, buf, sizeof(buf));
            write(1, buf, size);
        }
    }
}
