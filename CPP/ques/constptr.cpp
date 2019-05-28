/*************************************************************************
    > File Name: constptr.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月23日 星期四 21时49分09秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    char str1[] = "abc";
    char str2[] = "fgh";

    char* const p1 = str1;
    //p1 = str2; //指向的对象不允许改变
    p1[2] = 'd';

    cout << p1 << endl;

    //char* const p = "abc"; //abc在数据区，无法修改
    //p[2] = 'k';
    //*p[2] = 'k';
    //cout << p << endl;

    return 0;
}
