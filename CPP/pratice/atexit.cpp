/*************************************************************************
    > File Name: atexit.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月21日 星期二 22时48分36秒
 ************************************************************************/

#include <iostream>

void func1(void)
{
    std::cout << "func1 delete" << std::endl;
}

void func2(void)
{
    std::cout << "func2 delete" << std::endl;
}

int main(void)
{
    atexit(func1);
    atexit(func2);
    std::cout << "main exit" << std::endl;

    return 0;
}
