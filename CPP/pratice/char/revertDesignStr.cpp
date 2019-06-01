#include <iostream>
#include <cstring>
#include <stack>

void swap(char* c1, char* c2)
{
    *c1 ^= *c2;
    *c2 ^= *c1;
    *c1 ^= *c2;
}

void revertDesignStr(char *str, char* token)
{
    if (str == NULL || NULL == token)
        return;

    int len = strlen(str);
    char* beg = str;
    char* end = beg+len-1;

    while(beg < end)
    {
        swap(&(*beg), &(*end));

        beg++;
        end--;
    }

    for(int index = len; index >= 0; --index)
    {
        char* tmp = token;
        if(*tmp == str[index])
        {
            end = str+index;
            while(str[index] != '\0' && *tmp != '\0' && *tmp == str[index])
            {
                --index;
                tmp++;
            }

            if(*tmp == '\0')
            {
                beg = str+(++index);
                break;
            }
            else
            {
                tmp = token;
            }
        }
    }

    while(beg < end)
    {
        swap(&(*beg), &(*end));

        beg++;
        end--;
    }
}

void revert(char* str, char* token)
{
    if(NULL == str || NULL == token)
        return;

    char* pstr = str;
    char* ptmp = str;
    char* ptok = token;
    std::stack<char> cStack;

    while(*pstr != '\0')
    {
        ptok = token;
        ptmp = pstr;
        while((*ptmp != '\0') && (*ptok != '\0') && (*ptmp == *ptok))
        {
            ptmp++;
            ptok++;
        }

        if(*ptok == '\0')
        {
            for(char* p = ptmp-1; p >= pstr; --p)
                cStack.push(*p);

            pstr = ptmp;
        }
        else
        {
            cStack.push(*pstr);
            pstr++;
        }
    }

    int index = 0;
    while(!cStack.empty())
    {
        char c = cStack.top();
        cStack.pop();
        *(str+index) = c;
        index++;
    }
}

int main(void)
{
    //char str[] = "Welcome To Shanxi";
    //char token[] = "To Shan";
    char str[] = "Welcome you, my friend";
    char token[] = "you";

    std::cout << str << std::endl;
    //revertDesignStr(str, token);
    revert(str, token);
    std::cout << str << std::endl;

    return 0;
}
