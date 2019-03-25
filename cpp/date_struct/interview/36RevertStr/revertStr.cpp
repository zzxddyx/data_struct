/*************************************************************************
    > File Name: revertStr.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月25日 星期一 20时39分03秒
 ************************************************************************/

#include <iostream>
using namespace std;

void Revert(char *pBegin, char *pEnd)
{
    if (pBegin == NULL || pEnd == NULL)
        return;

    while (pBegin < pEnd)
    {
        char tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;

        pBegin++;
        pEnd--;
    }
}

char *RevertStr(char *str)
{
    if (str == NULL)
        return NULL;

    char *pBegin = str;
    char *pEnd = str;
    while(*pEnd != '\0')
        pEnd++;
    pEnd--;

    Revert(pBegin, pEnd);

    pBegin = pEnd = str;
    while(*pBegin != '\0')
    {
        if (*pBegin == ' ')
        {
            pBegin++;
            pEnd++;
        }
        else if (*pEnd == ' ' || *pEnd == '\0')
        {
            --pEnd;
            Revert(pBegin, pEnd);
            ++pEnd;
            pBegin =pEnd;
        }
        else
        {
            pEnd++;
        }
    }

    return str;
}

int main(void)
{
    char str[] = "I am a student.";

    char *newStr = RevertStr(str);

    cout << newStr << endl;

    return 0;
}
