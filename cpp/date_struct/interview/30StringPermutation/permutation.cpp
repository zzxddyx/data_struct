/*************************************************************************
    > File Name: permutation.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月19日 星期二 08时37分37秒
 ************************************************************************/

#include <iostream>
using namespace std;

void _Permutation(char *pStr, char *pBegin)
{
    if (*pBegin == '\0')
    {
        cout << pStr << endl;
    }
    else
    {
        for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            char tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;

            _Permutation(pStr, pBegin+1);

            tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;
        }
    }
}

void Permutation(char *str)
{
    if (str == NULL)
        return;

    _Permutation(str, str);
}

int main(void)
{
    char str[] = "abc";
    Permutation(str);
    return 0;
}
