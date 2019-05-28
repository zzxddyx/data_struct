/*************************************************************************
    > File Name: stoi.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月24日 星期五 22时36分45秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void Str2Int(int &res, const string& str)
{
    if (str.empty())
    {
        res = 0;
        return;
    }

    bool isNegative = str[0] == '-' ? true : false;
    int index = isNegative ? 1 : 0;
    for ( ; index < str.size(); ++index)
    {
        res = res * 10 + (str[index] - '0');
    }

    res = isNegative ? -res : res;
}

int main(void)
{
    string str("-123456");
    int res = 0;

    Str2Int(res, str);
    cout << res << endl;

    return 0;
}

