/*************************************************************************
    > File Name: fibonacci.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月14日 星期四 08时41分41秒
 ************************************************************************/

#include <iostream>
using namespace std;

long long Fibonacci1(unsigned int n)
{
    if (n == 0)
        return 0;

    if(n == 1)
        return 1;

    return Fibonacci1(n-1) + Fibonacci1(n-2);
}

long long Fibonacci(unsigned int n)
{
    int res[2] = {0, 1};
    if(n < 2)
        return res[n];

    long long num1 = 0;
    long long num2 = 1;
    long long rest = 0;

    for (int i = 2; i <= n; ++i)
    {
        rest = num1 + num2;
        num1 = num2;
        num2 = rest;
    }

    return rest;
}

int main(void)
{
    long long res = Fibonacci(10);
    cout << res << endl;

    return 0;
}
