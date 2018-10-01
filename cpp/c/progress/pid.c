#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t pid, ppid;
    printf("pid = %d, ppid = %d\n", getpid(), getppid());

    return 0;
}
