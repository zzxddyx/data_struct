#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define MAX_SIZE 1024

int main(void)
{
    char buf[MAX_SIZE] = "";
    int n = 0;
    while((n = read(STDOUT_FILENO, buf, MAX_SIZE)) > 0)
    {
        buf[n] = '\0';
        int int1, int2;
        if(sscanf(buf, "%d%d", &int1, &int2) == 2)
        {
            sprintf(buf, "%d\n", int1+int2);
            n = strlen(buf);
            if (write(STDOUT_FILENO, buf, n) != n)
            {
                cout << "write stdout error" << endl;
                exit(1);
            }
        }
        else
        {
            char str[] = "invalid args\n";
            n = strlen(str);
            if(write(STDOUT_FILENO, str, n) != n)
            {
                cout << "write error" << endl;
                exit(1);
            }
        }
    }
    return 0;
}
