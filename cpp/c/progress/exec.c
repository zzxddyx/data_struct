#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *args[] = {"/bin/ls", NULL};
    printf("pid = %d\n", getpid());

    if (execve("/bin/ls", args, NULL) < 0)
    {
        printf("error\n");
    }

    return 0;
}
