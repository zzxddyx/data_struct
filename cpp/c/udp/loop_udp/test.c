#include <stdio.h>
#include <string.h>


int main(void)
{
    char size[1024] = "";
    printf("%d\n", sizeof(size));
    printf("%d\n", strlen(size));
    return 0;
}
