/*************************************************************************
    > File Name: 3_bigORsmall.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年04月21日 星期日 15时55分42秒
 ************************************************************************/

#include <iostream>

// 元素共享内存
union systemType
{
    int iData;
    char cData;
};

int main(void)
{
    union systemType obj;
    obj.iData = 1;
    std::cout << (obj.iData == obj.cData) << std::endl;

    return 0;
}


