/*************************************************************************
    > File Name: string.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年04月28日 星期日 12时14分20秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <typeinfo>

int main(void)
{
    std::string s("heloo");
    auto size = s.size(); //unsigned int --> s.size()
    //decltype(std::size()) size = s.size();

    auto name = typeid(size).name();
    std::cout << name << std::endl;
    std::cout << s.max_size() << std::endl;

    return 0;
}
