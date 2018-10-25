#include<iostream>
#include <cstring>
using namespace std;

char *Reverst(char *str)
{
    if (NULL == str)
        return NULL;

    char *start = str;
    char *end = str + strlen(str)-1;

    while(start < end)
    {
        char ch = *start;
        *start = *end;
        *end = ch;
        
        start++;
        end--;
    }

    return str;
}


int main(void)
{
    char str[] = "abcdef";

    char *result = Reverst(str);
    
    cout << result << endl;

    return 0;
}

