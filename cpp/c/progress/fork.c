#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t pid;
    pid = fork();

    if (-1 == pid) 
    {
        printf("error\n");
        return -1;
    }
    else if (0 == pid)
    {
        printf("father ok, fork id = %d, pid = %d, ppid = %d\n", pid, getpid(), getppid());
    }
    else
    {
        printf("son ok, fork id = %d, pid = %d, ppid = %d\n", pid, getpid(), getppid());
    }

    return 0;
}
