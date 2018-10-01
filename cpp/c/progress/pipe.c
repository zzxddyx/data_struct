#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    int result = -1;
    int fd[2] = {};
    int size = 0;
    pid_t pid;
    char buf[] = "十九大威武";
    char readbuf[1024] = {};

    int *write_fd = &fd[1];
    int *read_fd = &fd[0];

    result = pipe(fd);
    if (-1 == result)
    {
        printf("pipe error\n");
        return -1;
    }

    pid = fork();
    if (-1 == pid)
    {
        printf("fork error\n");
        return -1;
    }

    if (0 == pid)
    {
        printf("father : ");
        close(*read_fd);
        result = write(*write_fd, buf, strlen(buf));
        return 0;
    }
    else
    {
        printf("son : ");
        close(*write_fd);
        int size = read(*read_fd, readbuf, sizeof(readbuf));
        printf("read is %d , contant is %s\n", size, readbuf);
    }

    return 0;
}
