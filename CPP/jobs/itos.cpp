/*************************************************************************
    > File Name: itos.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月24日 星期五 22时27分41秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void Int2Str(int value, string &str)
{
    bool isNegative = value < 0 ? true : false;
    value = value < 0 ? -value : value;

    stack<char> sRev;
    while(value != 0)
    {
        sRev.push((value%10) + '0');
        value /= 10;
    }

    while(!sRev.empty())
    {
        if(isNegative)
        {
            str += '-';
            isNegative = false;
        }

        str += sRev.top();
        sRev.pop();
    }
}

int main(void)
{
    int value = -123456;
    string str;

    Int2Str(value, str);
    cout << str << endl;

    return 0;
}
