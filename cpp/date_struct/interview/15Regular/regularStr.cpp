/*************************************************************************
    > File Name: regularStr.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月16日 星期六 18时16分17秒
 ************************************************************************/

/*
 * 请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
 * 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
 * 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
 * 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
 */

#include <iostream>
using namespace std;

bool matchCore(char *str, char *patten)
{
    if(*str == '\0' && *patten == '\0')
        return true;

    if (*str != '\0' && *patten == '\0')
        return false;

    if (*(patten+1) == '*')
    {
        if (*patten == *str || (*patten == '.' && *str != '\0'))
            return matchCore(str+1, patten+2) || matchCore(str+1, patten) || matchCore(str, patten+2);
        else
            return matchCore(str, patten+2);
    }

    if(*str == *patten || (*patten == '.' && *str != '\0'))
        return matchCore(str+1, patten+1);

    return false;
}

bool mathc(char *str, char *patten)
{
    if (NULL == str || NULL == patten)
        return false;

    return matchCore(str, patten);
}

int main(void)
{
    cout << mathc("aaa", "aa.a") << endl;

    return 0;
}
