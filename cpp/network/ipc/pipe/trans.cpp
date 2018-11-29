#include <iostream>
#include <cstdio>
#include <ctype.h>
using namespace std;


int main(void)
{

    int c;
    while ((c = getchar()) != EOF)
    {
        if (isupper(c))
            c = tolower(c);
        if(putchar(c) == EOF)
        {
            cout << "putchar error" << endl;
            return -1;
        }
        if(c == '\n')
            fflush(stdout);
    }

    return 0;
}
