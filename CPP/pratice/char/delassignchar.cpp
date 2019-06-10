#include <iostream>

void deleteChar(char *str, char c)
{
    if(NULL == str)
        return;

    char *pcur = str;
    char *next = str;

    while(*next != '\0')
    {
        if(*next != '\0' && *next != c)
        {
            *pcur++ = *next;

        }
        next++;
    }
    *pcur = '\0';
}

int main(void)
{
    char str[] = "welcome to wco";
    char c = 'o';

    std::cout << str << std::endl;
    deleteChar(str, c);
    std::cout << str << std::endl;

    return 0;
}
