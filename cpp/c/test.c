#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[1024] = {};

    printf("%d\n", sizeof(buf));
    printf("%d\n", strlen(buf));

    return 0;
}
