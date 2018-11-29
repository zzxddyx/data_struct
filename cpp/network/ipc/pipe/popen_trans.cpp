#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_SIZE 1024

void my_error(const char *str)
{
    cout << str << endl;
    return ;
}

int main(void)
{
    FILE *fpin = popen("./u2l", "w");
    if (NULL == fpin)
        my_error("popen error");

    char buf[MAX_SIZE] = "";
    while(true)
    {
        fputs("HaHaHa", stdout);
        fflush(stdout);
        if(fgets(buf, MAX_SIZE, fpin) == NULL)
            break;
        if(fputs(buf, stdout) == EOF)
            my_error("puts info error");
    }

    if(pclose(fpin) == -1)
        my_error("pclose error");
    putchar('\n');

    return 0;
}
